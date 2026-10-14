/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_Pend_variant2 @ 030c0fdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_Pend_variant2(int param_1,int param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *PTR_OSTCBCurPtr_030c1188;
  *(undefined1 *)(iVar1 + 0x34) = param_3;
  *(undefined1 *)(iVar1 + 0x35) = 0;
  OS_TaskBlock(iVar1,param_4);
  if (param_2 == 0) {
    iVar1 = *PTR_OSTCBCurPtr_030c1188;
    *(undefined2 *)(iVar1 + 0x3e) = 0;
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  else {
    *(int *)(param_1 + 0xc) = param_2;
    owner_slot_array_init_b(*PTR_OSTCBCurPtr_030c1188,param_1,1);
    pend_list_insert_by_prio_b(param_2 + 8,param_1);
  }
  FUN_030c0754(param_2,*PTR_OSTCBCurPtr_030c1188);
  return;
}

