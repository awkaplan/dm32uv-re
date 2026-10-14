/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: buffer_compare_memcmp_style @ 03070270 (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int buffer_compare_memcmp_style(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 != 0) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) {
      while( true ) {
        uVar1 = (uint)(byte)*param_1;
        uVar3 = (uint)(byte)*param_2;
        if ((uVar1 != uVar3) || (param_3 == 1)) break;
        uVar1 = (uint)*(byte *)((int)param_1 + 1);
        uVar3 = (uint)*(byte *)((int)param_2 + 1);
        if ((uVar1 != uVar3) || (param_3 == 2)) break;
        uVar1 = (uint)*(byte *)((int)param_1 + 2);
        uVar3 = (uint)*(byte *)((int)param_2 + 2);
        if ((uVar1 != uVar3) || (param_3 == 3)) break;
        uVar1 = (uint)*(byte *)((int)param_1 + 3);
        uVar3 = (uint)*(byte *)((int)param_2 + 3);
        if ((uVar1 != uVar3) || (param_3 = param_3 + -4, param_3 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
LAB_03070360:
      return uVar1 - uVar3;
    }
    while( true ) {
      uVar1 = *param_1;
      uVar3 = *param_2;
      iVar2 = param_3;
      if (uVar1 != uVar3) break;
      if (param_3 < 5) goto LAB_03070360;
      iVar2 = param_3 + -4;
      uVar1 = param_1[1];
      uVar3 = param_2[1];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -8;
      uVar1 = param_1[2];
      uVar3 = param_2[2];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -0xc;
      uVar1 = param_1[3];
      uVar3 = param_2[3];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -0x10;
      uVar1 = param_1[4];
      uVar3 = param_2[4];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -0x14;
      uVar1 = param_1[5];
      uVar3 = param_2[5];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -0x18;
      uVar1 = param_1[6];
      uVar3 = param_2[6];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      iVar2 = param_3 + -0x1c;
      uVar1 = param_1[7];
      uVar3 = param_2[7];
      if (uVar1 != uVar3) break;
      if (iVar2 < 5) goto LAB_03070360;
      param_3 = param_3 + -0x20;
      param_1 = param_1 + 8;
      param_2 = param_2 + 8;
    }
    if (iVar2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return 0;
}

