/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: circular_line_buffer_char_append @ 03011748 (file base 0x03000000; code starts at 0x03001000)
 * Size: 194 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void circular_line_buffer_char_append(void)

{
  ushort uVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  
  puVar5 = PTR_DAT_03011820;
  puVar4 = PTR_DAT_0301181c;
  uVar6 = (uint)(ushort)PTR_DAT_03011818[1];
  sVar8 = PTR_DAT_03011818[2];
  uVar7 = 0;
  do {
    puVar3 = PTR_DAT_03011818;
    cVar2 = puVar4[uVar7];
    if (cVar2 == '\n') {
      PTR_DAT_03011818[1] = (short)uVar6;
      puVar3[2] = sVar8;
      if ((uVar7 & 0xff) < 0x96) {
        uVar1 = puVar3[1];
        PTR_DAT_03011820[uVar1] = 10;
        uVar6 = uVar1 + 1;
        puVar3[1] = (short)uVar6;
        if (0x3ff < (uVar6 & 0xffff)) {
          PTR_DAT_03011818[1] = 0;
        }
        puVar3 = PTR_DAT_03011818;
        PTR_DAT_03011818[2] = PTR_DAT_03011818[2] + 1;
        PTR_DAT_0301181c[uVar7] = 0;
        *(char *)(puVar3 + 3) = *(char *)(puVar3 + 3) + '\x01';
      }
      else {
LAB_030117de:
        uVar1 = PTR_DAT_03011818[1];
        if (uVar1 < 0x97) {
          PTR_DAT_03011818[1] = uVar1 + 0x36a;
        }
        else {
          PTR_DAT_03011818[1] = uVar1 - 0x96;
        }
        if (0x95 < (ushort)PTR_DAT_03011818[2]) {
          PTR_DAT_03011818[2] = PTR_DAT_03011818[2] - 0x96;
        }
      }
      return;
    }
    if (uVar7 == 0x96) {
      PTR_DAT_03011818[1] = (short)uVar6;
      puVar3[2] = sVar8;
      goto LAB_030117de;
    }
    puVar5[uVar6] = cVar2;
    uVar6 = uVar6 + 1 & 0xffff;
    sVar8 = sVar8 + 1;
    puVar4[uVar7] = 0;
    if (0x3ff < uVar6) {
      uVar6 = 0;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

