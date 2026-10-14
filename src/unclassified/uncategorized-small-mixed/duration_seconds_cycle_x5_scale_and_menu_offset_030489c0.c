/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: duration_seconds_cycle_x5_scale_and_menu_offset @ 030489c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void duration_seconds_cycle_x5_scale_and_menu_offset(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  ushort uVar5;
  
  puVar1 = p_active_screen_state_word;
  iVar2 = cyclic_value_step(*(undefined1 *)p_active_screen_state_word,10,1,1);
  *(char *)puVar1 = (char)iVar2;
  duration_seconds_decimal_display(iVar2 * 5);
  if (1 < (byte)(*(char *)PTR_DAT_03048bc4 - 1U)) {
    return;
  }
  if (*(char *)PTR_DAT_03048bc8 == '\0') {
    *(undefined1 *)PTR_DAT_03048bc8 = 5;
    uVar5 = 5;
  }
  else {
    bVar4 = *(char *)PTR_DAT_03048bc8 - 1;
    uVar5 = (ushort)bVar4;
    *(byte *)PTR_DAT_03048bc8 = bVar4;
    if (5 < bVar4) {
      return;
    }
    uVar3 = 1 << ((int)(char)bVar4 & 0x3fU);
    if ((uVar3 & 0x30) == 0) {
      if ((uVar3 & 0xc) != 0) {
        *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0xc + uVar5 * 0xc;
        return;
      }
      if ((uVar3 & 3) == 0) {
        return;
      }
      *(ushort *)p_text_entry_current_char = uVar5 * 0xc + *(short *)PTR_DAT_03048bcc;
      return;
    }
  }
  *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0x18 + uVar5 * 0xc;
  return;
}

