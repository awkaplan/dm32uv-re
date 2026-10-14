/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_gate_call_record_toggle_a @ 03040b1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_gate_call_record_toggle_a(void)

{
  if (*(char *)p_active_screen_state_word == '\0') {
    tx_gate_write_call_record(0);
  }
  else {
    *(undefined1 *)p_active_screen_state_word = 0;
    tx_gate_write_call_record(1);
  }
  radio_id_detail_screen();
  return;
}

