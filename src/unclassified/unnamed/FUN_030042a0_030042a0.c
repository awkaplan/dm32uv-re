/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030042a0 @ 030042a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

bool FUN_030042a0(undefined1 *param_1)

{
  bool bVar1;
  dword dVar2;
  
  dVar2 = UART0_14030000.LSR;
  bVar1 = (dVar2 & 1) != 0;
  if (bVar1) {
    dVar2 = UART0_14030000.RBR_THR_DLL;
    *param_1 = (char)dVar2;
  }
  return bVar1;
}

