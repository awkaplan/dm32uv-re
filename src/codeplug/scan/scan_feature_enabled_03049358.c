/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_feature_enabled @ 03049358 (file base 0x03000000; code starts at 0x03001000)
 * Size: 160 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool scan_feature_enabled(char param_1)

{
  bool bVar1;
  byte local_9;
  
  flash_field_read_cached(4,0x501,&local_9,1);
  if (param_1 == '\0') {
    bVar1 = (local_9 & 0x1f) != 0;
  }
  else if (param_1 == '\x01') {
    bVar1 = (local_9 & 1) != 0;
  }
  else if (param_1 == '\x02') {
    bVar1 = (local_9 & 2) != 0;
  }
  else if (param_1 == '\x03') {
    bVar1 = (local_9 & 4) != 0;
  }
  else if (param_1 == '\x04') {
    bVar1 = (local_9 & 8) != 0;
  }
  else if (param_1 == '\x05') {
    bVar1 = (local_9 & 0x10) != 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

