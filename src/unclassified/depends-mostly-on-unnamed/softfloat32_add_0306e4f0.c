/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softfloat32_add @ 0306e4f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

float softfloat32_add(float a,float b)

{
  float fVar1;
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  float local_18;
  float local_14;
  
  local_18 = b;
  local_14 = a;
  float32_unpack(&local_14,auStack_28);
  float32_unpack(&local_18,auStack_38);
  softfloat32_addsub_core(auStack_28,auStack_38,auStack_48);
  fVar1 = (float)float32_pack_round();
  return fVar1;
}

