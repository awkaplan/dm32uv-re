/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_mode_state_transition_handler @ 03059bac (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_mode_state_transition_handler(void)

{
  byte *pbVar1;
  char cVar2;
  radio_mode_state_0003e318 *prVar3;
  
  prVar3 = p_radio_mode_state_0003e318;
  cVar2 = *(char *)PTR_DAT_03059cf8;
  if (cVar2 == '\x03') {
    pbVar1 = &p_radio_mode_state_0003e318->flags_0x5;
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xcf;
    prVar3->flags_0x5 = *pbVar1 & 0xd2;
    *(undefined1 *)PTR_DAT_03059d00 = 0;
    history_queue_pop();
  }
  else if ((byte)(cVar2 - 1U) < 2) {
    *(undefined1 *)PTR_DAT_03059d04 = 0;
    *(undefined1 *)PTR_DAT_03059d08 = 0;
    *(undefined1 *)PTR_DAT_03059d0c = 0;
    *(undefined1 *)PTR_DAT_03059d10 = 0;
    *(undefined1 *)PTR_DAT_03059cf8 = 3;
    scan_monitor_display_refresh();
  }
  else if (cVar2 == '\x04') {
    scan_monitor_display_refresh();
    *(undefined1 *)PTR_DAT_03059cf8 = 3;
  }
  return;
}

