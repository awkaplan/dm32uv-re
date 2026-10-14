/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cubic_polynomial_fixedpoint_interpolator @ 030c8de0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 186 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int cubic_polynomial_fixedpoint_interpolator(uint param_1,short *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar2 = param_1 >> 1;
  uVar3 = *(ushort *)PTR_DAT_030c8e9c;
  uVar4 = *(ushort *)((int)PTR_DAT_030c8e9c + 2);
  uVar5 = *(ushort *)(PTR_DAT_030c8e9c + 1);
  uVar6 = *(ushort *)((int)PTR_DAT_030c8e9c + 6);
  uVar7 = *(ushort *)(PTR_DAT_030c8e9c + 2);
  uVar1 = *(ushort *)((int)PTR_DAT_030c8e9c + 10);
  *param_2 = (short)(param_1 >> 0x10) + 1;
  return ((int)(((int)((uint)uVar7 * 0x10000 +
                      ((int)((uVar2 & 0x7fff) *
                             (((int)((uint)uVar6 << 0x10) >> 1) +
                              ((int)((uVar2 & 0x7fff) *
                                     (((int)((uint)uVar5 << 0x10) >> 1) +
                                      ((int)((uVar2 & 0x7fff) *
                                             ((int)((uint)uVar4 * 0x10000 +
                                                   ((int)((uVar2 & 0x7fff) * (uint)uVar3 * 2 +
                                                          0x8000 & 0xffff0000) >> 3)) >> 0x10 &
                                             0xffffU) * 2 + 0x8000 & 0xffff0000) >> 3) >> 0x10 &
                                     0xffffU) * 2 + 0x8000 & 0xffff0000) >> 2) >> 0x10 & 0xffffU) *
                             2 + 0x8000 & 0xffff0000) >> 1)) >> 0x10 & 0xffffU) * (uVar2 & 0x7fff) *
                2 + 0x8000 & 0xffff0000) >> 1) + (uint)uVar1 * 0x10000;
}

