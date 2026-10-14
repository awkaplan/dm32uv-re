# RTOS and memory layout: primitives and patch data placement

This doc consolidates the microcontroller-level facts a patch author needs: where the RTOS kernel
lives, what primitives you can call, and where to safely place your patch's state and code.

## uC/OS-III kernel map

The DM-32 runs **uC/OS-III** (a real-time, preemptive multitasking kernel) in IRAM. All addresses
below are **confirmed by reading IRAM decompiled code (2026-10-10)**. See `tools/include/` for
the standard uC/OS header definitions (e.g., `OS_TCB`).

| address | size | symbol | description |
|---:|---:|---|---|
| `0x00042500` | 4 bytes | `OSTCBCurPtr` | Pointer to current task control block |
| `0x00042508` | 1 byte | `OSPrioCur` | Priority of running task |
| `0x0004250d` | 1 byte | `OSSchedLockNestingCtr` | Scheduler lock counter (probable) |
| `0x000426d8` | 1 byte | `OSIntNestingCtr` | Interrupt nesting depth (0 = task level, 1+ = ISR level) |
| `0x000426f4` | 4 bytes | `OSTaskCtxSwCtr` | Context-switch counter |
| `0x00042ca8` | 1 byte | `OSPrioHighRdy` | Highest ready task priority |
| `0x00042cac` | 4 bytes | `OSTCBHighRdyPtr` | TCB pointer of highest-ready task |
| `0x00040e68` | 8 bytes (2 words) | `OSPrioTbl` | Bit table of ready priorities |
| `0x0004271c` | 768 bytes (64 × 12) | `OSRdyList` | Ready list (64 tasks × 12-byte node) |
| `0x00010934` | code | `OSSched` | Scheduler (context-switch entry) |
| `0x000119ec` | code | `OS_PrioGetHighest` | Find highest ready priority |
| `0x00010604` | code | `OSCtxSw` | Task-level context switch (68-byte frame: r0–r13, lr, epsr, pc) |
| `0x0001064a` | code | interrupt wrapper | Saves task sp at SRAM `0x18000bcc`; switches to IRQ stack top `0x0004b7b0` |
| `0x00045514` | code | ISR handler table | Indexed by (psr vector field − 32); see PIC interrupt map below |
| `0x00010894` | code | `OSIntEnter` | Mark entry into ISR |
| `0x000108b0` | code | `OSIntExit` | Mark exit from ISR, possibly reschedule |
| `0x0001018c` | code | `CPU_SR_Save` | `mfcr psr; clear bits 4,6; mtcr psr` (disable IRQ/exception) |
| `0x0001019c` | code | `CPU_SR_Restore` | Restore psr from register (reverse of above) |
| `0x00042300` | 512 bytes | idle task stack | Stack for idle task; top is `OSTCBCurPtr` on boot |
| `0x00041c78`–`0x00041e78` | 512 bytes | OS_IntQTask stack | Base `0x41c78`, 0x80 words (OSCfg word at flash `0x03076600`). (Corrected 2026-10-10: this range was previously written with its ends reversed; `0x00041e78` is the base of the NEXT stack in the table, see `0x0307666c`.) |
| `0x00041878`–`0x00041c78` | 1024 bytes | ISR stack (probable) | OSCfg words at flash `0x03076610`: base `0x41878`, 0x100 words, 0x400 bytes. In uC/OS-III's standard `os_cfg_app.c` field order this slot is `OSCfg_ISRStk`, not the IntQ ring (which would be base `0x40e70`, 10 entries, 0x140 bytes, words at `0x030765f4`). Field order inferred, not traced to a consumer. |
| `0x00042a44` | OS_TCB size | OS_IntQTask TCB | Priority 0; posts to `ui_event_flag_dispatch_loop` |
| `0x030765e4` | code table | `OSCfg` table | Static task stacks defined here; see decompiled `OSTaskCreate` call sites |

**Application task stacks** (user code, including the keypad poll and UI loop): allocated as
static arrays in flash tables. Find them via the `OSTaskCreate` call sites in
`src/rtos/` — the flash address of each stack is a parameter to the creation call.

## RTOS primitives: what patch code can safely call

All addresses are confirmed entry points or wrapper functions (2026-10-10):

| address | signature | purpose | notes |
|---:|---|---|---|
| `0x0300c4bc` | `void OSTimeDly_ms_wrapper(u32 ms)` | Sleep for N milliseconds | Blocks only the caller; other tasks run. Takes the millisecond count directly (not OS ticks). |
| `0x0300c500` | `OSMutexPend_wrapper2(void* sem, u32 ms)` | Acquire semaphore | Maps to `OSSemPend(sem, (ms+9)/10)` internally and returns the OS error code in r0. Returns immediately if semaphore is available; blocks otherwise with a timeout (in OS ticks ≈ 10 ms). **`ms = 0` means wait forever**, which is what all 21 stock pends on the LCD semaphore pass and what patch code should pass. Use for protecting shared hardware (LCD bus, keypad, MMIO). **0x00039344 is the LCD-semaphore address.** |
| `0x0300c53c` | `OSMutexPost_wrapper2(void* sem)` | Release semaphore | Maps to `OSSemPost(sem)`. Posts one count to the semaphore; wakes one waiting task if any. |
| `0x03013178` | `void write_field_and_mbox_post(u8 field, u8 code)` | Post key event to UI task | Field 1/3 unconditional; field 2 gated on byte `0x0003078c == 1`. Delivers `code` to `ui_event_flag_dispatch_loop`. |
| `0x03054d80` | `void event_queue_reset(void)` | Clear ISR event queue | Empties the `OS_IntQTask` ring buffer. Use before returning from a blocking game loop to discard queued events. |
| `build_sequential_index_list` @0x0304a118 | `void build_sequential_index_list(u8 count, volatile void *out_count, volatile void *out_list)` | Fill a sub-list index buffer | Writes `count` then the sequence 0..count-1; the Snake entry calls it as `build_sequential_index_list(count, 0x0003e5f8, 0x0003e5f8 + 2)` (the stock list screens pass the same buffer). |

### Do not call self-locking stock accessors under `OSSchedLock`

Several stock hardware accessors take their own semaphore. For example, `fd6818b_reg_write`
(`0x2c2f4`) and `fd6818_reg_read` (`0x2c33c`) pend on the FD6818 bus semaphore at IRAM `0x3a49c`
(literal at `0x2c384`), bit-bang, then post. Calling one with the scheduler locked breaks mutual
exclusion:

1. When the count is 0 and `OSSchedLockNestingCtr` (`0x4250d`) is non-zero, stock `OSSemPend`
   (`0x11a58`) returns at once with an error and does not take the semaphore.
2. The accessors ignore that return. They bit-bang over the holder's half-finished transfer and
   post anyway.
3. When the holder then posts, the count is 2, and every later pair of users can interleave until
   power-off.

A patch task can preempt a holder whenever it outranks it. Stock tasks that reach the FD6818
accessors include `task cds` (29), `task menu` (31), `task SqlCheck` (35) and `task ScanDisp` (38).
The accessors' own semaphore is the correct lock; just call them. Found in the dm32uv-fh
frequency-hopping patch (out of tree, not published; 2026-10-20), whose first revision did this.

### Stock task priorities

Every `OSTaskCreate` call site in the corpus, as name (priority): `OS_IntQTask` (0),
`task ShutDown` (5), `SlotTimer` (6), `keys` (7), `keyTime` (8), `task rf` (10), `task usb` (11),
`txslot` (12), `decrypt` (13), `encrypt` (14), `sysint` (17), `rxslot` (18), `task sound` (19),
`task psint` (20), `task gps` (21), `CclTraffic` (22), `rxcsbk` (23), `rxvoice` (24), `txmsg`
(25, two call sites), `rxmsg` (26), `record` (27), `task CodeSw` (28), `task cds` (29),
`task menu` (31), `Led Manage` (32), `cpchanscan` (33), `task TmrHnd` (34), `task SqlCheck` (35),
`task CallDisp` (36), `task InputAlter` (37), `task ScanDisp` (38), timer task (58, OSCfg byte at
flash `0x03076664`), stat task (60, `0x03076628`), idle (63).

**Free: 9, 15, 16 and 30**, plus anything 39–57. uC/OS-III accepts a shared priority, but
equal-priority tasks only alternate when one blocks. Pick a free priority for a patch task, and
remember that a lower number preempts every task numbered above it.

## Interrupt map and PIC sources

The HR_C7000 **Programmable Interrupt Controller (PIC)** defines 64 sources (0–63). The hardware
interrupt vector is the byte in PSR bits `[23:16]` (`cr<0,0> >> 16`, sign-extended; corrected
2026-10-20, the earlier `[15:10]` was wrong). A vector ≥ 32 maps to PIC source `vector − 32`. The
handler table at `0x00045514` is indexed directly: `handler_table[vector − 32]()`.

**Key sources for patch code:**

| PIC source | timer channel | address | purpose | notes |
|---:|---:|---|---|---|
| 1 | Timer 0 | (dispatch via PIC) | RTOS system tick (100 Hz) | Wakes the scheduler every 10 ms. Driver base: TIMER CH[0] (`0x14000000` LoadCount, `0x14000004` CurrentValue; 11.9 ns per count). Not CLK_MGR, which is at `0x11000000` (corrected 2026-10-20). |
| 2 | Timer 1 (CH[1]) | IRAM `0x0002caa4` (vector 0x22) | Stock timer ISR | Reads CH[1].EOI (`0x14000020`) and posts flag 0x80 to UI flag group `0x0003fd90`. Stock boot sets CH[1] ControlReg = 2 (disabled) and unmasks the vector. |
| 3 | Timer 2 (CH[2]) | not traced (2026-10-20) | — | Stock boot unmasks vectors 0x22–0x26, so vector 0x23 is unmasked, but no handler for it has been traced. Do not assume one. |
| 4 | Timer 3 (CH[3]) | IRAM `0x0002ca90` (vector 0x24) | Stock timer ISR | Reads CH[3].EOI (`0x14000048`) and posts flag 0x800 to UI flag group `0x0003fd90`. No stock code enables CH[3]. |
| 5 | Timer 4 (CH[4]) | IRAM `0x0002ca88` (vector 0x25) | Stock: EOI read only | Reads CH[4].EOI (`0x1400005c`) and returns. No stock code enables CH[4]. Free for patch use: an out-of-tree patch (dm32uv-fh) installs its own handler on this vector at runtime. |
| 6 | Timer 5 | IRAM `0x0002cab8` (vector 38 handler) | UI tick (10 Hz, dispatched every 10th PIC-1 interrupt) | Posts flag 1 of OS flag group `0x0003fd90` to wake `ui_event_flag_dispatch_loop`. The datasheet's Table 30 calls this channel TIMER_6 (its channels are 1-based); this doc numbers channels 0-based. |
| (other sources) | — | `0x00045514 + N*4` | General-purpose interrupts | Keypad/modem/ADC/SPI/UART etc. Not enumerated here; use `tools/include/dm32_patch_api.h` if you need to add a new ISR. |

The UI flag group at `0x0003fd90` is a uC/OS-III event-flag group. Flag 1 (mask `0x02`) triggers
a full UI redraw pass.

### Writing an interrupt handler (2026-10-20)

Entry sequence, from the common interrupt entry at IRAM `0x0001064a` (disassembled from
`data/firmware/IRAM_dm32.00.01.048.bin`):

1. Saves `r0`–`r13`, `lr`, `cr<2,0>` (EPSR) and `cr<4,0>` (EPC) on the interrupted stack, stores that
   stack pointer at SRAM `0x18000bcc`, and switches to the interrupt stack (`0x0004b7b0`).
2. Calls `OSIntEnter` (`0x00010894`).
3. Writes 4 to PIC_COW1 (`0x17000010`), the PIC end-of-interrupt. This is **before** the handler, so
   the PIC is already acknowledged when your code starts.
4. Indexes the handler table (`0x00045514`) by vector − 32 and calls the entry with `r0` = the PIC
   source number.
5. Calls `OSIntExit` (`0x000108b0`), which switches to the highest-priority ready task when the
   nesting count reaches 0.
6. Restores the stack pointer, EPC, EPSR and registers, then `rte`.

Handler contract:

- A table entry is a plain C function, `void handler(int source)`.
- Clear your own device's interrupt (for a timer, read its EOI register). The PIC is already done.
- Do not call `OSIntEnter` or `OSIntExit`; the entry sequence does.
- `OSTaskSemPost` (`0x00013664`) is allowed. While `OSIntNestingCtr` (`0x000426d8`) is non-zero it
  does not post directly: it queues the post to `OS_IntQTask` (priority 0), which runs on the way out
  of the interrupt, so the woken task is ready before any application task resumes.
- Do not call `OSTaskSemPend` (`0x00012720`) from a handler.
- OS_ERR values are stored as 32-bit words, and the codes do not follow stock uC/OS-III numbering
  (for example, `0x5e25` for a bad option).

Installing a handler:

- Use the stock function `irq_controller_unmask_and_register_handler(handler, vector)` (`0x0306cf70`).
  With interrupts disabled it writes `table[vector − 32] = handler` and clears bit `vector − 32` of
  PIC_MASK (`0x17000008`; PIC_MASK_1 `0x17000068` for vectors ≥ 0x40). In PIC_MASK, 1 = masked.
- It may be called at runtime, after boot (hardware-tested by dm32uv-fh).
- Stock sets PIC_MODE = 0 (level) for all sources at boot (`FUN_0306cfc8`). Every table slot starts
  with a default handler, filled by `irq_table_fill_and_enable_irq_0x21` (`0x0306cfe4`).
- Hardware-tested pattern (dm32uv-fh, not published): a periodic timer on CH[4], vector 0x25, whose
  handler reads the channel's EOI, then posts a waiting task's semaphore.

### Sub-tick time from patch code (2026-10-20)

Hardware-tested in dm32uv-fh's hop engine (not published).

- **TIMER CH[0]** (HR_C7000 DS section 4.8, six channels at stride `0x14`): `0x14000000` is LoadCount
  (840000), `0x14000004` is CurrentValue, a live read-only down-counter at 84 MHz (11.9 ns per
  count). It reloads every 10 ms and drives the 100 Hz uC/OS tick (PIC source 1). Patch code reads
  it and never writes it.
- **Tick counter**: the live uC/OS tick count (OSTickCtr) is the 32-bit word at IRAM
  `0x000426d0`: the running IRAM kernel's `OS_TickListInsert` @`0x000138e8` loads it
  (`lrw r2, 0x426d0; ld.w r2, (r2)` at `0x138f0`, `0x13926`, `0x13948`) to compute every
  `OSTimeDly` deadline, and `CPU_TS_TmrRd` @`0x0306ced4` returns it. **Not** `0x00016f34`: that
  is the counter of the flash copy `OS_TickListUpdate` @`0x03003978` (literal `0x03003ac8`), and
  the flash scheduler is not the one that runs (the IRAM set is; under QEMU `0x16f34` stays
  static while `0x426d0` counts). The tick task does the increment, not the ISR, so the counter
  lags a TIMER0 reload by the tick task's latency. **Which task that is, and at what priority,
  is unresolved (2026-10-20):** the flash tick-task create at `0x030037a0`-`0x030037d2` passes
  `OSCfg_TickTaskPrio` = **3** (the byte at flash `0x03001ef4`) to `OSTaskCreate` with the name
  at `0x03001e7c` "uC/OS-III Tick Task" and TCB `0x00016db8`, but under QEMU the counter at
  `0x426d0` **never advances while a task at priority 31 spins** with interrupts enabled, and
  advances normally across `OSTimeDly` sleeps (`dm32uv-fh` FH LAB: `TCK BLOCKED @31`,
  `CTR 32/32`). So the tick that the running IRAM kernel processes is handled below priority 31,
  whatever the flash copy's configuration says. Consequence for patch code: a task at 31 or above
  that is busy for N ms delays every `OSTimeDly` wake in the system by up to N ms, including
  wakes of tasks that outrank it. Confirmed on hardware (FH LAB, three runs, 2026-10-20): do not
  rely on the tick for timing while the UI may be busy; use a timer interrupt (next subsection).
- **Read the pair only after an `OSTimeDly` wake, then count reloads yourself.** Right after a wake
  the tick task has just incremented the counter, so (tick, CurrentValue) is consistent. Take that
  reading, then count reloads: a reload shows as the "microseconds into the tick" value dropping back
  to 0. Do not stamp "now" at any other moment.
- **`OSTimeDly(ticks, opt, &err)`** @`0x00013c6c`: opt 0 (`OS_OPT_TIME_DLY`) is relative (wakes at the
  counter at the call plus `ticks`); opt 8 (`OS_OPT_TIME_PERIODIC`) is periodic. `err` is written
  with a 32-bit store.
- **Sub-tick residual**: sleep to the tick before the due tick, then spin on CurrentValue for the
  rest. The engine's spin costs at most 10 ms per hop (average 5 ms) at priority 30.
- **Hardware confirmation (2026-10-20):** the tick being serviced below priority 31 is confirmed on
  hardware (FH LAB `TCK BLOCKED @31`, three runs). A patch that needs wake precision while the UI is
  busy must use a timer interrupt instead of `OSTimeDly`; see
  [Writing an interrupt handler](#writing-an-interrupt-handler-2026-10-20).

RTC facts, so the next patch does not re-derive them:

- The RTC is the SoC's internal one: an I2C slave at 7-bit `0x70` on the I2C2 controller
  (`0x14080000`), not memory-mapped. Binary registers: 0 VAL_S [5:0], 1 VAL_M, 2 VAL_H, 3/4 VAL_D_L/H,
  `0x0c`-`0x10` LOAD_S/M/H/D_L/D_H, `0x11` CCR ([2] load, [1] enable, [0] intr_en), `0x12` LOAD_VSTAT.
  1 Hz, no sub-second register, no alarm (stock never sets CCR[0] and never unmasks PIC source 19).
- `rtc_register_read(reg)` @`0x0301c2d4` is one I2C2 transaction, about 100 us at the 400 kHz the init
  programs (ESTIMATED from the register sequence, not measured). It is guarded by a uC/OS semaphore
  (through `i2c2_master_read_reg_locked` @`0x0002cea8`), with no interrupt disable and no wall-clock
  timeout. The read path's literal (IRAM `0x0002d034`) and the write path's
  (`uart_tx_poll_mutex_guarded` @`0x0002ce78`, literal `0x0002cea4`) both hold `0x0003b9f8` in
  `data/firmware/IRAM_dm32.00.01.048.bin`, so reads and writes share one semaphore (verified
  2026-10-20 from the IRAM image; not re-checked at runtime).
- Setting it: stock's `rtc_date_validate_and_write` @`0x0301c498` writes LOAD_VSTAT 0, the LOAD
  registers, LOAD_VSTAT 1, then CCR |= 4 (`rtc_register_0x11_set_bit2` @`0x0301c480`). The count
  restarts from LOAD at the CCR write. Stock sets the RTC from GPS RMC only when the decoded time
  differs (`gps_nmea_datetime_to_rtc_sync` @`0x0301265c`).

## Placing patch data: verified-free memory map

**DO NOT guess that a region is free** — memory that reads as zero during one session (e.g., IRAM
at boot) may be occupied by literals or runtime state on the next run. The tool
`tools/src/dm32_patch_tools/placement_scan.py` does a **literal scan** (searches both flash and
IRAM for every 4-byte pointer that could refer to your chosen address) and reports the nearest
cross-reference. Use it before committing to an address.

### IRAM (code/fast data; `0x00010000`–`0x00057FFF`, 288 KB total)

**Occupied by**: RTOS kernel, ISR handlers, uC/OS-III event ring, and task stacks.

**Verified free for patch state (2026-10-10)**: no literal in flash or IRAM references these
regions after a full boot → menu → game session:
- None yet identified; IRAM is densely packed. Patch code can occupy erased flash sectors, but
  fast-data state belongs in SRAM.

### SRAM (fast RAM; `0x18000000`–`0x18007FFF`, 32 KB total)

Bounds per the HR_C7000 v2.7 datasheet memory map. (Corrected 2026-10-10: this section previously
gave a 64 KB extent.)

**Occupied by**: `0x18000000`–`0x180007FF` is modem-owned (2 KB); `0x18000800`–`0x18004bfb` is the
SRAM initialised-data image the boot stub copies from flash `0x03072000` (see
`data/firmware/patching/occupied_regions.json`) — keypad poll flag, keypad handler table, LCD and
scheduler state, etc.

**Verified free for patch state (2026-10-10)**: `0x18004c00`–`0x18008000` (13 KB, `0x3400` bytes):
- Highest confirmed literal cross-reference: `0x18004bfc` (from flash `0x0300c0c8`)
- Reads zero across a full QEMU session (boot → menu → Snake game → back to menu). That is
  only because `qemu_run.py` / `compose_qemu_image.py` load a zero-filled `sram.bin`.
- **On real hardware the window is NOT zero.** The firmware never initialises it, so it holds
  power-on noise. The one full live SRAM capture from a real radio
  (RAMDUMP 2026-09-29, not shipped here; see `docs/live-ram-capture.md`) has 13,277 of the window's 13,312 bytes non-zero with no structure, and
  `0x18007fe0` reads `0x140b32b9`. That is consistent with nothing stock using the window, but a
  patch must initialise every variable it keeps there and must not assume a zero start value.
  Snake does (`reset_game()` sets its state on entry).

**Already allocated inside that window** (also listed in `tools/include/dm32_patch_api.h`,
`PATCH_SRAM_SCRATCH_LO`/`_HI`):
- **Snake game state**: `0x18007000`–`0x1800730f` (`0x310` bytes, 784 bytes; the Snake `.bss`)
- **Overlay guard word**: `0x18007fe0` (`overlay_trampoline.S` `GUARD`; does not overlap the Snake state).
  Its only provenance is "zero in `sram.bin`" (the QEMU loader image) in the
  trampoline's original comment; no live capture verified it. The one
  live capture above shows it non-zero at boot, so the guard tests for an exact magic value
  (`0x4F564C59`) rather than "non-zero", and needs no initialisation (QEMU-verified with the
  guard preset to the captured noise, 2026-10-10). The overlay has not yet run on hardware.
- **RAMDUMP cursor** (if using the live-memory-read patch): `0x18007ff0`

To use this region, place your state struct at an aligned address within `0x18004c00`–`0x18007000`
or `0x18007310`–`0x18007fe0`, and verify the placement with
`placement_scan.py --lo <your_lo> --hi <your_hi>`.

**Then declare it in [`data/allocations.json`](../data/allocations.json).** That file is the
machine-readable copy of the list above, and two tools read it: `placement_scan.py` reports a
candidate range that overlaps a declared claim as `suspect`, and `gen_link_artifacts.py` turns it
into `tools/link/dm32_patch_memory.ld`, so a patch that overlaps one fails to *link*. A static
claim like a patch's `.bss` is invisible to every other check (nothing in the stock firmware
points at it, and it is blank in any dump taken before that patch runs), so an undeclared
allocation will be reported as `clear` to the next person who scans it. The list above and that
file must agree.

### Flash program memory (`0x03000000`–`0x030FFFFF`, 1 MB total)

GD25Q80 program flash: 256 sectors of 4 KB; sector N = `(addr - 0x03000000) >> 12`. Anything at or
above `0x03100000` does not exist on this chip. (Corrected 2026-10-10: this section previously gave a
2 MB extent, wrong free-sector numbers, and claimed ~1.4 MB free. All of that was wrong; the figures below were re-checked against
`data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin`.)

**Occupied by**: the vendor update file `DM32.00.01.048.bin` (flash `0x03000000`–`0x030d20ff`),
plus regions OUTSIDE the update file that are occupied on every radio, listed with provenance in
`data/firmware/patching/occupied_regions.json`: the IRAM load image `0x030bfc20`–`0x030decb7`, its
trailing vendor data `0x030decb8`–`0x030e04bf`, and the SRAM init image from `0x03072000`. The
ALPU-bypass patch, if applied, lives in sector 198 (`0x030c6000`).

**The per-unit sector `0x0300b000`–`0x0300bfff` (sector 11) is NEVER free space.** It holds
per-radio parameters (an eFuse-derived hardware-binding record, per-unit hardware bytes). Every
image this repo ships has it blanked to `0xFF` (`scrub_unit_sector.py`), so it reads as erased
here — an all-`0xFF` scan of a shipped image will report it, and that report is wrong. Never write
it, and never write another unit's copy of it.

**Verified erased for patch code (2026-10-10)**: `0x030e1000`–`0x030fffff` (124 KB), sectors 225–255.
These are the only fully erased sectors in the image apart from the per-unit sector above.
Known allocations inside it:
- `0x030e1000`–`0x030e1fff` (sector 225): claimed TWICE. Every RAMDUMP / live-RAM-capture probe
  variant is a whole-sector handler at `0x030E1000` (`megaprobe-handler`, `audioprobe`,
  `pllprobe`, … in `meta/patch_sites.json` / `export_patch_sites.py`), and the overlay example
  also places its trampoline at `HANDLER = 0x030E1000` (`tools/examples/build_overlay_image.py`).
  Installing one overwrites the other's code, so as built they cannot be on a radio together;
  relinking the overlay into `0x030e2000`–`0x030e7fff` would remove the clash.
- `0x030e8000`–`0x030e9fff` (sectors 232–233, 8 KB): Snake example patch code + static tables

Remaining free for additional patches, 112 KB in all:
- `0x030e2000`–`0x030e7fff` (24 KB) free
- `0x030ea000`–`0x030fffff` (88 KB) free

**Absolute rules**: never use sector `0x030c6000` (holds the ALPU-MP anti-clone patch) or the
per-unit sector `0x0300b000`. Verify erased sectors by:
1. Reading with `placement_scan.py --lo 0x030e2000 --hi 0x03100000` (reports any cross-references)
2. Running `verify_patch.py` (checks both erased status and corpus-risk lookup)
3. Running `check_doc_claims.py` after editing any doc that states a free/erased range

## Linking and loading patch code

A patch is statically linked and flashed at a chosen address in the erased regions above. The
linker script and build process:

1. **Sections**: `.text` (code) and `.rodata` (read-only data like jump tables) at your chosen
   flash address; `.bss` (uninitialized data) at your SRAM scratch address.

2. **Entry function must be first**: compile with `-ffunction-sections` and put an explicit
   `*(.text.<entry_name>)` in the linker script's `.text` section BEFORE `*(.text*)`, then read
   the entry symbol back with `nm` and assert its address. This is exactly what the Snake build
   does (`build_c_with_ld()` in `tools/examples/snake/build_snake_patch.py`, `snake_game.ld`): it
   links with `csky-abiv2-elf-ld -T <script> -e <entry>` and does NOT use `--gc-sections`, which
   plays no part in ordering. GCC emits a file's functions in its own order, not declaration
   order: in Snake it emitted `place_food`, `reset_game`, `draw_frame` before
   `snake_screen_handler` (`snake_game.ld` comment). (Corrected 2026-10-10: this step previously
   called for `-Wl,--gc-sections` and blamed the linker placing "smaller functions from lib"
   first. If you do add `--gc-sections`, note that code reached only through a stock table you
   patch, not from the `-e` entry, has no reference the linker can see.)

3. **Extracting the binary**:
   ```bash
   csky-abiv2-elf-objcopy -O binary -j .text -j .rodata patch.elf patch.bin
   ```

4. **Jump tables in `.rodata`**: C `switch` statements with multiple cases generate jump tables
   that live in `.rodata`. These are fine as long as your linker script copies both `.text` and
   `.rodata` into flash at your chosen address. The build tools (`tools/src/dm32_patch_tools/build_patch.py`)
   handle this automatically.

## The emulator CPU-model bug (fixed 2026-10-10)

**What it was**: the `mtcr psr` / `psrset` helpers re-check pending interrupts and could stale
the TB's PC register, causing an interrupt return to land in the middle of `OSSched` with r0 and
sp clobbered. Under TB chaining, this led to a NULL TCB pointer (OSPrioHighRdy read as `0x41`,
PC reset to 0, sp to 0xfffffffc), a prompt crash.

**Signature to recognize (if it ever regresses)**:
```
Exception at 0x00010xxx in OSSched
  r0 = 0x41 (looks like a priority byte, not a TCB pointer)
  sp = 0xfffffffc (way out of bounds)
  FAULT: NULL TCB dereference
```

**The fix** (in `vendor/csky-qemu`'s `target/csky/translate_v2.c`): insert `gen_save_pc(ctx->pc + 4)`
before both the `mtcr psr` and `psrset` helper calls, forcing the TB to save its actual PC before
the ISR re-check. It is part of the overlay `install.sh` copies into the QEMU checkout; no action
needed.

## Debugging: reading kernel state from patch code

If a patch hangs or crashes, check these addresses at the exception point:

| address | read as | meaning |
|---:|---|---|
| `0x00042508` | 1 byte | Current task priority (0–63) |
| `0x00042500` | 4-byte pointer | Current TCB (validate: should point to IRAM, not 0 or garbage) |
| `0x000426d8` | 1 byte | ISR nesting depth (0 = task level, should be 0 at task exception) |
| `0x0003fd90` | 4-byte event flags | UI event flags; bit 0x02 triggers a redraw |
| `0x000392c4` | 1 byte | Current keypad scan code (0 = idle) |
| `0x18000800` | 4-byte | Stock keypad poll enable (0 = parked: the poll runs only its blanking stub) |
| `0x00030790` | 4-byte | Deferred poll re-enable request: non-zero = the blanking stub will set `0x18000800 = 1` after 21 blank polls and clear this word; 0 = no request (a parked poll then stays parked). Not a "poll active" flag (corrected 2026-10-10; see `docs/keypad-input.md`) |

Use `tools/src/dm32_patch_tools/dm32_ramdump.py` (requires a live-RAM-read patch on the radio)
to capture the full IRAM/SRAM state at the moment of a hang or crash, then inspect these
addresses in the dump.
