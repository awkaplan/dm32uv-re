/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: standby_timeout_step_and_char_picker_offset @ 030488dc (file base 0x03000000; code starts at 0x03001000)
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

void standby_timeout_step_and_char_picker_offset(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  if ((byte)p_dm32_settings_block04[0x36] < 0x61) {
    bVar2 = p_dm32_settings_block04[0x36] + 1;
    p_dm32_settings_block04[0x36] = bVar2;
    if (bVar2 != 0) {
      settings_duration_seconds_display((bVar2 - 1) * 5 + 0xf);
      goto text_entry_char_group_index_retreat_and_cursor_x_set;
    }
  }
  else {
    p_dm32_settings_block04[0x36] = 0;
  }
  settings_duration_seconds_display(0);
text_entry_char_group_index_retreat_and_cursor_x_set:
  if (1 < (byte)(*(char *)PTR_DAT_03048bc4 - 1U)) {
    return;
  }
  if (*(char *)PTR_DAT_03048bc8 == '\0') {
    *(undefined1 *)PTR_DAT_03048bc8 = 5;
    uVar3 = 5;
  }
  else {
    bVar2 = *(char *)PTR_DAT_03048bc8 - 1;
    uVar3 = (ushort)bVar2;
    *(byte *)PTR_DAT_03048bc8 = bVar2;
    if (5 < bVar2) {
      return;
    }
    uVar1 = 1 << ((int)(char)bVar2 & 0x3fU);
    if ((uVar1 & 0x30) == 0) {
      if ((uVar1 & 0xc) != 0) {
        *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0xc + uVar3 * 0xc;
        return;
      }
      if ((uVar1 & 3) == 0) {
        return;
      }
      *(ushort *)p_text_entry_current_char = uVar3 * 0xc + *(short *)PTR_DAT_03048bcc;
      return;
    }
  }
  *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0x18 + uVar3 * 0xc;
  return;
}

