/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_abort_reset @ 0300e360 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_abort_reset(void)

{
  uint uVar1;
  
  if ((*(byte *)p_call_active_flag & 4) != 0) {
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfb;
    uVar1 = get_current_mode_state1();
    if (2 < uVar1) {
      PTR_DAT_0300e3f8[3] = PTR_DAT_0300e3f8[3] & 0xbf;
    }
    if (p_radio_mode_state_0003e318[1].flags_0x2 == 0) {
      status_byte_bit5_set_clear_wrapper(0,1);
      fd6818b_reg47_afout_clear_mode();
      audio_pa_enable_gate(0);
    }
    PTR_DAT_0300e3fc[6] = 0;
  }
  return;
}

