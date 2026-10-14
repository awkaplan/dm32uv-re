/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_list_init_and_register @ 03068db4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void queue_list_init_and_register
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_03068ed8 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_4 = 0x5dc3;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03068edc;
      *(char *)PTR_OSSchedLockNestingCtr_03068edc = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_1 = _DAT_03068ee0;
      param_1[1] = param_2;
      param_1[8] = param_3;
      param_1[9] = 0;
      ucos3_pend_list_init(param_1 + 2);
      list_register_push_front_a(param_1);
      *(short *)PTR_DAT_03068ed0 = *(short *)PTR_DAT_03068ed0 + 1;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03068edc;
      *(char *)PTR_OSSchedLockNestingCtr_03068edc = cVar1 + -1;
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

