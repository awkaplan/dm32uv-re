/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_item_reinit_pend_list @ 0306a4b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_list_item_reinit_pend_list(undefined4 *param_1)

{
  FUN_030695b4(param_1 + 8);
  *param_1 = _DAT_0306a5b0;
  param_1[1] = _DAT_0306a5b4;
  critical_section_struct_init(param_1 + 8,0);
  ucos3_pend_list_init(param_1 + 2);
  return;
}

