/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_log_type3_packet_builder @ 030270e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 488 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_log_type3_packet_builder
               (undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,
               undefined4 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
               undefined4 param_9,undefined4 param_10,char param_11)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  puVar5 = PTR_DAT_030271a0;
  *(undefined1 *)PTR_DAT_030271a0 = param_1;
  puVar5[10] = param_9;
  puVar5[0xb] = param_10;
  *(undefined1 *)(puVar5 + 7) = 1;
  puVar6 = PTR_DAT_03027340;
  if (param_2 == '\x01') {
    *(undefined1 *)((int)puVar5 + 1) = 1;
    *(undefined1 *)(puVar5 + 5) = 8;
    *(undefined1 *)(puVar5 + 0xd) = 0x12;
    *(undefined2 *)((int)puVar5 + 0x372) = 0x1ff;
    *(undefined1 *)((int)puVar5 + 0x12) = 0;
    if (param_11 == '\0') {
      *(byte *)((int)puVar5 + 0x13) = *(char *)((int)puVar5 + 0x13) + 1U & 7;
    }
    puVar5 = PTR_DAT_030271a0;
    *(undefined1 *)(PTR_DAT_030271a0 + 1) = 3;
    *(undefined1 *)((int)puVar5 + 0x35) = 8;
    *(undefined1 *)((int)puVar5 + 3) = 0;
    *(undefined1 *)((int)puVar5 + 5) = 9;
    memcpy_bytes_iram(puVar5 + 0x15,param_5,param_6);
    *(undefined2 *)(puVar5 + 0xdb) = param_6;
    *(undefined2 *)(puVar5 + 0xc) = param_7;
    *(undefined2 *)((int)puVar5 + 0x32) = param_8;
    protocol_packet_field_pack_8byte(puVar5,0);
    sVar2 = *(short *)(puVar5 + 0xdb);
    *(ushort *)(puVar5 + 0xdb) = sVar2 + 9U;
    puVar6 = PTR_DAT_03027340;
    iVar8 = (ushort)(sVar2 + 9U) - 6;
    bVar1 = *(byte *)(puVar5 + 0xd);
    iVar9 = bVar1 - 2;
    iVar7 = iVar8 / iVar9;
    cVar4 = (char)iVar7;
    uVar10 = iVar8 - iVar7 * iVar9;
    cVar3 = (char)uVar10;
    if (bVar1 - 6 < uVar10) {
      *(char *)((int)PTR_DAT_03027340 + 0x11) = cVar4 + '\x02';
      *(byte *)((int)puVar6 + 0xf) = (bVar1 - 4) * '\x02' - cVar3;
    }
    else {
      *(char *)((int)PTR_DAT_03027340 + 0x11) = cVar4 + '\x01';
      *(byte *)((int)puVar6 + 0xf) = (bVar1 - 6) - cVar3;
    }
    *(undefined1 *)((int)PTR_DAT_03027340 + 0x26) = *(undefined1 *)((int)PTR_DAT_03027340 + 0x11);
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03027340 + 1) = 0;
    *(undefined1 *)(puVar6 + 5) = 0;
    *(undefined1 *)(puVar6 + 0xd) = 0xc;
    *(undefined2 *)((int)puVar6 + 0x372) = 0xf0;
    *(undefined1 *)(puVar6 + 1) = 2;
    *(undefined1 *)((int)puVar6 + 0x35) = 7;
    *(undefined1 *)((int)puVar6 + 3) = 0;
    *(undefined1 *)((int)puVar6 + 5) = 9;
    memcpy_bytes_iram(puVar6 + 0x15,param_5,param_6);
    *(undefined2 *)(puVar6 + 0xdb) = param_6;
    *(undefined2 *)(puVar6 + 0xc) = param_7;
    *(undefined2 *)((int)puVar6 + 0x32) = param_8;
    protocol_packet_field_pack_8byte(puVar6,0);
    sVar2 = *(short *)(puVar6 + 0xdb);
    *(ushort *)(puVar6 + 0xdb) = sVar2 + 9U;
    puVar5 = PTR_DAT_03027340;
    iVar7 = (ushort)(sVar2 + 9U) - 6;
    bVar1 = *(byte *)(puVar6 + 0xd);
    uVar11 = (uint)bVar1;
    iVar8 = iVar7 / (int)uVar11;
    cVar4 = (char)iVar8;
    uVar10 = iVar7 - uVar11 * iVar8;
    cVar3 = (char)uVar10;
    if (uVar11 - 4 < uVar10) {
      *(char *)((int)PTR_DAT_03027340 + 0x11) = cVar4 + '\x02';
      *(byte *)((int)puVar5 + 0xf) = (bVar1 - 2) * '\x02' - cVar3;
    }
    else {
      *(char *)((int)PTR_DAT_03027340 + 0x11) = cVar4 + '\x01';
      *(byte *)((int)puVar5 + 0xf) = (bVar1 - 4) - cVar3;
    }
    *(undefined1 *)((int)PTR_DAT_03027340 + 0x26) = *(undefined1 *)((int)PTR_DAT_03027340 + 0x11);
  }
  puVar5 = PTR_DAT_03027340;
  history_record_push_type3_repeated
            (param_1,param_9,param_10,param_4,1,*(char *)((int)PTR_DAT_03027340 + 0x11) + '\x01');
  history_record_push_typed(puVar5);
  *(undefined1 *)((int)puVar5 + 5) = 1;
  *(undefined1 *)(puVar5 + 1) = 0xf;
  *(undefined1 *)((int)puVar5 + 6) = 0x10;
  *(undefined1 *)((int)puVar5 + 7) = 2;
  *(char *)(puVar5 + 2) = *(char *)puVar5 * '\x02';
  memcpy_bytes_iram((int)puVar5 + 9,(int)puVar5 + 0x4b,6);
  history_record_push_typed(puVar5);
  *(undefined2 *)((int)puVar5 + 0x36e) = 6;
  dmr_message_split_into_history_slots(puVar5);
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if (param_2 == '\x01') {
      history_slot_alloc_with_data(puVar5);
    }
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return;
}

