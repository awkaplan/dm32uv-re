/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: signal_level_bargraph_render @ 030391d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 250 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void signal_level_bargraph_render(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  float a;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  param_2 = param_2 & 0xffff;
  if (param_2 < 9) {
    uVar5 = 0x1d;
    uVar6 = 0x103;
  }
  else {
    if (param_2 < 0x104) {
      uVar7 = int32_to_float32_special_case_only(param_2);
      fVar3 = (float)decimal_string_pair_to_fixed(*PTR_DAT_03039368,uVar7);
      uVar6 = mutex_guarded_call_wrapper();
      uVar6 = uVar6 & 0xffff;
      if (uVar6 < 3) {
        uVar5 = 1;
        uVar6 = 3;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 1;
      uVar7 = *PTR_DAT_03039360;
      do {
        uVar5 = uVar5 + 1 & 0xffff;
        uVar1 = int32_to_float32_special_case_only(0x103 / (param_2 / uVar5));
        iVar2 = softfloat32_compare_gt(uVar1,uVar7);
      } while (iVar2 == 0);
      fVar3 = *(float *)PTR_DAT_03039364;
      uVar6 = 4;
    }
    a = (float)int32_to_float32_special_case_only((param_1 & 0xffff) / uVar5);
    fVar3 = softfloat32_mul(a,fVar3);
    softfloat32_add(fVar3,*(float *)PTR_LAB_0303936c);
    uVar5 = mutex_guarded_call_wrapper();
    uVar5 = uVar5 & 0xffff;
    if ((int)(0x120 - uVar6) < (int)uVar5) {
      uVar5 = 0x120 - uVar6 & 0xffff;
    }
  }
  if ((param_1 & 0xffff) + 1 == param_2) {
    uVar4 = 0x120;
    uVar5 = 0x120 - uVar6 & 0xffff;
  }
  else {
    uVar4 = uVar5 + uVar6 & 0xffff;
  }
  display_fill_rect(0xe6,(short)uVar5,0xf0,(short)uVar4,0x8430);
  if (0x1d < uVar5) {
    display_fill_rect(0xe6,0x1d,0xf0,(short)uVar5,0xd69a);
  }
  if (uVar4 < 0x120) {
    display_fill_rect(0xe6,(short)uVar4,0xf0,0x120,0xd69a);
  }
  return;
}

