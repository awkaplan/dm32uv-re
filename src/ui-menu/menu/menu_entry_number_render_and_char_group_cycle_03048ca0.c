/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_entry_number_render_and_char_group_cycle @ 03048ca0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_entry_number_render_and_char_group_cycle(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = p_dm32_settings_block04[0x3c];
  p_dm32_settings_block04[0x3c] = cVar1 - 1U;
  if ((byte)(cVar1 - 1U) < 5) {
    p_dm32_settings_block04[0x3c] = 0x3c;
  }
  display_fill_rect(0x14,0x82,0xdc,0x9a,0x7e0);
  display_draw_number_centered(0x82,0,0x7e0,(uint)PTR_s__d_S__03048d9c);
  if (1 < (byte)(*(char *)PTR_DAT_03048ee0 - 1U)) {
    return;
  }
  bVar3 = *(char *)PTR_DAT_03048ee4 + 1;
  uVar4 = (ushort)bVar3;
  *(byte *)PTR_DAT_03048ee4 = bVar3;
  if (bVar3 < 6) {
    if (5 < bVar3) {
      return;
    }
    uVar2 = 1 << ((int)(char)bVar3 & 0x3fU);
    if ((uVar2 & 0x30) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0x18 + (ushort)bVar3 * 0xc
      ;
      return;
    }
    if ((uVar2 & 0xc) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0xc + (ushort)bVar3 * 0xc;
      return;
    }
    if ((uVar2 & 3) == 0) {
      return;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03048ee4 = 0;
    uVar4 = 0;
  }
  *(ushort *)p_text_entry_current_char = uVar4 * 0xc + *(short *)PTR_DAT_03048ee8;
  return;
}

