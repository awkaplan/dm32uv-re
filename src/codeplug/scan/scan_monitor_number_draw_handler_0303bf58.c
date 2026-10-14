/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_monitor_number_draw_handler @ 0303bf58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 268 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c84c) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_monitor_number_draw_handler(void)

{
  byte bVar1;
  char cVar2;
  
  display_clear_body_and_underline();
  bVar1 = p_radio_mode_state_0003e318->flags_0x5;
  if ((bVar1 & 8) == 0) {
    if ((p_radio_mode_state_0003e318->flags_0x6 & 0x10) == 0) {
      if ((bVar1 & 1) == 0) {
        if ((p_radio_mode_state_0003e318->flags_0x6 & 0x20) == 0) {
          if ((bVar1 & 0x20) == 0) {
            display_draw_number_centered
                      (1,0xffff,0,
                       **(uint **)(PTR_PTR_0303c1e0 +
                                  ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
          }
          else {
            display_draw_number_centered
                      (1,0xffff,0,
                       **(uint **)(PTR_PTR_0303c1dc +
                                  ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
          }
        }
        else {
          display_draw_number_centered
                    (1,0xffff,0,
                     *(uint *)(PTR_PTR_0303c1d8[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2]
                              + 0x2c));
        }
      }
      else {
        display_draw_number_centered
                  (1,0xffff,0,
                   *(uint *)(PTR_PTR_0303c1d8[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                            0x20));
      }
    }
    else {
      display_draw_number_centered
                (1,0xffff,0,
                 **(uint **)(PTR_PTR_0303c010 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4))
      ;
    }
  }
  else {
    display_draw_number_centered
              (1,0xffff,0,
               **(uint **)(PTR_PTR_0303c00c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
  }
  scan_channel_icon_draw(*(undefined1 *)PTR_DAT_0303c1e4);
  scan_monitor_display_refresh();
  cVar2 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar2 != '\b') && (cVar2 != '\x05')) && (cVar2 != '\x06')) &&
        ((cVar2 != '\x04' && (cVar2 != '\x18')))) &&
       ((cVar2 != '\x03' && ((cVar2 != '\n' && (cVar2 != '\x17')))))) && (cVar2 != '%')) &&
     ((cVar2 != '/' && ((cVar2 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  ucos_tmr_del(p_ucos_tmr_inputcursor,&stack0x00000020);
  return;
}

