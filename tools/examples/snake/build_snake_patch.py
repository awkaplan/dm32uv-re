#!/usr/bin/env python3
"""Build the Snake example patch: a real, non-bypass top-level menu entry that launches a
playable Snake game, wired through the actual traced menu mechanism
(docs/subsystems/keypad-input-hal.md) rather than a hook shortcut.

Pieces assembled and spliced into the stock image (EMULATOR/offline only -- does NOT touch
hardware; see CLAUDE.md's flashing safety rules for the separate, manual, human-run step that
would come after this). REWRITTEN 2026-10-10: this docstring used to list the abandoned v1-v5
design (a screen-mode-127 handler, a relocated screen-mode table, a category entry that skipped
the sub-list). The current build, as main() below actually does it:

  1. snake_game.c           -> snake_screen_handler, a BLOCKING game loop run from the sub-list
                               item (see its own header)
  2. snake_category_entry.c -> fills the sub-list cells and builds the index list, as the stock
                               render cases do
  3. snake_tail_stub.S x2   -> case-shaped stubs (bsr handler; lrw+jmp to 0x0303d872) for slot
                               10 of the render-path and item-path tables
  4. snake_ok_stub.S        -> slot 10 of the OK-path table (bsr catentry; lrw+jmp to 0x0303cde6;
                               12 bytes -- br16 cannot reach the epilogue from 0x030e9xxx)
  5. snake_menu_append_trampoline.S -> appends category index 10 to the visibility list
  6. data: "SNAKE" / "Play" strings, the 1-entry item array, the 2x8-byte sub-list descriptor,
     three relocated 11-entry jump tables, and two relocated 11-entry top-level label arrays
     (lang0/GB2312, lang1/English) -- see E below, the piece a first build got wrong.

No screen-mode table is relocated and no screen-mode literal is repointed: that route never runs
(its dispatcher 0x0305279c is reached only on UI event 0x2a; see snake_category_entry.c).

Hook/patch sites, all verified against the real stock image before writing:
  A. 0x03049dcc (br -> epilogue, end of menu_option_gen_idx23's item-9 append) replaced with a
     bsr to snake_menu_append_trampoline.S, which appends item index 10 then jumps to the same
     epilogue the original br used.
  B. Three bound checks, raw `09 3a` (`cmphsi16 a2, 0xa`) -> `0a 3a` (`cmphsi16 a2, 0xb`):
     0x0303da02 (render path), 0x0303cd8e (OK path), 0x0303ced8 (item path), so category /
     item index 10 passes instead of falling through.
  C. Three literal-pool slots holding the jump-table bases, repointed to the relocated 11-entry
     tables: 0x0303da48 (render), 0x0303cda8 (OK), 0x0303cf18 (item).
  D. (none -- the old screen-mode-table redirect at 0x0305282c was dropped in v6)
  E. 0x030b7db8 / 0x030b7dc0 (the lang-selector header's own two 8-byte entries, each
     {ptr:u32, count:u8, byte5:u8} -- see docs/menu-system.md's corrected write-up) repointed
     from the stock 10-entry label arrays (0x030b7d68 lang0 / 0x030b7d90 lang1) to two new
     11-entry arrays carrying Snake's "SNAKE" label as index 10 in both languages, with the
     count byte bumped 0xa -> 0xb. THIS is the piece the first build of this patch omitted: the
     top-level row renderer (display_list_with_icons_renderer @ 0x03041644, reached via
     menu_field_value_screen_render_and_key_dispatch @ 0x0303b720) indexes
     *(u32*)(array_base + row_index*4) directly against this array with NO bound check of its
     own -- appending row index 10 to the visibility list without extending this array makes it
     read *(u32*)(0x030b7db8), i.e. the lang-selector header's OWN first pointer field,
     as if it were a string pointer. That is the exact, confirmed cause of the garbled screen.
     (0x030b7db8/0x030b7dc0 are each referenced from exactly one place in the whole image --
     confirmed by a raw 4-byte search against the stock binary -- so relocating the two arrays
     and repointing these two header entries is a clean, single-site redirect, the same pattern
     as D above.)

Everything else in the stock image is untouched -- no existing menu item, string, or screen
loses anything; this is pure addition plus the small, surgical redirects above.
"""
import json
import os
import struct
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))   # dm32uv-re root
HERE = os.path.dirname(os.path.abspath(__file__))
FLASHBASE = 0x03000000
STOCK = os.environ.get("DM32_STOCK_IMAGE", os.path.join(ROOT, "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"))
# Toolchain wrapper: inside this repo's docker image the csky-abiv2-elf-* tools are on PATH, so the
# wrapper is a no-op `exec "$@"`; on a host, docker/cskybuild.sh runs them in the image. Override
# with CSKYBUILD=/path/to/wrapper (anything that takes the tool name as its first argument).
CSKYBUILD = os.environ.get("CSKYBUILD", os.path.join(ROOT, "docker/cskybuild.sh"))

# --- free-flash placement (all independently verified erased in the stock backup) ----------
# v6 REDESIGN 2026-10-08: Snake now presents a normal one-item SUB-LIST, exactly like stock
# categories 8/9 do, instead of claiming a screen-mode ID. The screen-mode table relocation and
# its literal-pool redirect are GONE (see snake_category_entry.c's header for the full reasoning
# and the five hardware cycles that established it). The game handler is no longer reached from
# the screen-mode table at all; it is reached from the sub-list item.
SNAKE_HANDLER_ADDR   = 0x030e8000   # snake_screen_handler
SNAKE_CATENTRY_ADDR  = 0x030e8800   # snake_category_entry (v12: moved from 0x030e8400 -- the 1112-byte handler overran it; see place())
SNAKE_TRAMP_ADDR     = 0x030e8900   # snake_menu_append trampoline (20 bytes; v12: moved with the entry)
SNAKE_STRING_ADDR    = 0x030e9000   # "SNAKE\0" -- the top-level category label
SNAKE_ITEM_STR_ADDR  = 0x030e9010   # "Play\0"  -- the one sub-list item's label
SNAKE_ITEMARR_ADDR   = 0x030e9020   # 1-entry string-pointer array -> SNAKE_ITEM_STR_ADDR
SNAKE_SUBDESC_ADDR   = 0x030e9030   # 2x8-byte sub-list descriptor {array_ptr, count, subtype}
SNAKE_OKSTUB_ADDR    = 0x030e9050   # 12-byte OK-dispatch stub (bsr catentry; lrw+jmp OK_EPILOGUE)
SNAKE_CATJMP_ADDR    = 0x030e9060   # 11-entry render-path jump table (44 bytes)
SNAKE_OKJMP_ADDR     = 0x030e9120   # 11-entry OK-path jump table (44 bytes)
SNAKE_ITEMJMP_ADDR   = 0x030e9160   # 11-entry sub-list item-action jump table (44 bytes)
# v11 (2026-10-09): the render-path and item-path tables hold CASE BLOCKS of their consuming
# functions, not functions -- each ends in the enclosing function's own epilogue. Slot 10 of each
# therefore points at a stub of that shape (snake_tail_stub.S): `bsr <C handler>; lrw+jmp` into the
# stock tail at STOCK_CASE_TAIL (`bsr main_menu_screen_dispatch; addi16 sp,4; pop16 l0-l2,lr`),
# which both consuming functions share (identical prologues). Found under QEMU: v10's plain C
# functions in these slots returned with the frame unpopped and livelocked the UI loop.
SNAKE_RENDERSTUB_ADDR = 0x030e91a0  # render-path stub: bsr snake_category_entry; -> STOCK_CASE_TAIL
SNAKE_ITEMSTUB_ADDR   = 0x030e91b0  # item-path stub:   bsr snake_screen_handler; -> STOCK_CASE_TAIL
STOCK_CASE_TAIL       = 0x0303d872  # shared case-block tail (verified by disassembly, see .S)
SNAKE_LABELARR_LANG0_ADDR = 0x030e90a0  # relocated 11-entry lang0/GB2312 label array (44 bytes)
SNAKE_LABELARR_LANG1_ADDR = 0x030e90e0  # relocated 11-entry lang1/English label array (44 bytes)

SUBTYPE_ICON_LIST = 2   # same value both stock categories 8/9 use; routes to
                        # display_list_with_icons_renderer via 0x0303b720

# --- hook / patch sites (byte offsets verified against STOCK before any write) --------------
HOOK_MENU_APPEND   = 0x03049dcc   # br -> epilogue; replaced with bsr to the trampoline
HOOK_MENU_APPEND_ORIG = bytes([0xa3, 0x05, 0x00, 0x00])   # br 0x304a112 ; bkpt
# There are TWO category-indexed dispatches, and v1-v6 only ever patched the first one:
#   RENDER path -- menu_screen_render_entry_variant @0x0303d8c8, bound @0x0303da02,
#                  table @0x030aff74. Builds/draws the screen for the highlighted category.
#   OK/ACTION path -- @0x0303cd98, bound @0x0303cd8e, table @0x030afef0. Ten 6-byte `bsr` stubs,
#                  one per category; this is what actually runs when OK is pressed. Snake needs
#                  an 11th entry here too, or OK on its row dispatches nothing.
# Both bounds use the same encoding: the stored imm is (value - 1), so stock 0x09 disassembles as
# "cmphsi a2, 10" (verified against csky-abiv2-elf-objdump); 0x0a gives "cmphsi a2, 11".
HOOK_CATBOUND      = 0x0303da02  # render-path bound
HOOK_CATBOUND_ORIG = bytes([0x09, 0x3a])
HOOK_CATBOUND_NEW  = bytes([0x0a, 0x3a])
SLOT_CATJMP_PTR    = 0x0303da48  # literal-pool slot: render-path jump-table base
SLOT_CATJMP_OLD    = 0x030aff74

HOOK_OKBOUND       = 0x0303cd8e  # OK-path bound
HOOK_OKBOUND_ORIG  = bytes([0x09, 0x3a])
HOOK_OKBOUND_NEW   = bytes([0x0a, 0x3a])
SLOT_OKJMP_PTR     = 0x0303cda8  # literal-pool slot: OK-path jump-table base
SLOT_OKJMP_OLD     = 0x030afef0
# The ten stock OK stubs live at 0x0303cdac + i*6; each is `bsr <handler>` + `br16 <epilogue>`
# (confirmed: all ten br16s resolve to the same 0x0303cde6). The dispatch is `jmp16 a3` -- a tail
# jump -- so r15 still holds the dispatching function's return address and that shared epilogue is
# what unwinds it. The new 11-entry table reuses the ten stock stub addresses verbatim (nothing
# stock moves) and adds an 11th pointing at a stub with the same contract but NOT the same shape:
# `bsr catentry; lrw a3, OK_EPILOGUE; jmp16 a3` (12 bytes), assembled from snake_ok_stub.S by
# build_ok_stub() below, because br16/br32 cannot reach OK_EPILOGUE from 0x030e9050.
OK_STUBS_OLD = [0x303cdac + i * 6 for i in range(10)]
OK_EPILOGUE  = 0x303cde6         # where every stock stub's br16 lands (shared tail)

# A THIRD per-category dispatch: the sub-list ITEM action path, @0x0303cee4 (bound @0x0303ced8,
# table @0x030aff18). Reached once a sub-list is open; it reads the item index from 0x0003e4e8+2
# through a second remap table at 0x0003e662 and jumps to a per-category item handler. Category
# 8's entry (0x0303d2a0) is the same descriptor-copy shape as the levels above it, i.e. the whole
# menu tree is recursive. Snake's entry here is what actually LAUNCHES the game. Its 11th slot
# points at the item-path tail stub (SNAKE_ITEMSTUB_ADDR), which calls snake_screen_handler and
# then tail-jumps to STOCK_CASE_TAIL (v11; before that it pointed straight at the C function).
HOOK_ITEMBOUND      = 0x0303ced8
HOOK_ITEMBOUND_ORIG = bytes([0x09, 0x3a])
HOOK_ITEMBOUND_NEW  = bytes([0x0a, 0x3a])
SLOT_ITEMJMP_PTR    = 0x0303cf18
SLOT_ITEMJMP_OLD    = 0x030aff18
ITEM_ENTRIES_OLD = [0x303cf1c, 0x303cf68, 0x303cf70, 0x303cf78, 0x303cf80,
                    0x303cfbe, 0x303cfc6, 0x303d1b4, 0x303d2a0, 0x303d54c]

# lang-selector header entries (each 8 bytes: {ptr:u32, count:u8, byte5:u8, pad:u16}) -- the
# single indirection point for the top-level label arrays, confirmed by raw-search to have
# exactly one reference each in the whole stock image.
HDR_LANG0_ADDR = 0x030b7db8
HDR_LANG1_ADDR = 0x030b7dc0
LABELARR_LANG0_OLD = 0x030b7d68   # 10 entries
LABELARR_LANG1_OLD = 0x030b7d90   # 10 entries

CAT_ENTRIES_OLD = [0x303da4c, 0x303da9a, 0x303dae8, 0x303db72, 0x303dbf6,
                   0x303dc44, 0x303dc92, 0x303dccc, 0x303dd06, 0x303dd40]


def sh(*args):
    r = subprocess.run(args, cwd=HERE, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"command failed: {' '.join(args)}\n--- stdout ---\n{r.stdout}\n--- stderr ---\n{r.stderr}")
    return r


def build_c(src, out_elf, out_bin, link_addr, entry):
    obj = src.replace(".c", ".o")
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-O2", "-Wall", "-c", src, "-o", obj)
    sh(CSKYBUILD, "csky-abiv2-elf-ld", f"-Ttext={link_addr:#x}", "-e", entry, "-o", out_elf, obj)
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text", "-j", ".rodata", out_elf, out_bin)
    return open(os.path.join(HERE, out_bin), "rb").read()


def build_c_with_ld(src, ld_script, out_elf, out_bin, entry):
    # -ffunction-sections: each function gets its own .text.<name> section, so the linker
    # script can place `entry` first by name instead of relying on GCC's emission order (which
    # is NOT declaration order and was the exact cause of the mode-126 freeze -- see
    # snake_game.ld's own comment).
    obj = src.replace(".c", ".o")
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-O2", "-Wall", "-ffunction-sections", "-c", src, "-o", obj)
    sh(CSKYBUILD, "csky-abiv2-elf-ld", "-T", ld_script, "-e", entry, "-o", out_elf, obj)
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text", "-j", ".rodata", out_elf, out_bin)
    built = open(os.path.join(HERE, out_bin), "rb").read()
    # verify the entry symbol actually landed at the handler's expected base address -- don't
    # just trust the linker-script section ordering worked; this is exactly the kind of
    # assumption that caused the mode-126 freeze.
    r = sh(CSKYBUILD, "csky-abiv2-elf-nm", out_elf)
    sym_line = next((l for l in r.stdout.splitlines() if l.split()[-1] == entry), None)
    assert sym_line, f"{entry} symbol not found in {out_elf}:\n{r.stdout}"
    sym_addr = int(sym_line.split()[0], 16)
    return built, sym_addr


def build_asm(src, out_elf, out_bin, link_addr, entry):
    obj = src.replace(".S", ".o")
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-c", src, "-o", obj)
    sh(CSKYBUILD, "csky-abiv2-elf-ld", f"-Ttext={link_addr:#x}", "-e", entry, "-o", out_elf, obj)
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text", out_elf, out_bin)
    return open(os.path.join(HERE, out_bin), "rb").read()


def encode_branch(src, tgt, kind):
    """CK803S br/bsr encoding -- see dm32uv-re/tools/src/dm32_patch_tools/build_patch.py's own
    encode_branch() docstring for the ground-truth cases this is checked against."""
    assert (tgt - src) % 2 == 0, f"misaligned branch: src={src:#x} tgt={tgt:#x}"
    off = (tgt - src) // 2
    if kind == "br":
        assert -(1 << 15) <= off < (1 << 15), "br out of range"
        insn = 0xE8000000 | (off & 0x0000FFFF)
    elif kind == "bsr":
        assert -(1 << 25) <= off < (1 << 25), "bsr out of range"
        insn = 0xE0000000 | (off & 0x03FFFFFF)
    else:
        raise ValueError(kind)
    hw_hi, hw_lo = (insn >> 16) & 0xFFFF, insn & 0xFFFF
    return bytes([hw_hi & 0xFF, (hw_hi >> 8) & 0xFF, hw_lo & 0xFF, (hw_lo >> 8) & 0xFF])


def encode_br16(src, tgt):
    """16-bit br16: 0x0400 | (simm10 & 0x3FF), halfword-granular, little-endian.

    Ground truth from the ten stock OK stubs: the br16 at 0x0303cdb0 is bytes `1b 04` and targets
    0x0303cde6, i.e. simm10 = (0x303cde6 - 0x303cdb0) / 2 = 0x1b. Encoding 0x0400|0x1b = 0x041b
    -> little-endian `1b 04`. Matches.
    """
    assert (tgt - src) % 2 == 0, f"misaligned br16: src={src:#x} tgt={tgt:#x}"
    off = (tgt - src) // 2
    assert -(1 << 9) <= off < (1 << 9), f"br16 out of range: {off}"
    hw = 0x0400 | (off & 0x3FF)
    return bytes([hw & 0xFF, (hw >> 8) & 0xFF])


def build_ok_stub(stub_addr, handler_addr):
    """Assemble snake_ok_stub.S at stub_addr: `bsr handler` then an absolute jump to OK_EPILOGUE.

    Same contract as the ten stock 6-byte stubs (run the handler, then tail-transfer into the
    shared epilogue at OK_EPILOGUE rather than returning), but it cannot be a literal byte-copy of
    their shape: this stub sits ~350 KB from the epilogue and br16 reaches only +/-1 KB, br32
    +/-64 KB. encode_br16()'s range assertion catches that if anyone tries. See the .S file.
    """
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-c", "snake_ok_stub.S", "-o", "snake_ok_stub.o")
    sh(CSKYBUILD, "csky-abiv2-elf-ld", f"-Ttext={stub_addr:#x}",
       f"--defsym=SNAKE_CATENTRY={handler_addr:#x}",
       f"--defsym=OK_EPILOGUE={OK_EPILOGUE:#x}",
       "-e", "snake_ok_stub", "-o", "snake_ok_stub.elf", "snake_ok_stub.o")
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text",
       "snake_ok_stub.elf", "snake_ok_stub.bin")
    return open(os.path.join(HERE, "snake_ok_stub.bin"), "rb").read()


def build_tail_stub(stub_addr, handler_addr, epilogue_addr, tag):
    """Assemble snake_tail_stub.S at stub_addr: `bsr handler` then an absolute jump to epilogue_addr.

    The shape every stock render/item case block has (see the .S header): run a real function,
    then tail-transfer into the enclosing dispatcher's epilogue instead of returning. Built twice,
    for the render-path slot (handler = snake_category_entry) and the item-path slot
    (handler = snake_screen_handler); `tag` keeps the intermediate files apart.
    """
    elf, binf = f"snake_tail_stub_{tag}.elf", f"snake_tail_stub_{tag}.bin"
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-c", "snake_tail_stub.S",
       "-o", f"snake_tail_stub_{tag}.o")
    sh(CSKYBUILD, "csky-abiv2-elf-ld", f"-Ttext={stub_addr:#x}",
       f"--defsym=HANDLER={handler_addr:#x}",
       f"--defsym=EPILOGUE={epilogue_addr:#x}",
       "-e", "snake_tail_stub", "-o", elf, f"snake_tail_stub_{tag}.o")
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text", elf, binf)
    data = open(os.path.join(HERE, binf), "rb").read()
    assert 8 <= len(data) <= 16, f"tail stub {tag}: unexpected size {len(data)}"
    return data


def require_erased(img, addr, length, label):
    off = addr - FLASHBASE
    region = img[off:off + length]
    if not all(b == 0xFF for b in region):
        bad = next(i for i, b in enumerate(region) if b != 0xFF)
        sys.exit(f"{label} @ {addr:#x} is NOT erased at +{bad:#x} (got {region[bad]:#04x}) -- "
                 f"wrong address, or stock image doesn't match the one these offsets were found in")


def require_bytes(img, addr, expected, label):
    off = addr - FLASHBASE
    got = bytes(img[off:off + len(expected)])
    if got != expected:
        sys.exit(f"{label} @ {addr:#x}: expected {expected.hex()}, got {got.hex()} -- "
                 f"hook site doesn't match (already patched, or wrong stock image)")


def main():
    print(f"loading stock image: {STOCK}")
    stock = bytearray(open(STOCK, "rb").read())
    assert len(stock) == 0x100000, f"expected 1MB stock image, got {len(stock):#x}"

    # ---- 1. build all new code/data ----
    print("\n-- building snake_screen_handler --")
    handler, handler_sym_addr = build_c_with_ld(
        "snake_game.c", "snake_game.ld", "snake_game.elf", "snake_game.bin", "snake_screen_handler")
    assert handler_sym_addr == SNAKE_HANDLER_ADDR, (
        f"snake_screen_handler linked at {handler_sym_addr:#x}, not {SNAKE_HANDLER_ADDR:#x} -- "
        f"the sub-list item would invoke the WRONG function (this is exactly the 2026-10-08 "
        f"handler-aliasing bug; see snake_game.ld's comment). Fix the linker script, don't "
        f"just update this constant.")
    print(f"  {len(handler)} bytes @ {SNAKE_HANDLER_ADDR:#x} (snake_screen_handler verified first)")

    print("\n-- building snake_category_entry --")
    # snake_submenu_descriptor is resolved by --defsym to its flash address; the entry point must
    # also land exactly at SNAKE_CATENTRY_ADDR since the category jump table points straight at it.
    sh(CSKYBUILD, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-O2", "-Wall", "-ffunction-sections",
       "-c", "snake_category_entry.c", "-o", "snake_category_entry.o")
    sh(CSKYBUILD, "csky-abiv2-elf-ld", f"-Ttext={SNAKE_CATENTRY_ADDR:#x}",
       f"--defsym=snake_submenu_descriptor={SNAKE_SUBDESC_ADDR:#x}",
       "-e", "snake_category_entry", "-o", "snake_category_entry.elf", "snake_category_entry.o")
    sh(CSKYBUILD, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text", "-j", ".rodata",
       "snake_category_entry.elf", "snake_category_entry.bin")
    catentry = open(os.path.join(HERE, "snake_category_entry.bin"), "rb").read()
    r = sh(CSKYBUILD, "csky-abiv2-elf-nm", "snake_category_entry.elf")
    centry_line = next((l for l in r.stdout.splitlines()
                        if l.split()[-1] == "snake_category_entry"), None)
    assert centry_line, f"snake_category_entry symbol missing:\n{r.stdout}"
    centry_addr = int(centry_line.split()[0], 16)
    assert centry_addr == SNAKE_CATENTRY_ADDR, (
        f"snake_category_entry linked at {centry_addr:#x}, not {SNAKE_CATENTRY_ADDR:#x} -- "
        f"the category jump table's slot 10 would point at the wrong code.")
    print(f"  {len(catentry)} bytes @ {SNAKE_CATENTRY_ADDR:#x} (entry address verified)")

    print("\n-- building snake_menu_append trampoline --")
    tramp = build_asm("snake_menu_append_trampoline.S", "snake_menu_append_trampoline.elf",
                      "snake_menu_append_trampoline.bin", SNAKE_TRAMP_ADDR, "snake_menu_append")
    print(f"  {len(tramp)} bytes @ {SNAKE_TRAMP_ADDR:#x}")

    print("\n-- building string/table data --")
    snake_label = b"SNAKE\x00"
    while len(snake_label) % 4:
        snake_label += b"\x00"
    # The one sub-list item. Both languages share it (no translation needed for "Play"), the
    # same way the stock top-level arrays share the "APRS" pointer across both language runs.
    item_label = b"Play\x00"
    while len(item_label) % 4:
        item_label += b"\x00"
    item_array = struct.pack("<I", SNAKE_ITEM_STR_ADDR)
    # Sub-list descriptor, 2 x 8 bytes {u32 array_ptr, u8 count, u8 subtype, u16 pad} -- byte-for-byte
    # the layout read out of the stock GNSS (0x030b7e28) and APRS (0x030ba924) descriptors.
    sub_desc = (struct.pack("<IBBH", SNAKE_ITEMARR_ADDR, 1, SUBTYPE_ICON_LIST, 0) +
                struct.pack("<IBBH", SNAKE_ITEMARR_ADDR, 1, SUBTYPE_ICON_LIST, 0))
    assert len(sub_desc) == 16
    # Render-path table: ten stock CASE-BLOCK addresses verbatim + Snake's render stub (v11: a
    # case-shaped stub, NOT the C function -- see SNAKE_RENDERSTUB_ADDR).
    print("\n-- building render-path and item-path tail stubs --")
    render_stub = build_tail_stub(SNAKE_RENDERSTUB_ADDR, SNAKE_CATENTRY_ADDR, STOCK_CASE_TAIL, "render")
    item_stub = build_tail_stub(SNAKE_ITEMSTUB_ADDR, SNAKE_HANDLER_ADDR, STOCK_CASE_TAIL, "item")
    print(f"  render stub @ {SNAKE_RENDERSTUB_ADDR:#x}: {render_stub.hex(' ')}")
    print(f"  item stub   @ {SNAKE_ITEMSTUB_ADDR:#x}: {item_stub.hex(' ')}")
    cat_jumptable = b"".join(struct.pack("<I", a) for a in CAT_ENTRIES_OLD)
    cat_jumptable += struct.pack("<I", SNAKE_RENDERSTUB_ADDR)
    # OK-path table: ten stock STUB addresses verbatim + Snake's new stub.
    ok_stub = build_ok_stub(SNAKE_OKSTUB_ADDR, SNAKE_CATENTRY_ADDR)
    ok_jumptable = b"".join(struct.pack("<I", a) for a in OK_STUBS_OLD)
    ok_jumptable += struct.pack("<I", SNAKE_OKSTUB_ADDR)
    assert len(ok_jumptable) == 44
    # Item-action table: ten stock CASE BLOCKS verbatim (`bsr <handler>; br32 STOCK_CASE_TAIL`) +
    # Snake's item stub of the same shape. This slot is reached when OK is pressed on the "Play"
    # item inside Snake's sub-list, which is the launch path.
    item_jumptable = b"".join(struct.pack("<I", a) for a in ITEM_ENTRIES_OLD)
    item_jumptable += struct.pack("<I", SNAKE_ITEMSTUB_ADDR)
    assert len(item_jumptable) == 44

    # relocated 11-entry top-level label arrays: copy the stock 10 pointers verbatim, append
    # Snake's own string pointer (same address for both languages -- "SNAKE" has no translation).
    def read_u32_list(img, base, count):
        return [struct.unpack_from("<I", img, base - FLASHBASE + i * 4)[0] for i in range(count)]

    lang0_old_entries = read_u32_list(stock, LABELARR_LANG0_OLD, 10)
    lang1_old_entries = read_u32_list(stock, LABELARR_LANG1_OLD, 10)
    labelarr_lang0 = b"".join(struct.pack("<I", p) for p in lang0_old_entries) + struct.pack("<I", SNAKE_STRING_ADDR)
    labelarr_lang1 = b"".join(struct.pack("<I", p) for p in lang1_old_entries) + struct.pack("<I", SNAKE_STRING_ADDR)
    assert len(labelarr_lang0) == len(labelarr_lang1) == 44

    # ---- 2. verify every hook/placement site against the real stock image ----
    print("\n-- verifying hook sites against stock image --")
    require_erased(stock, SNAKE_HANDLER_ADDR, len(handler), "snake handler region")
    require_erased(stock, SNAKE_CATENTRY_ADDR, len(catentry), "snake category-entry region")
    require_erased(stock, SNAKE_TRAMP_ADDR, len(tramp), "snake trampoline region")
    require_erased(stock, SNAKE_STRING_ADDR, len(snake_label), "snake string region")
    require_erased(stock, SNAKE_ITEM_STR_ADDR, len(item_label), "snake item-string region")
    require_erased(stock, SNAKE_ITEMARR_ADDR, len(item_array), "snake item-array region")
    require_erased(stock, SNAKE_SUBDESC_ADDR, len(sub_desc), "snake sub-list descriptor region")
    require_erased(stock, SNAKE_OKSTUB_ADDR, len(ok_stub), "snake OK-stub region")
    require_erased(stock, SNAKE_CATJMP_ADDR, len(cat_jumptable), "snake category-jumptable region")
    require_erased(stock, SNAKE_OKJMP_ADDR, len(ok_jumptable), "snake OK-jumptable region")
    require_erased(stock, SNAKE_ITEMJMP_ADDR, len(item_jumptable), "snake item-jumptable region")
    require_erased(stock, SNAKE_LABELARR_LANG0_ADDR, len(labelarr_lang0), "relocated lang0 label-array region")
    require_erased(stock, SNAKE_LABELARR_LANG1_ADDR, len(labelarr_lang1), "relocated lang1 label-array region")
    require_bytes(stock, HOOK_MENU_APPEND, HOOK_MENU_APPEND_ORIG, "menu-append hook site")
    require_bytes(stock, HOOK_CATBOUND, HOOK_CATBOUND_ORIG, "category-bound-check site")
    require_bytes(stock, HOOK_OKBOUND, HOOK_OKBOUND_ORIG, "OK-dispatch bound-check site")
    require_bytes(stock, HOOK_ITEMBOUND, HOOK_ITEMBOUND_ORIG, "item-action bound-check site")
    got_catjmp_ptr = struct.unpack_from("<I", stock, SLOT_CATJMP_PTR - FLASHBASE)[0]
    assert got_catjmp_ptr == SLOT_CATJMP_OLD, f"category jumptable literal-pool slot changed: {got_catjmp_ptr:#x}"
    got_okjmp_ptr = struct.unpack_from("<I", stock, SLOT_OKJMP_PTR - FLASHBASE)[0]
    assert got_okjmp_ptr == SLOT_OKJMP_OLD, f"OK jumptable literal-pool slot changed: {got_okjmp_ptr:#x}"
    got_itemjmp_ptr = struct.unpack_from("<I", stock, SLOT_ITEMJMP_PTR - FLASHBASE)[0]
    assert got_itemjmp_ptr == SLOT_ITEMJMP_OLD, f"item jumptable literal-pool slot changed: {got_itemjmp_ptr:#x}"
    # The ten stock item handlers must still be at the addresses the new table will point to.
    for i, a in enumerate(ITEM_ENTRIES_OLD):
        got = struct.unpack_from("<I", stock, SLOT_ITEMJMP_OLD - FLASHBASE + i * 4)[0]
        assert got == a, f"stock item-table entry {i} is {got:#x}, expected {a:#x}"
    # The ten stock OK stubs must be exactly where the new table will point at them.
    for i, a in enumerate(OK_STUBS_OLD):
        expect_br = encode_br16(a + 4, OK_EPILOGUE)
        got_br = bytes(stock[a + 4 - FLASHBASE: a + 6 - FLASHBASE])
        if i < 9:   # stub 9 falls through into the epilogue instead of branching to it
            assert got_br == expect_br, (
                f"OK stub {i} @ {a:#x} tail is {got_br.hex()}, expected br16 -> "
                f"{OK_EPILOGUE:#x} ({expect_br.hex()}) -- stub layout is not what was traced")
    got_hdr_lang0 = struct.unpack_from("<I", stock, HDR_LANG0_ADDR - FLASHBASE)[0]
    assert got_hdr_lang0 == LABELARR_LANG0_OLD, f"lang0 header entry changed: {got_hdr_lang0:#x}"
    got_hdr_lang1 = struct.unpack_from("<I", stock, HDR_LANG1_ADDR - FLASHBASE)[0]
    assert got_hdr_lang1 == LABELARR_LANG1_OLD, f"lang1 header entry changed: {got_hdr_lang1:#x}"
    got_hdr_lang0_count = stock[HDR_LANG0_ADDR - FLASHBASE + 4]
    assert got_hdr_lang0_count == 0xa, f"lang0 header count byte changed: {got_hdr_lang0_count:#x}"
    got_hdr_lang1_count = stock[HDR_LANG1_ADDR - FLASHBASE + 4]
    assert got_hdr_lang1_count == 0xa, f"lang1 header count byte changed: {got_hdr_lang1_count:#x}"
    print("  all hook sites verified against stock bytes")

    # ---- 3. apply every write ----
    print("\n-- applying patch --")
    patched = bytearray(stock)

    placed = []   # (start, end, label) -- v12: overlapping placements silently corrupted the handler
    def place(addr, data):
        off = addr - FLASHBASE
        for (a, b) in placed:
            assert off >= b or off + len(data) <= a, (
                f"placement {addr:#x}+{len(data)} overlaps an earlier placement {FLASHBASE + a:#x}..{FLASHBASE + b:#x} -- "
                f"this is how v12's 1112-byte handler (0x030e8000..0x030e8458) got its literal pool overwritten "
                f"by snake_category_entry at 0x030e8400 (QEMU: wild jump to 0x0010ec22).")
        placed.append((off, off + len(data)))
        patched[off:off + len(data)] = data

    place(SNAKE_HANDLER_ADDR, handler)
    place(SNAKE_CATENTRY_ADDR, catentry)
    place(SNAKE_TRAMP_ADDR, tramp)
    place(SNAKE_STRING_ADDR, snake_label)
    place(SNAKE_ITEM_STR_ADDR, item_label)
    place(SNAKE_ITEMARR_ADDR, item_array)
    place(SNAKE_SUBDESC_ADDR, sub_desc)
    place(SNAKE_OKSTUB_ADDR, ok_stub)
    require_erased(stock, SNAKE_RENDERSTUB_ADDR, len(render_stub), "render-path tail stub region")
    require_erased(stock, SNAKE_ITEMSTUB_ADDR, len(item_stub), "item-path tail stub region")
    place(SNAKE_RENDERSTUB_ADDR, render_stub)
    place(SNAKE_ITEMSTUB_ADDR, item_stub)
    place(SNAKE_CATJMP_ADDR, cat_jumptable)
    place(SNAKE_OKJMP_ADDR, ok_jumptable)
    place(SNAKE_ITEMJMP_ADDR, item_jumptable)
    place(SNAKE_LABELARR_LANG0_ADDR, labelarr_lang0)
    place(SNAKE_LABELARR_LANG1_ADDR, labelarr_lang1)

    hook_bytes = encode_branch(HOOK_MENU_APPEND, SNAKE_TRAMP_ADDR, "bsr")
    place(HOOK_MENU_APPEND, hook_bytes)
    place(HOOK_CATBOUND, HOOK_CATBOUND_NEW)
    place(SLOT_CATJMP_PTR, struct.pack("<I", SNAKE_CATJMP_ADDR))
    place(HOOK_OKBOUND, HOOK_OKBOUND_NEW)
    place(SLOT_OKJMP_PTR, struct.pack("<I", SNAKE_OKJMP_ADDR))
    place(HOOK_ITEMBOUND, HOOK_ITEMBOUND_NEW)
    place(SLOT_ITEMJMP_PTR, struct.pack("<I", SNAKE_ITEMJMP_ADDR))
    place(HDR_LANG0_ADDR, struct.pack("<I", SNAKE_LABELARR_LANG0_ADDR))
    place(HDR_LANG0_ADDR + 4, bytes([0xb]))  # count byte 0xa -> 0xb; byte5 (0x2) left untouched
    place(HDR_LANG1_ADDR, struct.pack("<I", SNAKE_LABELARR_LANG1_ADDR))
    place(HDR_LANG1_ADDR + 4, bytes([0xb]))

    print(f"  menu-append hook: {HOOK_MENU_APPEND_ORIG.hex(' ')} -> {hook_bytes.hex(' ')}")
    print(f"  category-bound-check: {HOOK_CATBOUND_ORIG.hex(' ')} -> {HOOK_CATBOUND_NEW.hex(' ')}")
    print(f"  category-jumptable ptr: {SLOT_CATJMP_OLD:#x} -> {SNAKE_CATJMP_ADDR:#x}")
    print(f"  OK-bound-check: {HOOK_OKBOUND_ORIG.hex(' ')} -> {HOOK_OKBOUND_NEW.hex(' ')}")
    print(f"  OK-jumptable ptr: {SLOT_OKJMP_OLD:#x} -> {SNAKE_OKJMP_ADDR:#x}")
    print(f"  OK stub @ {SNAKE_OKSTUB_ADDR:#x}: {ok_stub.hex(' ')} "
          f"(bsr -> {SNAKE_CATENTRY_ADDR:#x}, lrw+jmp -> {OK_EPILOGUE:#x})")
    print(f"  item-bound-check: {HOOK_ITEMBOUND_ORIG.hex(' ')} -> {HOOK_ITEMBOUND_NEW.hex(' ')}")
    print(f"  item-jumptable ptr: {SLOT_ITEMJMP_OLD:#x} -> {SNAKE_ITEMJMP_ADDR:#x} "
          f"(slot 10 -> item stub {SNAKE_ITEMSTUB_ADDR:#x} -> snake_screen_handler {SNAKE_HANDLER_ADDR:#x})")
    print(f"  render-jumptable slot 10 -> render stub {SNAKE_RENDERSTUB_ADDR:#x} -> snake_category_entry; "
          f"both stubs tail-jump to {STOCK_CASE_TAIL:#x}")
    print(f"  lang0 label-array ptr: {LABELARR_LANG0_OLD:#x} -> {SNAKE_LABELARR_LANG0_ADDR:#x} (count 0xa -> 0xb)")
    print(f"  lang1 label-array ptr: {LABELARR_LANG1_OLD:#x} -> {SNAKE_LABELARR_LANG1_ADDR:#x} (count 0xa -> 0xb)")
    print(f"  sub-list descriptor @ {SNAKE_SUBDESC_ADDR:#x}: array={SNAKE_ITEMARR_ADDR:#x} count=1 subtype={SUBTYPE_ICON_LIST}")

    # ---- 4. sector extraction + full-image diff summary ----
    def sector(off):
        return (off // 0x1000) * 0x1000

    touched_offsets = sorted({
        SNAKE_HANDLER_ADDR - FLASHBASE, SNAKE_CATENTRY_ADDR - FLASHBASE,
        SNAKE_TRAMP_ADDR - FLASHBASE, SNAKE_STRING_ADDR - FLASHBASE,
        SNAKE_ITEM_STR_ADDR - FLASHBASE, SNAKE_ITEMARR_ADDR - FLASHBASE,
        SNAKE_SUBDESC_ADDR - FLASHBASE, SNAKE_OKSTUB_ADDR - FLASHBASE,
        SNAKE_CATJMP_ADDR - FLASHBASE, SNAKE_OKJMP_ADDR - FLASHBASE,
        SNAKE_ITEMJMP_ADDR - FLASHBASE,
        SNAKE_RENDERSTUB_ADDR - FLASHBASE, SNAKE_ITEMSTUB_ADDR - FLASHBASE,
        HOOK_ITEMBOUND - FLASHBASE, SLOT_ITEMJMP_PTR - FLASHBASE,
        SNAKE_LABELARR_LANG0_ADDR - FLASHBASE, SNAKE_LABELARR_LANG1_ADDR - FLASHBASE,
        HOOK_MENU_APPEND - FLASHBASE, HOOK_CATBOUND - FLASHBASE,
        SLOT_CATJMP_PTR - FLASHBASE,
        HOOK_OKBOUND - FLASHBASE, SLOT_OKJMP_PTR - FLASHBASE,
        HDR_LANG0_ADDR - FLASHBASE, HDR_LANG1_ADDR - FLASHBASE,
    })
    touched_sectors = sorted({sector(o) for o in touched_offsets})
    print(f"\n-- touched sectors ({len(touched_sectors)}) --")
    for s in touched_sectors:
        addr = FLASHBASE + s
        out_stock = os.path.join(HERE, f"sector_{addr:08x}_stock.bin")
        out_patched = os.path.join(HERE, f"sector_{addr:08x}_patched.bin")
        open(out_stock, "wb").write(stock[s:s + 0x1000])
        open(out_patched, "wb").write(patched[s:s + 0x1000])
        print(f"  {addr:#010x}")

    full_out = os.path.join(HERE, "progmem_SNAKE_patched.bin")
    open(full_out, "wb").write(patched)

    ndiff = sum(1 for a, b in zip(stock, patched) if a != b)
    print(f"\nwrote {full_out} ({len(patched)} bytes, {ndiff} bytes differ from stock)")
    print("Flashing is a separate, manual, human-run step -- see CLAUDE.md's safety rules.")


if __name__ == "__main__":
    main()
