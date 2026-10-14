/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_lock_flag_bit_set_in_block11 @ 0302e714 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_lock_flag_bit_set_in_block11(ushort param_1,uint param_2)

{
  short sVar1;
  vfo_freq_display_state *pvVar2;
  ushort block_id;
  byte bVar3;
  uint uVar4;
  byte local_4c;
  byte bStack_4b;
  undefined1 auStack_48 [8];
  byte bStack_40;
  
  param_2 = param_2 & 0xffff;
  flash_bcd_frequency_pair_decode(param_2,auStack_48);
  block_id = flash_block_id_resolve_locked(0x11);
  sVar1 = ((param_1 & 0xff) - 1) * 0x39;
  flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x17),&local_4c,2);
  bVar3 = p_vfo_freq_display_state->field_0x1 + 1;
  uVar4 = (uint)bVar3;
  p_vfo_freq_display_state->field_0x1 = bVar3;
  if (uVar4 < 9) {
    bVar3 = (byte)(1 << (uVar4 - 1 & 0x3f));
    if ((bStack_40 & 0xf0) == 0x10) {
      local_4c = bVar3 | local_4c;
    }
    else {
      local_4c = local_4c & ~bVar3;
    }
  }
  else {
    bVar3 = (byte)(1 << (uVar4 - 9 & 0x3f));
    if ((bStack_40 & 0xf0) == 0x10) {
      bStack_4b = bVar3 | bStack_4b;
    }
    else {
      bStack_4b = bStack_4b & ~bVar3;
    }
  }
  flash_block_write(0x11,(uint)(ushort)(sVar1 + 0x17),&local_4c,2);
  pvVar2 = p_vfo_freq_display_state;
  local_4c = (byte)param_2;
  bStack_4b = (byte)(param_2 >> 8);
  flash_block_write(0x11,sVar1 + (ushort)p_vfo_freq_display_state->field_0x1 * 2 + 0x17,&local_4c,2)
  ;
  flash_block_write(0x11,sVar1 + 0xc,&pvVar2->field_0x1,1);
  return;
}

