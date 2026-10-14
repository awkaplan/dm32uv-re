/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: unix_time_to_date_components @ 0301c7f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 unix_time_to_date_components(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_1 / 0x15180;
  if (*PTR_DAT_0301c920 != uVar7) {
    *PTR_DAT_0301c920 = uVar7;
    if (uVar7 < 0x16d) {
      uVar6 = 0x7b2;
    }
    else {
      uVar6 = 0x7b2;
      do {
        if ((uVar6 % 400 == 0) || ((uVar6 % 100 != 0 && ((uVar6 & 3) == 0)))) {
          if (uVar7 < 0x16e) {
            uVar6 = uVar6 + 1 & 0xffff;
            break;
          }
          iVar1 = -0x16e;
        }
        else {
          iVar1 = -0x16d;
        }
        uVar7 = uVar7 + iVar1;
        uVar6 = uVar6 + 1 & 0xffff;
      } while (0x16c < uVar7);
    }
    *(short *)((int)PTR_DAT_0301c924 + 6) = (short)uVar6;
    puVar2 = PTR_DAT_0301c924;
    if (uVar7 < 0x1c) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      do {
        if (((uVar6 % 400 == 0) || ((uVar6 % 100 != 0 && ((uVar6 & 3) == 0)))) && (uVar4 == 1)) {
          if (uVar7 < 0x1d) break;
          iVar1 = -0x1d;
        }
        else {
          if (uVar7 < (byte)PTR_LAB_030ad9e7_1_0301c928[uVar4]) break;
          iVar1 = -(uint)(byte)PTR_LAB_030ad9e7_1_0301c928[uVar4];
        }
        uVar7 = uVar7 + iVar1;
        uVar4 = uVar4 + 1 & 0xffff;
      } while (0x1b < uVar7);
    }
    *(char *)((int)PTR_DAT_0301c924 + 5) = (char)uVar4 + '\x01';
    *(char *)(puVar2 + 1) = (char)uVar7 + '\x01';
  }
  puVar2 = PTR_DAT_0301c924;
  uVar7 = param_1 % 0x15180 & 0xffff;
  uVar3 = day_of_week_calculate(*PTR_DAT_0301c924,PTR_DAT_0301c924[1]);
  *(undefined1 *)((int)puVar2 + 3) = uVar3;
  *(char *)puVar2 = (char)(uVar7 / 0xe10);
  uVar7 = uVar7 % 0xe10;
  cVar5 = (char)(uVar7 / 0x3c);
  *(char *)((int)puVar2 + 1) = cVar5;
  *(char *)((int)puVar2 + 2) = (char)uVar7 + cVar5 * -0x3c;
  return *puVar2;
}

