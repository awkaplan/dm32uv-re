/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_status_display_adjust @ 030338d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_status_display_adjust(uint *param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = *PTR_DAT_03033938;
  if (uVar1 != 1) {
    if (*param_1 == 1) {
      if (*param_2 == 0) {
        *param_2 = uVar1 - 1;
        *param_1 = uVar1;
        if (8 < uVar1) {
          *param_1 = 8;
        }
      }
      else {
        *param_2 = *param_2 + -1;
      }
    }
    else {
      *param_2 = *param_2 + -1;
      *param_1 = *param_1 - 1;
    }
    range_count_status_display(*param_1,*param_2);
  }
  return;
}

