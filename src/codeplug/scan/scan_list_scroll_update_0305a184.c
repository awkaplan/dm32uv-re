/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_scroll_update @ 0305a184 (file base 0x03000000; code starts at 0x03001000)
 * Size: 294 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_list_scroll_update(undefined1 *param_1)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uVar8;
  
  puVar4 = p_text_entry_buffer;
  uVar8 = (uint)*(byte *)PTR_DAT_0305a2ac;
  if (uVar8 <= *(ushort *)PTR_DAT_0305a2b4) {
    if (uVar8 == 1) {
      p_text_entry_buffer[1] = 0;
    }
    else {
      bVar1 = *(byte *)PTR_DAT_0305a2b8;
      for (; bVar1 < uVar8; uVar8 = uVar8 - 1 & 0xff) {
        puVar4[uVar8] = puVar4[uVar8 - 1];
      }
    }
    puVar5 = PTR_DAT_0305a2b8;
    bVar1 = *(byte *)PTR_DAT_0305a2b8;
    p_text_entry_buffer[bVar1] = *param_1;
    *(byte *)puVar5 = bVar1 + 1;
    puVar5 = p_text_entry_current_char;
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_0305a2c0,*(undefined2 *)p_text_entry_current_char,
               PTR_LAB_0305a2c4,1);
    uVar3 = *(ushort *)puVar5;
    if (uVar3 < 0xe5) {
      *(ushort *)p_text_entry_current_char = uVar3 + 0xc;
    }
    else {
      *(undefined2 *)puVar5 = 0x11;
      *(short *)PTR_DAT_0305a2c0 = *(short *)PTR_DAT_0305a2c0 + 0x18;
    }
    if (0x108 < *(ushort *)PTR_DAT_0305a2c0) {
      *(ushort *)PTR_DAT_0305a2c0 = *(ushort *)PTR_DAT_0305a2c0 - 0x18;
      puVar5 = p_text_entry_current_char_alias;
      cVar2 = *(char *)p_text_entry_current_char_alias;
      cVar7 = text_entry_columns_remaining(cVar2);
      *(char *)puVar5 = cVar7 + cVar2;
    }
    *(char *)PTR_DAT_0305a2ac = *(char *)PTR_DAT_0305a2ac + '\x01';
    puVar6 = PTR_DAT_0305a2c0;
    puVar5 = p_text_entry_current_char;
    if (PTR_DAT_0305a2cc[3] == '\0') {
      scan_monitor_display_refresh();
    }
    else {
      if (PTR_DAT_0305a2cc[3] == '\x01') {
        display_draw_string_ascii_mixed
                  (*(undefined2 *)PTR_DAT_0305a2c0,*(short *)p_text_entry_current_char + -0xc,
                   param_1,1,0xffff,0);
      }
      else {
        display_fill_rect(*(short *)p_text_entry_current_char + -0xc,*(short *)PTR_DAT_0305a2c0,
                          *(short *)p_text_entry_current_char,*(short *)PTR_DAT_0305a2c0 + 0x18,
                          0xc618);
        display_draw_string_ascii_mixed
                  (*(undefined2 *)puVar6,*(short *)puVar5 + -0xc,param_1,1,0xffff,0xc618);
      }
      scan_channel_icon_draw(PTR_DAT_0305a2d0[800]);
    }
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_0305a2c0,*(undefined2 *)p_text_entry_current_char,
               PTR_DAT_0305a2d4,1);
  }
  return;
}

