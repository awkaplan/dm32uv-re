/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: active_command_subcommand_dispatcher @ 000136c8 (IRAM address; the boot stub copies these bytes from program flash 0x030c32e8)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void active_command_subcommand_dispatcher(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  if (param_1 == 0) {
    param_1 = *piRam0001371c;
  }
  else if (param_1 != *piRam0001371c) goto LAB_00013704;
  if (*pcRam00013720 != '\0') {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    *param_2 = 0x6d63;
    return;
  }
LAB_00013704:
  *param_2 = 0;
  if (7 < *(byte *)(param_1 + 0x36)) {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    *param_2 = 0x6e2d;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013718. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(uint *)(iRam00013724 + (uint)*(byte *)(param_1 + 0x36) * 4) & 0xfffffffe))();
  return;
}

