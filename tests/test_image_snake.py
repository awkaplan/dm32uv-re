"""Image tests (need the docker image's toolchain + QEMU): the Snake example rebuilds
byte-for-byte, and the committed Snake image still produces its measured screen sequence."""
from __future__ import annotations

import shutil
import sys
import unittest

from _support import (REPO, SNAKE_DIR, SNAKE_IMAGE, STOCK_FULL, TempDirTestCase, describe,
                      import_tool, requires_image, run, tool)

# Sources build_snake_patch.py consumes (everything else in tools/examples/snake is its output).
SNAKE_SOURCES = ["build_snake_patch.py", "snake_game.c", "snake_game.ld", "snake_category_entry.c",
                 "snake_tail_stub.S", "snake_ok_stub.S", "snake_menu_append_trampoline.S"]

# Codeplug-less key script from docs/img/README.md: MENU, Up (wrap to SNAKE), OK, OK, then
# four direction keys and two Backs.
SNAKE_KEYSEQ = ("-1:0:1:31:0:20;-1:0:1:17:20:120;2:11:1:17:60:400;2:7:1:17:60:400;"
                "2:7:1:17:60:600;2:11:1:18:150:500;2:8:1:20:150:500;2:11:1:17:150:500;"
                "2:8:1:18:150:500;2:10:1:17:150:900;2:10:1:17:150:900")

# Non-black pixel counts of successive distinct frames, measured 2026-10-10 with the committed
# progmem_SNAKE_patched.bin: boot, standby, menu, SNAKE row, sub-list, game frames (1175 between
# each direction change), then the stock UI after Back.
EXPECTED_SCREENS = ['0', '580', '13618', '13309', '9472', '1175', '1166', '1175', '1138', '1175',
                    '1164', '1175', '1142', '1175', '2993', '2997']
# 2993 and 2997 are the same post-Back screen 4 pixels apart (a blinking element); whether a
# 2993 frame gets dumped before the 2997 one is timing-dependent (missed in 1 of 3 runs on
# 2026-10-10 under host load). Only that frame may be absent; everything else is exact.
OPTIONAL_SCREENS = {14}   # indices into EXPECTED_SCREENS


def collapse(values):
    """Drop consecutive duplicates: one entry per screen change."""
    out = []
    for v in values:
        if not out or out[-1] != v:
            out.append(v)
    return out


@requires_image
class SnakeGoldenRebuild(TempDirTestCase):
    """Test 2: rebuilding Snake from source reproduces the committed image and sector files."""

    def setUp(self):
        super().setUp()
        # build_snake_patch.py writes every output next to itself, so build a copy of the
        # source tree; ../../include is the API header its .c files include.
        work = self.tmp / "tools" / "examples" / "snake"
        work.mkdir(parents=True)
        for name in SNAKE_SOURCES:
            shutil.copy2(SNAKE_DIR / name, work / name)
        shutil.copytree(REPO / "tools" / "include", self.tmp / "tools" / "include")
        p = run([sys.executable, work / "build_snake_patch.py"], cwd=work, timeout=600, env={
            "CSKYBUILD": str(REPO / "docker" / "cskybuild.sh"),
            "DM32_STOCK_IMAGE": str(STOCK_FULL),
        })
        self.assertEqual(p.returncode, 0, describe(p))
        self.work = work

    def test_full_image_matches_committed(self):
        built = (self.work / SNAKE_IMAGE.name).read_bytes()
        committed = SNAKE_IMAGE.read_bytes()
        self.assertEqual(len(built), len(committed))
        if built != committed:
            diffs = [i for i, (a, b) in enumerate(zip(built, committed)) if a != b]
            self.fail(f"rebuilt {SNAKE_IMAGE.name} differs from committed in {len(diffs)} bytes, "
                      f"first at flash {0x03000000 + diffs[0]:#010x}")

        # The sector files are outputs of the same run; the committed ones must not be stale.
        built_sectors = sorted(p.name for p in self.work.glob("sector_*_*.bin"))
        self.assertTrue(built_sectors)
        for name in built_sectors:
            with self.subTest(sector_file=name):
                self.assertEqual((self.work / name).read_bytes(), (SNAKE_DIR / name).read_bytes(),
                                 f"committed tools/examples/snake/{name} is stale")


@requires_image
class SnakeManifestGolden(TempDirTestCase):
    """Test 2b: the declarative manifest (snake.patch.json via build_manifest_patch.py) also
    reproduces the committed image byte-for-byte. Outputs go to a temp --out."""

    def test_manifest_build_matches_committed(self):
        p = run([sys.executable, tool("build_manifest_patch"), SNAKE_DIR / "snake.patch.json",
                 "--out", self.tmp / "snake", "--compare", SNAKE_IMAGE], timeout=600,
                env={"CSKYBUILD": str(REPO / "docker" / "cskybuild.sh")})
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("COMPARE: byte-identical", p.stdout, describe(p))


@requires_image
class SnakeQemuFingerprint(TempDirTestCase):
    """Test 3: the committed Snake image, booted codeplug-less under -M dm32 with the
    docs/img/README.md key script, walks through the measured screen sequence."""

    def test_screen_sequence(self):
        img = self.tmp / "snake_qemu.bin"
        p = run([sys.executable, tool("compose_qemu_image"), "--patched", SNAKE_IMAGE,
                 "--out", img, "--iram-out"])
        self.assertEqual(p.returncode, 0, describe(p))
        rundir = self.tmp / "run"
        p = run([sys.executable, tool("qemu_run"), "--image", img, "--iram", self.tmp / "iram.bin",
                 "--sram", self.tmp / "sram.bin", "--rundir", rundir, "--until-step", "11",
                 "--settle-after", "25", "--timeout", "500", f"--keyseq={SNAKE_KEYSEQ}"],
                timeout=600)
        self.assertEqual(p.returncode, 0, describe(p))
        qemu_run = import_tool("qemu_run")
        crashes, _, last_step, tokens = qemu_run.summarize_log(rundir / "qemu.log")
        self.assertEqual(crashes, 0, f"QEMU log reports {crashes} crash(es)" + describe(p))
        self.assertGreaterEqual(last_step, 11, "key script did not complete" + describe(p))
        screens = collapse(t.split(":", 1)[1] for t in tokens.split() if t.startswith("F"))
        without_optional = [v for i, v in enumerate(EXPECTED_SCREENS) if i not in OPTIONAL_SCREENS]
        if screens != EXPECTED_SCREENS and screens != without_optional:
            self.assertEqual(screens, EXPECTED_SCREENS, f"token line: {tokens}")


if __name__ == "__main__":
    unittest.main()
