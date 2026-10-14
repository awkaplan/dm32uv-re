/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_active_and_mode_not_2 @ 03027380 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool call_active_and_mode_not_2(void)

{
  bool bVar1;
  int iVar2;
  
  if ((p_dmr_call_config_state->field_0x13 == 0) && (p_dmr_call_config_state->field_0x3 == 0)) {
    bVar1 = false;
  }
  else {
    iVar2 = get_field_0301ea64_0x14();
    bVar1 = iVar2 != 2;
  }
  return bVar1;
}

