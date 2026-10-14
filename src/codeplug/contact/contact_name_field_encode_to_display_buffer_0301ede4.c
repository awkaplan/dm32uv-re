/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_name_field_encode_to_display_buffer @ 0301ede4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 274 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_name_field_encode_to_display_buffer(byte param_1,byte param_2,int param_3)

{
  char cVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  byte bVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  
  puVar2 = PTR_DAT_0301ef04;
  PTR_DAT_0301ef04[3] = PTR_DAT_0301ef04[3] & 0x83 | (param_1 & 1) << 2 | (param_2 & 0xf) << 3;
  puVar2[0x25] = 0;
  uVar4 = strlen_ck803s(param_3);
  memset_bytes(puVar2 + 0x26,0,0x20);
  puVar6 = PTR_DAT_0301ef08;
  puVar2 = PTR_DAT_0301ef04;
  if (param_1 != 0) {
    uVar8 = uVar4 & 0xff;
    if (param_2 == 0) {
      memcpy_bytes_iram(PTR_DAT_0301ef08,param_3,uVar8);
      *(char *)((int)puVar6 + -1) = (char)uVar4;
      *(byte *)(puVar6 + -9) = (char)uVar4 * '\x02' | 0x40;
      if (0x1b < uVar8) {
        PTR_DAT_0301ef04[0x25] = 0x1b;
      }
      bVar5 = PTR_DAT_0301ef04[0x25];
    }
    else {
      if (uVar8 == 0) {
        bVar5 = 0;
      }
      else {
        pcVar7 = (char *)((int)PTR_DAT_0301ef08 + 1);
        bVar5 = 0;
        uVar4 = 0;
        do {
          cVar1 = *(char *)(param_3 + uVar4);
          if (cVar1 < '\0') {
            uVar4 = uVar4 + 1 & 0xff;
            uVar3 = dbyte_code_range_table_lookup(cVar1,*(undefined1 *)(param_3 + uVar4));
            *(char *)puVar6 = (char)((ushort)uVar3 >> 8);
            *pcVar7 = (char)uVar3;
          }
          else {
            *(undefined1 *)puVar6 = 0;
            *pcVar7 = *(char *)(param_3 + uVar4);
          }
          bVar5 = bVar5 + 2;
          puVar2[0x25] = puVar2[0x25] + '\x01';
          if (bVar5 == 0x1a) break;
          uVar4 = uVar4 + 1 & 0xff;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
          pcVar7 = pcVar7 + 2;
        } while (uVar4 < uVar8);
      }
      PTR_DAT_0301ef04[2] = PTR_DAT_0301ef04[0x25] * '\x02' | 0xc0;
    }
    if (bVar5 < 0x15) {
      if (bVar5 < 0xe) {
        if (bVar5 < 7) {
          PTR_DAT_0301f030[1] = 0;
        }
        else {
          PTR_DAT_0301ef04[1] = 1;
        }
      }
      else {
        PTR_DAT_0301ef04[1] = 2;
      }
    }
    else {
      PTR_DAT_0301ef04[1] = 3;
    }
  }
  return;
}

