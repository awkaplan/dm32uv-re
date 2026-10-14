/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSSemCreate_variant2 @ 030c19dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
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

void OSSemCreate_variant2
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c1b14 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_4 = 0x5dc3;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1b18;
      *(char *)PTR_OSSchedLockNestingCtr_030c1b18 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        conditional_cached_value_refresh();
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      *param_1 = _DAT_030c1b1c;
      param_1[8] = param_3;
      param_1[9] = 0;
      param_1[1] = param_2;
      FUN_030c07a8(param_1 + 2);
      list_register_push_front_c(param_1);
      *(short *)PTR_DAT_030c1b20 = *(short *)PTR_DAT_030c1b20 + 1;
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1b18;
      *(char *)PTR_OSSchedLockNestingCtr_030c1b18 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      *param_4 = 0;
    }
  }
  else {
    *param_4 = 0x2ee1;
  }
  return;
}

