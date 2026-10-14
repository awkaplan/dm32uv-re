/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSStart @ 030c0624 (file base 0x03000000; code starts at 0x03001000)
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

void OSStart(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_DAT_030c0720 == '\0') {
    iVar1 = OS_PrioGetHighest_variant2();
    *(char *)PTR_OSPrioHighRdy_030c0724 = (char)iVar1;
    *(char *)PTR_DAT_030c0728 = (char)iVar1;
    uVar2 = *(undefined4 *)(iVar1 * 0xc + _DAT_030c072c);
    *PTR_OSTCBHighRdyPtr_030c0730 = uVar2;
    *PTR_OSTCBCurPtr_030c0734 = uVar2;
    *(undefined1 *)PTR_DAT_030c0720 = 1;
    FUN_030c01d8();
    *param_1 = 0x3a99;
  }
  else {
    *param_1 = 0x5e8a;
  }
  return;
}

