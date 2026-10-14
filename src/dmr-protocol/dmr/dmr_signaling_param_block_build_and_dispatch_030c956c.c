/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_signaling_param_block_build_and_dispatch @ 030c956c (file base 0x03000000; code starts at 0x03001000)
 * Size: 538 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

ushort dmr_signaling_param_block_build_and_dispatch
                 (undefined4 param_1,short param_2,ushort param_3,undefined2 param_4,int param_5,
                 ushort param_6)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puStack_1c0;
  undefined1 auStack_1a8 [136];
  undefined1 auStack_120 [136];
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  undefined2 uStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  undefined2 uStack_68;
  ushort uStack_66;
  int iStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  short sStack_58;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  int iStack_50;
  ushort auStack_4c [16];
  ushort uStack_2c;
  ushort uStack_2a;
  short sStack_26;
  
  uVar3 = (uint)param_6;
  if (*(short *)(param_5 + 0x138a) == 0) {
    param_3 = param_3 & 0xf7ff;
  }
  iStack_64 = param_5 + 0xa2e;
  iStack_60 = param_5 + 0x122e;
  iStack_78 = param_5 + 0x926;
  uStack_68 = *(undefined2 *)(param_5 + 0x97c);
  iStack_6c = param_5 + 0x740;
  iStack_74 = param_5 + 0x6f8;
  iStack_70 = param_5 + 0x710;
  iStack_8c = param_5 + 0x644;
  uStack_66 = (ushort)(((uint)((param_3 & 0x40) != 0) << 0x1f) >> 0x1f);
  uStack_88 = *(undefined2 *)(param_5 + 0x630);
  iStack_94 = param_5 + 0x69e;
  iStack_7c = param_5 + 0x746;
  uStack_54 = *(undefined2 *)(param_5 + 0x980);
  uStack_52 = *(undefined2 *)(param_5 + 0xa72);
  iStack_80 = param_5 + 0x624;
  iStack_98 = param_5 + 0x64e;
  iVar5 = param_5 + 0x938;
  sStack_58 = 0;
  iStack_90 = param_5 + 0x63a;
  iStack_84 = param_5 + 0x18;
  uStack_5c = _DAT_030c9788;
  uStack_56 = param_4;
  iStack_50 = iVar5;
  sVar1 = FUN_030cfbc0(param_5 + 0x138a);
  uVar2 = FUN_030cc8c4(iVar5,(int)sVar1);
  if ((param_3 & 0x4000) == 0) {
    sVar1 = FUN_030c7ce0(&sStack_26,&uStack_2c,param_5 + 0x1370);
    if (sVar1 == 0) {
      *(undefined2 *)(param_5 + 0x1370) = 0;
      if ((uVar2 == 0) && ((param_3 & 0x800) != 0)) {
        puVar4 = auStack_4c;
        uVar2 = log_domain_sample_decode_with_energy_clamp(puVar4,iVar5);
        if (uVar3 != 0) {
          do {
            *puVar4 = (ushort)((short)param_6 * 0x10000 + (uint)*puVar4 * 0x10000 >> 0x10);
            puVar4 = puVar4 + 1;
          } while (&uStack_2c != puVar4);
        }
        uVar6 = 2;
      }
      else {
        sStack_58 = sStack_58 + param_6;
        uVar2 = uVar2 | 2;
        uVar6 = 1;
      }
      goto LAB_030c96a0;
    }
    *(ushort *)(param_5 + 0x1370) = param_3 & 0x4000;
  }
  else {
    uStack_2c = *(ushort *)(param_5 + 0x1372);
    sStack_26 = *(short *)(param_5 + 0x1374);
    *(undefined2 *)(param_5 + 0x1370) = 1;
    uStack_2a = uStack_2c;
  }
  uVar2 = uVar2 | 0x8002;
  if (uVar3 == 0) {
    uVar6 = 3;
  }
  else {
    uStack_2c = (ushort)(uVar3 * 0x10000 + (uint)uStack_2c * 0x10000 >> 0x10);
    uStack_2a = (ushort)(uVar3 * 0x10000 + (uint)uStack_2a * 0x10000 >> 0x10);
    uVar6 = 3;
  }
LAB_030c96a0:
  puStack_1c0 = auStack_4c;
  calibration_fingerprint_compare_and_reset(&sStack_26,param_5 + 0x16ba,1);
  FUN_030cfe48(param_1,(int)param_2,auStack_120,0x44,auStack_1a8,0x44,param_5 + 0xabc,(int)sStack_26
               ,&uStack_2c,param_3 & 0x200,puStack_1c0,uVar6,param_5 + 0x138a,&iStack_98,
               param_3 & 0x80);
  return uVar2;
}

