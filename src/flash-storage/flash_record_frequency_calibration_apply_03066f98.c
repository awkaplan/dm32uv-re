/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_frequency_calibration_apply @ 03066f98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 396 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_record_frequency_calibration_apply(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  byte local_10 [2];
  short sStack_e;
  undefined2 uStack_c;
  
  flash_field_read_cached(3,((param_1 & 0xff) - 1) * 0x28 + 0x240 & 0xfff8,local_10,8);
  if (sStack_e == -1) {
    uVar3 = 0;
  }
  else {
    config_table_init_entries_0300f2cc();
    fd6818b_reg47_write_byte_or_6042(3);
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe000);
    fd6818b_reg50_write_bb18();
    config_table_init_group1();
    mmio_14000000_timer_config(1);
    wait_for_status_byte_clear((uint)*(byte *)PTR_DAT_03067144 * 100);
    if ((p_dm32_settings_block04[0x41] == '\0') && ((*(byte *)((int)PTR_DAT_03067144 + 6) & 1) != 0)
       ) {
      audio_pa_enable_gate(1);
    }
    soft_double_pack_constant_two(sStack_e);
    soft_double_multiply();
    soft_double_add();
    uVar2 = soft_double_to_int();
    fd6818b_reg_write(FD6818_PAGE0_REG_71H,(short)(uVar2 / 10));
    fd6818b_reg50_write_3b18();
    puVar1 = PTR_DAT_03067144;
    if ((local_10[0] & 1) == 0) {
      wait_for_status_byte_clear((uint)*(byte *)((int)PTR_DAT_03067144 + 1) * 100);
      if (*(char *)(puVar1 + 1) != '\0') {
        fd6818b_reg50_write_bb18();
        wait_for_status_byte_clear((uint)*(byte *)(puVar1 + 1) * 100);
      }
      soft_double_pack_constant_two(uStack_c);
      soft_double_multiply();
      soft_double_add();
      uVar2 = soft_double_to_int();
      fd6818b_reg_write(FD6818_PAGE0_REG_71H,(short)(uVar2 / 10));
      fd6818b_reg50_write_3b18();
      wait_for_status_byte_clear((uint)*(byte *)((int)PTR_DAT_03067144 + 2) * 100);
    }
    else {
      wait_for_status_byte_clear((uint)*(byte *)((int)PTR_DAT_03067144 + 3) * 100);
    }
    if ((p_dm32_settings_block04[0x41] == '\0') && ((*(byte *)((int)PTR_DAT_03067144 + 6) & 1) != 0)
       ) {
      audio_pa_enable_gate(0);
    }
    config_table_entry_0x30();
    fd6818b_reg47_write_byte_or_6042(0);
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
    config_table_entry_0300f2e4();
    timer_ch1_disable();
    uVar3 = 1;
  }
  return uVar3;
}

