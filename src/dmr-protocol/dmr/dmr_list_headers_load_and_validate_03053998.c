/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_list_headers_load_and_validate @ 03053998 (file base 0x03000000; code starts at 0x03001000)
 * Size: 332 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_list_headers_load_and_validate(void)

{
  undefined1 uVar1;
  ushort block_id;
  int iVar2;
  uint uVar3;
  undefined1 auStack_84 [100];
  undefined1 auStack_20 [16];
  char acStack_10 [4];
  
  iVar2 = flash_block_id_resolve_locked(7);
  flash_block_read((ushort)iVar2,0xfff,acStack_10,1);
  PTR_DAT_03053af0[1] = 0;
  if (acStack_10[0] == '\a') {
    uVar1 = dmr_contact_list1_active_count();
    PTR_DAT_03053af0[1] = uVar1;
  }
  else {
    flash_mutex_guarded_op(iVar2);
    mutex_guarded_param_dispatch_1(iVar2 << 0xc | 0xfff,7);
    flash_page_invalidate_range_locked();
  }
  uVar1 = dmr_list_header_load(1);
  PTR_DAT_03053af4[0xc] = uVar1;
  block_id = flash_block_id_resolve_locked(7);
  flash_block_read(block_id,0,auStack_20,0xd);
  flash_block_read(block_id,0x30,auStack_84,100);
  uVar3 = zero_bit_count_13byte_prefix(auStack_20);
  if (uVar3 < 100) {
    PTR_DAT_03053af8[1] = PTR_DAT_03053af8[1] & 0xdf;
  }
  else {
    PTR_DAT_03053af8[1] = PTR_DAT_03053af8[1] & 0xdf | 0x20;
  }
  iVar2 = flash_block_id_resolve_locked(8);
  flash_block_read((ushort)iVar2,0xfff,acStack_10,1);
  if (acStack_10[0] != '\b') {
    flash_mutex_guarded_op(iVar2);
    mutex_guarded_param_dispatch_1(iVar2 << 0xc | 0xfff,8);
    flash_page_invalidate_range_locked();
  }
  uVar1 = dmr_list_header_load(3);
  PTR_DAT_03053af4[0x14] = uVar1;
  iVar2 = flash_block_id_resolve_locked(9);
  flash_block_read((ushort)iVar2,0xfff,acStack_10,1);
  if (acStack_10[0] != '\t') {
    flash_mutex_guarded_op(iVar2);
    mutex_guarded_param_dispatch_1(iVar2 << 0xc | 0xfff,9);
    flash_page_invalidate_range_locked();
  }
  uVar1 = dmr_list_header_load(5);
  PTR_DAT_03053af4[0x1c] = uVar1;
  iVar2 = flash_block_id_resolve_locked(10);
  flash_block_read((ushort)iVar2,0xfff,acStack_10,1);
  if (acStack_10[0] != '\n') {
    flash_mutex_guarded_op(iVar2);
    mutex_guarded_param_dispatch_1(iVar2 << 0xc | 0xfff,10);
    flash_page_invalidate_range_locked();
  }
  uVar1 = dmr_list_count_block10_clamped();
  PTR_DAT_03053af4[4] = uVar1;
  return;
}

