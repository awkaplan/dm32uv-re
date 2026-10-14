/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_event_post_or_queue_isr_aware @ 030c3284 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 ucos_event_post_or_queue_isr_aware(undefined4 param_1,short param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == -0x8000)) {
    uVar1 = func_0x0611caf4();
    if (*(char *)PTR_OSIntNestingCtr_030c32e0 == '\0') {
      uVar1 = OS_TaskSemPost_variant3(param_1,param_2,uVar1,param_3);
    }
    else {
      bounded_queue_append_with_dropcount(_DAT_030c32e4,param_1,0,0,0,0,uVar1,param_3);
      uVar1 = 0;
    }
  }
  else {
    *param_3 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

