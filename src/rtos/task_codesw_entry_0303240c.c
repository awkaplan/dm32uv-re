/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: task_codesw_entry @ 0303240c (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void task_codesw_entry(void)

{
  void *flaggrp;
  undefined1 auStack_18 [4];
  
  flaggrp = DAT_030324e4;
  do {
    OSFlagPend_wrapper_consume(flaggrp,8,0,0,auStack_18);
    OSFlagPost_wrapper_clr(flaggrp,8);
    channel_switch_and_screen_refresh();
  } while( true );
}

