# data/registers/

The HR_C7000 SoC register map, as used in the Baofeng DM-32UV: every memory-mapped peripheral
register there is a source for, with its offset, reset value, bit fields and a citation.

| File | What it is |
|---|---|
| `HR_C7000-DM32.svd` | CMSIS-SVD (schema 1.3). The citation-bearing form: every register's description gives its datasheet section and page, and firmware evidence where there is any. |
| `HR_C7000-DM32.h` | The same map as a CMSIS-style C header: one struct per peripheral, `<PERIPH>_<REG>_<FIELD>_Pos`/`_Msk` macros, `<NAME>_BASE` and a `<NAME>` pointer per instance. Compiles as C99/C11; also suitable for a decompiler's C-header type import. Comments are abbreviated; the `.svd` has the full citations. |
| `*.sha256` | SHA-256 sidecars. Verify with `shasum -a 256 -c *.sha256`. |

Current size: 29 peripheral instances (28 with register-level detail),
398 registers (a layout shared by several instances, such as UART0-3, counted once) and
1173 bit fields.

## Generated, not hand-edited

Both files are produced outside this repository and copied in by a publish step; edits made here
are overwritten by the next publish. Report a wrong register or a missing citation instead.

Upstream, most peripherals are generated mechanically from the datasheet's register chapters, with
every correction to the datasheet recorded alongside its reason and repeated in the affected
register's description. Two blocks are hand-maintained upstream and are marked so in both files:

- **SystemControl** (`0x11000000`): soft reset, clock manager, pad mux, baseband control, DMR
  physical/link layer and FM registers, which share one 64 KB window. It keeps member names that
  existing decompiler labels use, and it is **not yet complete against the datasheet**: its SVD
  description lists the datasheet registers it does not describe yet (IOMGR pull-up/input-enable
  words, the RX FIR coefficients, the repeater/BS registers, part of the FM block). Two of its
  members, `RESERVED_0x40` and `RESERVED_0x48`, are the datasheet's `IOMGR_REN_REG0`/`_REG2`
  (pad pull-up enables) under older placeholder names.
- **TIMER** (`0x14000000`): six channels as an SVD `<cluster>`.

Between the `BEGIN GENERATED` / `END GENERATED` markers is the generated part.

## Sources

| Tag | Source |
|---|---|
| `DS` | Dahua, *HR_C7000 Chip User Guide* v2.7, English, 734 pages, 2017-07-19. Cited as section and PDF page, e.g. `DS §5.4.5.10 p.281`. The Chinese v2.7 original (412 pages) and the v2.2 Chinese user manual (2017-07-10) are cited by name where used. None of these documents is included here: they are marked "Internal disclosure". |
| `FW` | The stock DM32.00.01.048 firmware: the program image in `data/firmware/` (load base `0x03000000`) and the IRAM code it copies to `0x00010000`. Given as instruction or function addresses. `FW: n reads, m writes` counts come from a linear sweep for `movih`-built peripheral addresses, which cannot see bases kept in RAM tables: "no access found" does not mean "unused". |
| live reads | Register values read from a running DM-32UV (the TIMER block, the RTOS tick's PIC source). Only register state, no per-unit data. |
| `QEMU` | The `dm32uv-qemu` board model (`vendor/dm32uv-qemu`). |
| `DRV` | Third-party HR_C7000 driver headers (`C7000_DRV.h`, `bsp_vic.h`) from the DemoUV008 source tree, which is OpenGD77-derived and carries a non-commercial licence. Used only to corroborate names and offsets the datasheet also gives; nothing is copied from them. The five SystemControl registers that only those headers list (with placeholder names) are named by offset here, `REG_0x168` and `REG_0x370`-`REG_0x37c`: the datasheet does not list them, and the stock firmware writes all five. |
| `PSPEC` | A third-party processor-spec memory map for the C7000. |
| `INFERRED` | Not stated by any source for this instance; derived by symmetry. Always marked. |

Confidence varies per register; each description says what it rests on. A register whose bit
layout has not been transcribed is present without fields. A peripheral without `<registers>` is
"not described", not "has no registers". Trust a `<resetValue>` only where the description gives
its origin (`Reset 0x... (DS)`).

## Interrupts: source vs vector

The interrupt controller is the `PIC` peripheral at `0x17000000`, not the CK803S core's own VIC at
`0xE000E100` (the stock firmware never touches that range). DS Table 30 (p.168-169) gives each
interrupt a PIC **source** and a default CPU **vector**:

- source *n* is bit *n* of `PIC_MODE`/`PIC_PO`/`PIC_MASK`/`PIC_INT_ST` for *n* < 32, and bit *n*-32
  of the `_1` words for *n* >= 32;
- the CPU sees source *n* as vector *n* + 32 (`PIC_VECTOR.vector0` resets to 32);
- firmware and vendor code pass the **vector** (the RTOS tick is registered as vector 33).

The SVD `<interrupt><value>` is the **source**; the header's `*_BASE` comments give the source too.
Example: the uC/OS-III tick is timer channel 0 = `TIMER_1` = source 1 = vector 33 (confirmed on
hardware: unmasking source 33 instead delivers nothing).

## Datasheet errors corrected

Each correction is in the affected register's description with the printed text kept. The main
ones:

- PIC: `PIC_INT_CNT` printed at `0x48` (colliding with `PIC_INT_ST_1`), used at `0x4c` per
  Register Table 5; `PIC_PRIOR32-35` defaults printed as a copy of `PIC_PRIOR36-39`.
- TIMER: Timer5/Timer6 printed at Timer4's offsets in Register Table 6 and at Timer1's in
  §4.8.5.21-30; the `0x14` stride (and the firmware, and a live read) put them at `0x50` and `0x64`.
- SystemControl: `RX_INFO` printed at `0x39c` in Register Table 28 (it is `0x394`);
  `MODEM_AK_CLK_CALB`'s section prints `0x1b4` (it is `0x1b8`); `IO_DIPLEX1` bit 30 printed as
  "PTB4" (it is PTB5); `IO_DIPLEX2.lcd_db7_sel` printed as `GPIO_PTC24` (`GPIO_PTC14` by pattern,
  INFERRED).
- Access types the firmware contradicts: GPIO `DEBOUNCE` and `PORTA_EOI`, SSI `DR` (printed RO,
  written by the firmware).
- Name and copy typos across I2C, PWM, ADC, SDIO, USB and CODEC (e.g. `IC_RX_TL`'s field printed
  `TX_TL`, a second `PWM1_STATUS` that is `PWM2_STATUS`, `ADC_INTR_THRESHOLE`); two rows printed in
  Chinese in the English edition are translated with the original kept.

Registers the firmware uses that the datasheet does not list are included and say so:
i8080 `UNDOC_0x28`, SystemControl `REG_0x168`, `REG_0x370`-`REG_0x37c` and `INTERP_CLEAR_AUX`.
`SPI_Master3` (`0x14150000`, "EFUSE only" in the memory map) is not tabulated in any edition; the
firmware drives it with exactly the SSI offsets.

## RTC registers (not memory-mapped)

The RTC is an I2C slave at 7-bit address `0x70` behind the internal `I2C2` controller (DS §4.9,
p.200-212), so its registers are I2C register addresses reached with `IC_DATA_CMD` transactions,
not offsets from `0x14080000`. They are deliberately not in the SVD, where they would overlap and
mislabel `I2C2`'s own registers. Clock: external 32.768 kHz crystal. Interrupt: PIC source 19
(vector 51).

Bring-up order (DS §4.9.3.1): pull `rtc_rst_n` low, wait 3 APB cycles, write `RTC_SOFT_RST_N` = 0,
wait 25 ms, write it back to 1; program MATCH, then set `RTC_MATCH_VEN[0]` and `RTC_MATCH_VSTAT[0]`;
program LOAD, then set `RTC_CCR[2]` and `RTC_LOAD_VSTAT[0]`; then `RTC_CCR[0]` (interrupt) and
`RTC_CCR[1]` (run).

| RTC addr | Register | Bits | Access | Reset | Meaning |
|---|---|---|---|---|---|
| `0x00` | `RTC_VAL_S` | [5:0] | RO | 0x00 | Seconds of the current time |
| `0x01` | `RTC_VAL_M` | [5:0] | RO | 0x00 | Minutes of the current time |
| `0x02` | `RTC_VAL_H` | [4:0] | RO | 0x00 | Hours of the current time |
| `0x03` | `RTC_VAL_D_L` | [7:0] | RO | 0x00 | Day count, low 8 bits |
| `0x04` | `RTC_VAL_D_H` | [7:0] | RO | 0x00 | Day count, high 8 bits |
| `0x05` | `RTC_MATCH_S` | [5:0] | RW | 0x00 | Match (alarm) seconds |
| `0x06` | `RTC_MATCH_M` | [5:0] | RW | 0x00 | Match minutes |
| `0x07` | `RTC_MATCH_H` | [4:0] | RW | 0x00 | Match hours |
| `0x08` | `RTC_MATCH_D_L` | [7:0] | RW | 0x00 | Match day, low 8 bits |
| `0x09` | `RTC_MATCH_D_H` | [7:0] | RW | 0x00 | Match day, high 8 bits |
| `0x0a` | `RTC_MATCH_VEN` | [0] | RW | 0x00 | 1: commit the MATCH values (self-clearing) |
| `0x0b` | `RTC_MATCH_VSTAT` | [0] | RW | 0x00 | Set to 1 after configuring MATCH (power-fail guard); clear before reconfiguring |
| `0x0c` | `RTC_LOAD_S` | [5:0] | RW | 0x00 | Preload seconds |
| `0x0d` | `RTC_LOAD_M` | [5:0] | RW | 0x00 | Preload minutes |
| `0x0e` | `RTC_LOAD_H` | [4:0] | RW | 0x00 | Preload hours |
| `0x0f` | `RTC_LOAD_D_L` | [7:0] | RW | 0x00 | Preload day, low 8 bits |
| `0x10` | `RTC_LOAD_D_H` | [7:0] | RW | 0x00 | Preload day, high 8 bits |
| `0x11` | `RTC_CCR` | [2] | RW | 0x00 | `rtc_load`: 1 loads the count from LOAD (self-clearing) |
| `0x11` | `RTC_CCR` | [1] | RW | 0x00 | `rtc_enable`: 0 stop, 1 count |
| `0x11` | `RTC_CCR` | [0] | RW | 0x00 | `rtc_intr_en`: 1 interrupt enabled |
| `0x12` | `RTC_LOAD_VSTAT` | [0] | RW | 0x00 | Set to 1 after configuring LOAD (power-fail guard) |
| `0x13` | `RTC_RSTAT` | [0] | RC | 0x00 | 1: interrupt occurred; read to clear |
| `0x14` | `RTC_CLKDIV_NUMER_L` | [7:0] | RW | 0x00 | Clock divider, low 8 of 16 bits |
| `0x15` | `RTC_CLKDIV_NUMER_H` | [7:0] | RW | 0x00 | Clock divider, high 8 bits |
| `0x16` | `RTC_CLKDIV_NUMER_VLD` | [0] | RW | 0x00 | 0: default 32768 divider; 1: use RTC_CLKDIV_NUMER |
| `0x17` | `RTC_SOFT_RST_N` | [0] | RW | 0x01 | 0: soft reset asserted; 1: released |

## Relation to the rest of this repository

- `tools/include/hr_c7000_regs.h` is a small hand-checked subset for patch code (pad mux, GPIO,
  PIC, TIMER, WDG, ADC), with DM-32-specific traps such as the keypad-scan / LCD-bus pad sharing.
  It cites this map as its source of truth; prefer it in patches, and check it against this map
  when the map changes.
- `include/dm32/structs.h` (generated from the analysis database) uses the same peripheral struct
  type names. The database's types are applied from this map, so its members follow this header,
  but they can lag behind it until the next regeneration; where the two disagree, this map is
  newer.

## Using the header

The header typedefs `uint32_t`/`uint8_t` itself so it parses without a C library. To use your
platform's types instead, include `<stdint.h>` and define `DM32_UINT32_T_DEFINED` before including
it. Struct and macro names follow CMSIS conventions and may collide with other CMSIS-style headers
(`GPIOA`, `TIMER`, `__IO`); `tools/include/hr_c7000_regs.h` uses an `HRC_` prefix for that reason.

Nothing here is per-unit data. This map describes runtime MMIO only; it is unrelated to the
per-unit calibration data stored in each radio's external data flash.

## License

Covered by this repository's [`LICENSE.md`](../../LICENSE.md) (PolyForm Noncommercial 1.0.0).
The HR_C7000 datasheets the map is derived from are not included.
