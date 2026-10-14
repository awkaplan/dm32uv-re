/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: apply_flags_from_flash_0x65_0x66 @ 0305d544 (file base 0x03000000; code starts at 0x03001000)
 * Size: 444 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void apply_flags_from_flash_0x65_0x66(void)

{
  undefined1 *puVar1;
  ushort block_id;
  char cVar2;
  byte bVar3;
  byte local_d;
  
  block_id = flash_block_id_resolve_locked(4);
  puVar1 = PTR_DAT_0305d6ec;
  flash_block_read(block_id,0x66,PTR_DAT_0305d6ec,1);
  if ((byte)*puVar1 < 0xc) {
    cVar2 = (*puVar1 + 1) * '\n';
    p_dialog_flags_from_flash->field_0x2c = cVar2;
    if (cVar2 == '\0') {
      p_dialog_flags_from_flash->field_0x2c = 0x78;
    }
  }
  else {
    p_dialog_flags_from_flash->field_0x2c = 10;
  }
  flash_block_read(block_id,0x65,&local_d,1);
  if ((local_d & 8) == 0) {
    set_status_bit_dispatch(1,0);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xf7;
  }
  else {
    set_status_bit_dispatch(1,1);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xf7 | 8;
  }
  if ((char)local_d < '\0') {
    set_status_bit_dispatch(2,1);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xef | 0x10;
  }
  else {
    set_status_bit_dispatch(2,0);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xef;
  }
  if ((local_d & 0x40) == 0) {
    set_status_bit_dispatch(3,0);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xdf;
  }
  else {
    set_status_bit_dispatch(3,1);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xdf | 0x20;
  }
  if ((local_d & 0x20) == 0) {
    set_status_bit_dispatch(5,0);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xfb;
  }
  else {
    set_status_bit_dispatch(5,1);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xfb | 4;
  }
  if ((local_d & 0x10) == 0) {
    set_status_bit_dispatch(4,0);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xbf;
  }
  else {
    set_status_bit_dispatch(4,1);
    *(byte *)p_dialog_flags_from_flash = *(byte *)p_dialog_flags_from_flash & 0xbf | 0x40;
  }
  bVar3 = local_d >> 1 & 3;
  p_radio_mode_state_0003e318[1].flags_0x5 = bVar3;
  if (1 < bVar3) {
    p_radio_mode_state_0003e318[1].flags_0x5 = 2;
  }
  write_single_byte_0301ea5c(p_radio_mode_state_0003e318[1].flags_0x5);
  if ((local_d & 1) == 0) {
    p_dm32_settings_block04[0x6f] = p_dm32_settings_block04[0x6f] & 0xfe;
  }
  else {
    p_dm32_settings_block04[0x6f] = p_dm32_settings_block04[0x6f] & 0xfe | 1;
  }
  return;
}

