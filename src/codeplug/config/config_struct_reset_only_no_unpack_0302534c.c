/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_struct_reset_only_no_unpack @ 0302534c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void config_struct_reset_only_no_unpack(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR_DAT_03025394;
  *(undefined1 *)(PTR_DAT_03025394 + 0xf) = 0;
  puVar1[0xe1] = 0;
  puVar1[0xe3] = 0;
  *(undefined1 *)(puVar1 + 0xe5) = 0;
  puVar2 = PTR_DAT_03025394;
  if (*(char *)((int)puVar1 + 0xb) == '\x01') {
    PTR_DAT_03025394[0xdf] = 0;
    memset_bytes((int)puVar2 + 0x3e,0xff,0x14);
  }
  if ((*(char *)(PTR_DAT_03025394 + 1) == '\x01') && (*(char *)(PTR_DAT_03025394 + 3) == '\0')) {
    OSFlagPost_wrapper_set_passthrough(0x80);
  }
  return;
}

