/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bounded_queue_append_with_dropcount @ 030c1224 (file base 0x03000000; code starts at 0x03001000)
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

void bounded_queue_append_with_dropcount(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4__w,undefined4 param_5,int param_6__w,undefined4 param_7,undefined4 *param_8)

{
  undefined2 param_4 = (undefined2)param_4__w;
  undefined2 param_6 = (undefined2)param_6__w;
  ushort uVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 sr;
  int iVar4;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  uVar1 = *(ushort *)PTR_DAT_030c1404;
  if (uVar1 < *(ushort *)PTR_LAB_030c1408) {
    *(ushort *)PTR_DAT_030c1404 = uVar1 + 1;
    if (*(ushort *)PTR_DAT_030c140c < (ushort)(uVar1 + 1)) {
      *(ushort *)PTR_DAT_030c140c = uVar1 + 1;
    }
    puVar2 = PTR_DAT_030c1410;
    *(undefined4 *)*PTR_DAT_030c1410 = param_1;
    iVar4 = *puVar2;
    *(undefined4 *)(iVar4 + 8) = param_2;
    *(undefined4 *)(iVar4 + 0xc) = param_3;
    *(undefined2 *)(iVar4 + 0x10) = param_4;
    *(undefined4 *)(iVar4 + 0x14) = param_5;
    *(undefined2 *)(iVar4 + 0x18) = param_6;
    *(undefined4 *)(iVar4 + 0x1c) = param_7;
    *puVar2 = *(undefined4 *)(iVar4 + 4);
    puVar3 = PTR_OSRdyList_030c1414;
    PTR_OSRdyList_030c1414[4] = 1;
    puVar2 = PTR_OSIntQTaskTCB_030c1418;
    *(undefined4 **)puVar3 = PTR_OSIntQTaskTCB_030c1418;
    *(undefined4 **)(puVar3 + 2) = puVar2;
    FUN_030c1634(0);
    if (*(char *)PTR_DAT_030c141c != '\0') {
      *(char *)PTR_DAT_030c1420 = *(char *)PTR_DAT_030c141c;
    }
    *param_8 = 0;
  }
  else {
    *(short *)PTR_DAT_030c1424 = *(short *)PTR_DAT_030c1424 + 1;
    *param_8 = 0x4653;
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(sr);
  return;
}

