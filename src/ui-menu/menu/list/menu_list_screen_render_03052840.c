/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_screen_render @ 03052840 (file base 0x03000000; code starts at 0x03001000)
 * Size: 332 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_list_screen_render(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  ushort block_id;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  undefined1 auStack_38 [14];
  undefined1 uStack_2a;
  char cStack_25;
  
  block_id = flash_block_id_resolve_locked(10);
  flash_block_read(block_id,0,&cStack_25,1);
  puVar2 = PTR_active_screen_visible_rows_030529ac;
  puVar1 = PTR_active_screen_flag_0003e5d5_030529a8;
  if (*(char *)PTR_active_screen_option_count_030529a0 == '\0') {
    display_draw_string_gb2312
              (0x82,5,(byte *)**(undefined4 **)
                                (PTR_PTR_030529bc + ((byte)PTR_DAT_030529b0[0x30] >> 6 & 1) * 8),0,0
              );
  }
  else {
    if (1 < *(byte *)PTR_active_screen_visible_rows_030529ac + 1) {
      uVar3 = (*(byte *)PTR_active_screen_state_word_030529a4 + 1) -
              (uint)(byte)*PTR_active_screen_flag_0003e5d5_030529a8;
      uVar8 = 0;
      uVar7 = 1;
      do {
        if (cStack_25 != '\0') {
          uVar6 = uVar8 + 1 & 0xff;
          cVar5 = cStack_25;
          uVar4 = uVar8;
          while (uVar8 = uVar6, (uVar3 & 0xff) != uVar4) {
            cVar5 = cVar5 + -1;
            if (cVar5 == '\0') goto LAB_030528da;
            uVar6 = uVar8 + 1 & 0xff;
            uVar4 = uVar6 - 1 & 0xff;
          }
          cStack_25 = cVar5 + -1;
          flash_block_read(block_id,(uVar8 - 1) * 0x81 + 0x11 & 0xffff,auStack_38,0xe);
          uStack_2a = 0;
        }
LAB_030528da:
        if ((byte)*puVar1 == uVar7) {
          menu_list_row_draw_with_icon(uVar7 - 1,auStack_38,1,0);
        }
        else {
          menu_list_row_draw_with_icon(uVar7 - 1,auStack_38,0,0);
        }
        uVar7 = uVar7 + 1 & 0xff;
        if ((ushort)(*(byte *)puVar2 + 1) <= uVar7) break;
        uVar3 = (uVar3 & 0xff) + 1;
      } while( true );
    }
    if ((PTR_DAT_030529b0[0x30] & 0x40) == 0) {
      number_to_string_format_2args
                (auStack_38,PTR_LAB_030529b4,*(byte *)PTR_active_screen_state_word_030529a4 + 1,
                 *(undefined1 *)PTR_active_screen_option_count_030529a0);
    }
    else {
      number_to_string_format_2args
                (auStack_38,PTR_s_Quick_Text__d__d_030529b8,
                 *(byte *)PTR_active_screen_state_word_030529a4 + 1,
                 *(undefined1 *)PTR_active_screen_option_count_030529a0);
    }
    display_fill_rect(0,0,0xf0,0x1b,0);
    display_draw_number_centered(1,0xffff,0,(uint)auStack_38);
  }
  return;
}

