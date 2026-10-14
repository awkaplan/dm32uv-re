/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_field_write_6bit_at_9 @ 0302f5e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 218 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_field_write_6bit_at_9(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_44 [36];
  undefined4 uStack_20;
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  uVar4 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
  p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0xc0 | param_1 & 0x3f;
  iVar5 = is_memory_channel_not_vfo();
  if (iVar5 == 1) {
    uStack_20 = 1;
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
    memcpy_ck803s(auStack_44,&p_vfo_display_state->field_0x10,0x23);
    commit_channel_record_dual_vfo(uVar4,uVar1,uVar2,uVar3);
  }
  else {
    channel_num_to_block_offset(uVar4,local_18,&local_1a);
    flash_field_read_cached(local_18[0],local_1a + 9,&local_15,1);
    local_15 = param_1 & 0x3f | local_15 & 0xc0;
    flash_field_write_cached(local_18[0],local_1a + 9);
  }
  return;
}

