/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_event_record_append_to_history @ 03029708 (file base 0x03000000; code starts at 0x03001000)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool call_event_record_append_to_history
               (char param_1,char param_2,char param_3,undefined4 param_4,uint param_5,
               undefined4 param_6)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = PTR_DAT_03029828;
  PTR_DAT_03029828[3] = param_3;
  puVar1[5] = 0;
  puVar1 = PTR_DAT_03029828;
  if (param_1 == '\x01') {
    if ((p_call_setup_sm_state_aux->mode_0x1 == 2) && (param_5 == 0xff)) {
      bVar3 = 8;
      uVar4 = 0;
    }
    else if ((param_5 & 0xfffff0) == 0xfffff0) {
      bVar3 = 8;
      uVar4 = 0;
    }
    else {
      bVar3 = 0;
      uVar4 = 0;
    }
  }
  else {
    bVar3 = 0;
    uVar4 = 3;
  }
  if (param_2 == '\x01') {
    PTR_DAT_03029828[8] = bVar3 | 0x20;
    puVar1[9] = bVar3;
    puVar1[6] = 1;
    uVar5 = 0x10;
  }
  else {
    PTR_DAT_03029828[8] = bVar3;
    puVar1[9] = bVar3;
    puVar1[6] = 0;
    uVar5 = 0;
  }
  puVar1 = PTR_DAT_03029828;
  if (param_3 == '\x01') {
    bVar3 = PTR_DAT_03029828[8] & 0xbf | 0x40;
    PTR_DAT_03029828[8] = bVar3;
    dmr_call_history_slot_register(uVar4,0x10,bVar3,param_5,param_6);
    dmr_call_history_slot_register(uVar4,0x10,puVar1[8],param_5,param_6);
    dmr_call_history_slot_register(uVar4,0x10,puVar1[8],param_5,param_6);
    dmr_call_history_slot_register_short(param_4);
  }
  else {
    dmr_call_history_slot_register(uVar4,uVar5,PTR_DAT_03029828[8],param_5,param_6);
    dmr_call_history_slot_register(uVar4,uVar5,puVar1[8],param_5,param_6);
    dmr_call_history_slot_register(uVar4,uVar5,puVar1[8],param_5,param_6);
  }
  iVar2 = history_slot_allocate();
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 2) = 1;
    *(undefined1 *)(iVar2 + 3) = 0;
    memset_bytes(iVar2 + 5,0,0x18);
    history_slot_link_append(iVar2);
  }
  return iVar2 == 0;
}

