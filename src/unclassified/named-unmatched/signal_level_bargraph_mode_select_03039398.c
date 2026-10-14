/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: signal_level_bargraph_mode_select @ 03039398 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void signal_level_bargraph_mode_select(void)

{
  char cVar1;
  
  cVar1 = *(char *)PTR_active_screen_subtype_030394c8;
  if ((cVar1 == '\v') || (cVar1 == '\x1a')) {
    signal_level_bargraph_render(*(undefined2 *)PTR_DAT_030394cc,*(undefined2 *)PTR_DAT_030394d0);
  }
  else if (cVar1 == '!') {
    signal_level_bargraph_render(*(undefined2 *)PTR_DAT_030394d4,*(undefined2 *)PTR_DAT_030394d8);
  }
  else if (cVar1 == '\x15') {
    signal_level_bargraph_render(*(undefined2 *)PTR_DAT_030394dc,*(undefined2 *)PTR_DAT_030394e0);
  }
  else {
    signal_level_bargraph_render
              (*(undefined1 *)p_active_screen_state_word,*(undefined2 *)p_active_screen_index_list);
  }
  return;
}

