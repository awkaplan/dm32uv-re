/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_window_slot_rotate @ 030ca608 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_window_slot_rotate(int param_1,int param_2__w)

{
  short param_2 = (short)param_2__w;
  int iVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  undefined2 uVar5;
  short sStack_e;
  
  sVar3 = *(short *)(param_1 + 6);
  iVar1 = sVar3 + 8;
  uVar5 = *(undefined2 *)(param_1 + iVar1 * 2);
  iVar2 = *(int *)(param_1 + 0x80);
  *(undefined2 *)(param_1 + iVar1 * 2) = 0;
  *(undefined2 *)(iVar2 + sVar3 * 2) = 0;
  *(undefined2 *)(param_1 + (param_2 + 8) * 2) = uVar5;
  *(short *)(param_1 + 6) = param_2;
  *(undefined2 *)(iVar2 + param_2 * 2) = 1;
  if (*(short *)(param_1 + 2) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (*(short *)(param_1 + 6) != -1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = fixed_point_signed_divide_16bit(0,0xf,0,0x17,&sStack_e);
  uVar4 = (uint)(short)(sStack_e + 4);
  if ((int)uVar4 < 0) {
    uVar5 = (undefined2)((uint)((iVar1 << 0x10) >> (-uVar4 & 0x3f)) >> 0x10);
  }
  else {
    uVar5 = (undefined2)((uint)((iVar1 << 0x10) << (uVar4 & 0x3f)) >> 0x10);
  }
  sVar3 = *(short *)(param_1 + 4);
  *(undefined2 *)(param_1 + 0xc) = uVar5;
  if (sVar3 <= *(short *)(param_1 + 6)) {
    sVar3 = *(short *)(param_1 + 6) + 1;
  }
  if (sVar3 < 9) {
    sVar3 = 9;
  }
  if (0x38 < sVar3) {
    sVar3 = 0x38;
  }
  *(short *)(param_1 + 4) = sVar3;
  return;
}

