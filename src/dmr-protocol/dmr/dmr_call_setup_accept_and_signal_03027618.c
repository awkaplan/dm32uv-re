/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_accept_and_signal @ 03027618 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_setup_accept_and_signal(void)

{
  dmr_call_config_state *pdVar1;
  
  pdVar1 = p_dmr_call_config_state;
  if ((((uint)*PTR_DAT_03027670 >> 0x1a & 1) == 0) &&
     (PTR_DAT_03027674[6] == p_call_setup_sm_state_aux->field_0x5)) {
    *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
    pdVar1->field_0x3 = 1;
    p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xfd | 2;
    copy_bytes_from_offset_table(0,DAT_0302767c + (uint)*(byte *)pdVar1 * 0xc);
    OSFlagPost_wrapper_set_fixed_grp(1);
  }
  return;
}

