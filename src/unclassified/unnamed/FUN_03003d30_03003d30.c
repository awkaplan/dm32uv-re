/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03003d30 @ 03003d30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_03003d30(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  if (param_1 == 5) {
    if (iRam03000000 == _DAT_03003e90) {
      *param_4 = 0;
    }
    else {
      *param_4 = 0xff;
    }
  }
  return 0;
}

