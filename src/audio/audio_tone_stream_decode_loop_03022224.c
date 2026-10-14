/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: audio_tone_stream_decode_loop @ 03022224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: audio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void audio_tone_stream_decode_loop(void)

{
  dword dVar1;
  dialog_flags_from_flash *pdVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  ushort uVar9;
  uint uVar10;
  byte local_74 [16];
  byte local_64 [64];
  
  clear_two_state_bytes_03029fc8();
  mmio_14000000_timer_config(500);
  tx_forbid_flag_clear_call();
  mmio_14000000_timer_config(4);
  puVar3 = PTR_CODEC_Type_030223ec;
  pdVar2 = p_dialog_flags_from_flash;
  uVar10 = 0;
  uVar9 = 0;
  while ((pdVar2->flags_0x1 & 8) != 0) {
    dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
    if ((int)dVar1 < 0) {
      tx_forbid_flag_clear_call();
    }
    else {
      memcpy_bytes_iram(local_74,PTR_LAB_030223f0 + uVar10,0x10);
      uVar10 = uVar10 + 0x10;
      uVar9 = uVar9 + 0x10;
      pbVar8 = local_74;
      pbVar7 = local_64;
      do {
        uVar4 = table_scaled_clamped_accumulator_step(*pbVar8 & 0xf);
        *pbVar7 = (byte)(uVar4 << 4);
        pbVar7[1] = (byte)((uVar4 & 0xfffffff) >> 4);
        uVar4 = table_scaled_clamped_accumulator_step(*pbVar8 >> 4);
        pbVar7[2] = (byte)(uVar4 << 4);
        pbVar7[3] = (byte)((uVar4 & 0xfffffff) >> 4);
        pbVar8 = pbVar8 + 1;
        pbVar7 = pbVar7 + 4;
        pbVar5 = PTR_DAT_030223e4;
        pbVar6 = local_64;
      } while (pbVar8 != local_64);
      do {
        *pbVar5 = *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (pbVar5 != puVar3);
      tx_forbid_flag_clear_call();
      if (0x4ef < uVar10) {
        uVar10 = 0;
      }
    }
    if (0x4ef < uVar9) {
      uVar9 = 0;
    }
  }
  return;
}

