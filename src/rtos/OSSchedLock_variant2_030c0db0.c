/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSSchedLock_variant2 @ 030c0db0 (file base 0x03000000; code starts at 0x03001000)
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

void OSSchedLock_variant2(undefined4 *param_1)

{
  undefined4 sr;
  
  if (*(char *)PTR_OSIntNestingCtr_030c0e60 == '\0') {
    if (*(char *)PTR_DAT_030c0e64 == '\x01') {
      if (*(byte *)PTR_OSSchedLockNestingCtr_030c0e58 < 0xfa) {
        sr = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        *(char *)PTR_OSSchedLockNestingCtr_030c0e58 =
             *(char *)PTR_OSSchedLockNestingCtr_030c0e58 + '\x01';
        conditional_cached_value_refresh();
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        *param_1 = 0;
      }
      else {
        *param_1 = 0x5209;
      }
    }
    else {
      *param_1 = 0x5e89;
    }
  }
  else {
    *param_1 = 0x6d62;
  }
  return;
}

