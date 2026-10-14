/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c3d84 @ 030c3d84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c3d84(void)

{
  undefined4 *puVar1;
  
  vframe_message_poll_and_dispatch_3x();
  puVar1 = PTR_DAT_030c3da4;
  *PTR_DAT_030c3da4 = 0x180000a0;
  puVar1[1] = 0x18000000;
  return;
}

