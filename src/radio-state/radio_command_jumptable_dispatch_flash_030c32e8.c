/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_command_jumptable_dispatch_flash @ 030c32e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_command_jumptable_dispatch_flash(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  if (param_1 == 0) {
    param_1 = *PTR_OSTCBCurPtr_030c333c;
  }
  else if (param_1 != *PTR_OSTCBCurPtr_030c333c) goto LAB_030c3324;
  if (*(char *)PTR_OSSchedLockNestingCtr_030c3340 != '\0') {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_2 = 0x6d63;
    return;
  }
LAB_030c3324:
  *param_2 = 0;
  if (7 < *(byte *)(param_1 + 0x36)) {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_2 = 0x6e2d;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x030c3338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(PTR_LAB_030c3344[*(byte *)(param_1 + 0x36)] & 0xfffffffe))();
  return;
}

