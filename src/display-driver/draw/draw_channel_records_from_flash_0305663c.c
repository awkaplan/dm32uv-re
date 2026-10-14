/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_channel_records_from_flash @ 0305663c (file base 0x03000000; code starts at 0x03001000)
 * Size: 218 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_channel_records_from_flash(ushort param_1,ushort param_2,char param_3)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  undefined1 auStack_40 [20];
  undefined1 local_2c [2];
  short local_2a;
  byte local_27;
  undefined2 local_26;
  
  channel_offset_minus_0x10(param_3 + '\x01',local_2c,&local_2a);
  flash_field_read_cached(local_2c[0],local_2a + 0x10,&local_27,1);
  iVar1 = _DAT_030567f0;
  if (local_27 != 0) {
    uVar2 = ((param_2 & 0xff) - (param_1 & 0xff)) + 1 & 0xff;
    iVar3 = 0;
    uVar4 = 0;
    do {
      flash_field_read_cached(local_2c[0],local_2a + 0x11 + uVar2 * 2,&local_26,2);
      channel_record_read_full(local_26,auStack_40);
      if (uVar2 == (param_2 & 0xff)) {
        display_draw_list_row(iVar3 + 1,auStack_40,1);
        memcpy_bytes_iram(p_text_entry_buffer,auStack_40,0x11);
        *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xbf | 0x40;
      }
      else {
        display_draw_list_row(iVar3 + 1,auStack_40,0);
        *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xbf;
      }
      iVar3 = iVar3 + 1;
      menu_icon_draw_dispatch(iVar3,uVar2);
      uVar2 = uVar2 + 1 & 0xff;
    } while (((uVar2 < local_27) && (uVar4 != 7)) && (uVar4 = uVar4 + 1 & 0xff, uVar4 < local_27));
  }
  return;
}

