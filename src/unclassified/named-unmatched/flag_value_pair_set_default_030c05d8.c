/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flag_value_pair_set_default @ 030c05d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flag_value_pair_set_default(char param_1,int param_2,undefined4 *param_3)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  if (param_1 == '\x01') {
    *(undefined1 *)PTR_DAT_030c0714 = 1;
  }
  else {
    *(undefined1 *)PTR_DAT_030c0714 = 0;
  }
  if (param_2 == 0) {
    *PTR_DAT_030c0718 = (uint)*PTR_LAB_030c071c / 10;
  }
  else {
    *PTR_DAT_030c0718 = param_2;
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(sr);
  *param_3 = 0;
  return;
}

