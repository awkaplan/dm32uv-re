/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lazy_device_descriptor_init_once @ 0300256c (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void lazy_device_descriptor_init_once(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_LAB_00016d4c_1_030025b0 == '\0') {
    iVar1 = table_index_derive_from_element_count();
    *(char *)PTR_LAB_030025b4 = (char)iVar1;
    *(char *)PTR_LAB_00016db4_1_030025b8 = (char)iVar1;
    uVar2 = *(undefined4 *)(iVar1 * 0xc + _DAT_030025bc);
    *PTR_DAT_030025c0 = uVar2;
    *PTR_DAT_030025c4 = uVar2;
    *(undefined1 *)PTR_LAB_00016d4c_1_030025b0 = 1;
    FUN_03002210();
    *param_1 = 0x3a99;
  }
  else {
    *param_1 = 0x5e8a;
  }
  return;
}

