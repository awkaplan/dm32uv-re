/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_flash_load_and_build @ 03016944 (file base 0x03000000; code starts at 0x03001000)
 * Size: 942 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_flash_load_and_build(void)

{
  int iVar1;
  byte bStack_a;
  byte bStack_9;
  
  *(undefined1 *)PTR_DAT_03016b04 = 0;
  flash_field_read_cached(4,0x93,&bStack_9,1);
  if (9 < (byte)(bStack_9 - 1)) {
    bStack_9 = 1;
  }
  PTR_DAT_03016b08[0x5c] = bStack_9;
  bStack_9 = bStack_9 * '\x05';
  if ((*(byte *)PTR_DAT_03016b0c & 2) == 0) {
    flash_field_read_cached(4,0x87,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016b04 = *(byte *)PTR_DAT_03016b04 & 0xfd | 2;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016b10 = *(byte *)PTR_DAT_03016b10 & 0xfd | 2;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016afc[5] = PTR_DAT_03016b14[bStack_a];
    flash_field_read_cached(4,0x88,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016b04 = *(byte *)PTR_DAT_03016b04 & 0xfd | 2;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016b10 = *(byte *)PTR_DAT_03016b10 & 0xfd | 2;
      }
    }
    else {
      bStack_a = 0;
    }
    *PTR_DAT_03016afc = PTR_DAT_03016b14[bStack_a];
    flash_field_read_cached(4,0x89,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016b04 = *(byte *)PTR_DAT_03016b04 & 0xfb | 4;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016b10 = *(byte *)PTR_DAT_03016b10 & 0xfb | 4;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016afc[6] = PTR_DAT_03016b14[bStack_a];
    flash_field_read_cached(4,0x8a,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016b04 = *(byte *)PTR_DAT_03016b04 & 0xfb | 4;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016b10 = *(byte *)PTR_DAT_03016b10 & 0xfb | 4;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016afc[1] = PTR_DAT_03016b14[bStack_a];
    flash_field_read_cached(4,0x8b,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016cb4 = *(byte *)PTR_DAT_03016cb4 & 0xfe | 1;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016cb8 = *(byte *)PTR_DAT_03016cb8 & 0xfe | 1;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016cc0[7] = PTR_DAT_03016cbc[bStack_a];
    flash_field_read_cached(4,0x8c,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016cb4 = *(byte *)PTR_DAT_03016cb4 & 0xfe | 1;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016cb8 = *(byte *)PTR_DAT_03016cb8 & 0xfe | 1;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016cc0[2] = PTR_DAT_03016cbc[bStack_a];
    flash_field_read_cached(4,0x8d,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016cb4 = *(byte *)PTR_DAT_03016cb4 & 0xf7 | 8;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016cb8 = *(byte *)PTR_DAT_03016cb8 & 0xf7 | 8;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016cc0[8] = PTR_DAT_03016cbc[bStack_a];
    flash_field_read_cached(4,0x8e,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016cb4 = *(byte *)PTR_DAT_03016cb4 & 0xf7 | 8;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016cb8 = *(byte *)PTR_DAT_03016cb8 & 0xf7 | 8;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016cc0[3] = PTR_DAT_03016cbc[bStack_a];
    flash_field_read_cached(4,0x8f,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016cb4 = *(byte *)PTR_DAT_03016cb4 & 0xef | 0x10;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016cb8 = *(byte *)PTR_DAT_03016cb8 & 0xef | 0x10;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016cc0[9] = PTR_DAT_03016cbc[bStack_a];
    flash_field_read_cached(4,0x90,&bStack_a,1);
    if (bStack_a < 0x2b) {
      if (bStack_a == 0x1e) {
        *(byte *)PTR_DAT_03016e64 = *(byte *)PTR_DAT_03016e64 & 0xef | 0x10;
      }
      else if (bStack_a == 0x26) {
        *(byte *)PTR_DAT_03016e68 = *(byte *)PTR_DAT_03016e68 & 0xef | 0x10;
      }
    }
    else {
      bStack_a = 0;
    }
    PTR_DAT_03016e70[4] = PTR_DAT_03016e6c[bStack_a];
  }
  iVar1 = p_ucos_tmr_tmrkey;
  if (0x2f < (byte)(bStack_9 - 3)) {
    bStack_9 = 10;
  }
  *(uint *)(p_ucos_tmr_tmrkey + 0x20) = (uint)bStack_9;
  *(uint *)(iVar1 + 0x24) = (uint)bStack_9;
  return;
}

