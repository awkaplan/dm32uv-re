/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_slot_link_append @ 0302955c (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_slot_link_append(int param_1)

{
  undefined4 *puVar1;
  dmr_call_config_state *pdVar2;
  int iVar3;
  uint uVar4;
  
  pdVar2 = p_dmr_call_config_state;
  *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
  puVar1 = PTR_DAT_03029610;
  uVar4 = (uint)pdVar2->field_0x4;
  if (PTR_DAT_03029610[uVar4 + 0x29] == 0) {
    PTR_DAT_03029610[uVar4 + 0x29] = param_1;
    puVar1[uVar4 + 0x2b] = param_1;
  }
  else {
    *(int *)(PTR_DAT_03029610[uVar4 + 0x2b] + 0x20) = param_1;
    puVar1[uVar4 + 0x2b] = param_1;
  }
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if ((*(short *)(param_1 + 2) == 0x200) &&
       (((*(byte *)(param_1 + 5) & 0x3f) == 0 || ((*(byte *)(param_1 + 5) & 0x3f) == 3)))) {
      uVar4 = (uint)(byte)~(p_dmr_call_config_state->field_0x4 != 0);
      if (PTR_DAT_03029610[uVar4 + 0x29] != 0) {
        iVar3 = PTR_DAT_03029610[uVar4 + 0x2b];
        if (((iVar3 != 0) && (*(char *)(iVar3 + 2) == '\x01')) && (*(byte *)(iVar3 + 3) < 6)) {
          *(int *)(iVar3 + 0x20) = param_1;
          PTR_DAT_03029610[uVar4 + 0x2b] = param_1;
        }
      }
    }
    iVar3 = dmr_call_setup_block_d_byte5_read();
    if (iVar3 == 0) {
      modem_mode_select(0,2);
    }
  }
  else if ((p_call_setup_sm_state_aux->mode_0x1 == 4) &&
          (iVar3 = dmr_call_setup_block_d_byte5_read(), iVar3 == 0)) {
    modem_mode_select(0,2);
  }
  return;
}

