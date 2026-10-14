/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_periodic_state_tick @ 0302ee14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1240 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_mode_periodic_state_tick(void)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  ushort uVar6;
  
  iVar3 = get_current_mode_state1();
  if ((*_DAT_0302ef68 & 0x40) != 0) {
    return;
  }
  if (iVar3 == 0) {
    return;
  }
  iVar4 = keypad_dispatch_not_inhibited();
  if (iVar4 == 0) {
    dtmf_digit_input_handler();
    return;
  }
  if (iVar3 == 1) {
    if (((*(byte *)(_DAT_0302ef6c + 0x5c) < 2) && ((*(byte *)(_DAT_0302ef70 + 0x2d) & 4) != 0)) &&
       ((*(byte *)(_DAT_0302ef74 + 0x15) & 4) == 0)) {
      dtmf_digit_input_handler(0);
      return;
    }
    if ((*(byte *)(_DAT_0302ef78 + 1) & 3) != 0) {
      return;
    }
    bVar1 = *(char *)(_DAT_0302ef7c + 0x12) + 1;
    *(byte *)(_DAT_0302ef7c + 0x12) = bVar1;
    if (bVar1 < 0x32) {
      return;
    }
    bVar1 = vfo_active_side_mode_nibble();
    *(byte *)(_DAT_0302ef6c + 0x10) = *(byte *)(_DAT_0302ef6c + 0x10) & 0x9f | (bVar1 & 3) << 5;
    if ((*(byte *)(_DAT_0302ef74 + 0x15) & 4) == 0) {
      uVar2 = channel_list_index_resolve
                        (*(undefined1 *)(_DAT_0302ef70 + 0x29),*(undefined1 *)(_DAT_0302ef70 + 0x26)
                        );
      *(undefined2 *)(_DAT_0302ef6c + 0x56) = uVar2;
    }
    else {
      *(ushort *)(_DAT_0302ef6c + 0x56) = (ushort)*(byte *)(_DAT_0302ef70 + 0x26);
    }
    iVar3 = _DAT_0302ef6c;
    *(undefined2 *)(_DAT_0302ef6c + 0x5a) = *(undefined2 *)(_DAT_0302ef6c + 0x56);
    *(byte *)(_DAT_0302ef74 + 2) =
         *(byte *)(_DAT_0302ef74 + 2) & 0xf3 | (*(byte *)(_DAT_0302ef74 + 2) & 3) << 2;
    *(undefined1 *)(_DAT_0302ef7c + 0x12) = 0;
    *_DAT_0302ef80 = 0;
    *(byte *)(iVar3 + 0x5d) = *(byte *)(iVar3 + 0x5d) & 0xfe | 1;
    if ((*(char *)(iVar3 + 1) == '\0') && ((*(byte *)(_DAT_0302ef74 + 0x15) & 4) == 0)) {
      *(byte *)(_DAT_0302ef6c + 0xf) = *(byte *)(_DAT_0302ef6c + 0xf) & 0xdf | 0x20;
    }
    dtmf_digit_input_handler(3);
    vfo_frequency_panel_render();
    ui_event_notify(0x18);
    return;
  }
  if (iVar3 != 3) {
    if (iVar3 == 4) {
      bVar1 = *(char *)(_DAT_0302f284 + 0x12) + 1;
      *(byte *)(_DAT_0302f284 + 0x12) = bVar1;
      if ((*(byte *)(_DAT_0302f288 + 8) & 0xf0) == 0x10) {
        bVar5 = 100;
      }
      else {
        bVar5 = 0x1e;
      }
      if (bVar1 <= bVar5) {
        iVar3 = tx_is_inhibited();
        if (iVar3 == 0) {
          return;
        }
        *(undefined1 *)(_DAT_0302f284 + 0x12) = 0;
        dtmf_digit_input_handler(6);
        return;
      }
      *(undefined1 *)(_DAT_0302f284 + 0x12) = 0;
      *(byte *)(_DAT_0302f28c + 3) = *(byte *)(_DAT_0302f28c + 3) & 0xbf;
      *(byte *)(_DAT_0302f280 + 0x10) = *(byte *)(_DAT_0302f280 + 0x10) & 0xfe | 1;
      dtmf_digit_input_handler(3);
      return;
    }
    if (iVar3 != 6) {
      if (iVar3 != 2) {
        return;
      }
      if (*_DAT_0302f418 != 'M') {
        return;
      }
      dtmf_digit_input_handler(6);
      return;
    }
    if ((*(byte *)(_DAT_0302f280 + 0xf) & 0x40) != 0) {
      if ((*(byte *)(_DAT_0302f280 + 2) & 0xf0) == 0x10) {
        memcpy_bytes_iram(_DAT_0302f290,_DAT_0302f294,0x11);
      }
      iVar3 = _DAT_0302f280;
      *(undefined2 *)(_DAT_0302f280 + 0x56) = *(undefined2 *)(_DAT_0302f280 + 0x54);
      vfo_frequency_panel_render();
      *(byte *)(iVar3 + 0xf) = *(byte *)(iVar3 + 0xf) & 0xbf;
    }
    iVar3 = tx_is_inhibited();
    if (iVar3 == 0) {
      uVar6 = *(short *)(_DAT_0302f404 + 0x10) + 1;
      *(ushort *)(_DAT_0302f404 + 0x10) = uVar6;
      if (uVar6 < (ushort)((ushort)(byte)p_vfo_freq_display_state->field_0x3 * 0x32)) {
        return;
      }
      *(undefined2 *)(_DAT_0302f404 + 0x10) = 0;
      *(byte *)(_DAT_0302f414 + 3) = *(byte *)(_DAT_0302f414 + 3) & 0xbf;
      dtmf_digit_input_handler(3);
      p_vfo_freq_display_state->flags_0x10 = p_vfo_freq_display_state->flags_0x10 & 0xfe | 1;
      if (*_DAT_0302f418 != '\0') {
        return;
      }
      vfo_frequency_panel_render();
      return;
    }
    if (((*(byte *)(_DAT_0302f27c + 0x2d) & 4) != 0) || ((*(byte *)(_DAT_0302f298 + 0x15) & 4) != 0)
       ) {
      *(undefined2 *)(_DAT_0302f284 + 0x10) = 0;
      return;
    }
    if (*_DAT_0302f29c != '\0') {
      if (*_DAT_0302f29c == '\x01') {
        *(undefined2 *)(_DAT_0302f404 + 0x10) = 0;
        return;
      }
      dtmf_digit_input_handler(0);
      p_vfo_freq_display_state->field_0xe = 0;
      display_status_corner_clear_when_idle();
      bcd_pack_and_write_flash_block_0x41(*_DAT_0302f40c,*(byte *)(_DAT_0302f410 + 0x2d) >> 7);
      return;
    }
    uVar6 = *(short *)(_DAT_0302f284 + 0x10) + 1;
    *(ushort *)(_DAT_0302f284 + 0x10) = uVar6;
    if (uVar6 < (ushort)((ushort)*(byte *)(_DAT_0302f280 + 3) * 0x32)) {
      return;
    }
    *(undefined2 *)(_DAT_0302f284 + 0x10) = 0;
    dtmf_digit_input_handler(3);
    *(byte *)(_DAT_0302f280 + 0x10) = *(byte *)(_DAT_0302f280 + 0x10) & 0xfe | 1;
    vfo_frequency_panel_render();
    return;
  }
  bVar1 = *(char *)(_DAT_0302ef7c + 0x12) + 1;
  *(byte *)(_DAT_0302ef7c + 0x12) = bVar1;
  if (((*_DAT_0302ef68 & 0x20) != 0) && ((*(byte *)(_DAT_0302ef6c + 0x10) & 1) == 0)) {
    *(undefined1 *)(_DAT_0302ef7c + 0x12) = 0;
    dtmf_digit_input_handler(4);
    return;
  }
  if (bVar1 < 6) {
    return;
  }
  *(undefined1 *)(_DAT_0302f0e8 + 0x12) = 0;
  if (*(char *)(_DAT_0302f0ec + 0xc) != '\0') {
    dtmf_digit_input_handler(6);
    return;
  }
  *(byte *)(_DAT_0302f0f0 + 3) = *(byte *)(_DAT_0302f0f0 + 3) & 0xbf;
  iVar4 = _DAT_0302f280;
  iVar3 = _DAT_0302f0f8;
  if (((*(byte *)(_DAT_0302f0f4 + 0x2d) & 4) == 0) && ((*(byte *)(_DAT_0302f0ec + 0x15) & 4) == 0))
  {
    *(byte *)(_DAT_0302f280 + 0xf) = *(byte *)(_DAT_0302f280 + 0xf) & 0xdf;
    func_0x0302ed44(*(byte *)(iVar4 + 0x5d) & 1);
    *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) & 0xfe;
    return;
  }
  if ((*(byte *)(_DAT_0302f0f8 + 0x5c) < 2) && ((*(byte *)(_DAT_0302f0ec + 0x15) & 4) == 0)) {
    return;
  }
  if ((*(byte *)(_DAT_0302f0ec + 7) & 2) != 0) {
    return;
  }
  *(byte *)(_DAT_0302f0f8 + 0x10) = *(byte *)(_DAT_0302f0f8 + 0x10) & 0xfe | 1;
  bVar1 = *(byte *)(iVar3 + 4);
  if ((bVar1 == 0) || ((*(byte *)(_DAT_0302f0ec + 0x15) & 4) != 0)) {
    uVar2 = 0;
    *(byte *)(_DAT_0302f0f8 + 0xf) = *(byte *)(_DAT_0302f0f8 + 0xf) & 0xdf;
LAB_0302f078:
    if ((*(byte *)(_DAT_0302f0f8 + 0xf) & 0x20) != 0) {
LAB_0302f086:
      func_0x0302ed34(uVar2);
      if (*(char *)(_DAT_0302f0f8 + 1) != '\0') {
        *(byte *)(_DAT_0302f0f8 + 0xf) = *(byte *)(_DAT_0302f0f8 + 0xf) & 0xdf;
      }
      goto LAB_0302f138;
    }
    if ((*(byte *)(_DAT_0302f0ec + 0x15) & 4) != 0) {
      bVar1 = *(char *)(_DAT_0302f0f8 + 0xe) + 1;
      *(byte *)(_DAT_0302f0f8 + 0xe) = bVar1;
      if (10 < bVar1) {
        *(undefined1 *)(_DAT_0302f0f8 + 0xe) = 1;
      }
      bVar1 = *(byte *)(_DAT_0302f0f8 + 0xe);
      *(ushort *)(_DAT_0302f0f8 + 0x14) = (ushort)bVar1;
      iVar3 = _DAT_0302f0f4;
      *(byte *)(_DAT_0302f0f4 + 0x26) = bVar1;
      if ((*(byte *)(iVar3 + 0x2d) & 0x80) == 0) {
        *(byte *)(_DAT_0302f0f4 + 0x2a) = bVar1;
      }
      else {
        *(byte *)(_DAT_0302f27c + 0x2b) = bVar1;
      }
      ui_event_notify_alt(2);
      goto LAB_0302f138;
    }
  }
  else if ((*(byte *)(_DAT_0302f0f8 + 0xf) & 0x20) != 0) {
    if ((bVar1 & 0xf0) == 0) {
      if ((bVar1 & 0xf) != 0) {
        uVar2 = *(undefined2 *)(_DAT_0302f0f8 + 8);
        goto LAB_0302f086;
      }
    }
    else if ((bVar1 & 0xf) != 0) {
      if ((*(byte *)(_DAT_0302f0f8 + 0xf) & 0x10) == 0) {
        uVar2 = *(undefined2 *)(_DAT_0302f0f8 + 8);
        *(byte *)(_DAT_0302f0f8 + 0xf) = *(byte *)(_DAT_0302f0f8 + 0xf) & 0xef | 0x10;
      }
      else {
        uVar2 = *(undefined2 *)(_DAT_0302f0f8 + 10);
        *(byte *)(_DAT_0302f0f8 + 0xf) = *(byte *)(_DAT_0302f0f8 + 0xf) & 0xef;
      }
      goto LAB_0302f078;
    }
    uVar2 = *(undefined2 *)(_DAT_0302f0f8 + 10);
    goto LAB_0302f086;
  }
  iVar3 = _DAT_0302f280;
  func_0x0302ed34(*(undefined2 *)(_DAT_0302f280 + (*(byte *)(_DAT_0302f280 + 0xe) + 10) * 2 + 2));
  bVar1 = *(char *)(iVar3 + 0xe) + 1;
  *(byte *)(iVar3 + 0xe) = bVar1;
  if (*(byte *)(iVar3 + 1) <= bVar1) {
    *(undefined1 *)(iVar3 + 0xe) = 0;
  }
  *(byte *)(_DAT_0302f280 + 0xf) = *(byte *)(_DAT_0302f280 + 0xf) & 0xdf | 0x20;
LAB_0302f138:
  *(byte *)(_DAT_0302f280 + 0x10) = *(byte *)(_DAT_0302f280 + 0x10) & 0xfe;
  return;
}

