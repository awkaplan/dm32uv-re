/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_channel_step_on_key_event @ 03015d0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_channel_step_on_key_event(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  
  if ((((PTR_DAT_03015dd0[3] & 0x40) == 0) && (iVar2 = call_state_not_idle_check(), iVar2 == 0)) &&
     (iVar2 = read_byte_field_0302e118(), iVar2 == 0)) {
    iVar2 = poll_condition_group(0x22);
    if (iVar2 == 0) {
      ui_event_notify(0x21);
    }
    else {
      iVar2 = tx_is_inhibited();
      if ((iVar2 == 0) && ((PTR_DAT_03015dd0[0x10] & 0x80) == 0)) {
        mode_transition_cleanup();
        cVar1 = vfo_active_side_mode_nibble();
        iVar2 = value_at_or_above_low_bound_check(*PTR_DAT_03015dd8);
        if (iVar2 == 0) {
          bVar3 = cVar1 + 1;
          if (3 < bVar3) {
            bVar3 = 0;
          }
          ui_event_notify(0x1d);
          vfo_field_write_nibble_high(bVar3);
          ui_event_notify_alt(8);
          if (*(char *)PTR_DAT_03015ddc == '\0') {
            vfo_standby_row_render((byte)PTR_DAT_03015dc8[0x2d] >> 7);
          }
        }
        else {
          ui_event_notify(0x21);
        }
      }
      else {
        ui_event_notify(0x21);
      }
    }
  }
  return;
}

