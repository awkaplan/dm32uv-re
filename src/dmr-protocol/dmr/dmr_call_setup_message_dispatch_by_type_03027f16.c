/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_message_dispatch_by_type @ 03027f16 (file base 0x03000000; code starts at 0x03001000)
 * Size: 286 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_setup_message_dispatch_by_type(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  PTR_DAT_0302803c[7] = SUBPIECE(in_stack_0000001c, 3, 1);
  puVar2 = PTR_DAT_03028038;
  if (SUBPIECE_SET(in_stack_0000001c, 3, 1, = 0x7f) {
    bVar1 = *(byte *)p_dmr_call_config_state);
    PTR_DAT_03028038[bVar1 + 8] = in_r3;
    puVar2[bVar1 + 6] = in_stack_00000018;
    OSFlagPost_wrapper_set_fixed_grp(0x100000);
  }
  else if (SUBPIECE(in_stack_0000001c, 3, 1) < 0x80) {
    if (SUBPIECE_SET(in_stack_0000001c, 3, 1, = 0) {
      bVar1 = *(byte *)p_dmr_call_config_state);
      PTR_DAT_03028038[bVar1 + 8] = in_r3;
      puVar2[bVar1 + 6] = in_stack_00000018;
      OSFlagPost_wrapper_set_fixed_grp(0x400000);
    }
    else if (SUBPIECE_SET(in_stack_0000001c, 3, 1, = 0x7e) {
      bVar1 = *(byte *)p_dmr_call_config_state);
      PTR_DAT_03028038[bVar1 + 8] = in_r3;
      puVar2[bVar1 + 6] = in_stack_00000018;
      OSFlagPost_wrapper_set_fixed_grp(0x40000);
    }
  }
  else if (SUBPIECE_SET(in_stack_0000001c, 3, 1, = 0xfe) {
    bVar1 = *(byte *)p_dmr_call_config_state);
    PTR_DAT_03028038[bVar1 + 6] = in_stack_00000018;
    puVar2[bVar1 + 8] = in_r3;
    *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
    dialog_state_set_substate(4);
  }
  else if (SUBPIECE(in_stack_0000001c, 3, 1) < 0xff) {
    if (SUBPIECE_SET(in_stack_0000001c, 3, 1, = 0x80) {
      bVar1 = *(byte *)p_dmr_call_config_state);
      PTR_DAT_03028038[bVar1 + 6] = in_stack_00000018;
      puVar2[bVar1 + 8] = in_r3;
      *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
      dialog_state_set_substate(4);
    }
  }
  else {
    bVar1 = *(byte *)p_dmr_call_config_state;
    PTR_DAT_03028038[bVar1 + 6] = in_stack_00000018;
    puVar2[bVar1 + 8] = in_r3;
    *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
    dialog_state_set_substate(4);
  }
  return;
}

