/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: byte_table_derive_from_const_seed @ 0305f7e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void byte_table_derive_from_const_seed(byte *param_1)

{
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte bStack_1c;
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  
  struct_init_const_wrapper(&bStack_20);
  *param_1 = bStack_1d;
  param_1[1] = bStack_1b;
  param_1[2] = bStack_1a ^ bStack_1e;
  param_1[3] = bStack_1f;
  param_1[4] = bStack_1d ^ bStack_19;
  param_1[5] = bStack_1e;
  param_1[6] = bStack_19;
  param_1[7] = bStack_20;
  param_1[8] = bStack_1f | bStack_1b;
  param_1[9] = bStack_1c;
  param_1[10] = bStack_1a;
  param_1[0xb] = bStack_20 ^ bStack_1c;
  return;
}

