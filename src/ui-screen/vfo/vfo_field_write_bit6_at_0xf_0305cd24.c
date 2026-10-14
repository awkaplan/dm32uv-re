/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_field_write_bit6_at_0xf @ 0305cd24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 294 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 vfo_field_write_bit6_at_0xf(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  short local_1e;
  undefined1 local_1c [3];
  byte local_19;
  
  if (p_vfo_display_state->field_0xe == 0) {
    if (param_1 == '\0') {
      return 0;
    }
    vfo_record_offset_select3(local_1c,&local_1e);
    flash_field_read_cached(local_1c[0],local_1e + 0xf,&local_19,1);
  }
  else {
    vfo_record_offset_select3(local_1c,&local_1e);
    flash_field_read_cached(local_1c[0],local_1e + 0xf,&local_19,1);
    if (param_1 == '\0') {
      local_19 = local_19 | 0x40;
      p_vfo_display_state->field_0xf = p_vfo_display_state->field_0xf & 0xbf | 0x40;
      goto LAB_0305cd8a;
    }
  }
  local_19 = local_19 & 0xbf;
  p_vfo_display_state->field_0xf = p_vfo_display_state->field_0xf & 0xbf;
LAB_0305cd8a:
  iVar5 = is_memory_channel_not_vfo();
  if (iVar5 == 1) {
    uStack_24 = 1;
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
    memcpy_ck803s(auStack_48,&p_vfo_display_state->field_0x10,0x23);
    commit_channel_record_dual_vfo(uVar1,uVar2,uVar3,uVar4);
  }
  else {
    flash_field_write_cached(local_1c[0],local_1e + 0xf,local_19);
  }
  return 1;
}

