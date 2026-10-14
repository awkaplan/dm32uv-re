/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: standby_timeout_step_down_wrap97_display @ 03048c00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void standby_timeout_step_down_wrap97_display(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  if (p_dm32_settings_block04[0x36] == '\0') {
    p_dm32_settings_block04[0x36] = 0x61;
    uVar3 = 0x61;
  }
  else {
    bVar1 = p_dm32_settings_block04[0x36] - 1;
    uVar3 = (uint)bVar1;
    p_dm32_settings_block04[0x36] = bVar1;
    if (uVar3 == 0) {
      settings_duration_seconds_display(0);
      goto text_entry_char_group_index_advance_and_cursor_x_set;
    }
  }
  settings_duration_seconds_display((uVar3 - 1) * 5 + 0xf);
text_entry_char_group_index_advance_and_cursor_x_set:
  if (1 < (byte)(*(char *)PTR_DAT_03048ee0 - 1U)) {
    return;
  }
  bVar1 = *(char *)PTR_DAT_03048ee4 + 1;
  uVar2 = (ushort)bVar1;
  *(byte *)PTR_DAT_03048ee4 = bVar1;
  if (bVar1 < 6) {
    if (5 < bVar1) {
      return;
    }
    uVar3 = 1 << ((int)(char)bVar1 & 0x3fU);
    if ((uVar3 & 0x30) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0x18 + (ushort)bVar1 * 0xc
      ;
      return;
    }
    if ((uVar3 & 0xc) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0xc + (ushort)bVar1 * 0xc;
      return;
    }
    if ((uVar3 & 3) == 0) {
      return;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03048ee4 = 0;
    uVar2 = 0;
  }
  *(ushort *)p_text_entry_current_char = uVar2 * 0xc + *(short *)PTR_DAT_03048ee8;
  return;
}

