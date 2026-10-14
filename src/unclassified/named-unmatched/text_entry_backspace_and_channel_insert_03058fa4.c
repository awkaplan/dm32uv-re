/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_backspace_and_channel_insert @ 03058fa4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 252 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_backspace_and_channel_insert(void)

{
  char cVar1;
  undefined2 auStack_c [2];
  
  auStack_c[0] = 0;
  cVar1 = *(char *)PTR_active_screen_subtype_030590f8;
  if (cVar1 == '\n') {
    if (*(char *)PTR_DAT_030590fc != '\x03') {
LAB_03059024:
      if (cVar1 != '\x04') {
        return;
      }
      if (*(char *)PTR_DAT_03059100 == 'T') {
        return;
      }
      if (*(char *)PTR_DAT_03059100 == '[') {
        return;
      }
      number_to_string_format_2args
                (auStack_c,PTR_s__d_030afae0_8_0305911c,PTR_DAT_03059118[*(byte *)PTR_DAT_03059114])
      ;
      if (*(char *)((int)PTR_DAT_030590fc + 1) != '\0') {
        draw_string_mixed_charset
                  (*(undefined2 *)PTR_DAT_03059104,
                   *(undefined2 *)PTR_text_entry_current_char_03059108,auStack_c,1,0,0x7e0);
        *(undefined1 *)((int)PTR_DAT_030590fc + 1) = 0;
        return;
      }
      draw_string_mixed_charset
                (*(undefined2 *)PTR_DAT_03059104,*(undefined2 *)PTR_text_entry_current_char_03059108
                 ,auStack_c,1,0x7e0,0);
      *(undefined1 *)((int)PTR_DAT_030590fc + 1) = 1;
      return;
    }
  }
  else if (((cVar1 != '\b') && (cVar1 != '\x18')) || (*(char *)PTR_DAT_03059100 == 'T'))
  goto LAB_03059024;
  if ((*(char *)PTR_DAT_03059100 != 'T') && (*(char *)PTR_DAT_03059100 != '[')) {
    if (*(char *)((int)PTR_DAT_030590fc + 1) == '\0') {
      lcd_draw_monochrome_bitmap_icon
                (*(undefined2 *)PTR_DAT_03059104,*(undefined2 *)PTR_text_entry_current_char_03059108
                 ,PTR_LAB_03059110,1);
      *(undefined1 *)((int)PTR_DAT_030590fc + 1) = 1;
    }
    else {
      lcd_draw_monochrome_bitmap_icon
                (*(undefined2 *)PTR_DAT_03059104,*(undefined2 *)PTR_text_entry_current_char_03059108
                 ,PTR_DAT_0305910c,1);
      *(undefined1 *)((int)PTR_DAT_030590fc + 1) = 0;
    }
  }
  return;
}

