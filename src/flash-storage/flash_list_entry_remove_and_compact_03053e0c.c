/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_list_entry_remove_and_compact @ 03053e0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 204 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_list_entry_remove_and_compact(uint param_1,char param_2)

{
  ushort block_id;
  uint uVar1;
  char *unaff_r5;
  undefined4 unaff_r6;
  uint uVar2;
  undefined1 auStack_94 [100];
  undefined1 auStack_30 [16];
  
  os_sem_pend_ms(p_ucos_mutex_0003ea50,0);
  if (param_2 == '\x03') {
    unaff_r6 = 8;
    unaff_r5 = DAT_03053ee0;
  }
  else if (param_2 == '\x05') {
    unaff_r6 = 9;
    unaff_r5 = DAT_03053ee4;
  }
  else if (param_2 == '\x01') {
    PTR_DAT_03053ed8[1] = PTR_DAT_03053ed8[1] & 0xdf;
    unaff_r6 = 7;
    unaff_r5 = DAT_03053ee8;
  }
  if (*unaff_r5 == '\0') {
    os_sem_post(p_ucos_mutex_0003ea50);
  }
  else {
    block_id = flash_block_id_resolve_locked(unaff_r6);
    uVar1 = dmr_list_header_load(param_2);
    flash_block_read(block_id,0,auStack_30,0xd);
    flash_block_read(block_id,0x30,auStack_94,100);
    uVar2 = uVar1 - (param_1 & 0xff);
    bitarray_set_or_clear_bit(auStack_94[uVar2],auStack_30,0);
    for (; uVar2 = uVar2 & 0xff, uVar2 < uVar1; uVar2 = uVar2 + 1) {
      auStack_94[uVar2] = auStack_94[uVar2 + 1];
    }
    flash_page_read_modify_write(unaff_r6,0,auStack_30,0xd,0x30,auStack_94,100);
    *unaff_r5 = *unaff_r5 + -1;
    os_sem_post(p_ucos_mutex_0003ea50);
  }
  return;
}

