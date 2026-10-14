/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cfe48 @ 030cfe48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 274 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030cfe48(undefined4 param_1,int param_2__w,int param_3,undefined4 param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8__w,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12__w,short *param_13,int param_14,int param_15__w)

{
  short param_2 = (short)param_2__w;
  short param_8 = (short)param_8__w;
  short param_12 = (short)param_12__w;
  short param_15 = (short)param_15__w;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_88 [16];
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [16];
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [4];
  
  iVar3 = (int)param_13[1];
  iVar1 = *(int *)(param_14 + 0x24);
  *(undefined2 *)(param_5 + 0xe) = *(undefined2 *)(iVar1 + (iVar3 + 1) * 2);
  iVar2 = (int)param_12;
  *(undefined2 *)(param_3 + 0xe) = *(undefined2 *)(iVar1 + iVar3 * 2);
  if (iVar2 == 1) {
    func_0x030cfb2c(param_5 + 0xc,auStack_78,auStack_38,auStack_58,1,iVar3,param_14);
    func_0x030cfb2c(param_3 + 0xc,auStack_88,auStack_48,auStack_68,0,(int)param_13[1],param_14);
  }
  if (*param_13 != 0) {
    func_0x030cfcd4(param_1,auStack_28,(int)param_2,param_3,param_5,param_7,(int)param_8,param_9,
                    iVar2,param_13,auStack_88,(int)param_15);
  }
  if (iVar2 != 3) {
    func_0x030cfa84(param_5,param_7,1,(int)param_13[1],param_14,param_11);
    func_0x030cfa84(param_3,param_7,0,(int)param_13[1],param_14,param_11);
  }
  if (*param_13 != 0) {
    func_0x030cfe00(param_1,auStack_28,param_3,param_7,iVar2,param_13);
  }
  return;
}

