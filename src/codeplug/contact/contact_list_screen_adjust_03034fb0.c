/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_list_screen_adjust @ 03034fb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_list_screen_adjust(undefined1 param_1,short *param_2,short *param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)PTR_DAT_030350b4 == '\0') {
    uVar2 = 8;
  }
  else {
    uVar2 = 7;
  }
  uVar1 = contact_count_range_calc(param_1);
  if (uVar1 != 1) {
    if (*param_2 == 1) {
      if (*param_3 == 0) {
        *param_3 = (short)uVar1 + -1;
        *param_2 = (short)uVar1;
        if (uVar2 < uVar1) {
          *param_2 = (short)uVar2;
        }
      }
      else {
        *param_3 = *param_3 + -1;
      }
    }
    else {
      *param_3 = *param_3 + -1;
      *param_2 = *param_2 + -1;
    }
    contact_text_list_screen(param_1,*param_2,*param_3,uVar1);
  }
  return;
}

