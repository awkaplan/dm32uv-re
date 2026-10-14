/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_key_dispatch_or_clear_flags @ 03037620 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_key_dispatch_or_clear_flags(void)

{
  radio_mode_state_0003e318 *prVar1;
  
  prVar1 = p_radio_mode_state_0003e318;
  if ((*(char *)PTR_active_screen_subtype_03037678 == '\b') ||
     (*(char *)PTR_active_screen_subtype_03037678 == '\n')) {
    text_entry_enter_backspace_dispatch();
  }
  else {
    p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0x7f;
    prVar1->field_0x8 = prVar1->field_0x8 & 0xd8;
    history_queue_pop();
  }
  return;
}

