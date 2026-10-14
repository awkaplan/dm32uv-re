/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strtol_signed @ 0307014c (file base 0x03000000; code starts at 0x03001000)
 * Size: 288 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 * strtol_signed(byte *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  uint c;
  undefined4 *puVar9;
  
  puVar4 = param_2;
  pbVar7 = param_1;
  do {
    pbVar6 = pbVar7;
    c = (uint)*pbVar6;
    pbVar7 = pbVar6 + 1;
    iVar1 = isspace(c);
  } while (iVar1 != 0);
  iVar1 = 0;
  if (c == 0x2d) {
    iVar1 = 1;
    c = (uint)*pbVar7;
    pbVar7 = pbVar6 + 2;
  }
  else if (c == 0x2b) {
    c = (uint)*pbVar7;
    pbVar7 = pbVar6 + 2;
  }
  if ((param_3 == 0) || (param_3 == 0x10)) {
    if ((c == 0x30) && ((*pbVar7 == 0x78 || (*pbVar7 == 0x58)))) {
      c = (uint)pbVar7[1];
      pbVar7 = pbVar7 + 2;
      param_3 = 0x10;
    }
    else if ((param_3 == 0) && (param_3 = 10, c == 0x30)) {
      param_3 = 8;
    }
  }
  iVar8 = 0;
  puVar9 = (undefined4 *)0x0;
  do {
    iVar2 = isdigit(c);
    if (iVar2 == 0) {
      iVar2 = isalpha(c);
      if (iVar2 == 0) {
LAB_03070232:
        if (iVar8 == 0) {
          if (iVar1 != 0) {
            puVar9 = (undefined4 *)-(int)puVar9;
          }
        }
        else {
          puVar9 = (undefined4 *)0x7fffffff;
          if (iVar1 != 0) {
            puVar9 = (undefined4 *)0x80000000;
          }
          *PTR_DAT_0307026c = 0x22;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar8 == 0) {
            param_1 = pbVar7 + -1;
          }
          *param_2 = param_1;
        }
        return puVar9;
      }
      iVar2 = isupper(c);
      if (iVar2 == 0) {
        puVar4 = (undefined4 *)0x57;
      }
      else {
        puVar4 = (undefined4 *)0x37;
      }
      iVar2 = -(int)puVar4;
    }
    else {
      iVar2 = -0x30;
    }
    if (param_3 <= (int)(c + iVar2)) goto LAB_03070232;
    uVar3 = 0;
    iVar5 = param_3;
    do {
      uVar3 = uVar3 + (int)puVar9;
      if (iVar1 == 1) {
        puVar4 = (undefined4 *)0x80000000;
        if (0x80000000 < uVar3) {
          iVar8 = iVar8 + 1;
        }
      }
      else if ((uVar3 & 0x80000000) != 0) {
        iVar8 = iVar8 + 1;
      }
      iVar5 = iVar5 + -1;
    } while (0 < iVar5);
    puVar9 = (undefined4 *)(uVar3 + c + iVar2);
    if (iVar1 == 1) {
      if (puVar4 < puVar9) {
        iVar8 = iVar8 + 1;
      }
    }
    else if ((uVar3 & 0x80000000) != 0) {
      iVar8 = iVar8 + 1;
    }
    c = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  } while( true );
}

