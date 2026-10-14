/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_append_and_scroll @ 0305ad3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 392 bytes
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

void text_entry_char_append_and_scroll(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 *puVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = *(ushort *)PTR_text_entry_current_char_0305ae98 >> 3;
  uVar8 = uVar3 & 0xff;
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305ae9c,*(ushort *)PTR_text_entry_current_char_0305ae98,
             _DAT_0305aea0,1);
  uVar10 = (uint)*(byte *)PTR_DAT_0305aea4;
  uVar6 = text_entry_columns_remaining(uVar10 - uVar8 & 0xff);
  if ((int)(uVar10 + 0x1d) <= (int)(*(byte *)PTR_DAT_0305aea8 - 1)) {
    tx_gate_write_call_record(1);
    *(short *)PTR_DAT_0305ae9c = *(short *)PTR_DAT_0305ae9c + 0x10;
    if ((uVar8 < 2) && (uVar6 == 0x1c)) {
      *(char *)PTR_DAT_0305aea4 = (*(char *)PTR_DAT_0305aea4 + '\x1e') - (char)uVar3;
      *(undefined2 *)PTR_text_entry_current_char_0305ae98 = 0x10;
    }
    else {
      bVar2 = *(byte *)PTR_DAT_0305aea4;
      if ((uVar3 & 0xff) != 0) {
        uVar10 = uVar6 + (bVar2 - uVar8);
        uVar7 = 0;
        do {
          uVar10 = uVar10 & 0xff;
          if ((char)PTR_text_entry_buffer_0305aeac[uVar10] < '\0') {
            uVar7 = uVar7 + 2;
            uVar10 = uVar10 + 2;
          }
          else {
            uVar7 = uVar7 + 1;
            uVar10 = uVar10 + 1;
          }
          uVar7 = uVar7 & 0xff;
        } while (uVar7 < uVar8);
        if (uVar8 != uVar7) {
          *(short *)PTR_text_entry_current_char_0305ae98 =
               *(short *)PTR_text_entry_current_char_0305ae98 + -8;
          if (uVar6 == 0x1c) {
            *(byte *)PTR_DAT_0305aea4 = bVar2 + 0x1b;
          }
          else {
            *(byte *)PTR_DAT_0305aea4 = bVar2 + 0x1c;
          }
          goto LAB_0305ae60;
        }
      }
      if (uVar6 == 0x1c) {
        *(byte *)PTR_DAT_0305aea4 = bVar2 + 0x1c;
      }
      else {
        *(byte *)PTR_DAT_0305aea4 = bVar2 + 0x1d;
      }
    }
    goto LAB_0305ae60;
  }
  if (uVar6 < 0x1c) {
LAB_0305ad80:
    tx_gate_write_call_record(0);
  }
  else {
    if (uVar6 == 0x1c) {
      if (*(byte *)PTR_DAT_0305aea8 - 1 == (uVar10 + 0x1c) - uVar8) goto LAB_0305ad80;
      tx_gate_write_call_record(1);
      *(short *)PTR_DAT_0305b01c = *(short *)PTR_DAT_0305b01c + 0x10;
      iVar9 = uVar8 + ((*(byte *)PTR_DAT_0305b020 - 1) - (uint)*_DAT_0305b024);
      *(short *)PTR_text_entry_current_char_0305b028 =
           ((short)iVar9 + (short)(iVar9 / 0x1c) * -0x1c) * 8;
    }
    else {
      tx_gate_write_call_record(1);
      *(short *)PTR_DAT_0305ae9c = *(short *)PTR_DAT_0305ae9c + 0x10;
      iVar9 = ((*(byte *)PTR_DAT_0305aea8 - 2) - (uint)*(byte *)PTR_DAT_0305aea4) + uVar8;
      *(short *)PTR_text_entry_current_char_0305ae98 =
           ((short)iVar9 + (short)(iVar9 / 0x1c) * -0x1c) * 8;
    }
    *(char *)PTR_DAT_0305aea4 = *(char *)PTR_DAT_0305aea8 + -1;
  }
LAB_0305ae60:
  if (0x107 < *(ushort *)PTR_DAT_0305ae9c) {
    *(undefined2 *)PTR_DAT_0305ae9c = 0xf8;
    puVar4 = PTR_text_entry_current_char_minus_a_0305aeb0;
    cVar1 = *(char *)PTR_text_entry_current_char_minus_a_0305aeb0;
    cVar5 = text_entry_columns_remaining(cVar1);
    *(char *)puVar4 = cVar5 + cVar1;
    scan_monitor_display_refresh();
  }
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305ae9c,*(undefined2 *)PTR_text_entry_current_char_0305ae98,
             _DAT_0305aeb4,1);
  return;
}

