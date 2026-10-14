/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_select_input_gate @ 0305ca0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_select_input_gate
               (undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5)

{
  if ((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) {
    channel_select_type_dispatch(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    ui_event_notify(0x1b);
  }
  return;
}

