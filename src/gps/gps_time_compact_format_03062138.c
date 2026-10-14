/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_time_compact_format @ 03062138 (file base 0x03000000; code starts at 0x03001000)
 * Size: 322 bytes
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

void gps_time_compact_format
               (char param_1,uint param_2,byte param_3,undefined1 param_4,byte param_5,byte param_6,
               undefined1 param_7,undefined4 param_8)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bStack_26;
  byte bStack_25;
  
  param_2 = param_2 & 0xff;
  gps_coordinate_table_entry_parse(PTR_DAT_0306222c[0xb6],&bStack_25,&bStack_26);
  uVar2 = (uint)bStack_25;
  if ((char)bStack_25 < '\0') {
    bStack_25 = (byte)-uVar2;
    uVar2 = param_2 + (-uVar2 & 0xff) & 0xff;
    param_3 = param_3 + bStack_26;
    if (0x3b < param_3) {
      uVar2 = uVar2 + 1 & 0xff;
      param_3 = param_3 - 0x3c;
    }
    if (uVar2 < 0x18) {
      iVar3 = 0;
    }
    else {
      uVar2 = uVar2 - 0x18 & 0xff;
      iVar3 = 1;
    }
  }
  else {
    if (param_3 < bStack_26) {
      param_3 = (param_3 - bStack_26) + 0x3c;
      param_2 = param_2 - 1 & 0xff;
    }
    else {
      param_3 = param_3 - bStack_26;
    }
    if ((int)param_2 < (int)(char)bStack_25) {
      uVar2 = (param_2 - uVar2) + 0x18 & 0xff;
      iVar3 = 2;
    }
    else {
      uVar2 = param_2 - uVar2 & 0xff;
      iVar3 = 0;
    }
  }
  if (param_6 < 8) {
    bVar1 = (param_5 & 1) != 0;
  }
  else {
    bVar1 = ~((param_5 & 1) != 0);
  }
  if (iVar3 == 1) {
    param_5 = param_5 + 1;
    if (bVar1 == 0) {
      if (0x1e < param_5) {
        param_6 = param_6 + 1;
        param_5 = 1;
      }
    }
    else if (0x1f < param_5) {
      param_6 = param_6 + 1;
      param_5 = 1;
    }
  }
  else if ((iVar3 == 2) && (param_5 == 1)) {
    if (bVar1 == 0) {
      param_5 = 0x1f;
    }
    else if (param_6 == 8) {
      param_5 = 0x1f;
    }
    else {
      param_5 = 0x1e;
    }
    param_6 = param_6 - 1;
  }
  if (param_1 == '\0') {
    number_to_string_format_2args(param_8,_LAB_0306228c,uVar2,param_3,param_4);
  }
  else {
    number_to_string_format_2args(param_8,_LAB_0306228c,param_5,param_6,param_7);
  }
  return;
}

