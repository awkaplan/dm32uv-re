/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_scan_add_toggle @ 03056324 (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_scan_add_toggle(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  short local_1a;
  undefined2 local_18;
  byte local_15;
  
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  uVar3 = param_1 & 1;
  p_vfo_display_state->field_0xa = p_vfo_display_state->field_0xa & 0xf7 | (byte)(uVar3 << 3);
  iVar1 = is_memory_channel_not_vfo();
  if (iVar1 == 0) {
    if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
        local_1a = 0xfaf;
      }
      else {
        local_1a = 0xfdf;
      }
      local_18 = 0x41;
    }
    else {
      uVar2 = channel_list_index_resolve
                        (p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
      channel_num_to_block_offset(uVar2,&local_18,&local_1a);
    }
    flash_field_read_cached((undefined1)local_18,local_1a + 10,&local_15,1);
    local_15 = local_15 & 0xf7 | (byte)((param_1 & 1) << 3);
    flash_field_write_cached((undefined1)local_18,local_1a + 10);
  }
  else {
    iVar1 = get_current_mode_state2();
    if (iVar1 == 0) {
      if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
        PTR_DAT_0305643c[10] = PTR_DAT_0305643c[10] & 0xf7 | (byte)(uVar3 << 3);
      }
      else {
        PTR_DAT_03056440[10] = PTR_DAT_03056440[10] & 0xf7 | (byte)(uVar3 << 3);
      }
    }
    else if ((PTR_DAT_03056438[1] & 1) == 0) {
      PTR_DAT_0305643c[10] = PTR_DAT_0305643c[10] & 0xf7 | (byte)(uVar3 << 3);
    }
    else {
      PTR_DAT_03056440[10] = PTR_DAT_03056440[10] & 0xf7 | (byte)(uVar3 << 3);
    }
  }
  os_sem_post(p_ucos_mutex_0003e330);
  return;
}

