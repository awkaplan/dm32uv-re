/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: write_status_mode_byte_pair @ 03035ec4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void write_status_mode_byte_pair(int param_1__w,int param_2__w)

{
  byte param_1 = (byte)param_1__w;
  byte param_2 = (byte)param_2__w;
  dialog_history_ui_state *pdVar1;
  
  pdVar1 = p_dialog_history_ui_state;
  p_dialog_history_ui_state->field_0x3 = param_1;
  if (param_2 != 0) {
    pdVar1->field_0x4 = param_2;
  }
  return;
}

