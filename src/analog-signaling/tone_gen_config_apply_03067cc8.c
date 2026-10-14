/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_gen_config_apply @ 03067cc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 574 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_gen_config_apply(uint param_1)

{
  undefined1 *puVar1;
  undefined2 value;
  ushort value_00;
  undefined2 value_01;
  short sVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 local_78 [42];
  
  uVar8 = param_1 & 0xffff;
  if (uVar8 == 0) {
    return;
  }
  if (uVar8 == 0x180) {
    OSTimeDly_ms_wrapper((uint)(byte)PTR_DAT_03067e54[4] * 0x14);
  }
  puVar1 = PTR_DAT_03067e54;
  uVar3 = tone_gen_command_frame_build_and_send
                    (local_78,uVar8 >> 8,param_1 & 0xff,*(undefined2 *)PTR_DAT_03067e54);
  fd6818b_reg_write(FD6818_PAGE0_REG_50H,0x3b20);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0xc3fa);
  if (((puVar1[5] & 1) == 0) || (p_dm32_settings_block04[0x41] != '\0')) {
    fd6818b_reg47_write_byte_or_6042(0);
  }
  else {
    fd6818b_reg47_write_byte_or_6042(3);
    audio_pa_enable_gate(1);
    fd6818b_reg48_cic_mode_write(1);
  }
  value = fd6818_reg_read(FD6818_PAGE0_REG_51H);
  fd6818b_reg_write(FD6818_PAGE0_REG_51H,0);
  value_00 = fd6818_reg_read(FD6818_PAGE0_REG_40H);
  if ((p_vfo_display_state->flags_0x9 & 0x80) == 0) {
    uVar4 = 0x352;
  }
  else {
    uVar4 = 0x41a;
  }
  fd6818b_reg_write(FD6818_PAGE0_REG_40H,uVar4 | value_00 & 0xf000);
  value_01 = fd6818_reg_read(FD6818_PAGE0_REG_0X2B);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X2B,5);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X58,0x3c03);
  fd6818b_reg_write(FD6818_PAGE0_REG_72H,0x3065);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe0);
  fd6818b_reg_write(FD6818_PAGE0_REG_5DH,((short)uVar3 + -1) * 0x100);
  fd6818b_reg_write(FD6818_PAGE0_REG_5AH,0);
  fd6818b_reg_write(FD6818_PAGE0_REG_5BH,0);
  fd6818b_reg_write(FD6818_PAGE0_REG_5CH,0x5625);
  fd6818b_reg_write(FD6818_PAGE0_REG_59H,0xc0f8);
  fd6818b_reg_write(FD6818_PAGE0_REG_59H,0xf8);
  if (uVar3 >> 1 != 0) {
    puVar7 = local_78;
    uVar5 = 0;
    do {
      fd6818b_reg_write(FD6818_PAGE0_REG_5FH,*puVar7);
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar5 < uVar3 >> 1);
  }
  fd6818b_reg_write(FD6818_PAGE0_REG_3FH,0x8000);
  fd6818b_reg_write(FD6818_PAGE0_REG_59H,0x8f8);
  iVar6 = 0x4a;
  do {
    OSTimeDly_ms_wrapper(4);
    uVar3 = fd6818_reg_read(FD6818_PAGE0_REG_0CH);
    if ((uVar3 & 1) != 0) {
      fd6818b_reg_write(FD6818_PAGE0_REG_02H,0);
      sVar2 = fd6818_reg_read(FD6818_PAGE0_REG_02H);
      if (sVar2 < 0) {
LAB_03067e60:
        fd6818b_reg_write(FD6818_PAGE0_REG_59H,0xf8);
        fd6818b_reg_write(FD6818_PAGE0_REG_3FH,0);
        fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
        fd6818b_reg_write(FD6818_PAGE0_REG_0X58,0);
        fd6818b_reg_write(FD6818_PAGE0_REG_40H,value_00);
        fd6818b_reg_write(FD6818_PAGE0_REG_0X2B,value_01);
        fd6818b_reg_write(FD6818_PAGE0_REG_51H,value);
        fd6818b_reg_write(FD6818_PAGE0_REG_50H,0xbb20);
        fd6818b_reg_write(FD6818_PAGE0_REG_47H,0x6040);
        if (((PTR_DAT_03068020[5] & 1) != 0) && (p_dm32_settings_block04[0x41] == '\0')) {
          audio_pa_enable_gate(0);
          fd6818b_reg48_cic_mode_write(*(undefined1 *)PTR_DAT_03068028);
          busy_wait_delay_n_units(10);
        }
        fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0xc1fe);
        fd6818b_reg_write(FD6818_PAGE0_REG_50H,0x3b20);
        if ((uVar8 == 0x100) && ((*(byte *)PTR_DAT_0306802c & 0x20) == 0)) {
          *(byte *)PTR_DAT_03068030 = *(byte *)PTR_DAT_03068030 & 0xef | 0x10;
        }
        *(undefined1 *)((int)PTR_DAT_0306802c + 1) = PTR_DAT_03068020[8];
        return;
      }
    }
    if (iVar6 == 0) goto LAB_03067e60;
    iVar6 = iVar6 + -1;
  } while( true );
}

