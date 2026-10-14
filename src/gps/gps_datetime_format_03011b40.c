/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_datetime_format @ 03011b40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 466 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_datetime_format(char param_1,char *param_2,byte *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  uint unaff_r11;
  uint uStack_30;
  uint uStack_2c;
  byte local_26;
  byte local_25;
  
  uVar4 = ((uint)*param_3 * 10 + (uint)param_3[1]) - 0x10 & 0xff;
  bVar5 = (param_3[3] - 0x10) + param_3[2] * '\n';
  cVar6 = (param_3[5] - 0x10) + param_3[4] * '\n';
  gps_coordinate_table_entry_parse(PTR_DAT_03011d14[0xb6],&local_25,&local_26);
  if ((char)local_25 < '\0') {
    if (bVar5 < local_26) {
      bVar5 = (bVar5 - local_26) + 0x3c;
      uVar4 = uVar4 - 1 & 0xff;
    }
    else {
      bVar5 = bVar5 - local_26;
    }
    uVar1 = -(uint)local_25;
    uVar3 = uVar1 & 0xff;
    local_25 = (byte)uVar1;
    if ((int)uVar4 < (int)(char)local_25) {
      uVar4 = (uVar4 - uVar3) + 0x18 & 0xff;
      iVar2 = 2;
    }
    else {
      uVar4 = uVar4 - uVar3 & 0xff;
      iVar2 = 0;
    }
  }
  else {
    uVar4 = uVar4 + local_25 & 0xff;
    bVar5 = bVar5 + local_26;
    if (0x3b < bVar5) {
      uVar4 = uVar4 + 1 & 0xff;
      bVar5 = bVar5 - 0x3c;
    }
    if (uVar4 < 0x18) {
      iVar2 = 0;
    }
    else {
      uVar4 = uVar4 - 0x18 & 0xff;
      iVar2 = 1;
    }
  }
  if ((byte)(param_1 - 1U) < 2) {
    uStack_2c = (uint)(byte)param_2[4] * 10 + ((byte)param_2[5] - 0x10) & 0xff;
    uStack_30 = (uint)(byte)param_2[2] * 10 + ((byte)param_2[3] - 0x10) & 0xff;
    bVar7 = (*param_2 * '\n' + param_2[1]) - 0x10;
    unaff_r11 = (uint)bVar7;
    if (uStack_30 < 8) {
      bVar7 = (bVar7 & 1) != 0;
    }
    else {
      bVar7 = ~((bVar7 & 1) != 0);
    }
    if (iVar2 == 1) {
      unaff_r11 = unaff_r11 + 1 & 0xff;
      if (bVar7 == 0) {
        if (0x1e < unaff_r11) {
          uStack_30 = uStack_30 + 1 & 0xff;
          unaff_r11 = 1;
        }
      }
      else if (0x1f < unaff_r11) {
        uStack_30 = uStack_30 + 1 & 0xff;
        unaff_r11 = 1;
      }
    }
    else if (iVar2 == 2) {
      if (unaff_r11 == 1) {
        if (bVar7 == 0) {
          unaff_r11 = 0x1f;
        }
        else if (uStack_30 == 8) {
          unaff_r11 = 0x1f;
        }
        else {
          unaff_r11 = 0x1e;
        }
        uStack_30 = uStack_30 - 1 & 0xff;
      }
      else {
        unaff_r11 = unaff_r11 - 1 & 0xff;
      }
    }
  }
  if (param_1 == '\0') {
    number_to_string_format_2args(param_4,PTR_s__02d__02d__02d_03011d18,uVar4,bVar5,cVar6);
  }
  else if (param_1 == '\x01') {
    number_to_string_format_2args
              (param_4,PTR_s_20_02d__02d__02d_03011d1c,uStack_2c,uStack_30,unaff_r11);
  }
  else {
    number_to_string_format_2args
              (param_4,PTR_s_20_02d__02d__02d__02d__02d__02d_03011d20,uStack_2c,uStack_30,unaff_r11,
               uVar4,bVar5,cVar6);
  }
  return;
}

