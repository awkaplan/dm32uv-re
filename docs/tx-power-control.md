# TX power control: how stock sets PA drive

Everything here was traced statically in the corpus (`src/`, `meta/disasm.jsonl`) and in the
stock images; nothing below was measured on a radio or with a power meter. Addresses are for
DM32.00.01.048 at load base `0x03000000`; IRAM addresses are execution addresses (the IRAM image
is copied from flash at `iram + 0x030afc20`, checked byte for byte for `0x2b364..0x2b6a0`).

## 1. The actuator is a DAC byte, not an FD6818 register

Earlier feasibility work (in the research project) assumed TX power
is set through FD6818 `REG_19H[3:0]` (PA bias). **The stock firmware never writes `REG_19H`**, and
`fd6818b_pa_power_level_select` @0x0300e68c (the only PA-named FD6818 writer) writes `REG_53H`,
`4BH`, `27H`, `29H` with constants chosen by a 1/2 mode argument. What actually changes with the
Low/Mid/High setting is one RAM byte:

| thing | address | evidence |
|---|---|---|
| PA drive byte | RAM `0x00038498` = `0x38470[0x28]` | written by `freq_calibration_apply_all` @0x0300db48 (`st.b r0,(r5,0x28)` @0x0300db6c) from the interpolated calibration group selected by `(flags_0x8 >> 1) & 3` |
| consumer | `rf_tx_enable_sequence` @IRAM `0x2b440` | calls `FUN_0002b364(1, 1, *(0x38470+0x28))` after `pa_band_select_vhf_uhf_gpio(1)` |
| ramp | `FUN_0002b364` @IRAM `0x2b364` | 40 steps, each scaled by the byte, written with `dac_channel2_write_from_byte` (`dac_channel_write_12bit(2, byte << 4)`), ending at the byte |
| ramp-down | `rf_tx_disable_sequence` @IRAM `0x2b4a0` | `FUN_0002b364(1, 0, same byte)`: 21 steps down, then DAC ch2 = 0 |

This closes the "consumer of `0x38470[0x28]` not found" gap recorded in
the research project's block-2 calibration decode: the consumer was in IRAM, and
it reads the byte through the literal pool word `0x00038470` at IRAM `0x2b504`, which the flash-side
search could not see. That makes the L0<L1<L2 three-level group the TX power calibration by
construction of the call chain (a per-level DAC target), though the DAC-to-RF-power relation is
still unmeasured.

Not resolved: how DAC channel 2 reaches the PA (gate bias or a driver stage), and what the DAC
code to output power curve looks like. The patch therefore scales the byte by a fraction and
never claims a dB figure.

## 2. The RX level source is stock's own REG_67H average

`adc_rssi_rolling_average_tick` @0x0301bcb0 is **not RSSI**: it averages ADC channel 2 into
thresholds 700/800/900 and drives the low-battery icon and a low-battery reset. It is a battery
monitor (misnamed in the corpus).

The receive level comes from `rssi_rolling_average_meter_update` @0x0305ffe4, called from
`ui_background_periodic_subtask_dispatcher` at `0x030133c0`. It reads FD6818 `REG_67H[8:0]`
(`rssi_sq`, 0.5 dB/step, `RSSI(dB) = rssi_sq/2 - 160` per the FD6818 vendor datasheet), clamps to
255, shifts it into a 10-byte ring at IRAM `0x0003fdd0` (newest at `+9`) and stores the mean at
`0x0003fde0`. It updates only while a radio-state check (`0x0300f2a4`) is true, so after reception
ends the ring and mean freeze at their last values. That freeze is what the patch relies on: it
holds the mean while the ring is still changing and the mean is above the noise floor.

Open: that `0x0300f2a4` is "receiving" is inferred from the function's shape; the dB reference of
`rssi_sq` on this radio is the datasheet's, unverified here.

