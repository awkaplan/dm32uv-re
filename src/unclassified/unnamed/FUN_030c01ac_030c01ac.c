/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c01ac @ 030c01ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_030c01ac(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0 && param_2 == 0) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = FUN_030c0054(param_1 & -param_1,param_2 & -(param_1 == 0 ^ 1) - param_2);
    iVar1 = 0x3f - iVar1;
  }
  return iVar1;
}

