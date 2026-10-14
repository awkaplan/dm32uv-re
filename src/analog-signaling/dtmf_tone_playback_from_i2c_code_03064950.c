/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_tone_playback_from_i2c_code @ 03064950 (file base 0x03000000; code starts at 0x03001000)
 * Size: 354 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_tone_playback_from_i2c_code(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  byte *pbVar3;
  byte local_38;
  byte local_37 [19];
  
  param_1 = param_1 & 1;
  if (param_1 == 0) {
    flash_field_read_cached(3,0x7f0,&local_38,0x12);
    *(byte *)PTR_DAT_03064ab4 = *(byte *)PTR_DAT_03064ab4 & 0xef | 0x10;
  }
  else {
    flash_field_read_cached(3,2000,&local_38,0x12);
  }
  if (8 < local_37[0xf]) {
    local_37[0xf] = 0;
  }
  config_table_init_entries_0300f2cc();
  fd6818b_reg47_write_byte_or_6042(3);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe000);
  fd6818b_reg50_write_bb18();
  config_table_init_group1();
  mmio_14000000_timer_config(1);
  if (param_1 != 0) {
    wait_for_status_byte_clear((uint)(byte)PTR_DAT_03064ab8[7] * 0x14);
  }
  if ((p_dm32_settings_block04[0x41] == '\0') && ((PTR_DAT_03064ab8[0xc] & 1) != 0)) {
    audio_pa_enable_gate(1);
  }
  puVar1 = PTR_LAB_03064ac0;
  uVar2 = (uint)local_38;
  if (uVar2 < 0x10) {
    pbVar3 = local_37;
    do {
      soft_double_from_int((int)*(short *)(puVar1 + ((uint)local_37[0xf] * 0x10 + uVar2) * 2));
      soft_double_multiply();
      soft_double_add();
      uVar2 = soft_double_to_int();
      fd6818b_reg_write(FD6818_PAGE0_REG_71H,(short)(uVar2 / 10));
      fd6818b_reg50_write_3b18();
      wait_for_status_byte_clear((uint)local_37[0x10] * 10);
      uVar2 = (uint)*pbVar3;
      if (0xf < uVar2) break;
      pbVar3 = pbVar3 + 1;
    } while (pbVar3 != local_37 + 0x10);
  }
  if ((p_dm32_settings_block04[0x41] == '\0') && ((PTR_DAT_03064ab8[0xc] & 1) != 0)) {
    audio_pa_enable_gate(0);
  }
  config_table_entry_0x30();
  fd6818b_reg47_write_byte_or_6042(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
  config_table_entry_0300f2e4();
  fd6818b_init_seq_filter_ctcss_chipmode();
  if (param_1 != 0) {
    fd6818b_reg50_tx_audio_unmute_set();
  }
  timer_ch1_disable();
  return;
}

