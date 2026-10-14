"""Host tests: the Kaitai descriptions under specs/ksy/ parse their fixtures and write them back
byte for byte (the "round-trip before write" rule, specs/README.md), and specs/generated/ is
current.

SIDECARS. Each specs/ksy/<name>.ksy may have specs/ksy/<name>.fixtures.json:

    {"root_type": "<optional>",
     "generic": [{"path": "<repo-relative>", "offset": N, "length": N, "note": "...",
                  "root_type": "<optional, overrides the sidecar's>",
                  "expect": {"<field path>": <value>, ...}}],
     "private_globs": ["<glob relative to $DM32_PRIVATE_DUMPS>",
                       {"glob": "...", "root_type": "...", "stream": "host" | "radio"}]}

  root_type: the class to parse with. Omitted or equal to the ksy id: the root type. Otherwise a
    nested type of this ksy ("loader_session", "a::b"), or "<other ksy id>[::type]".
  expect (optional): dotted field paths ("frames[2].body.addr") and their values. Enums compare
    by name, ints may be written "0x..". Checked after parsing; this is what makes a fixture
    test more than "bytes in, same bytes out".
  stream (optional, private globs only): the file is a serial-port-monitor text log
    ("[time] Written data (COMx)" / "Read data" blocks of hex lines); the test extracts the host
    ("Written") or radio ("Read") byte stream and round-trips that.

Generic fixtures are committed, generic stock-firmware or constructed bytes. Private fixtures
are the user's own dumps under $DM32_PRIVATE_DUMPS; those tests skip when it is unset, and a
failure reports only the path, size, pass/fail and the first differing offset: never bytes,
strings or exception text from a dump.

The committed fixtures this file owns (specs/ksy/fixtures/hdboot_*.bin, cps_*.bin) are built by
the functions below from the documented formats, not captured; FixturesMatchBuilders checks the
committed files still equal them. Rebuild with:
    python3 tests/test_ksy_roundtrip.py --write-fixtures

RUNTIME. The generated parsers need the `kaitaistruct` 0.11 Python runtime (tools/pyproject.toml
group `specs`). It is imported normally if installed, else loaded from tools/.venv; the parsing
tests skip when neither has it. The --check test needs no runtime and no compiler.
"""
from __future__ import annotations

import enum
import glob
import importlib
import importlib.util
import json
import os
import pathlib
import re
import struct
import sys
import unittest

from _support import REPO, STOCK_FULL, IRAM_IMAGE, describe, import_tool, run, tool

KSY_DIR = REPO / "specs" / "ksy"
GEN_DIR = REPO / "specs" / "generated" / "python"
FIXTURE_DIR = KSY_DIR / "fixtures"
CUT_IMAGE = REPO / "data" / "firmware" / "DM32.00.01.048.bin"
PRIVATE_ENV = "DM32_PRIVATE_DUMPS"


# --------------------------------------------------------------------------------------------
# runtime + generated modules
# --------------------------------------------------------------------------------------------

def _load_runtime():
    """Return the kaitaistruct module (>= 0.11), or None."""
    try:
        import kaitaistruct  # noqa: F401
        mod = sys.modules["kaitaistruct"]
    except ImportError:
        mod = None
        for cand in sorted((REPO / "tools" / ".venv").glob("lib/python*/site-packages/kaitaistruct.py")):
            spec = importlib.util.spec_from_file_location("kaitaistruct", cand)
            m = importlib.util.module_from_spec(spec)
            try:
                spec.loader.exec_module(m)
            except Exception:  # an incompatible file: keep looking
                continue
            sys.modules["kaitaistruct"] = m
            mod = m
            break
    if mod is None or getattr(mod, "API_VERSION", (0, 0)) < (0, 11):
        return None
    if not hasattr(mod, "ReadWriteKaitaiStruct"):
        return None
    return mod


KS = _load_runtime()
requires_runtime = unittest.skipUnless(
    KS is not None, "needs the kaitaistruct 0.11 runtime (`cd tools && uv sync --group specs`)")


def camel(name: str) -> str:
    return "".join(p[:1].upper() + p[1:] for p in name.split("_"))


def generated_module(ksy_id: str):
    if str(GEN_DIR) not in sys.path:
        sys.path.insert(0, str(GEN_DIR))
    return importlib.import_module(ksy_id)


def resolve_class(ksy_id: str, root_type: str | None):
    """Class for root_type within ksy_id (see the module docstring)."""
    if not root_type or root_type == ksy_id:
        return getattr(generated_module(ksy_id), camel(ksy_id))
    parts = root_type.split("::")
    base_id = ksy_id
    if (KSY_DIR / f"{parts[0]}.ksy").exists() and parts[0] != ksy_id:
        base_id, parts = parts[0], parts[1:]
    elif parts[0] == ksy_id:
        parts = parts[1:]
    cls = getattr(generated_module(base_id), camel(base_id))
    for p in parts:
        cls = getattr(cls, camel(p))
    return cls


def roundtrip(cls, data: bytes):
    """Parse, load every instance, _check(), _write(); return (parsed object, written bytes)."""
    obj = cls(KS.KaitaiStream(KS.BytesIO(data)))
    obj._read()
    obj._fetch_instances()
    obj._check()
    out = KS.KaitaiStream(KS.BytesIO(bytearray(len(data))))
    obj._write(out)
    return obj, bytes(out.to_byte_array())


def first_diff(a: bytes, b: bytes):
    if a == b:
        return None
    for i, (x, y) in enumerate(zip(a, b)):
        if x != y:
            return i
    return min(len(a), len(b))


_PATH_TOKEN = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)|\[(\d+)\]")


def get_path(obj, path: str):
    for part in path.split("."):
        for name, idx in _PATH_TOKEN.findall(part):
            obj = getattr(obj, name) if name else obj[int(idx)]
    return obj


def matches(actual, expected) -> bool:
    if isinstance(actual, enum.Enum):
        return actual.name == expected if isinstance(expected, str) else actual.value == expected
    if isinstance(expected, str) and expected.startswith("0x") and isinstance(actual, int):
        return actual == int(expected, 16)
    if isinstance(actual, (bytes, bytearray)) and isinstance(expected, str):
        return bytes(actual).hex() == expected.replace(" ", "").lower()
    return actual == expected


def sidecars():
    for p in sorted(KSY_DIR.glob("*.fixtures.json")):
        yield p.name[: -len(".fixtures.json")], p, json.loads(p.read_text(encoding="utf-8"))


def serial_log_streams(path: pathlib.Path) -> tuple[bytes, bytes]:
    """(host, radio) byte streams of a serial-port-monitor text log."""
    host, radio = bytearray(), bytearray()
    cur = None
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            if line.startswith("["):
                cur = host if "] Written data" in line else radio if "] Read data" in line else None
                continue
            m = re.match(r"^\s+((?:[0-9a-fA-F]{2} )+)", line)
            if m and cur is not None:
                cur.extend(bytes.fromhex(m.group(1)))
    return bytes(host), bytes(radio)


# --------------------------------------------------------------------------------------------
# fixture builders: the documented formats, written independently of the .ksy files
# --------------------------------------------------------------------------------------------

def _be32(v: int) -> bytes:
    return v.to_bytes(4, "big")


def _mini(cmd: int, body: bytes = b"") -> bytes:
    """Mini frame: STX, cmd, (sum of body) & 0xff, ETX, body (DH SOC Tools PtzLibMiniPacket)."""
    return bytes([0x02, cmd, sum(body) & 0xFF, 0x03]) + body


def _dh6000(cmd: int, args: bytes = b"", data: bytes | None = None) -> bytes:
    """DH6000 frame: 00, cmd, args[, data], u32 BE checksum (of data alone when present)."""
    if cmd == 0x14:
        return bytes([0x00, 0x14, 0x14])
    chk = sum(data) if data is not None else sum(args)
    return bytes([0x00, cmd]) + args + (data or b"") + _be32(chk)


def _le24(v: int) -> bytes:
    return v.to_bytes(3, "little")


def _cps_mem(code: int, addr: int, length: int, data: bytes = b"") -> bytes:
    return bytes([code]) + _le24(addr) + length.to_bytes(2, "little") + data


def _flash(img: bytes, addr: int, n: int) -> bytes:
    return img[addr - 0x03000000: addr - 0x03000000 + n]


def _cstr(img: bytes, addr: int) -> bytes:
    off = addr - 0x03000000
    return img[off: img.index(b"\0", off)]


def build_fixtures() -> dict[str, bytes]:
    """Every committed fixture this module owns, as {repo-relative path: bytes}."""
    img = STOCK_FULL.read_bytes()
    iram = IRAM_IMAGE.read_bytes()
    fx: dict[str, bytes] = {}

    # --- hdboot_serial: boot-ROM stage, Mini format (the DM-32's format) ---
    fx["specs/ksy/fixtures/hdboot_mini_rom_frames.bin"] = b"".join([
        _mini(0x14),                                                    # DEBUG (reply to NOTIFY)
        _mini(0x18, _be32(0x00010000) + _be32(4) + bytes(range(16))),   # DOWNLOAD 4 words
        _mini(0x1A, _be32(0x03000000) + _be32(2)),                      # READ 2 words
        _mini(0x19, _be32(0x18000800) + _be32(0x12345678)),             # WRITE one word
        _mini(0x45, _be32(0x000FF000) + _be32(1)),                      # ERASE (tool layout)
        _mini(0x1B, _be32(0x00010974)),                                 # RUN
        _mini(0x65),                                                    # EXIT
    ])
    # A flash-loader session: DEBUG, one 256-byte DOWNLOAD, RUN, then loader commands. The loader
    # bytes are a zero placeholder (the real loader is not reproduced here); the only write goes
    # to the last 256 bytes of program flash (erased on stock) with 0xFF.
    fx["specs/ksy/fixtures/hdboot_loader_session.bin"] = b"".join([
        _mini(0x14),
        _mini(0x18, _be32(0x00010000) + _be32(0x40) + bytes(256)),
        _mini(0x1B, _be32(0x00010974)),
        _mini(0x17, _be32(0x00000000)),                 # program flash read
        _mini(0x15, _be32(0x00001000)),                 # data chip read
        _mini(0x18, _be32(0x000FFF00) + b"\xff" * 256),  # program flash write
    ])
    fx["specs/ksy/fixtures/hdboot_rom_boot_announce.bin"] = (
        bytes([0x02, 0x24, 0x00, 0x03]) + struct.pack("<I", struct.unpack_from("<I", img, 4)[0]))
    fx["specs/ksy/fixtures/hdboot_mini_ok.bin"] = bytes([0x02, 0x05, 0x00, 0x03])
    fx["specs/ksy/fixtures/hdboot_dh6000_frames.bin"] = b"".join([
        _dh6000(0x14),
        _dh6000(0x1A, _be32(0x03000000) + _be32(4)),
        _dh6000(0x19, _be32(0x18000800) + _be32(0x12345678)),
        _dh6000(0x18, _be32(0x00010000) + _be32(8), bytes(range(8))),
        _dh6000(0x1B, _be32(0x00010000)),
    ])
    fx["specs/ksy/fixtures/hdboot_dh6000_status.bin"] = bytes([0x00, 0x03, 0x00, 0x01])

    # --- cps_serial: one OEM-order session, both directions ---
    vf = lambda i, c=0: bytes([0x56, 0x00, 0x00, c, i])  # noqa: E731
    fx["specs/ksy/fixtures/cps_host_session.bin"] = b"".join([
        b"PSEARCH", b"PASSSTA", b"SYSINFO",
        vf(0x0D, 0x40), *(vf(i) for i in range(0x01, 0x0C)), vf(0x0D), vf(0x0E), vf(0x0F), vf(0x10),
        bytes([0x47, 0, 0, 0, 0x00, 0x01]),
        b"\xff\xff\xff\xff\x0c", b"PROGRAM", b"\x02", b"\x06",
        _cps_mem(0x52, 0x278000, 4),        # contact count
        _cps_mem(0x52, 0x001FFF, 1),        # logical-block-id probe
        _cps_mem(0x52, 0x001000, 0x1000),   # 4 KB read
        _cps_mem(0x52, 0xFFF001, 0x1000),   # sentinel read
        _cps_mem(0x57, 0xFFF001, 0x1000, bytes(0xFFF) + b"\x63"),  # sentinel write, id 0x63
    ])
    # Radio replies. Every V-frame value is taken from the stock image (literal pool of the info
    # loop); V-frame 0x02, the 0x47 data and all block data are placeholders, not radio data.
    ranges = {0x06: 0x030ADB30, 0x07: 0x030ADB18, 0x08: 0x030ADB28, 0x09: 0x030ADB48,
              0x0A: 0x030ADB0C, 0x0E: 0x030ADB20, 0x0F: 0x030ADB40}
    strings = {0x01: 0x030ADAA0, 0x03: 0x030ADAB0, 0x04: 0x030ADABC, 0x05: 0x030ADAEC,
               0x0B: 0x030ADADC}

    def vreply(i: int, payload: bytes) -> bytes:
        return bytes([0x56, i, len(payload)]) + payload

    replies = [vreply(0x0D, _flash(img, 0x030ADB50, 0x40))]
    for i in range(0x01, 0x0C):
        if i in strings:
            replies.append(vreply(i, _cstr(img, strings[i])))
        elif i in ranges:
            replies.append(vreply(i, _flash(img, ranges[i], 8)))
        else:  # 0x02
            replies.append(vreply(i, bytes(12)))
    replies += [vreply(0x0D, b""), vreply(0x0E, _flash(img, ranges[0x0E], 8)),
                vreply(0x0F, _flash(img, ranges[0x0F], 8)), vreply(0x10, b"\x50\xc3\x00")]
    fx["specs/ksy/fixtures/cps_radio_session.bin"] = b"".join([
        b"\x06" + _cstr(img, 0x030AF914),   # PSEARCH reply, model string from flash
        b"\x50\x00\x00",                    # PASSSTA (placeholder codeplug bytes)
        b"\x06",                            # SYSINFO
        *replies,
        bytes([0x53, 0, 0, 0, 0x00, 0x01]) + b"\xff" * 256,
        b"\x06", b"\xff" * 8, b"\x06",
        _cps_mem(0x57, 0x278000, 4, bytes(4)),
        _cps_mem(0x57, 0x001FFF, 1, b"\xff"),
        _cps_mem(0x57, 0x001000, 0x1000, b"\xff" * 0x1000),
        _cps_mem(0x57, 0xFFF001, 0x1000, bytes(0xFFF) + b"\x48"),  # the sentinel's fixed reply
        b"\x06",
    ])
    # This project's debug sub-ids (patched firmware only), info loop alone.
    fx["specs/ksy/fixtures/cps_debug_host.bin"] = vf(0x3F) + vf(0x40) + vf(0x3E)
    fx["specs/ksy/fixtures/cps_debug_radio.bin"] = b"".join([
        vreply(0x3F, _be32(0x00010000)),
        vreply(0x40, iram[:0x40]),          # IRAM 0x00010000 of the derived (stock) image
        vreply(0x3E, b"\xff" * 0x40),       # placeholder data-chip bytes
    ])
    return fx


# --------------------------------------------------------------------------------------------
# tests
# --------------------------------------------------------------------------------------------

class GeneratedCodeCurrent(unittest.TestCase):
    """gen_ksy.py --check passes: every .ksy follows specs/README.md and generated/ is current.
    Without the compiler (stdlib CI) it still lints and verifies each file's source hash."""

    def test_gen_ksy_check(self):
        p = run([sys.executable, tool("gen_ksy"), "--check", "--no-fetch"], timeout=900)
        self.assertEqual(p.returncode, 0, describe(p))


class GenKsyLint(unittest.TestCase):
    """The lint itself: missing doc / confidence and bad confidence values are caught."""

    def setUp(self):
        import tempfile
        self.gen = import_tool("gen_ksy")
        self.tmp = pathlib.Path(tempfile.mkdtemp(prefix="dm32test-ksylint-"))

    def tearDown(self):
        import shutil
        shutil.rmtree(self.tmp, ignore_errors=True)

    def lint(self, text: str, name: str = "t"):
        p = self.tmp / f"{name}.ksy"
        p.write_text(text)
        return self.gen.lint_ksy(p)

    GOOD = """meta:
  id: t
  -dm32-confidence: STRUCTURAL
doc-ref: x
seq:
  - id: a
    type: u1
    doc: A byte.
instances:
  b:
    value: a + 1
    doc: |
      Derived.
types:
  inner:
    -dm32-confidence: INFERRED
    seq:
      - id: c
        type: u1
        doc: C.
"""

    def test_good_file_is_clean(self):
        self.assertEqual(self.lint(self.GOOD), ([], []))

    def test_missing_doc_in_nested_type(self):
        errs, _ = self.lint(self.GOOD.replace("        doc: C.\n", ""))
        self.assertTrue(any("/types/inner/seq/c: missing doc" in e for e in errs), errs)

    def test_missing_instance_doc(self):
        errs, _ = self.lint(self.GOOD.replace("    doc: |\n      Derived.\n", ""))
        self.assertTrue(any("instances/b: missing doc" in e for e in errs), errs)

    def test_confidence_required_somewhere(self):
        errs, _ = self.lint(self.GOOD.replace("  -dm32-confidence: STRUCTURAL\n", ""))
        self.assertTrue(any("seq/a: no -dm32-confidence" in e for e in errs), errs)
        self.assertFalse(any("inner" in e for e in errs), "type-level confidence should cover c")

    def test_invalid_confidence_value(self):
        errs, _ = self.lint(self.GOOD.replace("INFERRED", "GUESSED"))
        self.assertTrue(any("GUESSED" in e for e in errs), errs)

    def test_id_must_match_file_name(self):
        errs, _ = self.lint(self.GOOD, name="other")
        self.assertTrue(any("meta.id" in e for e in errs), errs)

    def test_unsupported_yaml_is_an_error_not_a_misparse(self):
        errs, _ = self.lint(self.GOOD.replace("doc-ref: x", "doc-ref: &anchor x"))
        self.assertTrue(errs and "cannot read" in errs[0], errs)

    def test_check_without_compiler_uses_source_hashes(self):
        """The stdlib-CI path: no compiler, so --check verifies each generated file's recorded
        .ksy hash. A copy of the real tree passes; editing one .ksy makes it fail as stale."""
        import contextlib
        import io
        import shutil
        ksy, gen = self.tmp / "ksy", self.tmp / "gen"
        shutil.copytree(KSY_DIR, ksy)
        shutil.copytree(GEN_DIR, gen)
        saved = (self.gen.KSY_DIR, self.gen.OUT_DIR, self.gen.LOCAL_KSC, os.environ.get("KSC"),
                 os.environ.get("PATH"))
        try:
            self.gen.KSY_DIR, self.gen.OUT_DIR = ksy, gen
            self.gen.LOCAL_KSC = self.tmp / "no-ksc"
            os.environ["KSC"] = str(self.tmp / "no-ksc")
            os.environ["PATH"] = str(self.tmp)

            def check():
                buf = io.StringIO()
                with contextlib.redirect_stdout(buf):
                    rc = self.gen.run("check", fetch=False)
                return rc, buf.getvalue()

            rc, out = check()
            self.assertEqual(rc, 0, out)
            self.assertIn("source hashes only", out)
            victim = sorted(ksy.glob("*.ksy"))[0]
            victim.write_text(victim.read_text() + "# edited\n")
            rc, out = check()
            self.assertEqual(rc, 1, out)
            self.assertIn(f"{victim.stem}.py is stale", out)
        finally:
            self.gen.KSY_DIR, self.gen.OUT_DIR, self.gen.LOCAL_KSC = saved[:3]
            for k, v in (("KSC", saved[3]), ("PATH", saved[4])):
                if v is None:
                    os.environ.pop(k, None)
                else:
                    os.environ[k] = v

    def test_parser_matches_compiler_view_of_real_files(self):
        """The subset parser reads every committed .ksy without error and finds meta.id."""
        for ksy in sorted(KSY_DIR.glob("*.ksy")):
            with self.subTest(ksy=ksy.name):
                doc = self.gen.load_ksy(ksy)
                self.assertEqual(doc["meta"]["id"], ksy.stem)


@requires_runtime
class GenericFixtures(unittest.TestCase):
    """Every committed fixture in every sidecar parses, round-trips byte for byte, and meets its
    `expect` values."""

    def test_generic_fixtures_roundtrip(self):
        count = 0
        for ksy_id, sidecar, spec in sidecars():
            if not (GEN_DIR / f"{ksy_id}.py").exists():
                continue  # reported by GeneratedCodeCurrent
            for i, fx in enumerate(spec.get("generic", [])):
                with self.subTest(ksy=ksy_id, fixture=i, path=fx["path"], note=fx.get("note", "")):
                    path = REPO / fx["path"]
                    self.assertTrue(path.is_file(), f"{fx['path']} missing")
                    raw = path.read_bytes()
                    off, n = fx.get("offset", 0), fx.get("length", len(raw) - fx.get("offset", 0))
                    self.assertLessEqual(off + n, len(raw), "fixture range outside the file")
                    data = raw[off:off + n]
                    cls = resolve_class(ksy_id, fx.get("root_type") or spec.get("root_type"))
                    obj, out = roundtrip(cls, data)
                    d = first_diff(data, out)
                    self.assertIsNone(d, f"{fx['path']}[{off:#x}+{n:#x}]: write differs at {d}")
                    for fpath, want in fx.get("expect", {}).items():
                        got = get_path(obj, fpath)
                        self.assertTrue(matches(got, want), f"{fpath}: got {got!r}, want {want!r}")
                    count += 1
        if count == 0:
            self.skipTest("no generic fixtures")


@requires_runtime
class PrivateFixtures(unittest.TestCase):
    """The user's own dumps ($DM32_PRIVATE_DUMPS) round-trip. Reports path/size/offset only."""

    def test_private_dumps_roundtrip(self):
        root = os.environ.get(PRIVATE_ENV)
        if not root:
            self.skipTest(f"{PRIVATE_ENV} not set")
        root_p = pathlib.Path(root)
        count = 0
        for ksy_id, sidecar, spec in sidecars():
            if not (GEN_DIR / f"{ksy_id}.py").exists():
                continue
            for entry in spec.get("private_globs", []):
                if isinstance(entry, str):
                    entry = {"glob": entry}
                for f in sorted(glob.glob(str(root_p / entry["glob"]), recursive=True)):
                    f = pathlib.Path(f)
                    if not f.is_file():
                        continue
                    rel = f.relative_to(root_p)
                    with self.subTest(ksy=ksy_id, dump=str(rel)):
                        count += 1
                        verdict = self._one(ksy_id, spec, entry, f)
                        print(f"  private {ksy_id}: {rel} {verdict}", file=sys.stderr)
                        self.assertTrue(verdict.startswith("ok"), f"{rel}: {verdict}")
        if count == 0:
            self.skipTest(f"no file under {PRIVATE_ENV} matches any sidecar's private_globs")

    @staticmethod
    def _one(ksy_id, spec, entry, path: pathlib.Path) -> str:
        """Verdict string with no dump content in it."""
        try:
            data = path.read_bytes()
            if entry.get("stream") in ("host", "radio"):
                host, radio = serial_log_streams(path)
                data = host if entry["stream"] == "host" else radio
            cls = resolve_class(ksy_id, entry.get("root_type") or spec.get("root_type"))
        except Exception as e:  # noqa: BLE001
            return f"FAIL setup ({type(e).__name__})"
        size = len(data)
        stage = "parse"
        try:
            obj = cls(KS.KaitaiStream(KS.BytesIO(data)))
            obj._read()
            obj._fetch_instances()
            stage = "check"
            obj._check()
            stage = "write"
            out = KS.KaitaiStream(KS.BytesIO(bytearray(size)))
            obj._write(out)
            out = bytes(out.to_byte_array())
        except Exception as e:  # noqa: BLE001 - the message may quote dump bytes; drop it
            pos = None
            try:
                pos = obj._io.pos()
            except Exception:  # noqa: BLE001
                pass
            return f"FAIL {stage} ({type(e).__name__}, size {size}, stream pos {pos})"
        d = first_diff(data, out)
        return f"ok ({size} bytes)" if d is None else f"FAIL write differs (size {size}, first at {d:#x})"


@requires_runtime
class WriterIsNotVacuous(unittest.TestCase):
    """A round-trip proves little if the writer ignored the parsed fields. Change one field and
    check exactly those bytes change; corrupt a magic and check the parser refuses it."""

    def test_changed_field_lands_in_output(self):
        data = STOCK_FULL.read_bytes()
        cls = resolve_class("dm32_firmware_image", None)
        obj = cls(KS.KaitaiStream(KS.BytesIO(data)))
        obj._read()
        obj._fetch_instances()
        obj.header.entry = 0x0300C000
        obj.header._check()
        obj._check()
        out = KS.KaitaiStream(KS.BytesIO(bytearray(len(data))))
        obj._write(out)
        out = bytes(out.to_byte_array())
        changed = [i for i, (a, b) in enumerate(zip(data, out)) if a != b]
        self.assertEqual(changed, [5])  # 00 10 00 03 -> 00 c0 00 03
        self.assertEqual(struct.unpack_from("<I", out, 4)[0], 0x0300C000)

    def test_bad_dh_flag_is_rejected(self):
        data = bytearray(CUT_IMAGE.read_bytes())
        data[3] ^= 0xFF
        cls = resolve_class("dm32_firmware_image", None)
        obj = cls(KS.KaitaiStream(KS.BytesIO(bytes(data))))
        with self.assertRaises(KS.ValidationNotEqualError):
            obj._read()

    def test_unknown_rom_command_is_rejected(self):
        cls = resolve_class("hdboot_serial", None)
        obj = cls(KS.KaitaiStream(KS.BytesIO(_mini(0x17, _be32(0)))))  # a loader cmd, not a ROM cmd
        with self.assertRaises(KS.ValidationNotAnyOfError):
            obj._read()


class FixturesMatchBuilders(unittest.TestCase):
    """The committed hdboot/cps fixtures equal what build_fixtures() derives from the documented
    formats (and from the stock image for firmware constants)."""

    def test_committed_fixtures_are_current(self):
        for rel, want in build_fixtures().items():
            with self.subTest(fixture=rel):
                p = REPO / rel
                self.assertTrue(p.is_file(), f"{rel} missing (run with --write-fixtures)")
                got = p.read_bytes()
                self.assertIsNone(first_diff(got, want),
                                  f"{rel} differs from its builder at {first_diff(got, want)}")

    def test_sidecars_reference_every_owned_fixture(self):
        referenced = set()
        for _, _, spec in sidecars():
            referenced |= {fx["path"] for fx in spec.get("generic", [])}
        for rel in build_fixtures():
            self.assertIn(rel, referenced, f"{rel} is built but no sidecar tests it")


def _write_fixtures() -> int:
    for rel, data in build_fixtures().items():
        p = REPO / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        if not p.exists() or p.read_bytes() != data:
            p.write_bytes(data)
            print(f"wrote {rel} ({len(data)} bytes)")
    return 0


if __name__ == "__main__":
    if "--write-fixtures" in sys.argv:
        sys.exit(_write_fixtures())
    unittest.main()
