/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: osflag_pend_consume_with_decisecond_timeout_alt @ 0300c73c (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void osflag_pend_consume_with_decisecond_timeout_alt
               (uint param_1,int param_2,int param_3,void *param_4)

{
  OSFlagPend_wrapper_consume(p_ucos_flaggrp_00038314,param_1,param_2,(param_3 + 9U) / 10,param_4);
  return;
}

