/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: int_to_double_divide_convert @ 0300df5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void int_to_double_divide_convert(undefined2 param_1)

{
  undefined2 value;
  
  soft_double_from_int(param_1);
  soft_double_multiply();
  value = soft_double_to_int();
  fd6818b_reg_write(FD6818_PAGE0_REG_71H,value);
  return;
}

