/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_scan_list_row_up_or_exit @ 0305b798 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_scan_list_row_up_or_exit(void)

{
  byte bVar1;
  
  if (*(char *)PTR_DAT_0305b8dc == '\x01') {
    *(undefined1 *)PTR_DAT_0305b8e0 = 3;
    *(undefined1 *)PTR_DAT_0305b8e4 = 0;
    *(undefined1 *)PTR_DAT_0305b8e8 = 0;
    *(undefined1 *)PTR_DAT_0305b8dc = 0;
    *(undefined1 *)PTR_DAT_0305b8ec = 0;
    scan_monitor_display_refresh();
  }
  else {
    bVar1 = *(char *)PTR_DAT_0305b8dc - 1;
    *(byte *)PTR_DAT_0305b8dc = bVar1;
    PTR_DAT_0305b8f0[bVar1] = 0;
    *(undefined1 *)PTR_DAT_0305b8e4 = 0;
    name_table_prefix_match_count();
    text_entry_char_picker_render();
    scan_list_row_render();
  }
  return;
}

