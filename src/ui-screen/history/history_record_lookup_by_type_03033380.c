/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_lookup_by_type @ 03033380 (file base 0x03000000; code starts at 0x03001000)
 * Size: 274 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_record_lookup_by_type(char param_1,ushort param_2,void *param_3)

{
  ushort block_id;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort local_2c [2];
  byte local_28;
  byte local_27;
  ushort local_26;
  
  local_2c[0] = param_2;
  block_id = flash_block_id_resolve_locked(0xb);
  uVar1 = get_block0xb_u16_field0();
  if (param_1 == '\x05') {
    if (uVar1 != 0) {
      uVar2 = 0x101;
      uVar4 = 0;
      uVar3 = 0;
      do {
        flash_block_read(block_id,uVar2,&local_27,4);
        local_27 = local_27 >> 4;
        if ((local_27 == 3) && (uVar4 = uVar4 + 1, local_2c[0] == uVar4)) {
          local_2c[0] = (short)uVar3 + 1;
          break;
        }
        uVar3 = uVar3 + 1 & 0xffff;
        uVar2 = uVar2 + 2 & 0xffff;
      } while (uVar3 < uVar1);
    }
  }
  else if ((param_1 == '\x06') && (uVar1 != 0)) {
    uVar2 = 0x101;
    uVar4 = 0;
    uVar3 = 0;
    do {
      flash_block_read(block_id,uVar2,&local_27,4);
      local_27 = local_27 >> 4;
      if ((local_27 == 4) && (uVar4 = uVar4 + 1, local_2c[0] == uVar4)) {
        local_2c[0] = (short)uVar3 + 1;
        break;
      }
      uVar3 = uVar3 + 1 & 0xffff;
      uVar2 = uVar2 + 2 & 0xffff;
    } while (uVar3 < uVar1);
  }
  flash_block_read(block_id,(uint)(ushort)((local_2c[0] + 0x7f) * 2),local_2c,2);
  local_2c[0] = local_2c[0] & 0xfff;
  talkgroup_index_decode_paged(local_2c[0],&local_26,&local_28);
  local_26 = flash_block_id_resolve_locked((undefined1)local_26);
  flash_block_read(local_26,(local_28 - 1) * 0x18 & 0xfff8,param_3,0x18);
  return;
}

