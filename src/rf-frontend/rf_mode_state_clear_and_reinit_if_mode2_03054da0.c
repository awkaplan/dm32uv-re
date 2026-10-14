/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_mode_state_clear_and_reinit_if_mode2 @ 03054da0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_mode_state_clear_and_reinit_if_mode2(void)

{
  undefined4 *puVar1;
  
  PTR_DAT_03054dc4[2] = 0;
  if (*(char *)((int)PTR_DAT_03054dc0 + 1) == '\x02') {
    rf_transceiver_mode_init(2);
  }
  puVar1 = PTR_DAT_03054dc0;
  *(undefined1 *)((int)PTR_DAT_03054dc0 + 1) = 0;
  *(undefined1 *)puVar1 = 0;
  return;
}

