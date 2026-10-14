/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_string_mixed_ascii_gb2312 @ 030187f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_string_mixed_ascii_gb2312
               (undefined2 param_1,ushort param_2,byte *param_3,undefined2 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  local_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  if (*(char *)PTR_DAT_0301893c == '\0') {
    uVar4 = 0x10;
  }
  else {
    uVar4 = 0x14;
  }
  uVar3 = 0;
  while ((bVar1 = *param_3, bVar1 != 0 && (uVar3 < uVar4))) {
    if ((bVar1 < 0x81) || (param_3[1] < 0x81)) {
      if ((char)bVar1 < '\x01') {
        if (0xe8 < param_2) break;
        param_3 = param_3 + 1;
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 8;
      }
      else {
        if (0xe8 < param_2) break;
        uVar2 = font_glyph_ptr_lookup(param_3);
        blit_bitmap_8x8_two_blocks(param_1,param_2,uVar2,param_4);
        param_3 = param_3 + 1;
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 8;
      }
    }
    else {
      if (0xe0 < param_2) break;
      SUBPIECE_SET(local_44, 0, 2, CONCAT11(param_3[1],bVar1));
      gb2312_glyph_flash_offset_read(&local_44);
      blit_bitmap_8x16_two_blocks(param_1,param_2,&local_44,param_4);
      param_3 = param_3 + 2;
      uVar3 = uVar3 + 2;
      param_2 = param_2 + 0x10;
    }
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

