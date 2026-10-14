/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_name_edit_input_handler @ 0305a2d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 322 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_list_name_edit_input_handler(int param_1__w)

{
  byte param_1 = (byte)param_1__w;
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_c [4];
  
  puVar3 = PTR_DAT_0305a460;
  uVar7 = (uint)param_1;
  if (uVar7 < 2) {
    if (*(char *)PTR_DAT_0305a424 == '\x03') {
      if ((uint)*DAT_0305a41c <= (uint)*(ushort *)PTR_DAT_0305a420) {
        if (*(char *)((int)PTR_DAT_0305a424 + 3) == '\0') {
          if (uVar7 == 1) {
            *(undefined1 *)PTR_DAT_0305a424 = 4;
            puVar5 = PTR_LAB_0305a454;
            uVar7 = strlen_ck803s(PTR_LAB_0305a454);
            *(char *)PTR_DAT_0305a458 = (char)(uVar7 >> 1);
            *(undefined1 *)PTR_DAT_0305a42c = 0;
            scan_list_row_render(puVar5);
          }
          else if ((int)(uint)*DAT_0305a41c < (int)(*(ushort *)PTR_DAT_0305a420 - 1)) {
            scan_list_scroll_update(PTR_LAB_0305a45c);
          }
        }
        else {
          *(byte *)PTR_DAT_0305a460 = param_1;
          os_post_message_opt_validated(p_ucos_queue_inputq,puVar3,4,0,auStack_c);
        }
      }
    }
  }
  else if ((int)(uint)*DAT_0305a41c <= (int)(*(ushort *)PTR_DAT_0305a420 - 1)) {
    bVar1 = *(byte *)PTR_DAT_0305a424;
    if (bVar1 == 2) {
      *(undefined1 *)PTR_DAT_0305a424 = 1;
      *(undefined1 *)PTR_DAT_0305a428 = 0;
      *(undefined1 *)PTR_DAT_0305a42c = 0;
    }
    else if (bVar1 < 3) {
      if (bVar1 == 1) {
        *(undefined1 *)PTR_DAT_0305a428 = 0;
      }
    }
    else if (bVar1 == 3) {
      *PTR_DAT_0305a434 = PTR_DAT_0305a430[uVar7];
      *(undefined *)PTR_DAT_0305a43c = PTR_PTR_0305a438[uVar7];
      *PTR_DAT_0305a444 = PTR_DAT_0305a440[uVar7];
      display_fill_rect(0,0xe6,0xf0,0x11e,0xc618);
      *(undefined1 *)PTR_DAT_0305a424 = 1;
      *(undefined1 *)PTR_DAT_0305a428 = 0;
      *(undefined1 *)PTR_DAT_0305a42c = 0;
      *(undefined1 *)PTR_DAT_0305a448 = 0;
      *(undefined1 *)PTR_DAT_0305a44c = 0;
    }
    else if (bVar1 == 4) {
      return;
    }
    puVar4 = PTR_DAT_0305a450;
    puVar3 = PTR_DAT_0305a448;
    bVar1 = *(byte *)PTR_DAT_0305a448;
    PTR_DAT_0305a450[bVar1] = param_1 + 0x30;
    uVar7 = bVar1 + 1;
    *(char *)puVar3 = (char)uVar7;
    puVar4[uVar7 & 0xff] = 0;
    iVar6 = name_table_prefix_match_count();
    if (iVar6 == 0) {
      cVar2 = *(char *)PTR_DAT_0305a448;
      *(byte *)PTR_DAT_0305a448 = cVar2 - 1U;
      PTR_DAT_0305a450[(byte)(cVar2 - 1U)] = 0;
      name_table_prefix_match_count();
    }
    else {
      text_entry_char_picker_render();
      scan_list_row_render();
    }
  }
  return;
}

