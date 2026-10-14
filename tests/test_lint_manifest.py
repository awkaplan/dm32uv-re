"""Host tests for lint_manifest.py (static lint for patch manifests + ad-hoc hook sites) and for
the two build_manifest_patch.py changes that support it:
  * the pattern-12 bsr guard (count_source_bsr / count_elf_bsr) - the assembler silently drops a
    `bsr` to an absolute address / `.equ` absolute symbol, shrinking the blob with no error;
  * the top-level "verify" manifest key, passed through to summary.json unchanged.

Plain python3, stdlib only: every finding's disassembly evidence comes from the shipped
meta/disasm.jsonl + meta/functions.json, and the pattern-12 counters are pure text, so no
toolchain/QEMU image is needed (the builder's own TODO-refusal path is exercised with a no-blob
manifest, which needs no toolchain either).
"""
from __future__ import annotations

import json
import pathlib
import sys
import unittest

from _support import REPO, SNAKE_DIR, TempDirTestCase, describe, import_tool, run, tool

TOOL = tool("lint_manifest")
BUILDER = tool("build_manifest_patch")
SNAKE = SNAKE_DIR / "snake.patch.json"
TEMPLATE = REPO / "tools" / "templates" / "new_patch" / "patch.json.tmpl"

# Snake's menu_append_hook splice (branch to the append trampoline) - the one bsr splice in the
# committed manifest.
SNAKE_HOOK = 0x03049DCC


class LintSnakeManifest(TempDirTestCase):
    """Test: the committed Snake manifest lints clean (LINT PASS, exit 0). Its splices hook
    mid-function sites; the single bsr splice is a tail-transfer trampoline that never returns
    through r15, and the enclosing case block's frame was pushed by its dispatcher (pattern 4),
    so L1 (hook-at-entry) must not fire. The static L2 rule (no prologue push, no earlier call in
    menu_option_gen_idx23's own disasm span) does fire a WARNING here - that is expected and is
    asserted as a warning-only expectation (see the report)."""

    def test_snake_lints_pass(self):
        p = run([sys.executable, TOOL, SNAKE])
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("LINT PASS", p.stdout, describe(p))
        # No error-severity finding on the real manifest.
        self.assertNotIn("ERROR", p.stdout, describe(p))

    def test_snake_menu_append_hook_is_warning_only(self):
        # Genuine L2 warning (no prologue push / no earlier call in menu_option_gen_idx23), but it
        # must be warning severity, not error, and must not change the exit code.
        p = run([sys.executable, TOOL, SNAKE])
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("WARNING L2-r15-liveness", p.stdout, describe(p))
        # The tool prints addresses zero-padded to 8 hex digits (0x03049dcc).
        self.assertIn(f"{SNAKE_HOOK:#010x}", p.stdout, describe(p))


class LintHookMode(TempDirTestCase):
    """Test: --hook runs L1/L2 for one raw address. display_draw_string_gb2312's entry is pattern
    1's example (L1 error, exit 1); channel_type_mode_settings_write is pattern 11's incident
    function (no prologue push - its disasm starts with `subi sp,sp,0x10` - so L2 warns)."""

    def test_hook_display_entry_l1_error(self):
        p = run([sys.executable, TOOL, "--hook", "0x03018998"])
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("L1-hook-at-entry", p.stdout, describe(p))
        self.assertIn("pattern 1", p.stdout, describe(p))

    def test_hook_channel_type_l2_warning_present(self):
        # Function confirmed present in meta/disasm.jsonl; its disasm shows no push with r15
        # early (starts `subi sp,sp,0x10`), so we keep pattern 11's own incident address.
        p = run([sys.executable, TOOL, "--hook", "0x0304c68c"])
        self.assertIn("L2-r15-liveness", p.stdout, describe(p))
        self.assertIn("WARNING", p.stdout, describe(p))
        self.assertIn("0x0304c68c", p.stdout, describe(p))

    def test_hook_json_parses(self):
        p = run([sys.executable, TOOL, "--hook", "0x03018998", "--json"])
        self.assertEqual(p.returncode, 1, describe(p))
        payload = json.loads(p.stdout.splitlines()[-1])   # JSON is the final stdout line
        self.assertEqual(set(payload), {"findings", "verdict", "exit_code"})
        self.assertEqual(payload["verdict"], "FAIL")
        self.assertEqual(payload["exit_code"], 1)
        rules = {f["rule"] for f in payload["findings"]}
        self.assertIn("L1-hook-at-entry", rules)
        for f in payload["findings"]:
            self.assertEqual(set(f), {"rule", "severity", "site", "message", "evidence"})


class LintSynthetic(TempDirTestCase):
    """Test the error rules (L3-L6) and the L4 splice-schema rule with synthetic manifests."""

    def lint(self, obj: dict, name="m.patch.json"):
        p = self.tmp / name
        p.write_text(json.dumps(obj))
        return run([sys.executable, TOOL, p])

    def test_todo_placeholder_is_l3_error(self):
        p = self.lint({
            "name": "t", "description": "TODO: not written yet",
            "splices": [{"name": "hook", "addr": "0x030e9000", "expect": "aa",
                         "bytes": "bb"}]})
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("L3-todo", p.stdout, describe(p))
        self.assertIn("TODO", p.stdout, describe(p))

    def test_splice_missing_expectation_is_l4_error(self):
        p = self.lint({
            "name": "t", "allocations": ["snake_code"],
            "splices": [{"name": "hook", "addr": "0x030e9000", "bytes": "aa"}]})
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("L4-splice-schema", p.stdout, describe(p))

    def test_unknown_allocation_is_l5_error(self):
        p = self.lint({
            "name": "t", "allocations": ["no_such_claim"],
            "splices": [{"name": "hook", "addr": "0x030e9000", "expect": "aa",
                         "bytes": "bb"}]})
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("L5-claims", p.stdout, describe(p))
        self.assertIn("no_such_claim", p.stdout, describe(p))

    def test_unknown_stock_symbol_is_l6_error(self):
        p = self.lint({
            "name": "t", "allocations": ["snake_code"],
            "splices": [{"name": "hook", "addr": "0x030e9000", "expect": "aa",
                         "branch": {"kind": "bsr", "target": "@stock:no_such_fn"}}]})
        self.assertEqual(p.returncode, 1, describe(p))
        self.assertIn("L6-stock-symbol", p.stdout, describe(p))
        self.assertIn("no_such_fn", p.stdout, describe(p))

    def test_control_clean_synthetic_passes(self):
        p = self.lint({
            "name": "t", "allocations": ["snake_code"],
            "splices": [{"name": "hook", "addr": "0x030e9000", "expect": "aa",
                         "bytes": "bb"}]})
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("LINT PASS", p.stdout, describe(p))


class Pattern12Counters(TempDirTestCase):
    """Unit tests for the builder's pattern-12 counters (pure text, no toolchain)."""

    def setUp(self):
        super().setUp()
        self.bmp = import_tool("build_manifest_patch")

    def test_count_source_bsr_ignores_comments_and_equ(self):
        src = """
/* header prose mentioning bsr must not count */
    .text
    .global f
    .equ FD_WRITE, 0x0002c2f4          /* .equ absolute symbol: not a bsr line */
    bsr     fd6818b_reg_write           ; line comment after a real bsr still counts
    # bsr comment line
    // bsr comment line
    bsr     0x0002c2f4                  ; the pattern-12 trap: source counts, ELF won't
"""
        self.assertEqual(self.bmp.count_source_bsr([src]), 2)

    def test_count_elf_bsr_counts_objdump_mnemonics(self):
        elf = """
Disassembly of section .text:

00300000 <_entry>:
  300000:\t05 e0 6a 58 \tbsr     0x3002c2f4
  300004:\t6a 58 04 20 \tjmpi    0x30000a
  300008:\t05 e0 8c 4a \tbsr     0x300e9050
  30000c:\t4a 00 \tbr      0x300000
"""
        self.assertEqual(self.bmp.count_elf_bsr(elf), 2)

    def test_count_elf_bsr_handles_packed_hex(self):
        elf = " 3012e1c:\tec42fe00 \tori r2, r2, 65024\n 3012e20:\t05e0c2b5 \tbsr 0x3000\n"
        self.assertEqual(self.bmp.count_elf_bsr(elf), 1)


class BuilderChanges(TempDirTestCase):
    """Host-side checks of the two builder edits. The full template build needs the toolchain
    (its blob compiles C), so the deliberate TODO refusal is exercised with a no-blob manifest
    that reaches build_splice without a toolchain, and the template is checked only for the
    schema gate (it must fail for its own reason, never an unknown-key error about "verify")."""

    def builder(self, manifest: pathlib.Path, out: pathlib.Path):
        return run([sys.executable, BUILDER, manifest, "--out", out])

    def test_builder_refuses_todo_placeholder(self):
        m = self.tmp / "todo.patch.json"
        m.write_text(json.dumps({
            "name": "todotest", "output_image": "todotest.bin",
            "splices": [{"name": "hook", "addr": "TODO_HOOK_ADDR",
                         "expect": "TODO_STOCK_BYTES_AT_HOOK_ADDR",
                         "branch": {"kind": "bsr", "target": "@__PATCH_NAME__"}}]}))
        p = self.builder(m, self.tmp / "out")
        self.assertNotEqual(p.returncode, 0, describe(p))
        self.assertIn("TODO", p.stderr + p.stdout, describe(p))

    def test_builder_accepts_verify_key_and_copies_to_summary(self):
        m = self.tmp / "v.patch.json"
        verify = {"keyseq": "boot-to-standby", "until_step": 5, "settle_after": 25,
                  "timeout": 500, "expect_frames": [4433]}
        m.write_text(json.dumps({"name": "vtest", "output_image": "vtest.bin",
                                 "verify": verify}))
        out = self.tmp / "out"
        p = self.builder(m, out)
        self.assertEqual(p.returncode, 0, describe(p))
        summary = json.loads((out / "summary.json").read_text())
        self.assertEqual(summary["verify"], verify)

    def test_builder_template_fails_for_its_own_reason_not_verify(self):
        # The schema gate must accept the template's keys (and the new "verify" key); the run
        # fails for a later reason (toolchain/source/TODO), never with an unknown-key error
        # about "verify".
        p = self.builder(TEMPLATE, self.tmp / "out")
        self.assertNotEqual(p.returncode, 0, describe(p))
        out = p.stderr + p.stdout
        self.assertNotIn("unknown key", out, describe(p))
        self.assertNotIn("'verify'", out, describe(p))


if __name__ == "__main__":
    unittest.main()
