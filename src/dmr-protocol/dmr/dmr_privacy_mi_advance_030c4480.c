/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_mi_advance @ 030c4480 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint dmr_privacy_mi_advance(char param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = (uint)param_2[3] + (uint)*param_2 * 0x1000000 + (uint)param_2[1] * 0x10000 +
          (uint)param_2[2] * 0x100;
  iVar1 = func_0x060d1778();
  if (iVar1 != 0) {
    if (param_1 == '\x01') {
      iVar1 = 0;
      do {
        uVar2 = uVar6 & 10;
        uVar3 = uVar6 & 0x80000000;
        iVar1 = iVar1 + 1;
        uVar6 = uVar6 * 2;
        if (uVar3 != (uVar2 ^ uVar2 >> 2) << 0x1e) {
          uVar6 = uVar6 | 1;
        }
      } while (iVar1 != 0x20);
    }
    else {
      iVar1 = 0;
      do {
        uVar4 = uVar6 & 3;
        uVar3 = uVar6 >> 0x15;
        uVar2 = uVar6 >> 0x1f;
        uVar5 = uVar6 & 1;
        iVar1 = iVar1 + 1;
        uVar6 = uVar6 * 2;
        if ((uVar2 ^ uVar3 & 1 ^ uVar4 >> 1) != uVar5) {
          uVar6 = uVar6 | 1;
        }
      } while (iVar1 != 0x20);
    }
  }
  *param_2 = (byte)(uVar6 >> 0x18);
  param_2[1] = (byte)(uVar6 >> 0x10);
  param_2[2] = (byte)(uVar6 >> 8);
  param_2[3] = (byte)uVar6;
  func_0x060d1774(_DAT_030c48d8,5,0);
  func_0x060d1774(param_2,4,1);
  return uVar6;
}

