/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fm_radio_seek_up_gated_handler @ 0301641c (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fm_radio_seek_up_gated_handler(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = poll_condition_group(0x1f);
  if (*(char *)PTR_DAT_030164a0 == '\0') {
    if (PTR_DAT_03016498[0xc] == '\0') {
      bVar1 = iVar2 != 0;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  if ((((*(byte *)((int)PTR_DAT_030164a8 + 1) & 0x80) == 0) ||
      ((*PTR_DAT_030164a8 & 0x18000) == 0x18000)) || (!bVar1)) {
    ui_event_notify(0x21);
  }
  else if ((*(byte *)((int)PTR_DAT_030164a8 + 2) & 2) == 0) {
    *(byte *)((int)PTR_DAT_030164a8 + 2) = *(byte *)((int)PTR_DAT_030164a8 + 2) & 0xfd | 2;
    battery_value_display_format((uint)~(int)(char)PTR_DAT_030164a4[0x2d] >> 0x1f);
    rda5807m_seek_up(*(undefined2 *)PTR_DAT_030164ac);
  }
  return;
}

