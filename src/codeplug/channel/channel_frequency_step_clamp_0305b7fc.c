/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_frequency_step_clamp @ 0305b7fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 222 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint channel_frequency_step_clamp(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  cVar1 = value_at_or_above_low_bound_check();
  iVar2 = get_current_mode_state1();
  if (iVar2 == 0) {
    if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
      uVar6 = PTR_DAT_0305b908[2];
      uVar4 = PTR_DAT_0305b908[3];
    }
    else {
      uVar6 = *PTR_DAT_0305b908;
      uVar4 = PTR_DAT_0305b908[1];
    }
  }
  else if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
    uVar6 = *PTR_DAT_0305b900;
    uVar4 = *PTR_DAT_0305b904;
  }
  else {
    uVar6 = *PTR_DAT_0305b8f8;
    uVar4 = *PTR_DAT_0305b8fc;
  }
  if (cVar1 == '\x01') {
    uVar6 = PTR_DAT_0305b908[8];
    uVar4 = PTR_DAT_0305b908[9];
  }
  uVar7 = uVar6;
  if ((uVar6 <= param_1) && (uVar7 = param_1, uVar4 < param_1)) {
    uVar7 = uVar6;
  }
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    p_dm32_settings_block04[0x2f] = (byte)PTR_DAT_0305b910[0x19] >> 4;
  }
  else {
    p_dm32_settings_block04[0x2f] = (byte)PTR_DAT_0305b914[0x19] >> 4;
  }
  if (7 < (byte)p_dm32_settings_block04[0x2f]) {
    p_dm32_settings_block04[0x2f] = 0;
  }
  uVar5 = (uint)(ushort)PTR_DAT_0305b918[(byte)p_dm32_settings_block04[0x2f]];
  if (cVar1 == '\x01') {
    uVar5 = 0x341;
  }
  if (param_2 == 0) {
    uVar3 = uVar7 - uVar5;
    if (uVar7 - uVar5 < uVar6) {
      uVar3 = uVar4 - uVar5;
    }
  }
  else {
    uVar3 = uVar5 + uVar7;
    if (uVar4 <= uVar5 + uVar7) {
      uVar3 = uVar6;
    }
  }
  return uVar3;
}

