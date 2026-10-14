/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_input_loop_blocking @ 0305a6e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 438 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_input_loop_blocking(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  char *pcVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  char cVar14;
  uint uVar15;
  undefined1 auStack_30 [6];
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [4];
  
  critical_section_counted_init_dispatch(DAT_0305a810,PTR_s_inputq_0305a814,10,auStack_28);
  puVar7 = PTR_DAT_0305a824;
  puVar6 = PTR_PTR_0305a820;
  iVar5 = DAT_0305a81c;
  iVar4 = DAT_0305a818;
  uVar3 = DAT_0305a810;
LAB_0305a6fe:
  puVar9 = (undefined1 *)
           guarded_request_command_dispatch(uVar3,0,0,auStack_2a,auStack_30,auStack_28);
  *(undefined1 *)(iVar4 + 4) = *puVar9;
LAB_0305a718:
  do {
    *(undefined1 *)(iVar5 + 0x321) = 0;
    puVar2 = p_text_entry_buffer_alias;
    pcVar10 = (char *)puVar6[(uint)(byte)*puVar7 * 10 + (uint)*(byte *)(iVar4 + 4)];
    cVar1 = *pcVar10;
    if (cVar1 < '\0') {
      if ((int)(*(ushort *)PTR_DAT_0305a7f0 - 1) < (int)(uint)*(byte *)PTR_DAT_0305a7ec)
      goto LAB_0305a6fe;
      *(char *)p_text_entry_buffer_alias = cVar1;
      *(char *)((int)puVar2 + 1) = pcVar10[1];
      *(undefined1 *)((int)puVar2 + 2) = 0;
      text_entry_char_insert_and_render();
    }
    else {
      if (*(ushort *)PTR_DAT_0305a7f0 < (ushort)*(byte *)PTR_DAT_0305a7ec) goto LAB_0305a6fe;
      scan_list_scroll_update();
    }
    *(undefined1 *)(iVar4 + 5) = *(undefined1 *)(iVar4 + 4);
    *(undefined1 *)(iVar4 + 4) = 0xf0;
    while( true ) {
      pbVar11 = (byte *)guarded_request_command_dispatch
                                  (uVar3,0x78,0,auStack_2a,auStack_30,auStack_28);
      if (pbVar11 == (byte *)0x0) {
        *(undefined1 *)(iVar4 + 4) = 0xf0;
        if (*(char *)(iVar4 + 5) != -0x10) {
          *(undefined1 *)(iVar4 + 5) = 0xf0;
          puVar8 = PTR_DAT_0305a9f0;
          puVar2 = PTR_text_entry_current_char_0305a9ec;
          display_fill_rect(*(short *)PTR_text_entry_current_char_0305a9ec + -0xc,
                            *(short *)PTR_DAT_0305a9f0,
                            *(short *)PTR_text_entry_current_char_0305a9ec,
                            *(short *)PTR_DAT_0305a9f0 + 0x18,0xc618);
          display_draw_string_ascii_mixed
                    (*(undefined2 *)puVar8,*(short *)puVar2 + -0xc,
                     DAT_0305a9f8 + (uint)*DAT_0305a9f4,1,0xffff,0);
        }
        goto LAB_0305a6fe;
      }
      uVar15 = (uint)*pbVar11;
      *(byte *)(iVar4 + 4) = *pbVar11;
      puVar8 = PTR_DAT_0305a9f0;
      puVar2 = PTR_text_entry_current_char_0305a9ec;
      if (*(byte *)(iVar4 + 5) != uVar15) break;
      uVar13 = (uint)(byte)*puVar7;
      cVar1 = PTR_LAB_0305a828[uVar13 * 10 + uVar15];
      if (cVar1 == '\x01') goto LAB_0305a718;
      uVar12 = puVar6[uVar13 * 10 + uVar15];
      cVar14 = *(char *)(iVar5 + 0x321) + '\x01';
      *(char *)(iVar5 + 0x321) = cVar14;
      if (cVar1 == cVar14) {
        *(undefined1 *)(iVar5 + 0x321) = 0;
      }
      display_draw_single_char_or_gb2312_glyph(uVar12);
      *(undefined1 *)(iVar4 + 4) = 0xf0;
    }
    display_fill_rect(*(short *)PTR_text_entry_current_char_0305a9ec + -0xc,
                      *(short *)PTR_DAT_0305a9f0,*(short *)PTR_text_entry_current_char_0305a9ec,
                      *(short *)PTR_DAT_0305a9f0 + 0x18,0xc618);
    display_draw_string_ascii_mixed
              (*(undefined2 *)puVar8,*(short *)puVar2 + -0xc,DAT_0305a9f8 + (uint)*DAT_0305a9f4,1,
               0xffff,0);
  } while( true );
}

