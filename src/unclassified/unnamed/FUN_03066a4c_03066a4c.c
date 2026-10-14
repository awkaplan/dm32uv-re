/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03066a4c @ 03066a4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_03066a4c(void)

{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  byte abStack_14 [5];
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  
  iVar1 = sdcard_read_csd(abStack_14);
  if (iVar1 == 0) {
    if ((abStack_14[0] & 0xc0) == 0x40) {
      uVar3 = bStack_b + 1 + (ushort)bStack_c * 0x100;
      *(ushort *)((int)PTR_DAT_03066ad8 + 2) = uVar3;
      *PTR_DAT_03066adc = (uint)uVar3 << 10;
    }
    else {
      iVar1 = (uint)(bStack_c >> 6) + (uint)bStack_d * 4 + 1 + (bStack_e & 3) * 0x400;
      *(short *)((int)PTR_DAT_03066ad8 + 2) = (short)iVar1;
      *PTR_DAT_03066adc =
           iVar1 << (((bStack_f & 0xf) + (uint)(bStack_a >> 7) + (bStack_b & 3) * 2) - 7 & 0x3f);
    }
    uVar2 = *PTR_DAT_03066adc;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

