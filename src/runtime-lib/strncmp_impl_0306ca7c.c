/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strncmp_impl @ 0306ca7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort strncmp_impl(byte *param_1,byte *param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  ushort uVar4;
  byte *pbVar5;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else if (param_1 == (byte *)0x0) {
    if (param_2 == (byte *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = -(ushort)*param_2;
    }
  }
  else if (param_2 == (byte *)0x0) {
    uVar1 = (ushort)*param_1;
  }
  else {
    pbVar5 = param_1 + 1;
    pbVar3 = param_2 + 1;
    uVar1 = (ushort)*param_1;
    uVar4 = (ushort)*param_2;
    if ((((uVar1 == *param_2) && (uVar4 = uVar1, uVar1 != 0)) && (pbVar5 != (byte *)0x0)) &&
       (pbVar3 != (byte *)0x0)) {
      uVar2 = 0;
      while( true ) {
        pbVar5 = pbVar5 + 1;
        pbVar3 = pbVar3 + 1;
        uVar2 = uVar2 + 1;
        uVar1 = (ushort)param_1[uVar2];
        uVar4 = (ushort)param_2[uVar2];
        if ((uVar1 != param_2[uVar2]) || (uVar4 = uVar1, uVar1 == 0)) break;
        if ((pbVar5 == (byte *)0x0) || ((pbVar3 == (byte *)0x0 || (param_3 <= uVar2)))) break;
      }
      if (uVar2 == param_3) {
        return 0;
      }
    }
    if (uVar1 == uVar4) {
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else if (pbVar5 == (byte *)0x0) {
        if (pbVar3 == (byte *)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = -(ushort)*pbVar3;
        }
      }
      else {
        uVar1 = (ushort)*pbVar5;
      }
    }
    else {
      uVar1 = uVar1 - uVar4;
    }
  }
  return uVar1;
}

