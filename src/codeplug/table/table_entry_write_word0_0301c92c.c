/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_write_word0 @ 0301c92c (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 table_entry_write_word0(uint param_1,undefined4 param_2)

{
  **(undefined4 **)(PTR_LAB_0301c990 + (param_1 & 0xff) * 4) = param_2;
  return 0;
}

