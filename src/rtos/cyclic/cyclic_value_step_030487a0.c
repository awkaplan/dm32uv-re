/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cyclic_value_step @ 030487a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte cyclic_value_step(byte param_1,byte param_2,byte param_3,char param_4)

{
  bool bVar1;
  
  if (param_4 == '\0') {
    bVar1 = param_3 < param_1;
    param_3 = param_2;
    if (bVar1) {
      param_3 = param_1 - 1;
    }
  }
  else if (param_1 < param_2) {
    param_3 = param_1 + 1;
  }
  return param_3;
}

