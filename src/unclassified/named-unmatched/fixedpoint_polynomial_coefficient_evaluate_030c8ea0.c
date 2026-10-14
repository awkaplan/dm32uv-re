/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixedpoint_polynomial_coefficient_evaluate @ 030c8ea0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 224 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint fixedpoint_polynomial_coefficient_evaluate(int param_1,short param_2,short param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)(short)(param_2 + -0xf);
  if ((int)uVar3 < 0) {
    uVar3 = (param_1 << 0x10) >> (-uVar3 & 0x3f);
  }
  else {
    uVar3 = (param_1 << 0x10) << (uVar3 & 0x3f);
  }
  uVar1 = uVar3 >> 1;
  uVar3 = (uint)(short)(((short)(uVar3 >> 0x10) - param_3) + 1);
  iVar2 = ((int)(((int)((uint)*(ushort *)(PTR_DAT_030c8f80 + 2) * 0x10000 +
                       ((int)((uVar1 & 0x7fff) *
                              (((int)((uint)*(ushort *)((int)PTR_DAT_030c8f80 + 6) << 0x10) >> 1) +
                               ((int)((uVar1 & 0x7fff) *
                                      (((int)((uint)*(ushort *)(PTR_DAT_030c8f80 + 1) << 0x10) >> 1)
                                       + ((int)((uVar1 & 0x7fff) *
                                                ((int)((uint)*(ushort *)((int)PTR_DAT_030c8f80 + 2)
                                                       * 0x10000 +
                                                      ((int)((uVar1 & 0x7fff) *
                                                             (uint)*(ushort *)PTR_DAT_030c8f80 * 2 +
                                                             0x8000 & 0xffff0000) >> 3)) >> 0x10 &
                                                0xffffU) * 2 + 0x8000 & 0xffff0000) >> 3) >> 0x10 &
                                      0xffffU) * 2 + 0x8000 & 0xffff0000) >> 2) >> 0x10 & 0xffffU) *
                              2 + 0x8000 & 0xffff0000) >> 1)) >> 0x10 & 0xffffU) * (uVar1 & 0x7fff)
                 * 2 + 0x8000 & 0xffff0000) >> 1) +
          (uint)*(ushort *)((int)PTR_DAT_030c8f80 + 10) * 0x10000;
  if (-1 < (int)uVar3) {
    return (iVar2 << (uVar3 & 0x3f)) + 0x8000U >> 0x10;
  }
  return (iVar2 >> (-uVar3 & 0x3f)) + 0x8000U >> 0x10;
}

