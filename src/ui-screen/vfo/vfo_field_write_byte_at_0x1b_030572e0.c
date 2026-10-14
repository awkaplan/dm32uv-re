/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_byte_at_0x1b @ 030572e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 246 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_field_write_byte_at_0x1b(int param_1__w)

{
  byte param_1 = (byte)param_1__w;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_40 [36];
  undefined4 uStack_1c;
  short local_18;
  undefined2 local_16;
  
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  p_vfo_display_state->field_0x1b = param_1;
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      local_18 = 0xfaf;
    }
    else {
      local_18 = 0xfdf;
    }
    local_16 = 0x41;
  }
  else {
    uVar4 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
    channel_num_to_block_offset(uVar4,&local_16,&local_18);
  }
  flash_field_write_cached((undefined1)local_16,local_18 + 0x1b,param_1);
  uVar4 = flash_field_block67_signed_threshold_check(param_1);
  *PTR_DAT_030573e4 = uVar4;
  call_setup_sm_aux_field24_store();
  uStack_1c = 1;
  uVar4 = *(undefined4 *)p_vfo_display_state;
  uVar1 = *(undefined4 *)&p_vfo_display_state->field_0x4_0;
  SUBPIECE_SET(uVar2, 0, 1, p_vfo_display_state->flags_0x8);
  SUBPIECE_SET(uVar2, 1, 1, p_vfo_display_state->flags_0x9);
  SUBPIECE_SET(uVar2, 2, 1, p_vfo_display_state->field_0xa);
  SUBPIECE_SET(uVar2, 3, 1, p_vfo_display_state->field_0xb);
  SUBPIECE_SET(uVar3, 0, 1, p_vfo_display_state->field_0xc);
  SUBPIECE_SET(uVar3, 1, 1, p_vfo_display_state->flags_0xd);
  SUBPIECE_SET(uVar3, 2, 1, p_vfo_display_state->field_0xe);
  SUBPIECE_SET(uVar3, 3, 1, p_vfo_display_state->field_0xf);
  memcpy_ck803s(auStack_40,&p_vfo_display_state->field_0x10,0x23);
  commit_channel_record_dual_vfo(uVar4,uVar1,uVar2,uVar3);
  os_sem_post(p_ucos_mutex_0003e330);
  return;
}

