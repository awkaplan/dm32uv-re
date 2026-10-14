/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_teardown_and_history_dispatch @ 0305baa8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_teardown_and_history_dispatch(void)

{
  *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xbf;
  if ((PTR_DAT_0305bbf0[5] & 1) != 0) {
    PTR_DAT_0305bbf0[5] = PTR_DAT_0305bbf0[5] & 0xfe;
    call_setup_sm_reset();
    if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
      vfo_sync_active_side_on_ptt();
    }
  }
  protocol_control_char_dispatch_dialog_history(1);
  return;
}

