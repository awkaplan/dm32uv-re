/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_sm_aux_field24_store @ 0301e840 (file base 0x03000000; code starts at 0x03001000)
 * Size: 6 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_sm_aux_field24_store(undefined4 param_1)

{
  *(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0 = param_1;
  return;
}

