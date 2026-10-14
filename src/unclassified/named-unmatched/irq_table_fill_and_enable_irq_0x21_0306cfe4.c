/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: irq_table_fill_and_enable_irq_0x21 @ 0306cfe4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
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

void irq_table_fill_and_enable_irq_0x21(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0306cfc8();
  uVar2 = _DAT_0306d00c;
  puVar1 = PTR_irq_handler_table_0306d008;
  iVar3 = 0;
  do {
    puVar1[iVar3] = uVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x40);
  irq_controller_unmask_and_register_handler(_DAT_0306d010,0x21);
  return;
}

