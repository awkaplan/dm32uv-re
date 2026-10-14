/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos3_task_timeout_requeue @ 000112c8 (IRAM address; the boot stub copies these bytes from program flash 0x030c0ee8)
 * Size: 158 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ucos3_task_timeout_requeue(int *param_1)

{
  undefined4 sr;
  int iVar1;
  undefined *puVar2;
  
  if (*PTR_DAT_000113b0 == '\x01') {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    puVar2 = (undefined *)*param_1;
    if (puVar2 == (undefined *)0x0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
    }
    else if (puVar2 == PTR_DAT_000113b4) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
    }
    else {
      if ((*(int *)(puVar2 + 0x58) != 0) &&
         (iVar1 = *(int *)(puVar2 + 0x58) + -1, *(int *)(puVar2 + 0x58) = iVar1, iVar1 != 0)) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        return;
      }
      if (*(ushort *)(param_1 + 2) < 2) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
      }
      else if (*PTR_OSSchedLockNestingCtr_000113ac == '\0') {
        os_rdylist_move_head_to_tail(param_1);
        iVar1 = *param_1;
        if (*(int *)(iVar1 + 0x54) == 0) {
          *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)PTR_DAT_000113b8;
        }
        else {
          *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x54);
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
      }
    }
  }
  return;
}

