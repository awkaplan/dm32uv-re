/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_display_refresh_and_notify @ 03062510 (file base 0x03000000; code starts at 0x03001000)
 * Size: 172 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_display_refresh_and_notify(void)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  undefined1 auStack_3c [52];
  
  iVar2 = get_current_mode_state2();
  if (iVar2 != 0) {
    set_flag_byte_03064328(4);
    vfo_load_side_config();
    settings_bitfield_remap_0x2d();
    puVar1 = PTR_DAT_0306263c;
    PTR_DAT_0306263c[0x1d] = 0;
    puVar1[0x1c] = 0;
    busy_wait_delay_loop_counted(auStack_3c);
    memcpy_ck803s(p_vfo_display_state,auStack_3c,0x33);
    set_flag_byte_03064328(3);
  }
  if (*(short *)((int)PTR_DAT_03062644 + 2) == 0) {
    if ((PTR_DAT_03062648[1] & 1) != (byte)p_dm32_settings_block04[0x2d] >> 7) {
      ui_event_notify_alt(0x13);
    }
  }
  else {
    ui_event_notify_alt(0x16);
  }
  bVar3 = p_vfo_display_state->flags_0x8 & 0xf0;
  if ((bVar3 == 0x10) || (bVar3 == 0x30)) {
    p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | 0x10;
    gps_nmea_gprmc_parser(*(byte *)PTR_DAT_03062644 >> 1 & 1,PTR_DAT_03062644[2]);
  }
  PTR_DAT_03062648[1] = PTR_DAT_03062648[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
  return;
}

