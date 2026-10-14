/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uint_to_trimmed_decimal_ascii @ 030040fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
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

void uint_to_trimmed_decimal_ascii(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = 10;
  iVar4 = 0;
  iVar3 = 0;
  uVar2 = _DAT_03004264;
  do {
    uVar5 = param_2 / uVar2 + 0x30;
    *(char *)(param_1 + iVar3) = (char)uVar5;
    param_2 = param_2 - uVar2 * (param_2 / uVar2);
    uVar2 = uVar2 / 10;
    if (((uVar5 & 0xff) == 0x30) && ((char)((int)((uint)(iVar4 != 0) << 0x1f) >> 0x1f) != '\x01')) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 1;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

