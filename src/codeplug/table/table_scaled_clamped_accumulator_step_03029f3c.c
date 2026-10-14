/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_scaled_clamped_accumulator_step @ 03029f3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 table_scaled_clamped_accumulator_step(uint param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  
  uVar1 = (uint)(byte)PTR_LAB_03029fd0[*(byte *)PTR_DAT_03029fcc] * ((param_1 & 7) * 2 + 1) >> 3;
  uVar4 = uVar1 & 0xff;
  cVar2 = (char)uVar1;
  if ((param_1 & 8) == 0) {
    if (uVar4 + *(byte *)PTR_DAT_03029fc8 < 0x100) {
      *(byte *)PTR_DAT_03029fc8 = cVar2 + *(byte *)PTR_DAT_03029fc8;
    }
    else {
      *(undefined1 *)PTR_DAT_03029fc8 = 0xff;
    }
  }
  else if (uVar4 < *(byte *)PTR_DAT_03029fc8) {
    *(byte *)PTR_DAT_03029fc8 = *(byte *)PTR_DAT_03029fc8 - cVar2;
  }
  else {
    *(undefined1 *)PTR_DAT_03029fc8 = 0;
  }
  bVar3 = PTR_DAT_03029fd4[param_1 & 0xf] + *(char *)PTR_DAT_03029fcc;
  *(byte *)PTR_DAT_03029fcc = bVar3;
  if (bVar3 < 0x81) {
    if (0x1d < bVar3) {
      *(undefined1 *)PTR_DAT_03029fcc = 0x1d;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03029fcc = 0;
  }
  return *(undefined1 *)PTR_DAT_03029fc8;
}

