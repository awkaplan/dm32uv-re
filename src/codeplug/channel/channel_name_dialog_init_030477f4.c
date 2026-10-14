/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_name_dialog_init @ 030477f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_name_dialog_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  
  puVar1 = PTR_DAT_03047960;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03047960 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03047940 = *(undefined1 *)((int)puVar1 + 5);
  if (*(char *)PTR_DAT_03047944 == '\x01') {
    dialog_request_init(0x10);
    iVar2 = p_text_entry_buffer;
    read_channel_field_from_flash
              (p_dm32_settings_block04[0x26],(byte)p_dm32_settings_block04[0x2d] >> 7,
               p_text_entry_buffer);
    cVar3 = strlen_ck803s(iVar2);
    *(byte *)PTR_DAT_03047968 = cVar3 + 1U;
    if (0x10 < (byte)(cVar3 + 1U)) {
      *(undefined1 *)(iVar2 + 0x10) = 0;
      *(undefined1 *)PTR_DAT_03047968 = 0x11;
    }
    *(char *)PTR_DAT_0304796c = *(char *)PTR_DAT_03047968 + -1;
    *(undefined2 *)PTR_DAT_03047970 = 0x20;
    *(undefined2 *)p_text_entry_current_char = 5;
    *(undefined1 *)p_text_entry_current_char_alias = 0;
    gb2312_text_wrap_calculate(p_text_entry_buffer);
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf | 0x20;
  }
  return;
}

