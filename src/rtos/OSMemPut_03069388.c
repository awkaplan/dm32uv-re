/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSMemPut @ 03069388 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSMemPut(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 sr;
  
  if (param_1 == 0) {
    *param_3 = 0x56bf;
  }
  else if (param_2 == (undefined4 *)0x0) {
    *param_3 = 0x56be;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*(ushort *)(param_1 + 0x14) < *(ushort *)(param_1 + 0x12)) {
      *param_2 = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 **)(param_1 + 0xc) = param_2;
      *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = 0;
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = 0x56ba;
    }
  }
  return;
}

