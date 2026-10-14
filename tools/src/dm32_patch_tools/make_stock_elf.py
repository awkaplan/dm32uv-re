#!/usr/bin/env python3
"""Build dm32_stock.elf: the stock DM32.00.01.048 program flash + IRAM as one symbolised ELF.

Why: with a real ELF, the ordinary binutils/gdb workflow works against stock firmware --
    csky-abiv2-elf-objdump -d --start-address=0x03017c50 --stop-address=0x03017c70 out/dm32_stock.elf
prints `<display_fill_rect>:` and `bsr ... <name>` targets; csky-abiv2-elf-nm lists every
function; addr2line/gdb resolve addresses to names. It is also a valid `--just-symbols` input
(`csky-abiv2-elf-ld -R out/dm32_stock.elf`), an alternative to tools/link/dm32_stock_symbols.ld.

Contents (pure python, stdlib only -- no pyelftools or binutils needed to BUILD it):
  * PT_LOAD + section .stock_flash @ 0x03000000: data/firmware/patching/
    progmem_stock_DP570UV_20260926_FULL.bin (1 MB; per-unit sector 0x0300b000 scrubbed to 0xFF
    as shipped).
  * PT_LOAD + section .stock_iram  @ 0x00010000: data/firmware/IRAM_dm32.00.01.048.bin (288 KB,
    the run-time IRAM image the boot stub copies from flash 0x030bfc20).
  * .symtab: every function in meta/functions.json as STT_FUNC with its size.
        RAW (FUN_xxxxxxxx)        -> STB_LOCAL   (visible to objdump/nm/gdb, never exported)
        CONFIRMED / STRUCTURAL    -> STB_GLOBAL  (under the same link name as
                                    tools/link/dm32_stock_symbols.ld, i.e. C-library-namespace
                                    names become stock_<name>)
    plus every address-valued #define in tools/include/dm32_patch_api.h: function aliases as
    global STT_NOTYPE (so objdump still prefers the corpus FUNC name at that address), RAM
    cells as STT_OBJECT, code labels as STT_NOTYPE. Addresses outside both images (SRAM) are
    SHN_ABS.
  * e_machine EM_CSKY (252), e_flags 0x21000000 -- the value csky-abiv2-elf-gcc -mcpu=ck803s
    writes into its own objects in this repo's image (checked with readelf on
    tools/examples/snake/snake_game.elf), so objdump selects the same ABIv2 decoder.

Where the output goes, and why not under version control: the ELF is ~1.4 MB of bytes that are
already committed (the two images) plus a symbol table that is a pure function of
meta/functions.json. It is regenerated in well under a second, so it is written to
<repo>/out/dm32_stock.elf by default and <repo>/out/ is made self-ignoring (an `out/.gitignore`
containing `*` is created alongside it). Use --out to put it elsewhere.

Usage:
    python3 tools/src/dm32_patch_tools/make_stock_elf.py [--out out/dm32_stock.elf]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import struct
import sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from gen_link_artifacts import (FLASH_BASE, IRAM_LO, ROOT, load_api_header,  # noqa: E402
                                load_functions)

EM_CSKY = 252
E_FLAGS_CK803S_ABIV2 = 0x21000000
SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB = 1, 2, 3
SHF_WRITE, SHF_ALLOC, SHF_EXECINSTR = 1, 2, 4
PT_LOAD = 1
PF_X, PF_W, PF_R = 1, 2, 4
STB_LOCAL, STB_GLOBAL = 0, 1
STT_NOTYPE, STT_OBJECT, STT_FUNC, STT_SECTION, STT_FILE = 0, 1, 2, 3, 4
SHN_ABS = 0xFFF1
PAGE = 0x1000


def check_sha(path: pathlib.Path) -> None:
    side = path.with_name(path.name + ".sha256")
    if not side.exists():
        return
    want = side.read_text().split()[0]
    got = hashlib.sha256(path.read_bytes()).hexdigest()
    if want != got:
        sys.exit(f"make_stock_elf: {path} sha256 {got} != {side.name} {want}")


class StrTab:
    def __init__(self):
        self.data = bytearray(b"\0")
        self.index = {"": 0}

    def add(self, s: str) -> int:
        if s not in self.index:
            self.index[s] = len(self.data)
            self.data += s.encode() + b"\0"
        return self.index[s]


def build(flash: bytes, iram: bytes, funcs: list[dict], api: list[dict]) -> bytes:
    sections = [  # name, addr, data, flags, phdr flags
        (".stock_flash", FLASH_BASE, flash, SHF_ALLOC | SHF_EXECINSTR, PF_R | PF_X),
        (".stock_iram", IRAM_LO, iram, SHF_ALLOC | SHF_EXECINSTR | SHF_WRITE, PF_R | PF_W | PF_X),
    ]

    def shndx_for(addr: int) -> int:
        for i, (_, base, data, _, _) in enumerate(sections, start=1):
            if base <= addr < base + len(data):
                return i
        return SHN_ABS

    strtab = StrTab()
    locals_, globals_ = [], []
    # section symbols + a file symbol, conventional first locals
    locals_.append((strtab.add("dm32_stock.elf"), 0, 0, (STB_LOCAL << 4) | STT_FILE, SHN_ABS))
    for i, (_, base, _, _, _) in enumerate(sections, start=1):
        locals_.append((0, base, 0, (STB_LOCAL << 4) | STT_SECTION, i))

    names = set()
    for f in sorted(funcs, key=lambda f: f["addr"]):
        shndx = shndx_for(f["addr"])
        if shndx == SHN_ABS:
            sys.exit(f"make_stock_elf: function {f['name']} @{f['addr']:#x} is outside both images")
        if f["confidence"] == "RAW":
            locals_.append((strtab.add(f["name"]), f["addr"], f["size"],
                            (STB_LOCAL << 4) | STT_FUNC, shndx))
        else:
            names.add(f["link_name"])
            globals_.append((strtab.add(f["link_name"]), f["addr"], f["size"],
                             (STB_GLOBAL << 4) | STT_FUNC, shndx))
    for a in api:
        if a["name"] in names:
            continue
        names.add(a["name"])
        typ = STT_OBJECT if a["kind"] == "object" else STT_NOTYPE
        globals_.append((strtab.add(a["name"]), a["addr"], a["size"],
                         (STB_GLOBAL << 4) | typ, shndx_for(a["addr"])))

    symtab = bytearray(struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0))
    for name, value, size, info, shndx in locals_ + globals_:
        symtab += struct.pack("<IIIBBH", name, value, size, info, 0, shndx)
    first_global = 1 + len(locals_)

    shstr = StrTab()
    ehsize, phentsize, shentsize = 52, 32, 40
    phnum = len(sections)
    # layout: [ehdr][phdrs] ... page-aligned section data ... symtab strtab shstrtab [shdrs]
    off = PAGE
    placed = []
    for name, addr, data, flags, pflags in sections:
        placed.append((name, addr, data, flags, pflags, off))
        off += (len(data) + PAGE - 1) // PAGE * PAGE
    symtab_off = off
    strtab_off = symtab_off + len(symtab)
    names_for_sh = [n for n, *_ in sections] + [".symtab", ".strtab", ".shstrtab"]
    for n in names_for_sh:
        shstr.add(n)
    shstr_off = strtab_off + len(strtab.data)
    shoff = (shstr_off + len(shstr.data) + 3) // 4 * 4
    shnum = 1 + len(sections) + 3

    out = bytearray(shoff + shnum * shentsize)
    ident = b"\x7fELF" + bytes([1, 1, 1, 0]) + bytes(8)
    out[0:ehsize] = ident + struct.pack("<HHIIIIIHHHHHH", 2, EM_CSKY, 1, FLASH_BASE, ehsize,
                                        shoff, E_FLAGS_CK803S_ABIV2, ehsize, phentsize, phnum,
                                        shentsize, shnum, shnum - 1)
    for i, (name, addr, data, flags, pflags, doff) in enumerate(placed):
        out[ehsize + i * phentsize: ehsize + (i + 1) * phentsize] = struct.pack(
            "<IIIIIIII", PT_LOAD, doff, addr, addr, len(data), len(data), pflags, PAGE)
        out[doff:doff + len(data)] = data
    out[symtab_off:symtab_off + len(symtab)] = symtab
    out[strtab_off:strtab_off + len(strtab.data)] = strtab.data
    out[shstr_off:shstr_off + len(shstr.data)] = shstr.data

    shdrs = [struct.pack("<IIIIIIIIII", *([0] * 10))]
    for name, addr, data, flags, pflags, doff in placed:
        shdrs.append(struct.pack("<IIIIIIIIII", shstr.add(name), SHT_PROGBITS, flags, addr, doff,
                                 len(data), 0, 0, 4, 0))
    symtab_idx = 1 + len(sections)
    shdrs.append(struct.pack("<IIIIIIIIII", shstr.add(".symtab"), SHT_SYMTAB, 0, 0, symtab_off,
                             len(symtab), symtab_idx + 1, first_global, 4, 16))
    shdrs.append(struct.pack("<IIIIIIIIII", shstr.add(".strtab"), SHT_STRTAB, 0, 0, strtab_off,
                             len(strtab.data), 0, 0, 1, 0))
    shdrs.append(struct.pack("<IIIIIIIIII", shstr.add(".shstrtab"), SHT_STRTAB, 0, 0, shstr_off,
                             len(shstr.data), 0, 0, 1, 0))
    out[shoff:] = b"".join(shdrs)
    return bytes(out), len(locals_), len(globals_)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--flash", type=pathlib.Path,
                    default=ROOT / "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin")
    ap.add_argument("--iram", type=pathlib.Path, default=ROOT / "data/firmware/IRAM_dm32.00.01.048.bin")
    ap.add_argument("--functions", type=pathlib.Path, default=ROOT / "meta/functions.json")
    ap.add_argument("--api-header", type=pathlib.Path, default=ROOT / "tools/include/dm32_patch_api.h")
    ap.add_argument("--out", type=pathlib.Path, default=ROOT / "out/dm32_stock.elf")
    args = ap.parse_args(argv)

    for p in (args.flash, args.iram):
        check_sha(p)
    flash, iram = args.flash.read_bytes(), args.iram.read_bytes()
    if len(flash) != 0x100000:
        sys.exit(f"make_stock_elf: {args.flash} is {len(flash):#x} bytes, expected the full 1 MB image")
    if len(iram) > 0x48000:
        sys.exit(f"make_stock_elf: {args.iram} is larger than IRAM")
    elf, n_loc, n_glob = build(flash, iram, load_functions(args.functions),
                               load_api_header(args.api_header))

    out = args.out.resolve()
    out.parent.mkdir(parents=True, exist_ok=True)
    if out.parent == (ROOT / "out").resolve():
        ign = out.parent / ".gitignore"
        if not ign.exists():
            ign.write_text("# generated build output (make_stock_elf.py, link examples) - never commit\n*\n")
    out.write_bytes(elf)
    print(f"wrote {out} ({len(elf)} bytes, {n_loc} local + {n_glob} global symbols, "
          f"sha256 {hashlib.sha256(elf).hexdigest()[:16]}...)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
