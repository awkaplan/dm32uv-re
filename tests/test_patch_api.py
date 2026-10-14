"""Host tests: meta/patch_api.json and its generator (tools/src/dm32_patch_tools/gen_patch_api.py).

meta/patch_api.json is the machine-queryable view of tools/include/dm32_patch_api.h (regenerated,
never hand-edited). These tests pin the file's shape, that its per-kind "counts" match the actual
tallies, that function addresses live in flash/IRAM, the documented entries, the header-coverage
contract (every #define in the header is present in the JSON), and that the generator is
deterministic and the committed file is current (--check). No test writes into the repo tree.
"""
from __future__ import annotations

import json
import re
import sys
import unittest

from _support import REPO, TempDirTestCase, describe, run, tool

META = REPO / "meta" / "patch_api.json"
HEADER = REPO / "tools" / "include" / "dm32_patch_api.h"

# Half-open address windows for function entries (see the task spec / rtos-and-memory.md).
FLASH_LO, FLASH_HI = 0x03000000, 0x03100000      # 0x03000000..0x030FFFFF
IRAM_LO, IRAM_HI = 0x00000000, 0x00050000        # 0x00000000..0x0004FFFF

# The header's include guard is not an API entry; every other #define must be one.
INCLUDE_GUARD = "DM32_PATCH_API_H"


def load_api():
    doc = json.loads(META.read_text())
    return doc, {e["name"]: e for e in doc["api"]}


class PatchApiCounts(unittest.TestCase):
    """Test 1: the committed "counts" map matches the actual per-kind tallies in "api"."""

    def test_counts_match_actual_tallies(self):
        doc = json.loads(META.read_text())
        tallies = {}
        for e in doc["api"]:
            tallies[e["kind"]] = tallies.get(e["kind"], 0) + 1
        self.assertEqual(doc["counts"], tallies,
                         "meta/patch_api.json counts do not match the api entries")


class PatchApiAddresses(unittest.TestCase):
    """Test 2: function addresses are in flash or IRAM; entry names are unique."""

    def test_function_addresses_in_flash_or_iram(self):
        doc, _ = load_api()
        for e in doc["api"]:
            if e["kind"] != "function":
                continue
            addr = int(e["address"], 16)
            in_flash = FLASH_LO <= addr < FLASH_HI
            in_iram = IRAM_LO <= addr < IRAM_HI
            self.assertTrue(
                in_flash or in_iram,
                f"{e['name']}: address {e['address']} outside flash "
                f"({FLASH_LO:#x}..{FLASH_HI - 1:#x}) and IRAM ({IRAM_LO:#x}..{IRAM_HI - 1:#x})")

    def test_entry_names_unique(self):
        doc, _ = load_api()
        names = [e["name"] for e in doc["api"]]
        self.assertEqual(len(names), len(set(names)),
                         "duplicate name(s) in meta/patch_api.json api entries")


class PatchApiSpotChecks(unittest.TestCase):
    """Test 3: the documented entries and constants are exactly as recorded."""

    def test_documented_entries(self):
        _, by_name = load_api()
        cases = [
            ("display_fill_rect", "function", "0x03017c50"),
            ("keypad_scan_and_map_pressed_key", "function", "0x03013660"),
            ("lcd_bus_restore_after_keypad_scan", "function", "0x0301cad0"),
        ]
        for name, kind, address in cases:
            with self.subTest(name=name):
                e = by_name[name]
                self.assertEqual(e["kind"], kind)
                self.assertEqual(e["address"], address)

    def test_scan_constants(self):
        _, by_name = load_api()
        self.assertEqual(by_name["SCAN_BACK"]["kind"], "constant")
        self.assertEqual(int(by_name["SCAN_BACK"]["value"], 0), 0x06)
        self.assertEqual(int(by_name["SCAN_UP"]["value"], 0), 0x02)


class PatchApiHeaderCoverage(unittest.TestCase):
    """Test 4: every #define in the header (except the include guard) has a JSON entry."""

    def test_every_header_define_is_in_json(self):
        doc, by_name = load_api()
        defines = re.findall(r"^#define\s+(\w+)", HEADER.read_text(), re.M)
        self.assertTrue(defines, "no #define found in tools/include/dm32_patch_api.h")
        for name in defines:
            if name == INCLUDE_GUARD:
                continue
            with self.subTest(define=name):
                self.assertIn(name, by_name,
                              f"{name} defined in the header but absent from meta/patch_api.json")


class PatchApiGeneratorCheck(unittest.TestCase):
    """Test 5: the committed meta/patch_api.json is not stale (--check exits 0)."""

    def test_check_exits_0(self):
        p = run([sys.executable, tool("gen_patch_api"), "--check"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))


class PatchApiDeterminism(TempDirTestCase):
    """Test 6: regeneration is deterministic -- the generator's --out run is byte-identical to
    the committed file. The generator has an --out flag (verified in gen_patch_api.py's CLI), so
    this never writes the committed meta/patch_api.json and never needs to restore it."""

    def test_regeneration_is_byte_identical(self):
        out = self.tmp / "patch_api.json"
        p = run([sys.executable, tool("gen_patch_api"), "--out", out], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertEqual(out.read_bytes(), META.read_bytes(),
                         "regenerating the API json changed bytes; "
                         "the committed file is stale (run gen_patch_api.py --check)")


if __name__ == "__main__":
    unittest.main()
