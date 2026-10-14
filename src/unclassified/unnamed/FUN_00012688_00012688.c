/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00012688 @ 00012688 (IRAM address; the boot stub copies these bytes from program flash 0x030c22a8)
 * Size: 24 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_00012688(void)

{
  undefined4 uVar1;
  undefined4 *unaff_r5;
  undefined4 unaff_r6;
  
  uVar1 = *(undefined4 *)(*(int *)PTR_OSTCBCurPtr_000127a8 + 0x7c);
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(unaff_r6);
  *unaff_r5 = 0;
  return uVar1;
}

