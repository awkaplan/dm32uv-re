/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_list_field_write_dispatch_b @ 0304e6e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_list_field_write_dispatch_b(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_0304e710 + 2);
  if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0304e6f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0304e714[uVar1] & 0xfffffffe))();
    return;
  }
  call_list_index_write();
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e7a8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}

