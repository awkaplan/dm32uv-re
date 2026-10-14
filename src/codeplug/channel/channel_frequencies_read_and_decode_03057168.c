/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_frequencies_read_and_decode @ 03057168 (file base 0x03000000; code starts at 0x03001000)
 * Size: 256 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_frequencies_read_and_decode(short param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_6c [52];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [24];
  undefined2 local_18;
  undefined1 local_16 [2];
  
  local_18 = 0;
  if (param_1 == 0) {
    if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      channel_freq_record_build_from_flash(auStack_6c,(byte)p_dm32_settings_block04[0x2d] >> 7);
      memcpy_ck803s(param_2,auStack_6c,0x33);
    }
    else {
      channel_num_to_block_offset
                (*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0,local_16,&local_18);
      flash_field_read_cached(local_16[0],local_18,auStack_38,0x20);
      memcpy_bytes_iram(param_2 + 8,auStack_30,0x18);
      uVar1 = bcd_frequency_decode(auStack_38,4);
      *param_2 = (char)uVar1;
      param_2[1] = (char)((uint)uVar1 >> 8);
      param_2[2] = (char)((uint)uVar1 >> 0x10);
      param_2[3] = (char)((uint)uVar1 >> 0x18);
      uVar1 = bcd_frequency_decode(auStack_34,4);
      param_2[4] = (char)uVar1;
      param_2[5] = (char)((uint)uVar1 >> 8);
      param_2[6] = (char)((uint)uVar1 >> 0x10);
      param_2[7] = (char)((uint)uVar1 >> 0x18);
    }
  }
  else {
    channel_num_to_block_offset(param_1,local_16,&local_18);
    flash_field_read_cached(local_16[0],local_18,auStack_38,0x20);
    memcpy_bytes_iram(param_2 + 8,auStack_30,0x18);
    uVar1 = bcd_frequency_decode(auStack_38,4);
    *param_2 = (char)uVar1;
    param_2[1] = (char)((uint)uVar1 >> 8);
    param_2[2] = (char)((uint)uVar1 >> 0x10);
    param_2[3] = (char)((uint)uVar1 >> 0x18);
    uVar1 = bcd_frequency_decode(auStack_34,4);
    param_2[4] = (char)uVar1;
    param_2[5] = (char)((uint)uVar1 >> 8);
    param_2[6] = (char)((uint)uVar1 >> 0x10);
    param_2[7] = (char)((uint)uVar1 >> 0x18);
  }
  return;
}

