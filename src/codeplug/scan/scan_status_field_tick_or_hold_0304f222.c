/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_status_field_tick_or_hold @ 0304f222 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_status_field_tick_or_hold(void)

{
  if (*(char *)PTR_DAT_0304f2f8 == '\x03') {
    write_status_mode_byte_pair(0x2a,1);
  }
  else {
    scan_state_tick();
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f2e0 + DAT_0304f2e4),0);
  }
  return;
}

