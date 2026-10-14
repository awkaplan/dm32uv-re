"""Dynamic half of verify_patch.py: boot stock and patched images to the standby screen under
this repo's own qemu-system-cskyv2 (`-M dm32`, vendor/csky-qemu + vendor/dm32uv-qemu, built into
the Docker image - see ../../../docker/Dockerfile), drive one fixed key script through both, and
compare what each one put on the screen and which code each one ran.

HOW BOTH IMAGES ARE BUILT. Stock and patched are each composed with
compose_qemu_image.compose() from the same 1 MB base, so the three QEMU-only patches (ALPU-MP
bypass sector @0x030c6000, auto-power-off NOP @0x0301bde0, hardware-binding record @0x0300b10c)
are applied identically to both, with that module's byte-exact guards. Without the ALPU bypass the
firmware stops at the deliberate `while(1)` at IRAM 0x169d4 (the failure leg of the anti-clone
check) after roughly 7000 flash transfers - which is where this tool used to stop, so its old PASS
only covered early boot. With it, stock firmware reaches the standby screen and the menu.

IRAM: the boot stub (flash 0x0300c000) copies the IRAM load image (flash 0x030bfc20..0x030decb8)
into IRAM itself, so code that runs from IRAM always comes from the COMPOSED flash image,
including a patch to a sector inside that range. The `-device loader` IRAM preload is overwritten
by that copy (checked 2026-10-10: a derived, the committed, and an all-zero preload give identical
frames). By default each boot is preloaded with the IRAM derived from its own composed image
(derive_iram.py, as compose_qemu_image.py --iram-out does); an explicit iram_path is loaded for
both boots instead.

WHAT IS COMPARED, AND WHY THIS AND NOT A TIME WINDOW.
  * The run is stopped by FIRMWARE PROGRESS, not wall-clock time: the key script (DM32_KEYSEQ)
    advances on the firmware's own keypad-row reads, and the run ends when the model logs
    "KEYSEQ -> step <n_steps>" (the whole script consumed). `-icount shift=3,sleep=off` ties the
    model's virtual clock (which the LCD settle detector and the firmware's timers use) to the
    instruction count, so the result does not depend on host load or on running both boots in
    parallel.
  * Default probe (PROBE_KEYSEQ): wait for boot to settle on standby, press MENU (top-level menu),
    press BACK (standby again). That exercises boot, the standby screen, the menu builder/renderer
    and the return path. A patch whose effect lies deeper (a sub-menu, a game screen) is only
    exercised if you pass a longer `keyseq` (qemu_run.KEYS / qemu_run.keyseq build one).
  * PRIMARY signal - screens: every frame the LCD model reports as settled before the script
    completes, as (key-script step, non-black pixel count, sha256 of the raw GRAM). This sequence
    is deterministic run to run (stock vs stock compares equal), so any difference is a real
    behaviour difference, reported as DIFFERS with the first divergent frame.
  * SECONDARY signal - code: the set of translated instruction addresses (`-d in_asm`, logged to
    the same stream as the KEYSEQ/GRAMDUMP lines so the set can be cut at the same completion
    marker). Addresses inside the patched sector (and, if the sector lies inside the IRAM load
    image, its IRAM copy) are excluded. Differences elsewhere are WARNINGS: a hook that calls
    stock code legitimately executes different stock code. A small amount of run-to-run noise is
    possible here (the last few blocks before the process is stopped), so this is never a FAIL.

VERDICTS (result["verdict"]):
  PASS                 screens identical, no code-coverage change outside the sector
  PASS with warnings   screens identical, code coverage outside the sector changed
  DIFFERS              patched image completed the probe but the screens differ - expected for a
                       UI patch the probe reaches; review the frames (keep_dir) before flashing
  FAIL                 static gate failed, or the patched image crashed / never completed the
                       probe while stock did (hang, boot regression)
  INCONCLUSIVE         the comparison could not be made: stock itself did not reach standby or
                       complete the probe (harness problem), or the patch overlaps a QEMU-only
                       patch site so the emulated image cannot contain it

LIMITS: the model has no RF/DMR/vocoder simulation and no codeplug (all-0xFF data chip -> the
"Null Ch." standby). Identical screens on this probe say nothing about RF behaviour, about code
the probe never reaches, or about calibration safety.
"""
from __future__ import annotations

import hashlib
import pathlib
import re
import shutil
import subprocess
import sys
import tempfile
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import compose_qemu_image  # noqa: E402
import qemu_run  # noqa: E402
from derive_iram import derive as derive_iram, LOAD_SRC, LOAD_DST, LOAD_END  # noqa: E402

FLASH_BASE = compose_qemu_image.FLASH_BASE
FLASH_SIZE = compose_qemu_image.FLASH_SIZE
SECTOR_SIZE = compose_qemu_image.SECTOR_SIZE
DEFAULT_BASE = compose_qemu_image.DEFAULT_BASE

QEMU_BIN = shutil.which("qemu-system-cskyv2")

ICOUNT = ["-icount", "shift=3,sleep=off"]
STALL_FACTOR, STALL_SLACK = 4.0, 30.0

BOOTCRIT = [
    (0x00000, 0x01000, "DH_FLAG header + reset vector"),
    (0x01000, 0x02000, "crt0 stage-1 (early boot)"),
    (0x0c000, 0x0d000, "crt0 stage-2 / app entry (0x0300c000)"),
]

# Sectors that compose_qemu_image.apply_qemu_only_patches() writes into (file offsets).
QEMU_ONLY_SECTORS = {
    compose_qemu_image.ALPU_SECTOR_OFFSET: "ALPU-MP bypass sector",
    compose_qemu_image.AUTOPOWEROFF_OFFSET & ~(SECTOR_SIZE - 1): "auto-power-off NOP",
    compose_qemu_image.HWBIND_OFFSET & ~(SECTOR_SIZE - 1): "hardware-binding record",
}

# Probe key script: lead-in (hold=0 only counts row reads; boot settles on standby during it),
# MENU, BACK, then a short tail so the standby repaint after BACK settles before the script ends.
PROBE_KEYSEQ = qemu_run.keyseq(
    "-1:0:1:31:0:400",                       # lead-in: no key, 400 row reads
    qemu_run.KEYS["Menu"] + ":20:120",       # MENU -> top-level menu
    qemu_run.KEYS["Back"] + ":20:300",       # BACK -> standby
    "-1:0:1:31:0:200",                       # tail: no key
)

ADDR_RE = re.compile(r"^0x([0-9a-fA-F]+)")


def available() -> bool:
    return QEMU_BIN is not None


def n_steps(keyseq: str) -> int:
    return len([s for s in keyseq.split(";") if s.strip()])


def static_gates(stock_bytes: bytes, modded_bytes: bytes, offset: int) -> tuple[list[str], list[str], list[str]]:
    fails, warns, infos = [], [], []
    infos.append(f"write target: flash {FLASH_BASE + offset:#010x} (offset {offset:#x}), one 4KB sector")
    diffs = [i for i in range(FLASH_SIZE) if stock_bytes[i] != modded_bytes[i]]
    if not diffs:
        warns.append("modded image is byte-identical to stock (no change applied?)")
    else:
        lo, hi = min(diffs), max(diffs)
        infos.append(f"{len(diffs)} bytes differ, range {FLASH_BASE+lo:#x}..{FLASH_BASE+hi:#x}")
        if lo < offset or hi >= offset + SECTOR_SIZE:
            fails.append(f"changes fall OUTSIDE the declared sector [{offset:#x},{offset+SECTOR_SIZE:#x}) "
                         f"- image diff spans {lo:#x}..{hi:#x}")
    for a, b, name in BOOTCRIT:
        if offset < b and (offset + SECTOR_SIZE) > a:
            fails.append(f"write overlaps boot-critical region {name} [{a:#x},{b:#x}) - refusing")
    warns.append("harness cannot verify calibration safety (per-unit calibration lives on the "
                 "separate 16MB data chip, not this program-flash image) - rely on a verified "
                 "full backup of the real unit before ever flashing a derived patch")
    return fails, warns, infos


def sector_exec_ranges(offset: int) -> list[tuple[int, int]]:
    """Address ranges where code from the patched sector executes: its flash VA, plus its IRAM
    copy if it lies inside the boot stub's IRAM load image."""
    lo, hi = FLASH_BASE + offset, FLASH_BASE + offset + SECTOR_SIZE
    ranges = [(lo, hi)]
    load_hi = LOAD_SRC + (LOAD_END - LOAD_DST)
    a, b = max(lo, LOAD_SRC), min(hi, load_hi)
    if a < b:
        ranges.append((LOAD_DST + (a - LOAD_SRC), LOAD_DST + (b - LOAD_SRC)))
    return ranges


class BootRun:
    """One QEMU boot of one composed image, driven by a key script, stopped on completion."""

    def __init__(self, name: str, image: bytes, rundir: pathlib.Path, iram: bytes,
                 keyseq: str):
        self.name = name
        self.rundir = rundir
        self.rundir.mkdir(parents=True, exist_ok=True)
        self.n_steps = n_steps(keyseq)
        self.marker = f"KEYSEQ -> step {self.n_steps}"
        img = rundir / "image.bin"
        img.write_bytes(image)
        iram_p = rundir / "iram.bin"
        iram_p.write_bytes(iram)
        sram_p = rundir / "sram.bin"
        sram_p.write_bytes(b"\x00" * 0x8000)
        # -d in_asm with no -D: QEMU's log goes to stderr, the same stream the board model's
        # KEYSEQ/GRAMDUMP lines use, so translated code and screen events are ordered together.
        cmd = qemu_run.build_cmd(QEMU_BIN, img, iram_p, sram_p, vnc=None, gdb=False,
                                 extra=ICOUNT + ["-d", "in_asm"])
        env = qemu_run.build_env(rundir, keyseq, None)
        self.log_path = rundir / "qemu.log"
        self._logf = open(self.log_path, "wb")
        self.proc = subprocess.Popen(cmd, stdout=self._logf, stderr=subprocess.STDOUT, env=env)
        self.start = time.monotonic()
        self.completed = False
        self.exited_early = False
        self.elapsed = 0.0

    def _marker_seen(self) -> bool:
        # The log is large (in_asm); scan only the tail written since the last poll.
        try:
            with open(self.log_path, "rb") as f:
                f.seek(getattr(self, "_pos", 0))
                chunk = f.read()
                self._pos = max(0, f.tell() - 64)
        except OSError:
            return False
        return (self.marker + "\n").encode() in chunk

    def poll(self, timeout: float) -> bool:
        """Returns True once this run is finished (completed, exited, or timed out)."""
        if self.proc.poll() is not None:
            self.completed = self._marker_seen() or self.completed
            self.exited_early = not self.completed
            return True
        if self._marker_seen():
            self.completed = True
            return True
        return time.monotonic() - self.start >= timeout

    def stop(self) -> None:
        self.elapsed = time.monotonic() - self.start
        if self.proc.poll() is None:
            self.proc.terminate()
            try:
                self.proc.wait(timeout=10)
            except subprocess.TimeoutExpired:
                self.proc.kill()
                self.proc.wait(timeout=10)
        self._logf.close()

    def parse(self) -> dict:
        """Frames, translated addresses, crashes, and steps - everything up to the completion
        marker (or the end of the log if the script never completed)."""
        frames, addrs, crashes = [], set(), 0
        step = 0
        with open(self.log_path, errors="replace") as f:
            for line in f:
                m = ADDR_RE.match(line)
                if m:
                    addrs.add(int(m.group(1), 16))
                    continue
                if line.rstrip("\r\n") == self.marker:
                    break
                m = qemu_run.STEP_RE.search(line)
                if m:
                    step = int(m.group(1))
                    continue
                m = qemu_run.GRAMDUMP_RE.search(line)
                if m:
                    idx, nonblack = int(m.group(1)), int(m.group(2))
                    p = self.rundir / f"gram.raw.{idx:03d}"
                    digest = hashlib.sha256(p.read_bytes()).hexdigest()[:16] if p.exists() else None
                    frames.append({"idx": idx, "step": step, "nonblack": nonblack, "sha": digest})
                    continue
                if qemu_run.CRASH_RE.search(line):
                    crashes += 1
        return {"frames": frames, "addrs": addrs, "crashes": crashes, "last_step": step,
                "completed": self.completed, "exited_early": self.exited_early,
                "returncode": self.proc.returncode, "elapsed": self.elapsed}


def _frame_key(fr: dict) -> tuple:
    return (fr["step"], fr["nonblack"], fr["sha"])


def compare_frames(fs: list[dict], fm: list[dict]) -> str | None:
    """None if identical, else a one-line description of the first divergence."""
    for i in range(max(len(fs), len(fm))):
        a = fs[i] if i < len(fs) else None
        b = fm[i] if i < len(fm) else None
        if a is None or b is None or _frame_key(a) != _frame_key(b):
            def desc(fr):
                if fr is None:
                    return "(no frame)"
                return f"frame {fr['idx']} at key step {fr['step']}: nonblack={fr['nonblack']}"
            same_count = (a is not None and b is not None and a["nonblack"] == b["nonblack"])
            extra = " (same pixel count, different pixels)" if same_count else ""
            return f"settled frame #{i} differs - stock {desc(a)}; patched {desc(b)}{extra}"
    return None


def verify(base_path: pathlib.Path, sector_bytes: bytes, offset: int,
           iram_path: pathlib.Path | None = None, keyseq: str = PROBE_KEYSEQ,
           timeout: float = 300.0, keep_dir: pathlib.Path | None = None) -> dict:
    """Compose stock and patched images, boot both under the probe key script, compare.

    Never raises for an expected emulator-side outcome; the verdict says what happened.
    `base_path` must be a full 1 MB program-flash image (compose_qemu_image's requirement)."""
    result = {
        "infos": [], "warns": [], "fails": [], "verdict": None,
        "stock": None, "patched": None,
        "outside_mod_sample": [], "outside_stock_sample": [],
        "frames_stock": [], "frames_patched": [], "keep_dir": None,
    }

    def finish(verdict: str) -> dict:
        result["verdict"] = verdict
        return result

    if len(sector_bytes) != SECTOR_SIZE or offset % SECTOR_SIZE or not 0 <= offset < FLASH_SIZE:
        result["fails"].append(f"bad sector/offset ({len(sector_bytes)} bytes @ {offset:#x})")
        return finish("FAIL")
    if offset == compose_qemu_image.ALPU_SECTOR_OFFSET:
        result["warns"].append(f"sector {FLASH_BASE+offset:#010x} is replaced wholesale by the "
                               f"{QEMU_ONLY_SECTORS[offset]} - the emulated image cannot contain "
                               f"this patch")
        return finish("INCONCLUSIVE")

    base = base_path.read_bytes()
    if len(base) != FLASH_SIZE:
        result["warns"].append(f"base image {base_path} is {len(base)} bytes; the emulator needs "
                               f"a full {FLASH_SIZE:#x}-byte program-flash image (e.g. "
                               f"{DEFAULT_BASE.name})")
        return finish("INCONCLUSIVE")
    modded = bytearray(base)
    modded[offset:offset + SECTOR_SIZE] = sector_bytes
    fails, warns, infos = static_gates(base, bytes(modded), offset)
    result["fails"] += fails
    result["warns"] += warns
    result["infos"] += infos
    if fails:
        return finish("FAIL")

    work = pathlib.Path(tempfile.mkdtemp(prefix="qemu_boot_diff_"))
    try:
        sector_file = work / f"sector_{FLASH_BASE+offset:08x}.bin"
        sector_file.write_bytes(sector_bytes)
        try:
            img_stock, sum_stock = compose_qemu_image.compose(base_path, None, [], qemu_only=True)
            img_mod, sum_mod = compose_qemu_image.compose(
                base_path, None, [f"{sector_file}@{offset:#x}"], qemu_only=True)
        except compose_qemu_image.ComposeError as e:
            result["warns"].append(f"could not compose an emulator-bootable image: {e}")
            if offset in QEMU_ONLY_SECTORS:
                result["warns"].append(f"the patch changes the {QEMU_ONLY_SECTORS[offset]} site "
                                       f"the emulator needs patched - not testable under QEMU")
            return finish("INCONCLUSIVE")
        result["infos"].append("both images composed via compose_qemu_image.compose(); "
                               + sum_stock[-1])
        if len(sector_exec_ranges(offset)) > 1:
            result["infos"].append("sector lies inside the IRAM load image - its IRAM copy is "
                                   "treated as part of the patch too")

        if iram_path is not None:
            iram_s = iram_m = iram_path.read_bytes()
            result["infos"].append(f"IRAM preload: {iram_path} (both boots)")
        else:
            iram_s, iram_m = derive_iram(img_stock), derive_iram(img_mod)
            result["infos"].append("IRAM preload: derived from each composed image")

        steps = n_steps(keyseq)
        result["infos"].append(f"probe key script ({steps} steps): {keyseq}")
        runs = [BootRun("stock", img_stock, work / "stock", iram_s, keyseq),
                BootRun("patched", img_mod, work / "patched", iram_m, keyseq)]
        # Both boots run in parallel (-icount makes each deterministic regardless of load). A
        # hung patched image never logs the completion marker, so once stock has completed, the
        # patched run gets STALL_FACTOR x stock's time (+ STALL_SLACK s), not the full timeout.
        limits = {r.name: timeout for r in runs}
        pending = list(runs)
        while pending:
            time.sleep(0.5)
            for r in list(pending):
                if r.poll(limits[r.name]):
                    r.stop()
                    pending.remove(r)
                    if r.name == "stock" and r.completed:
                        limits["patched"] = min(timeout, r.elapsed * STALL_FACTOR + STALL_SLACK)
        rs, rm = runs[0].parse(), runs[1].parse()
        result["stock"] = {k: v for k, v in rs.items() if k != "addrs"} | {"addrs": len(rs["addrs"])}
        result["patched"] = {k: v for k, v in rm.items() if k != "addrs"} | {"addrs": len(rm["addrs"])}
        result["frames_stock"], result["frames_patched"] = rs["frames"], rm["frames"]

        # --- stock sanity: is the harness itself working? ---
        stock_problem = None
        if not rs["completed"]:
            stock_problem = (f"stock did not complete the probe key script (reached step "
                             f"{rs['last_step']}/{steps} in {rs['elapsed']:.0f}s"
                             + (", qemu exited" if rs["exited_early"] else ", timed out") + ")")
        elif not any(f["nonblack"] and f["step"] == 0 for f in rs["frames"]):
            stock_problem = "stock never put a settled screen up before the first key press"
        if stock_problem:
            result["warns"].append(stock_problem + " - harness/emulator problem, cannot compare")
            return finish("INCONCLUSIVE")
        result["infos"].append(f"stock reached standby and completed the probe in "
                               f"{rs['elapsed']:.0f}s ({len(rs['frames'])} settled frames)")

        # --- patched image ---
        if rm["crashes"]:
            result["fails"].append(f"patched image hit {rm['crashes']} emulator execution "
                                   f"fault(s) ('Execution cannot ...')")
        if not rm["completed"]:
            result["fails"].append(
                f"patched image did not complete the probe key script (reached step "
                f"{rm['last_step']}/{steps}"
                + (", qemu exited" if rm["exited_early"]
                   else f", still not done after {rm['elapsed']:.0f}s vs stock's {rs['elapsed']:.0f}s")
                + ") - hang, crash or boot regression")
        if rs["crashes"] and not rm["crashes"]:
            result["warns"].append(f"stock hit {rs['crashes']} execution fault(s), patched none")

        frame_diff = compare_frames(rs["frames"], rm["frames"])
        if frame_diff:
            result["warns"].append("SCREENS DIFFER: " + frame_diff)

        ranges = sector_exec_ranges(offset)

        def in_patch(a: int) -> bool:
            return any(lo <= a < hi for lo, hi in ranges)

        outside_mod = sorted(a for a in rm["addrs"] - rs["addrs"] if not in_patch(a))
        outside_stock = sorted(a for a in rs["addrs"] - rm["addrs"] if not in_patch(a))
        inside_mod = sum(1 for a in rm["addrs"] if in_patch(a))
        result["infos"].append(f"translated code addresses: stock {len(rs['addrs'])}, patched "
                               f"{len(rm['addrs'])}; {inside_mod} inside the patched sector ran "
                               f"in the patched image")
        if outside_mod:
            result["warns"].append(f"{len(outside_mod)} code address(es) ran in PATCHED but not "
                                   f"stock, outside the patched sector")
            result["outside_mod_sample"] = [f"{a:#010x}" for a in outside_mod[:5]]
        if outside_stock:
            result["warns"].append(f"{len(outside_stock)} code address(es) ran in STOCK but not "
                                   f"patched, outside the patched sector")
            result["outside_stock_sample"] = [f"{a:#010x}" for a in outside_stock[:5]]

        if result["fails"]:
            return finish("FAIL")
        if frame_diff:
            return finish("DIFFERS")
        if outside_mod or outside_stock:
            return finish("PASS with warnings")
        return finish("PASS")
    finally:
        if keep_dir is not None:
            keep_dir.mkdir(parents=True, exist_ok=True)
            for sub in ("stock", "patched"):
                src = work / sub
                if src.exists():
                    dst = keep_dir / sub
                    if dst.exists():
                        shutil.rmtree(dst)
                    shutil.copytree(src, dst)
                    # The booted image carries the QEMU-only patches (ALPU-MP bypass etc.) and
                    # must never be flashed; name it so nobody mistakes it for a patch artifact.
                    img = dst / "image.bin"
                    if img.exists():
                        img.rename(dst / "image_QEMU_ONLY_NEVER_FLASH.bin")
            result["keep_dir"] = str(keep_dir)
        shutil.rmtree(work, ignore_errors=True)
