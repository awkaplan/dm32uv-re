/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSSchedUnlock_variant2 @ 030c0e70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSSchedUnlock_variant2(undefined4 *param_1)

{
  char cVar1;
  undefined4 sr;
  
  if (*(char *)PTR_OSIntNestingCtr_030c0fc4 == '\0') {
    if (*(char *)PTR_DAT_030c0fc8 == '\x01') {
      if (*(char *)PTR_OSSchedLockNestingCtr_030c0fcc == '\0') {
        *param_1 = 0x6d64;
      }
      else {
        sr = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c0fcc;
        *(char *)PTR_OSSchedLockNestingCtr_030c0fcc = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(sr);
          OS_Sched();
          *param_1 = 0;
        }
        else {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(sr);
          *param_1 = 0x6d63;
        }
      }
    }
    else {
      *param_1 = 0x5e89;
    }
  }
  else {
    *param_1 = 0x6d65;
  }
  return;
}

