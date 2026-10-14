/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_edit_field_init_or_commit_dispatch @ 03041db8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_edit_field_init_or_commit_dispatch(void)

{
  menu_screen_state *pmVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if ((*(byte *)PTR_DAT_03041e44 & 2) == 0) {
    display_fill_rect(0,0,0xf0,0x1b,0);
    uVar3 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03041fd0 + 2);
    if (uVar3 < 8) {
                    /* WARNING: Could not recover jumptable at 0x03041f9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_03041fd4[uVar3] & 0xfffffffe))();
      return;
    }
  }
  else {
    display_fill_rect(0,0,0xf0,0x1b,0);
    puVar2 = p_active_screen_index_list;
    pmVar1 = p_menu_screen_state;
    display_draw_number_centered
              (0,0xffff,0,
               *(uint *)(*PTR_PTR_03041e48 +
                        (uint)(byte)p_active_screen_index_list
                                    [p_menu_screen_state->index_0x2 + 0x6c] * 4));
    if ((byte)puVar2[pmVar1->index_0x2 + 0x6c] < 8) {
                    /* WARNING: Could not recover jumptable at 0x03041e10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_03041e4c[(byte)puVar2[pmVar1->index_0x2 + 0x6c]] & 0xfffffffe))();
      return;
    }
  }
  return;
}

