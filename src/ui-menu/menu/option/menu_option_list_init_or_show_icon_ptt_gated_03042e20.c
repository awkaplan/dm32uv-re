/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_or_show_icon_ptt_gated @ 03042e20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_or_show_icon_ptt_gated(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_03042f70;
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03042f44 + 2) == '\0') {
    if ((p_radio_mode_state_0003e318[1].flags_0x7 & 2) != 0) {
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfd;
    }
    puVar2 = PTR_DAT_03042f54;
    bVar1 = PTR_DAT_03042f54[4];
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03042f60 = puVar2[5];
    *(ushort *)p_active_screen_index_list = (ushort)bVar1;
    *(undefined1 *)PTR_DAT_03042f68 = 3;
  }
  else if (PTR_DAT_03042f54[4] == '\0') {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_03042f74 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03042f70 + uVar4 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042f60 = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5)
    ;
  }
  return;
}

