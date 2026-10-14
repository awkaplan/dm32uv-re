/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: copy_bytes_from_offset_table @ 0300d41c (file base 0x03000000; code starts at 0x03001000)
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

void copy_bytes_from_offset_table(int param_1,undefined1 *param_2,int param_3__w)

{
  short param_3 = (short)param_3__w;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + DAT_0300d46c);
  if (param_3 != 0) {
    param_1 = param_1 + DAT_0300d470;
    do {
      *param_2 = *puVar1;
      puVar1 = puVar1 + 1;
      param_2 = param_2 + 1;
    } while (puVar1 != (undefined1 *)(param_1 + (uint)(ushort)(param_3 - 1)));
  }
  return;
}

