/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cpu_and_channel_load_statistics_task @ 0306aa2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 742 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void cpu_and_channel_load_statistics_task(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  
  puVar3 = PTR_LAB_0306ab28;
  puVar2 = PTR_DAT_0306ab24;
  while (*puVar2 != '\x01') {
    OSTimeDly(*puVar3 * 2,0,auStack_28);
  }
  radio_state_and_linked_list_node_fields_zero_reset(auStack_28);
  puVar2 = PTR_OSSchedLockNestingCtr_0306ab30;
  uVar8 = *PTR_LAB_0306ab2c;
  if ((uVar8 <= (uint)*PTR_LAB_0306ab28) ||
     (uStack_2c = uVar8 / (uint)*PTR_LAB_0306ab28, uStack_2c == 0)) {
    uStack_2c = uVar8 / 10;
  }
  do {
    iVar4 = CPU_TS_TmrRd();
    uVar5 = irq_lock_release_global_value();
    *PTR_DAT_0306ab10 = uVar5;
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    *PTR_DAT_0306ab38 = *PTR_DAT_0306ab34;
    *PTR_DAT_0306ab34 = 0;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    uVar8 = *PTR_DAT_0306ab3c;
    if ((uint)*PTR_DAT_0306ab38 < uVar8) {
      if (DAT_0306ab40 < uVar8) {
        if (DAT_0306ab44 < uVar8) {
          if (DAT_0306ab48 < uVar8) {
            uVar10 = 1000;
            if (DAT_0306ab4c < uVar8) {
              uVar10 = 10000;
              iVar6 = 1;
            }
            else {
              iVar6 = 10;
            }
          }
          else {
            uVar10 = 100;
            iVar6 = 100;
          }
        }
        else {
          uVar10 = 10;
          iVar6 = 1000;
        }
      }
      else {
        uVar10 = 1;
        iVar6 = 10000;
      }
      uVar8 = 10000 - (uint)(iVar6 * *PTR_DAT_0306ab38) / (uVar8 / uVar10);
      uVar7 = (ushort)uVar8;
      *_LAB_0306ad6c = uVar7;
      if ((uint)*_LAB_0306ad70 < (uVar8 & 0xffff)) {
        *_LAB_0306ad70 = uVar7;
      }
    }
    else {
      *_LAB_0306ad6c = 10000;
    }
    FUN_00010708();
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    iVar6 = *_LAB_0306ad74;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    if (iVar6 == 0) {
      uVar8 = 1;
      iVar6 = 0;
    }
    else {
      uVar8 = 0;
      do {
        uVar5 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *puVar2;
        *puVar2 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          OS_SchedLockTimeMeasStart_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
        *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar6 + 0x9c);
        *(undefined4 *)(iVar6 + 0x9c) = 0;
        uVar5 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *puVar2;
        *puVar2 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          if (*_LAB_0306ad78 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar5);
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar5);
            irq_disable_save_and_release_reinit();
          }
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar5);
        }
        uVar8 = uVar8 + *(int *)(iVar6 + 0xa0);
        uVar5 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        iVar6 = *(int *)(iVar6 + 0xc0);
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
      } while (iVar6 != 0);
      if (uVar8 == 0) {
        uVar8 = 1;
        iVar6 = 0;
      }
      else {
        if (_LAB_0306ad7c < uVar8) {
          if (_LAB_0306ad80 < uVar8) {
            if (DAT_0306ad84 < uVar8) {
              if (DAT_0306ad88 < uVar8) {
                iVar6 = 1;
              }
              else {
                iVar6 = 10;
              }
              uVar10 = 1000;
              if (DAT_0306ad88 < uVar8) {
                uVar10 = 10000;
              }
            }
            else {
              iVar6 = 100;
              uVar10 = 100;
            }
          }
          else {
            iVar6 = 1000;
            uVar10 = 10;
          }
        }
        else {
          iVar6 = 10000;
          uVar10 = 1;
        }
        uVar8 = uVar8 / uVar10;
      }
    }
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    iVar9 = *_LAB_0306ad74;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
    if (iVar9 != 0) {
      do {
        uVar10 = (uint)(iVar6 * *(int *)(iVar9 + 0xa0)) / uVar8;
        if (10000 < (uVar10 & 0xffff)) {
          uVar10 = 10000;
        }
        *(short *)(iVar9 + 0x8c) = (short)uVar10;
        if ((uint)*(ushort *)(iVar9 + 0x8e) < (uVar10 & 0xffff)) {
          *(short *)(iVar9 + 0x8e) = (short)uVar10;
        }
        OSTaskStkChk(iVar9,iVar9 + 0xb0,iVar9 + 0xac,auStack_28);
        uVar5 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        iVar9 = *(int *)(iVar9 + 0xc0);
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
      } while (iVar9 != 0);
    }
    if (*(char *)PTR_DAT_0306ad8c == '\x01') {
      *(undefined1 *)PTR_DAT_0306ad8c = 0;
      radio_state_and_linked_list_node_fields_zero_reset(auStack_28);
    }
    iVar6 = CPU_TS_TmrRd();
    if ((uint)*PTR_DAT_0306ad90 < (uint)(iVar6 - iVar4)) {
      *PTR_DAT_0306ad90 = iVar6 - iVar4;
    }
    OSTimeDly(uStack_2c,0,auStack_28);
  } while( true );
}

