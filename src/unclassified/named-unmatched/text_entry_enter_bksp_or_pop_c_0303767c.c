/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_enter_bksp_or_pop_c @ 0303767c (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_enter_bksp_or_pop_c(void)

{
  if ((*(char *)PTR_active_screen_subtype_03037800 == '\b') ||
     (*(char *)PTR_active_screen_subtype_03037800 == '\n')) {
    text_entry_enter_backspace_dispatch();
  }
  else {
    history_queue_pop();
  }
  return;
}

