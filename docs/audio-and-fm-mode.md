# Stock analog and DMR audio, FM mode, retune and PTT: architecture summary (DM32.00.01.048)

Status: static reverse engineering of the stock image, plus the HR_C7000 and FD6818B datasheets. Nothing in
the static sections was run on a radio. Where the sources include real hardware measurements, they are marked
as such (section 6).

Sources, all in dm32uv-unleashed (a separate patch project by the same author, not published) unless stated:
- `docs/rx-audio-fm-mode.md` (analog RX as PCM, FM mode; cited "rx §")
- `docs/retune-for-scope.md` (RX retune, lock, RSSI, restore; cited "retune §")
- `docs/afsk-tx.md` (analog TX keying, FD6818 tone generator; cited "afsk §")
- `docs/parrot-recording.md` (DMR voice recording and playback; cited "parrot §")
- `feature-checklist.md`, item P5 (RF Lab hardware measurements)

Confidence tags follow the sources. CONFIRMED means disassembly or datasheet plus a literal agree. STRUCTURAL
means read from code and not cross-checked. INFERRED and OPEN are the sources' own words for inference and
unknowns. Function names are the 2026-10-15 manifest names; the old names appear in the sources.

## 1. FM mode on analog channels

- Stock runs the HR_C7000 in FM mode on every analog channel. `modem_rf_mode_transition_apply` @0x0301e628 (analog
  branch) sets `CLK_MGR_REG0x2c` bits 7:6 (0xc0) and `WORK_MODE |= 0x80`. `radio_mode_transition_sequencer` @0x03021670
  writes `WORK_MODE = 0x80` for analog modes. `rf_mode_transition_on_freq_delta` @0x03055f88 calls the apply on channel
  changes. CONFIRMED (rx §0, §3.1).
- WORK_MODE bit 7 is the FM select (`modulator_mode`); bit 8 is the digital/analog dual-detect. Digital sets
  `(v & 0x7e) | 4`, which clears bit 7. CONFIRMED (rx §2, §3.1).
- The ADC is enabled on analog and digital channels: `mmio_11000074_bits78_set_from_status_nibble` @0x0305ba70 sets
  ADC_CONTROL bits 8:7 for nibble 0 (analog) or 0x10 (digital). CONFIRMED (rx §3.3).
- Input: stock programs RF_MODE bit 24 (`af_mode`) with `af_recv_ctrl` 0x26 in `hr_c7000_modem_core_register_init`
  @0x03023608, so the modem takes the FD6818 AF output, not IQ or IF. Configuration HIGH; the PCM spectrum MEDIUM
  (rx §1.1, §5). The wiring "AF_out feeds the modem ADC on analog" is inferred from DMR using the same pin (rx §1.1).
- Stock also writes `FM_BANDWIDTH` = 0x5f and `FM_DEV_COEF` = 0x33500 (rx §1.1, §3.5).

## 2. FM receive RAM and FM_ADDR_SW (stock does not read them)

- Stock never reads the FM output. A scan of the flash functions finds no access to FM_SQL (0x508), FM_DECODE_FLAG1/2
  (0x564/0x568), FM_ADDR_SW (0x56c), SYS_INTERP_LIST (0x398) or SYS_INTERP_CLEAR (0x3a0), and no access to the FM RX
  voice halves (rx §0.2, §3.6). CONFIRMED for the scan's coverage of the flash functions; IRAM was not exhaustively
  decoded (rx §3.6).
- RX voice halves: FM_VOICE_1 = 0x160004e0..0x160006df and FM_VOICE_2 = 0x160006e0..0x160008df, each 512 bytes
  (256 16-bit samples). The RX RAM base is 0x160004b0 (rx §1.3). The datasheet (§7.2.2.3.2) says FM RX recording is
  on by default in FM mode; no stock code exercises it. MEDIUM.
- `FM_ADDR_SW` (0x1100056c, bits [1:0], read-only): 1 means the low half, 2 means the high half. The meaning
  ("read this half now" or "being filled") is INFERRED from the datasheet wording; a read-only probe was proposed to
  settle it (rx §2, §4.3). It is not verified.
- Sample format: 16-bit, high byte first (zh-CN Table 58), signedness assumed two's complement. Big-endian is MEDIUM-HIGH;
  sign is LOW-MEDIUM. The 8 kHz rate is inferred from a datasheet sentence about the TX RAM (rx §1.3, §5).
- Interrupts: stock keeps `SYS_INTERP_MASK` bits 13..15 clear, so it never takes an FM interrupt. A patch must keep
  those bits clear (rx §2).
- The RX RAM base is shared with the DMR L2 receive area (`copy_bytes_from_offset_table` @0x0300d41c uses 0x160004b0).
  Reading the FM halves on a digital or dual-detect channel is unsafe (rx §4.7).

## 3. Analog and DMR audio paths

- Analog speaker source: GPIO 0x2F = 1 selects the FD6818 direct path to the speaker amp. INFERRED from the pattern
  that stock restores 0x2F on analog after tone playback; the pin label is "Switch audio PWM/FD6818" (rx §3.2).
  DMR clears 0x2E and 0x2F, which selects the codec PWM path (rx §3.2).
- GPIO 0x2E is the MIC analog/DMR path select (rx §3.2).
- Speaker amp enable: GPIO 0x35 via `audio_pa_enable_gate` @0x0301d6cc. It is not the TX gate; the older name
  `tx_enable_gate` was wrong (parrot §3.1, HIGH).
- Codec: `hr_c7000_modem_reset_sequence` @0x03021b80 enables the codec DAC and ADC in master, parallel-PCM mode (rx §3.4).
- DMR voice: the IRAM vocoder task (`FUN_0002f000`) moves 27-byte units through MMIO 0x16000960. In TX it writes the
  encoder output; in RX it reads the modem's frames and runs the software decode to PCM and the speaker. The unit is
  one DMR voice burst payload (three AMBE+2 frames), one per 60 ms (parrot §1.1, §3.2).
- Recording: `voice_recorder_task` @0x030212f4 (formerly `channel_activity_log_flush_task`) writes 27-byte units to
  the data chip while the recorder state byte is 1 (RX) or 2 (TX). `record_switch_toggle` @0x03015bb0 is the Record
  Switch; toggling it writes block 4 in flash (parrot §1.2).
- Playback: `recording_playback_to_speaker` @0x0306158c (formerly `channel_send_dtmf_autodial_call`) plays a stored
  recording on the local speaker only. It does not key TX (parrot §2).
- Prompt and PTT tones: `flash_audio_clip_playback_pcm` @0x030222f0 (formerly `flash_audio_clip_playback_tx`) streams
  PCM clips into the audio FIFO at MMIO 0x16000980. It cannot carry AMBE and does not key TX (parrot §2.1, HIGH).

## 4. Retune, lock and RF register map (FD6818B)

- Frequencies are u32 values in 10 Hz units (14400000 = 144.000000 MHz). The live RX word is at 0x0003846c and the TX
  word at 0x00038468. The RX/TX assignment of the two words is MEDIUM-HIGH, read from code and not observed on a radio
  (retune §A.1).
- RF frequency registers: REG_38H = F10 & 0xFFFF and REG_39H = F10 >> 16. Stock writes them through
  `fd6818_set_frequency` (IRAM 0x0002b56c), which has no scaling or divider math. CONFIRMED (retune §A.1, §A.2).
- RXON re-trigger: after a frequency write, stock writes REG 0x30 = 0 and then 0xbff1 (the datasheet's RXON with
  `vco_cal_en` going 0 to 1), in `fd6818b_filter_select_then_chipmode_normal` (IRAM 0x2b5e4). REG_37H is 0x1f1f on
  digital channels and 0x1f0f on analog. CONFIRMED for the values. The mapping of REG 0x30 to the guide's REG_03H is
  MEDIUM (retune §A.3, §F).
- TX-on: stock writes REG 0x30 = 0xC1FE (TXON) in the TX path (afsk §1.1).
- Tone divider, not the RF tune: `fd6818b_write_tone_divider_reg07` @0x0300e7e0 (formerly `fd6818b_program_divider`)
  writes REG_07H. The sub-audible apply is `ctcss_dcs_tone_apply` @0x0300e10c (formerly `rf_channel_frequency_apply`),
  which takes the tone type and the CTCSS (BCD, 0.1 Hz) or DCS code. CONFIRMED (retune §0).
- Lock: REG_0CH bit 9 is `pll_lock` (1 = locked), per the datasheet. Stock never reads bit 9; its REG_0CH accessors
  read other bits (retune §B). CONFIRMED for the register, and "stock does not poll it" is a static negative result.
- Band: stock writes no FD6818 band register. Band selection is by board GPIO: LNA VHF is 0x22 and LNA UHF is 0x24, set
  by `antenna_switch_select_gpio_24_22` (IRAM 0x0002c878). The PA paths are 0x37 (VHF) and 0x23 (UHF). A retune alone
  does not move the LNA GPIO (retune §A.4, MEDIUM-HIGH).
- Calibration: `freq_calibration_apply_all` @0x0300db48 is not on the RF tune path. It sets TX-power and audio-level
  bytes, not the RX synth. RSSI is not calibrated per frequency on the chip path (retune §A.5).
- Restore: `channel_change_apply_squelch` @0x0300df08 re-reads the RX word and runs the full stock RX tune. Stock calls
  it from the menu task, so a menu-task retune is stock behaviour (retune §A.6, HIGH).
- Stock settle waits: the frequency-adjust screen waits 100 ms after the squelch apply and 500 ms after the filter
  select, under the scheduler lock. These are generous waits, not measured settle times (retune §D).

## 5. TX keying, PTT events and the analog tone generator

- PTT press: the debounced key posts event-flag bit 0x08 on group 0x0003a4f0; release (and TOT expiry) posts 0x10.
  `main_ptt_and_channel_event_loop` @0x03012d10 consumes them. Press goes through `ptt_press_handler` @0x0305bfb8 (its
  gates) and `tx_key_from_vfo_mode_guard` @0x0305be64 to `radio_mode_entry_reinit_and_display` @0x0305baec. That sets
  `call_active` bit 3 (0x0003fdc8) and calls `radio_init_sequence` @0x0300e40c, the analog TX-on. CONFIRMED (afsk §1.1).
- TX inhibit: `tx_is_inhibited` @0x0302ed50 returns 0 when TX is allowed. Meanings of individual bits are STRUCTURAL
  (afsk §1.3).
- Calling `radio_init_sequence` directly skips the gates and the event-driven state that TOT and the release path read.
  Posting the PTT event is the route stock itself uses for TOT release. Both work in principle; the event route is
  the one the source recommends (afsk §1.4, INFERRED).
- DMR TX: `rf_tx_enable_sequence` (IRAM 0x2b440) runs only from `dmr_rf_tx_task` @0x0300dc94 (formerly FUN_0300dc94),
  and only when the channel is digital. It is not reached on analog channels. CONFIRMED (afsk §1.2).
- TOT: `call_display_countdown_and_ui_event_trigger` @0x030556cc posts 0x10 at expiry. CONFIRMED (afsk §1.1).
- Tone generator, FD6818 page 0:
  - REG_70H: [15] `tone1_gen` (also bypasses the MIC input), [14:8] tone1 gain, [7] `tone2_gen`, [6:0] tone2 gain.
  - REG_71H: tone 1 frequency word. REG_72H: tone 2 frequency word.
  - Word = Hz x 10.32444 (2^26 / 6.5 MHz). The stock literal 0x3065 (1200 Hz) matches the formula. 2200 Hz is 0x58BA by
    the same formula; that value is computed, not a stock literal. CONFIRMED for the datasheet and the stock literal
    (afsk §2).
  - Mute: REG_50H[15]. Stock values 0x3B18 (unmuted) and 0xBB18 (muted). CONFIRMED (afsk §2).
- Open for tones: the mapping from gain to deviation is not documented (OPEN). Phase continuity across a word change is
  not stated in the datasheet (INFERRED, medium-high). Pre-emphasis is in the path, so 2200 Hz comes out a few dB hotter
  than 1200 Hz unless bypassed (afsk §2).
- Stock tone timing is millisecond-class: `mmio_14000000_timer_config` @0x0301d900 programs TIMER CH1, and
  `timer_ch1_disable` @0x0301d920 (formerly `timer_ch0_disable`) stops it. The flag wake-up adds task jitter. This is
  not usable for 1200-baud timing (afsk §3, CONFIRMED).
- Local beep: `local_beep_frontend_init_and_burst` @0x03068450 (formerly `tx_rf_frontend_init_and_burst`) sets REG 0x30
  = 0x0302 and tone1 = 0xC000. It transmits no RF. CONFIRMED (afsk §1.2).
- PTT preamble: `ptt_preamble_end_ui_audio_setup_1` @0x0300e2c0 and `_2` @0x0305fbf8 (formerly `tx_enable_caller1/2`)
  set UI and audio state at the end of the preamble tones. They are not the TX-on. STRUCTURAL (afsk §1.2).

## 6. Hardware measurements (real data, RF Lab)

These come from the RF Lab tool on the test radio, measured 2026-10-15 (`feature-checklist.md`, P5). They are
hardware data, not static analysis:

- PLL lock: 1250, 1264 and 1321 us across the runs listed. The lock bit was never stale (0 of 20 trials).
- RSSI register: changes 8.7 ms after lock, in every trial. The feature checklist describes this as a fixed update
  schedule.
- Full retune: 313 us for 6 register writes.
- One FD6818 register access: about 53 us (the checklist's figure). afsk §2 also quotes a measured 52 us for the
  total of one `fd6818b_reg_write`; its source is not stated there.
- Timer: 84 counts per us.

Caveats the sources give: the checklist does not say whether the RF Lab retune included the REG 0x30 RXON re-trigger.
retune §B flags an earlier ~40 us lock figure as possibly a stale bit taken without that re-trigger, so the RF Lab
numbers are the ones to plan with. The checklist also lists the dBm reference as still open.

## 7. Summary of what is measured, verified or inferred

| Claim | Strength | Source |
|---|---|---|
| Analog channels run FM mode (WORK_MODE bit 7, FM clocks) | CONFIRMED | rx §0, §3.1 |
| Modem takes AF input on this board | HIGH config, MEDIUM spectrum | rx §1.1, §5 |
| FM RX RAM is filled by default in FM mode | MEDIUM (datasheet only) | rx §0.3 |
| FM_ADDR_SW meaning (read vs being filled) | INFERRED | rx §2, §4.3 |
| Stock never reads FM RX output | CONFIRMED (scan) | rx §3.6 |
| RF frequency is REG_38H/39H in 10 Hz units | CONFIRMED | retune §A.1-A.2 |
| RXON re-trigger via REG 0x30 0 to 0xbff1 | CONFIRMED (values), MEDIUM (REG 0x30 = REG_03H) | retune §A.3, §F |
| Stock never polls pll_lock (REG_0CH bit 9) | STRUCTURAL negative result | retune §B |
| LNA GPIO 0x22/0x24 needs manual switching for cross-band | MEDIUM-HIGH | retune §A.4 |
| TX-on is `radio_init_sequence` via the PTT event | CONFIRMED | afsk §1.1 |
| Tone word formula and 1200 Hz literal | CONFIRMED | afsk §2 |
| Gain-to-deviation mapping | OPEN | afsk §2 |
| Tone phase continuity on word change | INFERRED | afsk §2 |
| Analog speaker source is FD6818 (GPIO 0x2F = 1) | INFERRED | rx §3.2 |
| Speaker amp is GPIO 0x35 (`audio_pa_enable_gate`) | HIGH | parrot §3.1 |
| Lock about 1.25-1.32 ms; RSSI 8.7 ms after lock; ~53 us per access | Hardware (RF Lab) | feature-checklist P5 |

## 8. Open questions (from the sources)

1. Whether FM RX RAM fills with no switch beyond WORK_MODE bit 7 (rx §7.1).
2. Whether the FM engine needs an FM_RX_INTERP acknowledge or a codec-clock handshake to keep the ping-pong running (rx §7.2).
3. The exact FM_ADDR_SW semantics, and whether 0 can appear after the first buffer (rx §7.3).
4. PCM spectrum: whether the FM filters or de-emphasis tilt 1200 to 2200 Hz, and whether `af_recv_ctrl` 0x26 clips full deviation (rx §7.4-7.5).
5. Tone gain to deviation, and whether mark and space need different gains (afsk §6.3).
6. Whether a REG_71H word write resets tone phase (afsk §6.2).
7. Which `radio_mode_state` bit is the busy-channel lockout (afsk §6.4).
8. The RF settle time with the full RXON re-trigger, and AGC convergence (retune §F.5).

## Additions 2026-10-20 (from dm32uv-unleashed hardware results)

Source project: dm32uv-unleashed (not published; two radios, captures 2026-10-16). Bullets marked "datasheet" are not hardware-verified.

- **FD6818 is not register-compatible with the AT1846S.** Frequency is REG_38H/39H (not AT 0x29/0x2A), tones are REG_71H/72H (not AT 0x35/0x36). Wire 0x30 (stock 0xBFF1 RX, 0xC1FE TX) is FD6818 REG_03H. Source: `docs/at1846s-opengd77-analogy.md` section 3.
- **Registers above 0x7F need page 1.** REG_9BH, REG_96H and REG_9DH need `REG_7FH = 1` before the access and `0` after. Stock never writes page-1 registers, and `fd6818b_reg_write` (0x0002c2f4) does not page. Source: `docs/fd6818-disc-mode-rx.md` section 3 and `patches/unleashed_ui/unl_aprsrx.c` lines 43-44.
  **CORRECTION 2026-10-22 (hardware, dm32uv-fh):** the REG_7FH page switch did NOT reach page 1 through stock's 3-wire helpers. With `WRITE(0x7F,1)` / access / `WRITE(0x7F,0)` around each access, a read of "REG_9AH" returned low byte 0x50 in every run, which is page-0 REG_1AH (the band register, 0x2f50 for 370-560 MHz, FD6818 guide p.24). Writing "REG_9AH" with its low byte cleared left the receiver unable to lock, as a mis-banded REG_1AH would. "REG_96H" read 0x00 both before and after writing 6 to its low bits, and "REG_87H" read 0 throughout. So accesses above 0x7F alias to page-0 `reg & 0x7f` even with paging. No working page-1 access is known on this radio. Do not write a page-1 register this way: it overwrites a live page-0 register (0x96 to 0x16, 0x9A to the band register 0x1A, 0x9B to 0x1B). Source: hardware notes of dm32uv-fh (a frequency-hopping patch by the same author, not published), dumps c0/c1/c2 of 2026-10-22.
- **Per-bit tone retunes do not form tones.** Changing REG_71H or REG_70H per bit (833 us) ramps over ~1 ms, so 1200 and 2200 Hz never separate (captures 6-10). Two running generators with gain switching work. Source: `docs/afsk-tx.md` "Hardware results 2026-10-16, captures 4-8" and "captures 9-11".
- **tone2 needs tone1.** REG_72H alone produces nothing; tone1_gen must also be set (capture7). Source: `docs/afsk-tx.md` "Hardware results 2026-10-16, captures 4-8".
- **The FSK packet engine is baseband FSK, not AFSK.** Driven by `tone_gen_config_apply` @0x03067cc8 (REG_59H, REG_5AH-5FH): a direct carrier shift of the bit stream plus a ~1488 Hz pilot (wire 0x58 = 0x3c03). Rate word 0x3065 gave 600 baud; the length field counts bytes (capture11). Source: `docs/afsk-tx.md` "captures 9-11".
- **Stock FM_BANDWIDTH = 0x5f.** HR_C7000 0x11000500: bit 6 fmbpfon, bit 4 fmpreemphasison, bits 3:0 25 kHz selects (datasheet). Source: `docs/rx-audio-fm-mode.md` section 1.1.
- **FM Send RAM is an unused TX voice path.** Base 0x16000000; FM_VOICE_1 at +0x030, FM_VOICE_2 at +0x230, 256 big-endian int16 each. AUDIO_CONTROL (0x11000080) bit 0 selects it as the TX voice source; stock never sets it (datasheet). Source: `docs/fm-send-ram-tx.md` sections 1-2.
- **Stock FM_DEV_COEF = 0x33500.** `hr_c7000_modem_core_register_init` @0x03023608 writes tr_sig_lim 3, fm_dev_coef_r 0x35, fm_dev_coef_t 0, so stock analog TX has no modem FM voice deviation. Source: `docs/fm-send-ram-tx.md` section 4.
- **2200 Hz arrives late and weak through the radio.** Via AFOUT, GPIO 0x2F low and the modem ADC, the 2200 Hz energy lags 1200 Hz by ~2.5 samples (310 us at 8 kHz) and is 5-10 dB lower. Delaying it decodes 9 of 12 over-the-air bursts (capture2). Source: `docs/rx-audio-fm-mode.md` "Decoder study 2026-10-16"; `patches/unleashed_ui/unl_aprsrx.c` lines 84-85.
- **Squelch mutes the start of a capture.** With squelch above 0 the audio is lost for ~0.3 s after a carrier appears (squelch 3 ate the 267 ms preamble, capture5). The aprsrx comment ties the 0.3-0.7 s cut to stock code re-driving GPIO 0x2F, so the cause is not fully separated. Source: `docs/afsk-tx.md` "captures 4-8"; `patches/unleashed_ui/unl_aprsrx.c` lines 479-482.
- **REG_43H weak-signal filter.** In the stock wide value 0x3028, `firlpf_bw_for_weak` [11:9] = 000 (1.7 kHz). Source: `docs/at1846s-opengd77-analogy.md` line 93; `docs/afsk-tx.md` section on the decoder study.
