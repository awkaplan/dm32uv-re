/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_compand_config_apply @ 03063cf4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 338 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 dtmf_compand_config_apply(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined2 local_38;
  undefined2 local_36;
  byte local_34 [16];
  
  dtmf_code_flash_read(2,param_1,0x10,local_34);
  if (local_34[0] < 0x11) {
    bVar3 = *(byte *)((int)PTR_DAT_03063e48 + 2);
    iVar8 = (uint)*(byte *)((int)PTR_DAT_03063e48 + 3) * 10 + 0x50;
    bVar1 = *(byte *)PTR_DAT_03063e48;
    bVar2 = *(byte *)((int)PTR_DAT_03063e48 + 1);
    config_table_init_entries_0x21_0x24();
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe0e0);
    fd6818b_reg50_write_bb18();
    fd6818b_reg47_write_byte_or_6042(3);
    config_table_init_group1();
    mmio_14000000_timer_config(1);
    wait_for_status_byte_clear((uint)bVar1 * 0x14);
    *(undefined1 *)((int)PTR_DAT_03063e50 + 1) = 2;
    iVar5 = p_dm32_settings_block04;
    puVar4 = PTR_DAT_03063e50;
    if ((local_34[0] < 0x11) && ((*(byte *)PTR_DAT_03063e50 & 1) == 0)) {
      uVar7 = 1;
      do {
        compand_table_nibble_split_lookup(local_34[0],&local_36,&local_38);
        if (*(char *)(iVar5 + 0x41) == '\0') {
          if ((*(byte *)((int)PTR_DAT_03063e48 + 5) & 1) != 0) {
            audio_pa_enable_gate(1);
          }
        }
        config_entry_0x71_0x72_and_gain_apply(local_36,local_38,(uint)bVar3 * 10 + 0x50);
        if (uVar7 == 1) {
          wait_for_status_byte_clear((uint)bVar2 * 0x32 + 100);
          audio_pa_enable_gate(0);
          fd6818b_reg50_write_bb18();
          wait_for_status_byte_clear(iVar8);
        }
        else {
          audio_pa_enable_gate(0);
          fd6818b_reg50_write_bb18();
          wait_for_status_byte_clear(iVar8);
          if (0xf < uVar7) break;
        }
        local_34[0] = local_34[uVar7];
        if (0x10 < local_34[0]) break;
        uVar7 = uVar7 + 1 & 0xff;
      } while ((*(byte *)puVar4 & 1) == 0);
    }
    audio_pa_enable_gate(0);
    config_table_entry_0x30();
    fd6818b_reg47_write_byte_or_6042(0);
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
    config_table_entry_0x24();
    puVar4 = PTR_DAT_03063e50;
    *(byte *)PTR_DAT_03063e50 = *(byte *)PTR_DAT_03063e50 & 0xfe;
    *(undefined1 *)((int)puVar4 + 1) = 0;
    timer_ch1_disable();
    fd6818b_init_seq_filter_ctcss_chipmode();
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

