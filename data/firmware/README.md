# data/firmware/

The two binaries `tools/` analyzes directly, so this repository's patch-building tooling
(`tools/`) works standalone - cloning `dm32uv-re` alone is enough to run it, with no
dependency on the upstream analysis tree this repository's generated half comes from.

| File | What it is | Load base | Provenance |
|---|---|---|---|
| `DM32.00.01.048.bin` | Flash app image (the same binary `src/`, `meta/` and `PROVENANCE.md` describe) | `0x03000000` | Read from a DM-32UV's program flash (no vendor download of this build exists), truncated at `0xd2100`, with the per-unit sector `0x0300b000` blanked (see `patching/README.md`). `PROVENANCE.md` cites `0791558d...6147`, the hash before blanking. No public redistribution license is claimed |
| `IRAM_dm32.00.01.048.bin` | IRAM image (`0x00010000`-`0x00057FFF`, 288KB) as the boot stub builds it: flash `0x030bfc20..0x030decb8` copied to `0x00010000..0x0002f098`, zeros above | `0x00010000` | Derived from `patching/progmem_stock_DP570UV_20260926_FULL.bin` by `tools/src/dm32_patch_tools/derive_iram.py`; identical on every unit. Replaced a live capture (2026-10-10) that also held one radio's runtime state |

Each `.bin` has a matching `.bin.sha256` sidecar; verify with `shasum -a 256 -c *.sha256`
before trusting a checkout.

## Load base, verified empirically - do not trust PROVENANCE.md's wording here

`PROVENANCE.md`'s "Assumed load base: 0x03001000" field names the address where CODE starts,
**not** the file's own base address. `DM32.00.01.048.bin` has a reserved 4096-byte (`0x1000`)
header (the `DH_FLAG` boot magic `"thd\x0c"` at file offset 0, the encoded load address
`0x03001000` as a little-endian u32 at offset 4, then zero padding) before real code begins at
file offset `0x1000`. So the FILE's base address - what you pass to a loader/disassembler - is
`0x03000000`, which puts that `0x1000`-byte header at `0x03000000`-`0x03000FFF` and the first
real code at `0x03001000`, matching the corpus's own function addresses.

This was confirmed by disassembling a known corpus function
(`sram_state_word_bit_clear @ 0x03001c50`) at both candidate bases: under `0x03000000` it maps
to file offset `0x1c50` and is dense, correct CK803S instructions matching the decompiled `.c`
exactly (`push {r4,r5,r15}`, parameter checks, a `bsr` to the sibling function the `.c` also
calls); under `0x03001000` it maps to file offset `0xc50`, which is all zero bytes (still
inside the reserved header).

See `tools/src/dm32_patch_tools/ghidra_project.py`'s module docstring for the same note next
to the code that uses it.
