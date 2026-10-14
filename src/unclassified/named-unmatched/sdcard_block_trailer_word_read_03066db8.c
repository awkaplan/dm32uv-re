/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sdcard_block_trailer_word_read @ 03066db8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
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

undefined4 sdcard_block_trailer_word_read(void)

{
  void *mutex;
  int iVar1;
  undefined4 uVar2;
  
  mutex = _DAT_03066dec;
  os_sem_pend_ms(_DAT_03066dec,0);
  iVar1 = _DAT_03066df0;
  sdcard_data_block_read(_DAT_03066df0,67999,1);
  uVar2 = *(undefined4 *)(iVar1 + 0x1fc);
  os_sem_post(mutex);
  return uVar2;
}

