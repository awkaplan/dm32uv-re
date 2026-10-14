/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSFlagPend @ 03068814 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint OSFlagPend(int *param_1,uint param_2,undefined4 param_3,uint param_4,int *param_5,
               undefined4 *param_6)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_44 [32];
  
  uVar8 = param_4 & 0xffff;
  if (*(char *)PTR_OSIntNestingCtr_03068974 != '\0') {
    *param_6 = 0x61ae;
    return 0;
  }
  if (param_1 == (int *)0x0) {
    *param_6 = 0x5dc3;
    return 0;
  }
  if (uVar8 != 0x108) {
    if (uVar8 < 0x109) {
      if (uVar8 != 8) {
        if (uVar8 < 9) {
          if (uVar8 == 0) {
LAB_030688ce:
            *param_6 = 0x5e25;
            return 0;
          }
          if (2 < uVar8) {
            if (uVar8 == 4) {
              uVar8 = os_flag_wait_and_dispatch();
              return uVar8;
            }
            goto LAB_030688ce;
          }
        }
        else {
          if (uVar8 < 0x101) goto LAB_030688ce;
          if (0x102 < uVar8) {
            if (uVar8 == 0x104) {
              uVar8 = os_flag_wait_and_dispatch();
              return uVar8;
            }
            goto LAB_030688ce;
          }
        }
      }
    }
    else if (uVar8 != 0x8008) {
      if (uVar8 < 0x8009) {
        if (uVar8 < 0x8001) goto LAB_030688ce;
        if (0x8002 < uVar8) {
          if (uVar8 == 0x8004) {
            uVar8 = os_flag_wait_and_dispatch();
            return uVar8;
          }
          goto LAB_030688ce;
        }
      }
      else if (uVar8 != 0x8104) {
        if (uVar8 < 0x8105) {
          if (uVar8 - 0x8101 < 2) {
            uVar8 = os_flag_wait_and_dispatch();
            return uVar8;
          }
          goto LAB_030688ce;
        }
        if (uVar8 != 0x8108) goto LAB_030688ce;
      }
    }
  }
  if (*param_1 != DAT_03068978) {
    *param_6 = 0x5dc4;
    return 0;
  }
  bVar1 = (param_4 & 0x100) != 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  uVar10 = param_4 & 0xf;
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  puVar4 = PTR_OSSchedLockNestingCtr_03068c94;
  puVar3 = PTR_OSSchedLockNestingCtr_03068b0c;
  sVar7 = (short)param_4;
  if (uVar10 == 2) {
    uVar9 = param_2 & ~param_1[8];
    if (uVar9 != 0) {
      if (bVar1) {
        param_1[8] = param_1[8] | uVar9;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068c98 + 0x84) = uVar9;
      if (param_5 != (int *)0x0) {
        *param_5 = param_1[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0;
      return uVar9;
    }
    if (sVar7 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068c94 != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068c94 = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    update_and_apply_settings(auStack_44,param_1,param_2,uVar8,param_3);
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar2 = *(char *)puVar4;
    *(char *)puVar4 = cVar2 + -1;
    if ((char)(cVar2 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
  }
  else if (uVar10 < 3) {
    if (uVar10 != 1) {
LAB_03068c34:
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x5e25;
      return 0;
    }
    uVar9 = param_2 & ~param_1[8];
    if (uVar9 == param_2) {
      if (bVar1) {
        param_1[8] = param_1[8] | uVar9;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068b10 + 0x84) = uVar9;
      if (param_5 != (int *)0x0) {
        *param_5 = param_1[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0;
      return uVar9;
    }
    if (sVar7 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068c94 != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068c94 = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    update_and_apply_settings(auStack_44,param_1,param_2,uVar8,param_3);
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar2 = *(char *)puVar4;
    *(char *)puVar4 = cVar2 + -1;
    if ((char)(cVar2 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
  }
  else if (uVar10 == 4) {
    uVar9 = param_2 & param_1[8];
    if (uVar9 == param_2) {
      if (bVar1) {
        param_1[8] = param_1[8] & ~uVar9;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068970 + 0x84) = uVar9;
      if (param_5 != (int *)0x0) {
        *param_5 = param_1[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0;
      return uVar9;
    }
    if (sVar7 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068b0c != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068b0c = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    update_and_apply_settings(auStack_44,param_1,param_2,uVar8,param_3);
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar2 = *(char *)puVar3;
    *(char *)puVar3 = cVar2 + -1;
    if ((char)(cVar2 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
  }
  else {
    if (uVar10 != 8) goto LAB_03068c34;
    uVar9 = param_2 & param_1[8];
    if (uVar9 != 0) {
      if (bVar1) {
        param_1[8] = param_1[8] & ~uVar9;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068b10 + 0x84) = uVar9;
      if (param_5 != (int *)0x0) {
        *param_5 = param_1[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0;
      return uVar9;
    }
    if (sVar7 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068b0c != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068b0c = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    update_and_apply_settings(auStack_44,param_1,param_2,uVar8,param_3);
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar2 = *(char *)puVar3;
    *(char *)puVar3 = cVar2 + -1;
    if ((char)(cVar2 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
  }
  OSSched();
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  iVar6 = *PTR_OSTCBCurPtr_03068c98;
  cVar2 = *(char *)(iVar6 + 0x35);
  if (cVar2 == '\x01') {
    if (param_5 != (int *)0x0) {
      *param_5 = *(int *)(iVar6 + 0x40);
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    *param_6 = 0x61a9;
    return 0;
  }
  if (cVar2 != '\0') {
    if (cVar2 == '\x02') {
      if (param_5 != (int *)0x0) {
        *param_5 = *(int *)(iVar6 + 0x40);
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x5dc2;
      return 0;
    }
    if (cVar2 == '\x03') {
      if (param_5 != (int *)0x0) {
        *param_5 = 0;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      *param_6 = 0x72d9;
      return 0;
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    *param_6 = 0x6e2e;
    return 0;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = *(int *)(iVar6 + 0x40);
  }
  *param_6 = 0;
  uVar8 = *(uint *)(*PTR_OSTCBCurPtr_03068c98 + 0x84);
  if (bVar1) {
    if (uVar10 != 4) {
      if (uVar10 < 5) {
        if (uVar10 - 1 < 2) {
          param_1[8] = param_1[8] | uVar8;
          goto LAB_03068d56;
        }
LAB_03068d40:
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
        *param_6 = 0x5e25;
        return 0;
      }
      if (uVar10 != 8) goto LAB_03068d40;
    }
    param_1[8] = param_1[8] & ~uVar8;
  }
LAB_03068d56:
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar5);
  *param_6 = 0;
  return uVar8;
}

