/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_string_centered_mixed @ 0301a6b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_string_centered_mixed
               (char param_1,byte *param_2,undefined4 param_3,undefined2 param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  byte local_6c;
  byte bStack_6b;
  
  memset_ck803s(&local_6c,0,0x48);
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  if (param_1 == '\0') {
    uVar5 = PTR_DAT_0301a90c[(byte)p_dm32_settings_block04[100]];
    uVar4 = 0x36;
  }
  else {
    uVar5 = PTR_DAT_0301a90c[(byte)p_dm32_settings_block04[0x65]];
    uVar4 = 0xac;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    uVar4 = 0x3b;
  }
  uVar3 = strlen_ck803s(param_2);
  uVar3 = ((int)(0x14 - (uVar3 & 0xff)) / 2) * 0xc & 0xffff;
  while( true ) {
    bVar2 = *param_2;
    if (bVar2 == 0) break;
    if ((bVar2 < 0x81) || (bVar1 = param_2[1], bVar1 < 0x81)) {
      if ((char)bVar2 < '\x01') {
        if (0xef < uVar3 + 8) break;
        display_fill_glyph_cell(uVar4,uVar3,param_4);
        param_2 = param_2 + 1;
        uVar3 = uVar3 + 8 & 0xffff;
      }
      else {
        if (0xef < uVar3 + 0xc) break;
        display_draw_glyph_ascii(uVar3,uVar4,bVar2,0x18,uVar5,param_4);
        uVar3 = uVar3 + 0xc & 0xffff;
        param_2 = param_2 + 1;
      }
    }
    else {
      local_6c = bVar2;
      bStack_6b = bVar1;
      if (0xef < uVar3 + 0x18) break;
      if (0xf < bVar2) {
        local_6c = bVar2 - 0xf;
      }
      gb2312_glyph_index_lookup2(&local_6c);
      display_draw_glyph_gb2312(uVar4,uVar3,&local_6c,uVar5,param_4);
      uVar3 = uVar3 + 0x18 & 0xffff;
      param_2 = param_2 + 2;
    }
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

