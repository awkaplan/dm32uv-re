"""Shared helpers for the dm32uv-re test suite (stdlib only, no pytest).

Two kinds of test module live in tests/:

  test_*.py        HOST tests - plain python3, no toolchain, no QEMU. Run anywhere the repo is
                   cloned (including CI): `make -C tools test` or `python3 tests/run_tests.py`.
  test_image_*.py  IMAGE tests - need the csky-abiv2-elf-* toolchain and qemu-system-cskyv2,
                   i.e. this repo's Docker image (built from docker/). They skip, never fail,
                   when those tools are not on PATH. `make -C tools test-all` runs them in the
                   image via `docker run`.

No test writes into the repo tree: every artefact goes to a per-test temporary directory.
"""
from __future__ import annotations

import importlib
import os
import pathlib
import shutil
import subprocess
import sys
import tempfile
import unittest

REPO = pathlib.Path(__file__).resolve().parent.parent
TOOLS_SRC = REPO / "tools" / "src" / "dm32_patch_tools"
SNAKE_DIR = REPO / "tools" / "examples" / "snake"
STOCK_FULL = REPO / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"
IRAM_IMAGE = REPO / "data" / "firmware" / "IRAM_dm32.00.01.048.bin"
SNAKE_IMAGE = SNAKE_DIR / "progmem_SNAKE_patched.bin"

FLASH_BASE = 0x03000000
SECTOR_SIZE = 0x1000

QEMU = "qemu-system-cskyv2"
CSKY_GCC = "csky-abiv2-elf-gcc"


def in_image() -> bool:
    """True when the toolchain and the dm32 QEMU are on PATH (i.e. inside the Docker image)."""
    return shutil.which(QEMU) is not None and shutil.which(CSKY_GCC) is not None


requires_image = unittest.skipUnless(
    in_image(), f"needs {CSKY_GCC} and {QEMU} on PATH (run inside the docker image: "
                f"`make -C tools test-all`)")


def import_tool(name: str):
    """Import a module from tools/src/dm32_patch_tools (they import each other by bare name)."""
    if str(TOOLS_SRC) not in sys.path:
        sys.path.insert(0, str(TOOLS_SRC))
    return importlib.import_module(name)


def run(cmd, *, cwd=None, env=None, timeout=600) -> subprocess.CompletedProcess:
    """Run a command, capture text output, enforce a wall-clock cap (macOS has no `timeout`)."""
    full_env = dict(os.environ)
    full_env["PYTHONDONTWRITEBYTECODE"] = "1"   # keep __pycache__ out of the tree
    if env:
        full_env.update(env)
    return subprocess.run([str(c) for c in cmd], cwd=str(cwd) if cwd else None, env=full_env,
                          capture_output=True, text=True, timeout=timeout)


def tool(name: str) -> pathlib.Path:
    return TOOLS_SRC / f"{name}.py"


def describe(proc: subprocess.CompletedProcess, tail: int = 40) -> str:
    """Compact failure context for assertion messages."""
    out = "\n".join(proc.stdout.splitlines()[-tail:])
    err = "\n".join(proc.stderr.splitlines()[-tail:])
    return f"\n$ {' '.join(proc.args)}\nrc={proc.returncode}\n--- stdout (tail) ---\n{out}\n--- stderr (tail) ---\n{err}"


class TempDirTestCase(unittest.TestCase):
    """Gives each test a fresh self.tmp directory, removed afterwards unless DM32_TEST_KEEP=1."""

    def setUp(self):
        self.tmp = pathlib.Path(tempfile.mkdtemp(prefix=f"dm32test-{self._testMethodName}-"))

    def tearDown(self):
        if os.environ.get("DM32_TEST_KEEP"):
            print(f"\n  (kept {self.tmp})", file=sys.stderr)
        else:
            shutil.rmtree(self.tmp, ignore_errors=True)
