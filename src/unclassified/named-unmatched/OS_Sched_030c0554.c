/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_Sched @ 030c0554 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_Sched(void)

{
  undefined4 sr;
  int iVar1;
  
  if ((*(char *)PTR_OSIntNestingCtr_030c05bc == '\0') &&
     (*(char *)PTR_OSSchedLockNestingCtr_030c05c0 == '\0')) {
    sr = cpu_sr_save_and_disable_irq_variant2();
    iVar1 = OS_PrioGetHighest_variant2();
    *(char *)PTR_OSPrioHighRdy_030c05c4 = (char)iVar1;
    iVar1 = *(int *)(iVar1 * 0xc + _DAT_030c05c8);
    *PTR_OSTCBHighRdyPtr_030c05cc = iVar1;
    if (iVar1 == *PTR_OSTCBCurPtr_030c05d0) {
      cpu_sr_restore_irq_variant2(sr);
    }
    else {
      *(int *)(iVar1 + 0x90) = *(int *)(iVar1 + 0x90) + 1;
      *PTR_OSTaskCtxSwCtr_030c05d4 = *PTR_OSTaskCtxSwCtr_030c05d4 + 1;
      ucos3_highrdy_commit();
      cpu_sr_restore_irq_variant2(sr);
    }
  }
  return;
}

