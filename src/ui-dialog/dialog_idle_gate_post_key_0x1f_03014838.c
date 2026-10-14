/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_idle_gate_post_key_0x1f @ 03014838 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_idle_gate_post_key_0x1f(void)

{
  if ((((*(byte *)PTR_DAT_03014898 & 0x12) == 0x10) && ((PTR_DAT_0301489c[8] & 1) == 0)) &&
     (PTR_DAT_030148b0[1] == '\0')) {
    if (((*(byte *)PTR_DAT_030148a0 & 1) != 0) && (PTR_DAT_030148a4[1] == '\0')) {
      dialog_idle_ready_state_trigger();
    }
    if ((*(byte *)PTR_call_active_flag_030148b4 & 8) == 0) {
      clear_field_flag_if_setting0xf_and_empty();
      if ((*(byte *)PTR_DAT_030148a8 & 1) == 0) {
        if ((*(byte *)PTR_DAT_030149e4 & 1) == 0) {
          dialog_clear_flag_bit2_at_1();
          keypad_tmrkey_event_post_and_close(0x1f);
        }
        else {
          refresh_display_or_call_03015b24(1);
        }
      }
      else {
        refresh_display_or_call_03015ad8(1);
      }
    }
  }
  return;
}

