/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_tone_playback_from_i2c_stored_code @ 03064acc (file base 0x03000000; code starts at 0x03001000)
 * Size: 466 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 dtmf_tone_playback_from_i2c_stored_code(uint param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  char cVar7;
  byte local_64 [5];
  char acStack_5f [11];
  byte local_54;
  undefined1 auStack_53 [5];
  char cStack_4e;
  byte bStack_4d;
  byte bStack_4c;
  byte bStack_44;
  byte local_43 [31];
  
  flash_field_read_cached(3,((param_1 & 0xff) - 1) * 0x30 + 0x820 & 0xfff0,&local_54);
  if (local_54 < 2) {
    if (local_54 == 0) {
      memcpy_bytes_iram(local_64,auStack_53,5);
      if ((byte)(cStack_4e - 1U) < 0xf) {
        acStack_5f[0] = cStack_4e;
        iVar3 = 6;
      }
      else {
        iVar3 = 5;
      }
      pbVar4 = local_64 + iVar3;
      pbVar6 = (byte *)PTR_DAT_03064c90;
      do {
        *pbVar4 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        pbVar4 = pbVar4 + 1;
      } while (pbVar6 != (byte *)((int)PTR_DAT_03064c90 + 5));
      acStack_5f[iVar3] = -1;
    }
    else {
      if (bStack_44 < 0x10) {
        pbVar4 = local_43;
        pbVar6 = local_64;
        uVar5 = 1;
        do {
          pbVar6 = pbVar6 + 1;
          local_64[0] = bStack_44;
          if (0xf < *pbVar4) break;
          *pbVar6 = *pbVar4;
          uVar5 = uVar5 + 1 & 0xff;
          pbVar4 = pbVar4 + 1;
        } while (uVar5 != 0x10);
      }
      else {
        uVar5 = 0;
      }
      local_64[uVar5] = 0xff;
    }
    if (local_64[0] == 0xff) {
      uVar2 = 1;
    }
    else {
      config_table_init_entries_0300f2cc();
      fd6818b_reg47_write_byte_or_6042(3);
      fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe000);
      fd6818b_reg50_write_bb18();
      config_table_init_group1();
      mmio_14000000_timer_config(1);
      wait_for_status_byte_clear((uint)*(byte *)((int)PTR_DAT_03064c90 + 7) * 0x14);
      if ((p_dm32_settings_block04[0x41] == '\0') && ((*(byte *)(PTR_DAT_03064c90 + 3) & 1) != 0)) {
        audio_pa_enable_gate(1);
      }
      puVar1 = PTR_LAB_03064c98;
      uVar5 = (uint)local_64[0];
      if (uVar5 < 0x10) {
        pbVar6 = local_64;
        cVar7 = '\0';
        do {
          pbVar6 = pbVar6 + 1;
          soft_double_from_int((int)*(short *)(puVar1 + ((uint)bStack_4d * 0x10 + uVar5) * 2));
          soft_double_multiply();
          soft_double_add();
          uVar5 = soft_double_to_int();
          fd6818b_reg_write(FD6818_PAGE0_REG_71H,(short)(uVar5 / 10));
          if (cVar7 == '\0') {
            fd6818b_reg50_write_3b18();
          }
          wait_for_status_byte_clear((uint)bStack_4c * 10);
          cVar7 = cVar7 + '\x01';
          uVar5 = (uint)*pbVar6;
        } while ((uVar5 < 0x10) && (cVar7 != '\x10'));
      }
      if ((p_dm32_settings_block04[0x41] == '\0') && ((*(byte *)(PTR_DAT_03064c90 + 3) & 1) != 0)) {
        audio_pa_enable_gate(0);
      }
      config_table_entry_0x30();
      fd6818b_reg47_write_byte_or_6042(0);
      fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
      config_table_entry_0300f2e4();
      timer_ch1_disable();
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

