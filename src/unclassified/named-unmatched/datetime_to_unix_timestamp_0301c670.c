/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: datetime_to_unix_timestamp @ 0301c670 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int datetime_to_unix_timestamp(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = param_2 >> 0x10;
  if ((uVar1 - 0x7b2 & 0xffff) < 0x82) {
    uVar2 = 0x7b2;
    if (uVar1 < 0x7b3) {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      do {
        if ((uVar2 % 400 == 0) || ((iVar3 = _DAT_0301c778, uVar2 % 100 != 0 && ((uVar2 & 3) == 0))))
        {
          iVar3 = _DAT_0301c774;
        }
        iVar4 = iVar4 + iVar3;
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 != uVar1);
    }
    iVar3 = (param_2 >> 8 & 0xff) - 1;
    if (0 < iVar3) {
      uVar2 = 0;
      do {
        iVar4 = iVar4 + (uint)(byte)PTR_LAB_030ad9e7_1_0301c77c[uVar2] * 0x15180;
        if (((uVar1 % 400 == 0) || ((uVar1 % 100 != 0 && ((param_2 & 0x30000) == 0)))) &&
           (uVar2 == 1)) {
          iVar4 = iVar4 + 0x15180;
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while ((int)uVar2 < iVar3);
    }
    iVar4 = (param_1 & 0xff) * 0xe10 + (param_1 >> 8 & 0xff) * 0x3c + (param_1 >> 0x10 & 0xff) +
            ((param_2 & 0xff) - 1) * 0x15180 + iVar4;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

