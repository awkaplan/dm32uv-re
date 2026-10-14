/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_string_gb2312 @ 03018998 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_string_gb2312(short x,ushort y,byte *text,ushort fg,ushort bg)

{
  byte bVar1;
  byte bVar2;
  byte local_6c;
  byte bStack_6b;
  
  memset_ck803s(&local_6c,0,0x48);
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  do {
    while( true ) {
      bVar1 = *text;
      if (bVar1 == 0) {
        os_sem_post(p_ucos_mutex_00039344);
        return;
      }
      if (bVar1 < 0x81) break;
      bVar2 = text[1];
      if (bVar2 < 0x81) break;
      if (bVar1 == 0xff) {
LAB_03018a6c:
        if (0xe4 < y) {
          x = x + 0x18;
          y = 5;
        }
        display_fill_glyph_cell(x,y,bg);
        text = text + 1;
        y = y + 0xc;
      }
      else {
        if (0xd8 < y) {
          x = x + 0x18;
          y = 5;
        }
        local_6c = bVar1;
        bStack_6b = bVar2;
        if (bVar1 < 0xa6) {
          gb2312_glyph_index_lookup1(&local_6c);
        }
        else {
          if (0xf < bVar1) {
            local_6c = bVar1 - 0xf;
          }
          gb2312_glyph_index_lookup2(&local_6c);
        }
        display_draw_glyph_gb2312(x,y,&local_6c,fg,bg);
        if ((*text == 0xa1) && (text[1] == 0xe3)) {
          y = y + 0xc;
        }
        else {
          y = y + 0x18;
        }
        text = text + 2;
      }
    }
    if ((char)bVar1 < '\x01') goto LAB_03018a6c;
    if (0xe4 < y) {
      x = x + 0x18;
      y = 5;
    }
    display_draw_glyph_ascii(y,x,bVar1,0x18,fg,bg);
    text = text + 1;
    y = y + 0xc;
  } while( true );
}

