/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_scroll_list_cursor_advance @ 0302e9c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_scroll_list_cursor_advance(undefined1 *param_1,undefined1 *param_2)

{
  if (*(char *)p_vfo_freq_display_state != '\0') {
    list_cursor_increment(param_1,param_2,*(char *)p_vfo_freq_display_state + '\x01');
    scrollable_list_menu_render_8row(*param_1,*param_2,*(char *)p_vfo_freq_display_state + '\x01');
  }
  return;
}

