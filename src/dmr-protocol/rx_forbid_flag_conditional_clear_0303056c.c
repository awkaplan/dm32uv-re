/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rx_forbid_flag_conditional_clear @ 0303056c (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rx_forbid_flag_conditional_clear(void)

{
  void *flaggrp;
  undefined1 auStack_c [4];
  
  if ((p_radio_mode_state_0003e318->flags_0x7 & 1) != 0) {
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0x7f | 0x80;
    flaggrp = p_ucos_flaggrp_0003fd90;
    OSFlagPend_wrapper_consume(p_ucos_flaggrp_0003fd90,0x80000,0,0,auStack_c);
    OSFlagPost_wrapper_clr(flaggrp,0x80000);
  }
  return;
}

