/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_post_checked_isr_aware @ 030c2dec (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
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

void event_post_checked_isr_aware
               (undefined4 param_1,undefined4 param_2,undefined2 param_3,ushort param_4,
               undefined4 *param_5)

{
  undefined4 uVar1;
  
  if (param_4 == 0x10) {
LAB_030c2e20:
    uVar1 = func_0x0611caf4();
    if (*(char *)PTR_OSIntNestingCtr_030c2e64 == '\0') {
      OS_TaskQPost(param_1,param_2,param_3,param_4,uVar1,param_5);
    }
    else {
      bounded_queue_append_with_dropcount
                (_DAT_030c2e68,param_1,param_2,param_3,0,param_4,uVar1,param_5);
    }
  }
  else {
    if (param_4 < 0x11) {
      if (param_4 == 0) goto LAB_030c2e20;
    }
    else if ((param_4 == 0x8000) || (param_4 == 0x8010)) goto LAB_030c2e20;
    *param_5 = 0x5e25;
  }
  return;
}

