/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_decode_calendar_date @ 0301c2f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 354 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint rtc_decode_calendar_date(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined3 extraout_var;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  ushort *puVar11;
  ushort uVar12;
  short sVar13;
  undefined4 local_1c;
  
  bVar1 = rtc_register_read(0);
  bVar2 = rtc_register_read(1);
  bVar3 = rtc_register_read(2);
  bVar4 = rtc_register_read(4);
  bVar5 = rtc_register_read(3);
  sVar13 = (short)CONCAT31(extraout_var,bVar5) + (ushort)bVar4 * 0x100;
  uVar6 = (int)sVar13 / 0x16d + 0x7b2;
  uVar7 = uVar6 & 0xffff;
  uVar10 = uVar7 - 1;
  uVar8 = uVar10;
  if ((uVar10 & 0x80000000) != 0) {
    uVar8 = uVar7 + 2;
  }
  sVar13 = ((sVar13 + -0x559 + (short)uVar6 * -0x16d + (short)((int)uVar10 / 100)) -
           (short)((int)uVar8 >> 2)) - (short)((int)uVar10 / 400);
  if (sVar13 < 0) {
    uVar8 = uVar7 - 1;
    uVar7 = uVar8 & 0xffff;
    if (uVar7 % 400 == 0) {
      uVar12 = 1;
    }
    else if (uVar7 % 100 == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = (ushort)(byte)~((uVar8 & 3) != 0);
    }
    sVar13 = sVar13 + 0x16d + uVar12;
  }
  if ((uVar7 % 400 == 0) || ((uVar7 % 100 != 0 && ((uVar7 & 3) == 0)))) {
    if (sVar13 < 0x14f) {
      cVar9 = '\v';
      puVar11 = (ushort *)PTR_DAT_0301c5c4;
      do {
        if ((int)(uint)*puVar11 <= (int)sVar13) break;
        cVar9 = cVar9 + -1;
        puVar11 = puVar11 + -1;
      } while (cVar9 != '\0');
    }
  }
  else if (sVar13 < 0x14e) {
    cVar9 = '\v';
    puVar11 = (ushort *)PTR_DAT_0301c5c8;
    do {
      if ((int)(uint)*puVar11 <= (int)sVar13) break;
      cVar9 = cVar9 + -1;
      puVar11 = puVar11 + -1;
    } while (cVar9 != '\0');
  }
  local_1c = (uint)CONCAT12(bVar1,CONCAT11(bVar2,bVar3));
  return local_1c;
}

