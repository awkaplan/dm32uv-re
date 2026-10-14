/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: float32_unpack_then_softdouble_pack_round_wrapper @ 0306e898 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void float32_unpack_then_softdouble_pack_round_wrapper(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 local_c;
  
  local_c = param_1;
  float32_unpack(&local_c,&local_1c);
  softdouble_pack_round_wrapper(local_1c,uStack_18,uStack_14,uStack_10 << 0x1e,uStack_10 >> 2);
  return;
}

