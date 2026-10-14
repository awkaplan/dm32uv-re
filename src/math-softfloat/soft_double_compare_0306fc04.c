/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_compare @ 0306fc04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int soft_double_compare(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  if ((uVar1 < 2) || (uVar3 = *param_2, uVar3 < 2)) {
    return 1;
  }
  if (uVar1 == 4) {
    if (uVar3 == 4) {
      return param_2[1] - param_1[1];
    }
LAB_0306fc5c:
    uVar1 = param_1[1];
LAB_0306fc30:
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
          if ((int)param_2[2] < (int)param_1[2]) goto LAB_0306fc30;
          if ((int)param_2[2] <= (int)param_1[2]) {
            uVar3 = param_1[4];
            uVar4 = param_2[4];
            if ((uVar4 < uVar3) || ((uVar3 == uVar4 && (param_2[3] < param_1[3]))))
            goto LAB_0306fc30;
            if (uVar4 <= uVar3) {
              if (uVar4 != uVar3) {
                return 0;
              }
              if (param_2[3] <= param_1[3]) {
                return 0;
              }
            }
          }
          goto LAB_0306fc4a;
        }
        goto LAB_0306fc30;
      }
      goto LAB_0306fc5c;
    }
    if (uVar3 == 2) {
      return 0;
    }
  }
  uVar1 = param_2[1];
LAB_0306fc4a:
  iVar2 = -1;
  if (uVar1 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

