/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_deferred_event_task_loop @ 03055574 (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_deferred_event_task_loop(void)

{
  void *flaggrp;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 auStack_24 [4];
  
  uVar2 = DAT_03055664;
  puVar1 = PTR_DAT_03055660;
  flaggrp = p_ucos_flaggrp_0003fd90;
  do {
    OSFlagPend_wrapper_consume(flaggrp,0x8000,0,0,auStack_24);
    OSFlagPost_wrapper_clr(flaggrp,0x8000);
    if ((*puVar1 & 0x20) != 0) {
      *puVar1 = *puVar1 & 0xffffffdf;
    }
    if ((*puVar1 & 2) != 0) {
      *puVar1 = *puVar1 & 0xfffffffd;
    }
    if ((*puVar1 & 4) != 0) {
      deferred_callback_pair_run_and_clear();
      *puVar1 = *puVar1 & 0xfffffffb;
    }
    if ((*puVar1 & 8) != 0) {
      request_display_refresh(0x10);
      *puVar1 = *puVar1 & 0xfffffff7;
    }
    if ((*puVar1 & 0x10) != 0) {
      ucos_tmr_del(uVar2,auStack_24);
      *puVar1 = *puVar1 & 0xffffffef;
    }
  } while( true );
}

