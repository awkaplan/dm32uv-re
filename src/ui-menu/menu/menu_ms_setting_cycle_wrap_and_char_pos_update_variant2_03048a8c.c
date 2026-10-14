/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_ms_setting_cycle_wrap_and_char_pos_update_variant2 @ 03048a8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_ms_setting_cycle_wrap_and_char_pos_update_variant2(void)

{
  undefined4 *puVar1;
  undefined1 value;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  
  puVar1 = p_active_screen_state_word;
  value = cyclic_value_step(*(undefined1 *)p_active_screen_state_word,0xfa,0xf,1);
  *(undefined1 *)puVar1 = value;
  display_clear_and_draw_scaled_number_ms_label(value);
  if (1 < (byte)(*(char *)PTR_DAT_03048bc4 - 1U)) {
    return;
  }
  if (*(char *)PTR_DAT_03048bc8 == '\0') {
    *(undefined1 *)PTR_DAT_03048bc8 = 5;
    uVar4 = 5;
  }
  else {
    bVar3 = *(char *)PTR_DAT_03048bc8 - 1;
    uVar4 = (ushort)bVar3;
    *(byte *)PTR_DAT_03048bc8 = bVar3;
    if (5 < bVar3) {
      return;
    }
    uVar2 = 1 << ((int)(char)bVar3 & 0x3fU);
    if ((uVar2 & 0x30) == 0) {
      if ((uVar2 & 0xc) != 0) {
        *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0xc + uVar4 * 0xc;
        return;
      }
      if ((uVar2 & 3) == 0) {
        return;
      }
      *(ushort *)p_text_entry_current_char = uVar4 * 0xc + *(short *)PTR_DAT_03048bcc;
      return;
    }
  }
  *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048bcc + 0x18 + uVar4 * 0xc;
  return;
}

