/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_shutdown_confirm_screen @ 03052c98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_shutdown_confirm_screen(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  bVar1 = PTR_DAT_03052e0c[4];
  if (bVar1 == 0) {
    display_fill_screen(0);
    display_draw_glyph_row_mutex
              (0x46,0,**(undefined4 **)
                        (PTR_PTR_03052e28 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),0,
               0xffff);
    OSTimeDly_ms_wrapper(1000);
    history_queue_pop();
    write_field_and_mbox_post(1,0x2b);
  }
  else {
    *(byte *)p_active_screen_option_count = bVar1;
    puVar2 = PTR_DAT_03052e0c;
    *p_active_screen_option_ptr_array = *(undefined4 *)PTR_DAT_03052e0c;
    *(undefined1 *)PTR_active_screen_subtype_03052e18 = puVar2[5];
    *(ushort *)p_active_screen_index_list = (ushort)bVar1;
    *(undefined1 *)PTR_DAT_03052e20 = 4;
  }
  return;
}

