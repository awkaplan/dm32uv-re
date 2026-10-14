/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTmrCreate @ 0306b078 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTmrCreate(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5__w,undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  short param_5 = (short)param_5__w;
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_0306b194 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_8 = 0x5dc3;
    }
    else {
      if (param_5 == 1) {
        if (param_3 == 0) {
          *param_8 = 0x733f;
          return;
        }
      }
      else {
        if (param_5 != 2) {
          *param_8 = 0x5e25;
          return;
        }
        if (param_4 == 0) {
          *param_8 = 0x7340;
          return;
        }
      }
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306b198;
      *(char *)PTR_OSSchedLockNestingCtr_0306b198 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *(undefined1 *)((int)param_1 + 0x2a) = 1;
      *param_1 = DAT_0306b19c;
      param_1[1] = param_2;
      param_1[8] = param_3;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1[9] = param_4;
      *(short *)(param_1 + 10) = param_5;
      param_1[2] = param_6;
      param_1[3] = param_7;
      param_1[4] = 0;
      param_1[5] = 0;
      linked_list_prepend_struct(param_1);
      *(short *)PTR_DAT_0306b1a0 = *(short *)PTR_DAT_0306b1a0 + 1;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306b198;
      *(char *)PTR_OSSchedLockNestingCtr_0306b198 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_8 = 0;
    }
  }
  else {
    *param_8 = 0x7343;
  }
  return;
}

