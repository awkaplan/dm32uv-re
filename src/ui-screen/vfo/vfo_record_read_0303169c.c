/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_record_read @ 0303169c (file base 0x03000000; code starts at 0x03001000)
 * Size: 340 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void * vfo_record_read(void *param_1,int param_2__w)

{
  char param_2 = (char)param_2__w;
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_70;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [24];
  undefined2 local_1c;
  undefined1 local_1a [2];
  
  if (param_2 == '\0') {
    bVar2 = p_dm32_settings_block04[0x2d];
    uVar3 = p_dm32_settings_block04[0x27];
    local_1c = 0xfaf;
    uVar1 = *p_dm32_settings_block04;
  }
  else {
    bVar2 = (byte)p_dm32_settings_block04[0x2d] >> 1;
    uVar3 = p_dm32_settings_block04[0x28];
    local_1c = 0xfdf;
    uVar1 = p_dm32_settings_block04[0x13];
  }
  if ((bVar2 & 1) == 0) {
    flash_field_read_cached(0x41,local_1c,auStack_3c,0x20);
    memcpy_bytes_iram(&uStack_68,auStack_34,0x18);
    uVar4 = vfo_tx_contact_field_read_wrapper(param_2);
    uStack_40 = uStack_40 & 0xff0000ff | (uVar4 & 0xffff) << 8;
    local_70 = bcd_frequency_decode(auStack_3c,4);
    uStack_6c = channel_apply_frequency_offset
                          (local_70,uStack_6c,uStack_68,uStack_64,uStack_60,uStack_5c,uStack_58,
                           uStack_54,uStack_50,uStack_4c,uStack_48,uStack_44,(undefined2)uStack_40);
  }
  else {
    uVar4 = get_current_mode_state1();
    if (uVar4 < 2) {
      uVar4 = channel_list_index_resolve(uVar1,uVar3);
    }
    else {
      uVar4 = (uint)*(ushort *)&p_vfo_freq_display_state->field_0x5a_0;
    }
    channel_num_to_block_offset(uVar4,local_1a,&local_1c);
    flash_field_read_cached(local_1a[0],local_1c,auStack_3c,0x20);
    memcpy_bytes_iram(&uStack_68,auStack_34,0x18);
    channel_record_read_full(uVar4,&uStack_50);
    uVar4 = vfo_channel_apply_delegate(uVar4);
    uStack_40 = uStack_40 & 0xff0000ff | (uVar4 & 0xffff) << 8;
    local_70 = bcd_frequency_decode(auStack_3c,4);
    uStack_6c = bcd_frequency_decode(auStack_38,4);
  }
  iVar5 = value_at_or_above_low_bound_check(local_70);
  if (iVar5 == 1) {
    uStack_68 = uStack_68 & 0xffffff0f;
  }
  memcpy_ck803s(param_1,&local_70,0x33);
  return param_1;
}

