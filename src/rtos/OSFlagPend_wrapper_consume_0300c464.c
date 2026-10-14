/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSFlagPend_wrapper_consume @ 0300c464 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void OSFlagPend_wrapper_consume(void *flaggrp,uint flags,int consume,uint timeout,void *out_err)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  
  uVar1 = 0x104;
  if (consume == 0) {
    uVar1 = 0x108;
  }
  OSFlagPend(flaggrp,flags,timeout,uVar1,auStack_8,out_err);
  return;
}

