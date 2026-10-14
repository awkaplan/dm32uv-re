/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_channel_frequency @ 03030714 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_channel_frequency(char param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (param_1 == '\0') {
    uVar2 = PTR_DAT_030308c8[(byte)p_dm32_settings_block04[100]];
    uVar1 = 0x3b;
  }
  else {
    uVar2 = PTR_DAT_030308c8[(byte)p_dm32_settings_block04[0x65]];
    uVar1 = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    uVar1 = 0x59;
  }
  format_and_plot_number_with_decimals(param_1,uVar1,8,uVar2,0,param_2);
  if ((p_radio_mode_state_0003e318[2].field_0x1 & 0x24) == 0x24) {
    p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xdf;
    alarm_banner_draw(param_1);
  }
  return;
}

