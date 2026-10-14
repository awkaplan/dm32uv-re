/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_cursor_advance_wide_or_narrow @ 0305b368 (file base 0x03000000; code starts at 0x03001000)
 * Size: 244 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_cursor_advance_wide_or_narrow(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  
  PTR_DAT_0305b45c[5] = 0xf0;
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305b464,*(undefined2 *)p_text_entry_current_char,
             PTR_LAB_0305b46c,1);
  draw_wrapped_text_conditional();
  uVar6 = (uint)*(byte *)PTR_DAT_0305b470;
  if (uVar6 == 0) {
LAB_0305b428:
    if (*(short *)PTR_DAT_0305b464 != 0xfff) goto LAB_0305b44a;
  }
  else {
    if (-1 < *(char *)(uVar6 + p_text_entry_buffer_alias)) {
      *(char *)PTR_DAT_0305b470 = (char)(uVar6 - 1);
      if (*(short *)p_text_entry_current_char == 5) {
        iVar5 = text_entry_columns_used_for_length((uVar6 - 1 & 0xff) - 1 & 0xff);
        if (iVar5 == 0x13) {
          *(undefined2 *)p_text_entry_current_char = 0xdd;
        }
        else {
          *(undefined2 *)p_text_entry_current_char = 0xd1;
        }
        uVar2 = *(ushort *)PTR_DAT_0305b464;
        if (uVar2 < 0x21) goto LAB_0305b432;
        *(ushort *)PTR_DAT_0305b464 = uVar2 - 0x18;
        if ((ushort)(uVar2 - 0x18) < 0x20) {
          *(undefined2 *)PTR_DAT_0305b464 = 0x20;
          goto LAB_0305b44a;
        }
      }
      else {
        *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + -0xc;
      }
      goto LAB_0305b428;
    }
    *(byte *)PTR_DAT_0305b470 = *(byte *)PTR_DAT_0305b470 - 2;
    if (*(short *)p_text_entry_current_char != 5) {
      *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + -0x18;
      goto LAB_0305b428;
    }
    iVar5 = text_entry_columns_used_for_length();
    if (iVar5 == 0x13) {
      *(undefined2 *)p_text_entry_current_char = 0xd1;
    }
    else {
      *(undefined2 *)p_text_entry_current_char = 0xc5;
    }
    if (0x20 < *(ushort *)PTR_DAT_0305b464) {
      *(ushort *)PTR_DAT_0305b464 = *(ushort *)PTR_DAT_0305b464 - 0x18;
      goto LAB_0305b428;
    }
  }
LAB_0305b432:
  *(undefined2 *)PTR_DAT_0305b464 = 0x20;
  puVar3 = p_text_entry_current_char_alias;
  cVar1 = *(char *)p_text_entry_current_char_alias;
  cVar4 = text_entry_columns_used_for_length(cVar1);
  *(char *)puVar3 = cVar1 - cVar4;
  scan_monitor_display_refresh();
LAB_0305b44a:
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305b464,*(undefined2 *)p_text_entry_current_char,
             PTR_DAT_0305b47c,1);
  return;
}

