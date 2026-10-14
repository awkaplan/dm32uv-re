/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_menu_option_or_history_dispatch @ 030428bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 288 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_menu_option_or_history_dispatch(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [20];
  char cStack_16;
  
  bVar1 = p_vfo_display_state->flags_0x8 >> 4;
  iVar3 = contact_count_range_calc(bVar1);
  puVar2 = PTR_PTR_03042ae4;
  if (iVar3 == 0) {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03042ae4 + uVar4 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042ae0 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03042ae8 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)p_active_screen_index_list,
                 (byte *)((int)p_active_screen_index_list + 2));
      list_row_text_buffer_clear();
    }
  }
  else {
    iVar3 = get_state_field_03016e98();
    if (iVar3 == 0) {
      if (*(char *)PTR_DAT_03042954 == '\x01') {
        history_record_lookup_by_type(bVar1,*(short *)PTR_DAT_0304296c + 1,auStack_2c);
        iVar3 = p_list_row_text_buffer;
        strcpy_ck803s(p_list_row_text_buffer,auStack_2a);
        strcpy_ck803s(iVar3 + 0x1a,auStack_2a);
        *(char *)PTR_PTR_03042974 = cStack_16;
        if (cStack_16 == '\x03') {
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfb;
        }
        else {
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfb | 4
          ;
        }
        if (bVar1 == 1) {
          menu_option_list_dispatch
                    (0xe,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
        }
        else {
          menu_option_list_dispatch
                    (0xf,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
        }
      }
      puVar2 = PTR_PTR_03042ad4;
      if (*(short *)p_active_screen_index_list == 0) {
        history_queue_pop();
      }
      else {
        uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        *(undefined1 *)p_active_screen_option_count =
             *(undefined1 *)(PTR_PTR_03042ad4 + uVar4 * 2 + 1);
        *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
        *(undefined1 *)PTR_active_screen_subtype_03042ae0 =
             *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5);
      }
    }
    else {
      get_state_field_03016e98();
      noop_stub_03016ea0();
    }
  }
  return;
}

