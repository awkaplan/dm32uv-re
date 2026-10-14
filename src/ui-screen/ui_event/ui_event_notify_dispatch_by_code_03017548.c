/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_notify_dispatch_by_code @ 03017548 (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_event_notify_dispatch_by_code(char param_1)

{
  int iVar1;
  byte bVar2;
  
  if (param_1 == '\x01') {
    bVar2 = 1;
  }
  else {
    bVar2 = ~(param_1 != '\x03');
  }
  if (((p_tx_ptt_ui_state->flags_0xa & 0x30) == 0x10) || (bVar2 == 0)) {
    ui_event_notify(0x21);
  }
  else {
    iVar1 = poll_condition_group(0x19);
    if (iVar1 != 0) {
      if ((p_radio_mode_state_0003e318[1].flags_0x3 & 2) == 0) {
        sysctl_bit8_toggle_with_mode_flag(1);
        ui_event_notify(0x18);
      }
      else {
        sysctl_bit8_toggle_with_mode_flag(0);
        ui_event_notify(0x19);
      }
      if ((*(char *)PTR_DAT_030177c0 == '\0') || (*(char *)PTR_DAT_030177c0 == '[')) {
        display_draw_status_bar();
      }
    }
  }
  return;
}

