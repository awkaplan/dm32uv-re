/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_block_decode_tag6_dispatch @ 030cff5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 392 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: dmr-protocol
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: RAW - unmodified decompiler output; the name, if any, is a guess. */

uint dmr_block_decode_tag6_dispatch
               (short *param_1,undefined4 param_2,short *param_3,uint param_4,int param_5,
               undefined4 param_6,short param_7,undefined4 param_8,int param_9,short *param_10,
               undefined4 param_11,undefined4 param_12,short param_13)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined1 auStack_2c [6];
  short sStack_26;
  
  if (*param_10 == 0) {
    return param_4;
  }
  func_0x030cfbc4(param_10,(int)*param_10,
                  (int)(short)(0x31 - *(short *)(_DAT_030d00e4 + param_7 * 2)));
  func_0x030d2370(auStack_2c,param_6);
  sVar1 = pack_u16_array_low_bits_to_bitfield(param_6,6);
  if (sVar1 == 0x3f) {
    uVar3 = func_0x030d9100(param_1,param_3,auStack_2c,param_10,param_5);
    uVar3 = uVar3 & 0xffff;
    if (uVar3 != 0) goto LAB_030d0094;
  }
  else {
    if (sVar1 == 0x3e) {
      sVar1 = 2;
    }
    else {
      if (0x3b < sVar1) {
        uVar3 = 4;
        goto LAB_030d0094;
      }
      sVar1 = 1;
    }
    *param_3 = sVar1;
    param_3[1] = 0xff;
    *param_1 = sVar1;
    param_1[1] = 0xff;
    func_0x030d9330(param_6,1,param_10);
    sStack_26 = func_0x030d281c(auStack_2c,(int)param_10[5]);
    sVar2 = func_0x030d281c(auStack_2c,(int)param_10[4]);
    func_0x030d29d4(sVar1,param_3 + 4,param_1 + 4,(int)sVar2,(int)param_10[4]);
    sVar1 = func_0x030d7b10(&sStack_26,param_3,param_1,0,0,(int)param_10[5],0);
    if (sVar1 == 0) {
      func_0x030d2798((int)*param_1,param_1 + 6,param_1 + 2,(int)sStack_26,(int)param_10[5],
                      (int)param_13);
    }
    else {
      param_3[6] = 0x1079;
      param_3[2] = 0x38;
      param_1[6] = 0x1079;
      param_1[2] = 0x38;
    }
    func_0x030d2314(param_5,param_1,param_10,auStack_2c,0);
    func_0x030d9534(param_1,param_5,(int)*(short *)(param_9 + 0x30),(int)*(short *)(param_9 + 0x24))
    ;
  }
  func_0x030d66a4(param_3,param_1,param_5,0,(int)param_13);
  func_0x030d1c44(param_5,param_1,0,param_10);
  uVar3 = 0;
LAB_030d0094:
  *(undefined2 *)(param_5 + 0x88) = 0xfffd;
  return uVar3;
}

