/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_queue_entry_append_and_dialog_advance @ 03027e80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_setup_queue_entry_append_and_dialog_advance(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 in_r3;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  puVar2 = PTR_DAT_03028038;
  bVar1 = *(byte *)p_dmr_call_config_state;
  PTR_DAT_03028038[bVar1 + 6] = in_stack_00000018;
  puVar2[bVar1 + 8] = in_r3;
  puVar3 = PTR_DAT_0302803c;
  PTR_DAT_0302803c[4] = SUBPIECE(in_stack_0000001c, 2, 1) >> 6 & 1;
  puVar3[5] = SUBPIECE(in_stack_0000001c, 2, 1) & 0x3f;
  puVar3[6] = SUBPIECE(in_stack_0000001c, 3, 1);
  *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
  dialog_state_set_substate(5);
  return;
}

