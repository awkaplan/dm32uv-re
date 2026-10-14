/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_increment @ 03039450 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_cursor_increment(char *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  
  bVar1 = *param_2;
  if ((uint)bVar1 == (param_3 & 0xff) - 1) {
    *param_2 = 0;
    *param_1 = '\x01';
  }
  else if (*param_1 == '\b') {
    *param_2 = bVar1 + 1;
  }
  else {
    *param_2 = bVar1 + 1;
    *param_1 = *param_1 + '\x01';
  }
  return;
}

