/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_sem_pend_wait_variant @ 03003134 (file base 0x03000000; code starts at 0x03001000)
 * Size: 314 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int ucos_sem_pend_wait_variant
              (undefined4 param_1,short param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  if (*(char *)PTR_DAT_03003270 == '\0') {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    uVar2 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    puVar1 = PTR_LAB_03003278;
    iVar4 = *PTR_DAT_03003274;
    if (*(int *)(iVar4 + 0x44) == 0) {
      if (param_2 < 0) {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        *param_4 = 0x61b0;
        iVar5 = 0;
      }
      else if (*(char *)PTR_LAB_03003278 == '\0') {
        *(undefined1 *)PTR_LAB_03003278 = 1;
        ucos_timer_live_count_decrement_hook();
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        channel_object_link_or_clear_init(0,0,7,param_1);
        uVar2 = cpu_sr_save_and_disable_irq();
        OS_SchedLockTimeMeasStart_variant2();
        cVar3 = *(char *)puVar1 + -1;
        *(char *)puVar1 = cVar3;
        if (cVar3 == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track_variant2();
        }
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        bounded_queue_lock_release_pair_variant();
        uVar2 = cpu_sr_save_and_disable_irq();
        OS_SchedLockTimeMeasStart_variant2();
        iVar4 = *PTR_DAT_03003274;
        cVar3 = *(char *)(iVar4 + 0x35);
        if (cVar3 == '\x01') {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *(undefined4 *)(iVar4 + 0x40);
          }
          *param_4 = 0x61a9;
        }
        else if (cVar3 == '\0') {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *(undefined4 *)(iVar4 + 0x40);
          }
          *param_4 = 0;
        }
        else if (cVar3 == '\x03') {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = 0;
          }
          *param_4 = 0x72d9;
        }
        else {
          *param_4 = 0x6e2e;
        }
        iVar5 = *(int *)(*PTR_DAT_03003274 + 0x44);
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
      }
      else {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        *param_4 = 0x6d63;
        iVar5 = 0;
      }
    }
    else {
      iVar5 = *(int *)(iVar4 + 0x44) + -1;
      *(int *)(iVar4 + 0x44) = iVar5;
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(iVar4 + 0x40);
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      *param_4 = 0;
    }
  }
  else {
    *param_4 = 0x61ae;
    iVar5 = 0;
  }
  return iVar5;
}

