/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: seconds_decimal_from_int_format @ 03067494 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void seconds_decimal_from_int_format(int param_1__w,undefined4 param_2)

{
  undefined1 param_1 = (undefined1)param_1__w;
  undefined4 uVar1;
  
  soft_double_from_int(param_1);
  soft_double_divide();
  softdouble_extract_exponent_mantissa();
  uVar1 = float32_unpack_then_softdouble_pack_round_wrapper();
  numeric_value_display_centered(PTR_s___1f_s__030674cc,uVar1,param_2);
  return;
}

