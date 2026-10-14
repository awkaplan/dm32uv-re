/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hamming23_syndrome_error_correct @ 030c4e50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 486 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint hamming23_syndrome_error_correct(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = 0;
  while( true ) {
    uVar1 = 0;
    uVar14 = 0x16;
    do {
      uVar12 = uVar1 & 1;
      uVar13 = uVar1 >> 10;
      uVar6 = (param_1 >> (uVar14 & 0x3f) ^ uVar12) & 1;
      uVar3 = uVar1 >> 9 & 1 ^ uVar12;
      uVar11 = uVar1 >> 8 & 1;
      uVar9 = uVar1 >> 7 & 1 ^ uVar12;
      uVar7 = (uVar1 >> 6 & 1 ^ uVar12) << 5;
      uVar8 = uVar12 ^ uVar1 >> 5 & 1;
      uVar4 = uVar1 >> 4 & 1;
      uVar10 = uVar1 >> 3 & 1;
      uVar5 = uVar1 >> 2 & 1;
      uVar12 = uVar12 ^ uVar1 >> 1 & 1;
      uVar14 = uVar14 - 1;
      uVar1 = uVar6 << 10 | uVar13 << 9 | uVar3 << 8 | uVar11 << 7 | uVar9 << 6 | uVar7 | uVar8 << 4
              | uVar4 << 3 | uVar10 << 2 | uVar5 << 1 | uVar12;
    } while (uVar14 != 0x15 - (param_2 - 1 & 0xff));
    uVar1 = uVar6 | uVar13 << 1 | uVar3 << 2 | uVar11 << 3 | uVar9 << 4 | uVar7 | uVar8 << 6 |
            uVar4 << 7 | uVar10 << 8 | uVar5 << 9 | uVar12 << 10;
    if (uVar1 == 0) break;
    uVar13 = 0;
    uVar14 = uVar1;
    do {
      uVar6 = uVar14 & 1;
      uVar14 = uVar14 >> 1;
      uVar13 = uVar13 + uVar6 & 0xffff;
    } while (uVar14 != 0);
    if (uVar13 < 4) break;
    uVar6 = uVar1 ^ 0x366;
    uVar14 = 0;
    uVar13 = uVar6;
    if (uVar6 == 0) {
LAB_030c4fdc:
      param_1 = param_1 ^ (uVar6 | 0x10000);
      if ((int)(0x17 - uVar2) < 1) {
        return param_1;
      }
      uVar1 = 0;
      do {
        uVar1 = uVar1 + 1 & 0xff;
        param_1 = param_1 >> 0x16 | param_1 * 2 & 0x7ffffe;
      } while ((int)uVar1 < (int)(0x17 - uVar2));
      return param_1;
    }
    do {
      uVar7 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      uVar14 = uVar14 + uVar7 & 0xffff;
    } while (uVar13 != 0);
    if (uVar14 < 3) goto LAB_030c4fdc;
    uVar1 = uVar1 ^ 0x6cc;
    uVar14 = 0;
    uVar13 = uVar1;
    if (uVar1 == 0) {
LAB_030c5006:
      param_1 = param_1 ^ (uVar1 | 0x20000);
      if ((int)(0x17 - uVar2) < 1) {
        return param_1;
      }
      uVar1 = 0;
      do {
        uVar1 = uVar1 + 1 & 0xff;
        param_1 = param_1 >> 0x16 | param_1 * 2 & 0x7ffffe;
      } while ((int)uVar1 < (int)(0x17 - uVar2));
      return param_1;
    }
    do {
      uVar6 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      uVar14 = uVar14 + uVar6 & 0xffff;
    } while (uVar13 != 0);
    if (uVar14 < 3) goto LAB_030c5006;
    uVar2 = uVar2 + 1 & 0xff;
    if (param_2 <= uVar2) {
      return 0;
    }
    param_1 = param_1 >> 0x16 | param_1 * 2 & 0x7ffffe;
  }
  param_1 = param_1 ^ uVar1;
  if (0 < (int)(0x17 - uVar2)) {
    uVar1 = 0;
    do {
      uVar1 = uVar1 + 1 & 0xff;
      param_1 = param_1 >> 0x16 | param_1 * 2 & 0x7ffffe;
    } while ((int)uVar1 < (int)(0x17 - uVar2));
  }
  return param_1;
}

