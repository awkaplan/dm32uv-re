/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_conditional_complex @ 0304ff46 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_wrapper_conditional_complex(void)

{
  int iVar1;
  
  if (*(char *)p_active_screen_state_word == '\0') {
    iVar1 = get_current_mode_state1();
    if (iVar1 == 0) {
      rda5807m_fm_on();
      write_status_mode_byte_pair(0,1);
    }
    else {
      dialog_show_icon_and_number(0,PTR_PTR_0305002c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
    }
  }
  else {
    rda5807m_fm_off();
  }
  return;
}

