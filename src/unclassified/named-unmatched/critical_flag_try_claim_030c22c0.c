/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: critical_flag_try_claim @ 030c22c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool critical_flag_try_claim(undefined4 *param_1)

{
  char cVar1;
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_DAT_030c23cc;
  if (cVar1 == '\0') {
    *(undefined1 *)PTR_DAT_030c23cc = 1;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    *param_1 = 0;
  }
  else {
    *param_1 = 0x59da;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
  }
  return cVar1 != '\0';
}

