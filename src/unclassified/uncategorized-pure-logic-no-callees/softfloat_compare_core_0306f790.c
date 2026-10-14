/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softfloat_compare_core @ 0306f790 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int softfloat_compare_core(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *param_1;
  if ((uVar1 < 2) || (uVar3 = *param_2, uVar3 < 2)) {
    return 1;
  }
  if (uVar1 == 4) {
    if (uVar3 == 4) {
      return param_2[1] - param_1[1];
    }
LAB_0306f7e8:
    uVar1 = param_1[1];
LAB_0306f7bc:
    iVar2 = -1;
    if (uVar1 == 0) {
      iVar2 = 1;
    }
    return iVar2;
  }
  if (uVar3 != 4) {
    if (uVar1 != 2) {
      if (uVar3 != 2) {
        uVar1 = param_1[1];
        if (uVar1 == param_2[1]) {
          if ((int)param_2[2] < (int)param_1[2]) goto LAB_0306f7bc;
          if ((int)param_2[2] <= (int)param_1[2]) {
            if (param_2[3] < param_1[3]) goto LAB_0306f7bc;
            if (param_2[3] <= param_1[3]) {
              return 0;
            }
          }
          goto LAB_0306f7d6;
        }
        goto LAB_0306f7bc;
      }
      goto LAB_0306f7e8;
    }
    if (uVar3 == 2) {
      return 0;
    }
  }
  uVar1 = param_2[1];
LAB_0306f7d6:
  iVar2 = -1;
  if (uVar1 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

