/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_name_set_checked @ 030bfeb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
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

void ucos3_name_set_checked(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 sr;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_030bfdd4();
  }
  if (param_1 == 0) {
    *param_2 = 10;
  }
  else {
    uVar1 = func_0x0611c574(param_1,0x10);
    if (uVar1 < 0x10) {
      sr = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      func_0x0611c5b4(_DAT_030bff28,param_1,0x10);
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(sr);
      *param_2 = 0;
    }
    else {
      *param_2 = 1000;
    }
  }
  return;
}

