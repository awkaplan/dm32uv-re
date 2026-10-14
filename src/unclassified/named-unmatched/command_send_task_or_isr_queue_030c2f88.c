/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: command_send_task_or_isr_queue @ 030c2f88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
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

void command_send_task_or_isr_queue(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  if ((param_1 == 0) || (param_1 == *PTR_OSTCBCurPtr_030c2ff0)) {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_2 = 0x7157;
  }
  else {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    if (*(char *)PTR_OSIntNestingCtr_030c2ff4 == '\0') {
      command_jump_table_dispatch(param_1,param_2);
    }
    else {
      bounded_queue_append_with_dropcount(_DAT_030c2ff8,param_1,0,0,0,0,0,param_2);
    }
  }
  return;
}

