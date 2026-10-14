/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_adjust_shortcut @ 03052a84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_freq_adjust_shortcut(void)

{
  byte bVar1;
  
  if (*(char *)p_active_screen_flag_0003e5d5 == '\x01') {
    if (*(char *)p_active_screen_state_word == '\0') {
      bVar1 = *(byte *)p_active_screen_option_count;
      if (bVar1 < 9) {
        *(byte *)p_active_screen_state_word = bVar1 - 1;
        *(byte *)p_active_screen_flag_0003e5d5 = bVar1;
      }
      else {
        *(byte *)p_active_screen_state_word = bVar1 - 1;
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      }
    }
    else {
      *(char *)p_active_screen_state_word = *(char *)p_active_screen_state_word + -1;
    }
  }
  else {
    *(char *)p_active_screen_flag_0003e5d5 = *(char *)p_active_screen_flag_0003e5d5 + -1;
    *(char *)p_active_screen_state_word = *(char *)p_active_screen_state_word + -1;
  }
  return;
}

