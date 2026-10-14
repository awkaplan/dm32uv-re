/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_history_pop_or_scan_action_dispatch @ 0304f070 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_history_pop_or_scan_action_dispatch(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = contact_count_range_calc(p_vfo_display_state->flags_0x8 >> 4);
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304f148 + 2);
  if (cVar1 == '\0') {
    if (iVar2 == 0) {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f14c + 2);
      if (cVar1 == '\0') {
        if (*(char *)PTR_DAT_0304f150 == '\x03') {
          history_queue_pop();
          strcpy_ck803s(p_list_row_text_buffer,p_text_entry_buffer);
        }
        else {
          scan_state_tick();
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
        }
      }
      else if (cVar1 == '\x01') {
        iVar2 = ascii_digits_to_uint();
        if (iVar2 == 1) {
          history_queue_pop();
          strcpy_ck803s(DAT_0304f15c,_DAT_0304f160);
        }
        else {
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
        }
      }
    }
    else {
      uVar3 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f14c + 2);
      if (uVar3 < 6) {
                    /* WARNING: Could not recover jumptable at 0x0304f112. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_PTR_0304f164[uVar3] & 0xfffffffe))();
        return;
      }
    }
  }
  else if (cVar1 == '\x03') {
    write_status_mode_byte_pair(0x2a,1);
  }
  else if ((cVar1 == '\x04') &&
          (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304f304 + 2) == '\0')) {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f308 + 2);
    if (cVar1 == '\0') {
      if (*(char *)p_active_screen_state_word == '\0') {
        *(byte *)PTR_DAT_0304f30c = *(byte *)PTR_DAT_0304f30c & 0xfe | 1;
      }
      else {
        *(byte *)PTR_DAT_0304f484 = *(byte *)PTR_DAT_0304f484 & 0xfe;
      }
      contact_name_field_encode_to_display_buffer
                (*(byte *)PTR_DAT_0304f484 & 1,*(byte *)PTR_DAT_0304f484 >> 2 & 0xf,
                 (int)PTR_DAT_0304f484 + 1);
      packed_flags_0x67_write();
      menu_row_highlight_draw();
      dialog_show_icon_and_number_from_ptr();
    }
    else if (cVar1 == '\x01') {
      if (*(char *)p_active_screen_state_word == '\0') {
        *(byte *)PTR_DAT_0304f484 = *(byte *)PTR_DAT_0304f484 & 0xc3;
      }
      else {
        *(byte *)PTR_DAT_0304f484 = *(byte *)PTR_DAT_0304f484 & 0xc3 | 4;
      }
      contact_name_field_encode_to_display_buffer
                (*(byte *)PTR_DAT_0304f484 & 1,*(byte *)PTR_DAT_0304f484 >> 2 & 0xf,
                 (int)PTR_DAT_0304f484 + 1);
      packed_flags_0x67_write();
      menu_row_highlight_draw();
      dialog_show_icon_and_number_from_ptr();
    }
  }
  return;
}

