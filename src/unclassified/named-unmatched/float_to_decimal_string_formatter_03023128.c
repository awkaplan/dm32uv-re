/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: float_to_decimal_string_formatter @ 03023128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int float_to_decimal_string_formatter(int param_1,float param_2,byte param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  float fVar4;
  float b;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)param_3;
  param_4 = param_4 & 0xff;
  uVar1 = mutex_guarded_call_wrapper(param_2);
  if (uVar8 != 0) {
    uVar5 = 0;
    uVar7 = uVar8;
    do {
      uVar7 = uVar7 - 1;
      uVar2 = FUN_03023110(10,uVar7);
      *(char *)(param_1 + uVar5) = (char)(uVar1 / uVar2) + (char)((uVar1 / uVar2) / 10) * -10 + '0';
      uVar5 = uVar5 + 1;
    } while ((uVar5 & 0xff) < uVar8);
  }
  *(undefined1 *)(param_1 + uVar8) = 0x2e;
  uVar3 = FUN_03023110(10,param_4);
  fVar4 = (float)float32_pack_const_two(uVar1);
  fVar4 = softfloat32_sub(param_2,fVar4);
  b = (float)float32_pack_const_two(uVar3);
  softfloat32_mul(fVar4,b);
  uVar1 = mutex_guarded_call_wrapper();
  if (param_4 != 0) {
    pcVar6 = (char *)(uVar8 + 1 + param_1);
    uVar5 = 0;
    uVar7 = param_4;
    do {
      uVar7 = uVar7 - 1;
      uVar2 = FUN_03023110(10,uVar7);
      *pcVar6 = (char)(uVar1 / uVar2) + (char)((uVar1 / uVar2) / 10) * -10 + '0';
      uVar5 = uVar5 + 1 & 0xff;
      pcVar6 = pcVar6 + 1;
    } while (uVar5 < param_4);
  }
  *(undefined1 *)(uVar8 + param_4 + param_1 + 1) = 0;
  return param_1;
}

