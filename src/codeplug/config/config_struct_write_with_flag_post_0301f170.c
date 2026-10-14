/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_struct_write_with_flag_post @ 0301f170 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_struct_write_with_flag_post
               (undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = PTR_DAT_0301f2f4;
  *(undefined1 *)PTR_DAT_0301f2f4 = param_1;
  *(byte *)((int)puVar1 + 1) = p_call_setup_sm_state_aux->field_0x1b;
  *(undefined4 *)(puVar1 + 4) = param_2;
  *(undefined4 *)(puVar1 + 8) = param_3;
  puVar1[10] = param_4;
  OSFlagPost_wrapper_set_passthrough(0x400);
  return;
}

