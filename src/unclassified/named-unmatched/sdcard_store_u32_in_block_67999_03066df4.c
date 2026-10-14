/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sdcard_store_u32_in_block_67999 @ 03066df4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
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

void sdcard_store_u32_in_block_67999(undefined4 param_1)

{
  void *mutex;
  int iVar1;
  
  mutex = _DAT_03066e44;
  os_sem_pend_ms(_DAT_03066e44,0);
  iVar1 = _DAT_03066e48;
  sdcard_data_block_read(_DAT_03066e48,67999,1);
  *(char *)(iVar1 + 0x1fc) = (char)param_1;
  *(char *)(iVar1 + 0x1fd) = (char)((uint)param_1 >> 8);
  *(char *)(iVar1 + 0x1fe) = (char)((uint)param_1 >> 0x10);
  *(char *)(iVar1 + 0x1ff) = (char)((uint)param_1 >> 0x18);
  spi_sdcard_block_write_dispatch(iVar1,67999,1);
  os_sem_post(mutex);
  return;
}

