/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_offset_minus_0x10 @ 030558e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_offset_minus_0x10(uint param_1,short *param_2,short *param_3)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  
  iVar2 = (param_1 & 0xff) - 1;
  uVar4 = iVar2 / 0x1c;
  uVar1 = (ushort)(iVar2 % 0x1c) & 0xff;
  if ((uVar4 & 0xffff) == 0) {
    sVar3 = uVar1 * 0x91 + 0x10;
  }
  else {
    sVar3 = uVar1 * 0x91;
  }
  *param_2 = (short)uVar4 + 0x5c;
  *param_3 = sVar3;
  return;
}

