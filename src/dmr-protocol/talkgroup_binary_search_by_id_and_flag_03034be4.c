/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talkgroup_binary_search_by_id_and_flag @ 03034be4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 372 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
talkgroup_binary_search_by_id_and_flag(uint param_1,undefined2 *param_2,uint param_3,char param_4)

{
  bool bVar1;
  ushort block_id;
  undefined4 uVar2;
  uint unaff_r4;
  uint uVar3;
  int iStack_40;
  char cStack_2f;
  ushort local_2e;
  uint local_2c;
  byte local_27;
  ushort local_26;
  
  param_3 = param_3 & 0xffff;
  local_2c = 0;
  local_2e = 0;
  if (param_3 == 0) {
    *param_2 = 1;
    uVar2 = 0;
  }
  else {
    block_id = flash_block_id_resolve_locked(0xb);
    iStack_40 = 0;
    bVar1 = false;
    uVar3 = 1;
    do {
      if (bVar1) {
        if (iStack_40 == 0) {
          unaff_r4 = unaff_r4 - 1 & 0xffff;
          iStack_40 = 1;
        }
        else {
          unaff_r4 = unaff_r4 + 2 & 0xffff;
          iStack_40 = 2;
        }
      }
      else {
        unaff_r4 = uVar3 + (int)(param_3 - uVar3) / 2 & 0xffff;
      }
      flash_block_read(block_id,(unaff_r4 + 0x39f) * 2 & 0xffff,&local_2e,2);
      local_2e = local_2e & 0xfff;
      talkgroup_index_decode_paged(local_2e,&local_26,&local_27);
      local_26 = flash_block_id_resolve_locked((undefined1)local_26);
      flash_block_read(local_26,(local_27 - 1) * 0x18 + 0x13 & 0xffff,&local_2c,3);
      if (local_2c < param_1) {
        if (bVar1) {
          if (iStack_40 == 2) {
            uVar2 = 0;
            goto LAB_03034d44;
          }
        }
        else if (param_3 - uVar3 == 1) {
          uVar3 = unaff_r4 + 1 & 0xffff;
        }
        else {
          uVar3 = unaff_r4;
          if (unaff_r4 == param_3) {
            uVar2 = 0;
            goto LAB_03034d44;
          }
        }
      }
      else if (param_1 < local_2c) {
        if (bVar1) {
          if (iStack_40 == 2) {
            uVar2 = 0;
            goto LAB_03034d50;
          }
        }
        else if (param_3 - uVar3 == 1) {
          param_3 = unaff_r4 - 1 & 0xffff;
        }
        else {
          param_3 = unaff_r4;
          if (uVar3 == unaff_r4) {
            uVar2 = 0;
            goto LAB_03034d50;
          }
        }
      }
      else {
        flash_block_read(local_26,(local_27 - 1) * 0x18 + 0x16 & 0xfffe,&cStack_2f,1);
        if (cStack_2f == param_4) {
          uVar2 = 1;
          goto LAB_03034d32;
        }
        if (bVar1) {
          if (iStack_40 == 1) {
            uVar2 = 0;
            goto LAB_03034d32;
          }
        }
        else {
          bVar1 = true;
        }
      }
    } while (uVar3 <= param_3);
    uVar2 = 0;
LAB_03034d32:
    if (local_2c < param_1) {
LAB_03034d44:
      unaff_r4 = unaff_r4 + 1 & 0xffff;
    }
LAB_03034d50:
    *param_2 = (short)unaff_r4;
  }
  return uVar2;
}

