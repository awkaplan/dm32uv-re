/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSchedLock @ 00011190 (IRAM address; the boot stub copies these bytes from program flash 0x030c0db0)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSSchedLock(undefined4 *param_1)

{
  undefined4 sr;
  
  if (*PTR_OSIntNestingCtr_00011240 == '\0') {
    if (*PTR_DAT_00011244 == '\x01') {
      if ((byte)*PTR_OSSchedLockNestingCtr_00011238 < 0xfa) {
        sr = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        *PTR_OSSchedLockNestingCtr_00011238 = *PTR_OSSchedLockNestingCtr_00011238 + '\x01';
        OS_SchedLockTimeMeasStart_variant4();
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_1 = 0;
      }
      else {
        *param_1 = 0x5209;
      }
    }
    else {
      *param_1 = 0x5e89;
    }
  }
  else {
    *param_1 = 0x6d62;
  }
  return;
}

