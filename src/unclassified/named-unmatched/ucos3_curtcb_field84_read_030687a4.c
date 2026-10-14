/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_curtcb_field84_read @ 030687a4 (file base 0x03000000; code starts at 0x03001000)
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

undefined4 ucos3_curtcb_field84_read(undefined4 *param_1)

{
  undefined4 sr;
  undefined4 uVar1;
  
  if (*(char *)PTR_OSIntNestingCtr_030687e0 == '\0') {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    uVar1 = *(undefined4 *)(*PTR_OSTCBCurPtr_030687ec + 0x84);
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    *param_1 = 0;
  }
  else {
    *param_1 = 0x61ae;
    uVar1 = 0;
  }
  return uVar1;
}

