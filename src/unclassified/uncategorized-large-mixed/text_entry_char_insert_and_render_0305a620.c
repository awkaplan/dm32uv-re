/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_insert_and_render @ 0305a620 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_char_insert_and_render(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  
  puVar4 = p_text_entry_buffer;
  uVar7 = (uint)*(byte *)PTR_DAT_0305a7ec;
  if ((int)uVar7 <= (int)(*(ushort *)PTR_DAT_0305a7f0 - 1)) {
    if (uVar7 == 1) {
      p_text_entry_buffer[2] = 0;
    }
    else {
      bVar1 = *(byte *)PTR_DAT_0305a7f4;
      for (; bVar1 < uVar7; uVar7 = uVar7 - 1 & 0xff) {
        puVar4[uVar7 + 1] = puVar4[uVar7 - 1];
      }
    }
    puVar5 = p_text_entry_buffer_alias;
    puVar4 = p_text_entry_buffer;
    puVar3 = PTR_DAT_0305a7f4;
    bVar1 = *(byte *)PTR_DAT_0305a7f4;
    p_text_entry_buffer[bVar1] = *(undefined1 *)p_text_entry_buffer_alias;
    uVar7 = bVar1 + 1;
    puVar4[uVar7 & 0xff] = *(undefined1 *)((int)puVar5 + 1);
    *(char *)puVar3 = (char)uVar7 + '\x01';
    if (*(ushort *)p_text_entry_current_char < 0xd9) {
      *(ushort *)p_text_entry_current_char = *(ushort *)p_text_entry_current_char + 0x18;
    }
    else {
      *(undefined2 *)p_text_entry_current_char = 0x1d;
      *(short *)PTR_DAT_0305a804 = *(short *)PTR_DAT_0305a804 + 0x18;
    }
    if (0x107 < *(ushort *)PTR_DAT_0305a804) {
      *(undefined2 *)PTR_DAT_0305a804 = 0xf0;
      puVar3 = p_text_entry_current_char_alias;
      cVar2 = *(char *)p_text_entry_current_char_alias;
      cVar6 = text_entry_columns_remaining(cVar2);
      *(char *)puVar3 = cVar6 + cVar2;
    }
    *(char *)PTR_DAT_0305a7ec = *(char *)PTR_DAT_0305a7ec + '\x02';
    scan_monitor_display_refresh();
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_0305a804,*(undefined2 *)p_text_entry_current_char,
               PTR_DAT_0305a80c,1);
  }
  return;
}

