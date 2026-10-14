/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_contact_select_index_advance @ 03034e98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_contact_select_index_advance(undefined1 param_1,short *param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  
  if (*(char *)PTR_DAT_03034f50 == '\0') {
    sVar3 = 8;
  }
  else {
    sVar3 = 7;
  }
  iVar2 = contact_count_range_calc(param_1);
  uVar1 = *param_3;
  if ((uint)uVar1 == (iVar2 + 1U & 0xffff) - 1) {
    *param_3 = 0;
    *param_2 = 1;
  }
  else if (*param_2 == sVar3) {
    *param_3 = uVar1 + 1;
  }
  else {
    *param_3 = uVar1 + 1;
    *param_2 = *param_2 + 1;
  }
  tx_contact_select_screen(param_1,*param_2,*param_3);
  return;
}

