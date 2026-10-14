/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_mode_reset_and_post_0x62_on_bit1 @ 0304cf30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void status_mode_reset_and_post_0x62_on_bit1(void)

{
  if ((*(byte *)PTR_DAT_0304d090 & 2) != 0) {
    *(undefined1 *)PTR_DAT_0304d098 = *(undefined1 *)p_active_screen_state_word;
    *(undefined1 *)PTR_DAT_0304d09c = 0;
    *(undefined1 *)PTR_DAT_0304d0a0 = 0;
    write_status_mode_byte_pair(0x62,1);
  }
  return;
}

