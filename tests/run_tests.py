#!/usr/bin/env python3
"""Run the dm32uv-re test suite; console output plus a JUnit XML file per suite.

    python3 tests/run_tests.py                     # host suite (pure python, ~seconds)
    python3 tests/run_tests.py --suite image       # toolchain/QEMU suite, inside the docker image
    python3 tests/run_tests.py --suite all         # host here + image suite (via docker run
                                                   # when not already inside the image)

Suites (see tests/_support.py):
    host   tests/test_*.py except test_image_*.py - plain python3, stdlib only
    image  tests/test_image_*.py - needs csky-abiv2-elf-* and qemu-system-cskyv2 on PATH

Outside the image, `--suite image` / `--suite all` run the image suite with the repo mounted
READ-ONLY and only the JUnit directory writable:
    docker run --rm -v <repo>:/repo:ro -v <junit-dir>:/repo/<junit-dir> -w /repo <--docker-image> \
        -c 'python3 tests/run_tests.py --suite image ...'
(default image: $DM32_TEST_IMAGE or dm32uv-re-pipeline:latest; build it from docker/).

Results: <junit-dir>/<suite>.xml (default out/test-results/, git-ignored), one <testcase> per
test method; a subTest failure is reported on its parent test. The last console line is
machine-readable:  RESULT suite=<s> tests=N passed=N failed=N errors=N skipped=N time=S status=OK|FAIL

Exit status: 0 if every executed suite passed (skips allowed), 1 otherwise, 2 on usage errors.
Environment: DM32_TEST_KEEP=1 keeps each test's temp directory.
"""
from __future__ import annotations

import argparse
import hashlib
import os
import pathlib
import subprocess
import sys
import time
import unittest
import xml.etree.ElementTree as ET

TESTS = pathlib.Path(__file__).resolve().parent
REPO = TESTS.parent
sys.path.insert(0, str(TESTS))
from _support import in_image  # noqa: E402

DEFAULT_IMAGE = os.environ.get("DM32_TEST_IMAGE", "dm32uv-re-pipeline:latest")
DEFAULT_JUNIT_DIR = REPO / "out" / "test-results"


class RecordingResult(unittest.TextTestResult):
    """TextTestResult that also records per-test status, duration and failure text."""

    def __init__(self, *a, **kw):
        super().__init__(*a, **kw)
        self.records: dict[str, dict] = {}
        self._t0: dict[str, float] = {}

    def _rec(self, test) -> dict:
        tid = test.id()
        if tid not in self.records:
            cls, _, name = tid.rpartition(".")
            self.records[tid] = {"classname": cls, "name": name, "status": "passed",
                                 "time": 0.0, "detail": [], "message": ""}
        return self.records[tid]

    def startTest(self, test):
        self._t0[test.id()] = time.monotonic()
        self._rec(test)
        super().startTest(test)

    def stopTest(self, test):
        r = self._rec(test)
        r["time"] = time.monotonic() - self._t0.get(test.id(), time.monotonic())
        super().stopTest(test)

    def _mark(self, test, status, err=None, reason=None):
        r = self._rec(test)
        rank = {"passed": 0, "skipped": 1, "failed": 2, "error": 3}
        if rank[status] >= rank[r["status"]]:
            r["status"] = status
        if err is not None:
            text = self._exc_info_to_string(err, test)
            r["detail"].append(text)
            r["message"] = r["message"] or (text.strip().splitlines() or [""])[-1][:500]
        if reason:
            r["message"] = reason

    def addSuccess(self, test):
        super().addSuccess(test)
        self._mark(test, "passed")

    def addFailure(self, test, err):
        super().addFailure(test, err)
        self._mark(test, "failed", err)

    def addError(self, test, err):
        super().addError(test, err)
        self._mark(test, "error", err)

    def addSkip(self, test, reason):
        super().addSkip(test, reason)
        self._mark(test, "skipped", reason=reason)

    def addSubTest(self, test, subtest, err):
        super().addSubTest(test, subtest, err)
        if err is not None:
            status = "failed" if issubclass(err[0], test.failureException) else "error"
            self._mark(test, status, err)
            self._rec(test)["detail"][-1] = f"[{subtest._subDescription()}]\n" + self._rec(test)["detail"][-1]


def discover(suite: str) -> unittest.TestSuite:
    loader = unittest.TestLoader()
    if suite == "image":
        return loader.discover(str(TESTS), pattern="test_image_*.py", top_level_dir=str(TESTS))
    full = loader.discover(str(TESTS), pattern="test_*.py", top_level_dir=str(TESTS))
    keep = unittest.TestSuite()

    def walk(s):
        for t in s:
            if isinstance(t, unittest.TestSuite):
                walk(t)
            elif not t.id().startswith("test_image_"):
                keep.addTest(t)
    walk(full)
    return keep


def write_junit(path: pathlib.Path, suite: str, records: list[dict], elapsed: float) -> None:
    counts = {s: sum(1 for r in records if r["status"] == s)
              for s in ("passed", "failed", "error", "skipped")}
    root = ET.Element("testsuites")
    ts = ET.SubElement(root, "testsuite", name=f"dm32uv-re.{suite}", tests=str(len(records)),
                       failures=str(counts["failed"]), errors=str(counts["error"]),
                       skipped=str(counts["skipped"]), time=f"{elapsed:.3f}",
                       timestamp=time.strftime("%Y-%m-%dT%H:%M:%S"))
    for r in records:
        tc = ET.SubElement(ts, "testcase", classname=r["classname"], name=r["name"],
                           time=f"{r['time']:.3f}")
        if r["status"] in ("failed", "error"):
            el = ET.SubElement(tc, "failure" if r["status"] == "failed" else "error",
                               message=r["message"])
            el.text = "\n".join(r["detail"])
        elif r["status"] == "skipped":
            ET.SubElement(tc, "skipped", message=r["message"])
    path.parent.mkdir(parents=True, exist_ok=True)
    ET.ElementTree(root).write(path, encoding="utf-8", xml_declaration=True)


# Committed inputs the tests read. Tests must never write them; run_local() hashes them before
# and after the suite and reports a failing pseudo-test if any changed (or vanished/emptied).
GUARDED_GLOBS = [("data", "**/*"), ("tools/examples/snake", "*"), ("meta", "*")]


def snapshot_guarded() -> dict[str, str]:
    snap = {}
    for base, pattern in GUARDED_GLOBS:
        for p in sorted((REPO / base).glob(pattern)):
            if p.is_file() and "live-captures" not in p.parts:
                snap[str(p.relative_to(REPO))] = hashlib.sha256(p.read_bytes()).hexdigest()
    return snap


def run_local(suite: str, junit_dir: pathlib.Path, verbosity: int) -> bool:
    print(f"== suite: {suite} ({'inside' if in_image() else 'outside'} the toolchain/QEMU image) ==",
          flush=True)
    before = snapshot_guarded()
    t0 = time.monotonic()
    runner = unittest.TextTestRunner(stream=sys.stdout, verbosity=verbosity,
                                     resultclass=RecordingResult)
    result = runner.run(discover(suite))
    elapsed = time.monotonic() - t0
    records = list(result.records.values())
    after = snapshot_guarded()
    changed = sorted(k for k in before.keys() | after.keys() if before.get(k) != after.get(k))
    guard = {"classname": "run_tests", "name": "committed_inputs_unmodified", "time": 0.0,
             "status": "failed" if changed else "passed", "detail": [], "message": ""}
    if changed:
        guard["message"] = (f"{len(changed)} committed file(s) changed while the suite ran "
                            f"(a test or a concurrent process wrote them): {', '.join(changed[:10])}")
        guard["detail"] = [guard["message"]]
        print(f"\n!! {guard['message']}", flush=True)
    records.append(guard)
    # Errors raised outside any test (module import, setUpClass) have no startTest call.
    for test, err in result.errors:
        if test.id() not in result.records:
            records.append({"classname": test.id(), "name": "setup", "status": "error",
                            "time": 0.0, "detail": [err], "message": err.strip().splitlines()[-1]})
    xml_path = junit_dir / f"{suite}.xml"
    write_junit(xml_path, suite, records, elapsed)

    print("\n-- per-test results --")
    for r in records:
        print(f"  {r['status'].upper():8s} {r['time']:7.1f}s  {r['classname']}.{r['name']}"
              + (f"  ({r['message']})" if r["status"] == "skipped" else ""))
    n = {s: sum(1 for r in records if r["status"] == s) for s in ("passed", "failed", "error", "skipped")}
    ok = n["failed"] == 0 and n["error"] == 0
    print(f"junit: {xml_path}")
    print(f"RESULT suite={suite} tests={len(records)} passed={n['passed']} failed={n['failed']} "
          f"errors={n['error']} skipped={n['skipped']} time={elapsed:.1f} "
          f"status={'OK' if ok else 'FAIL'}", flush=True)
    return ok


def run_in_docker(image: str, junit_dir: pathlib.Path, verbosity: int) -> bool:
    try:
        rel = junit_dir.resolve().relative_to(REPO)
    except ValueError:
        print(f"ERROR: --junit-dir must be inside the repo to run the image suite in docker "
              f"(got {junit_dir})", file=sys.stderr)
        return False
    # The repo is mounted read-only; only the JUnit directory is writable (a nested bind mount).
    junit_dir.mkdir(parents=True, exist_ok=True)
    inner = f"python3 tests/run_tests.py --suite image --junit-dir /repo/{rel} -v{verbosity}"
    cmd = ["docker", "run", "--rm", "-e", "PYTHONDONTWRITEBYTECODE=1",
           "-v", f"{REPO}:/repo:ro", "-v", f"{junit_dir.resolve()}:/repo/{rel}",
           "-w", "/repo", image, "-c", inner]
    print(f"== suite: image (via docker: {image}) ==\n$ {' '.join(cmd)}", flush=True)
    try:
        return subprocess.run(cmd).returncode == 0
    except FileNotFoundError:
        print("ERROR: docker not found; run the image suite inside the image instead",
              file=sys.stderr)
        return False


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--suite", choices=("host", "image", "all"), default="host")
    ap.add_argument("--junit-dir", type=pathlib.Path, default=DEFAULT_JUNIT_DIR)
    ap.add_argument("--docker-image", default=DEFAULT_IMAGE,
                    help=f"image for the image suite when not already inside it (default {DEFAULT_IMAGE})")
    ap.add_argument("--no-docker", action="store_true",
                    help="run the image suite in this environment even outside the image "
                         "(its tests then report as skipped)")
    ap.add_argument("-v", "--verbosity", type=int, default=2)
    args = ap.parse_args()
    os.environ["PYTHONDONTWRITEBYTECODE"] = "1"
    sys.dont_write_bytecode = True

    ok = True
    if args.suite in ("host", "all"):
        ok &= run_local("host", args.junit_dir, args.verbosity)
    if args.suite in ("image", "all"):
        if in_image() or args.no_docker:
            ok &= run_local("image", args.junit_dir, args.verbosity)
        else:
            ok &= run_in_docker(args.docker_image, args.junit_dir, args.verbosity)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
