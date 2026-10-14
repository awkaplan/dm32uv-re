/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clamped_table_entry_update @ 030c9f24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 302 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void clamped_table_entry_update(int param_1,int param_2__w,uint param_3)

{
  short param_2 = (short)param_2__w;
  short sVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  
  if ((int)param_3 < -0x77ff) {
    param_3 = 0xffff8801;
  }
  sVar1 = param_2 + -1;
  param_3 = param_3 & 0xffff;
  if (-1 < (short)(param_2 + -1)) {
    psVar6 = (short *)((short)(param_2 + -1) * 2 + param_1);
    uVar4 = param_3;
    do {
      while( true ) {
        sVar3 = (short)uVar4;
        uVar5 = sVar3 * 0x10000;
        uVar2 = uVar5 + 0xfc000000;
        if ((int)*psVar6 < (int)sVar3) {
          *psVar6 = sVar3;
        }
        uVar4 = uVar2 >> 0x10;
        if (-1 < (int)((uVar2 ^ uVar5) & (uVar2 ^ 0xfbffffff))) break;
        sVar1 = sVar1 + -1;
        if ((uVar5 & 0x80000000) == 0) {
          uVar4 = 0x7fff;
        }
        else {
          uVar4 = 0x8801;
        }
        psVar6 = psVar6 + -1;
        if (sVar1 < 0) goto code_r0x030c9fc4;
      }
      sVar1 = sVar1 + -1;
      if ((short)(uVar2 >> 0x10) < -0x77ff) {
        uVar4 = 0x8801;
      }
      psVar6 = psVar6 + -1;
    } while (-1 < sVar1);
  }
code_r0x030c9fc4:
  sVar1 = param_2 + 1;
  if ((short)(param_2 + 1) < 0x38) {
    psVar6 = (short *)(param_1 + (short)(param_2 + 1) * 2);
    do {
      while( true ) {
        sVar3 = (short)param_3;
        uVar4 = sVar3 * 0x10000;
        uVar2 = uVar4 + 0xfc000000;
        if ((int)*psVar6 < (int)sVar3) {
          *psVar6 = sVar3;
        }
        param_3 = uVar2 >> 0x10;
        if (-1 < (int)((uVar2 ^ uVar4) & (uVar2 ^ 0xfbffffff))) break;
        sVar1 = sVar1 + 1;
        if ((uVar4 & 0x80000000) == 0) {
          param_3 = 0x7fff;
        }
        else {
          param_3 = 0x8801;
        }
        psVar6 = psVar6 + 1;
        if (0x37 < sVar1) {
          return;
        }
      }
      sVar1 = sVar1 + 1;
      if ((short)(uVar2 >> 0x10) < -0x77ff) {
        param_3 = 0x8801;
      }
      psVar6 = psVar6 + 1;
    } while (sVar1 < 0x38);
  }
  return;
}

