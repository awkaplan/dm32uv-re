/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSFlagPost_internal @ 030690e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 448 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
OSFlagPost_internal(int param_1,uint param_2,short param_3,undefined4 param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  if (param_3 != 1) {
    if ((param_3 == 0) || (param_3 == -0x8000)) {
      *(uint *)(param_1 + 0x20) = param_2 | *(uint *)(param_1 + 0x20);
      goto LAB_0306913e;
    }
    if (param_3 != -0x7fff) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_5 = 0x5e25;
      return 0;
    }
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & ~param_2;
LAB_0306913e:
  *(undefined4 *)(param_1 + 0x24) = param_4;
  if (*(short *)(param_1 + 0x10) == 0) {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0;
    uVar6 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030692a4;
    *(char *)PTR_OSSchedLockNestingCtr_030692a4 = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      OS_SchedLockTimeMeasStart_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    iVar7 = *(int *)(param_1 + 8);
    iVar3 = *(int *)(iVar7 + 8);
    while (iVar3 != 0) {
      iVar7 = *(int *)(iVar7 + 4);
      uVar5 = *(ushort *)(iVar3 + 0x88) & 0xf;
      if (uVar5 == 2) {
        uVar4 = *(uint *)(iVar3 + 0x80) & ~*(uint *)(param_1 + 0x20);
        if (uVar4 != 0) {
          queue_state_update_and_process(iVar3,uVar4,param_4);
        }
      }
      else if (uVar5 < 3) {
        if (uVar5 != 1) {
LAB_030691f4:
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030692a4;
          *(char *)PTR_OSSchedLockNestingCtr_030692a4 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
            if (*(short *)PTR_DAT_030692a8 == 0) {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar2);
            }
            else {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar2);
              irq_disable_save_and_release_reinit();
            }
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
          }
          *param_5 = 0x3aff;
          return 0;
        }
        uVar4 = *(uint *)(iVar3 + 0x80);
        if (uVar4 == (uVar4 & ~*(uint *)(param_1 + 0x20))) {
          queue_state_update_and_process(iVar3,uVar4,param_4);
        }
      }
      else if (uVar5 == 4) {
        uVar4 = *(uint *)(iVar3 + 0x80);
        if (uVar4 == (*(uint *)(param_1 + 0x20) & uVar4)) {
          queue_state_update_and_process(iVar3,uVar4,param_4);
        }
      }
      else {
        if (uVar5 != 8) goto LAB_030691f4;
        uVar4 = *(uint *)(iVar3 + 0x80) & *(uint *)(param_1 + 0x20);
        if (uVar4 != 0) {
          queue_state_update_and_process(iVar3,uVar4,param_4);
        }
      }
      if (iVar7 == 0) break;
      iVar3 = *(int *)(iVar7 + 8);
    }
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030692a4;
    *(char *)PTR_OSSchedLockNestingCtr_030692a4 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    if (-1 < param_3) {
      OSSched();
    }
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    uVar6 = *(undefined4 *)(param_1 + 0x20);
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0;
  }
  return uVar6;
}

