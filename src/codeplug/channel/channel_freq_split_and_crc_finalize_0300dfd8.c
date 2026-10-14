/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_split_and_crc_finalize @ 0300dfd8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_freq_split_and_crc_finalize(uint param_1)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  
  uVar6 = *PTR_DAT_0300e0e4;
  uVar5 = (uVar6 >> 1) + uVar6;
  if (param_1 < uVar5) {
    cVar7 = '\x01';
  }
  else if (param_1 < uVar5 + uVar6) {
    cVar7 = '\x02';
  }
  else if (param_1 < uVar5 + uVar6 * 2) {
    cVar7 = '\x03';
  }
  else if (param_1 < uVar5 + uVar6 * 3) {
    cVar7 = '\x04';
  }
  else if (param_1 < uVar5 + uVar6 * 4) {
    cVar7 = '\x05';
  }
  else if (param_1 < uVar5 + uVar6 * 5) {
    cVar7 = '\x06';
  }
  else {
    cVar7 = '\0';
  }
  puVar1 = PTR_DAT_0300e0f4;
  iVar2 = _DAT_0300e0f0;
  pcVar3 = PTR_DAT_0300e0ec;
  puVar4 = PTR_DAT_0300e0e8;
  if ((byte)PTR_DAT_0300e0e8[0x15] < 0xf) {
    PTR_DAT_0300e0e8[0x15] = cVar7 + PTR_DAT_0300e0e8[0x15];
    puVar1 = PTR_DAT_0300e0f4;
    iVar2 = _DAT_0300e0f0;
    pcVar3 = PTR_DAT_0300e0ec;
    puVar4 = PTR_DAT_0300e0e8;
  }
  for (; cVar7 != '\0'; cVar7 = cVar7 + -1) {
    uVar5 = *(uint *)(puVar4 + 0x18) >> 1;
    *(uint *)(puVar4 + 0x18) = uVar5;
    if (*pcVar3 == '\x01') {
      if ((*(byte *)(iVar2 + 0x35) & 0xc) == 8) {
        *(uint *)(puVar4 + 0x18) = uVar5 | 0x400000;
      }
    }
    else if ((*(byte *)(iVar2 + 0x35) & 0xc) == 0xc) {
      *(uint *)(puVar4 + 0x18) = uVar5 | 0x400000;
    }
    if (0xe < (byte)puVar4[0x15]) {
      uVar5 = *(uint *)(puVar4 + 0x18);
      *(uint *)(puVar4 + 0x18) = uVar5 & 0xf07fffff;
      uVar5 = count_clear_bits_low23(*puVar1 ^ uVar5 & 0xf07fffff);
      if (uVar5 < 0x14) {
        if (uVar5 < 0xf) {
          puVar4[0x14] = 0xaa;
        }
      }
      else {
        puVar4[0x14] = 0x55;
        *(undefined2 *)(puVar4 + 2) = 0;
        *(undefined4 *)(puVar4 + 0xc) = 0;
        *(undefined4 *)(puVar4 + 8) = 0;
        puVar4[4] = 0;
        puVar4[0x1d] = puVar4[0x1d] & 0xf5 | 2;
      }
    }
  }
  return;
}

