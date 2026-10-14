/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_config_state_reset_and_arm_timer @ 030241b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_config_state_reset_and_arm_timer(void)

{
  undefined1 *puVar1;
  dmr_call_config_state *pdVar2;
  call_setup_sm_state_aux *pcVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_0302432c;
  PTR_DAT_0302432c[9] = PTR_DAT_0302432c[9] & 7;
  *(ushort *)(puVar1 + 8) = *(ushort *)(puVar1 + 8) & 0xf800;
  *puVar1 = 3;
  puVar1[1] = 0;
  puVar1[2] = 0x12;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  puVar1[7] = 0;
  *(ushort *)(puVar1 + 0x12) = *(ushort *)(puVar1 + 0x12) & 0xf;
  uVar4 = lcg_rand_next();
  *(uint *)(puVar1 + 0x10) = *(uint *)(puVar1 + 0x10) & 0xfff00000 | uVar4 & 0xfffff;
  pcVar3 = p_call_setup_sm_state_aux;
  pdVar2 = p_dmr_call_config_state;
  p_dmr_call_config_state->field_0x2 = p_call_setup_sm_state_aux->field_0x4;
  pdVar2->field_0x4 = pcVar3->field_0x3;
  pdVar2->field_0xf = 0;
  guarded_timer_config_apply_wrapper_a(270000);
  flag_byte_clear_and_gpio_reset();
  return;
}

