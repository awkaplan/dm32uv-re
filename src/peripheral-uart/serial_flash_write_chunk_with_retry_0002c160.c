/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: serial_flash_write_chunk_with_retry @ 0002c160 (IRAM address; the boot stub copies these bytes from program flash 0x030dbd80)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-uart
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void serial_flash_write_chunk_with_retry(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 sr;
  int iVar1;
  char cVar2;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar2 = '\0';
  do {
    iVar1 = FUN_0002beb8(param_1 + 0x300b000,param_3,param_2);
    if (iVar1 != -1) break;
    busy_wait_delay_n_units(100);
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\v');
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  return;
}

