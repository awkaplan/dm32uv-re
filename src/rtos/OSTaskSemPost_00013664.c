/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskSemPost @ 00013664 (IRAM address; the boot stub copies these bytes from program flash 0x030c3284)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 OSTaskSemPost(undefined4 param_1,short param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == -0x8000)) {
    uVar1 = func_0x0306ced4();
    if (*PTR_OSIntNestingCtr_000136c0 == '\0') {
      uVar1 = OS_TaskSemPost(param_1,param_2,uVar1,param_3);
    }
    else {
      ucos3_message_queue_post_with_overflow_check(uRam000136c4,param_1,0,0,0,0,uVar1,param_3);
      uVar1 = 0;
    }
  }
  else {
    *param_3 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

