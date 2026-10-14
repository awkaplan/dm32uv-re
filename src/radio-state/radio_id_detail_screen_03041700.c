/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_id_detail_screen @ 03041700 (file base 0x03000000; code starts at 0x03001000)
 * Size: 352 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_id_detail_screen(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  byte local_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  undefined1 uStack_23;
  undefined1 uStack_18;
  
  display_fill_screen(0);
  puVar1 = p_active_screen_option_ptr_array;
  display_draw_string_gb2312(0x28,10,*(byte **)(*p_active_screen_option_ptr_array + 4),0xffff,0);
  radio_id_entry_read_by_stored_index(&local_28);
  uStack_18 = 0;
  display_draw_number_centered(0x46,0xffff,0,(uint)&local_28);
  display_draw_string_gb2312(100,10,*(byte **)*puVar1,0xffff,0);
  number_to_string_format_2args
            (&local_28,PTR_s__d_030afae0_8_03041888,*p_text_entry_current_char_alias);
  uVar2 = strlen_ck803s(*(undefined4 *)*puVar1);
  display_draw_string_gb2312(100,(uVar2 & 0xff) * 0xc + 10,&local_28,0xffff,0);
  display_draw_string_gb2312(0x82,10,*(byte **)(*puVar1 + 8),0xffff,0);
  local_28 = PTR_DAT_03041890[6] + 0x30;
  cStack_27 = PTR_DAT_03041890[7] + '0';
  cStack_26 = PTR_DAT_03041890[8] + '0';
  cStack_25 = 0;
  uVar2 = strlen_ck803s(*(undefined4 *)(*puVar1 + 8));
  display_draw_string_gb2312(0x82,(uVar2 & 0xff) * 0xc + 10,&local_28,0xffff,0);
  display_draw_string_gb2312(0xa0,10,*(byte **)(*puVar1 + 0xc),0xffff,0);
  number_to_string_format_2args(&local_28,PTR_LAB_03041894,*(undefined2 *)PTR_DAT_03041898);
  uVar2 = strlen_ck803s(*(undefined4 *)(*puVar1 + 0xc));
  display_draw_string_gb2312(0xa0,(uVar2 & 0xff) * 0xc + 10,&local_28,0xffff,0);
  display_draw_string_gb2312(0xbe,10,*(byte **)(*puVar1 + 0x10),0xffff,0);
  local_28 = *(char *)PTR_DAT_0304189c + 0x30;
  cStack_27 = *(char *)((int)PTR_DAT_0304189c + 1) + '0';
  cStack_26 = *(char *)((int)PTR_DAT_0304189c + 2) + '0';
  cStack_25 = *(char *)((int)PTR_DAT_0304189c + 3) + '0';
  cStack_24 = *(char *)(PTR_DAT_0304189c + 1) + '0';
  uStack_23 = 0;
  uVar2 = strlen_ck803s(*(undefined4 *)(*puVar1 + 0x10));
  display_draw_string_gb2312(0xbe,(uVar2 & 0xff) * 0xc + 10,&local_28,0xffff,0);
  return;
}

