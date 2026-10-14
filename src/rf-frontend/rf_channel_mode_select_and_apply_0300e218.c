/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_channel_mode_select_and_apply @ 0300e218 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_channel_mode_select_and_apply(void)

{
  ushort uVar1;
  byte bVar2;
  
  if (((p_dm32_settings_block04[0x6d] & 4) == 0) ||
     ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
    uVar1 = *(ushort *)&p_vfo_display_state->field_0x11_0;
  }
  else {
    uVar1 = 0x2625;
  }
  bVar2 = PTR_DAT_0300e2a4[0x35] & 0xc;
  if ((bVar2 == 4) ||
     (((p_dm32_settings_block04[0x6d] & 4) != 0 &&
      ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)))) {
    ctcss_dcs_tone_apply(1,uVar1);
  }
  else if (bVar2 == 8) {
    ctcss_dcs_tone_apply(2,uVar1 & 0x7ff);
  }
  else if (bVar2 == 0xc) {
    ctcss_dcs_tone_apply(3,uVar1 & 0x7ff);
  }
  else {
    ctcss_dcs_tone_apply(0,0xffff);
  }
  return;
}

