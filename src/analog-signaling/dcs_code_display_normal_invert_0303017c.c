/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dcs_code_display_normal_invert @ 0303017c (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dcs_code_display_normal_invert(undefined1 *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 auStack_14 [12];
  
  uVar2 = (*(byte *)p_active_screen_state_word - 1) * 2 & 0xffff;
  if ((PTR_DAT_030301fc[3] & 0x80) != 0) {
    *param_1 = PTR_LAB_0303020c[uVar2];
    if ((PTR_DAT_030301fc[4] & 4) == 0) {
      param_1[1] = PTR_LAB_0303020c[uVar2 + 1] + -0x80;
    }
    else {
      param_1[1] = PTR_LAB_0303020c[uVar2 + 1] + -0x40;
    }
  }
  uVar1 = bcd_frequency_decode(PTR_LAB_0303020c + uVar2,2);
  if ((PTR_DAT_030301fc[4] & 4) == 0) {
    number_to_string_format_2args(auStack_14,_DAT_03030344,uVar1);
  }
  else {
    number_to_string_format_2args(auStack_14,PTR_s_D_03dI_03030210,uVar1);
  }
  display_fill_rect(10,0x82,0xe6,0x9a,0);
  display_draw_number_centered(0x82,0xffff,0,(uint)auStack_14);
  return;
}

