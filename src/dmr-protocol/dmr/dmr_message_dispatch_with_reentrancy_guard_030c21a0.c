/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_message_dispatch_with_reentrancy_guard @ 030c21a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 dmr_message_dispatch_with_reentrancy_guard(int param_1,short param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c221c == '\0') {
    if ((param_2 == 0) || (param_2 == -0x8000)) {
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if ((param_1 == 0) || (param_1 == *PTR_OSTCBCurPtr_030c2218)) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        *param_3 = 0x61ac;
        uVar2 = 0;
      }
      else if (*(char *)(param_1 + 0x34) == '\x02') {
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c23c4;
        *(char *)PTR_OSSchedLockNestingCtr_030c23c4 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          conditional_cached_value_refresh();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        uVar2 = func_0x0611caf4();
        queued_event_dispatch_immediate_or_deferred_simple(0,param_1,uVar2);
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c23c4;
        *(char *)PTR_OSSchedLockNestingCtr_030c23c4 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        if (-1 < param_2) {
          OS_Sched();
        }
        *param_3 = 0;
        uVar2 = 1;
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        *param_3 = 0x61ab;
        uVar2 = 0;
      }
    }
    else {
      *param_3 = 0x5e25;
      uVar2 = 0;
    }
  }
  else {
    *param_3 = 0x61aa;
    uVar2 = 0;
  }
  return uVar2;
}

