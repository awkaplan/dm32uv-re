/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: control_action_char_dispatch @ 03056ba8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void control_action_char_dispatch(undefined2 *param_1,undefined2 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_DAT_03056c08;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03056c00 + 2);
  if (cVar1 == '\x01') {
    if (*(short *)PTR_DAT_03056c04 != 1) {
      menu_cursor_decrement_with_wrap();
      channel_list_render_rows_flash_matching_value
                (*param_1,*param_2,*(undefined2 *)PTR_DAT_03056c04);
    }
  }
  else if (cVar1 == '\x02') {
    menu_cursor_decrement_with_wrap(param_1,param_2,*(undefined2 *)PTR_DAT_03056c08);
    channel_list_render_rows_free_slot(*param_1,*param_2,*(undefined2 *)puVar2);
  }
  return;
}

