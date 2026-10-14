/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rc4_key_scheduling_init @ 030c42b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rc4_key_scheduling_init(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte abStack_104 [256];
  
  uVar2 = 0;
  do {
    *(char *)(param_1 + uVar2) = (char)uVar2;
    abStack_104[uVar2] = *(byte *)(param_2 + (uVar2 - param_3 * (uVar2 / param_3)));
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x100);
  uVar2 = 0;
  iVar3 = 0;
  do {
    bVar1 = *(byte *)(param_1 + iVar3);
    uVar2 = (uint)abStack_104[iVar3] + (uint)bVar1 + uVar2 & 0xff;
    *(byte *)(param_1 + iVar3) = *(byte *)(param_1 + uVar2);
    iVar3 = iVar3 + 1;
    *(byte *)(param_1 + uVar2) = bVar1;
  } while (iVar3 != 0x100);
  return;
}

