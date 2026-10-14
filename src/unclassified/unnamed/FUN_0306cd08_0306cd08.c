/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0306cd08 @ 0306cd08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

char * FUN_0306cd08(char *param_1,char param_2,char param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  
  if (param_1 != (char *)0x0) {
    if (param_4 == 0) {
      param_1 = (char *)0x0;
    }
    else {
      cVar2 = *param_1;
      pcVar1 = param_1;
      if (cVar2 != '\0') {
        do {
          if (cVar2 == param_2) {
            *pcVar1 = param_3;
          }
          pcVar1 = pcVar1 + 1;
        } while (((pcVar1 != (char *)0x0) && (cVar2 = *pcVar1, cVar2 != '\0')) &&
                (param_4 = param_4 + -1, param_4 != 0));
      }
    }
  }
  return param_1;
}

