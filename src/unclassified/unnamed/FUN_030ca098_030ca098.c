/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030ca098 @ 030ca098 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_030ca098(uint param_1,ushort param_2,short param_3)

{
  short sVar1;
  
  if (param_1 == 0) {
    sVar1 = (short)((uint)(((int)((uint)param_2 * 0xa000) >> 3) + 0xffff) >> 0x10) + -1;
    if (sVar1 < 0) {
      sVar1 = 0;
    }
    return sVar1;
  }
  if (param_1 < 4) {
    return *(short *)(_DAT_030ca0e4 + (((short)param_2 + -0x80) * 2 + (int)param_3) * 2) + -1;
  }
  return 0;
}

