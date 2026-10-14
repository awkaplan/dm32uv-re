/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: line_buffer_pump_loop @ 03011824 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void line_buffer_pump_loop(void)

{
  void *flaggrp;
  undefined1 *puVar1;
  undefined1 auStack_1c [4];
  
  puVar1 = PTR_DAT_0301199c;
  flaggrp = DAT_03011998;
  do {
    OSFlagPend_wrapper_consume(flaggrp,0x100000,0,0,auStack_1c);
    OSFlagPost_wrapper_clr(flaggrp,0x100000);
    circular_line_buffer_char_append();
    *puVar1 = *puVar1 & 0xdf;
  } while( true );
}

