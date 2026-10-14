/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_step_frequency_bound_check @ 0301b214 (file base 0x03000000; code starts at 0x03001000)
 * Size: 518 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char channel_step_frequency_bound_check(uint param_1,uint param_2,int param_3)

{
  radio_mode_state_0003e318 *prVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  byte local_28;
  byte bStack_27;
  byte local_26;
  byte bStack_25;
  
  prVar1 = p_radio_mode_state_0003e318;
  param_2 = param_2 & 0xff;
  if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) == 0) {
    if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
      uVar5 = PTR_DAT_0301b3c8[6];
      uVar4 = PTR_DAT_0301b3c8[7];
      sVar6 = 0x328;
    }
    else {
      uVar5 = PTR_DAT_0301b3c8[4];
      uVar4 = PTR_DAT_0301b3c8[5];
      sVar6 = 0x300;
    }
    if ((uVar5 <= param_1) && (uVar5 = uVar4, param_1 < uVar4)) {
      uVar5 = param_1;
    }
    sVar3 = frequency_to_step_index_resolve(uVar5,p_radio_mode_state_0003e318->flags_0x3 >> 3 & 1,0)
    ;
    flash_field_read_cached(2,sVar6 + sVar3 * 4,&local_28,4);
    iVar8 = bcd_frequency_decode(&local_28,4);
    flash_field_read_cached(2,sVar6 + (sVar3 + 1) * 4,&local_28,4);
    iVar10 = bcd_frequency_decode(&local_28,4);
    if ((prVar1->flags_0x3 & 8) == 0) {
      if (param_3 == 0) {
        flash_field_read_cached(2,sVar3 + 0xef,&local_28,2);
        flash_field_read_cached(2,sVar3 + 0xea,&local_26,2);
      }
      else {
        flash_field_read_cached(2,sVar3 + 0xe5,&local_28,2);
        flash_field_read_cached(2,sVar3 + 0xe0,&local_26,2);
      }
    }
    else if (param_3 == 0) {
      flash_field_read_cached(2,sVar3 + 0x73,&local_28,2);
      flash_field_read_cached(2,sVar3 + 0x6e,&local_26,2);
    }
    else {
      flash_field_read_cached(2,sVar3 + 0x69,&local_28,2);
      flash_field_read_cached(2,sVar3 + 100,&local_26,2);
    }
  }
  else {
    uVar4 = PTR_DAT_0301b3c8[8];
    uVar9 = PTR_DAT_0301b3c8[9];
    uVar5 = uVar4;
    if ((uVar4 <= param_1) && (uVar5 = param_1, uVar9 < param_1)) {
      uVar5 = uVar9;
    }
    uVar9 = uVar9 - uVar4 >> 2;
    if (uVar9 == 0) {
      uVar9 = 1;
    }
    uVar7 = (uVar5 - uVar4) / uVar9 & 0xff;
    iVar8 = uVar7 * uVar9 + uVar4;
    iVar10 = (uVar7 + 1) * uVar9 + iVar8;
    flash_field_read_cached(2,uVar7 + 0x85,&local_28,2);
    flash_field_read_cached(2,uVar7 + 0x80,&local_26,2);
  }
  if (param_2 == 1) {
    uVar4 = (uint)local_28;
    uVar9 = (uint)bStack_27;
  }
  else if (param_2 == 9) {
    uVar4 = (uint)local_26;
    uVar9 = (uint)bStack_25;
  }
  else {
    uVar4 = param_2 * ((uint)local_26 - (uint)local_28);
    if ((uVar4 & 0x80000000) != 0) {
      uVar4 = uVar4 + 7;
    }
    uVar4 = (uint)local_28 + ((int)uVar4 >> 3) & 0xff;
    param_2 = ((uint)bStack_25 - (uint)bStack_27) * param_2;
    if ((param_2 & 0x80000000) != 0) {
      param_2 = param_2 + 7;
    }
    uVar9 = (uint)bStack_27 + ((int)param_2 >> 3) & 0xff;
  }
  cVar2 = linear_interpolate_freq_calibration(uVar5,iVar8,uVar4,iVar10,uVar9);
  if (cVar2 == '\0') {
    cVar2 = '\x01';
  }
  return cVar2;
}

