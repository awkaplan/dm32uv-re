/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_forbid_event_flag5_handler @ 0305e9cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_forbid_event_flag5_handler(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(5);
  if ((bVar1 & 1) != 0) {
    update_event_flags_byte_dispatch(5,1);
    tx_led_or_tone_off_conditional();
    *(undefined1 *)p_tx_ptt_ui_state = 10;
    PTR_DAT_0305eb24[0x328] = 1;
  }
  return;
}

