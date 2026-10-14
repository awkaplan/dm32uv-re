/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_timer_ensure_valid_or_recreate_wrapper @ 0300c6e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_timer_ensure_valid_or_recreate_wrapper(undefined4 param_1)

{
  timer_state_ensure_valid_or_recreate
            (PTR_protocol_frame_periodic_timer_state_machine_thunk_0300c77c,param_1,DAT_0300c780);
  return;
}

