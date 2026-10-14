/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_erase_firmware_region_locked @ 03004040 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 flash_erase_firmware_region_locked(void)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  pcVar2 = cpu_sr_restore_irq_inlined_fragment;
  do {
    flash_sector_erase_range_4kb(pcVar2,0x1000);
    pcVar2 = pcVar2 + 0x1000;
  } while (pcVar2 != (code *)0x3100000);
  OS_SchedLockTimeMeasStop_variant2();
  func_0x030020e4(uVar1);
  return 0;
}

