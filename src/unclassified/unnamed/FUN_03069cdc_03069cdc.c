/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03069cdc @ 03069cdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03069cdc(undefined4 *param_1)

{
  *param_1 = _DAT_03069dd0;
  param_1[1] = _DAT_03069dd4;
  param_1[8] = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 9) = 0x40;
  ucos3_pend_list_init(param_1 + 2);
  return;
}

