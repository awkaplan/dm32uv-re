/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_coordinate_seconds_to_hms_string_format @ 030114f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_coordinate_seconds_to_hms_string_format(int param_1__w,int param_2,undefined4 param_3)

{
  char param_1 = (char)param_1__w;
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 == '\0') {
    uVar2 = 10;
  }
  else {
    uVar2 = 9;
  }
  pbVar1 = (byte *)(param_2 + (uVar2 - 1));
  uVar4 = 0;
  iVar5 = 1;
  uVar3 = 0;
  do {
    if (*pbVar1 != 0x2e) {
      uVar3 = uVar3 + iVar5 * (*pbVar1 - 0x30);
      iVar5 = iVar5 * 10;
    }
    uVar4 = uVar4 + 1 & 0xff;
    pbVar1 = pbVar1 + -1;
  } while (uVar4 < uVar2);
  uVar2 = ((uVar3 % 1000000) % 10000) * 0x3c;
  number_to_string_format_2args
            (param_3,PTR_LAB_0301161c,uVar3 / 1000000,(uVar3 % 1000000) / 10000,uVar2 / 10000,
             (uVar2 % 10000) / 1000,0x22);
  return;
}

