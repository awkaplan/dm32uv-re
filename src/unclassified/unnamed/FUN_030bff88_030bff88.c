/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030bff88 @ 030bff88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030bff88(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 sr;
  
  *PTR_DAT_030c00d8 = 0;
  func_0x0611cae8();
  *(undefined2 *)PTR_DAT_030c00dc = 0;
  *(undefined2 *)PTR_DAT_030c00e0 = 0;
  *PTR_DAT_030c00e4 = 0;
  *PTR_DAT_030c00e8 = 0;
  puVar1 = PTR_DAT_030c00ec;
  *PTR_DAT_030c00ec = 0;
  puVar2 = PTR_DAT_030c00f0;
  *PTR_DAT_030c00f0 = 0;
  puVar3 = PTR_DAT_030c00f4;
  *PTR_DAT_030c00f4 = 0;
  sr = cpu_sr_save_and_disable_irq_variant2();
  *puVar1 = 0;
  OS_SchedLockTimeMeasStart_variant3();
  OS_SchedLockTimeMeasStop_variant3();
  *puVar3 = *puVar1;
  *puVar1 = 0;
  *puVar2 = 0;
  cpu_sr_restore_irq_variant2(sr);
  ucos3_sched_locked_op16();
  return;
}

