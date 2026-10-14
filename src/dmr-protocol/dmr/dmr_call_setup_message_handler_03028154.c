/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_message_handler @ 03028154 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_setup_message_handler(void)

{
  dword dVar1;
  dmr_call_config_state *pdVar2;
  call_setup_sm_state_aux *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  byte bStack_14;
  char cStack_13;
  char cStack_d;
  
  dVar1 = SystemControl_Type_11000000.RX_TYPE_INFO;
  if ((dVar1 >> 0x1a & 1) == 0) {
    copy_bytes_from_offset_table(0,&bStack_14,0xc);
    iVar5 = call_setup_target_id_decode_and_check(3,&bStack_14,auStack_18,auStack_1c);
    puVar4 = PTR_DAT_03028210;
    if (iVar5 == 0) {
      *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
      if ((cStack_13 == '\x10') && ((bStack_14 & 0x3f) == 0x3e)) {
        call_setup_frame_ack_state_machine(&bStack_14);
      }
    }
    else if ((cStack_13 == '\x10') && ((bStack_14 & 0x3f) == 0x3d)) {
      if (p_call_setup_sm_state_aux->field_0x15 == 0) {
        PTR_DAT_03028210[0x73] = cStack_d;
        pcVar3 = p_call_setup_sm_state_aux;
        bVar6 = cStack_d + 1U & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar6;
        pcVar3->field_0x4 = bVar6;
        pdVar2 = p_dmr_call_config_state;
        p_dmr_call_config_state->field_0x2 = bVar6;
        pdVar2->field_0x4 = bVar6;
        iVar5 = call_index_get_1based();
        iVar7 = (int)((byte)puVar4[0x73] + 1) >> 1;
        if (iVar5 != iVar7) {
          call_abort_by_index(iVar7);
        }
      }
      p_dmr_call_config_state->field_0x3 = 0;
    }
  }
  return;
}

