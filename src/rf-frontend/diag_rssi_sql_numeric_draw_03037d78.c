/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: diag_rssi_sql_numeric_draw @ 03037d78 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void diag_rssi_sql_numeric_draw(int param_1__w,int param_2__w)

{
  char param_1 = (char)param_1__w;
  undefined2 param_2 = (undefined2)param_2__w;
  undefined1 auStack_20 [20];
  
  display_fill_rect(0,0xa0,0xf0,0x122,0);
  if (p_dialog_history_ui_state->field_0xa09 == 0x49) {
    if (param_1 == '\x02') {
      number_to_string_format_2args(auStack_20,PTR_s_SQL__d_03037ea8,param_2);
    }
    else {
      number_to_string_format_2args(auStack_20,PTR_s_RSSI__d_03037eac,param_2);
    }
  }
  else {
    number_to_string_format_2args(auStack_20,PTR_LAB_03037eb0,param_2);
  }
  display_draw_number_centered(0xa0,0xffff,0,(uint)auStack_20);
  return;
}

