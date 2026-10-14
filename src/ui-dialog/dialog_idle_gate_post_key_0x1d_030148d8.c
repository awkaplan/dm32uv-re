/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_idle_gate_post_key_0x1d @ 030148d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_idle_gate_post_key_0x1d(void)

{
  if ((PTR_DAT_030149e8[8] & 1) == 0) {
    if ((*(byte *)PTR_DAT_030149ec & 0x12) == 0x10) {
      if (((*(byte *)PTR_DAT_030149f0 & 1) != 0) && (PTR_DAT_030149f4[1] == '\0')) {
        dialog_idle_ready_state_trigger();
      }
      clear_field_flag_if_setting0xf_and_empty();
      dialog_clear_flag_bit2_at_1();
      if ((*(byte *)PTR_DAT_030149f8 & 4) == 0) {
        if ((*(byte *)PTR_DAT_030149e4 & 4) == 0) {
          if (PTR_DAT_030149fc[1] == '\0') {
            keypad_tmrkey_event_post_and_close(0x1d);
          }
        }
        else {
          refresh_display_or_call_03015b24(1);
        }
      }
      else {
        refresh_display_or_call_03015ad8(1);
      }
    }
    else if ((*(byte *)((int)PTR_DAT_030149ec + 2) & 8) == 0) {
      *(byte *)PTR_DAT_030149ec = *(byte *)PTR_DAT_030149ec & 0xfd | 2;
    }
  }
  return;
}

