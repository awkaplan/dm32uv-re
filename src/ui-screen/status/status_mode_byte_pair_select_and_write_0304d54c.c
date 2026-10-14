/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_mode_byte_pair_select_and_write @ 0304d54c (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_mode_byte_pair_select_and_write(void)

{
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d638 + 2) == '\x03') {
    write_status_mode_byte_pair(0x1c,1);
  }
  else if (*(char *)p_active_screen_option_count == '\0') {
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304d60c + DAT_0304d610),0);
  }
  else {
    write_status_mode_byte_pair(0x1c,1);
  }
  return;
}

