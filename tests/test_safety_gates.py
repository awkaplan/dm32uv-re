"""Host tests: the tooling refuses to stage or build anything for the emulator-only and per-unit
sectors. These gates are the repo's main protection against an emulator image (or a write over
the per-radio binding record) reaching real hardware, so each is exercised directly."""
from __future__ import annotations

import sys
import unittest

from _support import (FLASH_BASE, SECTOR_SIZE, SNAKE_IMAGE, STOCK_FULL, TempDirTestCase,
                      describe, import_tool, run, tool)

# compose_qemu_image.py's three QEMU-only patches, as (file offset, label). 0xb000 is also the
# per-unit parameter sector (scrub_unit_sector.py).
QEMU_ONLY = [(0xC6000, "ALPU bypass"), (0x1B000, "auto-power-off NOP"),
             (0xB000, "hardware-binding bypass")]
PER_UNIT_OFFSET = 0xB000


class StageSectorsRefuses(TempDirTestCase):
    """Test 4: stage_sectors.py refuses each emulator-only sector and the per-unit sector."""

    def setUp(self):
        super().setUp()
        self.stock = STOCK_FULL.read_bytes()
        composed = self.tmp / "composed_qemu.bin"
        p = run([sys.executable, tool("compose_qemu_image"), "--out", composed])
        self.assertEqual(p.returncode, 0, describe(p))
        self.composed = composed.read_bytes()

    def stage(self, image: bytes, tag: str):
        patched = self.tmp / f"{tag}.bin"
        patched.write_bytes(image)
        out = self.tmp / f"staged_{tag}"
        p = run([sys.executable, tool("stage_sectors"), "--patched", patched,
                 "--stock", STOCK_FULL, "--out", out])
        staged = sorted(out.glob("*.bin")) if out.exists() else []
        return p, staged

    def assert_refused(self, p, staged, off):
        self.assertEqual(p.returncode, 2, describe(p))
        # argparse errors also exit 2; require the tool's own refusal message.
        self.assertIn("FAIL:", p.stderr, describe(p))
        self.assertIn(f"{FLASH_BASE + off:#010x}", p.stderr, describe(p))
        self.assertEqual(staged, [], f"refused run still wrote sector files: {staged}")

    def test_composed_image_changes_exactly_the_three_qemu_only_sectors(self):
        changed = [o for o in range(0, len(self.stock), SECTOR_SIZE)
                   if self.stock[o:o + SECTOR_SIZE] != self.composed[o:o + SECTOR_SIZE]]
        self.assertEqual(sorted(changed), sorted(o for o, _ in QEMU_ONLY))

    def test_refuses_whole_composed_image(self):
        p, staged = self.stage(self.composed, "composed")
        self.assertEqual(p.returncode, 2, describe(p))
        self.assertEqual(staged, [])

    def test_refuses_each_qemu_only_sector(self):
        for off, label in QEMU_ONLY:
            with self.subTest(sector=f"{FLASH_BASE + off:#010x}", patch=label):
                img = bytearray(self.stock)
                img[off:off + SECTOR_SIZE] = self.composed[off:off + SECTOR_SIZE]
                p, staged = self.stage(bytes(img), f"qemu_only_{off:x}")
                self.assert_refused(p, staged, off)

    def test_refuses_any_write_to_per_unit_sector(self):
        # Not the hardware-binding patch bytes: an arbitrary change elsewhere in the sector.
        img = bytearray(self.stock)
        img[PER_UNIT_OFFSET + 0x200] ^= 0xFF
        p, staged = self.stage(bytes(img), "per_unit")
        self.assert_refused(p, staged, PER_UNIT_OFFSET)

    def test_refuses_per_unit_sector_even_with_allow_qemu_only(self):
        # --allow-qemu-only exists for deliberately staging an emulator image; it must not also
        # open the per-unit sector (never writable from another unit's image, and listed in
        # data/firmware/patching/occupied_regions.json for exactly that reason).
        img = bytearray(self.stock)
        img[PER_UNIT_OFFSET + 0x200] ^= 0xFF
        patched = self.tmp / "per_unit_allow.bin"
        patched.write_bytes(bytes(img))
        out = self.tmp / "staged_per_unit_allow"
        p = run([sys.executable, tool("stage_sectors"), "--patched", patched,
                 "--stock", STOCK_FULL, "--out", out, "--allow-qemu-only"])
        staged = sorted(out.glob("*.bin")) if out.exists() else []
        self.assert_refused(p, staged, PER_UNIT_OFFSET)

    def test_control_ordinary_patch_is_staged(self):
        # Positive control: the gates are specific, not "refuse everything".
        p, staged = self.stage(SNAKE_IMAGE.read_bytes(), "snake")
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertEqual(len(staged), 6, f"expected Snake's six sectors, got {staged}")
        self.assertTrue((staged[0].parent / "MANIFEST.sha256").exists())


class BuildPatchRefusesPerUnitSector(TempDirTestCase):
    """Test 5: build_patch.build_patch() refuses sector_base 0x0300b000 before doing anything."""

    def test_refuses_per_unit_sector(self):
        build_patch = import_tool("build_patch")
        # The handler path does not exist: the refusal must come before any assembly is attempted.
        with self.assertRaisesRegex(build_patch.BuildError, "per-unit"):
            build_patch.build_patch(
                stock_sector=b"\xff" * SECTOR_SIZE,
                handler_src=self.tmp / "never_assembled.S",
                sector_base=0x0300B000, hook_addr=0x0300B010,
                expected_hook_bytes=b"\xff" * 4, hook_kind="br")

    def test_control_other_sector_gets_past_the_gate(self):
        build_patch = import_tool("build_patch")
        with self.assertRaises(build_patch.BuildError) as cm:
            build_patch.build_patch(
                stock_sector=b"\xff" * SECTOR_SIZE,
                handler_src=self.tmp / "never_assembled.S",
                sector_base=0x030E1000, hook_addr=0x030E1010,
                expected_hook_bytes=b"\x00" * 4, hook_kind="br")
        self.assertNotIn("per-unit", str(cm.exception))


if __name__ == "__main__":
    unittest.main()
