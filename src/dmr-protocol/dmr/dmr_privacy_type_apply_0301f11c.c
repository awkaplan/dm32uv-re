/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_type_apply @ 0301f11c (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_type_apply(int param_1__w)

{
  char param_1 = (char)param_1__w;
  p_call_setup_sm_state_aux->field_0xb = 0;
  if (param_1 == '\0') {
    stack_buffer_triple_call_helper();
    *(undefined1 *)PTR_DAT_0301f148 = 0;
  }
  else {
    dmr_privacy_alg_select_from_cps_type(1);
  }
  return;
}

