/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTimeDlyResume_dly_suspended_arm @ 00014046 (IRAM address; the boot stub copies these bytes from program flash 0x030c3c66)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTimeDlyResume_dly_suspended_arm(void)

{
  char cVar1;
  undefined4 sr;
  int unaff_r4;
  undefined4 *unaff_r5;
  undefined4 unaff_r6;
  
  cVar1 = *pcRam00014120;
  *pcRam00014120 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(unaff_r6);
  *(undefined1 *)(unaff_r4 + 0x36) = 4;
  dll_node_remove();
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *pcRam00014120;
  *pcRam00014120 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  *unaff_r5 = 0x715a;
  OSSched();
  return;
}

