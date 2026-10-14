/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strtoul_ascii_to_uint_radix @ 0306c5ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 410 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint strtoul_ascii_to_uint_radix
               (char *param_1,undefined4 *param_2,uint param_3,int param_4,undefined1 *param_5)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  undefined1 uStack_30;
  undefined1 uStack_29;
  undefined4 uStack_28;
  
  if (param_2 == (undefined4 *)0x0) {
    param_2 = &uStack_28;
  }
  *param_2 = param_1;
  if (param_5 == (undefined1 *)0x0) {
    param_5 = &uStack_29;
  }
  *param_5 = 0;
  if (param_1 == (char *)0x0) {
    uVar7 = 0;
  }
  else if (param_3 == 1) {
    uVar7 = 0;
  }
  else if (param_3 < 0x25) {
    iVar3 = isspace_impl(*param_1);
    pcVar5 = param_1;
    while (iVar3 == 1) {
      pcVar5 = pcVar5 + 1;
      iVar3 = isspace_impl(*pcVar5);
    }
    if (*pcVar5 == '+') {
      pcVar5 = pcVar5 + 1;
      uStack_30 = 0;
    }
    else if (*pcVar5 == '-') {
      if (param_4 == 1) {
        pcVar5 = pcVar5 + 1;
        uStack_30 = 1;
      }
      else {
        uStack_30 = 1;
      }
    }
    else {
      uStack_30 = 0;
    }
    pcVar6 = pcVar5;
    if (param_3 == 8) {
      if (*pcVar5 == '0') {
        pcVar6 = pcVar5 + 1;
      }
    }
    else if (param_3 == 0x10) {
      if (*pcVar5 == '0') {
        pcVar6 = pcVar5 + 1;
        if ((*pcVar6 == 'X') || (*pcVar6 == 'x')) {
          iVar3 = isxdigit_impl(pcVar5[2]);
          if (iVar3 == 1) {
            pcVar6 = pcVar5 + 2;
          }
        }
      }
    }
    else if (param_3 == 0) {
      if (*pcVar5 == '0') {
        pcVar6 = pcVar5 + 1;
        if ((*pcVar6 == 'X') || (*pcVar6 == 'x')) {
          iVar3 = isxdigit_impl(pcVar5[2]);
          param_3 = 0x10;
          if (iVar3 == 1) {
            pcVar6 = pcVar5 + 2;
          }
        }
        else {
          param_3 = 8;
        }
      }
      else {
        param_3 = 10;
      }
    }
    bVar2 = false;
    uVar7 = 0;
    while( true ) {
      cVar1 = *pcVar6;
      iVar3 = isalnum_impl(cVar1);
      if (iVar3 != 1) break;
      iVar3 = FUN_0306b78c(cVar1);
      if (iVar3 == 1) {
        uVar4 = (uint)(byte)(cVar1 - 0x30);
      }
      else {
        iVar3 = FUN_0306b76c(cVar1);
        if (iVar3 == 1) {
          uVar4 = (uint)(byte)(cVar1 + 0xa9);
        }
        else {
          uVar4 = (uint)(byte)(cVar1 - 0x37);
        }
      }
      if (param_3 <= uVar4) break;
      if (!bVar2) {
        if ((uint)PTR_DAT_0306c8d4[param_3] < uVar7) {
          bVar2 = true;
        }
        else {
          uVar7 = param_3 * uVar7 + uVar4;
          if (uVar7 < uVar4) {
            bVar2 = true;
          }
        }
      }
      pcVar6 = pcVar6 + 1;
    }
    if (bVar2) {
      uVar7 = 0xffffffff;
    }
    if (pcVar5 == pcVar6) {
      pcVar6 = param_1;
    }
    *param_2 = pcVar6;
    *param_5 = uStack_30;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}

