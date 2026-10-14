/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: serial_flash_sector_erase_then_poll_ready @ 0002c0f8 (IRAM address; the boot stub copies these bytes from program flash 0x030dbd18)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-uart
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void serial_flash_sector_erase_then_poll_ready(void)

{
  undefined4 uVar1;
  undefined4 sr;
  int iVar2;
  char cVar3;
  undefined1 auStack_24 [4];
  
  func_0x03010ddc(0x10c,auStack_24,4);
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  FUN_0002bde8(0x300b000,0x1000);
  uVar1 = uRam0002c1b0;
  cVar3 = '\0';
  do {
    iVar2 = FUN_0002beb8(uVar1,4,auStack_24);
    if (iVar2 != -1) break;
    busy_wait_delay_n_units(100);
    cVar3 = cVar3 + '\x01';
  } while (cVar3 != '\v');
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  return;
}

