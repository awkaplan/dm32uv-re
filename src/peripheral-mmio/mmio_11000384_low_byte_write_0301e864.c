/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mmio_11000384_low_byte_write @ 0301e864 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-mmio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void mmio_11000384_low_byte_write(byte param_1)

{
  dword dVar1;
  
  p_call_setup_sm_state_aux->field_0x5 = param_1;
  dVar1 = SystemControl_Type_11000000.LOCAL_CC;
  SystemControl_Type_11000000.LOCAL_CC = (uint)param_1 | dVar1 & 0xfffffff0;
  return;
}

