/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: numeric_value_adjust_dialog_screen @ 0303bd6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
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

void numeric_value_adjust_dialog_screen(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  short sVar4;
  
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered
            (1,0xffff,0,
             *(uint *)(PTR_PTR_0303be08[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8));
  display_fill_screen(0);
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0303be10 + 2);
  if (cVar1 == '\x01') {
    SUBPIECE_SET(uVar2, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
    SUBPIECE_SET(uVar2, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
    uVar3 = vfo_freq_display_index_from_offset(*(undefined1 *)PTR_DAT_0303be14,uVar2);
    *(short *)PTR_DAT_0303be18 = (short)uVar3;
    channel_list_render_rows_flash_matching_value
              (*(undefined2 *)PTR_DAT_0303bde4,*(undefined2 *)PTR_DAT_0303bde8,uVar3);
  }
  else if (cVar1 == '\x02') {
    sVar4 = *(short *)&p_radio_mode_state_0003e318[1].field_0x8 - (ushort)*DAT_0303bfb8;
    *(short *)PTR_DAT_0303bfc0 = sVar4;
    *(short *)PTR_DAT_0303bfc4 = sVar4;
    channel_list_render_rows_free_slot
              (*(undefined2 *)PTR_DAT_0303bfc8,*(undefined2 *)PTR_DAT_0303bfcc);
  }
  dialog_header_draw_two_lines();
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

