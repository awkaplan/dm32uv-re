/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: range_count_two_level_counter_increment @ 03033890 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void range_count_two_level_counter_increment(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*PTR_DAT_03033938 != 1) {
    iVar1 = *param_2;
    if (iVar1 == *PTR_DAT_03033938 + -1) {
      *param_2 = 0;
      *param_1 = 1;
    }
    else if (*param_1 == 8) {
      *param_2 = iVar1 + 1;
    }
    else {
      *param_2 = iVar1 + 1;
      *param_1 = *param_1 + 1;
    }
    range_count_status_display(*param_1,*param_2);
  }
  return;
}

