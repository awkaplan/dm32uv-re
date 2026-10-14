/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_nmea_datetime_to_rtc_sync @ 0301265c (file base 0x03000000; code starts at 0x03001000)
 * Size: 248 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_nmea_datetime_to_rtc_sync(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  char cVar7;
  short sVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [2];
  byte bStack_36;
  byte bStack_35;
  char cStack_33;
  char cStack_32;
  char cStack_30;
  char cStack_2f;
  char cStack_2d;
  char cStack_2c;
  char cStack_2a;
  char cStack_29;
  
  iVar1 = _DAT_03012754;
  iVar3 = string_find_nth_comma_index(_DAT_03012754,1);
  iVar4 = string_find_nth_comma_index(iVar1,2);
  memset_bytes(auStack_44,0,0xb);
  memcpy_bytes_iram(auStack_44,iVar1 + iVar3,iVar4 - iVar3);
  iVar3 = string_find_nth_comma_index(iVar1,9);
  iVar4 = string_find_nth_comma_index(iVar1,10);
  puVar6 = auStack_4c;
  memset_bytes(puVar6,0,7);
  memcpy_bytes_iram(puVar6,iVar1 + iVar3,iVar4 - iVar3);
  gps_datetime_format(2,puVar6,auStack_44,auStack_38);
  sVar8 = bStack_35 + 0x5c0 + (ushort)bStack_36 * 10;
  cVar9 = cStack_32 + -0x10 + cStack_33 * '\n';
  bVar10 = cStack_2f + -0x10 + cStack_30 * '\n';
  bVar11 = cStack_2c + -0x10 + cStack_2d * '\n';
  cVar7 = cStack_29 + -0x10 + cStack_2a * '\n';
  uVar5 = rtc_decode_calendar_date();
  SUBPIECE_SET(uStack_54, 1, 1, (char)(uVar5 >> 8));
  SUBPIECE_SET(uStack_50, 1, 1, (char)((uint)puVar6 >> 8));
  cVar2 = SUBPIECE(uStack_50, 1, 1);
  SUBPIECE_SET(uStack_50, 2, 2, (short)((uint)puVar6 >> 0x10));
  if ((((SUBPIECE(uStack_50, 2, 2) != sVar8) || (cVar9 != SUBPIECE(uStack_50, 1, 1))) ||
      ((uint)bVar10 != ((uint)puVar6 & 0xff))) ||
     (((uint)bVar11 != (uVar5 & 0xff) || (cVar7 != SUBPIECE(uStack_54, 1, 1))))) {
    SUBPIECE_SET(uStack_54, 2, 2, (undefined2)(uVar5 >> 0x10));
    SUBPIECE_SET(uStack_54, 0, 2, CONCAT11(cVar7,bVar11));
    uStack_50 = CONCAT22(sVar8,CONCAT11(cVar9,bVar10));
    rtc_date_validate_and_write(uStack_54,uStack_50,cVar2,&uStack_54,uVar5,puVar6);
  }
  return;
}

