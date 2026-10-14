/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_event_filter_dispatch1 @ 030392d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void key_event_filter_dispatch1(void)

{
  char cVar1;
  
  cVar1 = *(char *)PTR_active_screen_subtype_03039370;
  if ((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
       ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
      ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) &&
     ((cVar1 != '%' && (cVar1 != '/')))) {
    if (cVar1 == '\x16') {
      if (*(char *)PTR_DAT_03039374 == '\x01') {
        return;
      }
    }
    else if ((cVar1 == '\v') || (cVar1 == '\x1a')) {
      signal_level_bargraph_render(*(undefined2 *)PTR_DAT_03039378,*(undefined2 *)PTR_DAT_0303937c);
      return;
    }
    if (cVar1 == '!') {
      signal_level_bargraph_render(*(undefined2 *)PTR_DAT_03039380,*(undefined2 *)PTR_DAT_03039384);
    }
    else if (cVar1 == '\x15') {
      signal_level_bargraph_render(*(undefined2 *)PTR_DAT_03039388,*(undefined2 *)PTR_DAT_0303938c);
    }
    else {
      signal_level_bargraph_render
                (*(undefined1 *)p_active_screen_state_word,*(undefined2 *)p_active_screen_index_list
                );
    }
  }
  return;
}

