/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_list_entry_unlink @ 0306b3b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void timer_list_entry_unlink(int param_1)

{
  uint uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 0x18) -
          (*(uint *)(param_1 + 0x18) / (uint)(ushort)*PTR_DAT_0306b4d4) *
          (uint)(ushort)*PTR_DAT_0306b4d4 & 0xffff;
  if (PTR_DAT_0306b4cc[uVar1 * 2] == param_1) {
    iVar3 = *(int *)(PTR_DAT_0306b4cc[uVar1 * 2] + 0x10);
    PTR_DAT_0306b4cc[uVar1 * 2] = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14);
    iVar4 = *(int *)(param_1 + 0x10);
    *(int *)(iVar3 + 0x10) = iVar4;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x14) = iVar3;
    }
  }
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  psVar2 = (short *)(uVar1 * 8 + DAT_0306b4d0);
  *psVar2 = *psVar2 + -1;
  return;
}

