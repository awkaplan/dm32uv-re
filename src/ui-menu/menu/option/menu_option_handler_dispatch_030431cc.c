/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_handler_dispatch @ 030431cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 288 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_handler_dispatch(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  puVar6 = PTR_PTR_03043328;
  puVar5 = PTR_PTR_03043324;
  puVar4 = PTR_PTR_03043320;
  puVar3 = PTR_PTR_03043308;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03043300 + 2);
  if (cVar1 == '\x01') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043320 + uVar7 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar4[uVar7 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043314 = *(undefined1 *)((int)puVar4 + uVar7 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043318 == '\x01') {
      menu_option_list_dispatch(0x16,p_active_screen_index_list,p_active_screen_index_list + 1);
    }
  }
  else if (cVar1 == '\0') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03043308 + uVar7 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar3[uVar7 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043314 = *(undefined1 *)((int)puVar3 + uVar7 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043318 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar1 == '\x02') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043324 + uVar7 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar5[uVar7 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043314 = *(undefined1 *)((int)puVar5 + uVar7 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043318 == '\x01') {
      menu_option_list_dispatch(0x13,p_active_screen_index_list,p_active_screen_index_list + 1);
    }
  }
  else if (cVar1 == '\x03') {
    uVar7 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043328 + uVar7 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar6[uVar7 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043314 = *(undefined1 *)((int)puVar6 + uVar7 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043318 == '\x01') {
      menu_option_list_dispatch(0x15,p_active_screen_index_list,p_active_screen_index_list + 1);
    }
  }
  return;
}

