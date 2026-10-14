/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: os_queue_create_and_register @ 03069404 (file base 0x03000000; code starts at 0x03001000)
 * Size: 274 bytes
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

void os_queue_create_and_register
               (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,ushort param_4,
               ushort param_5,undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = (uint)param_5;
  if (*(char *)PTR_OSIntNestingCtr_0306951c == '\0') {
    if (param_3 == (undefined4 *)0x0) {
      *param_6 = 0x56bb;
    }
    else if (param_4 < 2) {
      *param_6 = 0x56bc;
    }
    else if (uVar5 < 4) {
      *param_6 = 0x56c1;
    }
    else if (((uint)param_3 & 3) == 0) {
      if ((param_5 & 3) == 0) {
        puVar3 = param_3;
        if (param_4 != 1) {
          uVar4 = 0;
          do {
            *puVar3 = (undefined4 *)((int)puVar3 + uVar5);
            uVar4 = uVar4 + 1;
            puVar3 = (undefined4 *)((int)puVar3 + uVar5);
          } while (uVar4 < (ushort)(param_4 - 1));
          puVar3 = (undefined4 *)((int)param_3 + uVar5 * ((ushort)(param_4 - 2) + 1));
        }
        *puVar3 = 0;
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069520;
        *(char *)PTR_OSSchedLockNestingCtr_03069520 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          OS_SchedLockTimeMeasStart_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        *param_1 = _DAT_03069524;
        param_1[2] = param_2;
        param_1[1] = param_3;
        param_1[3] = param_3;
        *(ushort *)(param_1 + 5) = param_4;
        *(ushort *)((int)param_1 + 0x12) = param_4;
        *(ushort *)(param_1 + 4) = param_5;
        registry_list_push_front_a(param_1);
        *(short *)PTR_DAT_03069528 = *(short *)PTR_DAT_03069528 + 1;
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069520;
        *(char *)PTR_OSSchedLockNestingCtr_03069520 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        *param_6 = 0;
      }
      else {
        *param_6 = 0x56c1;
      }
    }
    else {
      *param_6 = 0x56bb;
    }
  }
  else {
    *param_6 = 0x56b9;
  }
  return;
}

