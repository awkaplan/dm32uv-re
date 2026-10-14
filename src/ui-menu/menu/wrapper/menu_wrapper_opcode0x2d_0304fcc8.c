/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_opcode0x2d @ 0304fcc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_wrapper_opcode0x2d(void)

{
  undefined1 *puVar1;
  
  puVar1 = p_dm32_settings_block04;
  p_dm32_settings_block04[0x3a] = *(undefined1 *)p_active_screen_state_word;
  settings_write_dispatcher(0x2d);
  menu_row_highlight_draw();
  dialog_show_icon_and_number
            (1,**(undefined4 **)(PTR_PTR_0304fe48 + ((byte)puVar1[0x30] >> 6 & 1) * 8));
  return;
}

