/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_flags1_group_dispatch @ 0305e9f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void event_flags1_group_dispatch(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(1);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) != 0) {
        tx_led_tone_off_on_event_flag();
        update_event_flags_byte_dispatch(1,4);
      }
    }
    else {
      tx_forbid_event_flag5_handler();
      update_event_flags_byte_dispatch(1,2);
    }
  }
  else {
    tx_dialog_event_state_dispatcher();
    update_event_flags_byte_dispatch(1,1);
  }
  return;
}

