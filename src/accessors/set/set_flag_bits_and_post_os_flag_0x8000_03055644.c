/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: set_flag_bits_and_post_os_flag_0x8000 @ 03055644 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void set_flag_bits_and_post_os_flag_0x8000(uint param_1)

{
  *PTR_DAT_03055660 = *PTR_DAT_03055660 | param_1;
  OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x8000);
  return;
}

