/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: command_jump_table_dispatch @ 030c2e6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void command_jump_table_dispatch(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  *param_2 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
                    /* WARNING: Could not recover jumptable at 0x030c2e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_LAB_030c2e94[*(byte *)(param_1 + 0x36)] & 0xfffffffe))();
    return;
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(sr);
  *param_2 = 0x6e2d;
  return;
}

