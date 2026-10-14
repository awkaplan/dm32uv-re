/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mode_display_icon_draw_dispatch @ 0303bee0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void mode_display_icon_draw_dispatch(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  
  bVar1 = *(byte *)p_active_screen_option_count;
  *(ushort *)p_active_screen_index_list = (ushort)bVar1;
  if (*(uint *)*p_active_screen_option_ptr_array != 0) {
    if (bVar1 == 1) {
      dialog_show_icon_and_two_numbers(0x30,0x30,PTR_DAT_0303c008);
    }
    else if (bVar1 == 2) {
      dialog_show_icon_and_two_numbers(0x30,0x30,PTR_DAT_0303c008);
    }
    else if (bVar1 == 3) {
      display_draw_number_centered(0x72,0,0xc618,*(uint *)*p_active_screen_option_ptr_array);
      puVar3 = p_active_screen_option_ptr_array;
      display_draw_number_centered(0x90,0,0xc618,*(uint *)(*p_active_screen_option_ptr_array + 4));
      display_draw_number_centered(0xae,0,0xc618,*(uint *)(*puVar3 + 8));
    }
  }
  dialog_header_draw_two_lines();
  cVar2 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar2 != '\b') && (cVar2 != '\x05')) && (cVar2 != '\x06')) &&
        ((cVar2 != '\x04' && (cVar2 != '\x18')))) &&
       ((cVar2 != '\x03' && ((cVar2 != '\n' && (cVar2 != '\x17')))))) && (cVar2 != '%')) &&
     ((cVar2 != '/' && ((cVar2 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  return;
}

