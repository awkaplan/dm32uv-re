/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_scroll_and_display_refresh @ 0305b19c (file base 0x03000000; code starts at 0x03001000)
 * Size: 332 bytes
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

void text_entry_scroll_and_display_refresh(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = *(ushort *)PTR_text_entry_current_char_0305b2e8;
  display_blit_bitmap_1bpp_rows(*(undefined2 *)PTR_DAT_0305b2ec,uVar3,_DAT_0305b2f0,1);
  if (*(byte *)PTR_DAT_0305b2f4 < 0x1d) {
    tx_gate_write_call_record(0);
  }
  else {
    uVar3 = uVar3 >> 3;
    uVar7 = uVar3 & 0xff;
    tx_gate_write_call_record(1);
    bVar1 = *(byte *)PTR_DAT_0305b2f4;
    uVar8 = (uint)bVar1;
    uVar9 = uVar8 - uVar7 & 0xff;
    iVar6 = text_entry_columns_used_for_length(uVar9);
    if (*(ushort *)PTR_DAT_0305b2ec < 0x29) {
      *(undefined2 *)PTR_DAT_0305b2ec = 0xfff;
    }
    else {
      *(ushort *)PTR_DAT_0305b2ec = *(ushort *)PTR_DAT_0305b2ec - 0x10;
    }
    cVar2 = (char)iVar6;
    if ((uVar3 & 0xff) == 0) {
      if (uVar8 == 0x1d) {
        *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0;
        *(undefined1 *)PTR_DAT_0305b2f4 = 0;
      }
      else {
        iVar6 = text_entry_columns_used_for_length(uVar9 - iVar6 & 0xff);
        if (iVar6 == 0x1c) {
          *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0x10;
          *(byte *)PTR_DAT_0305b2f4 = (bVar1 + 2) - cVar2;
        }
        else {
          *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0;
          *(byte *)PTR_DAT_0305b2f4 = bVar1 - cVar2;
        }
      }
    }
    else if (uVar7 == 0x1c) {
      if (iVar6 == 0x1d) {
        if (*(char *)(uVar8 + _DAT_0305b2f8) < '\0') {
          *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0xd4;
          *(byte *)PTR_DAT_0305b2f4 = bVar1 - 0x1e;
        }
        else {
          *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0xdc;
          *(byte *)PTR_DAT_0305b2f4 = bVar1 - 0x1d;
        }
      }
      else {
        *(undefined2 *)PTR_text_entry_current_char_0305b2e8 = 0xdc;
        *(byte *)PTR_DAT_0305b2f4 = bVar1 - 0x1c;
      }
    }
    else {
      uVar9 = uVar9 - iVar6;
      uVar8 = 0;
      do {
        uVar9 = uVar9 & 0xff;
        if ((char)PTR_text_entry_buffer_0305b2fc[uVar9] < '\0') {
          uVar8 = uVar8 + 2;
          uVar9 = uVar9 + 2;
        }
        else {
          uVar8 = uVar8 + 1;
          uVar9 = uVar9 + 1;
        }
        uVar8 = uVar8 & 0xff;
      } while (uVar8 < uVar7);
      if (uVar7 == uVar8) {
        *(byte *)PTR_DAT_0305b2f4 = bVar1 - cVar2;
      }
      else {
        *(short *)PTR_text_entry_current_char_0305b2e8 =
             *(short *)PTR_text_entry_current_char_0305b2e8 + 8;
        *(byte *)PTR_DAT_0305b2f4 = (bVar1 + 1) - cVar2;
      }
    }
    if (*(short *)PTR_DAT_0305b2ec == 0xfff) {
      *(undefined2 *)PTR_DAT_0305b2ec = 0x28;
      puVar4 = PTR_text_entry_current_char_minus_a_0305b300;
      cVar2 = *(char *)PTR_text_entry_current_char_minus_a_0305b300;
      cVar5 = text_entry_columns_used_for_length(cVar2);
      *(char *)puVar4 = cVar2 - cVar5;
      scan_monitor_display_refresh();
    }
  }
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305b2ec,*(undefined2 *)PTR_text_entry_current_char_0305b2e8,
             _DAT_0305b304,1);
  return;
}

