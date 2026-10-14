/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_exit_timer_tick @ 030544ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 482 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_exit_timer_tick(void)

{
  bool bVar1;
  byte *pbVar2;
  char cVar3;
  char cVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 auStack_8 [4];
  
  puVar5 = PTR_DAT_03054604;
  if ((PTR_DAT_030545ec[8] & 1) != 0) {
    return;
  }
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    bVar1 = (*(byte *)p_call_active_flag & 8) != 0;
  }
  else {
    bVar1 = false;
  }
  if ((PTR_DAT_030545f8[0x2b] & 8) != 0) {
    bVar1 = true;
  }
  cVar3 = *(char *)PTR_active_screen_subtype_030545fc;
  if (cVar3 == '\n') {
    bVar1 = true;
  }
  if ((((p_dialog_flags_from_flash->flags_0x1e & 0x70) == 0x20) ||
      ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1)) || (bVar1)) {
    PTR_DAT_03054604[10] = 0;
    *(undefined1 *)PTR_DAT_03054608 = 0;
    return;
  }
  if (((cVar3 == '\x13') && (*(char *)PTR_DAT_0305460c == '\x04')) &&
     ((*(byte *)PTR_DAT_03054610 & 4) != 0)) {
    list_display_with_strlen_format();
    PTR_DAT_03054604[10] = 0;
    *(undefined1 *)PTR_DAT_03054608 = 0;
    return;
  }
  if ((((*(byte *)PTR_DAT_03054614 < 7) || (0x3f < *(byte *)PTR_DAT_03054614)) &&
      ((*(char *)PTR_DAT_03054614 != 'i' && (*(char *)PTR_DAT_03054614 != 'w')))) ||
     ((*(byte *)PTR_DAT_03054618 & 2) != 0)) {
    *(undefined1 *)(PTR_DAT_03054744 + 5) = 0;
    if (*(char *)PTR_DAT_03054748 != '\0') {
      return;
    }
    if ((*(byte *)p_call_active_flag & 3) != 0) {
      return;
    }
    if (p_radio_mode_state_0003e318[1].flags_0x2 != 0) {
      return;
    }
    if ((*(uint *)PTR_DAT_03054754 & 0x18000) != 0x18000) {
      return;
    }
    if ((*(byte *)PTR_DAT_03054758 & 2) != 0) {
      return;
    }
    cVar3 = *(char *)PTR_DAT_0305475c;
    *(byte *)PTR_DAT_0305475c = cVar3 + 1U;
    if ((byte)(cVar3 + 1U) < 6) {
      return;
    }
    *(undefined1 *)PTR_DAT_0305475c = 0;
    PTR_DAT_03054754[2] = PTR_DAT_03054754[2] & 0xfe;
    rda5807m_fm_on();
    iVar6 = get_current_mode_state2();
    if ((iVar6 != 0) && ((PTR_DAT_03054760[1] & 1) != (byte)p_dm32_settings_block04[0x2d] >> 7)) {
      vfo_load_side_config();
      settings_bitfield_remap_0x2d();
      PTR_DAT_03054760[1] = PTR_DAT_03054760[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
      ui_event_notify_alt(0x13);
    }
    write_field_and_mbox_post(1,100);
    return;
  }
  pbVar2 = PTR_DAT_03054604 + 0xb;
  if (*pbVar2 == 0) {
    return;
  }
  cVar4 = PTR_DAT_03054604[10];
  PTR_DAT_03054604[10] = cVar4 + 1U;
  if ((byte)(cVar4 + 1U) < *pbVar2) {
    return;
  }
  puVar5[10] = 0;
  if (cVar3 == '\n') {
    if (*(char *)PTR_DAT_0305461c != '\x03') goto LAB_030545c6;
  }
  else if (cVar3 != '\b') goto LAB_030545c6;
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_8);
LAB_030545c6:
  p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfe;
  write_field_and_mbox_post(1,100);
  return;
}

