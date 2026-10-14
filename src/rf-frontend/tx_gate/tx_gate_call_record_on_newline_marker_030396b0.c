/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_gate_call_record_on_newline_marker @ 030396b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_gate_call_record_on_newline_marker(void)

{
  if (*(char *)PTR_active_screen_subtype_030397d4 == '\n') {
    tx_gate_write_call_record(1);
    scan_monitor_mode_cycle_advance();
  }
  else {
    tx_gate_write_call_record(0);
  }
  return;
}

