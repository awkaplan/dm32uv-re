/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_monitor_mode_cycle_advance @ 03059c1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_monitor_mode_cycle_advance(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  
  if (*(char *)PTR_DAT_03059cf8 != '\x04') {
    cVar3 = *(char *)((int)PTR_DAT_03059cf8 + 3) + '\x01';
    *(char *)((int)PTR_DAT_03059cf8 + 3) = cVar3;
    if (cVar3 == '\x04') {
      *(undefined1 *)((int)PTR_DAT_03059cf8 + 3) = 0;
    }
    if (((p_dm32_settings_block04[0x30] & 0x40) != 0) &&
       (*(char *)((int)PTR_DAT_03059cf8 + 3) == '\0')) {
      *(undefined1 *)((int)PTR_DAT_03059cf8 + 3) = 1;
    }
    puVar1 = PTR_DAT_03059cf8;
    *(undefined1 *)(PTR_DAT_03059cf8 + 1) = 0xf0;
    *(undefined1 *)((int)puVar1 + 5) = 0xf0;
    puVar2 = PTR_DAT_03059cf8;
    cVar3 = *(char *)((int)puVar1 + 3);
    if (cVar3 == '\x01') {
      if (*(char *)PTR_DAT_03059cf8 != '\x03') {
        *(undefined1 *)PTR_DAT_03059cf8 = 3;
        *(undefined1 *)PTR_DAT_03059d08 = 0;
        *(undefined1 *)PTR_DAT_03059d0c = 0;
        *(undefined1 *)PTR_DAT_03059d10 = 0;
        *(undefined1 *)PTR_DAT_03059d04 = 0;
        scan_monitor_display_refresh();
        dialog_header_draw_two_lines();
        *(undefined1 *)puVar2 = 3;
      }
    }
    else if (cVar3 == '\0') {
      *(undefined1 *)PTR_DAT_03059d18 = 2;
      *(undefined1 *)PTR_DAT_03059d08 = 0;
      *(undefined1 *)PTR_DAT_03059d10 = 0;
      *(undefined1 *)PTR_DAT_03059d0c = 0;
      *(undefined1 *)PTR_DAT_03059d04 = 0;
    }
    else if (cVar3 == '\x02') {
      *(undefined1 *)PTR_DAT_03059d18 = 0;
      PTR_DAT_03059ce8[0x321] = 0;
    }
    else if (cVar3 == '\x03') {
      *(undefined1 *)PTR_DAT_03059d18 = 1;
      PTR_DAT_03059ce8[0x321] = 0;
    }
    scan_channel_icon_draw(*(undefined1 *)((int)PTR_DAT_03059cf8 + 3));
  }
  return;
}

