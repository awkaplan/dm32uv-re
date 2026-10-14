/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_scrolling_list_render_with_roaming @ 030663c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_scrolling_list_render_with_roaming(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  byte local_26;
  undefined1 local_25;
  
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  iVar1 = (param_3 & 0xff) * 0x21;
  flash_field_read_cached(0x65,iVar1 + 0x20,&local_26,1);
  iVar2 = _DAT_030664c0;
  if (local_26 != 0) {
    uVar3 = ((param_2 & 0xff) - (param_1 & 0xff)) + 1 & 0xff;
    iVar4 = 0;
    uVar5 = 0;
    do {
      flash_field_read_cached(0x65,uVar3 + iVar1 + 0x21,&local_25,1);
      channel_and_roaming_record_read(local_25,&local_38);
      if (uVar3 == (param_2 & 0xff)) {
        display_draw_list_row(iVar4 + 1,&local_38,1);
        memcpy_bytes_iram(p_text_entry_buffer,&local_38,0x11);
        *(byte *)(iVar2 + 1) = *(byte *)(iVar2 + 1) & 0xbf | 0x40;
      }
      else {
        display_draw_list_row(iVar4 + 1,&local_38,0);
        *(byte *)(iVar2 + 1) = *(byte *)(iVar2 + 1) & 0xbf;
      }
      iVar4 = iVar4 + 1;
      menu_icon_draw_dispatch(iVar4,uVar3);
      uVar3 = uVar3 + 1 & 0xff;
    } while (((uVar3 < local_26) && (uVar5 != 7)) && (uVar5 = uVar5 + 1 & 0xff, uVar5 < local_26));
  }
  return;
}

