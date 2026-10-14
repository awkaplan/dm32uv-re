/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_bit4_at_0x15 @ 0301be6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 278 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_field_write_bit4_at_0x15(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 auStack_44 [36];
  undefined4 uStack_20;
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  vfo_record_offset_select3(local_18,&local_1a);
  flash_field_read_cached(local_18[0],local_1a + 0x15,&local_15,1);
  if (param_1 == 0) {
    local_15 = local_15 & 0xef;
    p_dm32_settings_block04[0x30] = p_dm32_settings_block04[0x30] & 0xfe;
  }
  else {
    local_15 = local_15 | 0x10;
    PTR_DAT_0301bf84[6] = 0;
    p_dm32_settings_block04[0x30] = p_dm32_settings_block04[0x30] & 0xfe | 1;
  }
  bVar1 = p_dm32_settings_block04[0x30];
  PTR_DAT_0301bf8c[2] = PTR_DAT_0301bf8c[2] & 0xbf | (byte)((bVar1 & 1) << 6);
  p_vfo_display_state->field_0x15 =
       p_vfo_display_state->field_0x15 & 0xef | (byte)((bVar1 & 1) << 4);
  iVar6 = is_memory_channel_not_vfo();
  if (iVar6 == 1) {
    uStack_20 = 1;
    uVar2 = *(undefined4 *)p_vfo_display_state;
    uVar3 = *(undefined4 *)&p_vfo_display_state->field_0x4_0;
    SUBPIECE_SET(uVar4, 0, 1, p_vfo_display_state->flags_0x8);
    SUBPIECE_SET(uVar4, 1, 1, p_vfo_display_state->flags_0x9);
    SUBPIECE_SET(uVar4, 2, 1, p_vfo_display_state->field_0xa);
    SUBPIECE_SET(uVar4, 3, 1, p_vfo_display_state->field_0xb);
    SUBPIECE_SET(uVar5, 0, 1, p_vfo_display_state->field_0xc);
    SUBPIECE_SET(uVar5, 1, 1, p_vfo_display_state->flags_0xd);
    SUBPIECE_SET(uVar5, 2, 1, p_vfo_display_state->field_0xe);
    SUBPIECE_SET(uVar5, 3, 1, p_vfo_display_state->field_0xf);
    memcpy_ck803s(auStack_44,&p_vfo_display_state->field_0x10,0x23);
    commit_channel_record_dual_vfo(uVar2,uVar3,uVar4,uVar5);
  }
  else {
    flash_field_write_cached(local_18[0],local_1a + 0x15,local_15);
  }
  return;
}

