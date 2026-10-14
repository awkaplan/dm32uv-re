/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: signed_divide_saturating @ 030c8994 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int signed_divide_saturating(uint param_1,int param_2__w)

{
  short param_2 = (short)param_2__w;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_2;
  uVar3 = uVar2 ^ param_1;
  if ((int)param_1 < 0) {
    if (param_1 == 0x80000000) {
      param_1 = 0x7fffffff;
    }
    else {
      param_1 = -param_1;
    }
  }
  if ((int)uVar2 < 0) {
    if (uVar2 == 0xffff8000) {
      uVar2 = 0x7fff;
    }
    else {
      uVar2 = (uint)-param_2;
    }
  }
  if ((int)param_1 < (int)uVar2) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)param_1 / (int)uVar2;
  }
  if ((int)uVar3 < 0) {
    return -iVar1;
  }
  return iVar1;
}

