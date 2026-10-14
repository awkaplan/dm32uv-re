# Patch cookbook: "I want to X" → read, do, traps, verify

Goal-indexed recipes for the common patch asks, cross-referenced against the real docs and worked
examples rather than paraphrased. Each recipe lists the **minimal reading set** (pattern numbers
refer to `docs/patch-patterns.md`), the **commands**, the **traps** (real incidents, with their
pattern numbers and `tools/examples/snake/HISTORY.md` version numbers), and how to **verify** with
exact QEMU commands and frame fingerprints.

Background for every recipe: `CLAUDE.md` (standing gotchas 0-4), `tools/include/dm32_patch_api.h`
(every stock primitive, with addresses), and `docs/qemu-workflow.md` (the build-run-render loop).
All addresses are for DM32.00.01.048 at load base `0x03000000`; calling convention is C-SKY ABIv2
(r15 = return address).

---

## 1. Add a top-level menu category

**Read first (minimal):** `docs/menu-system.md` ("Adding a new top-level category, end to end" and
"Adding an 11th category — the proven recipe"); `docs/patch-patterns.md` patterns **4** (case-block
stubs) and **5** (appending to a visibility list); `tools/examples/snake/README.md` and
`HISTORY.md`; the multi-site manifest `tools/examples/snake/snake.patch.json`.

**Do it** (the Snake path — every step is proven; follow `build_snake_patch.py`, not this summary):

```sh
# scaffold an out-of-tree patch, or copy the snake manifest and sources as a template
python3 tools/src/dm32_patch_tools/new_patch.py snake --dest /tmp/mysnake

# build the manifest (byte-exact expectations on every byte it overwrites)
docker run --rm -v "$(git rev-parse --show-toplevel)":/repo -w /repo \
    dm32uv-re-pipeline -c 'python3 tools/src/dm32_patch_tools/build_manifest_patch.py \
    tools/examples/snake/snake.patch.json --out /tmp/snake_out \
    --compare tools/examples/snake/progmem_SNAKE_patched.bin'
```

The five pieces (pattern 5): (1) a `bsr` hook over `menu_option_gen_idx23`'s final `br16` at
`0x03049dcc` appending your category's index to the visibility buffer; (2) the two 10-entry label
arrays (`0x030b7d68` lang0, `0x030b7d90` lang1) relocated to 11-entry copies with their header
entries repointed and the count byte `0xa` → `0xb`; (3) the three jump tables plus three bound
checks relocated and extended (recipe 7); (4) a category entry that fills the sub-list cells and
builds the index list (`build_sequential_index_list`); (5) a one-item sub-list whose item slot runs
your screen (recipe 4).

**Traps:**

- **Plain C functions in jump-table slots → livelock, not crash.** v10 put functions in the render
  and item tables; the radio re-ran the slot ~1,300×/s (16.3M TBs in 10 s in the exec trace,
  `memset_bytes` dominating). Slots must be case-shaped stubs that tail-jump into the shared
  epilogue (pattern 4; `HISTORY.md` v11).
- **A table "address" from Ghidra/decompiled C is usually the literal-pool slot** holding the
  table base, not the table. Disassemble the `lrw` before the indirect jump and read the stored
  32-bit value (`CLAUDE.md` gotchas 1-2; pattern 4).
- **The bound-check encoding is compare-value minus one.** `09 3a` is `cmphsi16 a2, 0xa`; the
  patch's `0a 3a` is `cmphsi16 a2, 0xb`. Change the raw bytes at `0x0303da02`, `0x0303cd8e` and
  `0x0303ced8`, not a written "9 → 10" (pattern 4, section 10 item 3; `docs/menu-system.md`).
- **Do not call `0x03012b0c`.** It is `device_telemetry_report_build` (category 8's text builder),
  not a generic repaint — it fed the v10 livelock (pattern 5; `HISTORY.md` v11).
- **Do not use `ui_set_screen_mode()`.** Setting the mode byte never runs the screen-mode
  dispatcher (it runs only on UI event `0x2a`); Snake v1-v5 froze on hardware (pattern 5, section
  10 item 1; `docs/menu-system.md` "The screen-mode dispatch").
- **The visibility hook covers only one of four exits.** `menu_option_gen_idx23` reaches its
  epilogue `0x0304a112` through four exits; only the final `br16` at `0x03049dcc` is hooked, so a
  radio that takes an early `bez` exit shows no category (pattern 5 "Known limitation").

**Verify:**

```sh
cd tools/src/dm32_patch_tools
python3 compose_qemu_image.py --patched ../../examples/snake/progmem_SNAKE_patched.bin \
    --out /tmp/snk/boot.bin --iram-out
python3 qemu_run.py --image /tmp/snk/boot.bin --iram /tmp/iram.bin --sram /tmp/sram.bin \
    --rundir /tmp/snk/run --until-step 11 --settle-after 25 --timeout 500 \
    --keyseq="-1:0:1:31:0:20;-1:0:1:17:20:120;2:11:1:17:60:400;2:7:1:17:60:400;2:7:1:17:60:600;2:11:1:18:150:500;2:8:1:20:150:500;2:11:1:17:150:500;2:8:1:18:150:500;2:10:1:17:150:900;2:10:1:17:150:900"
python3 render_frames.py --rundir /tmp/snk/run --last 8 --out /tmp/snk/snake.png
```

Fingerprints (`docs/qemu-workflow.md` "Reading the results"; `snake/README.md`): main menu
~13300–14300 non-black pixels, SNAKE sub-list **9472**, game frames ~1138–1175. `tests/test_image_snake.py`
asserts the exact token sequence.

---

## 2. Wrap or redirect one stock function call

**Read first (minimal):** `docs/patch-patterns.md` patterns **1** (hook after the prologue), **3**
(`bsr` vs `br`, encoding), **11** (r15 liveness), **12** (call stock by name);
`tools/templates/new_patch/README.md.tmpl` (the scaffold's TODO hook); `tools/README.md`
"Building a patch" (`build_patch.py` single-hook path).

**Do it:**

```sh
# scaffold: a call-site redirect handler + linker script + manifest with a TODO hook
python3 tools/src/dm32_patch_tools/new_patch.py my_wrap

# single hook into one sector (build_patch.py) — asserts the stock bytes before writing
python3 tools/src/dm32_patch_tools/build_patch.py --handler my_handler.S \
    --stock-sector sector.bin --sector-base 0x030e1000 --hook-addr 0x030e100c \
    --expect-hook-bytes 08ea0000 --hook-kind bsr --out modded_sector.bin
```

The scaffolded handler calls the stock callee **by name** (the link resolves it from
`tools/link/dm32_stock_symbols.ld` — e.g. `bsr lcd_bus_restore_after_keypad_scan`), then does its
own work. Worked example of a proven hook site: `0x0301375c` in
`keypad_poll_and_dispatch_key_event` is `bsr 0x0301cad0`, stock bytes `00 e0 ba 49`.

**Traps:**

- **Never hook the first instruction of a function.** A `bsr` there overwrites r15 before the
  displaced `push ... r15` saves it; the epilogue then "returns" into the function's own body.
  Hook after the prologue (pattern 1; `tools/examples/README.md` gotcha 1). The overlay example
  hooks `0x0301899c`, two instructions into `display_draw_string_gb2312`.
- **Check r15 liveness first.** A `bsr` is only safe if the stock function has already saved or
  clobbered r15 on every path to your window. A leaf-style function with no `push` has r15 live
  for its whole body: `channel_type_mode_settings_write` @`0x0304c68c` booted to a "Voltage"
  screen when hooked with a `bsr` stub; the fix was a 2-byte in-place `lsri r2,r3,1` (pattern 11).
- **`bsr` to an absolute address assembles to nothing** — the stub then has fewer instructions
  than it looks like and every later offset shifts, with no error. Name the stock function so the
  linker resolves it (pattern 12).
- **A 32-bit CK803S instruction is two little-endian halfwords with the opcode first**, not one
  little-endian word. Use `encode_branch()` from `build_patch.py`/`build_snake_patch.py`, never a
  hand-encoded branch (pattern 3).
- **Verify the exact stock bytes at the hook site immediately before writing**, in the build
  itself (`CLAUDE.md` gotcha 4; pattern 9's `require_bytes`).

**Verify:**

```sh
cd tools/src/dm32_patch_tools
python3 compose_qemu_image.py --patched modded_sector.bin --out /tmp/t/boot.bin --iram-out
python3 qemu_run.py --image /tmp/t/boot.bin --iram /tmp/t/iram.bin --sram /tmp/t/sram.bin \
    --rundir /tmp/t/run --until-step 2 --keyseq="-1:0:1:17:20:120;2:7:1:17:60:300"
python3 render_frames.py --rundir /tmp/t/run --last 4 --out /tmp/t.png
```

Boot to the standby frame (expect about 4433 non-black pixels and `F5:4437` frame signatures,
pattern 11). **Isolated stub unit tests cannot see a clobbered return address** — always boot the
patched image. `make -C tools verify-patch SECTOR=out.bin OFFSET=0xE1000` runs the single-sector
check (corpus pre-flight + optional QEMU boot-diff).

---

## 3. Draw an overlay on stock screens

**Read first (minimal):** `docs/patch-patterns.md` patterns **1** and **2**;
`tools/examples/README.md` (the overlay section, both gotchas); `tools/examples/overlay_trampoline.S`
and `tools/examples/build_overlay_image.py`.

**Do it** — copy the overlay example and edit the banner:

```sh
python3 tools/examples/build_overlay_image.py --out /tmp/ovl/boot.bin --iram-out
cd tools/src/dm32_patch_tools
python3 qemu_run.py --image /tmp/ovl/boot.bin --iram /tmp/ovl/iram.bin --sram /tmp/ovl/sram.bin \
    --rundir /tmp/ovl/run --timeout 110 --stall-seconds 1000
python3 render_frames.py --rundir /tmp/ovl/run --last 1 --out /tmp/ovl/last.png
```

The trampoline is spliced with a `bsr` at `0x0301899c` (replacing the 4 bytes `4b 6d 81 75`),
re-executes the two displaced stock instructions, and jumps back. It saves the live argument
registers because the display primitives it calls clobber them.

**Traps:**

- **A hooked function that reaches itself again needs a re-entrancy guard**, or the nested call
  re-triggers the hook and recurses (`tools/examples/README.md` gotcha 2; pattern 2). The guard
  lives at `0x18007fe0`.
- **The guard is a magic value, not a zero/non-zero flag.** Real SRAM holds power-on noise
  (observed `0x18007fe0 = 0x140b32b9` in the one live capture); a non-zero test would skip the
  banner forever on that radio. The overlay tests for `0x4F564C59` ("OVLY"), so no initialisation
  is needed (pattern 2; section 10 item 12). Limitation: abandon the overlay mid-draw and the word
  stays at the magic value, keeping the overlay off until cleared.
- **`display_draw_string_gb2312` takes its 5th argument on the stack**; leaving it unset painted a
  brown band coloured `0x89a0`, the low half of the trampoline's own saved r15 (pattern 3).
- **The overlay shares flash `0x030e1000` with the RAMDUMP probe family** (whole-sector handlers
  in `meta/patch_sites.json`); as built, both cannot be on a radio at once (pattern 8; section 10).

**Verify:** boot to standby and confirm the banner draws on top of the standby screen. If the boot
stalls before the first text draw, suspect the hook position (pattern 1): run `pc_histogram.py`
over a `-d exec,nochain` trace to see where execution is stuck (`docs/qemu-workflow.md`
"Debugging under QEMU"). To reproduce hardware SRAM noise, pass `qemu_run.py --sram` a 32 KiB file
with a non-zero word at offset `0x7fe0` (e.g. `0x140b32b9`); the banner must still draw.

---

## 4. Make a blocking screen that owns the keypad

**Read first (minimal):** `docs/patch-patterns.md` pattern **6**; `docs/keypad-input.md`
("Parking the stock poll", the lock pattern, scan codes); `tools/examples/snake/snake_game.c`;
`HISTORY.md` v12-v22 (each rule below is one of those incidents).

**Do it:** the loop body from `tools/examples/snake/snake_game.c`:

```c
for (;;) {
    *KEYPAD_POLL_ENABLE = 0;                /* park the stock poll, every frame */
    *KEYPAD_BLANK_COUNTER = 0;
    os_sem_pend_ms(LCD_KEYPAD_BUS_SEM, 0);  /* hold ONLY around the scan */
    scan = keypad_scan_and_map_pressed_key();
    lcd_bus_restore_after_keypad_scan();   /* give DB0..DB4 back to the panel */
    os_sem_post(LCD_KEYPAD_BUS_SEM);
    if (scan == SCAN_BACK) {
        snake_category_entry_fn();          /* restore the sub-list cells */
        *STOCK_KEY_CUR  = SCAN_BACK;        /* deferred Back hand-off */
        *STOCK_KEY_PREV = 0;
        *KEYPAD_BLANK_REARM = 1;
        *KEYPAD_BLANK_COUNTER = 0;
        *KEYPAD_POLL_ENABLE = 0;
        break;                              /* the stub's tail redraws the sub-list */
    }
    ...
    os_time_dly_ms(FRAME_MS);
}
```

The five rules, each with the incident that produced it (pattern 6):

| rule | failure without it | source |
|---|---|---|
| **Park the stock poll** (`0x18000800 = 0`, counter `0x0003e395 = 0`, every frame) | The stock `keypad_poll_and_dispatch_key_event` @`0x03013744` ran ~12k TBs during the game loop and corrupted the game's own scans (the "K:xx" overlay read mostly `0x00`) | `HISTORY.md` v12, v14 |
| **Hold the bus semaphore `0x00039344` only around the scan**, never across a `display_*` call | Every LCD primitive pends the same semaphore; uC/OS-III semaphores are not recursive. v13 held it for the whole loop and self-deadlocked on the first draw (QEMU r36) | `HISTORY.md` v13; `dm32_patch_api.h` |
| **`lcd_bus_restore_after_keypad_scan()` (`0x0301cad0`) after every scan, before the next LCD write** | The scan sets `IO_DIPLEX2 |= 0xfe00`, handing the shared pads to GPIO. v21 on hardware drew one frame then froze white until power-cycled | `HISTORY.md` v22; `CLAUDE.md` gotcha 0; `docs/keypad-input.md` |
| **Deferred Back hand-off:** set cur = Back and prev = 0, arm the one-shot re-enable request `0x00030790 = 1`, keep the poll disabled, and return | Entering the item pushed a UI level. v17 (re-enable + re-run entry) needed two extra Backs; v19 (`write_field_and_mbox_post(2, 6)`) and v20 (immediate re-enable) were lost under the epilogue; v14-v16 left the poll dead forever because `0x00030790` was 0 | `HISTORY.md` v17-v21; `docs/keypad-input.md` |
| **Restore the sub-list cells before returning** (re-run the category entry) | The item-OK path zeroes `ACTIVE_VISIBLE_ROWS` on the way in | `dm32_patch_api.h` menu cells; `docs/menu-system.md` |

Measured scan codes: Up `0x02`, Down `0x05`, Ok `0x03`, Back `0x06` (through v14 the constants
were really '1'/'2'/'3'/'Ok' — `HISTORY.md`, scan-code map).

**Verify:** run the Snake key script (recipe 1). Four direction changes must produce game frames
(~1138–1175 px), **one** Back the sub-list with its title (**9472** px), a second Back the main
menu — verified in runs r69, r71, r75. If input looks wrong, keep a "K:xx"-style raw scan-code
readout on screen and check `pc_histogram.py` for `keypad_poll_and_dispatch_key_event` running
during your loop (pattern 6).

---

## 5. Place patch state in RAM

**Read first (minimal):** `docs/patch-patterns.md` pattern **7**; `docs/rtos-and-memory.md`
(SRAM section); `tools/src/dm32_patch_tools/placement_scan.py` docstring;
`data/allocations.json` (the claims registry).

**Do it:**

```sh
# static "is this range safe?" scan (flash + IRAM literal references)
python3 tools/src/dm32_patch_tools/placement_scan.py --lo 0x18007000 --hi 0x18007400

# put .bss there from the linker script (Snake's example):
#   .bss 0x18007000 : { *(.bss) *(COMMON) }
```

Then **declare the claim** in `data/allocations.json` and re-run
`python3 tools/src/dm32_patch_tools/gen_link_artifacts.py`; a patch that overlaps a declared claim
fails to link.

**The SRAM scratch window is `0x18004c00`–`0x18008000` (13 KB)** — the only RAM region that passed
all three checks (no literal reference from flash or IRAM — highest is `0x18004bfc`; nothing
referenced within the margin; zero across a boot → menu → game session). Already allocated inside
it (pattern 7; `docs/rtos-and-memory.md`):

| range | owner |
|---|---|
| `0x18007000`–`0x1800730f` | Snake `.bss` (`snake_game.ld`) |
| `0x18007fe0` | overlay `GUARD` (`overlay_trampoline.S`) |
| `0x18007ff0` | RAMDUMP cursor |

Left free: `0x18004c00`–`0x18007000` and `0x18007310`–`0x18007fe0`. No IRAM region has been found
free (same doc).

**Traps:**

- **A range that reads zero is not free.** Snake's state was first placed at IRAM `0x00042cb4`
  because it read zero in a live dump; it covered live kernel words `0x42cb4..0x42cc8`
  (statistics-task counters, and `0x42cc0`, read by IRAM scheduler code at `0x10b08`) just above
  `OSPrioHighRdy` `0x00042ca8` / `OSTCBHighRdyPtr` `0x00042cac` (pattern 7; `HISTORY.md` v15→v16).
  Whether that overlap caused the r38 freeze is now attributed to a fixed emulator bug, not the
  placement (section 10 item 13) — the move was still right.
- **The window reads zero under QEMU only because `sram.bin` is zero-filled.** On real hardware it
  holds power-on noise (13,277 of 13,312 bytes non-zero in the one live capture). **Initialise
  everything you keep there; never rely on a zero start value** (pattern 7;
  `docs/rtos-and-memory.md`).

**Verify:** treat a `clear` verdict from `placement_scan.py` as the best static evidence, not
proof. Under QEMU, after a full boot → menu → your-screen session, `gdb_rsp.py mem <lo> <len>`
(the Snake window was read back this way, r39). A run ending with `pc=0`, `sp=0xfffffffc` and
`epc` in `OSSched` is the signature of the fixed emulator PSR bug, not a kernel collision
(pattern 7).

---

## 6. Place patch code/tables in flash

**Read first (minimal):** `docs/patch-patterns.md` pattern **8**; `docs/rtos-and-memory.md`
(Flash program memory section); `data/firmware/patching/README.md`.

**Do it:** link `.text`/`.rodata` at a chosen address inside the only erased window
**`0x030e1000`–`0x030fffff` (124 KB, sectors 225–255)**. Force the entry function first
(`-ffunction-sections`, explicit `*(.text.<entry>)` before `*(.text*)`, then assert with `nm`), and
claim **whole 4 KB sectors** in `data/allocations.json`. Give every blob its own range and assert
they don't overlap (`place()` in `build_snake_patch.py`).

Already allocated inside the window (pattern 8):

| range | owner |
|---|---|
| `0x030e1000`–`0x030e1fff` | RAMDUMP / live-RAM probe handler; the overlay trampoline also links at `HANDLER = 0x030E1000` |
| `0x030e8000`–`0x030e9fff` | Snake code and tables |

Still unallocated: `0x030e2000`–`0x030e7fff` (24 KB) and `0x030ea000`–`0x030fffff` (88 KB).

**Traps:**

- **Sector 225 (`0x030e1000`) is claimed twice.** Every live-RAM probe variant is a whole-sector
  handler at `0x030E1000`, and the overlay links its trampoline there too; writing one overwrites
  the other. Relink one into `0x030e2000`–`0x030e7fff` to fix it (pattern 8).
- **Never use:** the per-unit sector `0x0300b000`–`0x0300bfff` (sector 11 — eFuse-derived binding
  record; reads `0xFF` only because shipped images are scrubbed); `0x030c6000` (ALPU bypass) and
  anything in `data/firmware/patching/occupied_regions.json`; and `data/firmware/DM32.00.01.048.bin`
  as an erased-check base (truncated at `0xd2100` — use
  `data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin`).
- **GCC emits functions in its own order**, not declaration order: it emitted `place_food` first,
  so the table pointed at the wrong function ("screen never transitions, then freezes" on
  hardware, `snake_game.ld` comment).
- **An oversized handler runs over its neighbour.** v12's 1112-byte handler at `0x030e8000` ran
  over `snake_category_entry` at `0x030e8400`, overwriting its literal pool; QEMU showed a wild
  jump to `0x0010ec22` (`HISTORY.md` v12).

**Verify:** `require_erased()` passes for every blob against the full image; under QEMU a `pc` far
outside flash and IRAM right after entering your code points to an overlap or mislinked entry.
After editing any doc naming a free range, run `check_doc_claims.py` (pattern 8).

---

## 7. Add a slot to a stock jump table

**Read first (minimal):** `docs/patch-patterns.md` pattern **4**; `docs/menu-system.md` ("The
category jump tables hold CASE BLOCKS, not functions").

**Do it** — extending a table means **relocating it**:

1. Copy the ten stock entries verbatim into free flash, append your case-shaped stub
   (`bsr handler; lrw r3, EPILOGUE; jmp r3` — see `tools/examples/snake/snake_tail_stub.S`).
2. Repoint the literal-pool slots to the relocated tables: render `0x0303da48`, OK `0x0303cda8`,
   item `0x0303cf18` (`build_snake_patch.py` asserts each still holds the stock base first).
3. Raise the `cmphsi16` bound by one: `09 3a` (`cmphsi16 a2, 0xa`) → `0a 3a` (`cmphsi16 a2, 0xb`)
   at `0x0303da02`, `0x0303cd8e`, `0x0303ced8`.

The three stock top-menu tables (pattern 4; `docs/menu-system.md`):

| table | consumer | holds | shared tail |
|---|---|---|---|
| render `0x030aff74` | `menu_screen_render_entry_variant` @`0x0303d8c8` | case blocks inside the consumer | `0x0303d872` |
| item `0x030aff18` | `main_menu_render_and_field_edit_dispatch` @`0x0303cdf0` | case blocks inside the consumer | `0x0303d872` |
| OK `0x030afef0` | dispatch @`0x0303cd98` | 6-byte stubs `bsr handler; br16 0x0303cde6` | `0x0303cde6` |

**Traps:**

- **The table "address" is usually the literal-pool slot holding its base.** Reading N words at
  the named address produces garbage; read the stored 32-bit value instead (`CLAUDE.md` gotchas
  1-2; pattern 4).
- **Plain C functions in slots → livelock** (recipe 1's first trap). Stubs restore nothing; the
  shared tail pops the enclosing frame (`bsr main_menu_screen_dispatch; addi16 sp,4; pop16
  l0-l2,lr`). For the OK table, `br16` (±1 KB) and `br32` (±64 KB) cannot reach `0x0303cde6` from
  free flash, so the new stub is `bsr; lrw a3, 0x0303cde6; jmp16 a3` (12 bytes, `snake_ok_stub.S`;
  pattern 4, section 10 item 4).
- **Searching the raw image for a table base as a 4-byte value** finds coincidental literal-pool
  matches; compare every `bsr`'s computed target with the entry address instead (gotcha 2).

**Verify:** navigate onto the new slot, capture an exec trace, and run
`pc_histogram.py --map ... --top 20`. A livelock shows up as a few stock functions dominating the
histogram while the screen never settles (pattern 4).

---

## 8. Capture live RAM from a real radio

**Read first (minimal):** `docs/live-ram-capture.md` (the whole file — why captures are different
from stock-derived data, and the tool's constraints).

**Do it** — a live-RAM-read patch must already be on the radio (see `meta/patch_sites.json`'s
`live-ram-hook` entry):

```sh
cd tools
python3 src/dm32_patch_tools/dm32_ramdump.py \
    --port /dev/tty.usbserial-XXXX \
    --addr 0x18000000 --size 0x8000 \
    --out ../data/firmware/live-captures/sram_18000000_0x8000.bin
```

The tool is **read-only by construction** (`dm32_cps_common.py` docstring) — running it cannot
modify the radio. `--probe` reads one chunk as a sanity check first.

**Traps:**

- **Never commit a live capture.** `data/firmware/live-captures/` is gitignored. A capture is a
  snapshot of one specific radio's runtime/config state — a different category from the
  stock-image-derived data this repo commits (`docs/live-ram-capture.md`).
- **No live IRAM capture is safe to commit either.** One once shipped on the assumption IRAM is
  boot-time code; it is, only up to `0x0002f098`. Above that is runtime state — that capture held
  a codeplug channel name and the RAM copy of a calibration-derived table. It was replaced by
  `data/firmware/IRAM_dm32.00.01.048.bin`, derived from flash via `derive_iram.py` (identical on
  every unit). Use a live IRAM capture locally, e.g.
  `placement_scan.py --iram <capture> --iram-is-live`.
- **On hardware, unused SRAM holds noise, not zeros** — everything above the SRAM init image
  (`0x18004c00` and up) is unstructured non-zero bytes. Do not expect a scratch word to start at 0.

**Verify:** a region reading all-zero (or a stable known-idle pattern) across **two independent
captures at different times** is good evidence it's unused; a single capture is only a starting
hypothesis. Feed a capture to `placement_scan.py --sram <capture>` to test a candidate range.

---

## 9. Verify a patch under QEMU

**Read first (minimal):** `docs/qemu-workflow.md` (the whole loop, what the model can/cannot
simulate, known pitfalls); `tools/README.md` "Verify" (the `verify_patch.py` verdict table).

**Do it** — the loop:

```sh
cd tools/src/dm32_patch_tools
python3 compose_qemu_image.py --patched progmem_FULL_patched.bin --out /tmp/t/boot.bin --iram-out
python3 qemu_run.py --image /tmp/t/boot.bin --iram /tmp/t/iram.bin --sram /tmp/t/sram.bin \
    --rundir /tmp/t/run --tag t --until-step 2 --keyseq="-1:0:1:17:20:120;2:7:1:17:60:300"
python3 render_frames.py --rundir /tmp/t/run --last 4 --out /tmp/t.png
```

Frame fingerprints (`docs/qemu-workflow.md` "Reading the results"): standby ~2990–4433 px (no
codeplug), main menu ~13300–14300, Snake sub-list **9472**, Snake game ~1138–1175. `qemu_run.py`
prints one `F<n>:<pixels>` token per captured frame. For a **single sector**, use
`make -C tools verify-patch SECTOR=out.bin OFFSET=0xE1000`; for a **manifest patch**,
`verify_manifest.py` (in `tools/src/dm32_patch_tools/`, if present) is the manifest-wide analogue
of `verify_patch.py`.

**Traps:**

- **`compose_qemu_image.py` applies three QEMU-only patches** (ALPU bypass, auto-power-off,
  hardware-binding) guarded by byte assertions. **Never stage the composed image** — stage the
  output of your build, not of compose (pattern 9).
- **A `verify_patch.py` dynamic PASS is weaker than it looks:** `qemu_boot_diff.py` boots without
  the ALPU bypass, so a PASS proves only that roughly the first 7000 flash transfers were
  unchanged before the deliberate halt at `0x169d4` — not full behavioural equivalence. For a real
  check, use the compose → `qemu_run.py` → `render_frames.py` loop (pattern 9; `CLAUDE.md`).
- **Watchpoints defeat TB chaining** and can mask timing-dependent bugs — re-run without them to
  confirm a crash (pattern via `docs/qemu-workflow.md` "Debugging under QEMU").
- **The one-shot docker form discards `/tmp`** when the command exits; write outputs under the
  mounted repo (`/repo/...`) or run the whole sequence in one `-c '...'`
  (`docs/qemu-workflow.md` "The workflow loop").
- **A zero-filled `sram.bin` breaks anything using the SRAM-init tables** (the AES S-box and Rcon
  live there) — `aes_block_encrypt` then returns key bytes instead of ciphertext. Build the SRAM
  image yourself if your code touches those tables (`docs/qemu-workflow.md` pitfall).

**Verify your verification:** confirm the exact token line and non-black counts, and, when the
patch is committed, that `tests/test_image_snake.py` (the golden run) still passes.

---

## 10. Share a patch without shipping vendor firmware

**Read first (minimal):** `tools/README.md` "Stage" (the BPS paragraph); the `bps_patch.py`
docstring.

**Do it:**

```sh
cd tools/src/dm32_patch_tools
python3 bps_patch.py create \
    ../../../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin my_full_patched_image.bin my.bps
python3 bps_patch.py info my.bps
python3 bps_patch.py apply <own verified backup>.bin my.bps patched.bin
```

`apply` checks the CRC32 of the whole source image and refuses unless it is byte-identical to the
image the patch was created from (so the recipient must supply their own verified backup of the
stock image). Publish the `.bps`, never a patched image — a patched image contains the whole
vendor firmware.

**Traps:**

- `bps_patch.py` **refuses the per-unit sector and the three QEMU-only sites, with no override**
  — a BPS is for real-radio changes only.
- `create` takes the **full 1 MB stock image** as its source
  (`progmem_stock_DP570UV_20260926_FULL.bin`), not the truncated update file
  `data/firmware/DM32.00.01.048.bin`.
- Neither subcommand writes to a radio.

**Verify:** `bps_patch.py info my.bps` prints the source/target CRC32s; `apply` against a
byte-identical stock image must reproduce your patched image exactly.

---

## Choosing where your patch lives

- **In-repo, `tools/patches/` (gitignored):** for work-in-progress only. `new_patch.py` scaffolds
  there by default; the builder outputs to `out/patches/<name>/`, also gitignored. Nothing that
  adds new radio behaviour ships from here.
- **Out-of-tree repo with `--extra-allocations`:** the rule from `README.md` "Scope" — this repo
  carries only stock-behaviour documentation, the corpus, the tooling and the two worked examples.
  **New radio behaviour is out of scope and belongs in a repository of its own**; the tooling
  builds such patches unchanged. Keep the patch's claims in its own allocation file (same schema
  as `data/allocations.json`), list them in the manifest's `"allocations"`, and build with
  `build_manifest_patch.py <manifest> --extra-allocations <file> --require-claims`. The linker
  script then `INCLUDE`s `dm32_patch_own_memory.ld` (generated per build from the patch's own
  claims), not `dm32_patch_memory.ld` (`tools/README.md` "Building a patch that lives outside this
  repo").
