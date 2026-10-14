/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_notify_0x22_on_bit3_set_and_bit1_clear @ 0305d984 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_notify_0x22_on_bit3_set_and_bit1_clear(void)

{
  if (((p_dialog_flags_from_flash->flags_0x2d & 8) != 0) && ((*(byte *)PTR_DAT_0305dab8 & 2) == 0))
  {
    ui_event_notify(0x22);
  }
  return;
}

