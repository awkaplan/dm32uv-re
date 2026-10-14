/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_field_value_screen_render_and_key_dispatch @ 0303b720 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_field_value_screen_render_and_key_dispatch(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  menu_field_value_display_dispatch();
  uVar2 = *(ushort *)p_active_screen_index_list;
  if (uVar2 < 9) {
    *(char *)PTR_active_screen_visible_rows_0303b8ac = (char)uVar2;
  }
  else {
    *(undefined1 *)PTR_active_screen_visible_rows_0303b8ac = 8;
  }
  if (uVar2 == 0) {
    history_queue_pop();
    *(ushort *)p_active_screen_index_list = (ushort)*DAT_0303b8b0;
    p_dialog_history_ui_state->field_0x4 = 0;
    return;
  }
  if (*p_active_screen_option_ptr_array == 0) {
    display_fill_screen(0);
    return;
  }
  if (*(char *)PTR_active_screen_subtype_0303b8bc == '\x02') {
    display_fill_screen(0);
    display_list_with_icons_renderer();
LAB_0303b788:
    if (*(char *)PTR_active_screen_subtype_0303b8bc == '\x13') {
      display_fill_rect(0,0x122,0xf0,0x140,0);
      iVar3 = vfo_active_side_mode_nibble();
      if ((iVar3 == 1) || (iVar3 = vfo_active_side_mode_nibble(), iVar3 == 3)) {
        display_draw_string_gb2312
                  (0x122,0xc,
                   (byte *)**(undefined4 **)
                             (PTR_PTR_0303b8c4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8)
                   ,0xffff,0);
      }
      display_draw_string_gb2312
                (0x122,0xb4,
                 (byte *)**(undefined4 **)
                           (PTR_PTR_0303b8c8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 0xffff,0);
      goto LAB_0303c7fe;
    }
  }
  else if (*(char *)PTR_active_screen_subtype_0303b8bc == '\x13') {
    display_fill_screen(0);
    list_display_with_strlen_format();
    goto LAB_0303b788;
  }
  dialog_header_draw_two_lines();
LAB_0303c7fe:
  cVar1 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
        ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
       ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) && (cVar1 != '%')) &&
     ((cVar1 != '/' && ((cVar1 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  return;
}

