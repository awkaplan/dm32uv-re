"""Host tests: the committed firmware artefacts are what their sidecars and derivations say."""
from __future__ import annotations

import hashlib
import unittest

from _support import IRAM_IMAGE, REPO, STOCK_FULL, import_tool


def sha256_file(path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


class Sha256Sidecars(unittest.TestCase):
    """Test 1: every data/**/*.sha256 sidecar verifies (`sha256sum -c` semantics, names relative
    to the sidecar's own directory)."""

    def test_every_sidecar_verifies(self):
        sidecars = sorted((REPO / "data").rglob("*.sha256"))
        self.assertTrue(sidecars, "no *.sha256 sidecars found under data/")
        for sidecar in sidecars:
            rel = sidecar.relative_to(REPO)
            lines = [l for l in sidecar.read_text().splitlines() if l.strip()]
            with self.subTest(sidecar=str(rel)):
                self.assertTrue(lines, f"{rel} is empty")
                for line in lines:
                    digest, _, name = line.partition("  ")
                    name = name.lstrip("*").strip()
                    self.assertRegex(digest, r"^[0-9a-f]{64}$", f"{rel}: malformed line {line!r}")
                    target = sidecar.parent / name
                    self.assertTrue(target.is_file(), f"{rel} names {name!r}, which does not exist")
                    self.assertEqual(sha256_file(target), digest,
                                     f"{rel}: sha256 of {target.relative_to(REPO)} does not match")


class DerivedIram(unittest.TestCase):
    """Test 8: the committed IRAM image is exactly derive_iram.derive() of the full flash image."""

    def test_iram_matches_derivation(self):
        derive_iram = import_tool("derive_iram")
        derived = derive_iram.derive(STOCK_FULL.read_bytes())
        committed = IRAM_IMAGE.read_bytes()
        self.assertEqual(len(committed), len(derived), "IRAM image size differs from derivation")
        if committed != derived:
            first = next(i for i, (a, b) in enumerate(zip(committed, derived)) if a != b)
            ndiff = sum(1 for a, b in zip(committed, derived) if a != b)
            self.fail(f"{IRAM_IMAGE.relative_to(REPO)} differs from derive_iram.derive("
                      f"{STOCK_FULL.name}): {ndiff} bytes, first at IRAM {0x10000 + first:#x}")


if __name__ == "__main__":
    unittest.main()
