/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_state_advance_gate @ 030273c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool call_setup_state_advance_gate(void)

{
  bool bVar1;
  
  if (p_call_setup_sm_state_aux->field_0x5 == PTR_DAT_030274e0[6]) {
    bVar1 = false;
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    bVar1 = PTR_DAT_030274e0[6] != 0xf;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

