/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_change_key_handler @ 0302f464 (file base 0x03000000; code starts at 0x03001000)
 * Size: 356 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte zone_change_key_handler(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_44 [52];
  
  if (((param_1 == 0) && (iVar3 = get_current_mode_state1(), iVar3 == 2)) &&
     ((p_vfo_display_state->flags_0x9 & 0x3f) != 0)) {
    return 0;
  }
  dtmf_digit_input_handler(0);
  if (((p_dm32_settings_block04[0x2d] & 4) == 0) ||
     ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)) {
    vfo_zone_display_refresh();
  }
  else {
    if (0x1f < ((p_vfo_display_state->flags_0x9 & 0x3f) + 0x3f & 0x3f)) {
      bVar1 = 1;
      goto LAB_0302f5c2;
    }
    zone_record_read();
  }
  iVar3 = vfo_freq_display_field0x5c_in_range();
  if (((iVar3 == 0) && ((p_dm32_settings_block04[0x2d] & 4) != 0)) &&
     ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
    bVar1 = 1;
  }
  else {
    if (param_1 == 0) {
      if ((p_vfo_freq_display_state->flags_0x10 & 0x80) == 0) {
        bVar1 = 0;
        goto LAB_0302f5c2;
      }
    }
    else {
      p_vfo_freq_display_state->flags_0x10 = p_vfo_freq_display_state->flags_0x10 & 0x7f | 0x80;
    }
    if (((*(byte *)PTR_DAT_0302f778 & 8) == 0) || ((p_dm32_settings_block04[0x2d] & 0x80) != 0)) {
      if (((*(byte *)PTR_DAT_0302f778 & 0x10) != 0) && ((p_dm32_settings_block04[0x2d] & 0x80) != 0)
         ) {
        *(byte *)PTR_DAT_0302f5ac = *(byte *)PTR_DAT_0302f5ac & 0xef;
        puVar2 = PTR_DAT_0302f5b4;
        vfo_record_read(auStack_44,1);
        memcpy_ck803s(puVar2,auStack_44,0x33);
        memcpy_ck803s(p_vfo_display_state,puVar2,0x33);
      }
    }
    else {
      *(byte *)PTR_DAT_0302f5ac = *(byte *)PTR_DAT_0302f5ac & 0xf7;
      puVar2 = PTR_DAT_0302f5b0;
      vfo_record_read(auStack_44);
      memcpy_ck803s(puVar2,auStack_44,0x33);
      memcpy_ck803s(p_vfo_display_state,puVar2,0x33);
    }
    dtmf_digit_input_handler(1);
    PTR_DAT_0302f5b8[0xf] = 0;
    bVar1 = 0;
  }
LAB_0302f5c2:
  return ~bVar1;
}

