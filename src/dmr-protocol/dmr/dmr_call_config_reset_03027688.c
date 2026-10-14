/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_config_reset @ 03027688 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_config_reset(void)

{
  dmr_call_config_state *pdVar1;
  
  pdVar1 = p_dmr_call_config_state;
  *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
  pdVar1->field_0x3 = 0;
  pdVar1->field_0x7 = 1;
  OSFlagPost_wrapper_set_fixed_grp(0x200);
  if (*(char *)((uint)*(byte *)pdVar1 + p_dmr_config_unpack_state) != '\0') {
    *(undefined1 *)((uint)*(byte *)pdVar1 + p_dmr_config_unpack_state) = 0;
    OSFlagPost_wrapper_set_fixed_grp(4);
  }
  return;
}

