/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ctcss_tone_freq_display @ 0303011c (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ctcss_tone_freq_display(undefined1 *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined1 auStack_14 [12];
  
  puVar1 = PTR_LAB_03030208;
  uVar2 = (*(byte *)p_active_screen_state_word - 1) * 2 & 0xffff;
  if ((PTR_DAT_030301fc[3] & 0x80) != 0) {
    *param_1 = PTR_LAB_03030208[uVar2];
    param_1[1] = puVar1[uVar2 + 1];
  }
  uVar2 = bcd_frequency_decode(PTR_LAB_03030208 + uVar2,2);
  number_to_string_format_2args
            (auStack_14,PTR_s__d__dHz_030301ec,(uVar2 & 0xffff) / 10,(uVar2 & 0xffff) % 10);
  display_draw_number_centered(0x82,0xffff,0,(uint)auStack_14);
  return;
}

