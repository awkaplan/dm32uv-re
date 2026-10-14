/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos3_message_queue_post_with_overflow_check @ 00011604 (IRAM address; the boot stub copies these bytes from program flash 0x030c1224)
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

void ucos3_message_queue_post_with_overflow_check(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4__w,undefined4 param_5,int param_6__w,undefined4 param_7,undefined4 *param_8)

{
  undefined2 param_4 = (undefined2)param_4__w;
  undefined2 param_6 = (undefined2)param_6__w;
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 sr;
  int iVar4;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  uVar1 = *puRam000117e4;
  if (uVar1 < *puRam000117e8) {
    *puRam000117e4 = uVar1 + 1;
    if (*(ushort *)PTR_DAT_000117ec < (ushort)(uVar1 + 1)) {
      *(ushort *)PTR_DAT_000117ec = uVar1 + 1;
    }
    puVar2 = PTR_DAT_000117f0;
    **(undefined4 **)PTR_DAT_000117f0 = param_1;
    iVar4 = *(int *)puVar2;
    *(undefined4 *)(iVar4 + 8) = param_2;
    *(undefined4 *)(iVar4 + 0xc) = param_3;
    *(undefined2 *)(iVar4 + 0x10) = param_4;
    *(undefined4 *)(iVar4 + 0x14) = param_5;
    *(undefined2 *)(iVar4 + 0x18) = param_6;
    *(undefined4 *)(iVar4 + 0x1c) = param_7;
    *(undefined4 *)puVar2 = *(undefined4 *)(iVar4 + 4);
    puVar2 = PTR_OSRdyList_000117f4;
    *(undefined2 *)(PTR_OSRdyList_000117f4 + 8) = 1;
    puVar3 = PTR_OSIntQTaskTCB_000117f8;
    *(undefined **)puVar2 = PTR_OSIntQTaskTCB_000117f8;
    *(undefined **)(puVar2 + 4) = puVar3;
    OS_PrioInsert(0);
    if (*PTR_DAT_000117fc != '\0') {
      *PTR_DAT_00011800 = *PTR_DAT_000117fc;
    }
    *param_8 = 0;
  }
  else {
    *(short *)PTR_DAT_00011804 = *(short *)PTR_DAT_00011804 + 1;
    *param_8 = 0x4653;
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  return;
}

