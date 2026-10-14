/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_forbid_flag_clear @ 0301d92c (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_forbid_flag_clear(void)

{
  void *flaggrp;
  undefined1 auStack_c [4];
  
  flaggrp = p_ucos_flaggrp_0003fd90;
  OSFlagPend_wrapper_consume(p_ucos_flaggrp_0003fd90,0x80,0,0,auStack_c);
  OSFlagPost_wrapper_clr(flaggrp,0x80);
  return;
}

