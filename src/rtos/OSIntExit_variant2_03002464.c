/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSIntExit_variant2 @ 03002464 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
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

void OSIntExit_variant2(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)PTR_LAB_00016d4c_1_030024dc == '\x01') {
    uVar2 = cpu_sr_save_and_disable_irq();
    cVar1 = *(char *)PTR_DAT_030024e0;
    if (cVar1 == '\0') {
      func_0x030020e4();
    }
    else {
      *(char *)PTR_DAT_030024e0 = cVar1 + -1;
      if (cVar1 == '\x01') {
        if (*(char *)PTR_LAB_030024e4 == '\0') {
          iVar3 = table_index_derive_from_element_count();
          *(char *)PTR_LAB_030024e8 = (char)iVar3;
          iVar3 = *(int *)(iVar3 * 0xc + _DAT_030024ec);
          *PTR_DAT_030024f0 = iVar3;
          if (iVar3 == *PTR_DAT_030024f4) {
            func_0x030020e4(uVar2);
          }
          else {
            *PTR_DAT_030024f8 = *PTR_DAT_030024f8 + 1;
            ucos3_int_highrdy_commit_variant2();
            func_0x030020e4(uVar2);
          }
        }
        else {
          func_0x030020e4();
        }
      }
      else {
        func_0x030020e4();
      }
    }
  }
  return;
}

