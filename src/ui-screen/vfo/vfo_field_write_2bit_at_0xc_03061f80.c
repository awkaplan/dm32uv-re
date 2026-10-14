/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_2bit_at_0xc @ 03061f80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_field_write_2bit_at_0xc(uint param_1)

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
  
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  p_vfo_display_state->field_0xc =
       p_vfo_display_state->field_0xc & 0xf3 | (byte)((param_1 & 3) << 2);
  iVar5 = is_memory_channel_not_vfo();
  if (iVar5 == 1) {
    uStack_20 = 1;
    uVar1 = *(undefined4 *)p_vfo_display_state;
    uVar2 = *(undefined4 *)&p_vfo_display_state->field_0x4_0;
    SUBPIECE_SET(uVar3, 0, 1, p_vfo_display_state->flags_0x8);
    SUBPIECE_SET(uVar3, 1, 1, p_vfo_display_state->flags_0x9);
    SUBPIECE_SET(uVar3, 2, 1, p_vfo_display_state->field_0xa);
    SUBPIECE_SET(uVar3, 3, 1, p_vfo_display_state->field_0xb);
    SUBPIECE_SET(uVar4, 0, 1, p_vfo_display_state->field_0xc);
    SUBPIECE_SET(uVar4, 1, 1, p_vfo_display_state->flags_0xd);
    SUBPIECE_SET(uVar4, 2, 1, p_vfo_display_state->field_0xe);
    SUBPIECE_SET(uVar4, 3, 1, p_vfo_display_state->field_0xf);
    memcpy_ck803s(auStack_44,&p_vfo_display_state->field_0x10,0x23);
    commit_channel_record_dual_vfo(uVar1,uVar2,uVar3,uVar4);
  }
  else {
    vfo_record_offset_select3(local_18,&local_1a);
    flash_field_read_cached(local_18[0],local_1a + 0xc,&local_15,1);
    local_15 = local_15 & 0xf3 | (byte)((param_1 & 3) << 2);
    flash_field_write_cached(local_18[0],local_1a + 0xc);
  }
  os_sem_post(p_ucos_mutex_0003e330);
  return;
}

