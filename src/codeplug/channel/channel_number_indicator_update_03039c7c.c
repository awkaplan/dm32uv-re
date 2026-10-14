/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_number_indicator_update @ 03039c7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_number_indicator_update(int param_1,undefined2 param_2)

{
  short sVar1;
  int iVar2;
  ushort fg;
  byte abStack_20 [12];
  
  if (param_1 == 0) {
    fg = PTR_DAT_03039e24[(byte)p_dm32_settings_block04[100]];
    sVar1 = 0x62;
  }
  else {
    fg = PTR_DAT_03039e24[(byte)p_dm32_settings_block04[0x65]];
    sVar1 = 0xd8;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    number_to_string_format_2args(abStack_20,PTR_LAB_03039e28,param_2);
    sVar1 = strlen_ck803s(abStack_20);
    display_fill_rect(0xb4,0x81,0xe6,0x99,0);
    display_draw_string_gb2312(0x81,sVar1 * -0xc + 0xe6,abStack_20,fg,0);
  }
  else {
    number_to_string_format_2args(abStack_20,PTR_s_CH__d_03039e2c,param_2);
    display_fill_rect(0xaa,sVar1,0xe6,sVar1 + 0x10,0);
    iVar2 = strlen_ck803s(abStack_20);
    display_draw_glyph_row_mutex(sVar1,iVar2 * -8 + 0xdcU & 0xfffc,abStack_20,fg,0);
  }
  return;
}

