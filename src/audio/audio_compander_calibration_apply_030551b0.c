/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: audio_compander_calibration_apply @ 030551b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 516 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: audio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void audio_compander_calibration_apply(uint param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  vfo_display_state *pvVar4;
  ushort uVar5;
  byte local_10;
  byte bStack_f;
  
  flash_field_read_cached(2,0x27,&local_10,2);
  (*(code *)(PTR_DAT_0305536c[4] & 0xfffffffe))((bStack_f & 3) << 8 | (uint)local_10);
  pvVar4 = p_vfo_display_state;
  bVar1 = *(byte *)PTR_DAT_03055370;
  if ((0x31 < bVar1) && (bVar1 != 0x51)) {
    if (0x4b < bVar1) {
      p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | 0x10;
      pvVar4->flags_0x9 = pvVar4->flags_0x9 & 0x7f;
      return;
    }
    p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0x7f | 0x80;
    pvVar4->flags_0x8 = pvVar4->flags_0x8 & 0xf;
    return;
  }
  flash_field_read_cached(2,0x16,&local_10,1);
  (*(code *)(PTR_DAT_0305536c[1] & 0xfffffffe))(local_10);
  if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
    flash_field_read_cached(2,(param_1 & 0xff) + 0xa6,&local_10,1);
  }
  else {
    flash_field_read_cached(2,(param_1 & 0xff) + 0x17,&local_10,1);
  }
  if ((((byte)(*(char *)PTR_DAT_03055378 - 5U) < 3) || (*(char *)PTR_DAT_03055378 == '\x0e')) ||
     (*(char *)PTR_DAT_03055370 == 'Q')) {
    float32_pack_const_two(local_10);
    float32_unpack_then_softdouble_pack_round_wrapper();
    soft_double_multiply();
    uVar5 = soft_double_to_int();
    local_10 = (byte)uVar5;
    if (0xff < uVar5) {
      local_10 = 0xff;
    }
  }
  puVar3 = PTR_DAT_0305536c;
  (*(code *)(PTR_DAT_0305536c[2] & 0xfffffffe))(local_10);
  (*(code *)(puVar3[3] & 0xfffffffe))(local_10);
  p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | 0x10;
  cVar2 = *(char *)PTR_DAT_03055378;
  if ((byte)(cVar2 - 5U) < 3) {
    p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0x7f | 0x80;
    if (cVar2 != '\x05') goto LAB_030552c6;
    flash_field_read_cached(2,*(undefined2 *)PTR_DAT_03055384,&local_10,1);
  }
  else {
    if (cVar2 != '\x0e') goto LAB_03055338;
    p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0x7f | 0x80;
LAB_030552c6:
    if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
      flash_field_read_cached(2,0xac,&local_10,1);
    }
    else {
      flash_field_read_cached(2,0x1d,&local_10,1);
    }
  }
  fd6818b_compander_calibration_write(local_10);
  if (((byte)(*(char *)PTR_DAT_03055378 - 6U) < 2) || (*(char *)PTR_DAT_03055378 == '\x0e')) {
    flash_field_read_cached(2,*(undefined2 *)PTR_DAT_03055384,&local_10,1);
    PTR_DAT_03055388[0x2d] = local_10;
  }
  else {
    PTR_DAT_03055388[0x2d] = 0;
  }
  p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
LAB_03055338:
  if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
    flash_field_read_cached(2,0xd0,&local_10,1);
  }
  else {
    flash_field_read_cached(2,0x40,&local_10,1);
  }
  PTR_DAT_03055388[0x28] = local_10;
  return;
}

