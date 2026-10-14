/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_audio_clip_playback_pcm @ 030222f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 244 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_audio_clip_playback_pcm(uint param_1,int param_2,int param_3)

{
  dword dVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_90 [40];
  uint uStack_68;
  byte abStack_64 [64];
  
  flash_block_read(*(ushort *)PTR_DAT_030223f4,(param_1 & 0xff) << 4,abStack_64,0x10);
  iVar6 = ((uint)abStack_64[3] << 0x10 | (uint)abStack_64[1] | (uint)abStack_64[2] << 8) +
          *(int *)PTR_LAB_030223f8;
  flash_read_mutex_guarded(iVar6,auStack_90,0x2c);
  iVar3 = buffer_compare_memcmp_style(auStack_90,PTR_LAB_030223fc,4);
  if (iVar3 == 0) {
    iVar6 = iVar6 + 0x2c;
    spi_flash_read_mutex_guarded(iVar6,abStack_64,0x40);
    puVar2 = PTR_DAT_030223e4;
    uVar5 = 1;
    while (uVar5 < uStack_68 >> 6) {
      do {
        dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      } while ((int)dVar1 < 0);
      memcpy_bytes_iram(puVar2,abStack_64,0x40);
      spi_flash_read_mutex_guarded(uVar5 * 0x40 + iVar6,abStack_64,0x40);
      uVar5 = uVar5 + 1 & 0xffff;
      if (param_2 != 0) {
        audio_pa_enable_gate(1);
        param_2 = 0;
      }
    }
    if ((param_3 != 0) && (uVar4 = uStack_68 & 0x3f, uVar4 != 0)) {
      spi_flash_read_mutex_guarded(uVar5 * 0x40 + iVar6,abStack_64,0x40);
      do {
        abStack_64[uVar4] = 0;
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 != 0x40);
      do {
        dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      } while ((int)dVar1 < 0);
      memcpy_bytes_iram(PTR_DAT_030223e4,abStack_64,0x40);
    }
  }
  return;
}

