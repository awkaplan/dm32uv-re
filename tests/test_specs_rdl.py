"""Host tests: SystemRDL chip descriptions (specs/rdl/) and their generated outputs.

Two halves:
  * stdlib-only checks on the COMMITTED outputs in specs/generated/ (always run): the evidence
    rule holds in every JSON index, the flash-safety facts recorded for the two flash chips have
    not drifted, and the headers compile as C99.
  * toolchain checks (skip cleanly unless the `specs` uv group is installed, in this interpreter
    or in tools/.venv): `gen_rdl.py --check` passes on the repo, and the generator itself rejects
    missing evidence, malformed command blocks and stale output (run on a temporary copy of the
    layout, never on the repo tree).
"""
from __future__ import annotations

import json
import pathlib
import shutil
import subprocess
import sys
import unittest

from _support import REPO, TempDirTestCase, describe, run, tool

SPECS = REPO / "specs"
RDL_DIR = SPECS / "rdl"
INC_DIR = SPECS / "generated" / "include"
JSON_DIR = SPECS / "generated" / "json"
CONFIDENCE = {"CONFIRMED", "DATASHEET", "STRUCTURAL", "INFERRED"}
EVIDENCE = ("ds_ref", "fw_writes", "fw_reads", "hw_reads")


def _specs_python() -> str | None:
    """An interpreter that can import the SystemRDL toolchain, or None."""
    probe = "import systemrdl, peakrdl_cheader, peakrdl_html"
    candidates = [sys.executable, REPO / "tools" / ".venv" / "bin" / "python"]
    for c in candidates:
        if not pathlib.Path(c).exists():
            continue
        try:
            if subprocess.run([str(c), "-c", probe], capture_output=True,
                              timeout=60).returncode == 0:
                return str(c)
        except (OSError, subprocess.TimeoutExpired):
            continue
    return None


SPECS_PY = _specs_python()
requires_specs = unittest.skipUnless(
    SPECS_PY, "SystemRDL toolchain not installed (cd tools && uv sync --group specs)")


def _json_files():
    return sorted(JSON_DIR.glob("*.json"))


def _sent(fw_writes: str | None) -> bool:
    """True if a command's fw_writes says the stock firmware sends it."""
    return bool(fw_writes) and not fw_writes.startswith(("Never", "Not sent"))


class CommittedOutputs(unittest.TestCase):

    def test_every_rdl_has_outputs(self):
        for rdl in sorted(RDL_DIR.glob("*.rdl")):
            if rdl.name == "dm32_udp.rdl":
                continue
            for p in (INC_DIR / f"{rdl.stem}.h", INC_DIR / f"{rdl.stem}_regnum.h",
                      JSON_DIR / f"{rdl.stem}.json"):
                with self.subTest(file=str(p.relative_to(REPO))):
                    self.assertTrue(p.exists(), "missing: run tools/src/dm32_patch_tools/gen_rdl.py")

    def test_evidence_rule_in_json(self):
        for jp in _json_files():
            doc = json.loads(jp.read_text())
            for reg in doc["registers"]:
                for node, kind in [(reg, "reg")] + [(f, "field") for f in reg["fields"]]:
                    where = f"{jp.name}: {reg['path']}" + ("" if kind == "reg" else f".{node['inst_name']}")
                    with self.subTest(node=where):
                        self.assertIn(node["confidence"], CONFIDENCE)
                        self.assertTrue(any(node.get(e) for e in EVIDENCE),
                                        f"{kind} has none of {EVIDENCE}")

    def test_flash_opcode_safety_facts(self):
        """Pins the stock-firmware opcode sets traced into the two flash descriptions. If the
        trace is ever revised, update the .rdl AND this expectation together, deliberately."""
        expected = {
            "w25q128jv": {0x02, 0x03, 0x05, 0x06, 0x20},
            "gd25q80": {0x01, 0x02, 0x04, 0x05, 0x06, 0x20, 0x35},
        }
        destructive = {0x01, 0x02, 0x11, 0x20, 0x31, 0x32, 0x42, 0x44, 0x52, 0x60, 0xC7, 0xD8}
        for chip, want in expected.items():
            jp = JSON_DIR / f"{chip}.json"
            if not jp.exists():
                self.skipTest(f"{jp.name} not generated")
            cmds = {r["wire_number"]: r for r in json.loads(jp.read_text())["registers"]
                    if r["is_command"]}
            with self.subTest(chip=chip):
                self.assertEqual({op for op, r in cmds.items() if _sent(r["fw_writes"])}, want)
                for op in sorted(destructive & set(cmds)):
                    self.assertTrue(cmds[op]["fw_writes"],
                                    f"{chip} opcode 0x{op:02X}: erase/program opcode without fw_writes")

    def test_flash_erase_program_opcodes_marked_destructive(self):
        """Every erase / program / status-write / security-register erase+program opcode of both
        flash chips carries `destructive = true`, nothing else does, and the generated
        <CHIP>_CMD_IS_DESTRUCTIVE list matches."""
        expected = {
            "w25q128jv": {0x01, 0x02, 0x11, 0x20, 0x31, 0x32, 0x42, 0x44, 0x52, 0x60, 0xC7, 0xD8},
            "gd25q80": {0x01, 0x02, 0x20, 0x32, 0x42, 0x44, 0x52, 0x60, 0xC7, 0xD8},
        }
        for chip, want in expected.items():
            jp = JSON_DIR / f"{chip}.json"
            if not jp.exists():
                self.skipTest(f"{jp.name} not generated")
            cmds = {r["wire_number"]: r for r in json.loads(jp.read_text())["registers"]
                    if r["is_command"]}
            with self.subTest(chip=chip):
                self.assertTrue(want <= set(cmds), f"opcodes missing from {chip}: "
                                f"{sorted(hex(o) for o in want - set(cmds))}")
                self.assertEqual({op for op, r in cmds.items() if r["destructive"]}, want)
                regnum = (INC_DIR / f"{chip}_regnum.h").read_text()
                listed = ", ".join(f"0x{o:02X}" for o in sorted(want))
                self.assertIn(f"#define {chip.upper()}_CMD_DESTRUCTIVE_LIST {listed}\n", regnum)
                self.assertIn(f"#define {chip.upper()}_CMD_IS_DESTRUCTIVE(op) (", regnum)

    def test_flash_status_registers_have_wr_cmd_and_nonvolatile(self):
        for chip in ("w25q128jv", "gd25q80"):
            jp = JSON_DIR / f"{chip}.json"
            if not jp.exists():
                self.skipTest(f"{jp.name} not generated")
            for r in json.loads(jp.read_text())["registers"]:
                if r["block"] != "status":
                    continue
                with self.subTest(reg=f"{chip}.{r['inst_name']}"):
                    self.assertTrue(r["wr_cmd"])
                    for f in r["fields"]:
                        self.assertIn(f["nonvolatile"], (True, False), f["inst_name"])

    def test_headers_compile_c99(self):
        cc = shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
        if not cc:
            self.skipTest("no C compiler on PATH")
        headers = sorted(INC_DIR.glob("*.h"))
        if not headers:
            self.skipTest("no generated headers")
        tu = "".join(f'#include "{h.name}"\n' for h in headers) + "int main(void) { return 0; }\n"
        p = subprocess.run([cc, "-fsyntax-only", "-std=c99", "-Wall", "-Werror", f"-I{INC_DIR}",
                            "-x", "c", "-"], input=tu, capture_output=True, text=True, timeout=120)
        self.assertEqual(p.returncode, 0, p.stderr[-4000:])


@requires_specs
class GeneratorOnRepo(unittest.TestCase):

    def test_check_passes(self):
        p = run([SPECS_PY, tool("gen_rdl"), "--check"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))


GOOD = """`include "dm32_udp.rdl"
addrmap {name} {{
    default regwidth = 8;
    reg {{ name = "R"; confidence = "DATASHEET"; ds_ref = "test DS, 1.1, p.1";
          field {{ sw = rw; hw = na; confidence = "DATASHEET"; ds_ref = "test DS, 1.1, p.1"; }} F[0:0] = 0;
    }} R0 @ 0x3;
    addrmap {{
        reg {{ confidence = "DATASHEET"; ds_ref = "test DS, 2, p.2";
              field {{ sw = r; hw = na; confidence = "DATASHEET"; ds_ref = "x"; }} opcode[7:0] = {op};
        }} GO @ 0x06;
    }} cmd @ 0x100;
}};
"""


@requires_specs
class GeneratorBehaviour(TempDirTestCase):

    def setUp(self):
        super().setUp()
        # Mirror the layout gen_rdl.py resolves REPO from (parents[3] of the script).
        script = self.tmp / "tools" / "src" / "dm32_patch_tools" / "gen_rdl.py"
        script.parent.mkdir(parents=True)
        shutil.copy2(tool("gen_rdl"), script)
        self.script = script
        self.rdl = self.tmp / "specs" / "rdl"
        self.rdl.mkdir(parents=True)
        shutil.copy2(RDL_DIR / "dm32_udp.rdl", self.rdl / "dm32_udp.rdl")

    def gen(self, *args):
        return run([SPECS_PY, self.script, "--no-html", *args], cwd=self.tmp)

    def test_generate_then_check_then_stale(self):
        (self.rdl / "chip_a.rdl").write_text(GOOD.format(name="chip_a", op="0x06"))
        p = self.gen()
        self.assertEqual(p.returncode, 0, describe(p))
        regnum = (self.tmp / "specs/generated/include/chip_a_regnum.h").read_text()
        self.assertIn("CHIP_A_CMD_GO = 0x06", regnum)
        self.assertIn("CHIP_A_R0 = 0x03", regnum)
        doc = json.loads((self.tmp / "specs/generated/json/chip_a.json").read_text())
        self.assertEqual([r["wire_number"] for r in doc["registers"]], [0x03, 0x06])
        p = self.gen("--check")
        self.assertEqual(p.returncode, 0, describe(p))
        h = self.tmp / "specs/generated/include/chip_a.h"
        h.write_text(h.read_text() + "// edited\n")
        p = self.gen("--check")
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("chip_a.h (stale)", p.stderr)

    def test_missing_confidence_is_hard_error(self):
        good = GOOD.format(name="chip_b", op="0x06")
        bad = good.replace('field { sw = rw; hw = na; confidence = "DATASHEET";',
                           "field { sw = rw; hw = na;", 1)
        self.assertNotEqual(bad, good)
        (self.rdl / "chip_b.rdl").write_text(bad)
        for args in ((), ("--check",)):
            p = self.gen(*args)
            self.assertEqual(p.returncode, 1, describe(p))
            self.assertIn("field has no confidence", p.stderr)
        self.assertFalse((self.tmp / "specs/generated/json/chip_b.json").exists())

    def test_missing_evidence_is_hard_error(self):
        bad = GOOD.format(name="chip_c", op="0x06").replace(
            'reg { name = "R"; confidence = "DATASHEET"; ds_ref = "test DS, 1.1, p.1";',
            'reg { name = "R"; confidence = "DATASHEET";')
        (self.rdl / "chip_c.rdl").write_text(bad)
        p = self.gen("--check")
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("reg has none of", p.stderr)

    def test_command_opcode_must_match_offset(self):
        (self.rdl / "chip_d.rdl").write_text(GOOD.format(name="chip_d", op="0x07"))
        p = self.gen("--check")
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("reset equals its wire number 0x6", p.stderr)


if __name__ == "__main__":
    unittest.main()
