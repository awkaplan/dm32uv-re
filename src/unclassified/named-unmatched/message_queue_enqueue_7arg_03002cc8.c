/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: message_queue_enqueue_7arg @ 03002cc8 (file base 0x03000000; code starts at 0x03001000)
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

void message_queue_enqueue_7arg
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined4 *param_8)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  uVar1 = *(ushort *)PTR_DAT_03002d68;
  if (uVar1 < *(ushort *)PTR_LAB_03002d6c) {
    *(ushort *)PTR_DAT_03002d68 = uVar1 + 1;
    if (*(ushort *)PTR_DAT_03002d70 < (ushort)(uVar1 + 1)) {
      *(ushort *)PTR_DAT_03002d70 = uVar1 + 1;
    }
    puVar2 = PTR_LAB_00016dae_2_03002d74;
    *(undefined4 *)*PTR_LAB_00016dae_2_03002d74 = param_1;
    iVar5 = *puVar2;
    *(undefined4 *)(iVar5 + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = param_3;
    *(undefined2 *)(iVar5 + 0x10) = param_4;
    *(undefined4 *)(iVar5 + 0x14) = param_5;
    *(undefined2 *)(iVar5 + 0x18) = param_6;
    *(undefined4 *)(iVar5 + 0x1c) = param_7;
    *puVar2 = *(undefined4 *)(iVar5 + 4);
    puVar3 = PTR_LAB_03002d78;
    PTR_LAB_03002d78[4] = 1;
    puVar2 = PTR_DAT_03002d7c;
    *(undefined4 **)puVar3 = PTR_DAT_03002d7c;
    *(undefined4 **)(puVar3 + 2) = puVar2;
    FUN_03002ff4(0);
    if (*(char *)PTR_LAB_00016db4_1_03002d80 != '\0') {
      *(char *)PTR_DAT_03002d84 = *(char *)PTR_LAB_00016db4_1_03002d80;
    }
    *param_8 = 0;
  }
  else {
    *(short *)PTR_DAT_03002d88 = *(short *)PTR_DAT_03002d88 + 1;
    *param_8 = 0x4653;
  }
  OS_SchedLockTimeMeasStop_variant2();
  func_0x030020e4(uVar4);
  return;
}

