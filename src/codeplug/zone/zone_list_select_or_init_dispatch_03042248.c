/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_list_select_or_init_dispatch @ 03042248 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void zone_list_select_or_init_dispatch(void)

{
  byte bVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  short local_10;
  undefined1 local_e [2];
  
  uVar4 = get_zone_count();
  puVar2 = PTR_PTR_03042368;
  if (*(byte *)PTR_DAT_03042364 < uVar4) {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03042368 + uVar4 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042340 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_0304236c == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    cVar3 = *(char *)p_active_screen_state_word;
    *(char *)p_active_screen_flag_0003e5d5 = cVar3 + '\x01';
    *(undefined1 *)PTR_DAT_03042358 = 1;
    *(char *)p_menu_selected_item_index = cVar3;
    channel_offset_minus_0x10(*(char *)PTR_DAT_03042364 + '\x01',local_e,&local_10);
    flash_field_read_cached(local_e[0],local_10 + 0x10,DAT_03042370,1);
  }
  else if (uVar4 < 0xfa) {
    dialog_request_init(0x10);
    if (*(char *)PTR_DAT_0304236c == '\x01') {
      cVar3 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_0304237c = cVar3 + '\x01';
    }
    puVar2 = PTR_DAT_03042380;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03042380 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03042340 = *(undefined1 *)((int)puVar2 + 5);
  }
  else {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_03042374 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
  }
  return;
}

