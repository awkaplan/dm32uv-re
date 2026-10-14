/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_pop_clear_pending_flags @ 030370c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_pop_clear_pending_flags(void)

{
  undefined1 *puVar1;
  
  if ((PTR_DAT_030372c8[0x16] & 1) != 0) {
    PTR_DAT_030372c8[0x16] = PTR_DAT_030372c8[0x16] & 0xfe;
    puVar1 = PTR_DAT_030372e8;
    PTR_DAT_030372e8[1] = PTR_DAT_030372e8[1] & 0xf7;
    puVar1[0x2d] = puVar1[0x2d] & 0xf3;
    *(byte *)PTR_DAT_030372ec = *(byte *)PTR_DAT_030372ec & 0x7f;
  }
  history_queue_pop();
  return;
}

