/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_tick_prescaler_post @ 030546dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_tick_prescaler_post(void)

{
  char cVar1;
  
  cVar1 = *(char *)(PTR_DAT_03054744 + 1);
  *(byte *)(PTR_DAT_03054744 + 1) = cVar1 + 1U;
  if (99 < (byte)(cVar1 + 1U)) {
    *(undefined1 *)(PTR_DAT_03054744 + 1) = 0;
    OSFlagPost_wrapper_set(_DAT_03054768,0x20000);
  }
  return;
}

