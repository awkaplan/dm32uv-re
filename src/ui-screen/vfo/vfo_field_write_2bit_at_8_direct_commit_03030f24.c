/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_2bit_at_8_direct_commit @ 03030f24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_field_write_2bit_at_8_direct_commit(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short local_1a;
  undefined1 local_18 [3];
  byte local_15;
  
  iVar1 = is_memory_channel_not_vfo();
  if (iVar1 == 1) {
    SUBPIECE_SET(uVar2, 0, 1, p_vfo_display_state->flags_0x8);
    SUBPIECE_SET(uVar2, 1, 1, p_vfo_display_state->flags_0x9);
    SUBPIECE_SET(uVar2, 2, 1, p_vfo_display_state->field_0xa);
    SUBPIECE_SET(uVar2, 3, 1, p_vfo_display_state->field_0xb);
    SUBPIECE_SET(uVar3, 0, 1, p_vfo_display_state->field_0xc);
    SUBPIECE_SET(uVar3, 1, 1, p_vfo_display_state->flags_0xd);
    SUBPIECE_SET(uVar3, 2, 1, p_vfo_display_state->field_0xe);
    SUBPIECE_SET(uVar3, 3, 1, p_vfo_display_state->field_0xf);
    commit_channel_record_dual_vfo
              (*(undefined4 *)p_vfo_display_state,*(undefined4 *)&p_vfo_display_state->field_0x4_0,
               uVar2,uVar3,*(undefined4 *)&p_vfo_display_state->field_0x10,
               *(undefined4 *)&p_vfo_display_state->field_0x14,
               *(undefined4 *)&p_vfo_display_state->field_0x18,
               *(undefined4 *)&p_vfo_display_state->field_0x1c,
               *(undefined4 *)&p_vfo_display_state->field_0x20,
               *(undefined4 *)&p_vfo_display_state->field_0x24,
               *(undefined4 *)&p_vfo_display_state->field_0x28,
               *(undefined4 *)&p_vfo_display_state->field_0x2c,
               *(undefined2 *)&p_vfo_display_state->field_0x30,1);
  }
  else {
    vfo_record_offset_select3(local_18,&local_1a);
    flash_field_read_cached(local_18[0],local_1a + 8,&local_15,1);
    local_15 = local_15 & 0xf9 | param_1 * '\x02';
    flash_field_write_cached(local_18[0],local_1a + 8);
  }
  return;
}

