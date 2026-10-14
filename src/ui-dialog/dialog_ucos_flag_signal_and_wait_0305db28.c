/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_ucos_flag_signal_and_wait @ 0305db28 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_ucos_flag_signal_and_wait(void)

{
  void *flaggrp;
  undefined1 auStack_c [4];
  
  p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xfe | 1;
  call_teardown_and_history_dispatch();
  flaggrp = p_ucos_flaggrp_0003fd90;
  OSFlagPend_wrapper_consume(p_ucos_flaggrp_0003fd90,0x10000,0,0,auStack_c);
  OSFlagPost_wrapper_clr(flaggrp,0x10000);
  return;
}

