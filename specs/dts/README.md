# specs/dts: Devicetree description of the DM-32UV

Which chip sits on which bus and pin, written as Devicetree source so standard tools can read it.
It describes the hardware; it is not a Linux port (the CK803S has no MMU) and nothing here has
been booted.

| File | What |
|---|---|
| `hr_c7000.dtsi` | The SoC: every peripheral at its real base, `interrupts` = PIC **source** numbers, pad-mux groups for the values the stock firmware writes. |
| `dm32uv.dts` | The board: flash chips, RF transceiver, FM receiver, ALPU-MP, keypad, keys, LEDs, backlight, LCD panel, GPS, audio switches, battery sense, and a name for every GPIO line with a known use. |
| `validate.sh` | Compiles with `dtc` (must be warning-free) and, given a kernel bindings directory, runs `dt-validate` and fails on any report not in its expected list. |

Every node and pin has a comment citing its source. Source tags are defined at the top of each
file: `[DS]` HR_C7000 v2.7 guide, `[SVD]` `data/registers/HR_C7000-DM32.svd`, `[FW]` the stock
DM32.00.01.048 image by address, `[HW]`, `[QEMU]` `vendor/dm32uv-qemu`, `[MAP]` the community
GPIO pin map, `[ORTX]` the OpenRTX DM-32 port's `pinmap.h`, `[MAN]` the Baofeng user manual,
`[INF]` inferred.

## Validating

```sh
specs/dts/validate.sh                                 # dtc only
specs/dts/validate.sh <linux>/Documentation/devicetree/bindings   # + dt-validate (dtschema)
```

Checked on 2026-10-11 with DTC 1.8.1, dtschema 2026.9 and the bindings of Linux **v6.16**:

```
dtc: OK (13219 bytes, no warnings)
dt-validate: OK (26 expected reports, nothing else)
```

`dtc` gives no warnings even without `-W no-unit_address_vs_reg`. The 26 expected `dt-validate`
reports are 22 "failed to match any schema" lines (one per node with only a locally
namespaced compatible below, plus the CPU, which upstream does not document) and one real schema
error, printed as 4 lines: SPI master 3 has no `interrupts`, because the datasheet's Table 30 assigns it no PIC source. Every node that uses an
upstream binding otherwise validates clean, including all board-level ones (`jedec,spi-nor` x2,
`fixed-partitions`, `spi-gpio`, `i2c-gpio` x2, `rda,rda5807`, `gpio-matrix-keypad`, `gpio-keys`,
`rotary-encoder`, `gpio-leds`, `pwm-backlight`, `gpio-poweroff`, `simple-audio-amplifier`,
`gpio-mux` x2, `simple-battery`, `iio-hwmon`, `regulator-fixed`, `pinctrl-single`). The script
was mutation-tested: adding one stray property makes it fail.

## Compatibles

Upstream bindings are used wherever the hardware is that IP or device; the datasheet and SVD
identify the timer, GPIO, UART, I2C, SSI, USB and SDIO blocks as Synopsys DesignWare. Elsewhere
the strings are local and **not upstream-registered**:

- `dahua,hr-c7000-*`: SoC blocks with no generic binding (PIC, LCSFC, WDT, PWM, ADC, DAC, i8080,
  RTC, baseband, codec, SPI slaves, eFuse). "dahua" is the datasheet publisher; it is not in
  `vendor-prefixes.yaml`.
- `dm32uv,*`: board parts whose vendor is not established from a first-party document
  (FD6818B, the GPS module, the LCD panel, the RF front-end switch set).
- `neowine,alpu-mp`: vendor from the ALPU-MP datasheet; prefix not registered.
- `baofeng,dm32uv`: the board; prefix not registered.

Registered prefixes used: `snps`, `csky`, `rda`, `jedec`. `sitronix` exists but its ST7789V
binding is SPI-only (see the LCD row below).

## Nodes and confidence

CONFIRMED = stock firmware code read for this file (or hardware); STRUCTURAL = base/IRQ from the
datasheet, no DM-32 use seen; INFERRED = reasoned, not shown.

| Node | Binding | What, where | Confidence |
|---|---|---|---|
| `pic` | local | PIC @0x17000000, 1-cell source numbers | CONFIRMED (SVD, HW tick test) |
| `timer0..5` | `snps,dw-apb-timer` | 6 channels, 0x14 stride, sources 1-6; ch0 RTOS tick, ch5 UI tick | CONFIRMED (HW, FW); clock 84 MHz INFERRED |
| `gpioa/b/c` | `snps,dw-apb-gpio` | 3 banks, sources 15/14/17 | CONFIRMED; both-edge reg at +0x78, not +0x68 |
| `pinmux` | `pinctrl-single` | IO_DIPLEX0-2; 11 groups, each a value stock writes | CONFIRMED (FW per group) |
| `uart0` | `snps,dw-apb-uart` | CPS/console, 115200, source 12 | CONFIRMED |
| `uart1` + `gnss` | `snps,dw-apb-uart` + local | GPS, 9600, RX pad only, option-gated | CONFIRMED (FW); module part INFERRED (CASIC sentences + MAP) |
| `i2c2` + `rtc@70` | `snps,designware-i2c` + local | on-chip RTC as I2C slave 0x70, 400 kHz | CONFIRMED |
| `spi0` + `flash@0` | `snps,dw-apb-ssi` + `jedec,spi-nor` | W25Q128JV, CS GPIOA 18 (GPIO) | CONFIRMED |
| `xip` + `flash@0` | local + `jedec,spi-nor` | GD25Q80 1 MB at 0x03000000, 4 partitions | CONFIRMED layout; controller registers partly known |
| `spi-0` + `transceiver@0` | `spi-gpio` 3-wire + local | FD6818B, CLK A7 / DATA A8 / CS A24 | CONFIRMED (IRAM disassembly) |
| `i2c-0` + `security@3d` | `i2c-gpio` + local | ALPU-MP, SCL A5 / SDA A6, 7-bit 0x3d | CONFIRMED |
| `i2c-1` + `radio@10` | `i2c-gpio` + `rda,rda5807` | RDA5807M, SDA A25 / SCL A26, 7-bit 0x10 | CONFIRMED |
| `keypad` | `gpio-matrix-keypad` | rows GPIOB 17-20, cols GPIOC 7-11, 18 keys | CONFIRMED (FW + QEMU-measured codes) |
| `side-keys` (disabled) | `gpio-keys` | SK1 = GPIOB 19, SK2 = GPIOB 20 (shared with rows) | SK1 CONFIRMED (FW + MAN); SK2 INFERRED |
| `keys` | `gpio-keys` | PTT GPIOB 11 (low); power-switch sense GPIOA 16 (high = off) | CONFIRMED |
| `encoder` | `rotary-encoder` | GPIOB 7 (A) / 6 (B) | CONFIRMED pins; A/B order from MAP |
| `leds` | `gpio-leds` | red GPIOB 0, green GPIOB 1; keypad backlight GPIOB 8 (disabled) | pins CONFIRMED, polarity INFERRED, colours MAP; GPIOB 8 UNVERIFIED |
| `backlight` | `pwm-backlight` | PWM ch0 @1 kHz on GPIOA 15, stock's 7 duty levels | CONFIRMED |
| `poweroff` | `gpio-poweroff` | power hold GPIOA 17, low = off | CONFIRMED |
| `speaker-amplifier` | `simple-audio-amplifier` | TDA2822 switched by GPIOB 21 | CONFIRMED line; "switches supply" INFERRED |
| `mux-controller-0/1` | `gpio-mux` | mic source GPIOB 14, audio destination GPIOB 15 | CONFIRMED (FW polarity trace) |
| `rf-frontend` | local | LNA VHF B2 / UHF B4, PA UHF B3 / VHF B23 | CONFIRMED (IRAM disassembly) |
| `vbat-sense` + `battery` | `iio-hwmon` + `simple-battery` | ADC channel 2 (ADC2_IN, GPIOC 17); 7.4 V 2500 mAh | channel CONFIRMED; scaling unknown |
| `lcdc` + `panel@0` | local | 240x320, reset GPIOC 2, ST7789V command set | CONFIRMED (FW init sequence) |
| `pwm`, `adc`, `dac` | local | PWM ch0 used; ADC ch1/2 used; DAC enabled, consumer unknown | CONFIRMED use |
| `baseband`, `codec` | local | modem RAM + built-in vocoder area; codec regs | STRUCTURAL |
| `wdt`, `usb`, `mmc`, `uart2/3`, `i2c0/1`, `spi1/2`, `spi-slave*` (all disabled) | various | no DM-32 use found | STRUCTURAL |
| `spi3` + `efuse@0` | `snps,dw-apb-ssi` + local | eFuse read path | CONFIRMED (FW), eFuse contents never recorded |

## Reconciliation of the pin sources

Sources: **MAP** = community pin map (infotex58.ru OpenDM32 thread, `PinMap_Baofeng_DM-32_14.06.26`);
**ORTX** = OpenRTX DM-32 port `pinmap.h`/`hwconfig.h`; **QEMU** = `vendor/dm32uv-qemu`
(`hw/csky/dm32.c`, `hw/gpio/dm32_gpio.c`, device files, `docs/dm32/`); **FW** = stock firmware,
which wins every disagreement. Also listed: disagreements with this repo's own SVD/corpus names
and with the task brief this file was written from.

| Item | MAP | ORTX | QEMU | Other | FW (wins) |
|---|---|---|---|---|---|
| Keypad line naming | GPIOC 7-11 "ROW 0-4", GPIOB 17-20 "COL_1-4" | same as MAP | rows = GPIOB, cols = GPIOC (the model's `docs/key-injection.md` calls the orientation disputed) | | GPIOC 7-11 driven, GPIOB 17-20 sensed. Only naming differs; DT calls the sensed lines rows (binding convention). |
| GPIOB 19/20 | "Keyboard COL_3/4" only | KB_COL3/4 only | `dm32_gpio.c` comment: side keys SK1/SK2 on GPIOB 19/20 (an earlier version said Up/Down) | | Also SK1 (19) / SK2 (20) direct to ground, codes 4/7. Up/Down are matrix keys (GPIOC 11). |
| GPIOA 17 (0x11) | "Power key" | `PWR_SW` (switch) | power-hold **output** | | Output, set high at task init (FUN_0301b818), cleared on power-off. Not a key. |
| GPIOA 15 (0x0f) LCD backlight | "LCD BackLight" | `LCD_BKLIGHT` driven as a GPIO | | SVD: "PWM: FW no access found" | PWM channel 0 at 1 kHz (pad mux FUN_0301c1a4, setter 0x0301c1bc). The SVD sweep missed the arithmetically built base. |
| GPIOB 8 (0x28) keypad backlight | "Keyboard BackLight" | `KB_BKLIGHT` | | | No constant-pin use found. Unverified; node disabled. |
| GPIOB 12 (0x2c) | "GPS power control" | | | corpus name `gps_power_set` (formerly `backlight_power_toggle`) | GPS power (the function clears the NMEA buffers). MAP right, corpus name wrong. Polarity: active low, INFERRED. |
| GPIOB 21 (0x35) | "Audio PA control" | `AUDIO_PA` | | corpus name `audio_pa_enable_gate` (formerly `tx_enable_gate`) | Audio PA. Corpus name wrong. |
| LCD controller | | "ST7789-class" | "HX8353E" | SVD + RE notes: HX8353E | Init sequence is ST7789V-specific (0xb2/0xb7/0xbb/0xc0/0xc2/0xc3/0xc6/0xd0/0xd6). The HX8353E identification rests on the shared DCS subset only. |
| UART1 | TXD GPS on GPIOA 9 | | unmapped | task brief: "HR_V3000 vocoder on UART1" | GPS at 9600, RX pad only, option-gated; CASIC sentences. No HR_V3000 on this radio (built-in vocoder, DS 7.1.1). |
| ALPU-MP bus | GPIOA 5/6 "ALPU-MP I2C" | | earlier model: on the I2C0 controller | SVD I2C0: "QEMU docs record ALPU on this controller" | Bit-banged on GPIOA 5 (SCL) / 6 (SDA); I2C0 controller never touched. |
| ALPU-MP address | | | "0x7a" | task brief: "0x7a" | 0x7a is the 8-bit write byte; DT `reg` is the 7-bit **0x3d**. |
| GPIOA 23 (0x17) | "SPI1_CSN_0" | | | | Driven as a GPIO chip select only by an SD-over-SPI probe with no caller. |
| GPIOA 25/26 | RDA5807M SDIO/SCLK | none | "RDA5807M: I2C on GPIO", not modelled | | Agrees (I2C, 7-bit 0x10). Conflicts with the uncalled SPI1 pad mux above. |
| UART0 IRQ | | | wired to PIC input **44** | DS Table 30: source 12 | Stock registers vector 0x2c = 44 = source 12. QEMU wires the vector number as a source. |
| RTC | | | I2C2 slave 0x70 | | Agrees (`rtc_register_read` @0x0301c2d4). On-chip, no discrete RTC. |
| FD6818 pins | A7/A8/A24 | same | same | | Agree (IRAM 0x0002c33c, 0x0002c298). |
| W25Q128 CS | A18 | `FLASH_CS` 0x12 | GPIOA bit 18 | | Agree; a GPIO, the SSI CSN_0 mux is left on GPIO. |
| LNA/PA band lines | B2/B4 LNA, B3 UHF PA, B23 VHF PA | LNA only | | | Agree (IRAM 0x0002c838, 0x0002c878). |
| Audio muxes B14/B15 | names only | polarity SET = analog / FD6818 | | | Agree with ORTX (whose polarity cites the stock functions). |
| Battery ADC | | | channel 2 (C), corrected from F | | Channel 2 = ADC2_IN, confirmed (battery_percentage_display_update). Channel 1 is also used; signal unknown. |

## Open questions

1. **UART1 transmit path.** Stock queues CASIC configuration sentences on UART1, but its init
   muxes only the RXD pad (IO_DIPLEX0 bit 9) and drives the TXD pad (GPIOA 10) low as a GPIO.
   Either those sentences never reach the GPS, or the datasheet's bit 9/10 assignment is swapped.
   A scope on GPIOA 9/10 at boot would settle it.
2. **Clock rates.** The APB clock is a placeholder (84 MHz, copied from the timer). The bus rate
   is computed at run time into RAM 0x0003a60c; read it live before trusting any divider.
3. **What 0x04000000 is.** The fifth entry of the stock SSI base table and an early-boot serial
   controller in the QEMU notes; not in the SVD. Possibly the LCSFC's register window.
4. **GPS power polarity.** The on/off path clears GPIOB 12 for "on", but board init drives it
   low when the GPS option bit is clear. Active low is the reading used; unconfirmed.
5. **LED colours and polarity**, and whether GPIOB 8 is the keypad backlight at all. The
   manual's upgrade mode shows a green LED while the xmodem loop toggles GPIOB 0 (MAP: red).
6. **SK2.** GPIOB 20 = SK2 is by elimination; GPIOB 19 = SK1 is supported by the PTT+SK1
   upgrade combination.
7. **ADC channel 1 and the DAC outputs**: which signals they carry.
8. **CLK_OUT (PLLA on GPIOC 0)**: consumer not traced; an RF reference clock is the guess.
9. **FD6818B GPIO0/1** (GPIOB 27/26, MAP only): never read with a constant pin; whether they
   are interrupt lines is unknown.
10. **LCD controller part number.** The command set is ST7789V; whether the die is an ST7789V
    or a compatible clone is unknown. A RDDID (0x04) read on hardware would answer it.
