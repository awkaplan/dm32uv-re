/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_dialog_request_by_code_dispatch_b @ 0304ece4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 218 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_dialog_request_by_code_dispatch_b(void)

{
  char cVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint unaff_r4;
  byte local_24 [19];
  undefined1 auStack_11 [5];
  
  if ((*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0304edc8 + 2) == '\0') &&
     (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304edcc + 2) == '\x02')) {
    *(undefined1 *)PTR_DAT_0304edd0 = 0;
    *PTR_DAT_0304edd8 = *p_text_entry_current_char_alias;
    local_24[0] = p_active_screen_index_list[*p_active_screen_state_word + 2];
  }
  else {
    cVar1 = *(char *)PTR_DAT_0304edd0;
    if (cVar1 == '\0') {
      uVar4 = 1;
    }
    else {
      if (cVar1 == '\x01') {
        *(undefined1 *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ede4 + 2) = 0;
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ede4 + 2) = 1;
      }
      else if (cVar1 == '\x03') {
        *(undefined1 *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ede4 + 2) = 2;
      }
      else if (cVar1 == '\x04') {
        *(undefined1 *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ede4 + 2) = 3;
      }
      else if (cVar1 == '\x05') {
        *(undefined1 *)((uint)p_menu_screen_state->index_0x4 + DAT_0304ede4 + 2) = 4;
      }
      uVar4 = 5;
    }
    history_record_lookup_by_type(uVar4,*(short *)PTR_DAT_0304ede8 + 1,local_24);
    memcpy_bytes_iram(PTR_DAT_0304edd8,auStack_11,3);
    local_24[0] = p_active_screen_index_list[*p_active_screen_state_word + 2];
  }
  if (local_24[0] < 6) {
                    /* WARNING: Could not recover jumptable at 0x0304edbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0304edec[local_24[0]] & 0xfffffffe))();
    return;
  }
  if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
    dialog_request_enqueue(unaff_r4,(void *)*PTR_DAT_0304f124);
  }
  else {
    format_and_write_status_field2
              (**(undefined4 **)
                 (PTR_PTR_0304f120 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  psVar2 = p_active_screen_index_list;
  menu_option_list_dispatch(1,p_active_screen_index_list,p_active_screen_index_list + 1);
  puVar3 = PTR_PTR_0304f12c;
  if (*psVar2 == 0) {
    history_queue_pop();
  }
  else {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_0304f12c + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304f138 = *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5)
    ;
  }
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
  return;
}

