/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030ca778 @ 030ca778 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030ca778(short *param_1,short *param_2,int param_3,uint param_4)

{
  short sVar1;
  
  if (0 < param_3) {
    if (param_4 == 0) {
      do {
        param_3 = param_3 + -1;
        *param_1 = *param_2;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      } while (0 < param_3);
      return;
    }
    if ((int)param_4 < 0) {
      if ((int)param_4 < 0) {
        param_4 = ~param_4 + 1;
      }
      do {
        sVar1 = *param_2;
        param_3 = param_3 + -1;
        param_2 = param_2 + 1;
        *param_1 = (short)((int)sVar1 >> (param_4 & 0x3f));
        param_1 = param_1 + 1;
      } while (0 < param_3);
      return;
    }
    do {
      sVar1 = *param_2;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      *param_1 = (short)((int)sVar1 << (param_4 & 0x3f));
      param_1 = param_1 + 1;
    } while (0 < param_3);
  }
  return;
}

