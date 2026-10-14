/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_teardown_on_event_flag @ 0305e220 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_teardown_on_event_flag(void)

{
  tx_ptt_ui_state *ptVar1;
  byte bVar2;
  
  bVar2 = get_event_flags_byte_dispatch(0xc);
  if ((bVar2 & 1) != 0) {
    update_event_flags_byte_dispatch(0xc,1);
    ptVar1 = p_tx_ptt_ui_state;
    p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfe;
    memset_bytes(&ptVar1->field_0x3f,0,0x20);
    memset_bytes(DAT_0305e308,0,0x20);
    memset_bytes(DAT_0305e30c,0,0x20);
    *p_call_active_flag = *p_call_active_flag & 0xfe;
    ptVar1->field_0x1 = 5;
    dialog_clear_flag_bit2_at_1_variant_0301f01c();
    if ((p_call_setup_sm_state->flags_0x18 & 8) != 0) {
      call_setup_sm_reset();
    }
  }
  return;
}

