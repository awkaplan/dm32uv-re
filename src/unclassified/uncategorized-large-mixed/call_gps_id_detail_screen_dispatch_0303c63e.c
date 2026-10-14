/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_gps_id_detail_screen_dispatch @ 0303c63e (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_gps_id_detail_screen_dispatch(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = *(char *)PTR_DAT_0303c7ac;
  if (cVar1 == '\0') {
    call_record_detail_render();
  }
  else if (cVar1 == '\x01') {
    display_clear_body_and_underline();
    aprs_log_record_detail_screen(*(undefined2 *)PTR_DAT_0303c7b0);
  }
  else if (cVar1 == '\x02') {
    display_fill_rect(0,0,0xf0,0x1b,0);
    puVar2 = p_active_screen_index_list;
    display_draw_number_centered
              (1,0xffff,0,
               *(uint *)(PTR_PTR_0303c7bc[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                        (uint)*(byte *)((int)p_active_screen_index_list +
                                       p_menu_screen_state->index_0x3 + 0x8f) * 4));
    if (*(ushort *)puVar2 < 9) {
      *(char *)PTR_active_screen_visible_rows_0303c7c0 = (char)*(ushort *)puVar2;
    }
    else {
      *(undefined1 *)PTR_active_screen_visible_rows_0303c7c0 = 8;
    }
    radio_id_detail_screen();
  }
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

