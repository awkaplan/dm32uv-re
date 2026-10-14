/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_frequency_display_setup @ 03047374 (file base 0x03000000; code starts at 0x03001000)
 * Size: 160 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_frequency_display_setup(void)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  uint unaff_r4;
  char *pcVar5;
  uint in_stack_00000034;
  uint in_stack_00000038;
  
  puVar3 = PTR_DAT_03047540;
  bVar1 = PTR_DAT_03047540[4];
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar3;
  *(undefined1 *)PTR_active_screen_subtype_0304754c = puVar3[5];
  if (*(char *)PTR_DAT_03047550 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  init_field_pair_0x20_5();
  channel_record_load_by_index();
  memcpy_ck803s(&stack0x00000034,&stack0x00000000,0x33);
  cVar2 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304755c + 2);
  if (cVar2 == '\0') {
    p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f | 0x20;
  }
  else {
    in_stack_00000034 = unaff_r4;
    if (cVar2 == '\x01') {
      p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f | 0x40;
      in_stack_00000034 = in_stack_00000038;
    }
  }
  pcVar5 = PTR_DAT_03047564 + -8;
  pcVar4 = PTR_DAT_03047564;
  do {
    *pcVar4 = (char)in_stack_00000034 + (char)(in_stack_00000034 / 10) * -10 + '0';
    pcVar4 = pcVar4 + -1;
    in_stack_00000034 = in_stack_00000034 / 10;
  } while (pcVar4 != pcVar5);
  *(undefined1 *)PTR_DAT_03047568 = 8;
  *(undefined2 *)p_text_entry_current_char = 0x6c;
  return;
}

