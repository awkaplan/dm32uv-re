/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frequency_step_cycle_and_field_select_b @ 03048c6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void frequency_step_cycle_and_field_select_b(void)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  byte bVar4;
  ushort uVar5;
  
  puVar1 = p_active_screen_state_word;
  uVar2 = cyclic_value_step(*(undefined1 *)p_active_screen_state_word,0xff,1,0);
  *(undefined1 *)puVar1 = uVar2;
  display_fill_rect(0x14,0x82,0xdc,0x9a,0x7e0);
  display_draw_number_centered(0x82,0,0x7e0,(uint)PTR_s__d_Min__03048d98);
  if (1 < (byte)(*(char *)PTR_DAT_03048ee0 - 1U)) {
    return;
  }
  bVar4 = *(char *)PTR_DAT_03048ee4 + 1;
  uVar5 = (ushort)bVar4;
  *(byte *)PTR_DAT_03048ee4 = bVar4;
  if (bVar4 < 6) {
    if (5 < bVar4) {
      return;
    }
    uVar3 = 1 << ((int)(char)bVar4 & 0x3fU);
    if ((uVar3 & 0x30) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0x18 + (ushort)bVar4 * 0xc
      ;
      return;
    }
    if ((uVar3 & 0xc) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0xc + (ushort)bVar4 * 0xc;
      return;
    }
    if ((uVar3 & 3) == 0) {
      return;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03048ee4 = 0;
    uVar5 = 0;
  }
  *(ushort *)p_text_entry_current_char = uVar5 * 0xc + *(short *)PTR_DAT_03048ee8;
  return;
}

