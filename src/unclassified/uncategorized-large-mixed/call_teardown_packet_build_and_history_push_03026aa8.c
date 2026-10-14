/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_teardown_packet_build_and_history_push @ 03026aa8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 410 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
call_teardown_packet_build_and_history_push
          (undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,undefined2 param_5,
          short param_6,undefined4 param_7,undefined4 param_8,char param_9)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  puVar4 = PTR_DAT_03026c44;
  *(undefined1 *)PTR_DAT_03026c44 = param_1;
  *(undefined1 *)(puVar4 + 7) = 1;
  puVar4[10] = param_7;
  puVar4[0xb] = param_8;
  puVar5 = PTR_DAT_03026c44;
  if (param_2 == '\x01') {
    *(undefined1 *)((int)puVar4 + 1) = 1;
    *(undefined1 *)(puVar4 + 5) = 8;
    *(undefined1 *)(puVar4 + 0xd) = 0x12;
    *(undefined2 *)((int)puVar4 + 0x372) = 0x1ff;
    *(undefined1 *)((int)puVar4 + 0x12) = 0;
    if (param_9 == '\0') {
      *(byte *)((int)puVar4 + 0x13) = *(char *)((int)puVar4 + 0x13) + 1U & 7;
    }
    puVar4 = PTR_DAT_03026c44;
    *(undefined1 *)(PTR_DAT_03026c44 + 1) = 3;
    *(undefined1 *)((int)puVar4 + 0x35) = 8;
    *(undefined1 *)((int)puVar4 + 5) = 4;
    *(undefined1 *)((int)puVar4 + 3) = 0;
    *(undefined2 *)(puVar4 + 0xdb) = 0;
    *(undefined2 *)(puVar4 + 0xc) = param_5;
    *(short *)((int)puVar4 + 0x32) = param_6 + -0x80;
    protocol_packet_build_with_checksum(puVar4,1);
    uVar8 = *(short *)(puVar4 + 0xdb) + 0x21;
    *(ushort *)(puVar4 + 0xdb) = uVar8;
    puVar5 = PTR_DAT_03026c44;
    bVar1 = *(byte *)(puVar4 + 0xd);
    iVar7 = bVar1 - 2;
    iVar6 = (int)(uint)uVar8 / iVar7;
    cVar3 = (char)iVar6;
    uVar9 = (uint)uVar8 - iVar6 * iVar7;
    cVar2 = (char)uVar9;
    if (bVar1 - 6 < uVar9) {
      *(char *)((int)PTR_DAT_03026c44 + 0x11) = cVar3 + '\x02';
      *(byte *)((int)puVar5 + 0xf) = (bVar1 - 4) * '\x02' - cVar2;
    }
    else {
      *(char *)((int)PTR_DAT_03026c44 + 0x11) = cVar3 + '\x01';
      *(byte *)((int)puVar5 + 0xf) = (bVar1 - 6) - cVar2;
    }
    *(undefined1 *)((int)PTR_DAT_03026c44 + 0x26) = *(undefined1 *)((int)PTR_DAT_03026c44 + 0x11);
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03026c44 + 1) = 0;
    *(undefined1 *)(puVar5 + 5) = 0;
    *(undefined1 *)(puVar5 + 0xd) = 0xc;
    *(undefined2 *)((int)puVar5 + 0x372) = 0xf0;
    *(undefined1 *)(puVar5 + 1) = 2;
    *(undefined1 *)((int)puVar5 + 0x35) = 7;
    *(undefined1 *)((int)puVar5 + 5) = 4;
    *(undefined1 *)((int)puVar5 + 3) = 0;
    *(undefined2 *)(puVar5 + 0xdb) = 0;
    *(undefined2 *)(puVar5 + 0xc) = param_5;
    *(short *)((int)puVar5 + 0x32) = param_6 + -0x80;
    protocol_packet_build_with_checksum(puVar5,1);
    uVar8 = *(short *)(puVar5 + 0xdb) + 0x21;
    *(ushort *)(puVar5 + 0xdb) = uVar8;
    puVar4 = PTR_DAT_03026c44;
    bVar1 = *(byte *)(puVar5 + 0xd);
    uVar10 = (uint)bVar1;
    uVar9 = uVar8 / uVar10;
    cVar3 = (char)uVar9;
    uVar9 = (uint)uVar8 - uVar10 * uVar9;
    cVar2 = (char)uVar9;
    if (uVar10 - 4 < uVar9) {
      *(char *)((int)PTR_DAT_03026c44 + 0x11) = cVar3 + '\x02';
      *(byte *)((int)puVar4 + 0xf) = (bVar1 - 2) * '\x02' - cVar2;
    }
    else {
      *(char *)((int)PTR_DAT_03026c44 + 0x11) = cVar3 + '\x01';
      *(byte *)((int)puVar4 + 0xf) = (bVar1 - 4) - cVar2;
    }
    *(undefined1 *)((int)PTR_DAT_03026c44 + 0x26) = *(undefined1 *)((int)PTR_DAT_03026c44 + 0x11);
  }
  puVar4 = PTR_DAT_03026c44;
  history_record_push_type3_repeated
            (param_1,param_7,param_8,param_4,1,*(char *)((int)PTR_DAT_03026c44 + 0x11) + '\x01');
  history_record_push_typed(puVar4);
  *(undefined2 *)((int)puVar4 + 0x36e) = 0;
  dmr_message_split_into_history_slots(puVar4);
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    if (param_2 == '\x01') {
      history_slot_alloc_with_data(puVar4);
    }
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return 0;
}

