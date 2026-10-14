/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_frame_unpack_and_dispatch @ 03028214 (file base 0x03000000; code starts at 0x03001000)
 * Size: 290 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_setup_frame_unpack_and_dispatch(void)

{
  undefined1 *puVar1;
  dmr_call_config_state *pdVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  undefined4 local_18;
  byte local_14;
  char cStack_13;
  byte bStack_12;
  
  if ((((uint)*PTR_DAT_030283f0 >> 0x19 & 1) == 0) &&
     ((PTR_DAT_030283f4[6] == p_call_setup_sm_state_aux->field_0x5 ||
      ((p_call_setup_sm_state->flags_0x18 & 8) != 0)))) {
    p_dmr_call_config_state->field_0x3 = 1;
    copy_bytes_from_offset_table(0,&local_14,0xc);
    PTR_DAT_030283f4[9] = 0;
    iVar3 = call_setup_target_id_decode_and_check(2,&local_14,&local_18,&local_1c);
    pdVar2 = p_dmr_call_config_state;
    if (iVar3 == 0) {
      *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
      uVar4 = (uint)*(byte *)pdVar2;
      *(undefined1 *)(uVar4 + DAT_03028404) = 1;
      puVar1 = PTR_DAT_030283f4;
      if ((local_14 & 0x3f) == 0x30) {
        if (*(char *)(uVar4 + p_dmr_config_unpack_state + 2) == '\x01') {
          PTR_DAT_030283f4[uVar4 + 0xe] = 0;
          *(undefined4 *)(puVar1 + (uVar4 + 6) * 4) = local_18;
          *(int *)(puVar1 + (uVar4 + 8) * 4) = local_1c;
          OSFlagPost_wrapper_set_passthrough(0x100);
        }
      }
      else if (*(char *)(uVar4 + p_dmr_config_unpack_state) == '\x01') {
        PTR_DAT_030283f4[uVar4 + 0xc] = 0;
        puVar1[0xb] = bStack_12;
        *(undefined4 *)(puVar1 + (uVar4 + 6) * 4) = local_18;
        *(int *)(puVar1 + (uVar4 + 8) * 4) = local_1c;
        OSFlagPost_wrapper_set_fixed_grp(4);
      }
      else if ((cStack_13 == '\x10') && ((bStack_12 & 0x30) == 0x10)) {
        PTR_DAT_030283f4[0xb] = bStack_12;
        *(undefined4 *)(puVar1 + (uVar4 + 6) * 4) = local_18;
        *(int *)(puVar1 + (uVar4 + 8) * 4) = local_1c;
        OSFlagPost_wrapper_set_fixed_grp(4);
      }
    }
    else if (*(int *)&p_call_setup_sm_state_aux->field_0x24_0 == local_1c) {
      *(undefined1 *)((uint)*(byte *)p_dmr_call_config_state + DAT_03028404) = 1;
    }
  }
  return;
}

