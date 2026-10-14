/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: irq_boot_register_handlers_3b_to_41 @ 0301d128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
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

void irq_boot_register_handlers_3b_to_41(void)

{
  irq_controller_unmask_and_register_handler(_DAT_0301d168,0x3c);
  irq_controller_unmask_and_register_handler(_DAT_0301d16c,0x3b);
  irq_controller_unmask_and_register_handler(_DAT_0301d170,0x3d);
  irq_controller_unmask_and_register_handler(_DAT_0301d174,0x3f);
  irq_controller_unmask_and_register_handler(_DAT_0301d178,0x3e);
  irq_controller_unmask_and_register_handler(_DAT_0301d17c,0x40);
  irq_controller_unmask_and_register_handler(_DAT_0301d180,0x41);
  return;
}

