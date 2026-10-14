/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: buffer_prepend_3byte_le @ 0305437c (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void buffer_prepend_3byte_le(undefined4 param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_3 + 2U & 0xffff;
  if (2 < uVar1) {
    do {
      param_2[uVar1] = param_2[uVar1 - 3];
      uVar1 = uVar1 - 1 & 0xffff;
    } while (uVar1 != 2);
  }
  *param_2 = (char)param_1;
  param_2[1] = (char)((uint)param_1 >> 8);
  param_2[2] = (char)((uint)param_1 >> 0x10);
  return;
}

