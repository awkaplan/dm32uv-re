"""Launch and babysit one `-M dm32` QEMU run, then summarize what it did.

WHY THIS EXISTS: every ad-hoc QEMU invocation in this project's history has hand-built the same
command line (image/IRAM/SRAM loader devices, the `DM32_KEYLOG`/`DM32_GRAMDUMP`/`DM32_GRAMSEQ`/
`DM32_ADC_CH2` env vars, a VNC or headless display choice) and then manually tailed the log to
see whether it was making progress or stuck. This script is that invocation plus the babysitting
loop, so a UI-navigation session is one command instead of a remembered incantation.

QEMU command line (always exactly this shape):
    <qemu> -M dm32 -cpu ck803 -vnc <...> -monitor none \\
        -serial <--serial, default file:<rundir>/uart0.txt> -serial <--serial1, default null> [-s] \\
        -d unimp,guest_errors,invalid_mem -D <rundir>/qemu-d.log   (see "QEMU logging" below) \\
        -kernel <image> \\
        -device loader,file=<iram>,addr=0x00010000 \\
        -device loader,file=<sram>,addr=0x18000000 \\
        <extra>

Environment always set: DM32_KEYLOG=1 DM32_GRAMDUMP=<rundir>/gram.raw DM32_GRAMSEQ=1
DM32_ADC_CH2=0x300, plus DM32_SPINOR=<spinor> when --spinor is given. stdout+stderr both go to
<rundir>/qemu.log.

SERIAL PORTS. QEMU numbers the -serial options in order: the first is serial_hd(0) = UART0
(0x14030000, PIC 12), the second serial_hd(1) = UART1 (0x14040000, PIC 10, stock's GPS port).
`--serial` sets the first, `--serial1` the second; the defaults are a file capture of UART0 and
a null UART1. Accepted SPEC values are any QEMU -serial argument, e.g.:
    file:<path>                      capture TX bytes to a file (default for UART0)
    null                             drop everything (what every runner did before this option)
    pty                              QEMU allocates a host pseudo-terminal and prints its name
    tcp:127.0.0.1:5555,server,nowait  QEMU listens on TCP; attach with any TCP client
To DRIVE the CPS serial protocol (or any host-side serial conversation), use the TCP form, which
lets the host connect and talk while the guest runs:
    qemu_run.py --image ... --serial tcp:127.0.0.1:5555,server,nowait
    # then, from the host:  nc 127.0.0.1 5555   (or a Python socket) - bytes you send arrive at the
    # guest's UART0 RX, and the guest's UART0 TX appears on the socket.
The `pty` form is the alternative: QEMU prints "char device redirected to /dev/ttysNNN", and a
host tool opens that device. The TCP form is simpler to script; `nowait` lets QEMU run before a
client connects (without it QEMU blocks until one does). Note that the run is killed at the end
unless --keep is given, so connect while the babysitter is still waiting.

QEMU LOGGING. Unless --no-qemu-log is given or --extra already contains -d or -D, QEMU is started
with `-d unimp,guest_errors,invalid_mem -D <rundir>/qemu-d.log`. This captures two things that
were previously silent:
    "<name>: unimplemented device read|write (...)"   accesses to an unimplemented-device window
                                                       (hw/misc/unimp.c, LOG_UNIMP)
    "Invalid read|write at addr 0x..., ..."           accesses to an address no region covers
                                                       (system/memory.c, LOG_INVALID_MEM)
After the run the counts are appended to the first output line as `unimp=N invalid=M` (with `-`
in place of the numbers when logging is off).

If --vnc is given, `-vnc 0.0.0.0:<N>` is added (all interfaces, so a port published from the
Docker container is reachable), plus `-L $QEMU_PC_BIOS_DIR` when that variable is set (the Docker
image sets it): QEMU aborts at VNC start-up without its keymap files (see
vendor/dm32uv-qemu/docs/running.md). If --vnc is NOT given, `-display none` is passed instead
(there is no graphical console to show, and QEMU should not try to open one).

KEYSEQ GRAMMAR (DM32_KEYSEQ, passed via --keyseq, consumed by vendor/dm32uv-qemu/hw/gpio/dm32_gpio.c):

    cb:cbit:rb:rbit:hold:gap;cb:cbit:rb:rbit:hold:gap;...

Each step forces one key for `hold` row-bank data reads, then releases it for `gap` reads,
then the sequence advances to the next step. `cb`/`cbit` is the GPIOC column bit driven (bank
2, the keypad matrix's column driver); `rb`/`rbit` is the GPIOB row bit read back (bank 1).
`cb=-1` means a DEDICATED input pin (not part of the column-scanned matrix, e.g. the side keys
SK1/SK2 on GPIOB 19/20, or the MENU step below; Up and Down are matrix keys) - in that case
`rb:rbit` is forced low on every read while the step is active, with no column condition at all. A lead-in step with `hold=0` only delays (it never forces anything,
since `reads < 0` is never true) before the real sequence starts.

Measured key table (GPIOC column bit : GPIOB row bit), each step confirmed to produce the expected
key in stock firmware under this model. Which side the physical keypad drives is a separate, open
question (vendor/dm32uv-qemu/docs/key-injection.md, "Open questions"); these steps work either way:

    Ok    = 2:7:1:17      '1' = 2:7:1:20      '2' = 2:7:1:19      '3' = 2:7:1:18
    '4'   = 2:8:1:20      '5' = 2:8:1:19      '6' = 2:8:1:18      P1  = 2:8:1:17
    '7'   = 2:9:1:20      '8' = 2:9:1:19      '9' = 2:9:1:18      P2  = 2:9:1:17
    '*'   = 2:10:1:20     '0' = 2:10:1:19     '#' = 2:10:1:18     Back= 2:10:1:17
    Up    = 2:11:1:17     Down = 2:11:1:18

MENU key from standby (a dedicated input pin, held 20 reads then release-settle for 120):

    -1:0:1:17:20:120

Other scripts/notes should build KEYSEQ strings with this module's `keyseq()` helper and the
`KEYS` dict rather than hand-typing the cb:cbit:rb:rbit numbers again. Named scripts live in
data/keyseq_scenarios.json: `--keyseq-name NAME` resolves one via keyseq_lib.py (mutually
exclusive with --keyseq), and when it is given and --until-step is not, the scenario's own
until_step is used. `python3 tools/src/dm32_patch_tools/keyseq_lib.py list` shows the names.

`--json [PATH]` emits one compact JSON object after the human summary - to PATH when given, or
as the final stdout line when PATH is "-" (the default), so an agent can take the last line:
{"tag","rundir","image","steps","crashes","muxwarns","unimp","invalid","elapsed_s",
"token_line","frames":[{"idx","step","nonblack","matches":[...]}]}. "matches" names the
screens that non-black count could be, resolved from data/screen_fingerprints.json by
fingerprints.py; it is omitted per-run if that lookup fails (the pixel counts are still there).

Stopping conditions (whichever fires first): --until-step N is reached (optionally followed by
--settle-after more seconds), the step counter stalls for --stall-seconds, or --timeout is hit.
On exit, unless --keep, the QEMU process is killed.
"""
from __future__ import annotations

import argparse
import json
import os
import pathlib
import re
import signal
import subprocess
import sys
import time

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
DEFAULT_IRAM = REPO_ROOT / "data" / "firmware" / "IRAM_dm32.00.01.048.bin"   # derive_iram.py


def keyseq(*steps: str) -> str:
    """Join KEYSEQ step strings (each "cb:cbit:rb:rbit:hold:gap") into one DM32_KEYSEQ value."""
    return ";".join(steps)


# Measured key table: "cb:cbit:rb:rbit" (hold/gap are supplied by the caller, since how long to
# hold is a per-use choice, not a property of the key). See module docstring for the derivation.
KEYS = {
    "Ok": "2:7:1:17",
    "1": "2:7:1:20", "2": "2:7:1:19", "3": "2:7:1:18",
    "4": "2:8:1:20", "5": "2:8:1:19", "6": "2:8:1:18", "P1": "2:8:1:17",
    "7": "2:9:1:20", "8": "2:9:1:19", "9": "2:9:1:18", "P2": "2:9:1:17",
    "*": "2:10:1:20", "0": "2:10:1:19", "#": "2:10:1:18", "Back": "2:10:1:17",
    "Up": "2:11:1:17", "Down": "2:11:1:18",
    "Menu": "-1:0:1:17",  # dedicated input pin; caller still supplies :hold:gap
}


STEP_RE = re.compile(r"KEYSEQ -> step (\d+)")
GRAMDUMP_RE = re.compile(r"GRAMDUMP\[(\d+)\] settled: nonblack=(\d+)")
CRASH_RE = re.compile(r"Execution cannot")
# The model prints the mux warning once per run; the per-write count is the lcd_mux field of the
# dm32-events: line it prints at exit (vendor/dm32uv-qemu/hw/csky/dm32.c).
MUXWARN_RE = re.compile(r"DATA write while IO_DIPLEX2")
MUXCOUNT_RE = re.compile(r"^dm32-events:.*\blcd_mux=(\d+)")


UNIMP_RE = re.compile(r"unimplemented device (read|write)")
INVALID_RE = re.compile(r"Invalid (read|write) at addr")


def build_cmd(qemu: str, image: pathlib.Path, iram: pathlib.Path, sram: pathlib.Path,
              vnc: int | None, gdb: bool, extra: list[str], serial0: str = "null",
              serial1: str = "null", qemu_log: pathlib.Path | None = None) -> list[str]:
    cmd = [qemu, "-M", "dm32", "-cpu", "ck803"]
    if vnc is not None:
        cmd += ["-vnc", f"0.0.0.0:{vnc}"]
        if os.environ.get("QEMU_PC_BIOS_DIR"):
            cmd += ["-L", os.environ["QEMU_PC_BIOS_DIR"]]
    else:
        cmd += ["-display", "none"]
    cmd += ["-monitor", "none", "-serial", serial0, "-serial", serial1]
    if gdb:
        cmd += ["-s"]
    if qemu_log is not None:
        cmd += ["-d", "unimp,guest_errors,invalid_mem", "-D", str(qemu_log)]
    cmd += ["-kernel", str(image)]
    cmd += ["-device", f"loader,file={iram},addr=0x00010000"]
    cmd += ["-device", f"loader,file={sram},addr=0x18000000"]
    cmd += extra
    return cmd


def build_env(rundir: pathlib.Path, keyseq_str: str | None, spinor: pathlib.Path | None) -> dict:
    env = dict(os.environ)
    env["DM32_KEYLOG"] = "1"
    env["DM32_GRAMDUMP"] = str(rundir / "gram.raw")
    env["DM32_GRAMSEQ"] = "1"
    env["DM32_ADC_CH2"] = "0x300"
    if keyseq_str:
        env["DM32_KEYSEQ"] = keyseq_str
    if spinor is not None:
        env["DM32_SPINOR"] = str(spinor)
    return env


def count_qemu_log(qemu_d_log: pathlib.Path) -> tuple[int, int]:
    """Returns (unimplemented-device accesses, invalid/unassigned accesses) from a -d log."""
    if not qemu_d_log.exists():
        return 0, 0
    unimp = invalid = 0
    with open(qemu_d_log, errors="replace") as f:
        for line in f:
            if UNIMP_RE.search(line):
                unimp += 1
            if INVALID_RE.search(line):
                invalid += 1
    return unimp, invalid


def summarize_log(log_path: pathlib.Path) -> tuple[int, int, int, str]:
    """Returns (crash_count, muxwarn_count, elapsed-ish step count, token line)."""
    if not log_path.exists():
        return 0, 0, 0, ""
    tokens: list[str] = []
    crashes = 0
    muxwarns = 0
    steps_seen = 0
    with open(log_path, errors="replace") as f:
        for line in f:
            if CRASH_RE.search(line):
                crashes += 1
            if MUXWARN_RE.search(line):
                muxwarns = max(muxwarns, 1)
            m = MUXCOUNT_RE.search(line)
            if m:
                muxwarns = max(muxwarns, int(m.group(1)))
                continue
            m = GRAMDUMP_RE.search(line)
            if m:
                tokens.append(f"F{m.group(1)}:{m.group(2)}")
                continue
            m = STEP_RE.search(line)
            if m:
                tokens.append(f"S{m.group(1)}")
                steps_seen = int(m.group(1))
    return crashes, muxwarns, steps_seen, " ".join(tokens)


def summarize_frames(log_path: pathlib.Path) -> list[dict]:
    """Ordered GRAM frames from a qemu.log as [{"idx","step","nonblack"}].

    "idx" is the GRAMDUMP[i] frame number (the gram.raw.NNN suffix), "step" is the KEYSEQ
    step counter in force when the frame settled (0 until the first KEYSEQ line - the same
    tracking summarize_log uses), "nonblack" the settled non-black pixel count. This is the
    frame-list side of summarize_log (which keeps its 4-tuple signature); qemu_run.py --json
    and the tests use it.
    """
    frames: list[dict] = []
    if not log_path.exists():
        return frames
    step = 0
    with open(log_path, errors="replace") as f:
        for line in f:
            m = STEP_RE.search(line)
            if m:
                step = int(m.group(1))
                continue
            m = GRAMDUMP_RE.search(line)
            if m:
                frames.append({"idx": int(m.group(1)), "step": step,
                               "nonblack": int(m.group(2))})
    return frames


def babysit(proc: subprocess.Popen, log_path: pathlib.Path, until_step: int | None,
            stall_seconds: float, timeout: float, settle_after: float) -> None:
    start = time.monotonic()
    last_step = -1
    last_step_change = start
    reached_until = False
    reached_until_at = None

    while True:
        time.sleep(2)
        now = time.monotonic()
        elapsed = now - start

        if proc.poll() is not None:
            print(f"qemu exited on its own after {elapsed:.0f}s (returncode {proc.returncode})")
            return

        _, _, step, _ = summarize_log(log_path)
        if step != last_step:
            last_step = step
            last_step_change = now

        if until_step is not None and not reached_until and step >= until_step:
            reached_until = True
            reached_until_at = now
            print(f"t={elapsed:.0f}s: reached step {step} >= --until-step {until_step}, "
                  f"settling {settle_after}s more")

        if reached_until and (now - reached_until_at) >= settle_after:
            print(f"t={elapsed:.0f}s: settle period done, stopping")
            return

        if (now - last_step_change) >= stall_seconds and not reached_until:
            print(f"t={elapsed:.0f}s: step counter stalled at {last_step} for "
                  f">= {stall_seconds}s, stopping")
            return

        if elapsed >= timeout:
            print(f"t={elapsed:.0f}s: --timeout {timeout}s reached, stopping")
            return


def main() -> None:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", required=True, type=pathlib.Path,
                     help="bootable image (from compose_qemu_image.py)")
    ap.add_argument("--qemu", default="qemu-system-cskyv2",
                     help="qemu binary (default: qemu-system-cskyv2, found on PATH inside the "
                          "repo's Docker image)")
    ap.add_argument("--iram", type=pathlib.Path, default=DEFAULT_IRAM,
                     help=f"IRAM loader image (default: {DEFAULT_IRAM.relative_to(REPO_ROOT)})")
    ap.add_argument("--sram", type=pathlib.Path, default=None,
                     help="32KiB SRAM loader image (default: create a zero file in the run dir)")
    ap.add_argument("--spinor", type=pathlib.Path, default=None,
                     help="codeplug SPI-NOR image (default: none - all-0xFF chip, stock "
                          "firmware boots to a 'Null Ch.' standby screen, fine for UI work)")
    keyseq_group = ap.add_mutually_exclusive_group()
    keyseq_group.add_argument("--keyseq", default=None,
                              help="DM32_KEYSEQ string (see module docstring)")
    keyseq_group.add_argument("--keyseq-name", default=None, metavar="NAME",
                              help="name of a keyseq scenario in data/keyseq_scenarios.json "
                                   "(see `python3 tools/src/dm32_patch_tools/keyseq_lib.py "
                                   "list`); mutually exclusive with --keyseq. When given and "
                                   "--until-step is not, the scenario's until_step is used.")
    ap.add_argument("--json", nargs="?", const="-", default=None, metavar="PATH",
                    help="also emit one compact JSON object after the human summary - to PATH "
                         "when given, or as the final stdout line when PATH is '-' (default). "
                         "See the module docstring for the fields.")
    ap.add_argument("--rundir", type=pathlib.Path, default=None,
                     help="run directory (default: ./qemu-run/<tag>)")
    ap.add_argument("--tag", default=None, help="tag used to build the default --rundir")
    ap.add_argument("--vnc", type=int, default=None, metavar="N",
                     help="VNC display number (adds -vnc 0.0.0.0:N); omit for -display none")
    ap.add_argument("--gdb", action="store_true", help="adds -s (GDB stub on :1234)")
    ap.add_argument("--serial", default="file:{rundir}/uart0.txt", metavar="SPEC",
                     help="-serial backend for UART0 (serial_hd(0)); {rundir} is substituted. "
                          "Default: file:<rundir>/uart0.txt. Use 'null' for the old behaviour, or "
                          "tcp:127.0.0.1:5555,server,nowait to drive the CPS protocol from the host "
                          "(see module docstring)")
    ap.add_argument("--serial1", default="null", metavar="SPEC",
                     help="-serial backend for UART1 (serial_hd(1), stock's GPS port). Default: null")
    ap.add_argument("--no-qemu-log", action="store_true",
                     help="do not pass -d/-D (no <rundir>/qemu-d.log, no unimp/invalid counts)")
    ap.add_argument("--extra", default="", help="raw extra QEMU args, space-separated")
    ap.add_argument("--until-step", type=int, default=None, metavar="N",
                     help="stop when the log shows 'KEYSEQ -> step N'")
    ap.add_argument("--stall-seconds", type=float, default=90,
                     help="stop when the step counter hasn't advanced for this long (default 90)")
    ap.add_argument("--timeout", type=float, default=600, help="overall timeout in seconds (default 600)")
    ap.add_argument("--settle-after", type=float, default=20,
                     help="seconds to keep running after --until-step is reached (default 20)")
    ap.add_argument("--keep", action="store_true", help="do not kill QEMU at the end")
    args = ap.parse_args()

    # Lazy sibling-module import: keyseq_lib.py is a plain module in this directory, imported by
    # bare name after the sys.path dance (the same pattern verify_patch.py uses for
    # qemu_boot_diff). It imports this module for KEYS - safe, because main() only runs under
    # __main__, so the import never recurses into a second run.
    sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
    keyseq_str = args.keyseq
    if args.keyseq_name is not None:
        import keyseq_lib
        try:
            keyseq_str, scenario = keyseq_lib.resolve_keyseq(args.keyseq_name)
        except ValueError as e:
            print(f"error: {e}", file=sys.stderr)
            sys.exit(2)
        if scenario is not None and args.until_step is None:
            args.until_step = scenario["until_step"]

    tag = args.tag or time.strftime("%Y%m%d-%H%M%S")
    rundir = args.rundir or (pathlib.Path("qemu-run") / tag)
    rundir.mkdir(parents=True, exist_ok=True)
    run_start = time.monotonic()

    sram = args.sram
    if sram is None:
        sram = rundir / "sram.bin"
        sram.write_bytes(b"\x00" * 0x8000)

    extra = args.extra.split() if args.extra else []
    serial0 = args.serial.replace("{rundir}", str(rundir))
    qemu_d_log = rundir / "qemu-d.log"
    # The default -d/-D is skipped when the caller already supplies one (their -d/-D wins).
    use_qemu_log = not args.no_qemu_log and not any(t in ("-d", "-D") for t in extra)
    cmd = build_cmd(args.qemu, args.image, args.iram, sram, args.vnc, args.gdb, extra,
                    serial0=serial0, serial1=args.serial1,
                    qemu_log=qemu_d_log if use_qemu_log else None)
    env = build_env(rundir, keyseq_str, args.spinor)
    log_path = rundir / "qemu.log"

    print("launching:", " ".join(cmd))
    with open(log_path, "wb") as logf:
        proc = subprocess.Popen(cmd, stdout=logf, stderr=subprocess.STDOUT, env=env)

        try:
            babysit(proc, log_path, args.until_step, args.stall_seconds, args.timeout,
                    args.settle_after)
        except KeyboardInterrupt:
            print("interrupted")

        if not args.keep and proc.poll() is None:
            proc.send_signal(signal.SIGTERM)
            try:
                proc.wait(timeout=10)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait(timeout=10)

    crashes, muxwarns, last_step, tokens = summarize_log(log_path)
    elapsed_total = time.monotonic() - run_start
    if use_qemu_log:
        unimp_n, invalid_n = count_qemu_log(qemu_d_log)
        unimp_s, invalid_s = str(unimp_n), str(invalid_n)
    else:
        unimp_s = invalid_s = "-"
    print(f"t={elapsed_total:.0f} steps={last_step} crash={crashes} muxwarn={muxwarns} "
          f"unimp={unimp_s} invalid={invalid_s}")
    print(tokens)
    print(f"log: {log_path}")
    print(f"frames: {rundir}/gram.raw.NNN")

    if args.json is not None:
        frames = summarize_frames(log_path)
        try:
            # Same bare-name sibling import as keyseq_lib above; degraded to "no matches" on
            # any failure (missing/corrupt data/screen_fingerprints.json must not fail a run).
            import fingerprints
            frames = fingerprints.describe(frames)
        except Exception:
            pass
        payload = {
            "tag": tag,
            "rundir": str(rundir),
            "image": str(args.image),
            "steps": last_step,
            "crashes": crashes,
            "muxwarns": muxwarns,
            "unimp": unimp_n if use_qemu_log else None,
            "invalid": invalid_n if use_qemu_log else None,
            "elapsed_s": round(elapsed_total, 1),
            "token_line": tokens,
            "frames": frames,
        }
        line = json.dumps(payload, separators=(",", ":"))
        if args.json == "-":
            print(line)
        else:
            pathlib.Path(args.json).write_text(line + "\n")


if __name__ == "__main__":
    main()
