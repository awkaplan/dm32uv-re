/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: irq_controller_unmask_and_register_handler @ 0306cf70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void irq_controller_unmask_and_register_handler(int param_1,int param_2)

{
  uint uVar1;
  dword dVar2;
  undefined4 uStack_10;
  
  if ((param_1 != 0) && (0x1f < param_2)) {
    FUN_0306cf38(param_2 - 0x20U,param_1);
    func_0x0002e1c0(&uStack_10);
    if (param_2 < 0x40) {
      dVar2 = PIC_Type_17000000.PIC_MASK;
      uVar1 = param_2 - 0x20U & 0x3f;
      PIC_Type_17000000.PIC_MASK = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & dVar2;
    }
    else {
      dVar2 = PIC_Type_17000000.PIC_MASK_1;
      uVar1 = param_2 - 0x40U & 0x3f;
      PIC_Type_17000000.PIC_MASK_1 = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & dVar2;
    }
    FUN_0002e1cc(uStack_10);
  }
  return;
}

