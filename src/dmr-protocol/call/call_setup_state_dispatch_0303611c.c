/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_state_dispatch @ 0303611c (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_state_dispatch(void)

{
  int iVar1;
  
  if (PTR_DAT_03036214[9] == '\x05') {
    tx_gate_write_call_record(1);
    clear_field_bit3_and_set_dialog_bit();
  }
  else if (PTR_DAT_03036218[0x328] == '\x01') {
    PTR_DAT_0303621c[10] = PTR_DAT_0303621c[10] & 0xfe | 1;
    dialog_history_show_if_present();
  }
  else if ((PTR_DAT_03036214[0x5f] & 2) == 0) {
    if (((*(byte *)PTR_call_active_flag_03036220 & 3) == 0) &&
       (iVar1 = get_field_0301ea64_0x14(), iVar1 != 0)) {
      call_setup_sm_reset();
    }
    else if ((*(byte *)PTR_call_active_flag_03036220 & 0x14) == 0x10) {
      *(byte *)PTR_call_active_flag_03036220 = *(byte *)PTR_call_active_flag_03036220 & 0xef;
    }
    else if ((*(byte *)PTR_call_active_flag_03036220 & 0x28) == 0x20) {
      *(byte *)PTR_call_active_flag_03036220 = *(byte *)PTR_call_active_flag_03036220 & 0xdf;
    }
    else {
      tx_gate_write_call_record(0);
    }
  }
  else {
    PTR_DAT_03036214[2] = 0x1f;
  }
  write_status_mode_byte_pair(0x5b,0);
  return;
}

