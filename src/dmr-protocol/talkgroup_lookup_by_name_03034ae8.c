/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talkgroup_lookup_by_name @ 03034ae8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 244 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 talkgroup_lookup_by_name(undefined4 param_1,undefined2 *param_2,uint param_3)

{
  char cVar1;
  ushort block_id;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort local_3a;
  undefined1 auStack_38 [15];
  undefined1 uStack_29;
  byte local_27;
  ushort local_26;
  
  param_3 = param_3 & 0xffff;
  local_3a = 0;
  if (param_3 == 0) {
    *param_2 = 1;
    uVar2 = 0;
  }
  else {
    block_id = flash_block_id_resolve_locked(0xb);
    uVar4 = 1;
    do {
      iVar3 = param_3 - uVar4;
      uVar5 = uVar4 + iVar3 / 2 & 0xffff;
      flash_block_read(block_id,(uVar5 + 0x7f) * 2 & 0xffff,&local_3a,2);
      local_3a = local_3a & 0xfff;
      talkgroup_index_decode_paged(local_3a,&local_26,&local_27);
      local_26 = flash_block_id_resolve_locked((undefined1)local_26);
      flash_block_read(local_26,(local_27 - 1) * 0x18 + 2 & 0xfffe,auStack_38,0x10);
      uStack_29 = 0;
      cVar1 = strncmp_ck803s(param_1,auStack_38,0x10);
      if (cVar1 < '\x01') {
        if (-1 < cVar1) {
          uVar2 = 1;
          goto LAB_03034bd4;
        }
        if (iVar3 == 1) {
          param_3 = uVar5 - 1 & 0xffff;
        }
        else {
          param_3 = uVar5;
          if (uVar4 == uVar5) {
            uVar2 = 0;
            goto LAB_03034bd4;
          }
        }
      }
      else if (iVar3 == 1) {
        uVar4 = uVar5 + 1 & 0xffff;
      }
      else {
        uVar4 = uVar5;
        if (param_3 == uVar5) goto LAB_03034bca;
      }
    } while (uVar4 <= param_3);
    if (cVar1 < '\x01') {
      uVar2 = 0;
    }
    else {
LAB_03034bca:
      uVar5 = uVar5 + 1 & 0xffff;
      uVar2 = 0;
    }
LAB_03034bd4:
    *param_2 = (short)uVar5;
  }
  return uVar2;
}

