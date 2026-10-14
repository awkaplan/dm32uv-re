/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_queue_reset @ 03054d80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void event_queue_reset(void)

{
  undefined4 *puVar1;
  
  PTR_DAT_03054dc4[2] = 0;
  if (*(char *)((int)PTR_DAT_03054dc0 + 1) == '\x02') {
    rf_transceiver_mode_init(1);
  }
  puVar1 = PTR_DAT_03054dc0;
  *(undefined1 *)((int)PTR_DAT_03054dc0 + 1) = 0;
  *(undefined1 *)puVar1 = 0;
  return;
}

