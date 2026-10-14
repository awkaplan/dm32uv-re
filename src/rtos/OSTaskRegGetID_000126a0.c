/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskRegGetID @ 000126a0 (IRAM address; the boot stub copies these bytes from program flash 0x030c22c0)
 * Size: 66 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool OSTaskRegGetID(undefined4 *param_1)

{
  char cVar1;
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_DAT_000127ac;
  if (cVar1 == '\0') {
    *PTR_DAT_000127ac = 1;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    *param_1 = 0;
  }
  else {
    *param_1 = 0x59da;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
  }
  return cVar1 != '\0';
}

