/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_dialog_request_by_code_dispatch @ 0305169c (file base 0x03000000; code starts at 0x03001000)
 * Size: 130 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_dialog_request_by_code_dispatch(void)

{
  char cVar1;
  int iVar2;
  uint unaff_r4;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03051748 + 2);
  if (cVar1 == '\0') {
    iVar2 = quick_text_insert_and_rewrap(*(undefined1 *)p_active_screen_state_word);
    if (iVar2 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051738 + DAT_0305173c),0);
    }
    else {
      history_queue_pop();
      history_queue_pop();
    }
  }
  else if (cVar1 == '\x03') {
    if (*(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03051750 + 2) == '\0') {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051738 + DAT_0305173c),0);
    }
    else {
      memcpy_bytes_iram(DAT_03051754,DAT_03051758,3);
      if ((byte)p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] < 6) {
                    /* WARNING: Could not recover jumptable at 0x0305171c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_PTR_03051760
                   [(byte)p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2]] &
                  0xfffffffe))();
        return;
      }
      if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
        dialog_request_enqueue(unaff_r4,(void *)*PTR_DAT_03051af4);
      }
      else {
        format_and_write_status_field2
                  (**(undefined4 **)
                     (PTR_PTR_03051af0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051af8 + DAT_03051afc),0);
    }
  }
  return;
}

