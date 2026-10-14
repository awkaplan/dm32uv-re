/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_code_best_of4_score_argmax @ 030c73d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_code_best_of4_score_argmax(int *param_1,short *param_2,int param_3,short *param_4)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  sVar3 = 0;
  iVar5 = 0;
  sVar4 = 0;
  do {
    iVar1 = ones_complement_checksum_32word(param_3 + *param_4 * 4,5);
    sVar2 = sVar4 + 1;
    param_4 = param_4 + 1;
    if (iVar5 <= iVar1) {
      iVar5 = iVar1;
      sVar3 = sVar4;
    }
    sVar4 = sVar2;
  } while (sVar2 != 4);
  *param_1 = iVar5;
  *param_2 = sVar3;
  return;
}

