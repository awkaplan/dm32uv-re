/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_number_decode_from_menu_index @ 03054274 (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int channel_number_decode_from_menu_index(int param_1__w,uint param_2,byte *param_3,char *param_4)

{
  char param_1 = (char)param_1__w;
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_r5;
  byte local_24;
  byte local_23;
  byte local_22;
  undefined1 local_21;
  byte local_20;
  byte bStack_1f;
  byte bStack_1e;
  
  if (param_1 == '\x03') {
    unaff_r5 = 8;
    param_4 = DAT_03054448;
  }
  else if (param_1 == '\x05') {
    unaff_r5 = 9;
    param_4 = DAT_0305444c;
  }
  else if (param_1 == '\x01') {
    unaff_r5 = 7;
    param_4 = DAT_03054444;
  }
  if (*param_4 == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = dmr_list_header_load(param_1);
    uVar1 = flash_block_id_resolve_locked(unaff_r5);
    flash_block_read(uVar1,(iVar2 - (param_2 & 0xff)) + 0x30 & 0xffff,&local_23,1);
    uVar3 = (uint)local_23;
    if (uVar3 < 0xe) {
      flash_block_read(uVar1,(uVar3 - 1) * 0x110 + 0x130 & 0xfff0,&local_24,1);
      flash_block_read(uVar1,(local_23 - 1) * 0x110 + 0x13d & 0xffff,&local_20,3);
    }
    else {
      contact_char_index_to_display_code(uVar3,param_1,&local_21,&local_22);
      uVar1 = flash_block_id_resolve_locked(local_21);
      flash_block_read(uVar1,(local_22 - 1) * 0x110 & 0xfff0,&local_24,1);
      flash_block_read(uVar1,(local_22 - 1) * 0x110 + 0xd & 0xffff,&local_20,3);
    }
    *param_3 = local_24 >> 2 & 3;
    iVar2 = (uint)bStack_1f * 0x100 + (uint)bStack_1e * 0x10000 + (uint)local_20;
    *p_text_entry_current_char_alias = iVar2;
  }
  return iVar2;
}

