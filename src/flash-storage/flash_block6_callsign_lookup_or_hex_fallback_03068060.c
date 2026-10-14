/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block6_callsign_lookup_or_hex_fallback @ 03068060 (file base 0x03000000; code starts at 0x03001000)
 * Size: 260 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint flash_block6_callsign_lookup_or_hex_fallback(char *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  ushort block_id;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint offset;
  byte bStack_35;
  char cStack_34;
  char acStack_33 [15];
  
  block_id = flash_block_id_resolve_locked(6);
  flash_block_read(block_id,0x1ff,&bStack_35,1);
  if (bStack_35 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    do {
      offset = (uVar5 + 0x10) * 0x20;
      flash_block_read(block_id,offset + 0x10,&cStack_34,8);
      if (*param_1 == cStack_34) {
        cVar2 = '\x01';
        pcVar4 = acStack_33;
        pcVar3 = param_1;
        while (pcVar3 = pcVar3 + 1, *pcVar3 == *pcVar4) {
          cVar2 = cVar2 + '\x01';
          pcVar4 = pcVar4 + 1;
          if (cVar2 == '\x05') goto LAB_030680ec;
        }
        if (cVar2 == '\x05') {
LAB_030680ec:
          if (uVar5 < bStack_35) {
            flash_block_read(block_id,offset,&cStack_34,0x10);
            if ((byte)(cStack_34 - 1U) < 0xfe) {
              memcpy_bytes_iram(param_2,&cStack_34,0x10);
              param_2[0x10] = 0;
              return uVar5;
            }
            *param_2 = 0x4e;
            param_2[1] = 0x4f;
            param_2[2] = 0x20;
            param_2[3] = 0x49;
            param_2[4] = 0x44;
            return uVar5;
          }
          break;
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < bStack_35);
  }
  iVar6 = 0;
  do {
    uVar1 = nibble_to_hex_ascii_uppercase(param_1[iVar6]);
    param_2[iVar6] = uVar1;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  param_2[5] = 0;
  return uVar5;
}

