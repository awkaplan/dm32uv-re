/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_controller_descriptor_init_once @ 03003dd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_controller_descriptor_init_once(void)

{
  undefined4 *puVar1;
  
  iRam03000000 = CONCAT31(SUBPIECE(iRam03000000, 1, 3),4);
  if (iRam03000000 == _DAT_03003e90) {
    if (iRam03000004 + _DAT_03003e90 == iRam03000008) goto LAB_03003e2e;
  }
  iRam03000000 = 0x20000000;
  FUN_03003cc4(0x2000);
  puRam03800000 = &LAB_03001000;
  iRam03000000 = _DAT_03003e94;
  FUN_03003cc4(0x2000);
LAB_03003e2e:
  puVar1 = PTR_LAB_03003e98;
  PTR_LAB_03003e98[1] = 0x5c;
  puVar1[2] = 0x20;
  puVar1[4] = 0x3200000;
  puVar1[3] = 0x100;
  *puVar1 = 1;
  return;
}

