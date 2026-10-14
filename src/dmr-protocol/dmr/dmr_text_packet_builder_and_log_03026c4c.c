/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_text_packet_builder_and_log @ 03026c4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 694 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
dmr_text_packet_builder_and_log
          (undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5,
          short param_6,undefined2 param_7,undefined2 param_8,undefined4 param_9,undefined4 param_10
          ,char param_11)

{
  char cVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  puVar3 = PTR_DAT_03026e1c;
  *(undefined1 *)PTR_DAT_03026e1c = param_1;
  *(undefined4 *)(puVar3 + 0x14) = param_9;
  *(undefined4 *)(puVar3 + 0x16) = param_10;
  *(undefined1 *)(puVar3 + 0xe) = 1;
  puVar4 = PTR_DAT_03026e1c;
  if (param_2 == '\x01') {
    *(undefined1 *)((int)puVar3 + 1) = 1;
    *(undefined1 *)(puVar3 + 10) = 8;
    *(undefined1 *)(puVar3 + 0x1a) = 0x12;
    puVar3[0x1b9] = 0x1ff;
    *(undefined1 *)(puVar3 + 9) = 0;
    if (param_11 == '\0') {
      *(byte *)((int)puVar3 + 0x13) = *(char *)((int)puVar3 + 0x13) + 1U & 7;
    }
    if ((byte)(p_radio_mode_state_0003e318[1].flags_0x5 - 1) < 2) {
      *(undefined1 *)(PTR_DAT_03026e1c + 2) = 3;
    }
    else {
      *(undefined1 *)(PTR_DAT_03026e1c + 2) = 0xd;
    }
    *(undefined1 *)((int)PTR_DAT_03026e1c + 0x35) = 8;
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03026e1c + 1) = 0;
    *(undefined1 *)(puVar4 + 10) = 0;
    *(undefined1 *)(puVar4 + 0x1a) = 0xc;
    puVar4[0x1b9] = 0xf0;
    if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
      if ((byte)(p_radio_mode_state_0003e318[1].flags_0x5 - 1) < 2) {
        *(undefined1 *)(PTR_DAT_03026e1c + 2) = 2;
      }
      else {
        *(undefined1 *)(PTR_DAT_03026e1c + 2) = 0xd;
      }
    }
    else {
      *(undefined1 *)(PTR_DAT_03026e1c + 2) = 2;
    }
    *(undefined1 *)((int)PTR_DAT_03026e1c + 0x35) = 7;
  }
  *(undefined1 *)((int)PTR_DAT_03026e1c + 3) = 0;
  puVar3 = PTR_DAT_03026e1c;
  if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
    if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
      *(undefined1 *)((int)PTR_DAT_03026e1c + 5) = 4;
      memcpy_bytes_iram((int)puVar3 + 0x6d,param_5,param_6);
    }
    else if (p_radio_mode_state_0003e318[1].flags_0x5 == 2) {
      *(undefined1 *)((int)PTR_DAT_03026e1c + 5) = 3;
      memcpy_bytes_iram((int)puVar3 + 0x4b,param_5,param_6);
      puVar3 = PTR_DAT_03026e1c;
      *(char *)((int)PTR_DAT_03026e1c + 0x4b) = (char)param_7;
      *(char *)(puVar3 + 0x26) = (char)((ushort)param_7 >> 8);
    }
    else {
      *(undefined1 *)((int)PTR_DAT_03026e1c + 5) = 10;
      memcpy_bytes_iram((int)puVar3 + 0x4b,param_5,param_6);
    }
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03026e1c + 5) = 3;
    memcpy_bytes_iram(puVar3 + 0x28,param_5,param_6);
  }
  puVar3 = PTR_DAT_03026e1c;
  PTR_DAT_03026e1c[0x1b6] = param_6;
  puVar3[0x18] = param_7;
  puVar3[0x19] = param_8;
  puVar3 = PTR_DAT_03026e1c;
  if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
    if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
      protocol_packet_build_with_checksum(PTR_DAT_03026e1c,0);
      puVar3[0x1b6] = puVar3[0x1b6] + 0x22;
    }
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03026e1c + 0x4b) = 0;
    *(undefined1 *)(puVar3 + 0x26) = 1;
    *(undefined1 *)((int)puVar3 + 0x4d) = 0;
    *(undefined1 *)(puVar3 + 0x27) = 0;
    *(undefined1 *)((int)puVar3 + 0x4f) = 0;
    puVar3[0x1b6] = param_6 + 6;
  }
  puVar4 = PTR_DAT_03026fb4;
  puVar3 = PTR_DAT_03026e1c;
  if (param_2 == '\x01') {
    bVar9 = *(byte *)(PTR_DAT_03026e1c + 0x1a);
    iVar7 = bVar9 - 2;
    iVar5 = (int)(uint)(ushort)PTR_DAT_03026e1c[0x1b6] / iVar7;
    cVar2 = (char)iVar5;
    uVar8 = (uint)(ushort)PTR_DAT_03026e1c[0x1b6] - iVar5 * iVar7;
    cVar1 = (char)uVar8;
    if (bVar9 - 6 < uVar8) {
      *(char *)((int)PTR_DAT_03026e1c + 0x11) = cVar2 + '\x02';
      *(byte *)((int)puVar3 + 0xf) = (bVar9 - 4) * '\x02' - cVar1;
    }
    else {
      *(char *)((int)PTR_DAT_03026fb4 + 0x11) = cVar2 + '\x01';
      *(byte *)((int)puVar4 + 0xf) = (bVar9 - 6) - cVar1;
    }
    puVar3 = PTR_DAT_03026fb4;
    *(undefined1 *)(PTR_DAT_03026fb4 + 0x13) = *(undefined1 *)((int)PTR_DAT_03026fb4 + 0x11);
    uVar6 = puVar3[0x1b6] + 4;
    uVar8 = (uint)uVar6;
    bVar9 = *(char *)(puVar3 + 0x1a) - 2;
    uVar10 = (uint)bVar9;
    if (uVar8 == uVar10 * (uVar8 / uVar10)) {
      *(undefined1 *)(PTR_DAT_03026fb4 + 0xf) = 0;
    }
    else {
      *(byte *)(PTR_DAT_03026fb4 + 0xf) =
           (((char)(uVar8 / uVar10) + '\x01') * bVar9 - (char)uVar6) * '\b';
    }
  }
  else {
    bVar9 = *(byte *)(PTR_DAT_03026fb4 + 0x1a);
    uVar10 = (uint)bVar9;
    uVar8 = (ushort)PTR_DAT_03026fb4[0x1b6] / uVar10;
    cVar2 = (char)uVar8;
    uVar8 = (uint)(ushort)PTR_DAT_03026fb4[0x1b6] - uVar10 * uVar8;
    cVar1 = (char)uVar8;
    if (uVar10 - 4 < uVar8) {
      *(char *)((int)PTR_DAT_03026fb4 + 0x11) = cVar2 + '\x02';
      *(byte *)((int)puVar4 + 0xf) = (bVar9 - 2) * '\x02' - cVar1;
    }
    else {
      *(char *)((int)PTR_DAT_03026fb4 + 0x11) = cVar2 + '\x01';
      *(byte *)((int)puVar4 + 0xf) = (bVar9 - 4) - cVar1;
    }
    *(undefined1 *)(PTR_DAT_03026fb4 + 0x13) = *(undefined1 *)((int)PTR_DAT_03026fb4 + 0x11);
  }
  if (p_radio_mode_state_0003e318[1].flags_0x5 == 0) {
    *(undefined1 *)(PTR_DAT_03026fb4 + 1) = *(undefined1 *)((int)PTR_DAT_03026fb4 + 0x11);
  }
  puVar3 = PTR_DAT_03026fb4;
  history_record_push_type3_repeated
            (param_1,param_9,param_10,param_4,1,*(char *)((int)PTR_DAT_03026fb4 + 0x11) + '\x01');
  history_record_push_typed(puVar3);
  puVar3[0x1b7] = 0;
  dmr_message_split_into_history_slots(puVar3);
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if (param_2 == '\x01') {
      history_slot_alloc_with_data(puVar3);
    }
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return 0;
}

