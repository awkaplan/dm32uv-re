/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bit_matrix_column_transpose_pack @ 03010f44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void bit_matrix_column_transpose_pack(byte *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_3 & 0xff) != 0) {
    *param_1 = 0;
    uVar7 = 0;
    uVar2 = uVar7;
    uVar6 = uVar7;
    while( true ) {
      pbVar3 = param_1 + 1;
      uVar1 = uVar7;
      bVar5 = 1;
      while( true ) {
        uVar4 = uVar1;
        if (7 < uVar6) {
          uVar4 = uVar1 + 8 & 0xff;
        }
        if (((uint)*(byte *)(param_2 + uVar4) & 0x80 >> (uVar2 & 7)) != 0) {
          *param_1 = *param_1 | bVar5;
        }
        uVar1 = uVar1 + 1 & 0xff;
        if (uVar1 == 8) break;
        bVar5 = bVar5 * '\x02';
      }
      uVar6 = uVar6 + 1 & 0xff;
      if ((param_3 & 0xff) <= uVar6) break;
      *pbVar3 = 0;
      param_1 = pbVar3;
      uVar2 = uVar6;
      if (7 < uVar6) {
        uVar2 = uVar6 - 8 & 0xff;
      }
    }
  }
  return;
}

