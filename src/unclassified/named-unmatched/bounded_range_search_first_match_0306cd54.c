/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bounded_range_search_first_match @ 0306cd54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int bounded_range_search_first_match(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      param_1 = 0;
    }
    else if (param_3 == 0) {
      param_1 = 0;
    }
    else {
      if (param_3 == -1) {
        iVar4 = -1;
      }
      else {
        iVar4 = param_3 + 1;
      }
      uVar2 = strnlen_impl(param_1,param_3);
      uVar3 = strnlen_impl(param_2,iVar4);
      if (uVar3 != 0) {
        if (uVar2 < uVar3) {
          param_1 = 0;
        }
        else if (param_1 + uVar2 == 0) {
          param_1 = 0;
        }
        else if (param_2 + uVar3 == 0) {
          param_1 = 0;
        }
        else {
          uVar5 = 0;
          do {
            sVar1 = strncmp_impl(param_1 + uVar5,param_2,uVar3);
            if (sVar1 == 0) {
              return param_1 + uVar5;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 <= uVar2 - uVar3);
          param_1 = 0;
        }
      }
    }
  }
  return param_1;
}

