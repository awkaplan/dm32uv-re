/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_buffer_frame_process @ 030c99d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 992 bytes
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

void channel_buffer_frame_process
               (short *param_1,undefined4 param_2,short param_3,short param_4,int param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  uint uVar13;
  undefined1 auStack_338 [336];
  short asStack_1e8 [56];
  short asStack_178 [56];
  undefined1 auStack_108 [112];
  undefined1 auStack_98 [114];
  short sStack_26;
  short sVar12;
  
  iVar4 = param_5 + 0x470;
  if ((*(ushort *)(param_5 + 0x7ba) & 1) == 0) {
    if (*param_1 == 1) {
      func_0x030d993c(param_5 + 0x172,param_1 + 8,(int)param_1[2]);
    }
    else {
      u16_buffer_fill_memset(param_5 + 0x172,*(ushort *)(param_5 + 0x7ba) & 1,0x38);
    }
    func_0x030d2838(param_1 + 8,param_1 + 0x42,(int)param_1[2]);
    sVar1 = *param_1;
    if (sVar1 == 1) {
      func_0x030d7418(param_1 + 8,param_1 + 0x42,param_5 + 0x7c0,param_5 + 0x7c2,(int)param_1[6],
                      (int)param_1[2]);
      sVar1 = *param_1;
    }
    if (sVar1 == 2) {
      call_config_state_duplicate(param_5 + 0x4f8,param_1);
    }
  }
  *(undefined1 **)(param_1 + 0x40) = auStack_98;
  display_buffer_command_dispatch(param_1);
  *(undefined1 **)(param_5 + 0x4f0) = auStack_108;
  display_buffer_command_dispatch(iVar4);
  if (param_1[1] == 0xff) {
    if (param_4 == 0) {
      sVar1 = func_0x030d299c((int)*(short *)(param_5 + 0x7be),(int)param_1[6],
                              *(undefined4 *)(param_1 + 4));
      *(short *)(param_5 + 0x7be) = sVar1;
    }
    else {
      sVar1 = *(short *)(param_5 + 0x7be);
    }
    if ((0x3333 < sVar1) || (sVar1 != 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar5 = fixed_point_signed_divide_16bit(0x40000000,1,0,0xfffffffc,&sStack_26);
    uVar8 = (uint)(ushort)param_1[6];
    iVar4 = (int)param_1[6];
    if (iVar4 < 0) {
      uVar13 = iVar4 * 0x10000;
      puVar6 = (ushort *)(param_1 + 8);
      while( true ) {
        while( true ) {
          if (((uVar5 & 0xffff) * uVar8 & 0x7fffffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          uVar8 = (uint)(short)((sStack_26 + -4) * 2);
          if ((int)uVar8 < 0) {
            iVar10 = 0 >> (-uVar8 & 0x3f);
          }
          else {
            iVar10 = 0 << (uVar8 & 0x3f);
          }
          uVar8 = iVar4 * 0x10000;
          uVar9 = uVar8 + uVar13;
          *puVar6 = (ushort)((uint)*puVar6 * (iVar10 >> 0x10 & 0xffffU) * 2 >> 0x10);
          if (-1 < (int)((uVar9 ^ uVar13) & (uVar9 ^ uVar8))) break;
          if (-1 < (int)uVar8) goto LAB_030c9d30;
          puVar6 = puVar6 + 1;
          uVar8 = 0x8000;
          iVar4 = -0x8000;
        }
        uVar7 = (ushort)(uVar9 >> 0x10);
        iVar4 = (int)(short)uVar7;
        puVar6 = puVar6 + 1;
        if (-1 < iVar4) break;
        uVar8 = (uint)uVar7;
      }
    }
LAB_030c9d30:
    uVar7 = param_1[2];
    if (0 < (short)uVar7) {
      sVar1 = param_1[0x42];
      param_1 = param_1 + 8;
      iVar4 = 0;
      do {
        *(short *)((int)asStack_178 + iVar4) = *param_1;
        *(short *)((int)asStack_1e8 + iVar4) = sVar1;
        iVar4 = iVar4 + 2;
        param_1 = param_1 + 1;
      } while (iVar4 != ((uVar7 - 1 & 0xffff) + 1) * 2);
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (*(short *)(param_5 + 0x7a0) == 1) {
    sVar1 = classify_id_into_range_bucket();
    if (((sVar1 == 0) && (*(short *)(param_5 + 0x470) == 3)) &&
       (sVar1 = classify_id_into_range_bucket((int)*(short *)(param_5 + 0x472)), sVar1 == 0)) {
      sVar1 = *(short *)(param_5 + 0x476);
      uVar7 = param_1[3] - sVar1;
      if ((short)uVar7 < 0) {
        uVar7 = ~uVar7 + 1;
      }
      if ((short)uVar7 < 2) {
        sVar2 = param_1[1];
        if ((int)sVar2 < (sVar1 + 1) * 0x10) {
          channel_window_slot_rotate(param_1,(int)sVar1);
          goto LAB_030c9aca;
        }
      }
      else {
        sVar2 = param_1[1];
      }
      sVar1 = signed_divide_saturating
                        ((int)sVar2 * (sVar1 + 1) + (int)*(short *)(param_5 + 0x472) / 2);
      for (iVar10 = (int)sVar1 << 4; iVar10 <= param_1[1]; iVar10 = iVar10 + 0x10) {
        sVar1 = sVar1 + 1;
      }
      channel_window_slot_rotate(param_1,(int)(short)(sVar1 + -1));
    }
  }
  else {
    sVar1 = classify_id_into_range_bucket();
    sVar2 = FUN_030ca098((int)sVar1,(int)param_1[1],0);
    sVar3 = FUN_030ca098((int)sVar1,(int)param_1[1],1);
    sVar1 = param_1[2];
    if (0 < sVar1) {
      puVar6 = (ushort *)(param_1 + 8);
      sVar12 = 0;
      do {
        sVar11 = sVar12 + 1;
        if ((sVar2 != sVar12) && (sVar3 != sVar12)) {
          *puVar6 = (ushort)((uint)*puVar6 * 0xa3c >> 0x10);
        }
        puVar6 = puVar6 + 1;
        sVar12 = sVar11;
      } while (sVar11 < sVar1);
    }
    uVar8 = (uint)(ushort)param_1[1];
    if ((uVar8 - 0x80 & 0xffff) < 0x20) {
      sVar1 = FUN_030c9000((uint)(ushort)param_1[sVar3 + 8] * (uint)(ushort)param_1[sVar3 + 8] +
                           (uint)(ushort)param_1[sVar2 + 8] * (uint)(ushort)param_1[sVar2 + 8],8,4);
      uVar8 = (uint)(ushort)param_1[1];
      param_1[sVar3 + 8] = sVar1;
      param_1[sVar2 + 8] = sVar1;
    }
    if ((uVar8 - 0x14 & 0xffff) < 3) {
      sVar1 = signed_divide_saturating_halved(uVar8 << 0x14,(int)(short)((param_1[3] + 1) * 0x100));
      param_1[6] = sVar1;
    }
  }
LAB_030c9aca:
  u16_buffer_fill_memset(auStack_338,0,(int)(short)(param_3 * 2));
  iVar10 = (int)param_3;
  FUN_030cac00(auStack_338,iVar10,param_5 + 0x648,param_1,(int)*(short *)(param_5 + 0x7be));
  FUN_030cda30(auStack_338,iVar10,param_5 + 0x18,param_1,iVar4,(int)*(short *)(param_5 + 0x7be));
  FUN_030c864c(auStack_338,auStack_338,param_5,iVar10);
  FUN_030caa34(param_2,0xf,auStack_338,0x11,iVar10);
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  call_config_state_duplicate(iVar4,param_1);
  return;
}

