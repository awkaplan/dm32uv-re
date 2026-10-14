#!/usr/bin/env python3
"""Verify a manifest-built patch against its own declared expectations, under QEMU.

WHY THIS EXISTS: verify_patch.py answers "is this one modded sector safe" (boot diff, one fixed
probe). A manifest patch is bigger than that: it has its own screens, its own key path, and its
own idea of what "works" looks like. Until now that verification was hand-assembled - compose a
bootable image, run qemu_run.py, eyeball the token line's pixel counts against the README. This
tool makes the manifest the complete, self-describing unit of work: a "verify" block declares
the key script and the expected settled frames, and this script boots the patched image, drives
that script, and answers PASS/DIFFERS/FAIL/INCONCLUSIVE in JSON an agent can act on.

THE "verify" MANIFEST BLOCK (also documented in build_manifest_patch.py's docstring; the builder
copies it verbatim into summary.json but otherwise ignores it):

    "verify": {
      "keyseq": "snake-walkthrough",       # a name from data/keyseq_scenarios.json,
                                           # or a raw DM32_KEYSEQ string (qemu_run.py docstring)
      "until_step": 11,                    # optional; default: the named scenario's own
                                           # until_step, else the keyseq's step count
      "settle_after": 20,                  # optional, seconds after until_step (default 20)
      "timeout": 600,                      # optional, seconds (default 600)
      "expect_frames": [                   # the settled screens the run must produce
        0,                                 #   exact non-black pixel count
        {"min": 13300, "max": 14300},      #   a range
        {"name": "snake-category-sublist"} #   a fingerprint from data/screen_fingerprints.json
      ]
    }

MATCHING RULE: expect_frames is matched as an ORDERED SUBSEQUENCE of the observed settled
frames - each expected element must match at least one observed frame, in order, and extra
observed frames are allowed anywhere (boot-timing stragglers like the optional 2993 frame in the
Snake run are exactly why). An element matches a frame when: an int equals the frame's non-black
count; {"min","max"} contains it; {"name"} is one of the fingerprints matching that count (the
run's own "matches" list, or fingerprints.matches() as a fallback). Extra observed frames are
reported as info, never a failure. The token line's frame ORDER varies with host load in the
stock firmware too - pixel counts are compared, not frame indices (docs/qemu-workflow.md).

VERDICTS AND EXIT STATUS (mirrors verify_patch.py):
    PASS         0  every expected element matched, no crashes
    FAIL         1  the build failed, or the run crashed / produced zero frames
    (usage)      2  bad arguments, or an invalid verify block (the message names the field)
    DIFFERS      3  the run completed but some expected element matched nothing - expected when
                    the patch deliberately changes the screen sequence; review the kept frames
    INCONCLUSIVE 4  compose/emulator-side failure (not necessarily the patch's fault)
Without qemu-system-cskyv2 on PATH (or with --skip-dynamic) the manifest and block are still
validated and the dynamic half is reported as skipped - exit 0, verdict null, same convention
as verify_patch.py.

WHAT THIS DOES NOT DO: flash anything. It composes an emulator-only image (the three QEMU-only
boot patches included), boots it, and keeps files under --keep-dir or a temp dir.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import compose_qemu_image  # noqa: E402
import derive_iram  # noqa: E402
import fingerprints  # noqa: E402
import keyseq_lib  # noqa: E402

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
BUILDER = pathlib.Path(__file__).resolve().parent / "build_manifest_patch.py"
QEMU_RUN = pathlib.Path(__file__).resolve().parent / "qemu_run.py"
DEFAULT_BASE = REPO_ROOT / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"

EXIT_CODES = {"PASS": 0, "FAIL": 1, "DIFFERS": 3, "INCONCLUSIVE": 4}


class UsageError(Exception):
    """An invalid verify block or bad argument; the message names the offending field."""


def load_verify_block(manifest_path: pathlib.Path) -> tuple[dict, dict | None]:
    """Return (manifest, verify-block-or-None). UsageError on anything malformed."""
    manifest = json.loads(manifest_path.read_text())
    v = manifest.get("verify")
    if v is None:
        return manifest, None
    if not isinstance(v, dict):
        raise UsageError('"verify" must be an object')
    allowed = {"keyseq", "until_step", "settle_after", "timeout", "expect_frames"}
    unknown = set(v) - allowed
    if unknown:
        raise UsageError(f'"verify": unknown key(s) {sorted(unknown)}; allowed: {sorted(allowed)}')
    if not isinstance(v.get("keyseq"), str):
        raise UsageError('"verify.keyseq" is required and must be a string (scenario name or raw keyseq)')
    # resolve_keyseq raises ValueError for an unknown scenario name; that names the field too.
    try:
        keyseq, scenario = keyseq_lib.resolve_keyseq(v["keyseq"])
    except ValueError as e:
        raise UsageError(f'"verify.keyseq": {e}')
    v["_resolved_keyseq"] = keyseq
    if v.get("until_step") is None:
        if scenario is not None and scenario.get("until_step"):
            v["until_step"] = scenario["until_step"]
        else:
            v["until_step"] = len([s for s in keyseq.split(";") if s.strip()])
    for num_field in ("until_step", "settle_after", "timeout"):
        if num_field in v and not isinstance(v[num_field], (int, float)):
            raise UsageError(f'"verify.{num_field}" must be a number')
    v.setdefault("settle_after", 20)
    v.setdefault("timeout", 600)
    exp = v.get("expect_frames")
    if not isinstance(exp, list) or not exp:
        raise UsageError('"verify.expect_frames" is required and must be a non-empty list')
    known_names = set(fingerprints.load_fingerprints())
    for i, el in enumerate(exp):
        where = f'"verify.expect_frames"[{i}]'
        if isinstance(el, int):
            continue
        if not isinstance(el, dict):
            raise UsageError(f'{where} must be an int, {{"min","max"}} or {{"name"}}')
        keys = set(el)
        if keys == {"name"}:
            if el["name"] not in known_names:
                raise UsageError(f'{where}: unknown fingerprint name {el["name"]!r} '
                                 f"(data/screen_fingerprints.json)")
        elif keys <= {"min", "max"} and keys:
            if not all(isinstance(el[k], int) for k in keys):
                raise UsageError(f'{where}: "min"/"max" must be ints')
            if "min" in el and "max" in el and el["min"] > el["max"]:
                raise UsageError(f'{where}: min > max')
        else:
            raise UsageError(f'{where} must be an int, {{"min","max"}} or {{"name"}}')
    return manifest, v


def element_matches(el, nonblack: int, frame_matches: list[str] | None) -> bool:
    """One expect_frames element against one observed frame (see the module's matching rule)."""
    if isinstance(el, int):
        return nonblack == el
    if "name" in el:
        # An empty/absent "matches" list means "not populated" - fall back to a live lookup.
        names = frame_matches if frame_matches else fingerprints.matches(nonblack)
        return el["name"] in names
    lo = el.get("min")
    hi = el.get("max")
    if lo is not None and nonblack < lo:
        return False
    if hi is not None and nonblack > hi:
        return False
    return True


def match_expect_frames(expect: list, frames: list[dict]) -> tuple[list[dict], list]:
    """Ordered-subsequence match. Returns (per-element results, unmatched elements)."""
    results, unmatched = [], []
    pos = 0
    for el in expect:
        hit = None
        start = pos
        while pos < len(frames):
            fr = frames[pos]
            pos += 1
            if element_matches(el, fr["nonblack"], fr.get("matches")):
                hit = fr
                break
        if hit is None:
            # True subsequence semantics: a failed search must not consume the frames it
            # scanned - later elements can still match them.
            pos = start
        results.append({"expect": el, "matched_frame_idx": hit["idx"] if hit else None,
                        "matched_nonblack": hit["nonblack"] if hit else None})
        if hit is None:
            unmatched.append(el)
    return results, unmatched


def describe_element(el) -> str:
    if isinstance(el, int):
        return f"nonblack={el}"
    if "name" in el:
        return f'fingerprint "{el["name"]}"'
    return f"nonblack in [{el.get('min', '-')}, {el.get('max', '-')}]"


def build_image(manifest_path: pathlib.Path, out_dir: pathlib.Path,
                extra_allocations: list[str]) -> pathlib.Path:
    cmd = [sys.executable, str(BUILDER), str(manifest_path), "--out", str(out_dir)]
    for f in extra_allocations:
        cmd += ["--extra-allocations", f]
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode != 0:
        print(f"FAIL: the build failed (build_manifest_patch.py exit {p.returncode}):\n"
              + "\n".join((p.stdout + p.stderr).splitlines()[-15:]))
        sys.exit(1)
    manifest = json.loads(manifest_path.read_text())
    name = manifest.get("output_image") or f"progmem_{manifest.get('name', 'patch')}_patched.bin"
    image = out_dir / name
    if not image.exists():
        print(f"FAIL: build succeeded but {image.name} is missing under {out_dir}")
        sys.exit(1)
    return image


def run_qemu(image: pathlib.Path, rundir: pathlib.Path, v: dict, qemu: str) -> dict:
    """Drive qemu_run.py --json - and return its JSON summary (the last stdout line)."""
    rundir.mkdir(parents=True, exist_ok=True)
    boot = rundir / "boot.bin"
    iram = rundir / "iram.bin"
    sram = rundir / "sram.bin"
    try:
        composed, summary = compose_qemu_image.compose(DEFAULT_BASE, image, [], qemu_only=True)
    except compose_qemu_image.ComposeError as e:
        print(f"could not compose an emulator-bootable image: {e}")
        return {"verdict": "INCONCLUSIVE"}
    boot.write_bytes(composed)
    iram.write_bytes(derive_iram.derive(composed))
    sram.write_bytes(b"\x00" * 0x8000)
    cmd = [sys.executable, str(QEMU_RUN), "--qemu", qemu,
           "--image", str(boot), "--iram", str(iram), "--sram", str(sram),
           "--rundir", str(rundir), "--tag", "run",
           "--keyseq", v["_resolved_keyseq"],
           "--until-step", str(v["until_step"]),
           "--settle-after", str(v["settle_after"]),
           "--timeout", str(v["timeout"]),
           "--json", "-"]
    p = subprocess.run(cmd, capture_output=True, text=True)
    last = (p.stdout.strip().splitlines() or [""])[-1]
    try:
        result = json.loads(last)
    except json.JSONDecodeError:
        print(f"qemu_run.py did not emit a JSON summary (exit {p.returncode}):\n"
              + "\n".join((p.stdout + p.stderr).splitlines()[-15:]))
        return {"verdict": "INCONCLUSIVE"}
    return result


def main() -> None:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("manifest", type=pathlib.Path, help="the patch's <name>.patch.json")
    ap.add_argument("--image", type=pathlib.Path, default=None,
                    help="a prebuilt patched image (default: build the manifest into a temp dir)")
    ap.add_argument("--extra-allocations", action="append", default=[], metavar="FILE",
                    help="passed through to build_manifest_patch.py when building (repeatable)")
    ap.add_argument("--json", nargs="?", const="-", default=None, metavar="PATH",
                    help="emit one compact JSON object (to PATH, or as the final stdout line)")
    ap.add_argument("--keep-dir", type=pathlib.Path, default=None,
                    help="keep the composed image, iram/sram, qemu.log and gram.raw.NNN frames here")
    ap.add_argument("--timeout", type=float, default=None,
                    help="override the verify block's timeout (seconds)")
    ap.add_argument("--qemu", default="qemu-system-cskyv2", help="qemu binary")
    ap.add_argument("--skip-dynamic", action="store_true",
                    help="validate the manifest and verify block only; never boot QEMU")
    args = ap.parse_args()

    if not args.manifest.exists():
        print(f"ERROR: manifest {args.manifest} not found", file=sys.stderr)
        sys.exit(2)
    try:
        manifest, v = load_verify_block(args.manifest)
    except UsageError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        sys.exit(2)
    if v is None:
        print(f"no 'verify' block in {args.manifest}; nothing to do")
        sys.exit(0)
    if args.timeout is not None:
        v["timeout"] = args.timeout

    out: dict = {"manifest": str(args.manifest), "verdict": None, "exit_code": 0}

    def emit():
        out["exit_code"] = EXIT_CODES.get(out["verdict"], 0)
        if args.json is not None:
            line = json.dumps(out, separators=(",", ":"))
            if args.json == "-":
                print(line)
            else:
                pathlib.Path(args.json).write_text(line + "\n")

    print(f"verify block: keyseq={args.manifest.name}:{v['keyseq']!r} "
          f"until_step={v['until_step']} expect_frames={len(v['expect_frames'])} element(s)")

    if args.skip_dynamic or shutil.which(args.qemu) is None:
        reason = "--skip-dynamic" if args.skip_dynamic else \
            f"{args.qemu} is not on PATH (it is inside this repo's Docker image)"
        print(f"  dynamic verification skipped: {reason}. The manifest and verify block are valid.")
        emit()
        sys.exit(0)

    work = args.keep_dir or pathlib.Path(tempfile.mkdtemp(prefix="verify_manifest_"))
    work.mkdir(parents=True, exist_ok=True)
    image = args.image or build_image(args.manifest, work / "build", args.extra_allocations)
    out["image"] = str(image)
    out["keyseq_resolved"] = v["_resolved_keyseq"]
    out["until_step"] = v["until_step"]

    print(f"  image: {image}")
    print(f"  booting under QEMU (rundir {work})...")
    result = run_qemu(image, work / "run", v, args.qemu)
    if result.get("verdict") == "INCONCLUSIVE":
        out["verdict"] = "INCONCLUSIVE"
        emit()
        sys.exit(4)

    frames = result.get("frames", [])
    crashes = result.get("crashes", 0)
    out["frames"] = frames
    out["crashes"] = crashes
    out["token_line"] = result.get("token_line", "")

    if crashes or not frames:
        out["verdict"] = "FAIL"
        print(f"  FAIL: the run {'crashed' if crashes else 'captured no frames'} "
              f"(crashes={crashes}, frames={len(frames)}) - the patch broke boot or stalled early")
    else:
        results, unmatched = match_expect_frames(v["expect_frames"], frames)
        out["expect"] = results
        matched_idxs = {r["matched_frame_idx"] for r in results if r["matched_frame_idx"] is not None}
        out["unmatched_observed"] = [f["idx"] for f in frames if f["idx"] not in matched_idxs]
        for r in results:
            if r["matched_frame_idx"] is not None:
                print(f"  EXPECT {describe_element(r['expect'])} -> matched frame "
                      f"F{r['matched_frame_idx']} (nonblack {r['matched_nonblack']})")
            else:
                print(f"  EXPECT {describe_element(r['expect'])} -> UNMATCHED")
        if unmatched:
            out["verdict"] = "DIFFERS"
            print(f"  {len(unmatched)} expected element(s) matched nothing "
                  f"(review the kept frames; expected for a patch that changes its screens)")
        else:
            out["verdict"] = "PASS"
        if out["unmatched_observed"]:
            print(f"  info: {len(out['unmatched_observed'])} observed frame(s) matched no "
                  f"expectation (allowed: boot-timing stragglers)")

    print(f"\n== VERDICT: {out['verdict']} ==  (frames kept in {work})")
    print("  Scope: one emulated boot driven by the declared key script on the -M dm32 model "
          "(no RF/DMR; QEMU-only patches applied). Code the script never reaches is not exercised.")
    emit()
    sys.exit(EXIT_CODES.get(out["verdict"], 1))


if __name__ == "__main__":
    main()
