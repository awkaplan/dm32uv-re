/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_change_tx_led_reset @ 030553ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 222 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_change_tx_led_reset(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = *(char *)PTR_DAT_0305551c;
  if (cVar1 == '\0') {
    sVar2 = *(short *)PTR_DAT_03055520;
    *(ushort *)PTR_DAT_03055520 = sVar2 + 1U;
    if (0xf < (ushort)(sVar2 + 1U)) {
      *(undefined2 *)PTR_DAT_03055520 = 0;
      *(undefined1 *)PTR_DAT_0305551c = 1;
      modem_fm_bandwidth_write_0x5f(1);
      modem_fm_ptt_set(1);
      radio_init_sequence();
      tx_led_or_tone_off();
      tx_led_or_tone_off_conditional();
      fd6818b_reg50_tx_audio_unmute_set();
      status_byte_bit5_set_clear_wrapper(0,1);
    }
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)PTR_DAT_03055520;
    *(ushort *)PTR_DAT_03055520 = sVar2 + 1U;
    if (0x1e < (ushort)(sVar2 + 1U)) {
      *(undefined2 *)PTR_DAT_03055520 = 0;
      *(undefined1 *)PTR_DAT_0305551c = 2;
      tx_audio_dac_envelope_ramp(1,0,0);
      tx_led_or_tone_on();
      pa_band_select_vhf_uhf_gpio(0);
      modem_fm_bandwidth_write_0x5f(1);
      modem_fm_ptt_set(0);
      channel_change_apply_squelch();
      audio_ctrl_fm_play_set(1);
      fd6818b_reg47_tx_bypass_or_rx_afout();
      audio_pa_enable_gate(1);
      tx_led_or_tone_off_conditional_variant_030609ec();
    }
  }
  else if ((cVar1 == '\x02') &&
          (sVar2 = *(short *)PTR_DAT_03055520, *(ushort *)PTR_DAT_03055520 = sVar2 + 1U,
          0x1e < (ushort)(sVar2 + 1U))) {
    *(undefined2 *)PTR_DAT_03055520 = 0;
    *(undefined1 *)PTR_DAT_0305551c = 0;
    fd6818b_reg47_afout_clear_mode();
    audio_pa_enable_gate(0);
    audio_ctrl_fm_play_set(0);
    tx_led_or_tone_off();
    tx_led_or_tone_on();
  }
  return;
}

