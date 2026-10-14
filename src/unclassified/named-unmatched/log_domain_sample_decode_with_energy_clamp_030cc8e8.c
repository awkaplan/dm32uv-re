/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: log_domain_sample_decode_with_energy_clamp @ 030cc8e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 242 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 log_domain_sample_decode_with_energy_clamp(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  puVar6 = (ushort *)(param_2 + 0x52);
  iVar5 = 0;
  uVar3 = (uint)(short)(*(short *)(param_2 + 0x72) + -5);
  uVar10 = 0xfc00;
  iVar11 = 0;
  iVar9 = (uint)*puVar6 << 0x10;
  if ((int)uVar3 < 0) goto LAB_030cc95e;
LAB_030cc90a:
  iVar9 = iVar9 << (uVar3 & 0x3f);
  puVar7 = puVar6;
  do {
    uVar3 = iVar9 + 0x78000000;
    iVar9 = (int)(uVar3 + uVar10 * -0x10000) >> 0x10;
    if (iVar9 < 0x66) {
      iVar9 = 0x66;
    }
    sVar1 = FUN_030c8ce0(iVar9,5,5);
    sVar8 = (short)(uVar3 >> 0x10);
    if ((short)(sVar1 + -0x21d) < 0) {
      uVar3 = uVar3 & 0xffff0000;
      uVar2 = (short)(sVar1 + -0x21d) * 0x10000;
      uVar4 = uVar2 + uVar3;
      if (-1 < (int)((uVar2 ^ uVar4) & (uVar4 ^ uVar3))) {
        sVar8 = (short)(uVar4 >> 0x10);
        goto LAB_030cc936;
      }
      if ((int)uVar3 < 0) {
        iVar9 = -0x8000;
        sVar8 = -0x8000;
        goto LAB_030cc938;
      }
      *(undefined2 *)(param_1 + iVar5) = 0x7fff;
      iVar11 = iVar11 + 0x7fff;
    }
    else {
LAB_030cc936:
      iVar9 = (int)sVar8;
LAB_030cc938:
      *(short *)(param_1 + iVar5) = sVar8;
      iVar11 = iVar11 + iVar9;
    }
    if (iVar5 == 0x1e) {
      iVar5 = 0x2000;
      if (iVar11 < 0x10001) {
        iVar5 = 0x4000;
      }
      if (-1 < iVar5 * 0x1e + (iVar11 - *(int *)(param_2 + 0x40)) * 0x40) {
        return 0;
      }
      *(int *)(param_2 + 0x40) = iVar11;
      return 2;
    }
    puVar6 = puVar7 + 1;
    iVar5 = iVar5 + 2;
    uVar3 = (uint)(short)(puVar7[0x11] - 5);
    uVar10 = uVar10 * 0x10000 - 0x400000 >> 0x10;
    iVar9 = (uint)*puVar6 << 0x10;
    if (-1 < (int)uVar3) goto LAB_030cc90a;
LAB_030cc95e:
    iVar9 = iVar9 >> (-uVar3 & 0x3f);
    puVar7 = puVar6;
  } while( true );
}

