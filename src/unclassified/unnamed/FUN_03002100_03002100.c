/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03002100 @ 03002100 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_03002100(void)

{
  undefined4 uVar1;
  
  cpu_sr_save_and_disable_irq();
  uVar1 = *PTR_LAB_03002118;
  func_0x030020e4();
  FUN_030020ec(uVar1);
  return;
}

