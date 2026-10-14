/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskResume @ 00013368 (IRAM address; the boot stub copies these bytes from program flash 0x030c2f88)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskResume(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  if ((param_1 == 0) || (param_1 == *(int *)PTR_OSTCBCurPtr_000133d0)) {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    *param_2 = 0x7157;
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    if (*PTR_OSIntNestingCtr_000133d4 == '\0') {
      radio_command_dispatcher(param_1,param_2);
    }
    else {
      ucos3_message_queue_post_with_overflow_check(uRam000133d8,param_1,0,0,0,0,0,param_2);
    }
  }
  return;
}

