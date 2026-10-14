/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_select_screen_adjust @ 03034ef0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_select_screen_adjust(undefined1 param_1,ushort *param_2,short *param_3)

{
  short sVar1;
  ushort uVar2;
  
  if (*(char *)PTR_DAT_03034f50 == '\0') {
    uVar2 = 8;
  }
  else {
    uVar2 = 7;
  }
  sVar1 = contact_count_range_calc(param_1);
  if (*param_2 == 1) {
    if (*param_3 == 0) {
      *param_3 = sVar1;
      *param_2 = sVar1 + 1U;
      if (uVar2 < (ushort)(sVar1 + 1U)) {
        *param_2 = uVar2;
      }
    }
    else {
      *param_3 = *param_3 + -1;
    }
  }
  else {
    *param_3 = *param_3 + -1;
    *param_2 = *param_2 - 1;
  }
  tx_contact_select_screen(param_1,*param_2,*param_3);
  return;
}

