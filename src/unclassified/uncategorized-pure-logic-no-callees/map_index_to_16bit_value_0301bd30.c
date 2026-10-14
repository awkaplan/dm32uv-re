/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: map_index_to_16bit_value @ 0301bd30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void map_index_to_16bit_value(byte param_1)

{
  if (param_1 == 2) {
    PTR_DAT_0301be3c[0xc] = 0xe10;
    return;
  }
  if (param_1 < 3) {
    if (param_1 == 1) {
      PTR_DAT_0301be3c[0xc] = 0x708;
      return;
    }
  }
  else {
    if (param_1 == 3) {
      PTR_DAT_0301be3c[0xc] = 0x1c20;
      return;
    }
    if (param_1 == 4) {
      PTR_DAT_0301be3c[0xc] = 0x3840;
      return;
    }
  }
  PTR_DAT_0301be3c[0xc] = 0x7080;
  return;
}

