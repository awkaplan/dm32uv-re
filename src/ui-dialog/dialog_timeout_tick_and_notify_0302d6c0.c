/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_timeout_tick_and_notify @ 0302d6c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_timeout_tick_and_notify(void)

{
  byte bVar1;
  
  if ((p_dialog_flags_from_flash->flags_0x1 & 4) != 0) {
    bVar1 = p_dialog_flags_from_flash->field_0x2 + 1;
    p_dialog_flags_from_flash->field_0x2 = bVar1;
    if (0x1e < bVar1) {
      if ((*(byte *)p_call_active_flag & 3) == 0) {
        ui_event_notify(0x15);
      }
      p_dialog_flags_from_flash->field_0x2 = 0;
    }
  }
  dialog_periodic_tick_state_dispatcher();
  return;
}

