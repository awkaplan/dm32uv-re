/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_scroll_with_wraparound @ 030172e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 246 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_scroll_with_wraparound(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = *(byte *)PTR_DAT_030173f8;
  iVar2 = scan_entry_get_mode_bits(0x14);
  if (iVar2 == 0) {
    bVar4 = 1;
  }
  else {
    bVar4 = ~((bVar4 & 0x10) != 0);
  }
  iVar2 = call_state_not_idle_check();
  if (((iVar2 == 0) && (iVar2 = read_byte_field_0302e118(), iVar2 == 0)) &&
     (iVar2 = poll_condition_group(0x1b), iVar2 != 0)) {
    uVar3 = recording_count_scan();
    puVar1 = PTR_DAT_03017400;
    uVar3 = uVar3 & 0xffff;
    if (uVar3 == 0) {
      bVar4 = 1;
    }
    if ((*(char *)PTR_DAT_030173fc == '\0') && (bVar4 != 1)) {
      PTR_DAT_03017400[0x1d] = 0;
      puVar1[0x1c] = 0;
      iVar2 = get_current_mode_state2();
      if (iVar2 != 0) {
        set_flag_byte_03064328(4);
      }
      p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xf7 | 8
      ;
      iVar2 = PTR_DAT_03017408[5];
      if (iVar2 == 0) {
        PTR_DAT_03017408[5] = uVar3;
      }
      else {
        if (param_1 == '\0') {
          PTR_DAT_03017408[5] = iVar2 + -1;
        }
        else {
          PTR_DAT_03017408[5] = iVar2 + 1;
        }
        if (uVar3 < (uint)PTR_DAT_03017408[5]) {
          PTR_DAT_03017408[5] = 1;
        }
        else if (PTR_DAT_03017408[5] == 0) {
          PTR_DAT_03017408[5] = uVar3;
        }
      }
      if ((PTR_DAT_0301740c[1] & 0x80) != 0) {
        rda5807m_fm_off();
      }
      PTR_DAT_03017408[4] = PTR_DAT_03017408[5];
      recording_playback_to_speaker();
      p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xf7;
      if ((*(byte *)p_call_active_flag & 1) == 0) {
        write_field_and_mbox_post(1,100);
      }
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

