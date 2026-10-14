/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strncmp_ck803s_null_safe @ 0306cb4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 236 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint strncmp_ck803s_null_safe(char *param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else if (param_1 == (char *)0x0) {
    if (param_2 == (undefined1 *)0x0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_0306b8c8(*param_2);
      uVar2 = -iVar1 & 0xffff;
    }
  }
  else if (param_2 == (undefined1 *)0x0) {
    uVar2 = FUN_0306b8c8(*param_1);
  }
  else {
    pcVar4 = param_1 + 1;
    puVar5 = param_2 + 1;
    iVar3 = FUN_0306b8c8(*param_1);
    iVar1 = FUN_0306b8c8(*param_2);
    if ((((iVar3 == iVar1) && (iVar1 = iVar3, *param_1 != '\0')) && (pcVar4 != (char *)0x0)) &&
       (puVar5 != (undefined1 *)0x0)) {
      uVar2 = 0;
      while( true ) {
        pcVar4 = pcVar4 + 1;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 + 1;
        iVar3 = FUN_0306b8c8(param_1[uVar2]);
        iVar1 = FUN_0306b8c8(param_2[uVar2]);
        if ((iVar3 != iVar1) || (iVar1 = iVar3, param_1[uVar2] == '\0')) break;
        if ((pcVar4 == (char *)0x0) || ((puVar5 == (undefined1 *)0x0 || (param_3 <= uVar2)))) break;
      }
      if (uVar2 == param_3) {
        return 0;
      }
    }
    if (iVar3 == iVar1) {
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      else if (pcVar4 == (char *)0x0) {
        if (puVar5 == (undefined1 *)0x0) {
          uVar2 = 0;
        }
        else {
          iVar1 = FUN_0306b8c8(*puVar5);
          uVar2 = -iVar1 & 0xffff;
        }
      }
      else {
        uVar2 = FUN_0306b8c8(*pcVar4);
      }
    }
    else {
      uVar2 = iVar3 - iVar1 & 0xffff;
    }
  }
  return uVar2;
}

