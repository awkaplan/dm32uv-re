/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: radio_command_dispatcher @ 0001324c (IRAM address; the boot stub copies these bytes from program flash 0x030c2e6c)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_command_dispatcher(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  *param_2 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
                    /* WARNING: Could not recover jumptable at 0x00013270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(uint *)(iRam00013274 + (uint)*(byte *)(param_1 + 0x36) * 4) & 0xfffffffe))();
    return;
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  *param_2 = 0x6e2d;
  return;
}

