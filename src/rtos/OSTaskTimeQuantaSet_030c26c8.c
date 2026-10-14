/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTaskTimeQuantaSet @ 030c26c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskTimeQuantaSet(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 sr;
  
  if (*(char *)PTR_OSIntNestingCtr_030c271c == '\0') {
    sr = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    if (param_1 == 0) {
      param_1 = *PTR_OSTCBCurPtr_030c2720;
    }
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x54) = *PTR_DAT_030c2724;
    }
    else {
      *(int *)(param_1 + 0x54) = param_2;
    }
    if (*(uint *)(param_1 + 0x58) < *(uint *)(param_1 + 0x54)) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x54);
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_3 = 0;
  }
  else {
    *param_3 = 0x6dc6;
  }
  return;
}

