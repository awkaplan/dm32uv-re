/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_codec_pool_and_state_init @ 030c5ec8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 712 bytes
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

void modem_codec_pool_and_state_init(undefined1 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_28;
  
  vframe_message_poll_and_dispatch_3x();
  puVar1 = PTR_DAT_030c6144;
  PTR_DAT_030c6144[0xba3] = 0xffd8;
  iVar2 = _DAT_030c6148;
  puVar1[0xba4] = 0x4000;
  puVar1[0xba7] = 0x51e;
  puVar1[0xb9f] = 0xffec;
  *(undefined2 *)(iVar2 + 0x116c) = 0xffec;
  puVar1[0xba8] = 10;
  puVar1[0xba2] = 0xfff6;
  puVar1[0xb9d] = 0x2000;
  puVar1[0xb9e] = 0x80;
  puVar1[0xb96] = 0x1840;
  puVar1[0xba0] = 0xffea;
  puVar1[0xba1] = 0x14;
  puVar1[0xba5] = 0xccc;
  puVar1[0xba6] = 0xccc;
  puVar1[0xba9] = 0x14;
  *(undefined2 *)(iVar2 + 0x1152) = 0;
  *(undefined2 *)(iVar2 + 0x116a) = 0x80;
  channel_signaling_param_struct_defaults_init(puVar1,1,1);
  display_status_buffer_reset_or_score_calc(puVar1 + 0xb70,1);
  channel_tx_rx_offset_set(puVar1,(int)(short)puVar1[0xb9e],(int)(short)puVar1[0xb9f]);
  dmr_state_init_with_lcg_fill(iVar2,1);
  display_status_buffer_reset_or_score_calc(iVar2 + 0xfd0,1);
  channel_buffer_prepare_or_passthrough(iVar2 + 0x12ae,0x50,iVar2 + 0x1354,0,8,0,iVar2);
  codec_level_id_store_and_scale
            (iVar2,(int)*(short *)(iVar2 + 0x116a),(int)*(short *)(iVar2 + 0x116c));
  *(undefined1 *)(puVar1 + 0xb95) = 0;
  *(undefined1 *)(puVar1 + 0xcea) = 0;
  *(undefined1 *)((int)puVar1 + 0x19d5) = 0;
  *(undefined1 *)(puVar1 + 0xceb) = 0;
  *(undefined1 *)((int)puVar1 + 0x1729) = 0;
  *(undefined1 *)(iVar2 + 0x1496) = 0;
  *(undefined1 *)(iVar2 + 0x1494) = 0;
  *(undefined1 *)(iVar2 + 0x1495) = 0;
  *(undefined1 *)(iVar2 + 0x1497) = 0;
  *(undefined1 *)(iVar2 + 0x1498) = 0;
  *(undefined1 *)(iVar2 + 0x1151) = 0;
  *(undefined1 *)PTR_DAT_030c614c = 0;
  puVar1[0xb99] = 0;
  puVar1[0xb9a] = 0;
  puVar1[0xb9b] = 0;
  puVar1[0xb9c] = 0;
  puVar1[0xc4b] = 0;
  puVar1[0xc4a] = 0;
  uVar3 = _DAT_030c6150;
  *(undefined2 *)(iVar2 + 0x1162) = 0;
  *(undefined2 *)(iVar2 + 0x1164) = 0;
  *(undefined2 *)(iVar2 + 0x1166) = 0;
  *(undefined2 *)(iVar2 + 0x1168) = 0;
  *(undefined2 *)(iVar2 + 0x1350) = 0;
  *(undefined2 *)(iVar2 + 0x134e) = 0;
  *(undefined2 *)(iVar2 + 0x1352) = 0;
  *(undefined2 *)(iVar2 + 0x1474) = 0;
  *(undefined2 *)(iVar2 + 0x1476) = 0;
  func_0x030deca4(uVar3,0,0x1b);
  func_0x030deca4(_DAT_030c6154,0,0x1b);
  *(undefined1 *)PTR_DAT_030c6158 = 0;
  func_0x030deca4(_DAT_030c615c,0,0x1b);
  func_0x030deca4(_DAT_030c6160,0,0x1b);
  *(undefined1 *)PTR_DAT_030c6164 = 0;
  func_0x030deca4(_DAT_030c6168,0,0x1b);
  func_0x030deca4(_DAT_030c616c,0,0x1b);
  func_0x030deca4(puVar1 + 0xc94,0,0x90);
  func_0x030deca4(iVar2 + 0x13e4,0,0x90);
  *(undefined1 *)(puVar1 + 0xb94) = 0;
  *(undefined1 *)(iVar2 + 0x1150) = 0;
  vframe_message_poll_and_dispatch_3x(param_1);
  func_0x0612005c(_DAT_030c6170,0,0x1400);
  uVar3 = FUN_030c5d8c();
  OSTaskCreate_variant2
            (_DAT_030c6174,_DAT_030c6178,_DAT_030c617c,param_1,uVar3,_DAT_030c6170,0,0x500,0,0,0,0,
             &iStack_28);
  if (iStack_28 != 0) {
    *param_1 = 4;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  func_0x0612005c(_DAT_030c61d0,0,0xc00);
  uVar3 = func_0x030c5d9c();
  OSTaskCreate_variant2
            (_DAT_030c61d8,_DAT_030c61d4,_DAT_030c61dc,param_1,uVar3,_DAT_030c61d0,0,0x300,0,0,0,0,
             &iStack_28);
  if (iStack_28 != 0) {
    *param_1 = 5;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

