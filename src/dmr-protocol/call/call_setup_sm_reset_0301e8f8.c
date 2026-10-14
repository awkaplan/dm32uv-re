/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_sm_reset @ 0301e8f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_sm_reset(void)

{
  call_setup_sm_state *pcVar1;
  
  PTR_DAT_0301ea60[1] = 0;
  pcVar1 = p_call_setup_sm_state;
  p_call_setup_sm_state->flags_0x18 = p_call_setup_sm_state->flags_0x18 & 0xfe;
  pcVar1->field_0x14 = 0;
  return;
}

