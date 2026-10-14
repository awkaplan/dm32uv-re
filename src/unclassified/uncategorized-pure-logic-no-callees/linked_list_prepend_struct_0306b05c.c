/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: linked_list_prepend_struct @ 0306b05c (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void linked_list_prepend_struct(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  iVar1 = *PTR_DAT_0306b190;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    *(int *)(param_1 + 0x30) = iVar1;
    *(int *)(iVar1 + 0x2c) = param_1;
  }
  *PTR_DAT_0306b190 = param_1;
  return;
}

