/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_type0x2f_flag_init_submode1 @ 0304211e (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_type0x2f_flag_init_submode1(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  *(undefined1 *)p_active_screen_state_word = 1;
  puVar2 = PTR_DAT_030421a8;
  PTR_DAT_030421a8[3] = PTR_DAT_030421a8[3] & 0x7f | 0x80;
  bVar1 = puVar2[4];
  p_vfo_freq_display_state->field_0x5d = p_vfo_freq_display_state->field_0x5d & 0xfe | 1;
  *(undefined1 *)PTR_DAT_030421ac = 0;
  *(undefined1 *)PTR_active_screen_subtype_0304216c = 0x2f;
  puVar2[4] = bVar1 & 0xfc | 1;
  return;
}

