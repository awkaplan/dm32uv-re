#!/usr/bin/env python3
"""Host tests for tools/src/dm32_patch_tools/verify_manifest.py (stdlib unittest, no QEMU).

The dynamic QEMU half is not exercised here (the image suite owns QEMU); these tests cover the
verify-block validation, the ordered-subsequence matching rule, and the --json/--skip-dynamic
CLI behaviour.
"""
from __future__ import annotations

import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

from _support import REPO, TOOLS_SRC, import_tool  # noqa: E402

TOOL = TOOLS_SRC / "verify_manifest.py"
vm = import_tool("verify_manifest")


def run(cmd, cwd=REPO):
    return subprocess.run(cmd, capture_output=True, text=True, cwd=cwd)


def write_manifest(directory: Path, verify=None) -> Path:
    m = {"name": "t", "blobs": [], "data": [], "splices": []}
    if verify is not None:
        m["verify"] = verify
    p = Path(directory) / "t.patch.json"
    p.write_text(json.dumps(m))
    return p


GOOD_VERIFY = {"keyseq": "probe",
               "expect_frames": [0, {"min": 2990, "max": 4433}, {"name": "menu-no-codeplug"}]}


class VerifyBlockValidation(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def test_no_verify_block_exits_0(self):
        p = run([sys.executable, str(TOOL), str(write_manifest(self.dir))])
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertIn("no 'verify' block", p.stdout)

    def test_good_block_validates_and_skips_dynamic(self):
        p = run([sys.executable, str(TOOL), str(write_manifest(self.dir, GOOD_VERIFY)),
                 "--skip-dynamic", "--json", "-"])
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertIn("dynamic verification skipped", p.stdout)
        last = json.loads(p.stdout.strip().splitlines()[-1])
        self.assertIsNone(last["verdict"])
        self.assertEqual(last["exit_code"], 0)

    def test_verify_not_an_object(self):
        m = {"name": "t", "verify": ["not", "a", "dict"]}
        p = self.dir / "t.patch.json"
        p.write_text(json.dumps(m))
        r = run([sys.executable, str(TOOL), str(p)])
        self.assertEqual(r.returncode, 2)
        self.assertIn('"verify"', r.stderr)

    def test_unknown_key_names_field(self):
        p = run([sys.executable, str(TOOL),
                 str(write_manifest(self.dir, {**GOOD_VERIFY, "bogus": 1}))])
        self.assertEqual(p.returncode, 2)
        self.assertIn("bogus", p.stderr)

    def test_missing_keyseq(self):
        p = run([sys.executable, str(TOOL),
                 str(write_manifest(self.dir, {"expect_frames": [0]}))])
        self.assertEqual(p.returncode, 2)
        self.assertIn('"verify.keyseq"', p.stderr)

    def test_unknown_scenario(self):
        p = run([sys.executable, str(TOOL),
                 str(write_manifest(self.dir, {**GOOD_VERIFY, "keyseq": "no-such-scenario"}))])
        self.assertEqual(p.returncode, 2)
        self.assertIn('"verify.keyseq"', p.stderr)

    def test_expect_frames_wrong_type(self):
        p = run([sys.executable, str(TOOL),
                 str(write_manifest(self.dir, {"keyseq": "probe", "expect_frames": "nope"}))])
        self.assertEqual(p.returncode, 2)
        self.assertIn('"verify.expect_frames"', p.stderr)

    def test_unknown_fingerprint_name(self):
        bad = {"keyseq": "probe", "expect_frames": [{"name": "no-such-screen"}]}
        p = run([sys.executable, str(TOOL), str(write_manifest(self.dir, bad))])
        self.assertEqual(p.returncode, 2)
        self.assertIn("no-such-screen", p.stderr)

    def test_minmax_must_be_ints(self):
        bad = {"keyseq": "probe", "expect_frames": [{"min": "1", "max": 2}]}
        p = run([sys.executable, str(TOOL), str(write_manifest(self.dir, bad))])
        self.assertEqual(p.returncode, 2)
        self.assertIn('"verify.expect_frames"[0]', p.stderr)

    def test_until_step_defaults_from_scenario(self):
        _, v = vm.load_verify_block(write_manifest(self.dir, GOOD_VERIFY))
        self.assertEqual(v["until_step"], 4)  # the "probe" scenario's own until_step

    def test_raw_keyseq_accepted(self):
        _, v = vm.load_verify_block(write_manifest(
            self.dir, {"keyseq": "-1:0:1:31:0:400;2:7:1:17:20:120", "expect_frames": [0]}))
        self.assertEqual(v["until_step"], 2)  # step count when no scenario default exists


class MatchRule(unittest.TestCase):
    """The ordered-subsequence rule: extras allowed anywhere, absences fail, order enforced."""

    def frames(self, *nonblacks):
        return [{"idx": i, "step": 0, "nonblack": n, "matches": []} for i, n in enumerate(nonblacks)]

    def test_exact(self):
        _, unmatched = vm.match_expect_frames([1, 2, 3], self.frames(1, 2, 3))
        self.assertEqual(unmatched, [])

    def test_prefix_suffix_extras_allowed(self):
        _, unmatched = vm.match_expect_frames([2, 3], self.frames(9, 2, 8, 3, 7))
        self.assertEqual(unmatched, [])

    def test_missing_middle_element_fails(self):
        _, unmatched = vm.match_expect_frames([1, 2, 3], self.frames(1, 3))
        self.assertEqual(unmatched, [2])

    def test_order_enforced(self):
        _, unmatched = vm.match_expect_frames([3, 1], self.frames(1, 3))
        self.assertEqual(unmatched, [1])  # 1 matched before 3, so the second element finds nothing

    def test_minmax_bounds(self):
        _, unmatched = vm.match_expect_frames([{"min": 10, "max": 20}], self.frames(15))
        self.assertEqual(unmatched, [])
        _, unmatched = vm.match_expect_frames([{"min": 10, "max": 20}], self.frames(25))
        self.assertEqual(unmatched, [{"min": 10, "max": 20}])

    def test_name_via_real_fingerprints(self):
        _, unmatched = vm.match_expect_frames([{"name": "snake-category-sublist"}],
                                              self.frames(9472))
        self.assertEqual(unmatched, [])
        _, unmatched = vm.match_expect_frames([{"name": "snake-category-sublist"}],
                                              self.frames(5))
        self.assertEqual(unmatched, [{"name": "snake-category-sublist"}])

    def test_frame_matches_list_takes_precedence(self):
        fr = [{"idx": 0, "step": 0, "nonblack": 9472, "matches": ["custom-name"]}]
        _, unmatched = vm.match_expect_frames([{"name": "custom-name"}], fr)
        self.assertEqual(unmatched, [])


class SnakeManifest(unittest.TestCase):
    def test_snake_verify_block_validates(self):
        p = run([sys.executable, str(TOOL),
                 str(REPO / "tools/examples/snake/snake.patch.json"),
                 "--skip-dynamic", "--json", "-"])
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        last = json.loads(p.stdout.strip().splitlines()[-1])
        self.assertEqual(last["exit_code"], 0)

    def test_snake_expect_against_readme_token_line(self):
        """The README's documented token line must satisfy the manifest's own expect_frames."""
        manifest = json.loads((REPO / "tools/examples/snake/snake.patch.json").read_text())
        expect = manifest["verify"]["expect_frames"]
        token = [0, 580, 2993, 13618, 13309, 9472, 1175, 1166, 1175, 1138, 1175, 1164, 1175,
                 1142, 1175, 2993, 2997]  # README: the optional 2993 boot frame included
        frames = [{"idx": i, "step": 0, "nonblack": n, "matches": []}
                  for i, n in enumerate(token)]
        _, unmatched = vm.match_expect_frames(expect, frames)
        self.assertEqual(unmatched, [])
        # and without the optional 2993 boot straggler (the subsequence rule's whole point)
        frames = [{"idx": i, "step": 0, "nonblack": n, "matches": []}
                  for i, n in enumerate(token) if i != 2]
        _, unmatched = vm.match_expect_frames(expect, frames)
        self.assertEqual(unmatched, [])


if __name__ == "__main__":
    unittest.main()
