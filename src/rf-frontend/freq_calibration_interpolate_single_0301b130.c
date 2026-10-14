/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: freq_calibration_interpolate_single @ 0301b130 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined1 freq_calibration_interpolate_single(uint param_1)

{
  radio_mode_state_0003e318 *prVar1;
  undefined1 uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  undefined1 local_20;
  undefined1 uStack_1f;
  
  prVar1 = p_radio_mode_state_0003e318;
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x10) == 0) {
    uVar8 = PTR_DAT_0301b1e8[6];
    uVar6 = PTR_DAT_0301b1e8[7];
    sVar7 = 0x33c;
  }
  else {
    uVar8 = PTR_DAT_0301b1e8[4];
    uVar6 = PTR_DAT_0301b1e8[5];
    sVar7 = 0x314;
  }
  if ((uVar8 <= param_1) && (uVar8 = uVar6, param_1 < uVar6)) {
    uVar8 = param_1;
  }
  sVar3 = frequency_to_step_index_resolve(uVar8,p_radio_mode_state_0003e318->flags_0x3 >> 4 & 1,1);
  flash_field_read_cached(2,sVar7 + sVar3 * 4,&local_20,4);
  uVar4 = bcd_frequency_decode(&local_20,4);
  flash_field_read_cached(2,sVar7 + (sVar3 + 1) * 4,&local_20,4);
  uVar5 = bcd_frequency_decode(&local_20,4);
  if ((prVar1->flags_0x3 & 0x10) == 0) {
    flash_field_read_cached(2,sVar3 + 0xa6,&local_20,2);
  }
  else {
    flash_field_read_cached(2,sVar3 + 0x17,&local_20,2);
  }
  uVar2 = linear_interpolate_freq_calibration(uVar8,uVar4,local_20,uVar5,uStack_1f);
  return uVar2;
}

