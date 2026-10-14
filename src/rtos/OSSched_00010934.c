/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSched @ 00010934 (IRAM address; the boot stub copies these bytes from program flash 0x030c0554)
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

void OSSched(void)

{
  undefined4 sr;
  int iVar1;
  
  if ((*PTR_OSIntNestingCtr_0001099c == '\0') && (*PTR_OSSchedLockNestingCtr_000109a0 == '\0')) {
    sr = cpu_sr_save_and_disable_irq_iram();
    iVar1 = OS_PrioGetHighest();
    *PTR_OSPrioHighRdy_000109a4 = (char)iVar1;
    iVar1 = *(int *)(PTR_OSRdyList_000109a8 + iVar1 * 0xc);
    *(int *)PTR_OSTCBHighRdyPtr_000109ac = iVar1;
    if (iVar1 == *(int *)PTR_OSTCBCurPtr_000109b0) {
      cpu_sr_restore_irq_iram(sr);
    }
    else {
      *(int *)(iVar1 + 0x90) = *(int *)(iVar1 + 0x90) + 1;
      *(int *)PTR_OSTaskCtxSwCtr_000109b4 = *(int *)PTR_OSTaskCtxSwCtr_000109b4 + 1;
      OSCtxSw();
      cpu_sr_restore_irq_iram(sr);
    }
  }
  return;
}

