/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rx_audio_queue_dequeue_n @ 0302b6fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 278 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint rx_audio_queue_dequeue_n(uint param_1,uint param_2,int param_3,int *param_4)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  
  puVar7 = PTR_DAT_0302b854;
  iVar6 = DAT_0302b850;
  puVar5 = PTR_OSSchedLockNestingCtr_0302b84c;
  puVar4 = PTR_DAT_0302b848;
  param_2 = param_2 & 0xffff;
  if (param_2 != 0) {
    uVar10 = 0;
    while( true ) {
      while (*puVar4 == 0) {
        if (param_2 <= uVar10) goto LAB_0302b7ba;
        iVar9 = os_sem_pend_ms(DAT_0302b840,param_3);
        *param_4 = iVar9;
        if ((*puVar4 == 0) && (iVar9 == 0x72d9)) {
          return uVar10;
        }
        PTR_DAT_0302b838[2] = 0;
        if (*(char *)((int)PTR_DAT_0302b844 + 1) == '\x02') {
          rf_transceiver_mode_init(1);
        }
        puVar3 = PTR_DAT_0302b844;
        *(undefined1 *)((int)PTR_DAT_0302b844 + 1) = 0;
        *(undefined1 *)puVar3 = 0;
      }
      if (param_2 <= uVar10) break;
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *puVar5;
      *puVar5 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar8);
      *(undefined1 *)(param_1 + uVar10) = *(undefined1 *)(iVar6 + (uint)*(ushort *)puVar7);
      uVar10 = uVar10 + 1 & 0xffff;
      *puVar4 = *puVar4 + -1;
      PTR_DAT_0302b838[10] = 0;
      sVar2 = *(short *)puVar7;
      *(ushort *)puVar7 = sVar2 + 1U;
      if (0x11ff < (ushort)(sVar2 + 1U)) {
        *(undefined2 *)puVar7 = 0;
      }
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *puVar5;
      *puVar5 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0302b83c == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar8);
      }
    }
LAB_0302b7ba:
    *param_4 = 0;
    param_1 = uVar10;
  }
  return param_1;
}

