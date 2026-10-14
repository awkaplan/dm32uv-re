/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_load_synchronized @ 0305813c (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_load_synchronized(undefined2 param_1,undefined1 param_2)

{
  void *flaggrp;
  undefined1 auStack_14 [4];
  
  radio_mode_dispatcher_char(0,0);
  flaggrp = p_ucos_flaggrp_0003fd90;
  OSFlagPend_wrapper_consume(p_ucos_flaggrp_0003fd90,0x20,0,0,auStack_14);
  OSFlagPost_wrapper_clr(flaggrp,0x20);
  dialog_flags_clear_for_channel_sync();
  channel_change_apply_dispatcher(param_1,param_2);
  radio_mode_dispatcher_char(1,0);
  return;
}

