/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_control_char_and_reset @ 0305df58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_control_char_and_reset(void)

{
  dialog_flags_from_flash *pdVar1;
  
  if (((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) &&
     ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1)) {
    if ((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 8) {
      protocol_control_char_dispatch_backspace_wrapper();
    }
    if ((*(byte *)p_call_active_flag & 2) != 0) {
      protocol_control_char_dispatch_dialog_history(1);
    }
    *(undefined1 *)PTR_DAT_0305e028 = 0;
    pdVar1 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x30;
    pdVar1->field_0x30 = pdVar1->field_0x30 & 0xfe | 1;
    pdVar1->flags_0x2f = pdVar1->flags_0x2f & 0x8f;
    call_setup_sm_reset();
    ui_event_notify(0x19);
  }
  return;
}

