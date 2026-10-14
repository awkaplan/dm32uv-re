/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: argmax_index_int32_array @ 030ca8bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

short argmax_index_int32_array(int *param_1,short param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = *param_1;
  if (1 < param_2) {
    sVar1 = 0;
    sVar2 = 1;
    do {
      param_1 = param_1 + 1;
      sVar4 = sVar2 + 1;
      if (iVar3 < *param_1) {
        iVar3 = *param_1;
        sVar1 = sVar2;
      }
      sVar2 = sVar4;
    } while (sVar4 != param_2);
    return sVar1;
  }
  return 0;
}

