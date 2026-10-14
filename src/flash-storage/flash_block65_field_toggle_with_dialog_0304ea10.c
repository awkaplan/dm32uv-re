/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block65_field_toggle_with_dialog @ 0304ea10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block65_field_toggle_with_dialog(void)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  byte local_c [4];
  
  puVar4 = p_active_screen_state_word;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304eb14 + 2);
  if (cVar1 == '\0') {
    flash_field_read_cached(0x65,1,local_c,1);
    if (*(char *)p_active_screen_state_word == '\0') {
      local_c[0] = local_c[0] | 1;
      iVar5 = vfo_active_side_mode_nibble();
      if ((iVar5 == 1) || (iVar5 == 3)) {
        if ((p_vfo_display_state->flags_0x8 & 8) != 0) {
          dialog_show_icon_and_number
                    (3,**(undefined4 **)
                         (PTR_PTR_0304eb20 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
          return;
        }
        *PTR_DAT_0304eafc = *PTR_DAT_0304eafc & 0xfe | 1;
      }
    }
    else {
      local_c[0] = local_c[0] & 0xfe;
      *PTR_DAT_0304eafc = *PTR_DAT_0304eafc & 0xe2;
    }
    flash_field_write_cached(0x65,1,local_c[0]);
    menu_row_highlight_draw();
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0304eb24 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else if (cVar1 == '\x01') {
    flash_field_write_cached(0x65,2,*(undefined1 *)p_active_screen_state_word);
    puVar3 = PTR_DAT_0304eafc;
    bVar2 = *(byte *)puVar4;
    PTR_DAT_0304eafc[1] = (char)((uint)bVar2 * 0x3c);
    puVar3[2] = (char)((uint)bVar2 * 0x3c >> 8);
    dialog_show_icon_and_number_from_ptr();
  }
  return;
}

