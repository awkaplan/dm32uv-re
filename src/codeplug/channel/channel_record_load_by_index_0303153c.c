/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_load_by_index @ 0303153c (file base 0x03000000; code starts at 0x03001000)
 * Size: 330 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void * channel_record_load_by_index(void *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [24];
  undefined2 local_18;
  undefined1 local_16 [2];
  
  iVar3 = is_memory_channel_not_vfo();
  if (iVar3 == 1) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      memcpy_ck803s(param_1,DAT_03031690,0x33);
    }
    else {
      memcpy_ck803s(param_1,DAT_03031694,0x33);
    }
  }
  else {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      bVar1 = p_dm32_settings_block04[0x2d];
      uVar2 = p_dm32_settings_block04[0x27];
      local_18 = 0xfaf;
    }
    else {
      bVar1 = (byte)p_dm32_settings_block04[0x2d] >> 1;
      uVar2 = p_dm32_settings_block04[0x28];
      local_18 = 0xfdf;
    }
    if ((bVar1 & 1) == 0) {
      flash_field_read_cached(0x41,local_18,auStack_38,0x20);
      memcpy_bytes_iram(&uStack_64,auStack_30,0x18);
      local_6c = bcd_frequency_decode(auStack_38,4);
      uStack_68 = channel_apply_frequency_offset
                            (local_6c,uStack_68,uStack_64,uStack_60,uStack_5c,uStack_58,uStack_54,
                             uStack_50,uStack_4c,uStack_48,uStack_44,uStack_40,uStack_3c);
    }
    else {
      uVar4 = get_current_mode_state1();
      if (uVar4 < 2) {
        uVar4 = channel_list_index_resolve(p_dm32_settings_block04[0x29],uVar2);
      }
      else {
        uVar4 = (uint)*(ushort *)&p_vfo_freq_display_state->field_0x5a_0;
      }
      channel_num_to_block_offset(uVar4,local_16,&local_18);
      flash_field_read_cached(local_16[0],local_18,auStack_38,0x20);
      memcpy_bytes_iram(&uStack_64,auStack_30,0x18);
      local_6c = bcd_frequency_decode(auStack_38,4);
      uStack_68 = bcd_frequency_decode(auStack_34,4);
    }
    memcpy_ck803s(param_1,&local_6c,0x33);
  }
  return param_1;
}

