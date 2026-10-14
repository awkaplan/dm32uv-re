/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_packet_build_and_history_push @ 03026f0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 456 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_packet_build_and_history_push
               (undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,
               undefined2 param_5,short param_6,undefined4 param_7,undefined4 param_8,char param_9)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  puVar5 = PTR_DAT_03026fb4;
  *(undefined1 *)PTR_DAT_03026fb4 = param_1;
  *(undefined4 *)(puVar5 + 0x14) = param_7;
  *(undefined4 *)(puVar5 + 0x16) = param_8;
  *(undefined1 *)(puVar5 + 0xe) = 1;
  puVar6 = PTR_DAT_030271a0;
  if (param_2 == '\x01') {
    *(undefined1 *)((int)puVar5 + 1) = 1;
    *(undefined1 *)(puVar5 + 10) = 8;
    *(undefined1 *)(puVar5 + 0x1a) = 0x12;
    puVar5[0x1b9] = 0x1ff;
    *(undefined1 *)(puVar5 + 9) = 0;
    if (param_9 == '\0') {
      *(byte *)((int)puVar5 + 0x13) = *(char *)((int)puVar5 + 0x13) + 1U & 7;
    }
    puVar5 = PTR_DAT_03026fb4;
    *(undefined1 *)(PTR_DAT_03026fb4 + 2) = 3;
    *(undefined1 *)((int)puVar5 + 0x35) = 8;
    *(undefined1 *)((int)puVar5 + 3) = 0;
    *(undefined1 *)((int)puVar5 + 5) = 9;
    puVar5[0x1b6] = 0;
    puVar5[0x18] = param_5;
    puVar5[0x19] = param_6 + -0x80;
    protocol_packet_field_pack_8byte(puVar5,1);
    sVar2 = puVar5[0x1b6];
    puVar5[0x1b6] = sVar2 + 8U;
    puVar6 = PTR_DAT_030271a0;
    iVar9 = (ushort)(sVar2 + 8U) - 6;
    bVar1 = *(byte *)(puVar5 + 0x1a);
    iVar10 = bVar1 - 2;
    iVar8 = iVar9 / iVar10;
    cVar4 = (char)iVar8;
    uVar11 = iVar9 - iVar8 * iVar10;
    cVar3 = (char)uVar11;
    if (bVar1 - 6 < uVar11) {
      *(char *)((int)PTR_DAT_030271a0 + 0x11) = cVar4 + '\x02';
      *(byte *)((int)puVar6 + 0xf) = (bVar1 - 4) * '\x02' - cVar3;
    }
    else {
      *(char *)((int)PTR_DAT_030271a0 + 0x11) = cVar4 + '\x01';
      *(byte *)((int)puVar6 + 0xf) = (bVar1 - 6) - cVar3;
    }
    *(undefined1 *)((int)PTR_DAT_030271a0 + 0x26) = *(undefined1 *)((int)PTR_DAT_030271a0 + 0x11);
  }
  else {
    *(undefined1 *)((int)PTR_DAT_030271a0 + 1) = 0;
    *(undefined1 *)(puVar6 + 5) = 0;
    *(undefined1 *)(puVar6 + 0xd) = 0xc;
    *(undefined2 *)((int)puVar6 + 0x372) = 0xf0;
    *(undefined1 *)(puVar6 + 1) = 2;
    *(undefined1 *)((int)puVar6 + 0x35) = 7;
    *(undefined1 *)((int)puVar6 + 3) = 0;
    *(undefined1 *)((int)puVar6 + 5) = 9;
    *(undefined2 *)(puVar6 + 0xdb) = 0;
    *(undefined2 *)(puVar6 + 0xc) = param_5;
    *(short *)((int)puVar6 + 0x32) = param_6 + -0x80;
    protocol_packet_field_pack_8byte(puVar6,1);
    sVar2 = *(short *)(puVar6 + 0xdb);
    *(ushort *)(puVar6 + 0xdb) = sVar2 + 8U;
    puVar7 = PTR_DAT_030271a0;
    iVar8 = (ushort)(sVar2 + 8U) - 6;
    bVar1 = *(byte *)(puVar6 + 0xd);
    uVar12 = (uint)bVar1;
    iVar9 = iVar8 / (int)uVar12;
    cVar4 = (char)iVar9;
    uVar11 = iVar8 - uVar12 * iVar9;
    cVar3 = (char)uVar11;
    if (uVar12 - 4 < uVar11) {
      *(char *)((int)PTR_DAT_030271a0 + 0x11) = cVar4 + '\x02';
      *(byte *)((int)puVar7 + 0xf) = (bVar1 - 2) * '\x02' - cVar3;
    }
    else {
      *(char *)((int)PTR_DAT_030271a0 + 0x11) = cVar4 + '\x01';
      *(byte *)((int)puVar7 + 0xf) = (bVar1 - 4) - cVar3;
    }
    *(undefined1 *)((int)PTR_DAT_030271a0 + 0x26) = *(undefined1 *)((int)PTR_DAT_030271a0 + 0x11);
  }
  puVar6 = PTR_DAT_030271a0;
  history_record_push_type3_repeated
            (param_1,param_7,param_8,param_4,1,*(char *)((int)PTR_DAT_030271a0 + 0x11) + '\x01');
  history_record_push_typed(puVar6);
  *(undefined1 *)((int)puVar6 + 5) = 1;
  *(undefined1 *)(puVar6 + 1) = 0xf;
  *(undefined1 *)((int)puVar6 + 6) = 0x10;
  *(undefined1 *)((int)puVar6 + 7) = 2;
  *(char *)(puVar6 + 2) = *(char *)puVar6 * '\x02';
  memcpy_bytes_iram((int)puVar6 + 9,(int)puVar6 + 0x4b,6);
  history_record_push_typed(puVar6);
  *(undefined2 *)((int)puVar6 + 0x36e) = 6;
  dmr_message_split_into_history_slots(puVar6);
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if (param_2 == '\x01') {
      history_slot_alloc_with_data(puVar6);
    }
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return;
}

