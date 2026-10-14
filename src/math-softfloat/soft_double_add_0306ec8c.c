/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_add @ 0306ec8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_add(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_5c [20];
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [20];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_20 = param_3;
  uStack_1c = param_4;
  local_18 = param_1;
  uStack_14 = param_2;
  soft_double_unpack(&local_18,auStack_34);
  soft_double_unpack(&local_20,auStack_48);
  soft_double_addsub_core(auStack_34,auStack_48,auStack_5c);
  soft_double_pack_and_round();
  return;
}

