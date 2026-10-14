/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_tcb_word_0x7c_set @ 030c2304 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_tcb_word_0x7c_set(int param_1,char param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 sr;
  
  if (param_2 == '\0') {
    sr = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    if (param_1 == 0) {
      param_1 = *PTR_OSTCBCurPtr_030c23c8;
    }
    *(undefined4 *)(param_1 + 0x7c) = param_3;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_4 = 0;
  }
  else {
    *param_4 = 0x6979;
  }
  return;
}

