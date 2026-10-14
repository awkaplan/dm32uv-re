/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_reg_snapshot_shift12_then_flash_scan @ 0300f4fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
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

void hw_reg_snapshot_shift12_then_flash_scan(void)

{
  short sVar1;
  
  *(char *)PTR_DAT_0300f67c = (char)(*_LAB_0300f678 >> 0xc);
  *(char *)PTR_DAT_0300f684 = (char)(*_LAB_0300f680 >> 0xc);
  sVar1 = (short)(*_LAB_0300f688 >> 0xc);
  *_LAB_0300f68c = sVar1;
  *_LAB_0300f690 = sVar1 + 1;
  spi_flash_pending_update_scan_and_invalidate();
  return;
}

