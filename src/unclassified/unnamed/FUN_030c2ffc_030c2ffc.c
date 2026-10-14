/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c2ffc @ 030c2ffc (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c2ffc(void)

{
  undefined1 auStack_8 [4];
  
  FUN_030c0358(*PTR_OSTCBCurPtr_030c3170);
  radio_list_command_dispatch_jumptable(0,auStack_8);
  return;
}

