/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_write_and_readback_channel_data @ 03066334 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_field_write_and_readback_channel_data(undefined1 param_1)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 local_14 [4];
  
  puVar2 = PTR_DAT_030664b8;
  PTR_DAT_030664b8[3] = param_1;
  flash_field_write_cached(0x65,3);
  sVar1 = ((byte)puVar2[3] - 1) * 0x21;
  flash_field_read_cached(0x65,sVar1 + 0x20,local_14,1);
  puVar2[5] = local_14[0];
  flash_field_read_cached(0x65,sVar1 + 0x21,puVar2 + 8,0x10);
  *(undefined1 *)PTR_DAT_030664bc = 0;
  return;
}

