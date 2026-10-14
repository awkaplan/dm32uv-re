/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: compand_table_nibble_split_lookup @ 03060d80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void compand_table_nibble_split_lookup(uint param_1,undefined2 *param_2,undefined2 *param_3)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = PTR_LAB_03060f18;
  bVar1 = PTR_LAB_03060f18[param_1 & 0xff];
  *param_2 = *(undefined2 *)(PTR_LAB_03060f18 + (uint)(bVar1 >> 4) * 2 + 0x10);
  *param_3 = *(undefined2 *)(puVar2 + (bVar1 & 0xf) * 2 + 0x18);
  return;
}

