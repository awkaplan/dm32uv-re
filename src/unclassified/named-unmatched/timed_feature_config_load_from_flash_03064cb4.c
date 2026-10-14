/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timed_feature_config_load_from_flash @ 03064cb4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void timed_feature_config_load_from_flash(void)

{
  undefined2 *puVar1;
  char cStack_c;
  byte bStack_b;
  undefined1 uStack_a;
  byte bStack_9;
  
  flash_field_read_cached(0x10,0xb00,&cStack_c,4);
  if (cStack_c == '\x01') {
    *(byte *)PTR_DAT_03064e50 = *(byte *)PTR_DAT_03064e50 & 0xfe | 1;
  }
  else {
    *(byte *)PTR_DAT_03064e50 = *(byte *)PTR_DAT_03064e50 & 0xfe;
  }
  puVar1 = PTR_DAT_03064e50;
  PTR_DAT_03064e50[1] = (ushort)bStack_b * 0x3c;
  *(undefined1 *)(puVar1 + 3) = uStack_a;
  *(byte *)puVar1 = *(byte *)puVar1 & 7 | (bStack_9 & 7) << 3;
  return;
}

