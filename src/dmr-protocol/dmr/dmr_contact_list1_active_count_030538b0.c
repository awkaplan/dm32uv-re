/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_contact_list1_active_count @ 030538b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char dmr_contact_list1_active_count(void)

{
  ushort block_id;
  ushort block_id_00;
  uint uVar1;
  uint uVar2;
  char cVar3;
  byte bStack_2b;
  undefined1 uStack_2a;
  byte bStack_29;
  byte abStack_28 [4];
  
  uVar1 = dmr_list_header_load(1);
  block_id = flash_block_id_resolve_locked(7);
  if (uVar1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\0';
    do {
      flash_block_read(block_id,uVar1 + 0x2f & 0xffff,&bStack_29,1);
      uVar2 = (uint)bStack_29;
      if (uVar2 < 0xe) {
        flash_block_read(block_id,(uVar2 - 1) * 0x110 + 0x130 & 0xfff0,abStack_28,1);
      }
      else {
        contact_char_index_to_display_code(uVar2,1,&uStack_2a,&bStack_2b);
        block_id_00 = flash_block_id_resolve_locked(uStack_2a);
        flash_block_read(block_id_00,(bStack_2b - 1) * 0x110 & 0xfff0,abStack_28,1);
      }
      if ((abStack_28[0] & 3) == 3) {
        cVar3 = cVar3 + '\x01';
      }
      uVar1 = uVar1 - 1 & 0xff;
    } while (uVar1 != 0);
  }
  return cVar3;
}

