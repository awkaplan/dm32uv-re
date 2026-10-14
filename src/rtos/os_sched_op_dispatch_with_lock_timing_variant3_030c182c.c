/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: os_sched_op_dispatch_with_lock_timing_variant3 @ 030c182c (file base 0x03000000; code starts at 0x03001000)
 * Size: 256 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

short os_sched_op_dispatch_with_lock_timing_variant3
                (int *param_1,ushort param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  short sVar3;
  
  if (*(char *)PTR_OSIntNestingCtr_030c1984 != '\0') {
    *param_3 = 0x61aa;
    return 0;
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x5dc3;
    return 0;
  }
  if (param_2 == 0x100) {
LAB_030c187c:
    if (*param_1 == _DAT_030c1988) {
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if ((short)param_1[4] == 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        *param_3 = 0x61ab;
        sVar3 = 0;
      }
      else {
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c198c;
        *(char *)PTR_OSSchedLockNestingCtr_030c198c = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          conditional_cached_value_refresh();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        uVar2 = func_0x0611caf4();
        sVar3 = 0;
        do {
          if ((short)param_1[4] == 0) break;
          queued_event_dispatch_immediate_or_deferred_simple
                    (param_1,*(undefined4 *)(param_1[2] + 8),uVar2);
          sVar3 = sVar3 + 1;
        } while (param_2 == 0x100);
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c198c;
        *(char *)PTR_OSSchedLockNestingCtr_030c198c = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        if (-1 < (short)param_2) {
          OS_Sched();
        }
        *param_3 = 0;
      }
    }
    else {
      *param_3 = 0x5dc4;
      sVar3 = 0;
    }
  }
  else {
    if (param_2 < 0x101) {
      if (param_2 == 0) goto LAB_030c187c;
    }
    else if ((param_2 == 0x8000) || (param_2 == 0x8100)) goto LAB_030c187c;
    *param_3 = 0x5e25;
    sVar3 = 0;
  }
  return sVar3;
}

