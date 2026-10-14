/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_name_field_refresh_dispatch @ 0302ce90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_name_field_refresh_dispatch(void)

{
  byte bVar1;
  
  p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf;
  if ((p_dialog_flags_from_flash->flags_0x1e & 0xf) == 2) {
    call_dialog_field_progress_and_timeout();
  }
  else {
    contact_field_name_display_dispatch();
  }
  bVar1 = p_dialog_flags_from_flash->flags_0x1d >> 1;
  if ((p_dialog_flags_from_flash->flags_0x1d >> 4 & 7) != (bVar1 & 7)) {
    p_dialog_flags_from_flash->flags_0x1d =
         p_dialog_flags_from_flash->flags_0x1d & 0x8f | (bVar1 & 7) << 4;
  }
  return;
}

