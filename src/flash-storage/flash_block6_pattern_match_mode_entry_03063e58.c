/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block6_pattern_match_mode_entry @ 03063e58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 496 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 flash_block6_pattern_match_mode_entry(void)

{
  undefined4 *puVar1;
  ushort block_id;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  byte bVar8;
  byte abStack_1c [16];
  
  pbVar3 = abStack_1c;
  pbVar4 = abStack_1c;
  block_id = flash_block_id_resolve_locked(6);
  PTR_DAT_03063ff4[2] = 0;
  if (*(byte *)PTR_DAT_03063ff8 < 0x12) {
    flash_block_read(block_id,0x130,abStack_1c,0x10);
    if (abStack_1c[0] < 0x10) {
      if (*(byte *)PTR_DAT_03063ffc == abStack_1c[0]) {
        uVar7 = 1;
        pcVar2 = PTR_DAT_03064000;
        do {
          pbVar3 = pbVar3 + 1;
          if (*pcVar2 != *pbVar3) {
            if (uVar7 != 0x10) goto LAB_03063ed2;
            break;
          }
          uVar7 = uVar7 + 1 & 0xff;
          pcVar2 = pcVar2 + 1;
        } while (uVar7 != 0x10);
        if (*(char *)(PTR_DAT_03063ffc + 4) != '\x0f') {
          PTR_DAT_03063ff4[2] = 2;
          return 1;
        }
        PTR_DAT_03063ff4[2] = 1;
        return 1;
      }
      uVar7 = 0;
LAB_03063ed2:
      if ((abStack_1c[uVar7] == 0xff) && (*(char *)((int)PTR_DAT_03063ffc + uVar7) == '\x0f')) {
        PTR_DAT_03063ff4[2] = 1;
        return 1;
      }
    }
    flash_block_read(block_id,0x140,abStack_1c,0x10);
    if (abStack_1c[0] < 0x10) {
      if (*(byte *)PTR_DAT_03063ffc == abStack_1c[0]) {
        uVar7 = 1;
        pcVar2 = PTR_DAT_03064000;
        do {
          pbVar4 = pbVar4 + 1;
          if (*pcVar2 != *pbVar4) {
            if (uVar7 != 0x10) goto LAB_03063f56;
            break;
          }
          uVar7 = uVar7 + 1 & 0xff;
          pcVar2 = pcVar2 + 1;
        } while (uVar7 != 0x10);
        if (*(char *)(PTR_DAT_03063ffc + 4) != '\x0f') {
          PTR_DAT_03063ff4[2] = 4;
          return 1;
        }
        PTR_DAT_03063ff4[2] = 3;
        return 1;
      }
      uVar7 = 0;
LAB_03063f56:
      if ((abStack_1c[uVar7] == 0xff) && (*(char *)((int)PTR_DAT_03063ffc + uVar7) == '\x0f')) {
        PTR_DAT_03063ff4[2] = 3;
        return 1;
      }
    }
  }
  if (2 < *(byte *)PTR_DAT_03063ff8) {
    pcVar5 = PTR_DAT_03064004 + 6;
    bVar8 = 0;
    cVar6 = '\0';
    pcVar2 = (char *)PTR_DAT_03063ffc;
    do {
      if (*pcVar5 != *pcVar2) {
        if (*pcVar2 != PTR_DAT_03064004[9]) {
          if (cVar6 != '\x03') {
            return 0;
          }
          break;
        }
        bVar8 = bVar8 + 1;
      }
      cVar6 = cVar6 + '\x01';
      pcVar2 = pcVar2 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar6 != '\x03');
    if ((*(byte *)PTR_DAT_03063ff8 != 3) &&
       (*(char *)((int)PTR_DAT_03063ffc + 3) == PTR_DAT_03064004[10])) {
      radio_mode_enter_and_refresh(PTR_DAT_03064008[1] & 1);
      flash_block6_callsign_lookup_or_hex_fallback(_DAT_0306400c,_DAT_03064010);
      PTR_DAT_03064014[0x15] = PTR_DAT_03064014[0x15] & 0xbf | 0x40;
      if (bVar8 < 3) {
        if (bVar8 == 0) {
          *(undefined1 *)(PTR_DAT_03064174 + 1) = 0;
        }
        else {
          *(undefined1 *)(PTR_DAT_03064174 + 1) = 1;
        }
      }
      else {
        PTR_DAT_03063ff4[4] = 2;
      }
      puVar1 = PTR_DAT_03064174;
      cVar6 = PTR_DAT_03064178[0xb];
      if ((cVar6 != '\0') && (*(undefined1 *)((int)PTR_DAT_03064174 + 3) = 1, cVar6 == '\x02')) {
        *(byte *)puVar1 = *(byte *)puVar1 & 0xef | 0x10;
        PTR_DAT_0306417c[5] = PTR_DAT_0306417c[4];
      }
    }
  }
  return 0;
}

