/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scanlist_channel_membership_remove @ 0302e598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 376 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scanlist_channel_membership_remove(uint param_1,uint param_2)

{
  byte bVar1;
  vfo_freq_display_state *pvVar2;
  ushort uVar3;
  ushort block_id;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint offset;
  undefined1 uStack_69;
  ushort local_68;
  ushort local_65;
  ushort uStack_63;
  undefined2 local_48;
  undefined1 auStack_46 [34];
  
  block_id = flash_block_id_resolve_locked(0x11);
  uVar6 = ((param_1 & 0xff) - 1) * 0x39 & 0xffff;
  offset = uVar6 + 0x17 & 0xffff;
  flash_block_read(block_id,offset,&local_48,0x22);
  uVar4 = (param_2 & 0xff) - 1;
  local_48 = (ushort)(((int)(uint)local_48 >> (param_2 & 0x3f) & 0xffffU) << (uVar4 & 0x3f)) |
             local_48 & (short)(1 << (uVar4 & 0x3f)) - 1U;
  flash_block_read(block_id,uVar6 + 0x19 + uVar4 * 2 & 0xffff,&local_68,2);
  uVar3 = local_68;
  uVar4 = uVar6 + 0xf & 0xffff;
  flash_block_read(block_id,uVar4,&local_68,7);
  if (local_65 == uVar3) {
    local_68 = local_68 & 0xff00;
    local_65 = 0;
    uStack_63 = 0;
  }
  else if (uStack_63 == uVar3) {
    local_68 = local_68 & 0xff0f;
    uStack_63 = 0;
  }
  flash_block_write(0x11,uVar4,&local_68,7);
  bVar1 = p_vfo_freq_display_state->field_0x1;
  if (1 < bVar1) {
    uVar5 = 2;
    uVar4 = 2;
    do {
      if (uVar5 != (param_2 & 0xff)) {
        *(undefined1 *)(&local_68 + (uVar4 - 1)) = auStack_46[uVar5 * 2 + -2];
        (&uStack_69)[uVar4 * 2] = auStack_46[uVar5 * 2 + -1];
        uVar4 = uVar4 + 1 & 0xff;
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 <= bVar1);
  }
  memcpy_bytes_iram(auStack_46,&local_68,0x20);
  flash_block_write(0x11,offset,&local_48,0x22);
  pvVar2 = p_vfo_freq_display_state;
  p_vfo_freq_display_state->field_0x1 = p_vfo_freq_display_state->field_0x1 - 1;
  flash_block_write(0x11,uVar6 + 0xc & 0xffff,&pvVar2->field_0x1,1);
  zone_record_read(param_1 & 0xff);
  return;
}

