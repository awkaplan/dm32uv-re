/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7ce0 @ 030c7ce0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

bool FUN_030c7ce0(short *param_1,undefined2 *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  
  *param_1 = 0xff;
  sVar1 = *(short *)(param_3 + 10);
  if (sVar1 == 0xff) {
    sVar1 = *(short *)(param_3 + 0xc);
    if (sVar1 == 0xff) {
      return false;
    }
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  *param_1 = sVar1;
  *param_2 = *(undefined2 *)(param_3 + (iVar2 + 3) * 4 + 2);
  param_2[1] = *(undefined2 *)(param_3 + iVar2 * 4 + 0x10);
  return *param_1 != 0xff;
}

