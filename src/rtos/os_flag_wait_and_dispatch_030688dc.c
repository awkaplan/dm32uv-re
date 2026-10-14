/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: os_flag_wait_and_dispatch @ 030688dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 1138 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint os_flag_wait_and_dispatch(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  short sVar6;
  uint unaff_r4;
  uint uVar7;
  int *unaff_r6;
  uint unaff_r7;
  undefined4 *unaff_r9;
  uint uVar8;
  int *unaff_r11;
  uint uStack00000008;
  
  if (*unaff_r6 != DAT_03068978) {
    *unaff_r9 = 0x5dc4;
    return 0;
  }
  uStack00000008 = (uint)((unaff_r4 & 0x100) != 0);
  if (unaff_r11 != (int *)0x0) {
    *unaff_r11 = 0;
  }
  uVar8 = unaff_r4 & 0xf;
  uVar4 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  puVar3 = PTR_OSSchedLockNestingCtr_03068c94;
  puVar2 = PTR_OSSchedLockNestingCtr_03068b0c;
  sVar6 = (short)unaff_r4;
  if (uVar8 == 2) {
    uVar7 = unaff_r7 & ~unaff_r6[8];
    if (uVar7 != 0) {
      if (uStack00000008 == 1) {
        unaff_r6[8] = unaff_r6[8] | uVar7;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068c98 + 0x84) = uVar7;
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = unaff_r6[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0;
      return uVar7;
    }
    if (sVar6 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068c94 != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068c94 = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    update_and_apply_settings(&stack0x0000000c);
    uVar4 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)puVar3;
    *(char *)puVar3 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
  }
  else if (uVar8 < 3) {
    if (uVar8 != 1) {
LAB_03068c34:
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x5e25;
      return 0;
    }
    uVar7 = unaff_r7 & ~unaff_r6[8];
    if (uVar7 == unaff_r7) {
      if (uStack00000008 == 1) {
        unaff_r6[8] = unaff_r6[8] | uVar7;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068b10 + 0x84) = uVar7;
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = unaff_r6[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0;
      return uVar7;
    }
    if (sVar6 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068c94 != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068c94 = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    update_and_apply_settings(&stack0x0000000c);
    uVar4 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)puVar3;
    *(char *)puVar3 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
  }
  else if (uVar8 == 4) {
    uVar7 = unaff_r7 & unaff_r6[8];
    if (uVar7 == unaff_r7) {
      if (uStack00000008 == 1) {
        unaff_r6[8] = unaff_r6[8] & ~uVar7;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068970 + 0x84) = uVar7;
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = unaff_r6[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0;
      return uVar7;
    }
    if (sVar6 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068b0c != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068b0c = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    update_and_apply_settings(&stack0x0000000c);
    uVar4 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)puVar2;
    *(char *)puVar2 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
  }
  else {
    if (uVar8 != 8) goto LAB_03068c34;
    uVar7 = unaff_r7 & unaff_r6[8];
    if (uVar7 != 0) {
      if (uStack00000008 == 1) {
        unaff_r6[8] = unaff_r6[8] & ~uVar7;
      }
      *(uint *)(*PTR_OSTCBCurPtr_03068b10 + 0x84) = uVar7;
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = unaff_r6[9];
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0;
      return uVar7;
    }
    if (sVar6 < 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x61b0;
      return 0;
    }
    if (*(char *)PTR_OSSchedLockNestingCtr_03068b0c != '\0') {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x6d63;
      return 0;
    }
    *(undefined1 *)PTR_OSSchedLockNestingCtr_03068b0c = 1;
    OS_SchedLockTimeMeasStart_variant4();
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    update_and_apply_settings(&stack0x0000000c);
    uVar4 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)puVar2;
    *(char *)puVar2 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
  }
  OSSched();
  uVar4 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  iVar5 = *PTR_OSTCBCurPtr_03068c98;
  cVar1 = *(char *)(iVar5 + 0x35);
  if (cVar1 == '\x01') {
    if (unaff_r11 != (int *)0x0) {
      *unaff_r11 = *(int *)(iVar5 + 0x40);
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    *unaff_r9 = 0x61a9;
    return 0;
  }
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = *(int *)(iVar5 + 0x40);
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x5dc2;
      return 0;
    }
    if (cVar1 == '\x03') {
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = 0;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar4);
      *unaff_r9 = 0x72d9;
      return 0;
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar4);
    *unaff_r9 = 0x6e2e;
    return 0;
  }
  if (unaff_r11 != (int *)0x0) {
    *unaff_r11 = *(int *)(iVar5 + 0x40);
  }
  *unaff_r9 = 0;
  uVar7 = *(uint *)(*PTR_OSTCBCurPtr_03068c98 + 0x84);
  if (uStack00000008 == 1) {
    if (uVar8 != 4) {
      if (uVar8 < 5) {
        if (uVar8 - 1 < 2) {
          unaff_r6[8] = unaff_r6[8] | uVar7;
          goto LAB_03068d56;
        }
LAB_03068d40:
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar4);
        *unaff_r9 = 0x5e25;
        return 0;
      }
      if (uVar8 != 8) goto LAB_03068d40;
    }
    unaff_r6[8] = unaff_r6[8] & ~uVar7;
  }
LAB_03068d56:
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar4);
  *unaff_r9 = 0;
  return uVar7;
}

