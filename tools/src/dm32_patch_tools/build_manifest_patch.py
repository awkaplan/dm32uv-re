#!/usr/bin/env python3
"""Manifest-driven, multi-site patch builder for the DM-32UV program flash.

This generalizes tools/examples/snake/build_snake_patch.py, the first patch here to need many
sites at once (six blobs, eight data tables, eleven splices across six sectors). The steps are
the same: compile, link at a fixed or linker-chosen address, check that the entry landed where
the tables say it does, check every stock byte before writing, refuse overlapping placements,
then emit the full image plus per-sector files. What changes is that a JSON manifest describes
the patch, not a Python script. Every check lives here once, so a new patch gets all of them
without copying them.

build_patch.py stays the right tool for one handler plus one hook in one sector. Use this
builder when a patch spans sectors, relocates tables or links several blobs.

WHAT THIS DOES NOT DO: flash anything. Its outputs are files under --out. Flashing is a
separate, manual, human-run step on a radio with a verified full backup (CLAUDE.md "Safety").
The base image is opened read-only. The builder refuses to write any output over an input.

MANIFEST (JSON; paths are relative to the manifest's own directory; every address is absolute)
  {
    "name": "snake",                         # C-identifier-ish; used for the default --out dir
    "description": "...",
    "base_image": "<path>",                  # optional; default: the full 1 MB stock image
    "base_sha256": "<hex>",                  # optional pin; a <base>.sha256 sidecar is always checked
    "output_image": "progmem_SNAKE_patched.bin",   # optional; default progmem_<NAME>_patched.bin
    "allocations": ["snake_code", "snake_state"],  # claims this patch OWNS: named in
                                             # data/allocations.json or an --extra-allocations file
    "symbols": {"STOCK_CASE_TAIL": "0x0303d872"},  # named constants, usable as "@STOCK_CASE_TAIL"
    "allow_occupied": [ {"start": "0x...", "end_exclusive": "0x...", "justification": "..."} ],
    "blobs":   [ ... ],    # code, built with csky-abiv2-elf-gcc -mcpu=ck803s and linked
    "data":    [ ... ],    # tables/strings assembled here and placed in erased flash
    "splices": [ ... ],    # in-place edits of existing (stock) bytes, each with expected bytes
    "asserts": [ ... ],    # read-only checks of stock bytes the patch relies on but does not edit
    "verify": { "keyseq": "...", ... },  # optional; copied verbatim into summary.json for
                                          # verify_manifest.py; the build itself ignores it
  }

  blob:   {"name", "sources": [..c/.S..], "cflags": [...], "ldflags": [...],
           "linker_script": "x.ld"  OR  "link_address": "0x...",   (exactly one)
           "entry": "symbol", "expect_entry": "0x..." (optional, verified after linking),
           "sections": [".text", ".rodata"] (optional; default every allocated PROGBITS section),
           "defsym": {"SYM": "@ref" | "0x..."}, "libgcc": true}
          Linking uses `-L <build dir> -L tools/link -L <manifest dir>`, so a linker script can
          `INCLUDE dm32_stock_symbols.ld` and either `INCLUDE dm32_patch_memory.ld` (free space;
          for an unclaimed, in-development patch) or `INCLUDE dm32_patch_own_memory.ld`, which
          this builder generates per build from the manifest's own "allocations" claims (regions
          PATCH_OWN_FLASH / PATCH_OWN_SRAM). The two cannot be combined, because
          dm32_patch_memory.ld reserves every claim, including this patch's own.
  data:   {"name", "addr", "parts": [ part, ... ]}, part is one of:
           {"string": "SNAKE", "encoding": "ascii", "nul": true}   {"bytes": "hex"}
           {"u32": [value|@ref, ...]}   {"u8": [...]}   {"u16": [...]}
           {"struct": "<IBBH", "values": [...]}                   {"align": 4, "fill": 0}
           {"stock_u32": "0x...", "count": N, "expect": [...]}  (copy words from the base image;
                                                                 "expect" is checked if given)
  splice: {"name", "addr", ONE expectation: "expect": "hex" | "expect_u32": v | "expect_u8": v |
                                            "expect_branch": {"kind": "br"|"bsr", "target": ref}
           ONE replacement: "bytes": "hex" | "u32": v | "u8": v |
                            "branch": {"kind": "br"|"bsr", "target": ref} |
                            "branch": {"kind": "lrw_jmp", "target": ref, "reg": "r3"},
           "fill": "hex" (only to pad a shorter replacement, e.g. an lrw_jmp, to the expected length)}
  assert: {"name", "addr", ONE expectation as above}

  verify (optional): {"keyseq": "<scenario name from data/keyseq_scenarios.json or raw DM32_KEYSEQ>",
                      "until_step": N (optional), "settle_after": S (optional), "timeout": S (optional),
                      "expect_frames": [ <int nonblack> | {"min":..,"max":..} | {"name":"<fingerprint name>"} ]}
  # consumed by verify_manifest.py; the build itself ignores it except for copying it into summary.json

  References: "@NAME" is a manifest symbol, a data item's address, or a blob's entry address.
  "@blob:sym" is any symbol in an already-built blob's ELF. "@stock:name" is a name from
  tools/link/dm32_stock_symbols.ld. An optional "+0x10" / "-4" suffix adds an offset. A value
  containing "TODO" is a deliberate placeholder, and the builder refuses it.

SAFETY CHECKS (every one is a hard error unless noted)
  * Base image: exactly 1 MB, matches its .sha256 sidecar and any base_sha256 pin.
  * Every write lies in 0x03000000-0x030FFFFF.
  * Nothing ever touches the per-unit sector 0x0300B000-0x0300BFFF or any `forbidden` range in
    data/allocations.json. No allowance overrides this.
  * Nothing touches data/firmware/patching/occupied_regions.json ranges. The one exception is a
    splice (which carries expected bytes) inside an allow_occupied entry with a non-empty
    justification. Blobs and data may never land in an occupied range.
  * Blobs and data lie inside the allocations.json flash window and land on all-0xFF bytes.
  * Writes and RAM sections (.bss) that overlap ANOTHER patch's allocations.json claim are
    refused. Writes in the window that fall outside this patch's own claims produce a warning,
    or an error with --require-claims.
  * Every expected byte is checked against the base image just before the write, every
    placement is checked against every other, every branch written is decoded back and checked
    against its target, and every byte that differs from the base must belong to a declared
    write.
  * Linked blobs: the entry symbol lands at expect_entry, no initialised RAM data (.data), no
    allocated section left out of the extracted image, LMA == VMA.

OUTPUTS (in --out, default out/patches/<name>/, which .gitignore covers)
  <output_image>                 full patched 1 MB image
  sector_<addr>_stock.bin        base bytes of every changed 4 KiB sector
  sector_<addr>_patched.bin      patched bytes of every changed 4 KiB sector
  summary.json                   writes, sectors (with sha256), blobs, warnings
  build/                         .o / .elf / .map / extracted .bin per blob, generated own-memory .ld

EXTRA ALLOCATION FILES (--extra-allocations FILE, repeatable)
  A patch that lives outside this repository keeps its own claims
  in its own file, same schema as data/allocations.json: {"allocations": [{"name", "space":
  "flash"|"sram", "start", "end_exclusive", "owner", "source"}, ...]} and an optional "forbidden"
  list ({"name", "start", "end_exclusive"}); "windows" in an extra file is ignored (the windows
  always come from data/allocations.json). Every file is merged with data/allocations.json BEFORE
  claim resolution and overlap checks, so a manifest's "allocations" may name a claim from any
  loaded file, and other patches' claims in ANY file are protected exactly like the repo's own.
  A duplicate claim name, two overlapping claims in the same space, a claim outside its window
  (or a flash claim not on whole 4 KiB sectors), or an extra claim overlapping a forbidden range
  is a hard error naming both files. NOTE: dm32_patch_memory.ld (tools/link, generated from
  data/allocations.json only) does not know extra claims; out-of-tree linker scripts should
  INCLUDE dm32_patch_own_memory.ld, which this builder generates from the owned claims.

USAGE (inside the toolchain image, or anywhere csky-abiv2-elf-* is on PATH):
  python3 tools/src/dm32_patch_tools/build_manifest_patch.py tools/examples/snake/snake.patch.json \\
      --out /tmp/snake_out --compare tools/examples/snake/progmem_SNAKE_patched.bin

  # a patch outside this repo, with its own claims file:
  python3 tools/src/dm32_patch_tools/build_manifest_patch.py ../my-patches/x/x.patch.json \\
      --extra-allocations ../my-patches/allocations.json --require-claims --out /tmp/x_out
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
import re
import shlex
import shutil
import struct
import subprocess
import sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
# The single, hardware-verified CK803S branch encoder (see its docstring): never re-derive it.
from build_patch import encode_branch, decode_branch, corpus_crosscheck  # noqa: E402

REPO_ROOT = HERE.parents[2]
FLASH_BASE = 0x03000000
FLASH_END = 0x03100000            # end of the 1 MB GD25Q80
SECTOR = 0x1000
PER_UNIT_LO, PER_UNIT_HI = 0x0300B000, 0x0300C000
IRAM_LO, IRAM_HI = 0x00010000, 0x00058000
SRAM_LO, SRAM_HI = 0x18000000, 0x18008000

DEFAULT_BASE = REPO_ROOT / "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"
ALLOCATIONS_JSON = REPO_ROOT / "data/allocations.json"
OCCUPIED_JSON = REPO_ROOT / "data/firmware/patching/occupied_regions.json"
LINK_DIR = REPO_ROOT / "tools/link"
STOCK_SYMBOLS_LD = LINK_DIR / "dm32_stock_symbols.ld"
API_INCLUDE_DIR = REPO_ROOT / "tools/include"
OWN_MEMORY_LD = "dm32_patch_own_memory.ld"

TOOL_PREFIX = "csky-abiv2-elf-"
DEFAULT_CFLAGS = ["-O2", "-Wall", "-ffunction-sections", "-fdata-sections"]
RESERVED_PREFIX = ".dm32_reserved"


class BuildError(Exception):
    """A precondition failed. Nothing is written to --out until every check has passed."""


# ----------------------------------------------------------------------------------------------
# small helpers
# ----------------------------------------------------------------------------------------------

def sha256(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def overlaps(a_lo: int, a_hi: int, b_lo: int, b_hi: int) -> bool:
    return a_lo < b_hi and b_lo < a_hi



def _range_overlap_msg(a: dict, b: dict) -> str:
    return (f"'{a['name']}' [{a['lo']:#x},{a['hi']:#x}) ({a['file']}) overlaps "
            f"'{b['name']}' [{b['lo']:#x},{b['hi']:#x}) ({b['file']})")


def load_allocations(extra_paths=(), base_path: pathlib.Path | None = None) -> dict:
    """Load data/allocations.json merged with any --extra-allocations files.

    Returns {"windows": {name: (lo, hi)}, "forbidden": [(lo, hi, name)], "claims": [dict(name,
    space, lo, hi, owner, file)]}. Raises BuildError on a duplicate claim name, overlapping claims
    in the same space (across or within files), a claim outside its window, a flash claim not on
    whole sectors, or an extra file's claim/forbidden entry that overlaps a forbidden range.
    """
    base_path = pathlib.Path(base_path or ALLOCATIONS_JSON)
    alloc = json.loads(base_path.read_text())
    windows = {w["name"]: (int(w["start"], 16), int(w["end_exclusive"], 16))
               for w in alloc["windows"]}
    forbidden = [(int(f["start"], 16), int(f["end_exclusive"], 16), f["name"])
                 for f in alloc.get("forbidden", [])]
    claims: list[dict] = []

    def add_claims(doc: dict, label: str):
        for a in doc.get("allocations", []):
            try:
                c = dict(name=a["name"], space=a["space"], lo=int(a["start"], 16),
                         hi=int(a["end_exclusive"], 16), owner=a.get("owner", ""), file=label)
            except (KeyError, ValueError, TypeError) as e:
                raise BuildError(f"{label}: malformed allocation entry {a!r}: {e!r}")
            if c["space"] not in ("flash", "sram", "iram"):
                raise BuildError(f"{label}: claim '{c['name']}' has space {c['space']!r} "
                                 f"(must be 'flash', 'sram' or 'iram')")
            if c["hi"] <= c["lo"]:
                raise BuildError(f"{label}: claim '{c['name']}' is empty or negative")
            if c["space"] not in windows:
                raise BuildError(f"{label}: claim '{c['name']}' is in the {c['space']} space but "
                                 f"allocations.json has no '{c['space']}' window")
            wlo, whi = windows[c["space"]]
            if not (wlo <= c["lo"] and c["hi"] <= whi):
                raise BuildError(f"{label}: claim '{c['name']}' [{c['lo']:#x},{c['hi']:#x}) is "
                                 f"outside the {c['space']} window [{wlo:#x},{whi:#x})")
            if c["space"] == "flash" and (c["lo"] % SECTOR or c["hi"] % SECTOR):
                raise BuildError(f"{label}: flash claim '{c['name']}' must be whole 4 KiB sectors")
            for o in claims:
                if o["name"] == c["name"]:
                    raise BuildError(f"duplicate allocation name '{c['name']}' in {o['file']} "
                                     f"and {label}")
                if o["space"] == c["space"] and overlaps(c["lo"], c["hi"], o["lo"], o["hi"]):
                    raise BuildError("allocation overlap: " + _range_overlap_msg(c, o))
            for flo, fhi, fname in forbidden:
                if c["space"] == "flash" and overlaps(c["lo"], c["hi"], flo, fhi):
                    raise BuildError(f"{label}: claim '{c['name']}' [{c['lo']:#x},{c['hi']:#x}) "
                                     f"overlaps forbidden range '{fname}' [{flo:#x},{fhi:#x})")
            claims.append(c)

    add_claims(alloc, str(base_path.name if base_path == ALLOCATIONS_JSON else base_path))
    for ep in extra_paths:
        ep = pathlib.Path(ep)
        try:
            doc = json.loads(ep.read_text())
        except (OSError, ValueError) as e:
            raise BuildError(f"cannot load --extra-allocations {ep}: {e}")
        if not isinstance(doc, dict) or "allocations" not in doc:
            raise BuildError(f"{ep}: not an allocations file (needs an \"allocations\" list)")
        for f in doc.get("forbidden", []):
            forbidden.append((int(f["start"], 16), int(f["end_exclusive"], 16), f["name"]))
        add_claims(doc, str(ep))
    return dict(windows=windows, forbidden=forbidden, claims=claims)


def reject_todo(value, where: str) -> None:
    if isinstance(value, str) and "TODO" in value:
        raise BuildError(f"{where}: placeholder {value!r} is still a TODO. Fill it in (see the "
                         f"patch's README) before building.")


def parse_hex(s: str, where: str) -> bytes:
    reject_todo(s, where)
    try:
        return bytes.fromhex(s.replace(" ", "").replace("_", ""))
    except ValueError as e:
        raise BuildError(f"{where}: bad hex {s!r}: {e}") from None


def check_keys(obj: dict, allowed: set[str], where: str) -> None:
    extra = set(obj) - allowed - {"note", "_comment", "why"}
    if extra:
        raise BuildError(f"{where}: unknown key(s) {sorted(extra)}; allowed: {sorted(allowed)}")


def h(x: int) -> str:
    return f"{x:#010x}"


# Pattern-12 guard: `bsr <absolute addr>` / `bsr <.equ absolute symbol>` assembles to NOTHING
# (docs/patch-patterns.md pattern 12), silently shrinking the blob and shifting every later
# offset with no error. The builder compares the bsr count in each blob's .S sources with the
# linked ELF's objdump -d output and fails hard if any bsr vanished. The two counters are
# module-level so they are unit-testable without a toolchain.

_BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.S)


def count_source_bsr(sources) -> int:
    """Count `bsr` instruction mnemonics across C-SKY assembly source text(s).

    Matches ^\\s*bsr\\b on non-comment lines: `/* ... */` blocks are removed first, then lines
    whose first non-space character is `;`, `#` or `//` are skipped (GAS line comments). A
    `bsr` to an absolute address or an `.equ` absolute symbol still counts here - the point is
    to catch the case where the assembler then fails to emit it in the ELF.
    """
    n = 0
    for text in sources:
        text = _BLOCK_COMMENT_RE.sub("", text)
        for line in text.splitlines():
            stripped = line.strip()
            if not stripped or stripped[0] in (";", "#") or stripped.startswith("//"):
                continue
            if re.match(r"^\s*bsr\b", line):
                n += 1
    return n


_OBJDUMP_LINE = re.compile(
    r"^\s*[0-9a-f]+:\s+"
    r"(?:(?:[0-9a-f]{2}\s+)*[0-9a-f]{2}|[0-9a-f]{4}(?:[0-9a-f]{4})?)"   # bytes, spaced or packed
    r"\s+(\S+)\s*(.*)$")


def count_elf_bsr(elf_text: str) -> int:
    """Count `bsr` instructions in `csky-abiv2-elf-objdump -d` output of a linked ELF.

    objdump prints one instruction per line as `<addr>: <hexbytes> <mnemonic> <operands>`; the
    mnemonic is the first non-hex token after the bytes (see cs_disasm.py's
    ObjdumpDisassembler.LINE for the same shape)."""
    return sum(1 for line in elf_text.splitlines()
               if (m := _OBJDUMP_LINE.match(line)) and m.group(1) == "bsr")


# ----------------------------------------------------------------------------------------------
# minimal ELF32 little-endian reader (sections, program headers, symbols)
# ----------------------------------------------------------------------------------------------

SHT_PROGBITS, SHT_SYMTAB, SHT_NOBITS = 1, 2, 8
SHF_ALLOC = 0x2
PT_LOAD = 1


class Elf:
    def __init__(self, path: pathlib.Path):
        d = path.read_bytes()
        if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
            raise BuildError(f"{path}: not an ELF32 little-endian file")
        self.data = d
        (_, _, _, self.e_entry, phoff, shoff, _, _, phentsize, phnum, shentsize, shnum,
         shstrndx) = struct.unpack_from("<HHIIIIIHHHHHH", d, 16)
        raw = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
        strtab_off = raw[shstrndx][4]

        def cstr(off):
            return d[off:d.index(b"\0", off)].decode()

        self.sections = []
        for (name, typ, flags, addr, off, size, link, info, align, entsize) in raw:
            self.sections.append(dict(name=cstr(strtab_off + name), type=typ, flags=flags,
                                      addr=addr, offset=off, size=size, link=link))
        self.phdrs = [struct.unpack_from("<IIIIIIII", d, phoff + i * phentsize)
                      for i in range(phnum)]
        self.symbols: dict[str, int] = {}
        for s in self.sections:
            if s["type"] != SHT_SYMTAB:
                continue
            stroff = self.sections[s["link"]]["offset"]
            for i in range(s["size"] // 16):
                st_name, st_value, _sz, _info, _other, shndx = struct.unpack_from(
                    "<IIIBBH", d, s["offset"] + i * 16)
                if shndx == 0 or st_name == 0:
                    continue
                self.symbols.setdefault(cstr(stroff + st_name), st_value)

    def section_bytes(self, s: dict) -> bytes:
        return self.data[s["offset"]:s["offset"] + s["size"]]


# ----------------------------------------------------------------------------------------------
# toolchain
# ----------------------------------------------------------------------------------------------

class Toolchain:
    """Runs csky-abiv2-elf-* tools directly when they are on PATH, otherwise through a wrapper
    (CSKYBUILD / --cskybuild) that takes the tool name as its first argument, the same contract
    as docker/cskybuild.sh and build_snake_patch.py's CSKYBUILD."""

    def __init__(self, wrapper: str | None, cpu: str):
        self.wrapper = wrapper
        self.cpu = cpu
        if wrapper is None and shutil.which(TOOL_PREFIX + "gcc") is None:
            raise BuildError(
                f"{TOOL_PREFIX}gcc not on PATH and no --cskybuild/CSKYBUILD wrapper given. Run "
                f"inside the toolchain image, e.g.\n  docker run --rm -v <repo>:/repo -w /repo "
                f"dm32uv-re-pipeline:qemufix3 -c 'python3 tools/src/dm32_patch_tools/"
                f"build_manifest_patch.py <manifest> --out /tmp/x'")
        self.log: list[str] = []

    def run(self, tool: str, args: list[str], cwd: pathlib.Path) -> str:
        cmd = ([self.wrapper] if self.wrapper else []) + [TOOL_PREFIX + tool] + args
        self.log.append(" ".join(shlex.quote(c) for c in cmd))
        r = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
        if r.returncode:
            raise BuildError(f"command failed: {self.log[-1]}\n--- stdout ---\n{r.stdout}"
                             f"\n--- stderr ---\n{r.stderr}")
        return r.stdout

    def libgcc(self, cwd: pathlib.Path) -> str:
        return self.run("gcc", [f"-mcpu={self.cpu}", "-print-libgcc-file-name"], cwd).strip()

    def version(self, cwd: pathlib.Path) -> str:
        return self.run("gcc", ["--version"], cwd).splitlines()[0]


# ----------------------------------------------------------------------------------------------
# the builder
# ----------------------------------------------------------------------------------------------

class Write:
    __slots__ = ("addr", "data", "label", "kind", "item")

    def __init__(self, addr, data, label, kind, item=None):
        self.addr, self.data, self.label, self.kind, self.item = addr, bytes(data), label, kind, item

    @property
    def end(self):
        return self.addr + len(self.data)


class ManifestBuild:
    def __init__(self, manifest_path: pathlib.Path, base_override: pathlib.Path | None,
                 build_dir: pathlib.Path, toolchain_wrapper: str | None, require_claims: bool,
                 extra_allocations=()):
        self.extra_allocations = list(extra_allocations)
        self.manifest_path = manifest_path.resolve()
        self.mdir = self.manifest_path.parent
        self.m = json.loads(self.manifest_path.read_text())
        check_keys(self.m, {"name", "description", "base_image", "base_sha256", "output_image",
                            "allocations", "symbols", "allow_occupied", "blobs", "data",
                            "splices", "asserts", "cpu", "verify"}, "manifest")
        self.name = self.m.get("name") or self.manifest_path.stem
        if not re.fullmatch(r"[A-Za-z0-9_.-]+", self.name):
            raise BuildError(f"manifest name {self.name!r} must be [A-Za-z0-9_.-]+")
        self.build_dir = build_dir
        self.require_claims = require_claims
        self.wrapper = toolchain_wrapper
        self.cpu = self.m.get("cpu", "ck803s")
        self.warnings: list[str] = []
        self.writes: list[Write] = []
        self.ram_sections: list[tuple[int, int, str]] = []
        self.blob_info: dict[str, dict] = {}
        self.blob_decl = {b["name"]: b for b in self.m.get("blobs", [])}
        self.data_decl = {d["name"]: d for d in self.m.get("data", [])}
        self.symbols = {k: self.parse_int(v, f"symbols.{k}") for k, v in
                        self.m.get("symbols", {}).items()}
        names = list(self.symbols) + list(self.blob_decl) + list(self.data_decl)
        dup = {n for n in names if names.count(n) > 1}
        if dup:
            raise BuildError(f"names used more than once across symbols/blobs/data: {sorted(dup)}")
        self._stock_syms: dict[str, int] | None = None
        self._load_base(base_override)
        self._load_policy()

    # ---- inputs -----------------------------------------------------------------------------
    def _load_base(self, override):
        if override is not None:
            path = override
        elif "base_image" in self.m:
            path = (self.mdir / self.m["base_image"])
        else:
            path = DEFAULT_BASE
        self.base_path = path.resolve()
        with open(self.base_path, "rb") as f:          # read-only, always
            self.base = f.read()
        if len(self.base) != FLASH_END - FLASH_BASE:
            raise BuildError(f"base image {self.base_path} is {len(self.base):#x} bytes, expected "
                             f"0x100000 (the FULL stock image; DM32.00.01.048.bin is truncated "
                             f"at 0xd2100 and must not be used as a base)")
        self.base_sha = sha256(self.base)
        side = self.base_path.with_name(self.base_path.name + ".sha256")
        if side.exists():
            want = side.read_text().split()[0].lower()
            if want != self.base_sha:
                raise BuildError(f"base image sha256 {self.base_sha} does not match its sidecar "
                                 f"{side} ({want}): the image changed or was damaged")
        else:
            self.warnings.append(f"base image {self.base_path} has no .sha256 sidecar; "
                                 f"integrity not checked beyond its size")
        pin = self.m.get("base_sha256")
        if pin and pin.lower() != self.base_sha:
            raise BuildError(f"base image sha256 {self.base_sha} != manifest base_sha256 {pin}")

    def _load_policy(self):
        alloc = load_allocations(self.extra_allocations)
        win = alloc["windows"]
        self.flash_window = win["flash"]
        self.sram_window = win["sram"]
        self.iram_window = win.get("iram")      # optional: only patches that claim IRAM need it
        self.forbidden = list(alloc["forbidden"])
        self.forbidden.append((PER_UNIT_LO, PER_UNIT_HI, "per_unit_sector (hard-coded)"))
        self.claims = alloc["claims"]
        own = self.m.get("allocations", [])
        known = {c["name"] for c in self.claims}
        missing = [n for n in own if n not in known]
        if missing:
            raise BuildError(f"manifest claims allocations {missing} that data/allocations.json "
                             f"(or any --extra-allocations file) does not list. Add them there "
                             f"(and regenerate the .ld files with gen_link_artifacts.py for "
                             f"in-repo claims) first.")
        self.own_claims = [c for c in self.claims if c["name"] in own]
        occ = json.loads(OCCUPIED_JSON.read_text())
        # occupied_regions.json offsets are relative to the flash base
        self.occupied = [(FLASH_BASE + int(o["start"], 16), FLASH_BASE + int(o["end"], 16),
                          o["what"][:70]) for o in occ["occupied"]]
        self.allow_occupied = []
        for i, a in enumerate(self.m.get("allow_occupied", [])):
            where = f"allow_occupied[{i}]"
            check_keys(a, {"start", "end_exclusive", "justification"}, where)
            just = (a.get("justification") or "").strip()
            reject_todo(just, where + ".justification")
            if len(just) < 20:
                raise BuildError(f"{where}: an allowance needs a real justification (>= 20 chars)")
            self.allow_occupied.append((self.parse_int(a["start"], where),
                                        self.parse_int(a["end_exclusive"], where), just))

    def stock_symbols(self) -> dict[str, int]:
        if self._stock_syms is None:
            self._stock_syms = {}
            for m in re.finditer(r"PROVIDE\((\w+)\s*=\s*(0x[0-9a-fA-F]+)\)",
                                 STOCK_SYMBOLS_LD.read_text()):
                self._stock_syms[m.group(1)] = int(m.group(2), 16)
        return self._stock_syms

    # ---- values and references -------------------------------------------------------------
    def parse_int(self, v, where: str) -> int:
        if isinstance(v, bool):
            raise BuildError(f"{where}: boolean is not an address/value")
        if isinstance(v, int):
            return v
        if not isinstance(v, str):
            raise BuildError(f"{where}: expected int or string, got {v!r}")
        reject_todo(v, where)
        if v.startswith("@"):
            return self.resolve(v, where)
        try:
            return int(v, 0)
        except ValueError:
            raise BuildError(f"{where}: cannot parse {v!r} as an integer") from None

    def resolve(self, ref: str, where: str) -> int:
        m = re.fullmatch(r"@([A-Za-z_][\w.]*(?::[A-Za-z_.$][\w.$]*)?)\s*([+-]\s*(?:0x[0-9a-fA-F]+|\d+))?", ref)
        if not m:
            raise BuildError(f"{where}: bad reference {ref!r}")
        name, off = m.group(1), int(m.group(2).replace(" ", ""), 0) if m.group(2) else 0
        if name.startswith("stock:"):
            sym = name[6:]
            if sym not in self.stock_symbols():
                raise BuildError(f"{where}: {sym!r} is not in tools/link/dm32_stock_symbols.ld "
                                 f"(RAW FUN_ names are deliberately absent; use an address)")
            return self.stock_symbols()[sym] + off
        if ":" in name:
            blob, sym = name.split(":", 1)
            if blob not in self.blob_info:
                raise BuildError(f"{where}: {ref} refers to blob {blob!r}, which is not built yet "
                                 f"(blobs build in manifest order)")
            syms = self.blob_info[blob]["symbols"]
            if sym not in syms:
                raise BuildError(f"{where}: symbol {sym!r} not found in blob {blob!r}")
            return syms[sym] + off
        if name in self.symbols:
            return self.symbols[name] + off
        if name in self.data_decl:
            return self.parse_int(self.data_decl[name]["addr"], f"data.{name}.addr") + off
        if name in self.blob_decl:
            if name in self.blob_info:
                return self.blob_info[name]["entry_addr"] + off
            decl = self.blob_decl[name]
            if "expect_entry" in decl:   # verified when that blob is built
                return self.parse_int(decl["expect_entry"], f"blobs.{name}.expect_entry") + off
            raise BuildError(f"{where}: {ref} is used before blob {name!r} is built and that blob "
                             f"declares no expect_entry; reorder the blobs or add expect_entry")
        raise BuildError(f"{where}: unknown reference {ref!r}")

    def expectation(self, item: dict, where: str, addr: int) -> bytes:
        keys = [k for k in ("expect", "expect_u32", "expect_u8", "expect_branch") if k in item]
        if not keys:
            raise BuildError(f"{where}: no expected stock bytes given. Every edit must state what "
                             f"it overwrites (expect / expect_u32 / expect_u8 / expect_branch)")
        out = []
        for k in keys:
            if k == "expect":
                out.append(parse_hex(item[k], where + ".expect"))
            elif k == "expect_u32":
                out.append(struct.pack("<I", self.parse_int(item[k], where + ".expect_u32")))
            elif k == "expect_u8":
                out.append(bytes([self.parse_int(item[k], where + ".expect_u8") & 0xFF]))
            else:
                br = item[k]
                check_keys(br, {"kind", "target"}, where + ".expect_branch")
                out.append(encode_branch(addr, self.parse_int(br["target"], where + ".target"),
                                         br["kind"]))
        if any(o != out[0] for o in out):
            raise BuildError(f"{where}: the expectations given disagree: {[o.hex() for o in out]}")
        if not out[0]:
            raise BuildError(f"{where}: empty expectation")
        return out[0]

    # ---- blobs ------------------------------------------------------------------------------
    def build_own_memory_ld(self):
        lines = [f"/* {OWN_MEMORY_LD} -- GENERATED by build_manifest_patch.py for patch "
                 f"'{self.name}'. DO NOT EDIT.",
                 " * MEMORY regions for exactly the data/allocations.json claims this manifest "
                 "owns (\"allocations\").",
                 " * Use INSTEAD of dm32_patch_memory.ld (which reserves these same claims). */"]
        if not self.own_claims:
            lines.append("/* this manifest owns no claims: nothing defined */")
        else:
            lines.append("MEMORY\n{")
            for c in self.own_claims:
                attr = "rx" if c["space"] == "flash" else "rw!x"
                lines.append(f"    PATCH_OWN_{c['name'].upper()} ({attr}) : ORIGIN = {c['lo']:#010x}, "
                             f"LENGTH = {c['hi'] - c['lo']:#x}")
            lines.append("}")
            for space, alias in (("flash", "PATCH_OWN_FLASH"), ("sram", "PATCH_OWN_SRAM")):
                cs = [c for c in self.own_claims if c["space"] == space]
                if cs:
                    big = max(cs, key=lambda c: c["hi"] - c["lo"])
                    lines.append(f'REGION_ALIAS("{alias}", PATCH_OWN_{big["name"].upper()});')
        (self.build_dir / OWN_MEMORY_LD).write_text("\n".join(lines) + "\n")

    def build_bsr_guard(self, tc: Toolchain, b: dict, elf: pathlib.Path, bd: pathlib.Path):
        """Pattern-12 guard: a `bsr` whose operand is an absolute address (or an `.equ` absolute
        symbol) assembles to NOTHING - the blob then has fewer instructions than its source and
        every later offset shifts with no error (docs/patch-patterns.md pattern 12). Disassemble
        the linked ELF with the same objdump the rest of this build uses and compare the `bsr`
        count with the blob's .S sources; fail hard when any source `bsr` is missing from the ELF.
        Skipped when the blob has no .S sources or the source count is 0."""
        asm = [s for s in b.get("sources", []) if s.lower().endswith(".s")]
        if not asm:
            return
        texts = [(self.mdir / s).read_text() for s in asm]
        src_n = count_source_bsr(texts)
        if src_n == 0:
            return
        elf_text = tc.run("objdump", ["-d", str(elf)], bd)
        elf_n = count_elf_bsr(elf_text)
        if elf_n < src_n:
            raise BuildError(
                f"blobs.{b['name']}: {src_n - elf_n} source `bsr` instruction(s) in "
                f"{', '.join(asm)} are missing from the linked ELF (objdump -d finds {elf_n} of "
                f"{src_n}). A `bsr` to an absolute address or an `.equ` absolute symbol assembles "
                f"to nothing (docs/patch-patterns.md pattern 12), so every later offset shifts "
                f"silently. Call stock functions by NAME via dm32_stock_symbols.ld "
                f"(`bsr fd6818b_reg_write`, never `bsr 0x0002c2f4`).")

    def build_blob(self, tc: Toolchain, b: dict):
        name = b["name"]
        where = f"blobs.{name}"
        check_keys(b, {"name", "sources", "cflags", "ldflags", "linker_script", "link_address",
                       "entry", "expect_entry", "sections", "defsym", "libgcc"}, where)
        if ("linker_script" in b) == ("link_address" in b):
            raise BuildError(f"{where}: give exactly one of linker_script / link_address")
        if "entry" not in b or not b.get("sources"):
            raise BuildError(f"{where}: needs 'entry' and 'sources'")
        bd = self.build_dir
        cflags = b.get("cflags", DEFAULT_CFLAGS)
        objs = []
        for src in b["sources"]:
            sp = (self.mdir / src).resolve()
            if not sp.exists():
                raise BuildError(f"{where}: source {sp} not found")
            obj = bd / f"{name}__{sp.stem}.o"
            tc.run("gcc", [f"-mcpu={self.cpu}", *cflags, "-I", str(API_INCLUDE_DIR),
                           "-c", str(sp), "-o", str(obj)], bd)
            objs.append(str(obj))
        elf = bd / f"{name}.elf"
        ld = ["-L", str(bd), "-L", str(LINK_DIR), "-L", str(self.mdir)]
        if "linker_script" in b:
            ld += ["-T", str((self.mdir / b["linker_script"]).resolve())]
        else:
            ld += [f"-Ttext={self.parse_int(b['link_address'], where + '.link_address'):#x}"]
        ld += ["-e", b["entry"], "-Map", str(bd / f"{name}.map")]
        for sym, val in b.get("defsym", {}).items():
            ld.append(f"--defsym={sym}={self.parse_int(val, f'{where}.defsym.{sym}'):#x}")
        ld += list(b.get("ldflags", []))
        ld += ["-o", str(elf), *objs]
        if b.get("libgcc", True):
            ld.append(tc.libgcc(bd))
        tc.run("ld", ld, bd)
        self.build_bsr_guard(tc, b, elf, bd)

        e = Elf(elf)
        if b["entry"] not in e.symbols:
            raise BuildError(f"{where}: entry symbol {b['entry']!r} not in the linked ELF")
        entry = e.symbols[b["entry"]]
        if "expect_entry" in b:
            want = self.parse_int(b["expect_entry"], where + ".expect_entry")
            if entry != want:
                raise BuildError(
                    f"{where}: {b['entry']} linked at {entry:#x}, not the declared {want:#x}. "
                    f"Every table and branch that points at it would hit the wrong code (the "
                    f"Snake mode-126 handler-aliasing bug, snake_game.ld). Fix the link, not the "
                    f"number.")
        for (p_type, _o, vaddr, paddr, filesz, _m, _f, _a) in e.phdrs:
            if p_type == PT_LOAD and filesz and vaddr != paddr:
                raise BuildError(f"{where}: a loadable segment has LMA {paddr:#x} != VMA {vaddr:#x}; "
                                 f"this builder places bytes at their VMA and does not support AT()")

        alloc = [s for s in e.sections if s["flags"] & SHF_ALLOC and s["size"]
                 and not s["name"].startswith(RESERVED_PREFIX)]
        progbits = [s for s in alloc if s["type"] != SHT_NOBITS]
        for s in progbits:
            if not (FLASH_BASE <= s["addr"] < FLASH_END):
                raise BuildError(
                    f"{where}: section {s['name']} has file contents at {s['addr']:#x} (outside "
                    f"program flash). Initialised RAM data is never copied at boot: make it const "
                    f"or zero-initialised.")
        if "sections" in b:
            wanted = b["sections"]
            chosen = [s for s in progbits if s["name"] in wanted]
            left = [s["name"] for s in progbits if s["name"] not in wanted]
            if left:
                raise BuildError(f"{where}: allocated section(s) {left} are not in 'sections' and "
                                 f"would silently be missing from the radio")
        else:
            chosen = progbits
        if not chosen:
            raise BuildError(f"{where}: nothing to extract (no allocated PROGBITS sections)")
        chosen.sort(key=lambda s: s["addr"])
        lo = chosen[0]["addr"]
        hi = max(s["addr"] + s["size"] for s in chosen)
        img = bytearray(hi - lo)     # gaps zero-filled, as `objcopy -O binary` does
        prev_end = lo
        for s in chosen:
            if s["addr"] < prev_end:
                raise BuildError(f"{where}: section {s['name']} overlaps the previous section")
            img[s["addr"] - lo:s["addr"] - lo + s["size"]] = e.section_bytes(s)
            prev_end = s["addr"] + s["size"]
        if not (lo <= entry < hi):
            raise BuildError(f"{where}: entry {entry:#x} is outside the extracted image "
                             f"[{lo:#x}, {hi:#x})")
        (bd / f"{name}.bin").write_bytes(img)

        for s in alloc:
            if s["type"] == SHT_NOBITS:
                self.ram_sections.append((s["addr"], s["addr"] + s["size"], f"{name}:{s['name']}"))
        self.blob_info[name] = dict(entry=b["entry"], entry_addr=entry, addr=lo, size=len(img),
                                    sections=[s["name"] for s in chosen], symbols=e.symbols,
                                    ram=[(a, z, l) for (a, z, l) in self.ram_sections
                                         if l.startswith(name + ":")])
        self.writes.append(Write(lo, img, f"blob {name}", "blob", name))

    # ---- data -------------------------------------------------------------------------------
    def build_data(self, d: dict):
        name = d["name"]
        where = f"data.{name}"
        check_keys(d, {"name", "addr", "parts"}, where)
        addr = self.parse_int(d["addr"], where + ".addr")
        buf = bytearray()
        for i, p in enumerate(d.get("parts", [])):
            pw = f"{where}.parts[{i}]"
            if "string" in p:
                check_keys(p, {"string", "encoding", "nul"}, pw)
                buf += p["string"].encode(p.get("encoding", "ascii"))
                if p.get("nul", True):
                    buf += b"\0"
            elif "bytes" in p:
                check_keys(p, {"bytes"}, pw)
                buf += parse_hex(p["bytes"], pw)
            elif "u32" in p or "u16" in p or "u8" in p:
                (k,) = [k for k in ("u32", "u16", "u8") if k in p]
                check_keys(p, {k}, pw)
                fmt = {"u32": "<I", "u16": "<H", "u8": "<B"}[k]
                for j, v in enumerate(p[k]):
                    buf += struct.pack(fmt, self.parse_int(v, f"{pw}.{k}[{j}]"))
            elif "struct" in p:
                check_keys(p, {"struct", "values"}, pw)
                vals = [self.parse_int(v, f"{pw}.values[{j}]") for j, v in enumerate(p["values"])]
                buf += struct.pack(p["struct"], *vals)
            elif "align" in p:
                check_keys(p, {"align", "fill"}, pw)
                a = int(p["align"])
                while len(buf) % a:
                    buf.append(int(p.get("fill", 0)) & 0xFF)
            elif "stock_u32" in p:
                check_keys(p, {"stock_u32", "count", "expect"}, pw)
                src = self.parse_int(p["stock_u32"], pw + ".stock_u32")
                n = int(p["count"])
                if not (FLASH_BASE <= src and src + 4 * n <= FLASH_END):
                    raise BuildError(f"{pw}: stock_u32 range outside program flash")
                words = list(struct.unpack_from(f"<{n}I", self.base, src - FLASH_BASE))
                if "expect" in p:
                    exp = [self.parse_int(v, f"{pw}.expect[{j}]") for j, v in enumerate(p["expect"])]
                    if exp != words:
                        raise BuildError(f"{pw}: stock table at {src:#x} is "
                                         f"{[hex(w) for w in words]}, expected "
                                         f"{[hex(w) for w in exp]} (wrong base image?)")
                buf += struct.pack(f"<{n}I", *words)
            else:
                raise BuildError(f"{pw}: unknown part {sorted(p)}")
        if not buf:
            raise BuildError(f"{where}: empty data item")
        self.writes.append(Write(addr, buf, f"data {name}", "data", name))

    # ---- splices and asserts ----------------------------------------------------------------
    def assemble_lrw_jmp(self, tc: Toolchain, addr: int, target: int, reg: str, where: str) -> bytes:
        if not re.fullmatch(r"r(?:[0-9]|1[0-3])", reg):
            raise BuildError(f"{where}: lrw_jmp needs an explicit scratch register r0-r13 that is "
                             f"dead at {addr:#x}; got {reg!r}")
        stem = self.build_dir / f"lrwjmp_{addr:08x}"
        stem.with_suffix(".S").write_text(
            f"    .text\n    .global _lrwjmp\n_lrwjmp:\n    lrw {reg}, {target:#x}\n    jmp {reg}\n")
        tc.run("gcc", [f"-mcpu={self.cpu}", "-c", str(stem.with_suffix(".S")), "-o",
                       str(stem.with_suffix(".o"))], self.build_dir)
        tc.run("ld", [f"-Ttext={addr:#x}", "-e", "_lrwjmp", "-o", str(stem.with_suffix(".elf")),
                      str(stem.with_suffix(".o"))], self.build_dir)
        e = Elf(stem.with_suffix(".elf"))
        (text,) = [s for s in e.sections if s["name"] == ".text"]
        data = e.section_bytes(text)
        if struct.pack("<I", target) not in data:
            raise BuildError(f"{where}: assembled lrw/jmp does not carry the literal {target:#x}")
        return data

    def build_splice(self, tc: Toolchain, s: dict):
        name = s.get("name", h(0))
        where = f"splices.{name}"
        check_keys(s, {"name", "addr", "expect", "expect_u32", "expect_u8", "expect_branch",
                       "bytes", "u32", "u8", "branch", "fill"}, where)
        addr = self.parse_int(s["addr"], where + ".addr")
        expect = self.expectation(s, where, addr)
        reps = [k for k in ("bytes", "u32", "u8", "branch") if k in s]
        if len(reps) != 1:
            raise BuildError(f"{where}: give exactly one replacement (bytes/u32/u8/branch)")
        k = reps[0]
        branch_check = None
        if k == "bytes":
            new = parse_hex(s["bytes"], where + ".bytes")
        elif k == "u32":
            new = struct.pack("<I", self.parse_int(s["u32"], where + ".u32"))
        elif k == "u8":
            new = bytes([self.parse_int(s["u8"], where + ".u8") & 0xFF])
        else:
            br = s["branch"]
            check_keys(br, {"kind", "target", "reg"}, where + ".branch")
            tgt = self.parse_int(br["target"], where + ".branch.target")
            if br["kind"] in ("br", "bsr"):
                new = encode_branch(addr, tgt, br["kind"])
                branch_check = (br["kind"], tgt)
            elif br["kind"] == "lrw_jmp":
                new = self.assemble_lrw_jmp(tc, addr, tgt, br.get("reg", ""), where)
            else:
                raise BuildError(f"{where}: branch kind must be br, bsr or lrw_jmp")
        if len(new) < len(expect) and "fill" in s:
            fill = parse_hex(s["fill"], where + ".fill")
            while len(new) < len(expect):
                new += fill
            new = new[:len(expect)]
        if len(new) != len(expect):
            raise BuildError(f"{where}: replacement is {len(new)} bytes but the expectation covers "
                             f"{len(expect)}; they must match (use 'fill' to pad a shorter one)")
        w = Write(addr, new, f"splice {name}", "splice", name)
        w.item = dict(expect=expect, branch=branch_check)
        self.writes.append(w)

    def run_assert(self, a: dict):
        name = a.get("name", "?")
        where = f"asserts.{name}"
        check_keys(a, {"name", "addr", "expect", "expect_u32", "expect_u8", "expect_branch"}, where)
        addr = self.parse_int(a["addr"], where + ".addr")
        exp = self.expectation(a, where, addr)
        got = self.base_at(addr, len(exp), where)
        if got != exp:
            raise BuildError(f"{where} @ {addr:#x}: expected {exp.hex(' ')}, base has "
                             f"{got.hex(' ')} (wrong base image, or the stock layout this patch "
                             f"relies on is not what was traced)")

    def base_at(self, addr: int, n: int, where: str) -> bytes:
        if not (FLASH_BASE <= addr and addr + n <= FLASH_END):
            raise BuildError(f"{where}: {addr:#x}+{n} is outside program flash")
        return self.base[addr - FLASH_BASE:addr - FLASH_BASE + n]

    # ---- policy -----------------------------------------------------------------------------
    def check_policy(self):
        # ordering / overlap among this manifest's own writes
        ws = sorted(self.writes, key=lambda w: w.addr)
        for a, b in zip(ws, ws[1:]):
            if b.addr < a.end:
                raise BuildError(f"{b.label} [{b.addr:#x},{b.end:#x}) overlaps {a.label} "
                                 f"[{a.addr:#x},{a.end:#x}) (Snake v12: a handler's literal pool "
                                 f"overwritten by the next blob)")
        wlo, whi = self.flash_window
        for w in ws:
            if not (FLASH_BASE <= w.addr and w.end <= FLASH_END):
                raise BuildError(f"{w.label} [{w.addr:#x},{w.end:#x}) is outside program flash "
                                 f"0x03000000-0x030FFFFF")
            for lo, hi, what in self.forbidden:
                if overlaps(w.addr, w.end, lo, hi):
                    raise BuildError(f"{w.label} [{w.addr:#x},{w.end:#x}) touches forbidden range "
                                     f"{what} [{lo:#x},{hi:#x}). This is never allowed.")
            for lo, hi, what in self.occupied:
                if not overlaps(w.addr, w.end, lo, hi):
                    continue
                if w.kind != "splice":
                    raise BuildError(f"{w.label} [{w.addr:#x},{w.end:#x}) lands in occupied region "
                                     f"[{lo:#x},{hi:#x}) ({what}); new code/data may never go there")
                if not any(alo <= w.addr and w.end <= ahi for alo, ahi, _ in self.allow_occupied):
                    raise BuildError(f"{w.label} [{w.addr:#x},{w.end:#x}) edits occupied region "
                                     f"[{lo:#x},{hi:#x}) ({what}) without an allow_occupied entry "
                                     f"(with justification) covering it")
                self.warnings.append(f"{w.label} edits occupied region [{lo:#x},{hi:#x}) under an "
                                     f"explicit allow_occupied entry")
            if w.kind in ("blob", "data") and not (wlo <= w.addr and w.end <= whi):
                raise BuildError(f"{w.label} [{w.addr:#x},{w.end:#x}) is outside the patch flash "
                                 f"window [{wlo:#x},{whi:#x}) from data/allocations.json; new "
                                 f"code/data only goes there (anything else is a splice)")
            self._check_claims(w.addr, w.end, w.label, "flash")
            # bytes
            if w.kind == "splice":
                got = self.base_at(w.addr, len(w.data), w.label)
                if got != w.item["expect"]:
                    raise BuildError(f"{w.label} @ {w.addr:#x}: expected {w.item['expect'].hex(' ')}, "
                                     f"base has {got.hex(' ')} (already patched, or wrong base image)")
            else:
                region = self.base_at(w.addr, len(w.data), w.label)
                bad = next((i for i, x in enumerate(region) if x != 0xFF), None)
                if bad is not None:
                    raise BuildError(f"{w.label} @ {w.addr:#x} is NOT erased at +{bad:#x} "
                                     f"(base has {region[bad]:#04x})")
        for lo, hi, label in self.ram_sections:
            if overlaps(lo, hi, IRAM_LO, IRAM_HI):
                # IRAM is refused unless allocations.json declares an "iram" window AND this
                # manifest owns a claim covering the section (dm32uv-harness's state block).
                if not self.iram_window:
                    raise BuildError(f"{label} [{lo:#x},{hi:#x}) is in IRAM; no IRAM range is "
                                     f"verified free (docs/rtos-and-memory.md)")
                ilo, ihi = self.iram_window
                if not (ilo <= lo and hi <= ihi):
                    raise BuildError(f"{label} [{lo:#x},{hi:#x}) is outside the IRAM window "
                                     f"[{ilo:#x},{ihi:#x}) (data/allocations.json)")
                self._check_claims(lo, hi, label, "iram")
                continue
            slo, shi = self.sram_window
            if not (slo <= lo and hi <= shi):
                raise BuildError(f"{label} [{lo:#x},{hi:#x}) is outside the SRAM scratch window "
                                 f"[{slo:#x},{shi:#x}) (data/allocations.json)")
            self._check_claims(lo, hi, label, "sram")

    def _check_claims(self, lo, hi, label, space):
        win = {"flash": self.flash_window, "sram": self.sram_window,
               "iram": self.iram_window}[space]
        if not overlaps(lo, hi, *win):
            return
        own_names = {c["name"] for c in self.own_claims}
        for c in self.claims:
            if c["space"] == space and overlaps(lo, hi, c["lo"], c["hi"]) and c["name"] not in own_names:
                raise BuildError(f"{label} [{lo:#x},{hi:#x}) overlaps allocation '{c['name']}' "
                                 f"[{c['lo']:#x},{c['hi']:#x}) owned by another patch: {c['owner']}")
        clo, chi = max(lo, win[0]), min(hi, win[1])
        covered = any(c["lo"] <= clo and chi <= c["hi"] for c in self.own_claims if c["space"] == space)
        if not covered:
            msg = (f"{label} [{lo:#x},{hi:#x}) is not inside any data/allocations.json claim this "
                   f"manifest owns. Claim it (allocations.json + gen_link_artifacts.py, then list it "
                   f"under \"allocations\") before staging, or another patch may take the space.")
            if self.require_claims:
                raise BuildError(msg)
            self.warnings.append(msg)

    # ---- main flow --------------------------------------------------------------------------
    def build(self) -> dict:
        self.build_dir.mkdir(parents=True, exist_ok=True)
        self.build_own_memory_ld()
        need_tc = bool(self.m.get("blobs")) or any(
            isinstance(s.get("branch"), dict) and s["branch"].get("kind") == "lrw_jmp"
            for s in self.m.get("splices", []))
        tc = Toolchain(self.wrapper, self.cpu) if need_tc else None
        for a in self.m.get("asserts", []):
            self.run_assert(a)
        for b in self.m.get("blobs", []):
            self.build_blob(tc, b)
        for d in self.m.get("data", []):
            self.build_data(d)
        for s in self.m.get("splices", []):
            self.build_splice(tc, s)
        self.check_policy()

        patched = bytearray(self.base)
        for w in self.writes:
            # re-verify immediately before the write (CLAUDE.md gotcha 4), not from memory
            cur = bytes(patched[w.addr - FLASH_BASE:w.end - FLASH_BASE])
            if w.kind == "splice":
                assert cur == w.item["expect"], w.label
            else:
                assert all(x == 0xFF for x in cur), w.label
            patched[w.addr - FLASH_BASE:w.end - FLASH_BASE] = w.data

        # post-write verification
        for w in self.writes:
            if w.kind == "splice" and w.item["branch"]:
                kind, tgt = w.item["branch"]
                dec = decode_branch(bytes(patched[w.addr - FLASH_BASE:w.addr - FLASH_BASE + 4]))
                if dec is None or dec[0] != kind or w.addr + dec[1] * 2 != tgt:
                    raise BuildError(f"{w.label}: written branch does not decode back to {kind} "
                                     f"{tgt:#x} (got {dec})")
        covered = bytearray(len(patched))
        for w in self.writes:
            covered[w.addr - FLASH_BASE:w.end - FLASH_BASE] = b"\1" * len(w.data)
        diffs = [i for i in range(len(patched)) if patched[i] != self.base[i]]
        stray = [i for i in diffs if not covered[i]]
        if stray:
            raise BuildError(f"{len(stray)} changed byte(s) outside every declared write, first at "
                             f"{FLASH_BASE + stray[0]:#x}")
        if patched[PER_UNIT_LO - FLASH_BASE:PER_UNIT_HI - FLASH_BASE] != \
                self.base[PER_UNIT_LO - FLASH_BASE:PER_UNIT_HI - FLASH_BASE]:
            raise BuildError("per-unit sector changed")  # unreachable given the checks above

        sectors = sorted({(FLASH_BASE + i) & ~(SECTOR - 1) for i in diffs})
        seen = set()
        for w in self.writes:
            for warn in corpus_crosscheck(w.addr):
                if warn not in seen:
                    seen.add(warn)
                    self.warnings.append(f"[corpus, informational] {w.label}: {warn}")
        self.patched = bytes(patched)
        self.diffs = diffs
        self.sectors = sectors
        self.toolchain = (tc.version(self.build_dir) if tc else None)
        if tc:
            (self.build_dir / "commands.log").write_text("\n".join(tc.log) + "\n")
        return self.summary()

    def summary(self) -> dict:
        per_sector = []
        for s in self.sectors:
            off = s - FLASH_BASE
            st, pt = self.base[off:off + SECTOR], self.patched[off:off + SECTOR]
            per_sector.append(dict(addr=h(s), stock_sha256=sha256(st), patched_sha256=sha256(pt),
                                   bytes_changed=sum(1 for a, b in zip(st, pt) if a != b),
                                   stock_file=f"sector_{s:08x}_stock.bin",
                                   patched_file=f"sector_{s:08x}_patched.bin"))
        return dict(
            name=self.name,
            manifest=str(self.manifest_path),
            base=dict(path=str(self.base_path), sha256=self.base_sha),
            image=dict(file=self.m.get("output_image", f"progmem_{self.name.upper()}_patched.bin"),
                       sha256=sha256(self.patched)),
            bytes_changed=len(self.diffs),
            sectors=per_sector,
            writes=[dict(label=w.label, kind=w.kind, addr=h(w.addr), end=h(w.end), len=len(w.data))
                    for w in sorted(self.writes, key=lambda w: w.addr)],
            blobs={n: dict(entry=i["entry"], entry_addr=h(i["entry_addr"]), addr=h(i["addr"]),
                           size=i["size"], sections=i["sections"],
                           ram=[dict(section=l, start=h(a), end=h(z)) for a, z, l in i["ram"]])
                   for n, i in self.blob_info.items()},
            own_allocations=[c["name"] for c in self.own_claims],
            toolchain=self.toolchain,
            verify=self.m.get("verify"),
            warnings=self.warnings,
        )


def write_outputs(mb: ManifestBuild, summary: dict, out: pathlib.Path) -> None:
    out.mkdir(parents=True, exist_ok=True)
    protected = {mb.base_path, mb.manifest_path}
    targets = [(out / summary["image"]["file"], mb.patched), (out / "summary.json", None)]
    for s in mb.sectors:
        off = s - FLASH_BASE
        targets.append((out / f"sector_{s:08x}_stock.bin", mb.base[off:off + SECTOR]))
        targets.append((out / f"sector_{s:08x}_patched.bin", mb.patched[off:off + SECTOR]))
    for p, _ in targets:
        if p.resolve() in protected:
            raise BuildError(f"refusing to write {p}: it is an input of this build")
    for p, data in targets:
        if data is None:
            p.write_text(json.dumps(summary, indent=2) + "\n")
        else:
            p.write_bytes(data)


def compare(patched: bytes, ref_path: pathlib.Path) -> int:
    ref = ref_path.read_bytes()
    if ref == patched:
        print(f"\nCOMPARE: byte-identical to {ref_path} (sha256 {sha256(ref)})")
        return 0
    print(f"\nCOMPARE: DIFFERS from {ref_path}")
    if len(ref) != len(patched):
        print(f"  length {len(patched):#x} vs reference {len(ref):#x}")
    n = min(len(ref), len(patched))
    diffs = [i for i in range(n) if ref[i] != patched[i]]
    print(f"  {len(diffs)} differing byte(s)")
    runs, start = [], None
    for j, i in enumerate(diffs):
        if start is None:
            start = i
        if j + 1 == len(diffs) or diffs[j + 1] != i + 1:
            runs.append((start, i + 1))
            start = None
    for lo, hi in runs[:40]:
        print(f"  {FLASH_BASE + lo:#010x}+{hi - lo}: built {patched[lo:hi][:16].hex(' ')} | "
              f"reference {ref[lo:hi][:16].hex(' ')}")
    return 1


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("manifest", type=pathlib.Path)
    ap.add_argument("--out", type=pathlib.Path, default=None,
                    help="output directory (default: out/patches/<name>/ under the repo, gitignored)")
    ap.add_argument("--build-dir", type=pathlib.Path, default=None,
                    help="intermediates (default: <out>/build)")
    ap.add_argument("--base", type=pathlib.Path, default=None,
                    help="override the manifest's base image (read-only)")
    ap.add_argument("--cskybuild", default=os.environ.get("CSKYBUILD"),
                    help="toolchain wrapper taking the tool name as argv[1] (default: $CSKYBUILD, "
                         "else the tools on PATH)")
    ap.add_argument("--require-claims", action="store_true",
                    help="error (not warn) when a write in the patch window is outside this "
                         "manifest's own allocations.json claims")
    ap.add_argument("--extra-allocations", type=pathlib.Path, action="append", default=[],
                    metavar="FILE",
                    help="additional allocation file(s) (same schema as data/allocations.json), "
                         "merged with it before claim resolution; repeatable. For patches that "
                         "live outside this repo.")
    ap.add_argument("--compare", type=pathlib.Path, default=None,
                    help="compare the patched image with this reference; exit 1 if it differs")
    args = ap.parse_args(argv)

    try:
        name = json.loads(args.manifest.read_text()).get("name") or args.manifest.stem
        out = (args.out or (REPO_ROOT / "out" / "patches" / name)).resolve()
        build_dir = (args.build_dir or (out / "build")).resolve()
        mb = ManifestBuild(args.manifest, args.base, build_dir, args.cskybuild, args.require_claims,
                           args.extra_allocations)
        summary = mb.build()
        write_outputs(mb, summary, out)
    except BuildError as e:
        print(f"FAIL: {e}", file=sys.stderr)
        return 2

    print(f"patch '{summary['name']}' built from {summary['manifest']}")
    print(f"base   {summary['base']['path']}  sha256 {summary['base']['sha256']}")
    for n, b in summary["blobs"].items():
        ram = "".join(f", {r['section']} {r['start']}..{r['end']}" for r in b["ram"])
        print(f"  blob   {n:28s} {b['addr']} +{b['size']:<5} entry {b['entry']} @ {b['entry_addr']}{ram}")
    for w in summary["writes"]:
        if w["kind"] != "blob":
            print(f"  {w['kind']:6s} {w['label'][len(w['kind']) + 1:]:28s} {w['addr']} +{w['len']}")
    print(f"changed sectors ({len(summary['sectors'])}):")
    for s in summary["sectors"]:
        print(f"  {s['addr']}  {s['bytes_changed']:5d} bytes  patched sha256 {s['patched_sha256'][:16]}")
    print(f"{summary['bytes_changed']} bytes differ from base; image sha256 {summary['image']['sha256']}")
    if summary["warnings"]:
        print("warnings:")
        for w in summary["warnings"]:
            print(f"  ! {w}")
    print(f"wrote {out}/ ({summary['image']['file']}, sector_*_{{stock,patched}}.bin, summary.json)")
    print("Not flashed. Next: compose_qemu_image.py + qemu_run.py, then stage_sectors.py; flashing "
          "is a manual human step.")
    if args.compare:
        return compare(mb.patched, args.compare)
    return 0


if __name__ == "__main__":
    sys.exit(main())
