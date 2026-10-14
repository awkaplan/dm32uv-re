/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskSuspend @ 000137f4 (IRAM address; the boot stub copies these bytes from program flash 0x030c3414)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskSuspend(undefined *param_1,undefined4 *param_2)

{
  if (param_1 == PTR_DAT_00013840) {
    *param_2 = 0x715b;
  }
  else if (param_1 == PTR_OSIntQTaskTCB_00013844) {
    *param_2 = 0x715c;
  }
  else if (*PTR_OSIntNestingCtr_00013848 == '\0') {
    active_command_subcommand_dispatcher();
  }
  else {
    ucos3_message_queue_post_with_overflow_check(uRam0001384c,param_1,0,0,0,0,0,param_2);
  }
  return;
}

