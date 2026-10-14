/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_cursor_decrement_with_wrap @ 0303941c (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_cursor_decrement_with_wrap(ushort *param_1,short *param_2,int param_3__w)

{
  ushort param_3 = (ushort)param_3__w;
  if (*param_1 == 1) {
    if (*param_2 == 0) {
      *param_2 = param_3 - 1;
      *param_1 = param_3;
      if (8 < param_3) {
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
  return;
}

