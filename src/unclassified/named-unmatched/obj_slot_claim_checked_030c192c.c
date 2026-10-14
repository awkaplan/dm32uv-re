/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: obj_slot_claim_checked @ 030c192c (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
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

void obj_slot_claim_checked(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 sr;
  
  if (*(char *)PTR_OSIntNestingCtr_030c1984 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x5dc3;
    }
    else if (*param_1 == _DAT_030c1988) {
      *param_3 = 0;
      sr = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if (param_1[8] == 0) {
        if ((short)param_1[4] == 0) {
          param_1[8] = param_2;
        }
        else {
          *param_3 = 0x715f;
        }
      }
      else {
        param_1[8] = param_2;
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(sr);
    }
    else {
      *param_3 = 0x5dc4;
    }
  }
  else {
    *param_3 = 0x6dc6;
  }
  return;
}

