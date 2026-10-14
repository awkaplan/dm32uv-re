/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_table_init_entries_and_param_2b @ 0300f198 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_table_init_entries_and_param_2b(void)

{
  fd6818b_reg48_cic_mode_write(*(undefined1 *)PTR_DAT_0300f24c);
  config_table_init_entries_0300e884();
  fd6818b_reg_write(FD6818_PAGE0_REG_0X2B,0xc000);
  return;
}

