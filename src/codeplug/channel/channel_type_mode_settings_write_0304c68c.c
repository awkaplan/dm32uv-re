/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_type_mode_settings_write @ 0304c68c (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_type_mode_settings_write
               (undefined4 param_1,undefined4 param_2,byte param_3,uint param_4)

{
  byte bStack_3;
  
  if ((p_radio_mode_state_0003e318->flags_0x3 & 2) != 0) {
    bStack_3 = (byte)(param_4 >> 8);
    if ((bStack_3 >> 4 & 1) == 0) {
      p_dm32_settings_block04->field_0x3d = 0;
    }
    else {
      p_dm32_settings_block04->field_0x3d = 1;
    }
    if ((char)bStack_3 < '\0') {
      p_dm32_settings_block04->field_0x53 = 1;
    }
    else {
      p_dm32_settings_block04->field_0x53 = 0;
    }
    if ((param_4 & 0x4000) == 0) {
      p_dm32_settings_block04->field_0x54 = 0;
    }
    else {
      p_dm32_settings_block04->field_0x54 = 1;
    }
  }
  if ((param_3 & 6) == 0) {
    p_dm32_settings_block04->field_0x38 = 0;
  }
  else if ((param_3 & 6) == 2) {
    p_dm32_settings_block04->field_0x38 = 1;
  }
  else {
    p_dm32_settings_block04->field_0x38 = 2;
  }
  return;
}

