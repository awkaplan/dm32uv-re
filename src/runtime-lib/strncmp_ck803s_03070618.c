/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strncmp_ck803s @ 03070618 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int strncmp_ck803s(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = param_1 + param_3;
  while( true ) {
    if (pbVar2 <= param_1) {
      return 0;
    }
    iVar1 = (uint)*param_1 - (uint)*param_2;
    if (iVar1 != 0) break;
    if (*param_1 == 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return iVar1;
}

