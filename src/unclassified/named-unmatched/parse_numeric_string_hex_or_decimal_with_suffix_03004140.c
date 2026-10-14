/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: parse_numeric_string_hex_or_decimal_with_suffix @ 03004140 (file base 0x03000000; code starts at 0x03001000)
 * Size: 300 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 parse_numeric_string_hex_or_decimal_with_suffix(byte *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = (uint)*param_1;
  if (uVar3 == 0x30) {
    if ((param_1[1] == 0x78) || (param_1[1] == 0x58)) {
      uVar3 = (uint)param_1[2];
      if (uVar3 == 0) {
        return 0;
      }
      iVar6 = 0;
      uVar2 = 2;
      do {
        uVar5 = uVar3 - 0x41 & 0xff;
        if ((uVar5 < 6) || ((uVar3 - 0x61 & 0xff) < 6)) {
          if ((uVar3 - 0x30 & 0xff) < 10) goto LAB_030041ba;
          if (uVar5 < 6) {
            iVar4 = uVar3 - 0x37;
          }
          else {
            iVar4 = uVar3 - 0x57;
          }
        }
        else {
          if (9 < (uVar3 - 0x30 & 0xff)) {
            uVar1 = 0;
            goto LAB_030041d4;
          }
LAB_030041ba:
          iVar4 = uVar3 - 0x30;
        }
        uVar2 = uVar2 + 1;
        if (uVar2 == 0xb) {
          return 0;
        }
        iVar6 = iVar6 * 0x10 + iVar4;
        uVar3 = (uint)param_1[uVar2];
      } while (uVar3 != 0);
      *param_2 = iVar6;
      uVar1 = 1;
LAB_030041d4:
      if (uVar2 < 0xb) {
        return uVar1;
      }
      return 0;
    }
  }
  else if (uVar3 == 0) {
    iVar6 = 0;
    uVar2 = 0;
    goto LAB_030041f8;
  }
  iVar6 = 0;
  uVar2 = 0;
  do {
    if (((uVar3 == 0x6b) || (uVar3 == 0x4b)) && (uVar2 != 0)) {
      *param_2 = iVar6 << 10;
      uVar1 = 1;
      goto LAB_03004258;
    }
    if (((uVar3 == 0x6d) || (uVar3 == 0x4d)) && (uVar2 != 0)) {
      *param_2 = iVar6 << 0x14;
      uVar1 = 1;
      goto LAB_03004258;
    }
    if (9 < (uVar3 - 0x30 & 0xff)) {
      uVar1 = 0;
      goto LAB_03004258;
    }
    uVar2 = uVar2 + 1;
    if (uVar2 == 0xb) {
      return 0;
    }
    iVar6 = iVar6 * 10 + uVar3 + -0x30;
    uVar3 = (uint)param_1[uVar2];
  } while (uVar3 != 0);
LAB_030041f8:
  *param_2 = iVar6;
  uVar1 = 1;
LAB_03004258:
  if (10 < uVar2) {
    uVar1 = 0;
  }
  return uVar1;
}

