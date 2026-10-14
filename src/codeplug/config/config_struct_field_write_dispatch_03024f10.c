/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_struct_field_write_dispatch @ 03024f10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 252 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void config_struct_field_write_dispatch(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  dmr_call_config_state *pdVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  byte local_14;
  undefined1 uStack_13;
  byte bStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 auStack_f [7];
  
  if ((((uint)*PTR_DAT_03025014 >> 0x1a & 1) == 0) &&
     (PTR_DAT_03025018[6] == p_call_setup_sm_state_aux->field_0x5)) {
    p_dmr_call_config_state->field_0x3 = 1;
    copy_bytes_from_offset_table(0,&local_14,0xc);
    puVar2 = PTR_DAT_0302500c;
    uVar8 = local_14 & 0xf;
    if (uVar8 == 0xf) {
      PTR_DAT_0302500c[7] = local_14 >> 4;
      puVar2[5] = 0xf;
      puVar2[8] = uStack_13;
      puVar2[0x23] = bStack_12 & 7;
      puVar2[0x24] = uStack_11;
      memcpy_bytes_iram(puVar2 + 0x25,&uStack_10,6);
      puVar3 = PTR_DAT_0302500c;
      if (puVar2[7] == '\x04') {
        memcpy_bytes_iram(DAT_03025024,&bStack_12,8);
      }
      else if (puVar2[7] == '\x01') {
        PTR_DAT_0302500c[0x3b] = 5;
        memcpy_bytes_iram(puVar3 + *(int *)(puVar3 + 900) + 0x5a,auStack_f,5);
        *(int *)(puVar3 + 900) = *(int *)(puVar3 + 900) + 0x1f;
        puVar3[9] = 1;
      }
      if (PTR_DAT_0302500c[0xc] != '\0') {
        PTR_DAT_0302500c[0xc] = PTR_DAT_0302500c[0xc] + -1;
      }
    }
    else {
      iVar7 = call_setup_target_id_decode_and_check(6,&local_14,auStack_18,auStack_1c);
      if (iVar7 == 0) {
        *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
        pdVar4 = p_dmr_call_config_state;
        if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
          bVar1 = *(byte *)p_dmr_call_config_state;
          p_dmr_call_config_state->field_0x2 = bVar1;
          pdVar4->field_0x4 = bVar1;
        }
        memcpy_bytes_iram(DAT_03025028 + (uint)*(byte *)p_dmr_call_config_state * 0xc,&local_14);
        puVar5 = PTR_DAT_03025394;
        if (uVar8 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x0302500a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(PTR_PTR_0302502c[uVar8] & 0xfffffffe))();
          return;
        }
        *(undefined1 *)(PTR_DAT_03025394 + 0xf) = 0;
        puVar5[0xe1] = 0;
        puVar5[0xe3] = 0;
        *(undefined1 *)(puVar5 + 0xe5) = 0;
        puVar6 = PTR_DAT_03025394;
        if (*(char *)((int)puVar5 + 0xb) == '\x01') {
          PTR_DAT_03025394[0xdf] = 0;
          memset_bytes((int)puVar6 + 0x3e,0xff,0x14);
        }
        if ((*(char *)(PTR_DAT_03025394 + 1) == '\x01') && (*(char *)(PTR_DAT_03025394 + 3) == '\0')
           ) {
          OSFlagPost_wrapper_set_passthrough(0x80);
        }
      }
    }
  }
  return;
}

