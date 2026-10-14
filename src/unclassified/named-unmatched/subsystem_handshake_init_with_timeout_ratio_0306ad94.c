/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: subsystem_handshake_init_with_timeout_ratio @ 0306ad94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
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

void subsystem_handshake_init_with_timeout_ratio(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iStack_14;
  
  OSTaskSuspend(_DAT_0306aec0,&iStack_14);
  if (iStack_14 == 0) {
    OSTimeDly(2,0,&iStack_14);
    if (iStack_14 == 0) {
      uVar1 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      *PTR_DAT_0306aec4 = 0;
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar1);
      uVar3 = *PTR_LAB_0306aec8;
      if ((uVar3 <= (uint)*PTR_LAB_0306aecc) ||
         (uVar2 = uVar3 / (uint)*PTR_LAB_0306aecc, uVar2 == 0)) {
        uVar2 = uVar3 / 10;
      }
      OSTimeDly(uVar2,0,&iStack_14);
      OSTaskResume(_DAT_0306aec0,&iStack_14);
      if (iStack_14 == 0) {
        uVar1 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        *PTR_DAT_0306aed0 = 0;
        *PTR_DAT_0306aed4 = *PTR_DAT_0306aec4;
        *(undefined1 *)PTR_DAT_0306aed8 = 1;
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar1);
        *param_1 = 0;
      }
      else {
        *param_1 = iStack_14;
      }
    }
    else {
      *param_1 = iStack_14;
    }
  }
  else {
    *param_1 = iStack_14;
  }
  return;
}

