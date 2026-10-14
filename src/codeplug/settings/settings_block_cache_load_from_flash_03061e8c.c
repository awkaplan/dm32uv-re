/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_block_cache_load_from_flash @ 03061e8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 244 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_block_cache_load_from_flash(void)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  flash_field_read_cached(4,0x331,&bStack_14,4);
  if ((bStack_14 & 1) == 0) {
    *(byte *)PTR_DAT_03062058 = *(byte *)PTR_DAT_03062058 & 0xfd;
  }
  else {
    *(byte *)PTR_DAT_03062058 = *(byte *)PTR_DAT_03062058 & 0xfd | 2;
  }
  puVar1 = PTR_DAT_03062058;
  uVar2 = (uint)bStack_11 << 0x10 | (uint)bStack_13 | (uint)bStack_12 << 8;
  PTR_DAT_03062058[2] = uVar2;
  if (uVar2 == 0) {
    puVar1[2] = 1;
  }
  flash_field_read_cached(4,0x302,&bStack_14,1);
  if ((bStack_14 & 1) == 0) {
    *(byte *)PTR_DAT_03062058 = *(byte *)PTR_DAT_03062058 & 0xfb;
  }
  else {
    *(byte *)PTR_DAT_03062058 = *(byte *)PTR_DAT_03062058 & 0xfb | 4;
  }
  flash_field_read_cached(4,0x301,&bStack_14,1);
  puVar1 = PTR_DAT_03062058;
  *(ushort *)(PTR_DAT_03062058 + 1) = (ushort)bStack_14 * 0x1e;
  *(undefined2 *)(puVar1 + 3) = 0;
  flash_field_read_cached(4,0x306,(int)puVar1 + 0xe,9);
  flash_field_read_cached(4,0x310,puVar1 + 6,9);
  flash_field_read_cached(4,0x30f,(int)puVar1 + 0x17,1);
  flash_field_read_cached(4,0x319,(int)puVar1 + 0x21,1);
  return;
}

