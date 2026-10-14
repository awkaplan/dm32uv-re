"""Host tests (test 6): the repo's own consistency checkers pass, and export_xrefs.py's
partial-disasm guard holds. Nothing here touches meta/: the guard test runs a copy of the script
against a temporary tree."""
from __future__ import annotations

import shutil
import sys
import unittest

from _support import REPO, TempDirTestCase, describe, run, tool


class RepoCheckers(unittest.TestCase):

    def test_check_doc_claims_exits_0(self):
        p = run([sys.executable, tool("check_doc_claims")], cwd=REPO)
        self.assertEqual(p.returncode, 0,
                         "check_doc_claims.py reported FAILs:\n"
                         + "\n".join(l for l in p.stdout.splitlines() if ": FAIL" in l)
                         + describe(p, tail=5))

    def test_link_artifacts_are_current(self):
        p = run([sys.executable, tool("gen_link_artifacts"), "--check"], cwd=REPO)
        self.assertEqual(p.returncode, 0, describe(p))


class ExportXrefsPartialGuard(TempDirTestCase):

    def test_refuses_three_line_disasm(self):
        # Mirror the layout export_xrefs.py resolves REPO_ROOT from (parents[3] of the script).
        script = self.tmp / "tools" / "src" / "dm32_patch_tools" / "export_xrefs.py"
        script.parent.mkdir(parents=True)
        shutil.copy2(tool("export_xrefs"), script)
        meta = self.tmp / "meta"
        meta.mkdir()
        shutil.copy2(REPO / "meta" / "functions.json", meta / "functions.json")
        with open(REPO / "meta" / "disasm.jsonl") as src:
            head = [next(src) for _ in range(3)]
        (meta / "disasm.jsonl").write_text("".join(head))

        p = run([sys.executable, script], cwd=self.tmp)
        self.assertNotEqual(p.returncode, 0, describe(p))
        self.assertIn("covers only 3/", p.stderr, describe(p))
        self.assertFalse((meta / "xrefs.json").exists(), "guard tripped but xrefs.json was written")


if __name__ == "__main__":
    unittest.main()
