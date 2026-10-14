/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_record_number_table_display @ 0303c6d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_record_number_table_display(void)

{
  char cVar1;
  
  display_draw_dialog_panel();
  record_read_by_index(*(undefined2 *)((int)PTR_DAT_0303c7c4 + 1),&stack0x00000008);
  display_draw_number_centered(0x90,0,0xc618,(uint)&stack0x0000000a);
  display_draw_number_centered
            (0xae,0,0xc618,
             **(uint **)(PTR_PTR_0303c7c8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_from_table(0);
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

