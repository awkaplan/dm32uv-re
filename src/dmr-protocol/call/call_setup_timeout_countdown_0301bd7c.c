/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_timeout_countdown @ 0301bd7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 192 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_timeout_countdown(void)

{
  byte bVar1;
  undefined2 *puVar2;
  ushort uVar3;
  
  if ((*(byte *)(PTR_DAT_0301be40 + 1) & 8) != 0) {
    PTR_DAT_0301be3c[0xb] = 0;
    bVar1 = *(byte *)(PTR_DAT_0301be40 + 1);
    *(byte *)(PTR_DAT_0301be40 + 1) = bVar1 & 0xf7;
    if ((bVar1 & 0x10) != 0) {
      display_toggle_box_or_bitmap_by_flag(1);
      *(byte *)(PTR_DAT_0301be40 + 1) = *(byte *)(PTR_DAT_0301be40 + 1) & 0xef;
    }
  }
  puVar2 = PTR_DAT_0301be3c;
  if (((((*(byte *)PTR_DAT_0301be40 & 0x42) == 0) && ((*(byte *)p_call_active_flag & 0xf) == 0)) &&
      ((p_dialog_flags_from_flash->flags_0x1 & 3) == 0)) && (p_dm32_settings_block04[0x6e] != '\0'))
  {
    uVar3 = PTR_DAT_0301be3c[0xb] + 1;
    PTR_DAT_0301be3c[0xb] = uVar3;
    if ((uint)uVar3 < (uint)(ushort)puVar2[0xc]) {
      if ((int)((uint)(ushort)puVar2[0xc] - (uint)uVar3) < 0x15) {
        if ((*(byte *)(PTR_DAT_0301be40 + 1) & 0x10) == 0) {
          *(byte *)(PTR_DAT_0301be40 + 1) = *(byte *)(PTR_DAT_0301be40 + 1) & 0xef | 0x10;
        }
        ui_event_notify(0x25);
        settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
      }
    }
    else {
      PTR_DAT_0301be64[0xb] = 0;
      OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x40000);
    }
  }
  return;
}

