/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frequency_range_clamp_and_dispatch @ 0301b078 (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 frequency_range_clamp_and_dispatch(uint param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x10) == 0) {
    flash_field_read_cached(2,0xab,&local_1c,3);
    iVar6 = 0x33c;
  }
  else {
    flash_field_read_cached(2,0x1c,&local_1c,3);
    iVar6 = 0x314;
  }
  flash_field_read_cached(2,iVar6,auStack_20,4);
  uVar2 = bcd_frequency_decode(auStack_20,4);
  flash_field_read_cached(2,iVar6 + 8,auStack_20,4);
  uVar3 = bcd_frequency_decode(auStack_20,4);
  flash_field_read_cached(2,iVar6 + 0x10,auStack_20,4);
  uVar4 = bcd_frequency_decode(auStack_20,4);
  uVar5 = uVar2;
  if ((uVar2 <= param_1) && (uVar5 = uVar4, param_1 < uVar4)) {
    uVar5 = param_1;
  }
  if (uVar3 < uVar5) {
    uVar1 = linear_interpolate_freq_calibration(uVar5,uVar3,uStack_1b,uVar4,uStack_1a);
  }
  else {
    uVar1 = linear_interpolate_freq_calibration(uVar5,uVar2,local_1c,uVar3,uStack_1b);
  }
  return uVar1;
}

