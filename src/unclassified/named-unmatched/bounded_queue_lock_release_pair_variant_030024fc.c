/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bounded_queue_lock_release_pair_variant @ 030024fc (file base 0x03000000; code starts at 0x03001000)
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

void bounded_queue_lock_release_pair_variant(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(char *)PTR_DAT_03002550 == '\0') && (*(char *)PTR_LAB_03002554 == '\0')) {
    uVar1 = cpu_sr_save_and_disable_irq();
    iVar2 = table_index_derive_from_element_count();
    *(char *)PTR_LAB_03002558 = (char)iVar2;
    iVar2 = *(int *)(iVar2 * 0xc + _DAT_0300255c);
    *PTR_DAT_03002560 = iVar2;
    if (iVar2 == *PTR_DAT_03002564) {
      func_0x030020e4(uVar1);
    }
    else {
      *PTR_DAT_03002568 = *PTR_DAT_03002568 + 1;
      ucos3_highrdy_commit_variant2();
      func_0x030020e4(uVar1);
    }
  }
  return;
}

