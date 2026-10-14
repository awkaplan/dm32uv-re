/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSIntExit @ 000108b0 (IRAM address; the boot stub copies these bytes from program flash 0x030c04d0)
 * Size: 130 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSIntExit(void)

{
  char cVar1;
  undefined4 sr;
  int iVar2;
  
  if (*PTR_DAT_00010998 == '\x01') {
    sr = cpu_sr_save_and_disable_irq_iram();
    cVar1 = *PTR_OSIntNestingCtr_0001099c;
    if (cVar1 == '\0') {
      cpu_sr_restore_irq_iram(sr);
    }
    else {
      *PTR_OSIntNestingCtr_0001099c = cVar1 + -1;
      if (cVar1 == '\x01') {
        if (*PTR_OSSchedLockNestingCtr_000109a0 == '\0') {
          iVar2 = OS_PrioGetHighest();
          *PTR_OSPrioHighRdy_000109a4 = (char)iVar2;
          iVar2 = *(int *)(PTR_OSRdyList_000109a8 + iVar2 * 0xc);
          *(int *)PTR_OSTCBHighRdyPtr_000109ac = iVar2;
          if (iVar2 == *(int *)PTR_OSTCBCurPtr_000109b0) {
            cpu_sr_restore_irq_iram(sr);
          }
          else {
            *(int *)(iVar2 + 0x90) = *(int *)(iVar2 + 0x90) + 1;
            *(int *)PTR_OSTaskCtxSwCtr_000109b4 = *(int *)PTR_OSTaskCtxSwCtr_000109b4 + 1;
            OSIntCtxSw();
            cpu_sr_restore_irq_iram(sr);
          }
        }
        else {
          cpu_sr_restore_irq_iram(sr);
        }
      }
      else {
        cpu_sr_restore_irq_iram(sr);
      }
    }
  }
  return;
}

