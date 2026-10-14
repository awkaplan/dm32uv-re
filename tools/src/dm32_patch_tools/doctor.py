#!/usr/bin/env python3
"""doctor.py - check the dm32uv-re patch-development environment.

Prints one line per check:

    OK|WARN|FAIL  <check>  <detail>

followed by a `remedy:` line for every non-OK check, and a summary line
`summary: N ok, N warn, N fail`. Exits 0 when there is no FAIL, 1 otherwise.

Severity semantics (see the exit-code note below): missing qemu / toolchain / docker / Pillow are
WARN - static host work (lookup, placement scan, staging, the corpus pre-flight, docs checks)
is still possible without them. Repo-layout and stock-image problems are FAIL: a broken checkout
or a mismatched stock image poisons every patch build regardless of the toolchain.

    python3 tools/src/dm32_patch_tools/doctor.py
    python3 tools/src/dm32_patch_tools/doctor.py --json            # JSON as the final stdout line
    python3 tools/src/dm32_patch_tools/doctor.py --json out.json   # JSON written to out.json

--json [PATH] emits {"checks": [{"name", "status", "detail", "remedy"}], "summary":
{"ok", "warn", "fail", "total"}, "exit_code": N} to PATH - or, when PATH is omitted or "-", as the
final stdout line. "exit_code" is 0 when every check is OK/WARN, 1 if any check FAILs.

CHECK LIST (name -> what it verifies -> severity when it fails):
    python-version  running interpreter >= 3.10                      WARN if older (static work
                                                                     still runs; see note below)
    repo-layout     meta/functions.json, data/allocations.json and
                    tools/include/dm32_patch_api.h exist              FAIL
    stock-image     the full 1 MB stock image exists AND matches its
                    .sha256 sidecar (digest + two spaces + filename)  FAIL
    iram-image      data/firmware/IRAM_dm32.00.01.048.bin exists      WARN (derive_iram.py)
    git-submodules  vendor/{ghidra_csky,csky-qemu,dm32uv-qemu,
                    csky-toolchain-build} initialised                 WARN
    qemu            qemu-system-cskyv2 on PATH                        WARN
    toolchain       csky-abiv2-elf-gcc on PATH                        WARN
    docker          docker on PATH (substitutes for both above)       WARN
    docker-image    dm32uv-re-pipeline:latest built (or $DM32_IMAGE)  WARN
    capstone        DM32_CAPSTONE_LIB/DM32_CAPSTONE_HDR set, else
                    cs_disasm.py falls back to objdump                WARN
    pillow          Pillow importable for render_frames.py            WARN

NOTE ON python-version: the repo declares 3.10+ (tools/.python-version is 3.12), but every static
tool here also runs on 3.9 - that is the same "static host work is still possible" threshold the
other WARNs use - so an older interpreter is reported as WARN, not FAIL. A FAIL here is reserved
for a checkout or an image that cannot be trusted at all.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
import shutil
import subprocess
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]

STOCK_IMAGE = REPO_ROOT / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"
IRAM_IMAGE = REPO_ROOT / "data" / "firmware" / "IRAM_dm32.00.01.048.bin"
DEFAULT_IMAGE = "dm32uv-re-pipeline:latest"

LAYOUT_FILES = [
    REPO_ROOT / "meta" / "functions.json",
    REPO_ROOT / "data" / "allocations.json",
    REPO_ROOT / "tools" / "include" / "dm32_patch_api.h",
]

# Each submodule is "initialised" when at least one of these sentinels exists inside it.
SUBMODULES = [
    ("ghidra_csky", ["README.md"]),
    ("csky-qemu", ["hw"]),
    ("dm32uv-qemu", ["hw"]),
    ("csky-toolchain-build", ["README.md"]),
]

QEMU = "qemu-system-cskyv2"
CSKY_GCC = "csky-abiv2-elf-gcc"


# ----------------------------------------------------------------------------------------------
# individual checks - each returns (status, detail, remedy); remedy is '' for OK
# ----------------------------------------------------------------------------------------------

def check_python() -> tuple[str, str, str]:
    v = sys.version_info
    detail = f"{v.major}.{v.minor}.{v.micro}"
    if v >= (3, 10):
        return "OK", f"{detail} (>= 3.10)", ""
    return ("WARN",
            f"{detail} (< 3.10; the repo targets 3.10+, tools/.python-version is 3.12)",
            "run the tools with a Python 3.10+ interpreter (python3.11 / python3.12 / "
            "tools/.venv/bin/python3); every static tool also works on 3.9")


def check_repo_layout() -> tuple[str, str, str]:
    missing = [str(f.relative_to(REPO_ROOT)) for f in LAYOUT_FILES if not f.exists()]
    if missing:
        return ("FAIL",
                "missing " + ", ".join(missing),
                "restore a full checkout - these are committed inputs every patch tool reads")
    return ("OK",
            "meta/functions.json, data/allocations.json, tools/include/dm32_patch_api.h present",
            "")


def check_stock_image() -> tuple[str, str, str]:
    if not STOCK_IMAGE.exists():
        return ("FAIL",
                f"stock image missing: data/firmware/patching/{STOCK_IMAGE.name}",
                "restore the stock image (the .bin plus its .sha256 sidecar)")
    side = STOCK_IMAGE.with_name(STOCK_IMAGE.name + ".sha256")
    if not side.exists():
        return ("FAIL",
                "stock image present but its .sha256 sidecar is missing",
                f"restore {STOCK_IMAGE.name}.sha256 (one '<sha256hex>  <filename>' line per file)")
    digest = hashlib.sha256(STOCK_IMAGE.read_bytes()).hexdigest()
    for line in side.read_text().splitlines():
        parts = line.split()
        if parts and parts[0].lower() == digest:
            return ("OK", f"sha256 {digest[:16]}... matches sidecar", "")
    return ("FAIL",
            f"stock image sha256 ({digest[:16]}...) does not match its sidecar {side.name}",
            "the image was damaged or swapped - re-fetch progmem_stock_DP570UV_20260926_FULL.bin")


def check_iram_image() -> tuple[str, str, str]:
    if IRAM_IMAGE.exists():
        return "OK", f"{IRAM_IMAGE.name} present", ""
    return ("WARN",
            "IRAM image missing (needed by qemu_run/compose and some static lookups)",
            "python3 tools/src/dm32_patch_tools/derive_iram.py   # rebuilds it from the full "
            "flash image")


def check_submodules() -> tuple[str, str, str]:
    missing = [name for name, sentinels in SUBMODULES
               if not any((REPO_ROOT / "vendor" / name / s).exists() for s in sentinels)]
    if missing:
        return ("WARN",
                "vendor submodules not initialised: " + ", ".join(missing),
                "git submodule update --init --recursive")
    return ("OK",
            "vendor/ghidra_csky, vendor/csky-qemu, vendor/dm32uv-qemu, "
            "vendor/csky-toolchain-build initialised",
            "")


def check_qemu() -> tuple[str, str, str]:
    if shutil.which(QEMU):
        return "OK", f"{QEMU} on PATH", ""
    return ("WARN",
            f"{QEMU} not on PATH",
            "build the docker image (cd docker && docker compose build) - needed for QEMU "
            "verification, not for static work")


def check_toolchain() -> tuple[str, str, str]:
    if shutil.which(CSKY_GCC):
        return "OK", f"{CSKY_GCC} on PATH", ""
    return ("WARN",
            f"{CSKY_GCC} not on PATH",
            "build the docker image (cd docker && docker compose build) - needed to compile "
            "patches")


def check_docker() -> tuple[str, str, str]:
    if shutil.which("docker"):
        return "OK", "docker on PATH", ""
    return ("WARN",
            "docker not on PATH",
            "install docker - the dm32uv-re-pipeline image substitutes for both the toolchain "
            "and qemu")


def check_docker_image() -> tuple[str, str, str]:
    image = os.environ.get("DM32_IMAGE") or DEFAULT_IMAGE
    if not shutil.which("docker"):
        return ("WARN",
                f"cannot check docker image {image} (docker not on PATH)",
                "install docker, then build the image")
    try:
        r = subprocess.run(["docker", "images", "-q", image], capture_output=True, text=True)
    except OSError as e:  # pragma: no cover - docker vanished between which() and run()
        return ("WARN", f"cannot check docker image {image} ({e})", "install docker, then build the image")
    if r.returncode == 0 and r.stdout.strip():
        return "OK", f"docker image {image} present", ""
    return ("WARN",
            f"docker image {image} not built",
            "cd docker && docker compose build   (produces dm32uv-re-pipeline:latest; "
            "$DM32_IMAGE overrides the name)")


def check_capstone() -> tuple[str, str, str]:
    lib = os.environ.get("DM32_CAPSTONE_LIB")
    hdr = os.environ.get("DM32_CAPSTONE_HDR")
    if lib and hdr:
        if os.path.exists(lib) and os.path.exists(hdr):
            return "OK", "DM32_CAPSTONE_LIB/DM32_CAPSTONE_HDR set and present", ""
        return ("WARN",
                "DM32_CAPSTONE_LIB/DM32_CAPSTONE_HDR set but the file(s) do not exist",
                "point both at your capstone-csky build (see cs_disasm.py's docstring)")
    if lib or hdr:
        return ("WARN",
                "only one of DM32_CAPSTONE_LIB / DM32_CAPSTONE_HDR is set (need both)",
                "set both env vars to your capstone-csky build, or use the docker image")
    return ("WARN",
            "DM32_CAPSTONE_LIB/DM32_CAPSTONE_HDR not set",
            "cs_disasm.py falls back to csky-abiv2-elf-objdump, which needs the toolchain "
            "image; build capstone-csky (see cs_disasm.py) and set DM32_CAPSTONE_LIB/"
            "DM32_CAPSTONE_HDR")


def check_pillow() -> tuple[str, str, str]:
    try:
        import PIL  # noqa: F401
        return "OK", "Pillow importable (render_frames.py)", ""
    except ImportError:
        return ("WARN",
                "Pillow not installed (render_frames.py has a stdlib PNG fallback, but no labels)",
                "pip install pillow")


CHECKS = [
    ("python-version", check_python),
    ("repo-layout", check_repo_layout),
    ("stock-image", check_stock_image),
    ("iram-image", check_iram_image),
    ("git-submodules", check_submodules),
    ("qemu", check_qemu),
    ("toolchain", check_toolchain),
    ("docker", check_docker),
    ("docker-image", check_docker_image),
    ("capstone", check_capstone),
    ("pillow", check_pillow),
]


def run_checks() -> list[dict]:
    return [{"name": name, "status": st, "detail": det, "remedy": rem}
            for name, fn in CHECKS
            for st, det, rem in [fn()]]


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", nargs="?", const="-", default=None, metavar="PATH",
                    help="emit JSON to PATH, or to the final stdout line when PATH is omitted "
                         "or '-'")
    args = ap.parse_args(argv)

    checks = run_checks()
    n_ok = sum(1 for c in checks if c["status"] == "OK")
    n_warn = sum(1 for c in checks if c["status"] == "WARN")
    n_fail = sum(1 for c in checks if c["status"] == "FAIL")
    exit_code = 1 if n_fail else 0

    for c in checks:
        print(f"{c['status']:<4} {c['name']:<14} {c['detail']}")
        if c["status"] != "OK" and c["remedy"]:
            print(f"      remedy: {c['remedy']}")
    print(f"summary: {n_ok} ok, {n_warn} warn, {n_fail} fail")

    if args.json is not None:
        payload = {
            "checks": checks,
            "summary": {"ok": n_ok, "warn": n_warn, "fail": n_fail, "total": len(checks)},
            "exit_code": exit_code,
        }
        if args.json == "-":
            print(json.dumps(payload))  # the final stdout line
        else:
            pathlib.Path(args.json).write_text(json.dumps(payload) + "\n")
    return exit_code


if __name__ == "__main__":
    sys.exit(main())
