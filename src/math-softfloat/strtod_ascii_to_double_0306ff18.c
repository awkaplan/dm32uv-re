/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strtod_ascii_to_double @ 0306ff18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 548 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 strtod_ascii_to_double(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int v;
  undefined4 uVar14;
  int iStack_28;
  
  pbVar12 = param_1;
  while (iVar7 = isspace((uint)*pbVar12), iVar7 != 0) {
    pbVar12 = pbVar12 + 1;
  }
  uVar11 = (uint)*pbVar12;
  if (uVar11 == 0) goto LAB_0306ffcc;
  if (uVar11 == 0x2d) {
    bVar4 = true;
LAB_0306ffc4:
    pbVar12 = pbVar12 + 1;
    uVar11 = (uint)*pbVar12;
    if (uVar11 == 0) {
LAB_0306ffcc:
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = param_1;
        return 0;
      }
      return 0;
    }
  }
  else {
    bVar4 = false;
    if (uVar11 == 0x2b) goto LAB_0306ffc4;
  }
  bVar5 = false;
  bVar3 = false;
  uVar14 = 0;
  iStack_28 = 0;
  iVar7 = isdigit(uVar11);
  puVar6 = PTR_DAT_0307008c;
  bVar2 = false;
  v = 0;
  if (iVar7 != 0) goto LAB_0306ff7a;
LAB_0306ff5c:
  bVar1 = *pbVar12;
  if (bVar1 == 0x2e) {
    do {
      bVar3 = true;
      while( true ) {
        pbVar12 = pbVar12 + 1;
        iVar7 = isdigit((uint)*pbVar12);
        bVar2 = true;
        if (iVar7 == 0) goto LAB_0306ff5c;
LAB_0306ff7a:
        bVar1 = *pbVar12;
        if (bVar1 == 0x2e) break;
        uVar14 = soft_double_multiply(uVar14,iStack_28,*puVar6,puVar6[1]);
        iVar7 = iStack_28;
        uVar8 = soft_double_from_int(bVar1 - 0x30);
        uVar14 = soft_double_add(uVar14,iStack_28,uVar8,iVar7);
        if (bVar3) {
          v = v + -1;
        }
      }
    } while( true );
  }
  iVar7 = iStack_28;
  if ((bVar1 != 0x65) && (bVar1 != 0x45)) goto LAB_0306ffea;
  pbVar13 = pbVar12 + 1;
  uVar11 = (uint)*pbVar13;
  pbVar12 = pbVar13;
  if (uVar11 != 0) {
    while (iVar9 = isspace(uVar11), iVar9 != 0) {
      pbVar13 = pbVar13 + 1;
      uVar11 = (uint)*pbVar13;
    }
    uVar11 = (uint)*pbVar13;
    pbVar12 = pbVar13;
    if (uVar11 != 0) {
      if (uVar11 == 0x2d) {
        bVar1 = pbVar13[1];
        bVar5 = true;
joined_r0x03070134:
        uVar11 = (uint)bVar1;
        pbVar12 = pbVar13 + 1;
        if (uVar11 == 0) {
          pbVar12 = pbVar13 + 1;
          bVar2 = true;
          goto LAB_0306ffea;
        }
      }
      else if (uVar11 == 0x2b) {
        bVar1 = pbVar13[1];
        goto joined_r0x03070134;
      }
      iVar9 = 0;
      while( true ) {
        iVar10 = isdigit(uVar11);
        if (iVar10 == 0) break;
        if (iVar9 < 0x134) {
          iVar9 = (*pbVar12 - 0x30) + iVar9 * 10;
        }
        pbVar12 = pbVar12 + 1;
        uVar11 = (uint)*pbVar12;
      }
      if (bVar5) {
        v = v - iVar9;
        bVar2 = true;
      }
      else {
        v = iVar9 + v;
        bVar2 = true;
      }
      goto LAB_0306ffea;
    }
  }
  bVar2 = true;
LAB_0306ffea:
  if (param_2 != (undefined4 *)0x0) {
    if (bVar2) {
      param_1 = pbVar12;
    }
    *param_2 = param_1;
  }
  if (bVar4) {
    iVar7 = -0x80000000;
    iStack_28 = iStack_28 + -0x80000000;
  }
  uVar8 = uVar14;
  if (v != 0) {
    iVar9 = iStack_28;
    if (v < 0) {
      abs_int(v);
      uVar8 = pow10_decimal_exponent();
      uVar8 = soft_double_divide(uVar14,iStack_28,uVar8,iVar7);
    }
    else {
      abs_int(v);
      uVar8 = pow10_decimal_exponent();
      uVar8 = soft_double_multiply(uVar14,iStack_28,uVar8,iVar7);
    }
    iVar7 = soft_double_compare_packed_dup_0306f1b0(uVar8,iVar9,0,0);
    if ((((iVar7 == 0) &&
         (iVar7 = soft_double_compare_packed_dup_03071fb4(uVar14,iStack_28,0,0), iVar7 != 0)) ||
        (iVar7 = softdouble_compare_le(uVar8,iVar9,*PTR_DAT_03070090,PTR_DAT_03070090[1]), 0 < iVar7
        )) || (iVar7 = soft_double_compare_packed(uVar8,iVar9,*PTR_DAT_03070094,PTR_DAT_03070094[1])
              , iVar7 < 0)) {
      *PTR_DAT_03070098 = 0x22;
      return uVar8;
    }
  }
  return uVar8;
}

