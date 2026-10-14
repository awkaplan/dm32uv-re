/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talker_alias_screen_refresh_by_call_state @ 0302c27c (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talker_alias_screen_refresh_by_call_state(void)

{
  tx_ptt_ui_state *ptVar1;
  
  ptVar1 = p_tx_ptt_ui_state;
  if ((*(byte *)p_call_active_flag & 1) == 0) {
    if ((*(byte *)p_call_active_flag & 2) == 0) {
      if (PTR_DAT_0302c390[0x4b0] != '\0') {
        p_tx_ptt_ui_state->field_0x4 = 0;
        ptVar1->flags_0xa = ptVar1->flags_0xa & 0x7f | 0x80;
        PTR_DAT_0302c390[0x4b0] = 0;
      }
    }
    else if (PTR_DAT_0302c390[0x4b0] != '\x02') {
      talker_alias_info_screen();
      PTR_DAT_0302c390[0x4b0] = 2;
    }
  }
  else if (PTR_DAT_0302c390[0x4b0] != '\x01') {
    talker_alias_info_screen();
    PTR_DAT_0302c390[0x4b0] = 1;
  }
  return;
}

