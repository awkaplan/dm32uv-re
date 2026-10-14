"""Host tests (test 7): the named keyseq scenarios and screen fingerprints stay loadable,
internally consistent and resolvable, and the two edited CLIs' --help still works with no
QEMU on PATH. Nothing here writes into the repo tree (the synthetic qemu.log test uses a
per-test temp dir)."""
from __future__ import annotations

import sys
import unittest

from _support import REPO, TempDirTestCase, describe, import_tool, run, tool


class KeyseqScenarioChecks(unittest.TestCase):
    """data/keyseq_scenarios.json parses, every script matches the raw grammar, and
    resolve_keyseq does what the docstring promises."""

    @classmethod
    def setUpClass(cls):
        cls.keyseq_lib = import_tool("keyseq_lib")
        cls.qemu_run = import_tool("qemu_run")

    def test_scenarios_parse_and_validate(self):
        scenarios = self.keyseq_lib.load_scenarios()
        self.assertTrue(scenarios, "no scenarios in data/keyseq_scenarios.json")
        for name, sc in scenarios.items():
            with self.subTest(name=name):
                self.assertRegex(sc["keyseq"], self.keyseq_lib.RAW_KEYSEQ_RE,
                                 "keyseq does not match the raw grammar")
                self.assertIsInstance(sc["until_step"], int)
                self.assertIsInstance(sc["description"], str)
                self.assertTrue(sc["description"])
                self.assertIsInstance(sc["source"], str)
                self.assertTrue(sc["source"])

    def test_resolve_raw_passthrough(self):
        raw = "-1:0:1:31:0:20;-1:0:1:17:20:120"
        got, scenario = self.keyseq_lib.resolve_keyseq(raw)
        self.assertEqual(got, raw)
        self.assertIsNone(scenario)

    def test_resolve_probe_matches_qemu_boot_diff(self):
        # The "probe" scenario is a hand-reconstruction of qemu_boot_diff.PROBE_KEYSEQ; it must
        # resolve to a script that presses the Back key (2:10:1:17) and has 4 steps.
        got, scenario = self.keyseq_lib.resolve_keyseq("probe")
        self.assertIsNotNone(scenario)
        self.assertEqual(got, scenario["keyseq"])
        self.assertEqual(scenario["until_step"], 4)
        self.assertIn(self.qemu_run.KEYS["Back"], got)

    def test_resolve_unknown_raises_naming_available(self):
        with self.assertRaises(ValueError) as cm:
            self.keyseq_lib.resolve_keyseq("no-such-scenario")
        self.assertIn("no-such-scenario", str(cm.exception))
        self.assertIn("probe", str(cm.exception), "error should list available scenario names")

    def test_press_wait_build(self):
        self.assertEqual(self.keyseq_lib.press("Back", 20, 300), "2:10:1:17:20:300")
        self.assertEqual(self.keyseq_lib.press("Menu", 20, 120), "-1:0:1:17:20:120")
        self.assertEqual(self.keyseq_lib.wait(400), "-1:0:1:31:0:400")
        self.assertEqual(self.keyseq_lib.build("a", "b", "c"), "a;b;c")
        with self.assertRaises(ValueError):
            self.keyseq_lib.press("NoSuchKey", 1, 1)


class FingerprintChecks(unittest.TestCase):
    """data/screen_fingerprints.json parses, every entry is well-formed, and matches() resolves
    the pixel counts the docs name."""

    @classmethod
    def setUpClass(cls):
        cls.fingerprints = import_tool("fingerprints")

    def test_fingerprints_parse(self):
        fp = self.fingerprints.load_fingerprints()
        self.assertTrue(fp, "no fingerprints in data/screen_fingerprints.json")
        for name, spec in fp.items():
            with self.subTest(name=name):
                self.assertIn("context", spec)
                self.assertIn("source", spec)
                v = spec["nonblack"]
                if isinstance(v, dict):
                    self.assertIn("min", v)
                    self.assertIn("max", v)
                    self.assertLessEqual(v["min"], v["max"])
                else:
                    self.assertIsInstance(v, int)

    def test_matches(self):
        self.assertIn("snake-category-sublist", self.fingerprints.matches(9472))
        self.assertIn("standby-blank-chip", self.fingerprints.matches(13618))
        self.assertEqual(self.fingerprints.matches(5), [])

    def test_describe_enriches(self):
        frames = [{"idx": 2, "step": 1, "nonblack": 9472}, {"idx": 3, "step": 2, "nonblack": 5}]
        out = self.fingerprints.describe(frames)
        self.assertIn("snake-category-sublist", out[0]["matches"])
        self.assertEqual(out[1]["matches"], [])
        self.assertEqual(out[0]["idx"], 2)  # original fields preserved


class CliHelpChecks(unittest.TestCase):
    """The two edited CLIs' --help works without QEMU and advertises the new flags."""

    def test_qemu_run_help(self):
        p = run([sys.executable, tool("qemu_run"), "--help"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("--json", p.stdout)
        self.assertIn("--keyseq-name", p.stdout)

    def test_verify_patch_help(self):
        p = run([sys.executable, tool("verify_patch"), "--help"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("--json", p.stdout)

    def test_keyseq_lib_cli(self):
        p = run([sys.executable, tool("keyseq_lib"), "list"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))
        self.assertIn("probe", p.stdout)
        p = run([sys.executable, tool("keyseq_lib"), "resolve", "no-such-scenario"], cwd=REPO)
        self.assertEqual(p.returncode, 2, describe(p))
        self.assertIn("available scenarios", p.stderr)


class SummarizeFramesChecks(TempDirTestCase):
    """summarize_frames parses KEYSEQ/GRAMDUMP lines into idx/step/nonblack frames."""

    def test_parses_synthetic_log(self):
        log = self.tmp / "qemu.log"
        log.write_text(
            "unrelated boot chatter\n"
            "KEYSEQ -> step 0\n"
            "GRAMDUMP[0] settled: nonblack=0\n"
            "GRAMDUMP[1] settled: nonblack=580\n"
            "KEYSEQ -> step 1\n"
            "GRAMDUMP[2] settled: nonblack=13618\n"
            "KEYSEQ -> step 2\n"
        )
        qemu_run = import_tool("qemu_run")
        frames = qemu_run.summarize_frames(log)
        self.assertEqual(
            [(f["idx"], f["step"], f["nonblack"]) for f in frames],
            [(0, 0, 0), (1, 0, 580), (2, 1, 13618)],
        )

    def test_missing_log_returns_empty(self):
        qemu_run = import_tool("qemu_run")
        self.assertEqual(qemu_run.summarize_frames(self.tmp / "nope.log"), [])


if __name__ == "__main__":
    unittest.main()
