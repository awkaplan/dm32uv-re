/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_backspace_delete_char @ 0305b50c (file base 0x03000000; code starts at 0x03001000)
 * Size: 564 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_backspace_delete_char(void)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  short *psVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  if (*(char *)PTR_DAT_0305b604 == '\0') {
    return;
  }
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305b608,*(undefined2 *)p_text_entry_current_char,
             PTR_LAB_0305b610,1);
  uVar7 = (uint)*(byte *)PTR_DAT_0305b604;
  if (-1 < *(char *)(uVar7 + p_text_entry_buffer_alias)) {
    if (*_p_text_entry_current_char == 5) {
      iVar6 = text_entry_columns_used_for_length(uVar7 - 2 & 0xff);
      if (iVar6 == 0x13) {
        *_p_text_entry_current_char = 0xdc;
      }
      else {
        *_p_text_entry_current_char = 0xd0;
      }
      if (0x20 < *_LAB_0305b780) {
        *_LAB_0305b780 = *_LAB_0305b780 - 0x18;
        goto LAB_0305b6b4;
      }
LAB_0305b6be:
      *_LAB_0305b780 = 0x20;
      bVar1 = *_p_text_entry_current_char_alias;
      uVar7 = text_entry_columns_used_for_length((uint)bVar1);
      if (bVar1 < uVar7) {
        *_p_text_entry_current_char_alias = 0;
      }
      else {
        *_p_text_entry_current_char_alias = bVar1 - (char)uVar7;
      }
    }
    else {
      *_p_text_entry_current_char = *_p_text_entry_current_char + -0xc;
LAB_0305b6b4:
      if (*_LAB_0305b780 == 0xfff) goto LAB_0305b6be;
    }
    iVar6 = _p_text_entry_buffer;
    bVar1 = *_LAB_0305b770;
    bVar3 = *_LAB_0305b774;
    for (uVar7 = (uint)bVar1; uVar7 < bVar3; uVar7 = uVar7 + 1 & 0xffff) {
      *(undefined1 *)(iVar6 + uVar7 + -1) = *(undefined1 *)(iVar6 + uVar7);
    }
    *_LAB_0305b770 = bVar1 - 1;
    *_LAB_0305b774 = bVar3 - 1;
    display_fill_rect(*_p_text_entry_current_char,*_LAB_0305b780,*_p_text_entry_current_char + 0xc,
                      *_LAB_0305b780 + 0x18,0);
    *(undefined1 *)(_LAB_0305b784 + 5) = 0xf0;
    goto LAB_0305b73e;
  }
  uVar2 = *(ushort *)p_text_entry_current_char;
  if (uVar2 == 5) {
    iVar6 = text_entry_columns_used_for_length(uVar7 - 2 & 0xff);
    if (iVar6 == 0x13) {
      *(undefined2 *)p_text_entry_current_char = 0xd0;
    }
    else {
      *(undefined2 *)p_text_entry_current_char = 0xc4;
    }
    if (*(ushort *)PTR_DAT_0305b608 < 0x21) goto LAB_0305b5d4;
    *(ushort *)PTR_DAT_0305b608 = *(ushort *)PTR_DAT_0305b608 - 0x18;
LAB_0305b5ca:
    if (*(short *)PTR_DAT_0305b608 == 0xfff) goto LAB_0305b5d4;
  }
  else {
    if (uVar2 < 0x18) {
      *(undefined2 *)p_text_entry_current_char = 0xdd;
      if (*(ushort *)PTR_DAT_0305b608 < 0x21) goto LAB_0305b5d4;
      *(ushort *)PTR_DAT_0305b608 = *(ushort *)PTR_DAT_0305b608 - 0x18;
      goto LAB_0305b5ca;
    }
    *(ushort *)p_text_entry_current_char = uVar2 - 0x18;
    if (uVar2 != 0x1d) goto LAB_0305b5ca;
    if (0x20 < *(ushort *)PTR_DAT_0305b608) {
      iVar6 = text_entry_columns_used_for_length(uVar7 - 2 & 0xff);
      if (iVar6 == 0x13) {
        *(undefined2 *)p_text_entry_current_char = 0xe8;
      }
      else {
        *(undefined2 *)p_text_entry_current_char = 0xdc;
      }
      if (0x20 < *(ushort *)PTR_DAT_0305b608) {
        *(ushort *)PTR_DAT_0305b608 = *(ushort *)PTR_DAT_0305b608 - 0x18;
        goto LAB_0305b5ca;
      }
    }
LAB_0305b5d4:
    *(undefined2 *)PTR_DAT_0305b608 = 0x20;
    bVar1 = *(byte *)p_text_entry_current_char_alias;
    uVar7 = text_entry_columns_used_for_length((uint)bVar1);
    if (bVar1 < uVar7) {
      *_p_text_entry_current_char_alias = 0;
    }
    else {
      *(byte *)p_text_entry_current_char_alias = bVar1 - (char)uVar7;
    }
  }
  iVar6 = _p_text_entry_buffer;
  bVar1 = *_LAB_0305b770;
  bVar3 = *_LAB_0305b774;
  for (uVar7 = (uint)bVar1; uVar7 < bVar3; uVar7 = uVar7 + 1 & 0xffff) {
    *(undefined1 *)(iVar6 + uVar7 + -2) = *(undefined1 *)(iVar6 + uVar7);
  }
  *_LAB_0305b770 = bVar1 - 2;
  *_LAB_0305b774 = bVar3 - 2;
  display_fill_rect(*_p_text_entry_current_char,*_LAB_0305b780,*_p_text_entry_current_char + 0x18,
                    *_LAB_0305b780 + 0x18,0);
LAB_0305b73e:
  puVar5 = _LAB_0305b780;
  *_p_text_entry_buffer_alias = *_LAB_0305b780;
  psVar4 = _p_text_entry_current_char;
  *_LAB_0305b78c = *_p_text_entry_current_char;
  scan_monitor_display_refresh();
  scan_channel_icon_draw(*(undefined1 *)(_LAB_0305b790 + 800));
  display_blit_bitmap_1bpp_rows(*puVar5,*psVar4,_LAB_0305b794,1);
  return;
}

