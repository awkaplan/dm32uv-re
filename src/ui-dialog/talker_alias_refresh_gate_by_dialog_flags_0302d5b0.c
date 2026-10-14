/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talker_alias_refresh_gate_by_dialog_flags @ 0302d5b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talker_alias_refresh_gate_by_dialog_flags(void)

{
  byte bVar1;
  
  if (((((p_dialog_flags_from_flash->flags_0x1 & 3) != 1) ||
       (bVar1 = p_dialog_flags_from_flash->flags_0x1f & 0x78, bVar1 == 0x20)) || (bVar1 == 0x28)) &&
     ((*(byte *)p_dialog_flags_from_flash & 1) == 0)) {
    talker_alias_screen_refresh_by_call_state();
  }
  return;
}

