/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: guarded_state_validate_dispatch @ 0306afc0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte guarded_state_validate_dispatch(int *param_1,undefined4 *param_2)

{
  undefined4 sr;
  undefined4 uVar1;
  byte bVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_0306b048 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_2 = 0x7342;
      bVar2 = 0;
    }
    else if (*param_1 == DAT_0306b04c) {
      sr = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      bVar2 = *(byte *)((int)param_1 + 0x2a);
      if (bVar2 < 4) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x7341;
      }
      *param_2 = uVar1;
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
    }
    else {
      *param_2 = 0x5dc4;
      bVar2 = 0;
    }
  }
  else {
    *param_2 = 0x7343;
    bVar2 = 0;
  }
  return bVar2;
}

