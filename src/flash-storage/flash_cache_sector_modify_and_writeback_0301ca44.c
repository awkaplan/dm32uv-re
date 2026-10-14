/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_cache_sector_modify_and_writeback @ 0301ca44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_cache_sector_modify_and_writeback(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 sr;
  int iVar2;
  uint uVar3;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  FUN_0002be78(&DAT_0300b000,0x1000,DAT_0301cac8);
  iVar1 = DAT_0301cac8;
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      *(undefined1 *)(iVar1 + uVar3 + param_1) = *(undefined1 *)(param_2 + uVar3);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < param_3);
  }
  iVar2 = FUN_0002bde8(&DAT_0300b000,0x1000);
  iVar1 = DAT_0301cac8;
  if (iVar2 == 0) {
    do {
      iVar2 = FUN_0002beb8(&DAT_0300b000,0x1000,iVar1);
    } while (iVar2 == -1);
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

