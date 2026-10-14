/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_audio_clip_sequence_playback @ 03022400 (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_audio_clip_sequence_playback(uint param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint unaff_r7;
  undefined1 local_34 [6];
  char cStack_2e;
  byte bStack_2d;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  
  param_1 = param_1 & 0xff;
  if ((p_dm32_settings_block04[0x30] & 0x40) != 0) {
    param_1 = param_1 + 0x6e;
  }
  flash_block_read(*(ushort *)PTR_DAT_03022578,param_1 << 4,local_34,0x10);
  if (cStack_2e == '\x02') {
    unaff_r7 = (uint)bStack_2d;
    if (unaff_r7 != 0) {
      puVar3 = local_2c;
      puVar2 = local_24;
      do {
        *puVar2 = *puVar3;
        puVar3 = puVar3 + 2;
        puVar2 = puVar2 + 1;
      } while (puVar3 != local_2c + (unaff_r7 - 1 & 0xff) * 2 + 2);
    }
  }
  else if (cStack_2e == '\x01') {
    local_24[0] = local_34[0];
    unaff_r7 = 1;
  }
  uVar4 = 0;
  uVar1 = 1;
  while( true ) {
    if (uVar4 == unaff_r7 - 1) {
      flash_audio_clip_playback_pcm(local_24[uVar4],uVar1,1);
    }
    else {
      flash_audio_clip_playback_pcm(local_24[uVar4],uVar1,0);
    }
    uVar4 = uVar4 + 1;
    if (unaff_r7 <= (uVar4 & 0xff)) break;
    uVar1 = 0;
  }
  audio_pa_enable_gate(0);
  return;
}

