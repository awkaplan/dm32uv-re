/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskChangePrio @ 00012190 (IRAM address; the boot stub copies these bytes from program flash 0x030c1db0)
 * Size: 362 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskChangePrio(int param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  uint unaff_r4;
  int unaff_r5;
  undefined4 *unaff_r6;
  
  if (0x3e < unaff_r4) {
    *param_3 = 0x6273;
    return;
  }
  if (param_1 == 0) {
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    unaff_r5 = *(int *)PTR_OSTCBCurPtr_00012300;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
  }
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_00012304;
  *PTR_OSSchedLockNestingCtr_00012304 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  if (*(byte *)(unaff_r5 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(unaff_r5 + 0x36) & 0x3fU);
    uVar4 = (undefined1)unaff_r4;
    if ((uVar3 & 0xcc) == 0) {
      if ((uVar3 & 0x32) == 0) {
        if ((uVar3 & 1) == 0) goto LAB_00012278;
        OS_RdyListRemove(unaff_r5);
        *(undefined1 *)(unaff_r5 + 0x37) = uVar4;
        OS_PrioInsert();
        if (param_1 != 0) {
          timer_object_register_into_bucket_list(unaff_r5);
        }
        else {
          hashtable_bucket_insert_tail(unaff_r5);
        }
      }
      else {
        *(undefined1 *)(unaff_r5 + 0x37) = uVar4;
      }
    }
    else if (*(byte *)(unaff_r5 + 0x34) < 8) {
      uVar3 = 1 << ((int)*(char *)(unaff_r5 + 0x34) & 0x3fU);
      if ((uVar3 & 0x86) == 0) {
        if ((uVar3 & 0x78) != 0) {
          FUN_00010c98(unaff_r5);
        }
      }
      else {
        *(undefined1 *)(unaff_r5 + 0x37) = uVar4;
      }
    }
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *PTR_OSSchedLockNestingCtr_00012304;
    *PTR_OSSchedLockNestingCtr_00012304 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    OSSched();
    *unaff_r6 = 0;
  }
  else {
LAB_00012278:
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *PTR_OSSchedLockNestingCtr_00012304;
    *PTR_OSSchedLockNestingCtr_00012304 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_00012308 == 0) {
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
    *unaff_r6 = 0x6e2d;
  }
  return;
}

