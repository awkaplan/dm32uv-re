/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_config_state_duplicate @ 030c98dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_config_state_duplicate(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  
  uVar1 = param_2[7];
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  uVar5 = param_2[6];
  uVar6 = param_2[0x42];
  param_1[3] = param_2[3];
  param_1[7] = uVar1;
  uVar7 = *(undefined4 *)(param_2 + 4);
  *param_1 = uVar2;
  param_1[1] = uVar3;
  param_1[2] = uVar4;
  *(undefined4 *)(param_1 + 4) = uVar7;
  param_1[6] = uVar5;
  *(undefined4 *)(param_1 + 0x40) = 0;
  param_1[0x42] = uVar6;
  array_copy_u16(param_1 + 8,param_2 + 8,0x38);
  return;
}

