"""Image test (test 7): verify_patch.py's QEMU boot comparison gives PASS for a no-op patch
(the stock sector written back unchanged), i.e. two boots of the same image compare equal."""
from __future__ import annotations

import sys
import unittest

from _support import (SECTOR_SIZE, STOCK_FULL, TempDirTestCase, describe, requires_image, run,
                      tool)

OFFSET = 0xE1000   # erased flash the Snake/overlay examples also use; any sector would do


@requires_image
class VerifyPatchStockVsStock(TempDirTestCase):

    def test_stock_vs_stock_is_pass(self):
        sector = self.tmp / "stock_sector.bin"
        sector.write_bytes(STOCK_FULL.read_bytes()[OFFSET:OFFSET + SECTOR_SIZE])
        p = run([sys.executable, tool("verify_patch"), "--sector", sector,
                 "--offset", hex(OFFSET)], timeout=900)
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("== VERDICT: PASS", p.stdout, describe(p))
        self.assertNotIn("skipped: qemu-system-cskyv2", p.stdout, "dynamic step did not run")


if __name__ == "__main__":
    unittest.main()
