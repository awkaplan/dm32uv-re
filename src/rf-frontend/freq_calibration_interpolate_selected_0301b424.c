/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: freq_calibration_interpolate_selected @ 0301b424 (file base 0x03000000; code starts at 0x03001000)
 * Size: 308 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 freq_calibration_interpolate_selected(uint param_1,char param_2)

{
  radio_mode_state_0003e318 *prVar1;
  undefined1 uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  undefined1 local_24;
  undefined1 uStack_23;
  
  prVar1 = p_radio_mode_state_0003e318;
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x10) == 0) {
    uVar8 = PTR_DAT_0301b5a0[6];
    uVar6 = PTR_DAT_0301b5a0[7];
    sVar7 = 0x33c;
  }
  else {
    uVar8 = PTR_DAT_0301b5a0[4];
    uVar6 = PTR_DAT_0301b5a0[5];
    sVar7 = 0x314;
  }
  if ((uVar8 <= param_1) && (uVar8 = uVar6, param_1 < uVar6)) {
    uVar8 = param_1;
  }
  sVar3 = frequency_to_step_index_resolve(uVar8,p_radio_mode_state_0003e318->flags_0x3 >> 4 & 1,1);
  flash_field_read_cached(2,sVar7 + sVar3 * 4,&local_24,4);
  uVar4 = bcd_frequency_decode(&local_24,4);
  flash_field_read_cached(2,sVar7 + (sVar3 + 1) * 4,&local_24,4);
  uVar5 = bcd_frequency_decode(&local_24,4);
  if ((prVar1->flags_0x3 & 0x10) == 0) {
    if (param_2 == '\0') {
      flash_field_read_cached(2,sVar3 + 0xd0,&local_24,2);
    }
    else if (param_2 == '\x01') {
      flash_field_read_cached(2,sVar3 + 0xd5,&local_24,2);
    }
    else {
      flash_field_read_cached(2,sVar3 + 0xda,&local_24,2);
    }
  }
  else if (param_2 == '\0') {
    flash_field_read_cached(2,sVar3 + 0x40,&local_24,2);
  }
  else if (param_2 == '\x01') {
    flash_field_read_cached(2,sVar3 + 0x45,&local_24,2);
  }
  else {
    flash_field_read_cached(2,sVar3 + 0x4a,&local_24,2);
  }
  uVar2 = linear_interpolate_freq_calibration(uVar8,uVar4,local_24,uVar5,uStack_23);
  return uVar2;
}

