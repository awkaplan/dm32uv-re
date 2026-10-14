/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c68c4 @ 030c68c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c68c4(int param_1,int param_2)

{
  array_copy_u16(param_1 + 0x614,param_2,0xe);
  *(undefined4 *)(param_1 + 0x630) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(param_1 + 0x634) = *(undefined2 *)(param_2 + 0x20);
  array_copy_u16(param_1 + 0x636,param_2 + 0x22,7);
  *(undefined2 *)(param_1 + 0x644) = *(undefined2 *)(param_2 + 0x30);
  *(undefined2 *)(param_1 + 0x646) = *(undefined2 *)(param_2 + 0x32);
  return;
}

