/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_rx_control_state_update_from_status @ 030248fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_rx_control_state_update_from_status(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.RX_TYPE_INFO;
  if ((dVar1 & 0xc) == 8) {
    *(undefined1 *)p_dmr_call_config_state = 0;
  }
  else {
    *(undefined1 *)p_dmr_call_config_state = 1;
  }
  *(undefined1 *)((int)PTR_DAT_03024a84 + 1) = 1;
  control_reg_conditional_set_with_status_xor();
  return;
}

