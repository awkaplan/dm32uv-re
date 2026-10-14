/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: padded_block_total_size_with_overflow_guard @ 0306b960 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint padded_block_total_size_with_overflow_guard
               (uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = param_1 - param_4 * (param_1 / param_4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_4 - iVar1;
  }
  iVar1 = param_3 - param_4 * (param_3 / param_4);
  if (iVar1 == 0) {
    param_4 = 0;
  }
  else {
    param_4 = param_4 - iVar1;
  }
  uVar4 = uVar2 + param_3;
  if (uVar4 < uVar2) {
    uVar2 = 0;
  }
  else if (uVar4 < param_3) {
    uVar2 = 0;
  }
  else {
    uVar5 = param_4 + param_3;
    uVar3 = uVar5 * (param_2 - 1);
    uVar2 = uVar3 + uVar4;
    if (1 < param_2) {
      if (uVar5 < param_4) {
        uVar2 = 0;
      }
      else if (uVar5 < param_3) {
        uVar2 = 0;
      }
      else if (uVar3 < uVar5) {
        uVar2 = 0;
      }
      else if (uVar3 < param_4) {
        uVar2 = 0;
      }
      else if (uVar3 < param_3) {
        uVar2 = 0;
      }
      else {
        uVar5 = uVar3 + param_3;
        if (uVar5 < uVar3) {
          uVar2 = 0;
        }
        else if (uVar5 < param_3) {
          uVar2 = 0;
        }
        else if (uVar2 < uVar4) {
          uVar2 = 0;
        }
        else if (uVar2 < uVar3) {
          uVar2 = 0;
        }
        else if (uVar2 < uVar5) {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}

