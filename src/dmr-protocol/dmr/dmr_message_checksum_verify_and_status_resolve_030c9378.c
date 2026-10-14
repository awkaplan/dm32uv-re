/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_message_checksum_verify_and_status_resolve @ 030c9378 (file base 0x03000000; code starts at 0x03001000)
 * Size: 500 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
dmr_message_checksum_verify_and_status_resolve
          (undefined4 param_1,short param_2,ushort param_3,short param_4,short *param_5,
          undefined4 param_6,int param_7)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  byte bVar5;
  undefined4 uVar6;
  short sStack_26;
  
  param_3 = *(ushort *)(param_7 + 0x646) | param_3;
  *(short *)(param_7 + 0x7ba) = *(short *)(param_7 + 0x7ba) << 1;
  if ((param_3 & 0xc) == 0) {
    uVar4 = dmr_block_decode_tag6_dispatch
                      (param_5,0x44,param_6,0x44,param_7 + 0x580,param_1,(int)param_2,(int)param_4,
                       param_7 + 0x614,param_7 + 0x7a0,(int)*(short *)(param_7 + 0x7c0),
                       (int)*(short *)(param_7 + 0x7c2),param_3 & 0x80);
    if (uVar4 == 0) {
      bVar5 = 0;
      bVar1 = false;
    }
    else {
      bVar5 = ~((uVar4 & 8) != 0);
      bVar1 = (uVar4 & 8) != 0;
    }
  }
  else {
    bVar5 = 0;
    bVar1 = false;
  }
  sStack_26 = param_5[1];
  sVar2 = calibration_fingerprint_compare_and_reset(&sStack_26,param_7 + 0x7c4,0);
  if ((param_3 & 0x4000) == 0) {
    if (sVar2 != 0) {
      sVar2 = classify_id_into_range_bucket((int)sStack_26);
      sVar2 = FUN_030ca098((int)sVar2,(int)sStack_26,param_3 & 0x4000);
      sVar2 = param_5[sVar2 + 8];
      sVar3 = classify_id_into_range_bucket((int)sStack_26);
      sVar3 = FUN_030ca098((int)sVar3,(int)sStack_26,1);
      sVar2 = (short)((uint)((int)sVar2 + (int)param_5[sVar3 + 8]) >> 1);
      goto LAB_030c93dc;
    }
  }
  else {
    sStack_26 = *(short *)(param_7 + 0x79c);
    sVar2 = *(short *)(param_7 + 0x79e);
LAB_030c93dc:
    sVar2 = channel_tone_or_offset_buffer_build(param_5,(int)sStack_26,(int)sVar2,(int)sVar2,0);
    if (sVar2 == 0) {
      call_config_state_duplicate(param_6,param_5);
      uVar6 = 0x8002;
      goto LAB_030c9552;
    }
  }
  if ((param_3 & 8) == 0) {
    if ((param_3 & 4) == 0) {
      if (bVar1) goto LAB_030c941e;
      if (bVar5 == 0) {
        sVar2 = *param_5;
        uVar6 = 0;
        if (sVar2 == 2) {
LAB_030c9552:
          *(undefined2 *)(param_7 + 0x7bc) = 0;
          FUN_030d1ce0(param_7 + 0x580);
          return uVar6;
        }
        if (sVar2 == 3) {
          uVar6 = 0x8002;
          goto LAB_030c9552;
        }
        if (sVar2 == 1) {
          if (*(short *)(param_7 + 0x7a0) == 0) {
            if (param_5[1] == 0xff) {
              uVar6 = 2;
            }
            else {
              uVar6 = 0x8002;
            }
          }
          else {
            uVar6 = 2;
          }
          goto LAB_030c9552;
        }
      }
    }
    if ((*(ushort *)(param_7 + 0x7ba) & 0xe) != 0xe) {
      call_config_state_duplicate(param_5,param_7 + 0x470);
      goto LAB_030c9428;
    }
  }
LAB_030c941e:
  call_config_state_duplicate(param_5,param_7 + 0x4f8);
LAB_030c9428:
  call_config_state_duplicate(param_6,param_5);
  *(ushort *)(param_7 + 0x7ba) = *(ushort *)(param_7 + 0x7ba) | 1;
  FUN_030d1ce0(param_7 + 0x580);
  return 0x20;
}

