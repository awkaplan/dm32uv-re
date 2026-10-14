#!/usr/bin/env python3
"""Host tests for tools/dm32, the unified front door (stdlib unittest, no docker re-exec)."""
from __future__ import annotations

import importlib.util
import json
import subprocess
import sys
import unittest

from _support import REPO, in_image  # noqa: E402

DM32 = REPO / "tools" / "dm32"


def run_dm32(*args, timeout=120):
    return subprocess.run([sys.executable, str(DM32), *args],
                          capture_output=True, text=True, cwd=REPO, timeout=timeout)


def load_dm32_module():
    # tools/dm32 has no .py extension, so spec_from_file_location needs an explicit loader.
    import importlib.machinery
    loader = importlib.machinery.SourceFileLoader("dm32_cli", str(DM32))
    spec = importlib.util.spec_from_file_location("dm32_cli", DM32, loader=loader)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


class CliSmoke(unittest.TestCase):
    def test_help_lists_verbs(self):
        p = run_dm32("--help")
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        for verb in ("doctor", "lookup", "keyseq", "new", "build", "lint", "verify-sector",
                     "verify", "run", "render", "stage", "disasm", "scan"):
            self.assertIn(verb, p.stdout)

    def test_unknown_verb_exits_2(self):
        p = run_dm32("no-such-verb")
        self.assertEqual(p.returncode, 2)

    def test_doctor(self):
        p = run_dm32("doctor")
        # WARNs are fine on a host; FAILs would mean the repo itself is broken.
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertIn("summary:", p.stdout)

    def test_doctor_json(self):
        p = run_dm32("doctor", "--json", "-")
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        last = json.loads(p.stdout.strip().splitlines()[-1])
        self.assertIn("checks", last)
        self.assertIn("summary", last)
        self.assertIn("exit_code", last)

    def test_lookup(self):
        p = run_dm32("lookup", "0x03013660")
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertIn("keypad_scan_and_map_pressed_key", p.stdout)

    def test_keyseq_list(self):
        p = run_dm32("keyseq", "list")
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertIn("probe", p.stdout)

    def test_verb_help_never_reexecs(self):
        p = run_dm32("run", "--help", timeout=30)
        self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        self.assertNotIn("docker run", p.stderr)

    @unittest.skipIf(in_image(), "host-only assertion (inside the image the build verb runs)")
    def test_build_no_docker_host_fails_with_remedy(self):
        p = run_dm32("build", "tools/templates/new_patch/patch.json.tmpl", "--no-docker")
        # The template manifest is a deliberate TODO, but on a host without the toolchain the
        # wrapper must fail first with its remedy text and exit 3.
        self.assertEqual(p.returncode, 3, p.stdout + p.stderr)
        self.assertIn("remedy", p.stderr)


class ModuleFunctions(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.m = load_dm32_module()

    def test_needs_image_map(self):
        self.assertTrue(self.m.needs_image("build"))
        self.assertTrue(self.m.needs_image("run"))
        self.assertFalse(self.m.needs_image("lookup"))
        self.assertFalse(self.m.needs_image("doctor"))

    def test_rewrite_args_for_container(self):
        repo = self.m.REPO
        out = self.m.rewrite_args_for_container(
            repo, ["build", str(repo / "tools/examples/snake/snake.patch.json"),
                   "/outside/path", "--require-claims"])
        self.assertEqual(out[0], "build")
        self.assertEqual(out[1], "/repo/tools/examples/snake/snake.patch.json")
        self.assertEqual(out[2], "/outside/path")  # outside the repo: untouched
        self.assertEqual(out[3], "--require-claims")

    def test_build_docker_cmd_shape(self):
        cmd = self.m.build_docker_cmd(self.m.REPO, "img:tag", ["build", "x.patch.json"])
        self.assertIn("-v", cmd)
        self.assertIn(f"{self.m.REPO}:/repo", cmd)
        self.assertIn("-w", cmd)
        self.assertIn("/repo", cmd)
        self.assertIn("img:tag", cmd)
        self.assertIn("-c", cmd)
        self.assertIn("python3 tools/dm32 build x.patch.json", cmd)

    def test_can_reexec_respects_no_docker(self):
        self.assertFalse(self.m.can_reexec(["--no-docker"]))


if __name__ == "__main__":
    unittest.main()
