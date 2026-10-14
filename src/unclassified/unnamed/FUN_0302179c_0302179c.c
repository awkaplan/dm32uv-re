/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0302179c @ 0302179c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0302179c(int param_1)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.LAYER2_TXRX_CTRL;
  if (param_1 == 0) {
    dVar1 = dVar1 & 0xfffffffe;
  }
  else {
    dVar1 = dVar1 | 1;
  }
  SystemControl_Type_11000000.LAYER2_TXRX_CTRL = dVar1;
  return;
}

