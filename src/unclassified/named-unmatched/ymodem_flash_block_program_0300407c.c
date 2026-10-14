/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ymodem_flash_block_program @ 0300407c (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
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

bool ymodem_flash_block_program(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _DAT_030040d4;
  libc_memcpy_bytes(_DAT_030040d4);
  PTR_LAB_030040d0[0x14] = 0;
  uVar2 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  iVar3 = flash_region_write_chunked(*param_1,param_3,uVar1);
  if (iVar3 != -1) {
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
    *param_1 = *param_1 + param_3;
  }
  else {
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
  }
  return iVar3 == -1;
}

