/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_field_glyph_or_ascii_render @ 0301aafc (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_field_glyph_or_ascii_render(int param_1__w,undefined4 param_2,undefined4 param_3,int param_4__w)

{
  char param_1 = (char)param_1__w;
  undefined2 param_4 = (undefined2)param_4__w;
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (param_1 == '\0') {
    uVar2 = PTR_DAT_0301ac00[(byte)p_dm32_settings_block04[0x66]];
    uVar1 = 0x62;
  }
  else {
    uVar2 = PTR_DAT_0301ac00[(byte)p_dm32_settings_block04[0x67]];
    uVar1 = 0xd8;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    display_draw_string_ascii_mixed(0x81,10,param_2,0xe,uVar2,param_4);
  }
  else {
    display_draw_glyph_row_mutex(uVar1,0x14,param_2,uVar2,param_4);
  }
  return;
}

