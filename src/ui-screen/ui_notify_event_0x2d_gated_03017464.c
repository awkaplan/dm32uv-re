/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_notify_event_0x2d_gated @ 03017464 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_notify_event_0x2d_gated(void)

{
  int iVar1;
  
  if ((((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) &&
      (iVar1 = poll_condition_group(0x17), iVar1 != 0)) && (iVar1 = FUN_0301d72c(), iVar1 == 0)) {
    ui_event_notify(0x2d);
  }
  return;
}

