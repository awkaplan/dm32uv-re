"""Host tests: build_manifest_patch.py --extra-allocations (claim files from outside this repo).

Exercises load_allocations() directly: an extra file's claims resolve, a duplicate name or an
overlap with a data/allocations.json claim is a hard error, and a claim outside the windows or
inside a forbidden range is refused. Plain python3, no toolchain.
"""
from __future__ import annotations

import json
import unittest

from _support import TempDirTestCase, import_tool


class ExtraAllocations(TempDirTestCase):
    def setUp(self):
        super().setUp()
        self.bmp = import_tool("build_manifest_patch")

    def write(self, claims, name="extra.json", **extra):
        p = self.tmp / name
        p.write_text(json.dumps({"allocations": claims, **extra}))
        return p

    @staticmethod
    def flash(name, lo, hi):
        return {"name": name, "space": "flash", "start": lo, "end_exclusive": hi, "owner": "t"}

    @staticmethod
    def sram(name, lo, hi):
        return {"name": name, "space": "sram", "start": lo, "end_exclusive": hi, "owner": "t"}

    def test_resolves(self):
        p = self.write([self.flash("x_code", "0x030e2000", "0x030e3000"),
                        self.sram("x_state", "0x18007400", "0x18007500")])
        a = self.bmp.load_allocations([p])
        names = {c["name"]: c for c in a["claims"]}
        self.assertIn("snake_code", names)            # repo claims still present
        self.assertEqual(names["x_code"]["lo"], 0x030E2000)
        self.assertEqual(names["x_state"]["space"], "sram")
        self.assertEqual(names["x_state"]["file"], str(p))

    def test_no_extra_equals_base(self):
        a = self.bmp.load_allocations([])
        self.assertTrue(any(c["name"] == "snake_code" for c in a["claims"]))

    def test_duplicate_name(self):
        p = self.write([self.flash("snake_code", "0x030e2000", "0x030e3000")])
        with self.assertRaisesRegex(self.bmp.BuildError, "duplicate allocation name"):
            self.bmp.load_allocations([p])

    def test_duplicate_across_extra_files(self):
        p1 = self.write([self.flash("dup", "0x030e2000", "0x030e3000")], "a.json")
        p2 = self.write([self.flash("dup", "0x030e3000", "0x030e4000")], "b.json")
        with self.assertRaisesRegex(self.bmp.BuildError, "duplicate"):
            self.bmp.load_allocations([p1, p2])

    def test_overlap_with_repo_claim(self):
        p = self.write([self.sram("clash", "0x18007100", "0x18007200")])   # inside snake_state
        with self.assertRaisesRegex(self.bmp.BuildError, "overlap"):
            self.bmp.load_allocations([p])

    def test_overlap_between_extra_files(self):
        p1 = self.write([self.flash("a", "0x030e2000", "0x030e3000")], "a.json")
        p2 = self.write([self.flash("b", "0x030e2000", "0x030e3000")], "b.json")
        with self.assertRaisesRegex(self.bmp.BuildError, "overlap"):
            self.bmp.load_allocations([p1, p2])

    def test_outside_window_and_unaligned(self):
        p = self.write([self.flash("low", "0x030d0000", "0x030d1000")])
        with self.assertRaisesRegex(self.bmp.BuildError, "outside"):
            self.bmp.load_allocations([p])
        p = self.write([self.flash("odd", "0x030e2000", "0x030e2800")], "c.json")
        with self.assertRaisesRegex(self.bmp.BuildError, "sectors"):
            self.bmp.load_allocations([p])

    def test_not_an_allocations_file(self):
        p = self.tmp / "bad.json"
        p.write_text("{}")
        with self.assertRaisesRegex(self.bmp.BuildError, "allocations"):
            self.bmp.load_allocations([p])


if __name__ == "__main__":
    unittest.main()
