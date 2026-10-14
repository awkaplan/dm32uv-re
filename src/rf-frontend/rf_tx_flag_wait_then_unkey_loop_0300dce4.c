/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_tx_flag_wait_then_unkey_loop @ 0300dce4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_tx_flag_wait_then_unkey_loop(void)

{
  void *flaggrp;
  undefined1 *puVar1;
  undefined1 auStack_1c [4];
  
  puVar1 = PTR_DAT_0300de00;
  flaggrp = _DAT_0300ddfc;
  do {
    do {
      OSFlagPend_wrapper_consume(flaggrp,0x200,0,0,auStack_1c);
      OSFlagPost_wrapper_clr(flaggrp,0x200);
    } while ((*puVar1 & 1) == 0);
    rf_tx_disable_sequence();
  } while( true );
}

