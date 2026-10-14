# specs/lcd: the panel controller

| File | What |
|---|---|
| `st7789v_stock_init.txt` | The stock firmware's panel init, every command, parameter and delay, in the Linux `panel-mipi-dbi` command-file format. |
| `../rdl/st7789v_madctl.rdl` | MADCTL (`0x36`) bit fields, with the values stock writes. |
| `../../tools/include/mipi_dcs.h` | Standard MIPI DCS opcodes (`MIPI_DCS_*`). |
| `../../tools/include/st7789v.h` | Vendor opcodes (`ST7789V_*`), with the HX8353E list kept for comparison. |

## Which controller

**The commands match a Sitronix ST7789V.** The repo used to call the controller a Himax HX8353E,
because the DemoUV008 reference tree carries an `HX8353E.h` and because the four opcodes the
drawing code uses (`2Ah 2Bh 2Ch 36h`) fit it. Those four are standard MIPI DCS and fit any such
controller. The stock init (`lcd_controller_power_on_init_sequence` @`0x03017d4c`) settles it:

| Opcode | Stock sends | ST7789V v1.3 | HX8353E V01 |
|---|---|---|---|
| `B2h` | 5 params `0C 0C 00 33 33` | PORCTRL, 5 params, default `0C 0C 00 33 33` (9.2.3 p.263) | SETDISPLAY, 3 params (8.2.39 p.162) |
| `B7h` | `56` | GCTRL (9.2.6 p.268) | not defined |
| `BBh` | `17` | VCOMS (9.2.9 p.273) | SETOTP, 1st param = OTP key `AAh`/`55h` (8.2.44 p.171) |
| `C0h` | `2C` | LCMCTRL, default `2Ch` (9.2.10 p.275) | SETSTBA, 6 params (8.2.45 p.172) |
| `C2h` | `01` | VDVVRHEN (9.2.12 p.277) | not defined |
| `C3h` | `0B` | VRHS, default `0Bh` (9.2.13 p.278-279) | SETTID, writes the module ID (8.2.46 p.175) |
| `C6h` | `EF` | FRCTRL2 (9.2.16 p.284) | not defined |
| `D0h` | `A7`, then `A4 A1` | PWCTRL1, `A4h` + 1 param (9.2.21 p.290) | GETHID, a read (8.2.48 p.177) |
| `D6h` | `A1` | not documented | not defined |
| `E0h`/`E1h` | 14 params each | PVGAMCTRL/NVGAMCTRL, 14 params (9.2.24-25 p.294-297) | E0h SETGAMMA has 19; no E1h (8.2.49 p.178) |
| `B9h` | never sent | - | SETEXTC `FF 83 53`, needed for the HX8353E's extended set unless EXTC is strapped (8.2.43 p.170) |

The frame is 240 x 320 (the init clears CASET 0..239 by RASET 0..319). That is the ST7789V's size;
the HX8353E tops out at 132 x 162 (HX8353E 1 p.5, 2 p.6).

**Still uncertain:** a genuine ST7789V or a compatible clone (several vendors ship parts with this
command set). Two stock writes are not in the ST7789V v1.3 datasheet: `D0h A7h` with one
parameter, and `D6h A1h` (also absent from the ST7789VW v1.0 datasheet). Reading RDDID (`04h`) or
RDID1-3 (`DAh`-`DCh`) on a real radio would settle the part. Nobody has done it yet, and the
module's marking is not recorded.

## How the init sequence was obtained

1. Disassembly of `0x03017d4c` and its callees (`lcd_set_orientation` @`0x030178ec`,
   `display_clear_fullscreen` @`0x03017d40`). The function is straight-line code; the only branch
   is MADCTL `0xC0` / `0x00` from the user's display-direction setting.
2. The stock image run under this repo's QEMU model (`dm32uv-re-pipeline` image; image composed by
   `compose_qemu_image.py`, QEMU started with `-s -S`), with gdb-stub breakpoints on
   `lcd_write_command` (IRAM `0x0002c1cc`), `lcd_write_data` (`0x0002c1d8`), the delay wrapper
   (`0x0300c4bc`) and the GPIO setters, from entry to return of `0x03017d4c` (2026-10-11). The
   logged stream matched the disassembly byte for byte. The 76,800 pixel writes of the full-screen
   clear were skipped by disabling the data breakpoint after RAMWR.
3. `st7789v_stock_init.txt` compiles with the CC0 `mipi-dbi-cmd` tool
   (github.com/notro/panel-mipi-dbi) and decompiles to the same command list.

The format is that of Linux `panel-mipi-dbi` (`drivers/gpu/drm/tiny/panel-mipi-dbi.c`, binding
`panel-mipi-dbi-spi.yaml`): `command <opcode> <params...>`, `delay <ms>`, `#` comments. A Linux
user would also need the panel reset (stock: reset line high, 120 ms, low, 120 ms, high, 120 ms),
which the binding's `reset-gpios` covers, and an i8080 (not SPI) host; the commands are the same.

## Sources

- Sitronix, *ST7789V* datasheet, Version 1.3, 2014/03 (public; e.g. newhavendisplay.com).
  Sections 9.1 (standard commands) and 9.2 (command table 2). PDF page = printed page.
- Sitronix, *ST7789VW* datasheet, Version 1.0, 2017/09 (checked only for `D6h`).
- Himax, *HX8353-E* datasheet V01 (v0.1), April 2012, chapter 8.2.
