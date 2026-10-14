# Keypad input: reading a key press from patch code

The stock matrix-scan entry point is **`keypad_scan_and_map_pressed_key` (flash `0x03013660`)**.
It is the lowest-risk way for new patch code to read input: it already handles the real hardware
complexity (GPIO pin-mux/pull-direction quirks, LCD-data-bus sharing on the row pins, scan timing)
correctly, since it's the actual, continuously-running stock routine — call it directly rather than
re-deriving GPIO bit-banging from scratch.

```c
u8 scan = keypad_scan_and_map_pressed_key();  /* see tools/include/dm32_patch_api.h */
```

Side effects: hands the LCD data pads to GPIO and drives keypad rows GPIOC 7..11 low (see
below; an older reading of this as "mutes the RF modem" was a decompiler artefact) and takes a short, fixed time per call. Snake calls it once per 40 ms frame from its
blocking loop.

## Hardware structure

The keypad is a **5×4 matrix (5 driven lines, 4 sensed lines) plus 2 dedicated early-exit reads**.
Corrected 2026-10-10 against the disassembly of `0x03013660`, its helpers `0x030135d8` (row read)
and `0x030135e4` (column drive), and the IRAM GPIO helpers `0x2c544` (clear pin) / `0x2c588` (read
pin). Pin number = bank × 32 + bit, banks GPIOA `0x14020000`, GPIOB `0x14100000`, GPIOC
`0x14110000`.

- **Driven lines ("columns" in stock-scan terms, OpenRTX's ROW0..ROW4)**: GPIOC bits 7–11, pins
  `0x47`–`0x4b`, active-low, one at a time. The scan loop actually runs six times (GPIOC 7–12),
  but only 7–11 carry keys; see the table note below.
- **Sensed lines ("rows", OpenRTX's COL_1..4)**: GPIOB bits 17–20, read together from EXT_PORT
  (`0x14100050`, bits [20:17]); all ones when idle.
- **Dedicated early exits**: with all five driven lines held HIGH, the scan reads pin `0x34`
  (GPIOB bit 20) and pin `0x33` (GPIOB bit 19) and returns `7` / `4` if one is low. These are the
  same GPIOB lines as the matrix rows, pulled low by something other than the matrix. They are
  **not** the arrow keys (identity unknown; side keys are the obvious, unverified candidate).

The driven lines share a **critical hardware gotcha**: GPIOC 7..11 are the LCD data-bus pads
DB0..DB4. `IO_DIPLEX2[15:9]` are `lcd_db4_sel`..`lcd_db0_sel`; writing 1 (or 3 for the two-bit
DB0/DB1 fields) selects `GPIO_PTC11`..`GPIO_PTC7` instead of `LCD_DB4`..`LCD_DB0` (HR_C7000 v2.7
datasheet §4.4.4.6, p.101-105). The scan function
hands them to GPIO via `IO_DIPLEX2 |= 0xfe00` (SystemControl `0x11000000 + 0x3c`, in
`keypad_scan_begin_mux_rows_drive_low` @`0x03012e14`, formerly `rf_modem_mute_during_keypad_scan`). **Any patch that calls the scan MUST call `FUN_0301cad0` @`0x0301cad0` immediately after, before any LCD write**, or the panel goes white/frozen until reboot. This function restores LCD bus ownership: `IO_DIPLEX2 &= 0xffff01ff` (the same bits the stock poll clears; the panel init `lcd_controller_power_on_init_sequence` @`0x03017d4c` clears them too with mask `0xfff80107`). **Macro: use `lcd_bus_restore_after_keypad_scan` in `tools/include/dm32_patch_api.h`.**

The shared bus is also protected by a uC/OS-III **SEMAPHORE at `0x00039344`** (wrappers `OSMutexPend_wrapper2` @`0x0300c500` = `OSSemPend(sem, (ms+9)/10)`, so `ms = 0` waits forever, and `OSMutexPost_wrapper2` @`0x0300c53c` = `OSSemPost`). Every LCD primitive AND the stock keypad poll take it. Take it only around your own scan call, never across a draw call (self-deadlock; semaphores are not recursive).

## Scan codes (MEASURED 2026-10-09 on QEMU, every matrix intersection confirmed)

Before the matrix loop the function reads the 4-bit row field (GPIOB bits 17..20): all ones means
nothing is pressed and it returns `0` at once. Otherwise it drives GPIOC 7..11 high and samples two
**dedicated** inputs: pin 0x34 (GPIOB bit 20) low returns `7`, pin 0x33 (GPIOB bit 19) low returns
`4`. Those two codes are NOT the front-panel arrows (identity unknown; the side keys are the obvious
candidate, unverified). Up and Down are ordinary matrix keys on the GPIOC 11 column:

| raw scan code | key | GPIOC column | GPIOB row |
|---:|---|---:|---:|
| `0x02` | Up | 11 | 17 |
| `0x05` | Down | 11 | 18 |

The matrix positions go through a scan loop over six GPIOC lines (7..12, driven low one at a time; the arrows sit on 11) and a lookup table at flash `0x03081f1c`, column-major, 4 bytes per driven line: index = (GPIOC bit − 7) × 4 + (20 − GPIOB bit). Only the first 20 bytes are keys (GPIOC 7..11: `10 11 12 03 | 13 14 15 09 | 16 17 18 0c | 0d 0f 0e 06 | 65 65 05 02`); the four bytes a GPIOC 12 hit would index are the start of an adjacent ASCII string (`keym…`), and GPIOC 12's pad is `LCD_DB5`, which `0xfe00` does not hand to GPIO. The physical layout groups keys by driven line:

| key | GPIOC | row | raw scan code |
|---|---:|---:|---:|
| '1' | 7 | 20 | `0x10` |
| '2' | 7 | 19 | `0x11` |
| '3' | 7 | 18 | `0x12` |
| Ok | 7 | 17 | `0x03` |
| '4' | 8 | 20 | `0x13` |
| '5' | 8 | 19 | `0x14` |
| '6' | 8 | 18 | `0x15` |
| P1 | 8 | 17 | `0x09` |
| '7' | 9 | 20 | `0x16` |
| '8' | 9 | 19 | `0x17` |
| '9' | 9 | 18 | `0x18` |
| P2 | 9 | 17 | `0x0c` |
| '*' | 10 | 20 | `0x0d` |
| '0' | 10 | 19 | `0x0f` |
| '#' | 10 | 18 | `0x0e` |
| Back | 10 | 17 | `0x06` |

Other scan codes (`0x65` = scan timeout, `0` = nothing pressed) exist but are not independently re-confirmed here. The earlier version of this table (OK=0x10, P1=0x11, P2=0x12, Back=0x03, Up=7, Down=4) was wrong: those codes are '1', '2', '3', Ok and the two dedicated pins.

## Emulator key injection

For testing patches under QEMU, the board model's `DM32_KEYSEQ` environment variable takes a sequence of key steps: `cb:cbit:rb:rbit:hold:gap;...`

- `cb` = GPIO bank of the driven line (`2` = GPIOC), or `-1` for a line forced low with no
  driven-line condition
- `cbit` = driven-line bit (7–11)
- `rb` = bank of the sensed line (always `1` = GPIOB)
- `rbit` = sensed-line bit (17–20)
- `hold` = how many row-bank reads to hold the key
- `gap` = idle reads before the next key

The board model accepts at most 32 steps per `DM32_KEYSEQ` (it logs `KEYSEQ parsed N steps`).

**Example sequence for menu navigation:**
```
DM32_KEYSEQ="2:7:1:17:20:120;2:11:1:17:20:120;2:11:1:18:20:120"
```
(Ok, Up, Down. Corrected 2026-10-10: this example previously used `2:7:1:19` / `2:7:1:20`, which
are the '2' and '1' keys.)

**Full table for all keys (row bits are offset positions, not GPIO indices):**
- Ok: `2:7:1:17:20:120`
- '1': `2:7:1:20:20:120`, '2': `2:7:1:19:20:120`, '3': `2:7:1:18:20:120`
- '4': `2:8:1:20:20:120`, '5': `2:8:1:19:20:120`, '6': `2:8:1:18:20:120`, P1: `2:8:1:17:20:120`
- '7': `2:9:1:20:20:120`, '8': `2:9:1:19:20:120`, '9': `2:9:1:18:20:120`, P2: `2:9:1:17:20:120`
- '*': `2:10:1:20:20:120`, '0': `2:10:1:19:20:120`, '#': `2:10:1:18:20:120`, Back: `2:10:1:17:20:120`
- Up: `2:11:1:17:20:120`, Down: `2:11:1:18:20:120`
- MENU from standby: `-1:0:1:17:20:120`

**Up and Down are matrix steps.** The measured table above is the one that works: Up = `2:11:1:17`, Down = `2:11:1:18`.
An earlier comment in the board model's `DM32_KEYSEQ` parser called Up and Down dedicated pins on GPIOB bits 20 and
19. That was wrong; the comment (`vendor/dm32uv-qemu/hw/gpio/dm32_gpio.c`, above `DM32_KEYSEQ_MAX`) now names the
side keys SK1/SK2 on GPIOB 19/20 as the dedicated inputs. See the Up/Down discussion in
`vendor/dm32uv-qemu/docs/key-injection.md`.

**Pin injectors.** Knob, PTT and other pins that are not matrix steps can be driven at virtual times with
`DM32_PINSEQ`, `DM32_KNOB`, `DM32_KNOB_EDGE_MS` and `DM32_PTT` (see `docs/qemu-workflow.md`, "Injecting the knob, PTT and
other pins"). The knob and PTT pin identities are hypotheses, and PTT active-low polarity is assumed.

## Parking the stock poll while a patch owns the keypad

The stock poll (`keypad_poll_and_dispatch_key_event` @`0x03013744`) runs in a separate task, "task init" (entry `0x03068688`, which loops `main_ui_background_task_loop` @`0x03013a3c`; the poll is called from `keypad_event_maybe_forward_to_dialog` at `0x03013a2e`). A patch screen handler runs in "task menu" (`docs/menu-system.md`, "Blocking screen handlers"; measured under QEMU 2026-10-10). The poll can run concurrently with your handler and interfere with input.

**To park it**: the poll's first test is `if (*(u32*)0x18000800 == 0)` → it skips scanning and runs only a blanking stub @`0x03013494` instead. That stub, disassembled:

```
if (*(u32*)0x00030790 == 0) return;          // no re-enable requested: stay parked
if (++*(u8*)0x0003e395 <= 0x14) return;      // count blank polls
*(u8*)0x0003e395 = 0;
*(u32*)0x00030790 = 0;                       // request consumed
*(u32*)0x18000800 = 1;                       // poll re-enabled (on the 21st blank poll)
```

So `0x00030790` is a one-shot "re-enable the poll later" request, not a state flag. Stock code
sets it the same way a patch does: `dtmf_quicktext_scroll_display_dispatch` @`0x03059550` and
`tx_gate_companded_audio_burst_send` @`0x03022fac` both store `0x18000800 = 0` and then
`0x00030790 = 1`. Outside the boot-time copy and the firmware-update receive loop, the blanking
stub is the only stock code that writes `0x18000800 = 1`.

To silence the stock poll for your own scan:
1. **During your input**: clear `0x18000800` and `0x0003e395` (write 0) every frame.
2. **On exit**: arm the deferred re-enable: `*(u32*)0x00030790 = 1`, `*(u8*)0x0003e395 = 0`,
   `*(u32*)0x18000800 = 0`. This is the only exit tested to work (Snake v21/v22).
   Writing `0x18000800 = 1` directly is not a safe alternative from the item-OK path: Snake v17
   and v20 did that and lost or doubled the Back (`tools/examples/snake/HISTORY.md` v17–v21).
   Writing nothing leaves the keypad dead (v14–v16).

## Keypad dispatch: how confirmed keys reach handlers

The stock poll confirms keys through a **two-scan debounce** (counters at `0x00030388 + 0x40c` and `0x00030388 + 0x40d`). Confirmed keys are stored in SRAM:

- `0x000392c4`: current key (0 = nothing)
- `0x000392c5`: previous key

**Handler dispatch table at SRAM `0x18000834`** (indexed by scan code, ~100+ entries for all codes + modifiers):
```c
if (current_key != previous_key && current_key != 0) {
    handler_table[current_key]();
    previous_key = current_key;
}
```

**Most handlers post to the UI task's mailbox** via `write_field_and_mbox_post(2, code)` @`0x03013178`. The Back handler (@`0x03014a00`) is special — it directly drives UI state.

## Key repeat and long-press (unverified)

Six scan codes feed through a **separate gated-timer dispatch** (`keypad_tmrkey_state_dispatch`, a uC/OS-III timer callback) via `keypad_tmrkey_event_post_and_close`:

- Scan code 3 → posted event 5
- Scan code 4 → posted event 0x1e
- Scan code 7 → posted event 0x1d
- Scan code 9, 10, 12 → posted events 0x15, 0x1f, 0x16

Codes 4 and 7 are the scan's two dedicated-pin early exits (GPIOB 19 / 20 low with every driven
line high), which are **not** the arrow keys; the arrows are `0x05` / `0x02`. Earlier notes
labelled events 0x1e/0x1d "Down"/"Up" on the assumption that 4/7 were the arrows, so those event
names are unverified. Code 3 is Ok, 9 is P1 and 12 (`0x0c`) is P2 per the measured table above;
code 10 (`0x0a`) does not appear in the matrix table. What the six events mean is **not
confirmed**. What the "pending action" slot does when consumed is written at runtime, not a flash constant, and was not traced further — not needed for simple directional input.

## In patch code: the keypad lock pattern

If your handler calls the scan and the stock poll might also run:
```c
os_sem_pend_ms(LCD_KEYPAD_BUS_SEM, 0);        // 0x0300c500: take semaphore 0x00039344, wait forever
u8 key = keypad_scan_and_map_pressed_key();
lcd_bus_restore_after_keypad_scan();          // 0x0301cad0: give DB0..DB4 back to the LCD
os_sem_post(LCD_KEYPAD_BUS_SEM);              // 0x0300c53c: release
```

Use timeout `0`. The wrapper passes `(ms + 9) / 10` ticks to `OSSemPend`, where 0 means wait
forever, and returns the OS error code. Every stock pend on `0x00039344` (21 call sites: the poll
and every LCD primitive) passes 0. (Corrected 2026-10-10: this example used to pass 50 ms. With a
timeout and the return value ignored, a timed-out pend would go on to scan without holding the
bus.)

See `tools/examples/snake/` for a working example of parking the poll and responding to keys from a blocking game loop.
