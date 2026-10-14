/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_save_flow1 @ 03053be4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 494 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 contact_edit_save_flow1(undefined4 param_1,int param_2__w,int param_3__w,int param_4__w)

{
  undefined2 param_2 = (undefined2)param_2__w;
  char param_3 = (char)param_3__w;
  byte param_4 = (byte)param_4__w;
  ushort block_id;
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  undefined4 unaff_r5;
  byte bVar5;
  char *unaff_r10;
  byte local_aa;
  undefined1 local_a9;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  byte local_98 [99];
  byte bStack_35;
  undefined1 auStack_34 [16];
  
  local_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  os_sem_pend_ms(p_ucos_mutex_0003ea50,0);
  if (param_3 == '\x03') {
    unaff_r5 = 8;
    unaff_r10 = DAT_03053ee0;
  }
  else if (param_3 == '\x05') {
    unaff_r5 = 9;
    unaff_r10 = DAT_03053ee4;
  }
  else if ((param_3 == '\x01') || (param_3 == '\x01')) {
    local_a8 = local_a8 & 0xfffffff0 | 3;
    PTR_DAT_03053cf0[1] = PTR_DAT_03053cf0[1] + '\x01';
    PTR_DAT_03053cf4[1] = PTR_DAT_03053cf4[1] & 0xdf;
    unaff_r5 = 7;
    unaff_r10 = DAT_03053cf8;
    goto LAB_03053c46;
  }
  local_a8 = local_a8 & 0xfffffff0 | 1;
LAB_03053c46:
  bVar5 = (param_4 & 3) << 2 | (byte)local_a8;
  SUBPIECE_SET(local_a8, 0, 2, CONCAT11((char)param_2,bVar5));
  block_id = flash_block_id_resolve_locked(unaff_r5);
  flash_block_read(block_id,0,auStack_34,0xd);
  flash_block_read(block_id,0x30,local_98,100);
  uVar1 = zero_bit_count_13byte_prefix(auStack_34);
  if (uVar1 < 100) {
    uVar2 = byte_field_first_set_bit_position(auStack_34);
    bitarray_set_or_clear_bit(uVar2,auStack_34,1);
    local_98[uVar1] = (byte)uVar2;
    *unaff_r10 = *unaff_r10 + '\x01';
    if ((uVar1 == 99) && (param_3 == '\x01')) {
      PTR_DAT_03053cf4[1] = PTR_DAT_03053cf4[1] & 0xdf | 0x20;
    }
  }
  else {
    uVar2 = (uint)local_98[0];
    if (0 < (int)(uVar1 - 1)) {
      uVar4 = 0;
      do {
        local_98[uVar4] = local_98[uVar4 + 1];
        uVar4 = uVar4 + 1 & 0xff;
      } while ((int)uVar4 < (int)(uVar1 - 1));
    }
    bStack_35 = local_98[0];
    if (param_3 == '\x01') {
      PTR_DAT_03053ed8[1] = PTR_DAT_03053ed8[1] & 0xdf | 0x20;
    }
  }
  contact_char_index_to_display_code(uVar2,param_3,&local_a9,&local_aa);
  if (uVar2 < 0xe) {
    sVar3 = (local_aa - 1) * 0x110;
    flash_record_commit_4field
              (unaff_r5,0,auStack_34,0xd,0x30,local_98,100,sVar3 + 0x130,&local_a8,0xd,sVar3 + 0x13d
               ,param_1,param_2);
  }
  else {
    sVar3 = (local_aa - 1) * 0x110;
    flash_page_read_modify_write(local_a9,sVar3,&local_a8,0xd,sVar3 + 0xd,param_1,param_2);
    flash_page_read_modify_write(unaff_r5,0,auStack_34,0xd,0x30,local_98,100);
  }
  os_sem_post(p_ucos_mutex_0003ea50);
  return 1;
}

