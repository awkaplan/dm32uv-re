/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: critical_section_counted_init_dispatch @ 0306a500 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void critical_section_counted_init_dispatch(undefined4 *param_1,undefined4 param_2,int param_3__w,undefined4 *param_4)

{
  short param_3 = (short)param_3__w;
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_0306a5c0 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_4 = 0x5dc3;
    }
    else if (param_3 == 0) {
      *param_4 = 0x6594;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a5ac;
      *(char *)PTR_OSSchedLockNestingCtr_0306a5ac = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_1 = DAT_0306a5a8;
      param_1[1] = param_2;
      critical_section_struct_init(param_1 + 8,param_3);
      ucos3_pend_list_init(param_1 + 2);
      instance_list_prepend_with_vtable(param_1);
      *(short *)PTR_DAT_0306a5c4 = *(short *)PTR_DAT_0306a5c4 + 1;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a5ac;
      *(char *)PTR_OSSchedLockNestingCtr_0306a5ac = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_4 = 0;
    }
  }
  else {
    *param_4 = 0x2ee1;
  }
  return;
}

