/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_string_mutex_variant @ 0301a10c (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_string_mutex_variant
               (undefined2 param_1,ushort param_2,byte *param_3,undefined2 param_4,
               undefined2 param_5)

{
  byte bVar1;
  byte bVar2;
  byte local_6c;
  byte bStack_6b;
  
  memset_ck803s(&local_6c,0,0x48);
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  while( true ) {
    bVar2 = *param_3;
    if (bVar2 == 0) break;
    if ((bVar2 < 0x81) || (bVar1 = param_3[1], bVar1 < 0x81)) {
      if ((byte)(bVar2 - 0x20) < 0x60) {
        if (0xe3 < param_2) break;
        display_draw_glyph_ascii(param_2,param_1,bVar2,0x18,param_4,param_5);
        param_3 = param_3 + 1;
        param_2 = param_2 + 0xc;
      }
      else {
        if (0xe3 < param_2) break;
        display_fill_glyph_cell(param_1,param_2,param_5);
        param_3 = param_3 + 1;
        param_2 = param_2 + 8;
      }
    }
    else {
      if (0xd8 < param_2) break;
      local_6c = bVar2;
      bStack_6b = bVar1;
      if (bVar2 < 0xa6) {
        gb2312_glyph_index_lookup1(&local_6c);
      }
      else {
        if (0xf < bVar2) {
          local_6c = bVar2 - 0xf;
        }
        gb2312_glyph_index_lookup2(&local_6c);
      }
      display_draw_glyph_gb2312(param_1,param_2,&local_6c,param_4,param_5);
      param_3 = param_3 + 2;
      param_2 = param_2 + 0x18;
    }
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}

