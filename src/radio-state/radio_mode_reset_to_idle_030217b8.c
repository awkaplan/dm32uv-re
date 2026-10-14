/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_reset_to_idle @ 030217b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_reset_to_idle(void)

{
  modem_fm_ptt_set(0);
  SystemControl_Type_11000000.LAYER2_CONTROL = 0;
  SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0;
  SystemControl_Type_11000000.SYS_SOFT_RSTN = 0xfffffffc;
  return;
}

