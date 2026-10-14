/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_dispatch_by_count_range @ 030439ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_dispatch_by_count_range(void)

{
  int iVar1;
  
  iVar1 = contact_count_range_calc(p_vfo_display_state->flags_0x8 >> 4);
  if (iVar1 == 0) {
    text_entry_dialog_init_two_field();
  }
  else {
    contact_list_select_and_history_dispatch();
  }
  return;
}

