/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_target_present_check @ 03023b90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool call_setup_target_present_check(void)

{
  bool bVar1;
  
  if (PTR_DAT_03023ce0[0x75] == '\0') {
    if (*(char *)((uint)p_dmr_call_config_state->field_0x2 + p_dmr_config_unpack_state) == '\0') {
      bVar1 = *(char *)((uint)p_dmr_call_config_state->field_0x2 + p_dmr_config_unpack_state + 2) !=
              '\0';
    }
    else {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

