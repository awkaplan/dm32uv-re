/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: quick_text_insert_and_commit @ 03051e60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void quick_text_insert_and_commit(void)

{
  int iVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x6 + DAT_030520f8 + 2) == '\x01') {
    iVar1 = quick_text_insert_and_rewrap(*(undefined1 *)p_active_screen_state_word);
    if (iVar1 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03052100 + DAT_03052104),0);
    }
    else {
      history_queue_pop();
      history_queue_pop();
    }
  }
  return;
}

