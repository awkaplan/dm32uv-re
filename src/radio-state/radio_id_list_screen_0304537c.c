/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_id_list_screen @ 0304537c (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_id_list_screen(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  
  if (*(char *)PTR_DAT_03045448 == '\x01') {
    menu_option_list_dispatch
              (0x20,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
    if (*(byte *)PTR_DAT_0304544c < *(byte *)PTR_DAT_03045450) {
      uVar4 = flash_field_block67_signed_threshold_check();
      *PTR_DAT_03045454 = uVar4;
      radio_id_entry_read_and_terminate(*(undefined1 *)PTR_DAT_0304544c,p_list_row_text_buffer);
    }
    else {
      *PTR_DAT_03045454 = 1;
      puVar2 = PTR_s_Radio__d_0304545c;
      uVar4 = p_list_row_text_buffer;
      puVar1 = PTR_DAT_03045450;
      cVar6 = -1;
      do {
        number_to_string_format_2args(uVar4,puVar2,*(undefined1 *)puVar1);
        iVar3 = locked_radio_id_lookup_by_string(uVar4,*(undefined1 *)puVar1);
        if (iVar3 == 0) break;
        cVar6 = cVar6 + -1;
      } while (cVar6 != '\0');
    }
  }
  puVar1 = PTR_PTR_03045460;
  if (*(short *)p_active_screen_index_list == 0) {
    history_queue_pop();
  }
  else {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03045460 + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar1[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03045428 = *(undefined1 *)((int)puVar1 + uVar5 * 8 + 5)
    ;
  }
  return;
}

