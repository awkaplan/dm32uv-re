/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event10_flag_dispatch_and_ptt_ui_state @ 0305e290 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void event10_flag_dispatch_and_ptt_ui_state(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(10);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) != 0) {
      update_event_flags_byte_dispatch(10,2);
    }
  }
  else {
    update_event_flags_byte_dispatch(10,1);
    call_teardown_on_event_flag();
    *(undefined1 *)p_tx_ptt_ui_state = 10;
  }
  return;
}

