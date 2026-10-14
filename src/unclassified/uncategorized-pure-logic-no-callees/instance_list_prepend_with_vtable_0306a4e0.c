/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: instance_list_prepend_with_vtable @ 0306a4e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void instance_list_prepend_with_vtable(int param_1)

{
  int iVar1;
  
  *(undefined **)(param_1 + 0x1c) = PTR_LAB_0306a5b8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = *PTR_DAT_0306a5bc;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    *(int *)(param_1 + 0x18) = iVar1;
    *(int *)(iVar1 + 0x14) = param_1;
  }
  *PTR_DAT_0306a5bc = param_1;
  return;
}

