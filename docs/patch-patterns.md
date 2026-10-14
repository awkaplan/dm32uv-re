# Patch patterns: hook and splice techniques, in one place

This doc collects the patch techniques this repo has built and tested. Until now they were spread
across `tools/examples/`, the Snake example (`tools/examples/snake/`), the three subsystem docs
and `tools/include/dm32_patch_api.h`. Each pattern below covers: **when** to use it, the
**shape** (real snippets, with the file they come from), the **failure** it avoids (the real
incident), and **how to check it under QEMU**. Each pattern links to the doc that explains the
mechanism in full. Read that doc before relying on an address here.

All addresses are for DM32.00.01.048 at load base `0x03000000` (see `dm32_patch_api.h`'s header).
Calling convention is C-SKY ABIv2: arguments in r0-r3, the 5th and later on the stack, return
value in r0, return address in r15.

## Index

1. [Hook after the prologue, never at the first instruction](#1-hook-after-the-prologue-never-at-the-first-instruction)
2. [Re-entrancy guard word](#2-re-entrancy-guard-word)
3. [`bsr` vs `br`, range limits, and trampolines that re-execute displaced instructions](#3-bsr-vs-br-range-limits-and-trampolines-that-re-execute-displaced-instructions)
4. [Case-block stubs for jump tables](#4-case-block-stubs-for-jump-tables)
5. [Appending to a visibility list / adding a menu category](#5-appending-to-a-visibility-list--adding-a-menu-category)
6. [Blocking screen handlers](#6-blocking-screen-handlers)
7. [Placing state in RAM](#7-placing-state-in-ram)
8. [Placing code in flash](#8-placing-code-in-flash)
9. [Verify stock bytes, stage sectors, keep emulator-only patches off the radio](#9-verify-stock-bytes-stage-sectors-keep-emulator-only-patches-off-the-radio)
10. [Resolved contradictions](#10-resolved-contradictions)
11. [Check `r15` liveness before every `bsr` hook](#11-check-r15-liveness-before-every-bsr-hook)
12. [`bsr` to an absolute address assembles to nothing: call stock functions by name](#12-bsr-to-an-absolute-address-assembles-to-nothing-call-stock-functions-by-name)

The QEMU loop that every "verify" step below uses is build → `compose_qemu_image.py` →
`qemu_run.py` → `render_frames.py` (plus `gdb_rsp.py` and `pc_histogram.py` when something
hangs). See `docs/qemu-workflow.md` and the worked command lines in `tools/examples/snake/README.md`.

---

## 1. Hook after the prologue, never at the first instruction

**When:** any time you redirect a stock function into your own code with a `bsr`.

**Shape** (`tools/examples/overlay_trampoline.S`, hooking `display_draw_string_gb2312` @`0x03018998`):

```
03018998:  d814   push  r4-r11, r15    <- NOT hooked
0301899a:  3514   subi  r14, r14, 84   <- NOT hooked
0301899c:  4b6d   mov   r5, r2         <- displaced (re-executed here)
0301899e:  8175   zexth r6, r0         <- displaced (re-executed here)
030189a0:  ...                          <- resume point (= r15 after our bsr)
```

The 4 bytes at `0x0301899c` become one 32-bit `bsr` to the trampoline. The trampoline returns with
`jmp r15` to `0x030189a0`.

**Failure it avoids:** at a function's entry point, the caller's return address exists only in
r15. A `bsr` there overwrites r15 before the displaced `push ... r15` can save it. The re-executed
push then saves the trampoline's return address instead, and the epilogue "returns" into the
function's own body. The first overlay attempt did exactly this. Under emulation, the boot stalled
before the first text draw (`overlay_trampoline.S` header, `tools/examples/README.md` gotcha 1).
Once the hook sits after the push, r15 is already on the stack and the `bsr` may clobber it.

**Check under QEMU:** `tools/examples/build_overlay_image.py` writes `flash_overlay.bin` with the
ALPU bypass already applied. Boot it and confirm the standby screen draws, with the banner on top.
If the boot stalls before the first text draw, suspect the hook position. Run
`pc_histogram.py` over a `-d exec,nochain` trace to see where execution is stuck
(`docs/qemu-workflow.md`, "Debugging under QEMU").

## 2. Re-entrancy guard word

**When:** the hooked function can be reached again while your code is running. This happens if
your code calls it, or calls a helper that does. The overlay hooks the string-draw primitive and
then draws a string itself.

**Shape** (`tools/examples/overlay_trampoline.S`):

```asm
    .equ GUARD,       0x18007FE0
    .equ GUARD_MAGIC, 0x4F564C59    /* "OVLY" */
    ...
    lrw     r12, GUARD
    lrw     r0, GUARD_MAGIC     /* r0 is saved at entry and restored at .Lskip */
    ld.w    r3, (r12, 0)
    cmpne   r3, r0
    bf      .Lskip              /* word == MAGIC: already inside, run the function normally */
    st.w    r0, (r12, 0)        /* take the guard */
    ...                         /* new behaviour, which re-enters the hooked function */
    lrw     r12, GUARD
    movi    r3, 0
    st.w    r3, (r12, 0)        /* release the guard */
.Lskip:
```

**Failure it avoids:** without the guard, the nested call fires the hook again and recurses
(`tools/examples/README.md` gotcha 2).

**Where the word lives:** `0x18007FE0`, inside the SRAM scratch window (pattern 7). No live
capture ever verified it (section 10, item 12), and on real hardware the window holds power-on
noise: the one full live SRAM capture reads `0x140b32b9` there. That is why the guard tests for
an exact magic value instead of "non-zero": noise matches the magic with probability about
2^-32, so no initialisation is needed. (The earlier non-zero test would have skipped the banner
forever on that radio; under QEMU, with the guard preset to `0x140b32b9`, the old trampoline drew
nothing and the magic-value one draws the banner, 2026-10-10.) Limitation: if the overlay is
abandoned mid-draw (a fault, or a warm reset that keeps SRAM), the word stays at the magic value
and the overlay stays off until it is cleared. It is already taken by the overlay, so a second
guard needs its own word.

**Check under QEMU:** `tools/examples/build_overlay_image.py` writes `flash_overlay.bin` with the
ALPU bypass already applied. Boot it and confirm the standby screen draws, with the banner on top.
If the boot stalls before the first text draw, suspect the hook position. Run
`pc_histogram.py` over a `-d exec,nochain` trace to see where execution is stuck
(`docs/qemu-workflow.md`, "Debugging under QEMU").

## 3. `bsr` vs `br`, range limits, and trampolines that re-execute displaced instructions

**When to use which** (`tools/src/dm32_patch_tools/build_patch.py` docstring):

| instruction | size | reach | use |
|---|---:|---|---|
| `br16` | 2 B | ±1 KB | stock-internal short branches only (the stock OK stubs; `snake_ok_stub.S` explains why a patch cannot copy them) |
| `br` (32-bit) | 4 B | ±64 KB | chaining a fallthrough inside an already-hooked dispatcher to a nearby handler |
| `bsr` (32-bit) | 4 B | ±64 MB | the first hook into a stock function, redirected to a handler in free flash |
| `lrw rX, addr` + `jmp rX` | 2 + 2 B + 4 B pool | any | going back from free flash to stock code (both Snake stubs) |

Free flash at `0x030e8000` sits roughly 350 KB from the menu epilogues, which is too far for
`br16` or `br32`. Every return from patch code into stock code therefore uses an absolute
`lrw` + `jmp` (`snake_ok_stub.S`, `snake_tail_stub.S`). The Snake build's `encode_br16()` range
assertion is what caught this (`build_snake_patch.py`).

**Encoding trap:** a 32-bit CK803S instruction is stored as two little-endian halfwords, with the
**opcode halfword first**. It is not one little-endian word. Getting this backwards hung the radio
once (`build_patch.py` docstring). Use `encode_branch()` from `build_patch.py`, or the copy in
`build_snake_patch.py`, and never encode a branch by hand.

**Trampoline shape, case A: displace real instructions and re-execute them**
(`overlay_trampoline.S`). Save the live argument registers, do your work, restore them, then emit
the displaced instructions byte for byte and jump back:

```asm
    ld.w    r15, (r14, 0)       /* = 0x030189a0, the resume point */
    addi    r14, r14, 24
    .short  0x6d4b              /* 0301899c: mov r5, r2 */
    .short  0x7581              /* 0301899e: zexth r6, r0 */
    jmp     r15
```

Registers r0-r3 are still live at that site: the hooked function's arguments, read by the
displaced `mov r5, r2`. The display primitives the overlay calls clobber them, so the trampoline
saves them. Watch for calls with five arguments: `display_draw_string_gb2312` takes its 5th
argument (background colour) on the stack. Leaving that slot unset painted a brown band coloured
`0x89a0`, the low half of the trampoline's own saved r15 (`overlay_trampoline.S`).

**Trampoline shape, case B: replace a tail branch and re-do it absolutely**
(`snake_menu_append_trampoline.S`). The stock bytes at `0x03049dcc` are `a3 05 00 00`, which is
`br16 0x304a112 ; bkpt` (`HOOK_MENU_APPEND_ORIG` in `build_snake_patch.py`). The 2-byte branch plus
the 2-byte padding after it become one 4-byte `bsr`. The trampoline does its work, then takes the
original branch itself:

```asm
snake_menu_append:
    ld.h    r3, (r4, 0)      /* re-read the cursor -- same as every stock append block does */
    movi    r2, 10           /* Snake's new top-level item index */
    str.b   r2, (r5, r3 << 0)
    addi    r3, 1
    st.h    r3, (r4, 0)
    lrw     r3, EPILOGUE     /* 0x0304a112, the original br16's target */
    jmp     r3
```

The trampoline never returns through r15. Before reusing a register, read the real instructions
in front of the hook site. This trampoline's header records that r3, r4 and r5 hold the cursor,
the cursor pointer and the buffer base there.

**Check under QEMU:** run an exec trace and confirm the trampoline address actually executes.
`tools/examples/snake/README.md` reports it running once per menu build. Before building, also
disassemble the hook site with `cs_disasm.py` to confirm what you are displacing.

## 4. Case-block stubs for jump tables

**When:** you add a slot to a stock jump table that the code reaches with `jmp16 a3` (a tail
jump), not `jsr`. In the top menu, all three per-category tables work this way
(`docs/menu-system.md`, "The category jump tables hold CASE BLOCKS, not functions"):

| table | consumer | holds | shared tail |
|---|---|---|---|
| render `0x030aff74` | `menu_screen_render_entry_variant` @`0x0303d8c8` | case blocks inside the consumer | `0x0303d872` |
| item `0x030aff18` | `main_menu_render_and_field_edit_dispatch` @`0x0303cdf0` | case blocks inside the consumer | `0x0303d872` |
| OK `0x030afef0` | dispatch @`0x0303cd98` | 6-byte stubs `bsr handler; br16 0x0303cde6` | `0x0303cde6` |

**Shape** (`tools/examples/snake/snake_tail_stub.S`; `snake_ok_stub.S` is the same with
`OK_EPILOGUE`):

```asm
snake_tail_stub:
    bsr     HANDLER          /* a normal C function */
    lrw     r3, EPILOGUE     /* 0x0303d872, supplied by ld --defsym */
    jmp     r3
```

r3/a3 is free at this point because the dispatcher's `jmp16 a3` has already used it. The stub
calls your C function, then jumps into the tail that pops the enclosing frame:
`bsr main_menu_screen_dispatch; addi16 sp,4; pop16 l0-l2,lr`.

**Failure it avoids (Snake v10 → v11):** v10 put plain C functions in slot 10 of the render and
item tables. Each one returned with its own `pop lr` and left the dispatcher's frame on the
stack on every UI pass. The radio did not crash: it livelocked. The exec-trace histogram showed
16.3M translation blocks in 10 s, with `memset_bytes` at 8.4M and
`menu_screen_render_entry_variant` called about 13k times. The category entry was re-running about
1,300 times a second. The RAM state afterwards was correct, so the data was never the bug
(`HISTORY.md`, v11). Lesson recorded there: before you point a stock jump-table slot at new code,
disassemble that table's stock entries and see how they end.

**The address gotcha that comes with this pattern** (`CLAUDE.md` gotchas 1-2,
`docs/menu-system.md` "Gotchas"):

- A table "address" taken from Ghidra or the decompiled C (`PTR_PTR_xxxxx`, `_LAB_xxxxx`) is
  usually the **literal-pool slot** that holds the table's base, not the table itself. Disassemble
  the `lrw` before the indirect jump, read the 32-bit value stored in the slot, then read the
  table from that value. The Snake build repoints exactly these slots: `0x0303da48` (render),
  `0x0303cda8` (OK) and `0x0303cf18` (item). Before writing, it asserts that each slot still holds
  the stock table base (`build_snake_patch.py`, `SLOT_*_PTR` / `SLOT_*_OLD`).
- Searching the raw image for a table base as a 4-byte value also finds coincidental matches in
  unrelated literal pools. To find real callers, compare every `bsr`'s *computed* target with the
  entry address. A string search does not do this.
- `zext rd, rs, msb, lsb` extracts an inclusive bit range: `zext32 a1, a1, 6, 6` is one bit.

**Extending a table means relocating it:** copy the ten stock entries verbatim into free flash,
append yours, repoint the literal-pool slot, and raise the `cmphsi16` bound check by one. Raw
bytes `09 3a` (`cmphsi16 a2, 0xa`) → `0a 3a` (`cmphsi16 a2, 0xb`) at `0x0303da02`, `0x0303cd8e`
and `0x0303ced8` (`build_snake_patch.py`; the encoded field is the compare value minus one, see
section 10 item 3).

**Check under QEMU:** navigate onto the new slot, then capture an exec trace and run
`pc_histogram.py --map ... --top 20`. A livelock shows up as a few stock functions dominating the
histogram while the screen never settles.

## 5. Appending to a visibility list / adding a menu category

**When:** adding a top-level menu category. Read the full chain in `docs/menu-system.md` first.
For the complete recipe, follow `build_snake_patch.py` rather than this summary.

**The pieces** (all in `tools/examples/snake/build_snake_patch.py`):

1. **Visibility append:** a `bsr` over `menu_option_gen_idx23`'s final `br16` at `0x03049dcc`,
   into the trampoline shown in pattern 3, case B. These generator functions are packed flash with
   no slack, so a hook is required and an in-place edit is not possible (`docs/menu-system.md`).
2. **Label arrays:** the renderer indexes `*(u32*)(array_base + row_index*4)` with **no bound
   check of its own**. The two 10-entry label arrays (`0x030b7d68` lang0, `0x030b7d90` lang1) are
   relocated to 11-entry copies. Their header entries at `0x030b7db8` / `0x030b7dc0` are repointed,
   and the count byte goes from `0xa` to `0xb`. The first build skipped this and showed a garbled
   screen, because row 10 read the header's own pointer field as a string (`build_snake_patch.py`
   docstring, item E).
3. **Three jump tables plus three bound checks**, as described in pattern 4.
4. **Category entry:** fill the sub-list cells, clamp the visible row count, and build the index
   list. This is `snake_category_entry.c`:

```c
    active_item_count = count;
    active_option_ptr_array = *(const unsigned int *)desc;
    active_screen_subtype = desc[5];
    active_visible_rows = (count < MAX_VISIBLE_ROWS) ? count : MAX_VISIBLE_ROWS;
    build_sequential_index_list(count, active_index_list, active_index_list + 2);
```

**Failures it avoids:**

- **Stale visible-rows bound.** `display_list_with_icons_renderer` loops on `0x0003e8f4`, not on
  the item count. Coming from the 8-item APRS list, the loop ran 8 passes over Snake's 1-entry
  array. It then dereferenced `0xFFFFFFFF` as a string and hung in the middle of a draw, as
  measured with a hardware RAMDUMP (`snake_category_entry.c`).
- **Copying another category's call without knowing what it does.** `0x03012b0c` was assumed to
  be "screen_build_and_repaint". It is `device_telemetry_report_build`, category 8's text builder,
  and it fed the v10 livelock (`HISTORY.md` v11; `docs/menu-system.md` recipe step 5).
- **Claiming a screen mode.** In v1-v5, `ui_set_screen_mode()` never produced the event `0x2a`
  that the screen-mode dispatcher needs, so the screen never ran (`snake_category_entry.c`
  header). Snake presents a normal one-item sub-list instead. `docs/menu-system.md` used to
  recommend the screen-mode route; it no longer does (section 10, item 1).

**Known limitation:** `menu_option_gen_idx23` reaches its epilogue through four exits, and only
the final `br16` is hooked. A radio that takes one of the three early `bez` exits (`0x03049d8a`,
`0x03049db0`, `0x03049dbc`) will not show the category (`tools/examples/snake/README.md`).

**Check under QEMU:** use the Snake README key script. Press Menu, then Down ×10 (or Up ×1 with no
codeplug) to reach the new row, then OK. Expected frame fingerprints: main menu about
13300–14300 non-black pixels, sub-list 9472 (`docs/qemu-workflow.md`, "Reading the results").

## 6. Blocking screen handlers

**When:** your screen has to own the keypad and the UI task until the user leaves it, as a game
does. Snake v11 drew one frame and returned. On hardware, the stock list screen kept running, so
the arrow keys navigated out of it (`snake_game.c` v12 comment, `HISTORY.md` v12-v14).

**Shape:** the loop body from `tools/examples/snake/snake_game.c`, using names from
`tools/include/dm32_patch_api.h`:

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
        ...                                     /* step, draw only what changed */
        os_time_dly_ms(FRAME_MS);
    }
```

Each line has a reason, and each reason is a real incident:

| rule | failure without it | source |
|---|---|---|
| **Park the stock poll** (`0x18000800 = 0`, counter `0x0003e395 = 0`, every frame) | The stock `keypad_poll_and_dispatch_key_event` @`0x03013744` ran about 12k TBs during the game loop and corrupted the game's own scans (the "K:xx" overlay read mostly `0x00`) | `HISTORY.md` v12, v14 |
| **Hold the bus semaphore `0x00039344` only around the scan**, never across a `display_*` call | Every LCD primitive pends the same semaphore, and uC/OS-III semaphores are not recursive. v13 held it for the whole loop and self-deadlocked on the first draw (QEMU r36) | `HISTORY.md` v13; `dm32_patch_api.h` |
| **`lcd_bus_restore_after_keypad_scan()` (`0x0301cad0`) after every scan, before the next LCD write** | The scan sets `IO_DIPLEX2 \|= 0xfe00`, handing the shared pads to GPIO. v21 on hardware drew one frame and then froze white until power-cycled | `HISTORY.md` v22; `CLAUDE.md` gotcha 0; `docs/keypad-input.md` |
| **Deferred Back hand-off:** set cur = Back and prev = 0, arm the one-shot re-enable request `0x00030790 = 1`, keep the poll disabled, and return. This is the same idiom stock uses to park the poll (`0x03059550`, `0x03022fac`) | Entering the item pushed a UI level. v17 (re-enable + re-run entry) needed two extra Backs. v19 (`write_field_and_mbox_post(2, 6)`) and v20 (immediate re-enable) were lost under the epilogue. v14-v16 left the poll dead forever because `0x00030790` was 0 | `HISTORY.md` v17-v21; `docs/keypad-input.md` "Parking the stock poll" |
| **Restore the sub-list cells before returning** (re-run the category entry) | The item-OK path zeroes `ACTIVE_VISIBLE_ROWS` on the way in | `dm32_patch_api.h` menu cells; `docs/menu-system.md` "What entering an item does to UI state" |

Use the measured scan codes from `dm32_patch_api.h` / `docs/keypad-input.md`: Up `0x02`, Down
`0x05`, Ok `0x03`, Back `0x06`. Through v14, the constants were really '1', '2', '3' and Ok
(`HISTORY.md`, scan-code map).

**Check under QEMU:**

- The board model forces LCD data to white while the mux is wrong, so a missing restore now shows
  up in emulation too (`docs/qemu-workflow.md`).
- Run the Snake README key script and confirm that four direction changes produce game frames
  (about 1138-1175 px), that **one** Back gives the sub-list with its title (9472 px), and that a
  second Back gives the main menu. Verified in runs r69, r71 and r75 (`HISTORY.md`,
  `tools/examples/snake/README.md`).
- If input looks wrong, keep a "K:xx"-style readout of the raw scan code on screen (`draw_scan_code`
  in `snake_game.c`), and check `pc_histogram.py` for `keypad_poll_and_dispatch_key_event`
  running during your loop.

## 7. Placing state in RAM

**Rule: a range that reads zero is not free.** Empty ready-list slots, NULL pointers and unused
stack all read as zero (`placement_scan.py` docstring).

**Failure it avoids (Snake v15 → v16):** the game's `.bss` was placed at IRAM `0x00042cb1` because
it read zero in the live dump. The linker put the state at `0x00042cb4`, over live kernel words
`0x42cb4..0x42cc8` (statistics-task counters, and `0x42cc0`, read by IRAM scheduler code at
`0x10b08`), just above `OSPrioHighRdy` `0x00042ca8` and `OSTCBHighRdyPtr` `0x00042cac`. Moving it
was right. Whether the overlap caused the r38 `pc=0`, `sp=0xfffffffc` freeze is a separate
question: a rebuild with that placement ran without crashing under the fixed emulator, so the
since-fixed emulator bug is the better-supported cause (section 10, item 13). The v9 trace markers
at `0x42c80` sat in the same kernel area.

**Where state goes:** the SRAM scratch window `0x18004c00`–`0x18008000`
(`PATCH_SRAM_SCRATCH_LO`/`_HI` in `dm32_patch_api.h`). It is the only RAM region that passed all
three checks: no literal reference from flash or IRAM (the highest is `0x18004bfc`), nothing
referenced within the margin, and zero across a boot → menu → game session under QEMU
(`docs/rtos-and-memory.md`). The zero reading is a QEMU artefact (the loader `sram.bin` is
zero-filled). On a real radio nothing initialises the window and it holds power-on noise, so
initialise everything you keep there. Already allocated inside it:

| range | owner |
|---|---|
| `0x18007000`–`0x1800730f` | Snake `.bss` (`snake_game.ld`) |
| `0x18007fe0` | overlay `GUARD` (`overlay_trampoline.S`) |
| `0x18007ff0` | RAMDUMP cursor |

What is left: `0x18004c00`–`0x18007000` and `0x18007310`–`0x18007fe0` (`docs/rtos-and-memory.md`).
No IRAM region has been found free (same doc).

**Shape:** put `.bss` there from the linker script (`snake_game.ld`):

```
    .bss 0x18007000 : { *(.bss) *(COMMON) }
```

**Check:**

- Statically: `python3 placement_scan.py --lo <lo> --hi <hi>`, adding `--sram <capture>` or
  `--iram <capture> --iram-is-live` if you have a live capture. Treat a `clear` verdict as the
  best static evidence available, not as proof (`placement_scan.py` docstring).
- Under QEMU: after a full boot → menu → your-screen session, run `gdb_rsp.py mem <lo> <len>`. The
  Snake window was read back this way (r39, `snake_game.ld`). A run that ends with `pc=0`,
  `sp=0xfffffffc` and `epc` in `OSSched` is the signature of the now-fixed emulator PSR bug
  (`docs/rtos-and-memory.md`, "The emulator CPU-model bug"). A kernel-object collision could in
  principle end the same way, but the one tested (Snake's old placement) did not reproduce it on
  the fixed emulator (section 10, item 13).

## 8. Placing code in flash

**Where:** the only erased program-flash space is `0x030e1000`–`0x030fffff`, sectors 225-255
(`docs/rtos-and-memory.md`). Already allocated inside it:

| range | owner |
|---|---|
| `0x030e1000`–`0x030e1fff` | RAMDUMP / live-RAM probe handler; `build_overlay_image.py` also places its trampoline at `HANDLER = 0x030E1000` |
| `0x030e8000`–`0x030e9fff` | Snake code and tables |

Still unallocated: `0x030e2000`–`0x030e7fff` (24 KB) and `0x030ea000`–`0x030fffff` (88 KB).
**Sector 225 is claimed twice.** `build_overlay_image.py` links its trampoline at
`HANDLER = 0x030E1000`, and every live-RAM probe variant is a whole-sector handler at
`0x030E1000` (`meta/patch_sites.json`: `megaprobe-handler`, `audioprobe`, `pllprobe`, …). Writing
either one overwrites the other's code, so as built the overlay and the RAMDUMP probe cannot be
on a radio at the same time. Relinking the overlay into `0x030e2000`–`0x030e7fff` would fix that.

**Never use:**

- The per-unit sector `0x0300b000`–`0x0300bfff` (sector 11). It holds the eFuse-derived binding
  record at `+0x10c` and per-unit hardware bytes. It reads `0xFF` in every shipped image only
  because the images are scrubbed. An erased-scan therefore reports it, and that report is wrong.
  `build_patch.py` refuses it (`data/firmware/patching/README.md`, `docs/rtos-and-memory.md`).
- `0x030c6000` (ALPU bypass sector), and anything listed in
  `data/firmware/patching/occupied_regions.json`. That includes the IRAM load image and its
  trailer, which lie beyond the end of the update file.
- `data/firmware/DM32.00.01.048.bin` as an erased-check base. It is truncated at `0xd2100`. Use
  `progmem_stock_DP570UV_20260926_FULL.bin` instead.

**Shape:** force the entry function to come first, and assert it did (`snake_game.ld`,
`build_snake_patch.py`):

```
    .text 0x030e8000 : {
        *(.text.snake_screen_handler)
        *(.text*)
    }
```

Compile with `-ffunction-sections`. After linking, read the entry symbol with `nm` and assert it
landed at the planned address. Give every blob its own range and assert they don't overlap
(`place()` in `build_snake_patch.py`).

**Failures it avoids:**

- GCC emitted `place_food` first, so the table pointed at the wrong function: "screen never
  transitions, then freezes" on hardware (`snake_game.ld` comment).
- v12's 1112-byte handler at `0x030e8000` ran over `snake_category_entry` at `0x030e8400`, which
  overwrote its literal pool. QEMU showed a wild jump to `0x0010ec22` (`HISTORY.md` v12).

**Check:** `require_erased()` passes for every blob against the full image. After editing any doc
that names a free range, run `check_doc_claims.py` (`docs/rtos-and-memory.md`). Under QEMU, a
`pc` far outside flash and IRAM right after entering your code points to an overlap or a
mislinked entry.

## 9. Verify stock bytes, stage sectors, keep emulator-only patches off the radio

**Assert expected bytes immediately before every write** (`CLAUDE.md` gotcha 4). Do not rely on
remembering an earlier check. Both example builders do this:

```python
def require_bytes(img, addr, expected, label):
    off = addr - FLASHBASE
    got = bytes(img[off:off + len(expected)])
    if got != expected:
        sys.exit(f"{label} @ {addr:#x}: expected {expected.hex()}, got {got.hex()} -- "
                 f"hook site doesn't match (already patched, or wrong stock image)")
```

(`build_snake_patch.py`; `build_overlay_image.py` checks `HOOK_ORIG = 4b 6d 81 75` and the erased
handler region in the same way). Check all of these:

- the hook bytes;
- every bound-check byte pair;
- every literal-pool slot's current value;
- every stock table entry your relocated copy reuses;
- that every placement range is erased.

`build_patch.py` (`make build-patch ... HOOK_BYTES=<hex>`) also enforces that at most
`4 + len(handler)` bytes differ from stock.

**Stage only the changed sectors:** `stage_sectors.py --patched ... --stock ... --out ...` writes
each changed 4 KB sector, hashes it and prints a command template. It never flashes. The Snake
patch touches six sectors: `0x0303c000`, `0x0303d000`, `0x03049000`, `0x030b7000`, `0x030e8000`
and `0x030e9000` (`HISTORY.md` v11). Never flash a whole image. The shipped images carry a blanked
per-unit sector, and flashing one would overwrite the radio's own binding record
(`data/firmware/patching/README.md`).

**Emulator-only patches never reach a radio.** `compose_qemu_image.py` applies three patches, each
guarded by a stock-bytes assertion:

- the ALPU-MP bypass (sector `0xC6000`);
- auto power-off (`0x1BDE0`);
- the hardware-binding record (`0xB10C`).

`stage_sectors.py` refuses those three sector offsets unless `--allow-qemu-only` is passed
(`compose_qemu_image.py` and `stage_sectors.py` docstrings). Build your patch against the plain
full stock image and compose the QEMU image as a separate output. Never stage the composed image.

**A caveat on `verify_patch.py`'s dynamic PASS:** `qemu_boot_diff.py` boots without splicing the
ALPU bypass. A PASS therefore proves only that roughly the first 7000 flash transfers were
unchanged before the ALPU halt at `0x169d4` (`CLAUDE.md`, "CORRECTED 2026-10-09"). For a real
behavioural check, use the compose → `qemu_run.py` → `render_frames.py` loop.

**Flashing is always a manual, human-run step on a radio with a verified full backup.** No tool
in this repo writes to hardware (`CLAUDE.md` "Safety").

---

## 10. Resolved contradictions

These thirteen conflicts turned up while collecting the patterns above. On 2026-10-10 each was
checked against primary evidence: disassembly of the full stock image with `cs_disasm.py`, a
brute-force scan of every `bsr`/`br`/`bt`/`bf` target in it, the Snake sources and a rebuild of
them, and QEMU runs with gdb breakpoints in `dm32uv-re-pipeline:qemufix3`. The losing source was
corrected in each case. Item 13 is only partly settled. One verdict per item, then the evidence.

1. **Screen-mode handler vs. sub-list plus blocking loop: the sub-list wins.** The screen-mode
   dispatcher (`screen_mode_static_table_dispatch` @`0x0305279c`, formerly `history_entry_confirm_or_cancel`) has exactly one caller, the `bsr`
   at `0x030408ee`, reached only by the `bf16` at `0x0304073e` when the UI event code is `0x2a`.
   It also returns unless arm byte `0x0003ea30` is 1. Writing the mode byte never runs it, which
   matches the v1-v5 hardware RAMDUMP. It indexes `table + mode*12` (no `- 1`, `0x030527d4`).
   *Fixed:* `docs/menu-system.md` ("Adding a new top-level category" steps 3-4, recipe step 5, the
   screen-mode section), the `snake_game.c` header and old handler comment, and the
   `build_snake_patch.py` docstring.
2. **Which task runs the stock poll: a different task from the screen handler.** QEMU gdb
   breakpoints during a Snake game showed the game's scan (lr `0x030e805c`) running with
   `OSTCBCurPtr = 0x0003e4fc`, the task "task menu" (entry `0x03040a80`, which loops
   `ui_event_code_dispatch_main`). They showed the poll (lr `0x03013a32`) running with
   `0x00040da0`, "task init" (entry `0x03068688`, which loops `main_ui_background_task_loop`).
   Names, TCBs and entries come from the `OSTaskCreate` literal pools at `0x03035f0c` and
   `0x030dddd4`. *Fixed:* the `snake_game.c` v12 comment, plus `docs/menu-system.md`, which named
   `ui_event_flag_dispatch_loop` (not the handler's task).
3. **Bound notation: `09 3a` is `cmphsi16 a2, 0xa`.** `cs_disasm.py --addr 0303cd80` prints
   `[093a] cmphsi16 a2, 0xa`, so the encoded field is the compare value minus one. The patch's
   `0a 3a` is `cmphsi16 a2, 0xb`. *Fixed:* `docs/menu-system.md` recipe step 3, which had the raw
   field ("9 → 10").
4. **OK stub: `bsr` + `lrw` + `jmp`, 12 bytes.** The built image at `0x030e9050` disassembles as
   `bsr 0x030e8800; lrw a3,[0x030e9058] (= 0x0303cde6); jmp16 a3`. *Fixed:* the Snake README and
   the `build_snake_patch.py` comments (`SNAKE_OKSTUB_ADDR`, the OK-stub block). *Still wrong:*
   the build's summary `print` says `br16 ->`. That is code, so it was left alone.
5. **`0x00030790` is a one-shot "re-enable later" request.** The blanking stub `0x03013494`
   returns if the word is 0. Otherwise it counts `0x0003e395`, and on the 21st blank poll it
   clears the counter, **clears `0x00030790`** and writes `0x18000800 = 1`. Stock sets the word
   exactly as Snake does: `0x03059550` and `0x03022fac` store `0x18000800 = 0`, then
   `0x00030790 = 1`. The enable word is `0x18000800`. *Fixed:* `docs/rtos-and-memory.md` debug
   table, `docs/keypad-input.md`, `dm32_patch_api.h` comment, plus a `HISTORY.md` note.
6. **Shared pads: GPIOC 7..11, the lines the scan drives.** In the HR_C7000 v2.7 datasheet
   (§4.4.4.6), `IO_DIPLEX2[15:9]` are `lcd_db4_sel..lcd_db0_sel`, and setting them selects
   `GPIO_PTC11..PTC7`. The scan drives those pins (`0x47..0x4b`) and reads GPIOB 17..20 from
   `0x14100050`. The dedicated exits read pins `0x34`/`0x33` (GPIOB 20/19) with every driven
   line high, returning 7/4. The arrows are matrix keys `0x02`/`0x05` on GPIOC 11. The loop
   drives GPIOC 7..12, but the table at `0x03081f1c` has keys for 7..11 only (20 bytes, then
   ASCII). *Fixed:* `docs/keypad-input.md` (hardware structure, table note, key-injection field
   meanings, the injection example, which used '2'/'1' for Up/Down, and the key-repeat section).
7. **Exit: use the deferred re-arm, not an immediate re-enable.** v21/v22 are the only exits
   tested good. v17 (immediate re-enable) needed two extra Backs, and v20 lost the Back
   (`HISTORY.md`). Apart from boot and the firmware-update loop, no stock code writes
   `0x18000800 = 1` except the blanking stub. Immediate re-enable is untested from other entry
   paths. *Fixed:* `docs/menu-system.md`, `docs/keypad-input.md`, `dm32_patch_api.h`.
8. **Semaphore timeout: 0 (wait forever).** The wrapper `0x0300c500` passes `(ms+9)/10` ticks
   to `OSSemPend` and returns the OS error code. All 21 stock pends on `0x00039344` pass 0. With
   50 ms and the return value ignored, the old example would go on to scan without holding the
   bus after a timeout. *Fixed:* `docs/keypad-input.md` lock pattern, plus notes in
   `docs/rtos-and-memory.md` and `dm32_patch_api.h`.
9. **Hardware-binding "patch": a data value, not a NOP.** `compose_qemu_image.py` (`HWBIND_*`)
   writes `ff 18 ff ff` over `ff ff ff ff` at file offset `0xB10C`. That is the eFuse-derived
   record in the scrubbed per-unit sector (`scrub_unit_sector.py` docstring), and no instruction
   changes. *Fixed:* `docs/qemu-workflow.md`.
10. **`--gc-sections`: not used and not needed.** `build_c_with_ld()` compiles with
    `-ffunction-sections` and links `ld -T snake_game.ld -e <entry>` without `--gc-sections`.
    The entry comes first because of `*(.text.snake_screen_handler)`. The nm assertion proves
    it. *Fixed:* `docs/rtos-and-memory.md` linking step 2 (and its ARM `objcopy` example).
11. **Case stubs restore nothing.** A stub is `bsr; lrw a3; jmp16 a3`. The stock tail at
    `0x0303d872` is `bsr 0x0303b6c4; addi16 sp,4; pop16 l0-l2,lr`, and it is the tail that pops
    the frame. *Fixed:* the `docs/qemu-workflow.md` pitfall.
12. **Guard `0x18007FE0`: never verified on hardware, and not zero on hardware.** The
    trampoline's original comment claimed only "zero in sram.bin", which is the zero-filled QEMU
    loader image. The one full live SRAM capture from a real radio (RAMDUMP 2026-09-29, sha256
    `2d68e001…`; not shipped, see `docs/live-ram-capture.md`) shows `0x18004c00-0x18007fff` as power-on noise (13,277 of 13,312 bytes
    non-zero), with `0x18007fe0 = 0x140b32b9` and the RAMDUMP cursor at `0x18007ff0`. That means
    no stock code uses the window, but the guard is non-zero at boot. The overlay skips its
    banner while the guard was non-zero, so on that radio it would never have drawn.
    Snake does not depend on zero-init. *Fixed:* `docs/rtos-and-memory.md`,
    `docs/live-ram-capture.md`, `snake_game.ld`, `dm32_patch_api.h`, pattern 2 above, and (same
    day) the trampoline itself, which now tests for a magic value; `tools/examples/README.md`
    gotcha 2 and the `overlay_trampoline.S` header now state the real provenance. QEMU with the
    guard preset to `0x140b32b9`: old trampoline 0 banner pixels, new one 3600 of 3801. Not yet
    run on hardware.
13. **Cause of the QEMU r38 hang: open, leaning to the emulator bug.** The old `.bss` (`s` at
    `0x00042cb4`) did overlap live kernel words `0x42cb4..0x42cc8`, though not
    `OSPrioHighRdy`/`OSTCBHighRdyPtr`, which sit at `0x42ca8`/`0x42cac`. The current Snake was
    rebuilt out of tree with `.bss 0x00042cb1` and run on the fixed emulator. It survived 260 s
    of play with 27 direction changes. With `len` then forced to 12, so the body array rewrote
    `0x42cc0..0x42cc7` every step, it ran another 120 s. Neither run crashed. That supports
    `HISTORY.md` v16(c) (emulator PSR bug) over `snake_game.ld`'s causal claim, which is now
    marked unproven. *To settle:* run the exact v15 sources (the r38 image) on the fixed
    emulator.

**Also checked: the overlay and the RAMDUMP probe share flash `0x030E1000` (sector 225).**
`build_overlay_image.py` has `HANDLER = 0x030E1000`, and every probe variant in
`meta/patch_sites.json` is a whole-sector handler at `0x030E1000`. They overwrite each other and
cannot be installed together as built (pattern 8, `docs/rtos-and-memory.md`).

**Snake rebuilt byte-identical after these comment edits:** an out-of-tree
`build_snake_patch.py` run reproduces `progmem_SNAKE_patched.bin` exactly.

## 11. Check `r15` liveness before every `bsr` hook

**When:** replacing a window inside a stock function with a `bsr` to your stub.

**Rule:** a `bsr` overwrites `r15`. It is only safe if the stock function has already saved `r15`
(a `push ... r15` prologue) or has already clobbered it with calls of its own on every path to the
window. A leaf-style function that ends in `jmp r15` with no push has `r15` live for its whole
body. There, use an in-place edit that fits the window (a same-size instruction) or a jump that does
not write `r15`.

**Failure it avoids:** `channel_type_mode_settings_write` @0x0304c68c has no prologue push. A
patch that hooked it with a `bsr` stub passed every unit test of the stub, but the patched image
booted to a "Voltage" screen and never reached standby. The fix was a 2-byte in-place
`lsri r2,r3,1` instead of a call.

**Check under QEMU:** always boot the patched image to the standby frame (`qemu_run.py` and
`render_frames.py`, expect about 4433 non-black pixels and `F5:4437` frame signatures), not just
unit-test the stubs. Isolated stub tests cannot see a clobbered return address.

---

## 12. `bsr` to an absolute address assembles to nothing: call stock functions by name

**When:** writing a stub or hook in C-SKY assembly that calls a stock function.

**Shape:** name the stock function. Use `bsr fd6818b_reg_write` (the symbol is defined by `PROVIDE(fd6818b_reg_write = 0x0002c2f4)`
in `tools/link/dm32_stock_symbols.ld`), not `bsr 0x0002c2f4`, and not an `.equ` absolute symbol followed by `bsr`:

```
    bsr     fd6818b_reg_write        ; right: resolved at link time from dm32_stock_symbols.ld
    bsr     0x0002c2f4               ; wrong: the bsr is silently not emitted
    .equ    FD_WRITE, 0x0002c2f4
    bsr     FD_WRITE                 ; also wrong, same result
```

**Failure it avoids:** the assembler silently emits nothing for a `bsr` whose operand is an absolute address or an
`.equ` absolute symbol. The stub then has fewer instructions than it looks like, so every later instruction and
every later offset is shifted. Nothing reports an error. Name the stock function instead, so the link resolves it, and
check the assembled bytes (`objdump -d`) for the expected `bsr` count before writing the stub into a sector.

**Status:** reported from the 2026-10-15 build of dm32uv-unleashed. It was not re-run in this pass, because the
C-SKY toolchain copy in the firmware tree is a Linux binary and this host could not execute it.

**Check:** `objdump -d` the assembled stub and confirm each call site is a `bsr` to the intended address, then boot the
patched image to the standby frame under QEMU (section 11).

## Additions 2026-10-20 (from dm32uv-unleashed hardware results)

Source project: dm32uv-unleashed (not published). These are patch-technique notes from its hardware runs.

- **Use a paging helper for FD6818 registers above 0x7F.** Write `REG_7FH = 1`, access the register, then write `REG_7FH = 0`; a bare `fd6818b_reg_write` to 0x9B did nothing (v23-v29). Source: `patches/unleashed_ui/unl_aprsrx.c` lines 43-58 (`fd6818_p1_read` / `fd6818_p1_write`).
  **CORRECTION 2026-10-22 (hardware, dm32uv-fh):** the REG_7FH page switch did NOT reach page 1 through stock's 3-wire helpers. With `WRITE(0x7F,1)` / access / `WRITE(0x7F,0)` around each access, a read of "REG_9AH" returned low byte 0x50 in every run, which is page-0 REG_1AH (the band register, 0x2f50 for 370-560 MHz, FD6818 guide p.24). Writing "REG_9AH" with its low byte cleared left the receiver unable to lock, as a mis-banded REG_1AH would. "REG_96H" read 0x00 both before and after writing 6 to its low bits, and "REG_87H" read 0 throughout. So accesses above 0x7F alias to page-0 `reg & 0x7f` even with paging. No working page-1 access is known on this radio. Do not write a page-1 register this way: it overwrites a live page-0 register (0x96 to 0x16, 0x9A to the band register 0x1A, 0x9B to 0x1B). Source: hardware notes of dm32uv-fh (a frequency-hopping patch by the same author, not published), dumps c0/c1/c2 of 2026-10-22.
- **Calibrate timer counts against a UART, not the timer name.** TIMER.CH[0] LoadCount is not 10 ms: 40 bytes at 115200 take 3.472 ms, and the minimum of six runs gives ~83300 counts/ms (single runs ranged 83302..87162). Source: `patches/unleashed_ui/unl_beacon.c` lines 5-16 and 274-305.
- **Do not key per-bit tone changes on one generator.** Changing REG_71H per 833 us bit ramps for ~1 ms and erases the tones; running two generators and switching only gains works. Source: `docs/afsk-tx.md` "Hardware results 2026-10-16, captures 4-8".
