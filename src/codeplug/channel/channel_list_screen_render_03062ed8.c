/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_screen_render @ 03062ed8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 240 bytes
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

void channel_list_screen_render(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_38 [5];
  undefined1 uStack_33;
  undefined1 uStack_30;
  undefined1 uStack_2c;
  short local_26;
  
  iVar1 = _DAT_03062fcc;
  uVar2 = ((param_2 & 0xff) - (param_1 & 0xff)) + 1 & 0xff;
  iVar3 = 0;
  do {
    flash_field_read_cached(4,(uVar2 + 400) * 2,&local_26,2);
    if (local_26 == 0) {
      if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
        memcpy_bytes_iram(auStack_38,PTR_LAB_03062fd4,8);
        uStack_30 = 0;
      }
      else {
        memcpy_bytes_iram(auStack_38,PTR_s_Current_Chan_03062fd8,0xc);
        uStack_2c = 0;
      }
    }
    else if (local_26 == 0xfa1) {
      memcpy_bytes_iram(auStack_38,PTR_s_VFO_A_03062fdc,5);
      uStack_33 = 0;
    }
    else if (local_26 == 0xfa2) {
      memcpy_bytes_iram(auStack_38,PTR_s_VFO_B_03062fe0,5);
      uStack_33 = 0;
    }
    else {
      channel_record_read_full(local_26,auStack_38);
    }
    if (uVar2 == (param_2 & 0xff)) {
      display_draw_list_row(iVar3 + 1,auStack_38,1);
      *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xbf | 0x40;
    }
    else {
      display_draw_list_row(iVar3 + 1,auStack_38,0);
      *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xbf;
    }
    iVar4 = iVar3 + 1;
    menu_icon_draw_dispatch(iVar4,uVar2);
    uVar2 = uVar2 + 1 & 0xff;
  } while (((uVar2 < 8) && (iVar3 != 7)) && (iVar3 = iVar4, iVar4 != 8));
  return;
}

