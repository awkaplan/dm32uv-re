/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSchedUnlock @ 00011250 (IRAM address; the boot stub copies these bytes from program flash 0x030c0e70)
 * Size: 118 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSSchedUnlock(undefined4 *param_1)

{
  char cVar1;
  undefined4 sr;
  
  if (*PTR_OSIntNestingCtr_000113a4 == '\0') {
    if (*PTR_DAT_000113a8 == '\x01') {
      if (*PTR_OSSchedLockNestingCtr_000113ac == '\0') {
        *param_1 = 0x6d64;
      }
      else {
        sr = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_000113ac;
        *PTR_OSSchedLockNestingCtr_000113ac = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          OSSched();
          *param_1 = 0;
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_1 = 0x6d63;
        }
      }
    }
    else {
      *param_1 = 0x5e89;
    }
  }
  else {
    *param_1 = 0x6d65;
  }
  return;
}

