/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_coordinate_normalize_pair @ 03062fe4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_coordinate_normalize_pair
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5,undefined4 *param_6)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar1 = PTR_LAB_0306308c;
  uVar2 = soft_double_divide(param_3,param_4,*(undefined4 *)PTR_LAB_0306308c,
                             *(undefined4 *)(PTR_LAB_0306308c + 4));
  uVar7 = param_4;
  softdouble_to_int32();
  uVar3 = soft_double_from_int();
  soft_double_sub(uVar2,param_4,uVar3,uVar7);
  soft_double_multiply();
  uVar4 = soft_double_divide();
  uVar5 = soft_double_divide(param_1,param_2,*(undefined4 *)puVar1,*(undefined4 *)(puVar1 + 4));
  uVar2 = param_2;
  softdouble_to_int32();
  uVar6 = soft_double_from_int();
  soft_double_sub(uVar5,param_2,uVar6,uVar2);
  soft_double_multiply();
  uVar5 = soft_double_divide();
  uVar5 = soft_double_add(uVar6,uVar2,uVar5,param_2);
  *param_5 = uVar5;
  param_5[1] = uVar2;
  uVar2 = soft_double_add(uVar3,uVar7,uVar4,param_4);
  *param_6 = uVar2;
  param_6[1] = uVar7;
  return;
}

