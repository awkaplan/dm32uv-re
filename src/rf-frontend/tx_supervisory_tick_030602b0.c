/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_supervisory_tick @ 030602b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 882 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_supervisory_tick(void)

{
  int iVar1;
  byte bVar2;
  
  if ((PTR_DAT_03060304[0x1d] & 4) == 0) {
    if ((*(byte *)PTR_DAT_03060850 & 0x20) != 0) {
      *(byte *)PTR_DAT_03060850 = *(byte *)PTR_DAT_03060850 & 0xdf;
      stage_hook_dispatch(4);
      gpio_interrupt_disable_bit(0x3b);
      menu_highlight_position_update(0,0);
      tx_abort_reset();
      *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
    }
  }
  else {
    iVar1 = get_current_mode_state1();
    if (iVar1 == 0) {
      if ((PTR_DAT_03060494[3] & 2) == 0) {
        if (*(char *)PTR_active_screen_subtype_03060498 == '/') {
          if ((PTR_DAT_0306048c[0x1d] & 2) != 0) {
            p_radio_mode_state_0003e318[2].flags_0x2 =
                 p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
          }
        }
        else {
          bVar2 = p_vfo_display_state->field_0x16 & 0x70;
          if ((p_vfo_display_state->field_0x16 & 0x70) == 0) {
            if ((PTR_DAT_0306048c[0x1d] & 2) == 0) {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
            }
            else {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
            }
          }
          else if (bVar2 == 0x10) {
            if ((PTR_DAT_030604a0[1] & 1) == 0) {
              bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 8;
            }
            else {
              bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0x10;
            }
            if (bVar2 == 0) {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
            }
            else {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
            }
          }
          else if (bVar2 == 0x20) {
            if ((PTR_DAT_0306048c[0x1d] & 2) == 0) {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
            }
            else {
              if ((PTR_DAT_030604a0[1] & 1) == 0) {
                bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 8;
              }
              else {
                bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0x10;
              }
              if (bVar2 == 0) {
                p_radio_mode_state_0003e318[2].flags_0x2 =
                     p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
              }
              else {
                p_radio_mode_state_0003e318[2].flags_0x2 =
                     p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
              }
            }
          }
          else if (bVar2 == 0x30) {
            if ((PTR_DAT_0306062c[0x1d] & 2) == 0) {
              if ((PTR_DAT_03060630[1] & 1) == 0) {
                bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 8;
              }
              else {
                bVar2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0x10;
              }
              if (bVar2 == 0) {
                p_radio_mode_state_0003e318[2].flags_0x2 =
                     p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
              }
              else {
                p_radio_mode_state_0003e318[2].flags_0x2 =
                     p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
              }
            }
            else {
              p_radio_mode_state_0003e318[2].flags_0x2 =
                   p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
            }
          }
          if ((PTR_DAT_0306062c[0x1d] & 1) != 0) {
            p_radio_mode_state_0003e318[2].flags_0x2 =
                 p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf;
          }
        }
      }
      else if ((PTR_DAT_0306048c[0x1d] & 2) != 0) {
        p_radio_mode_state_0003e318[2].flags_0x2 =
             p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
      }
    }
    else {
      if (((PTR_DAT_03060310[0x35] & 0xc) != 0) && ((p_dm32_settings_block04[0x2d] & 4) != 0)) {
        bVar2 = p_vfo_freq_display_state->field_0x2 & 0xf;
        if ((p_vfo_freq_display_state->field_0x2 & 0xf) == 0) {
          PTR_DAT_03060304[0x1d] = PTR_DAT_03060304[0x1d] & 0xfd | 2;
        }
        else if (bVar2 == 1) {
          if ((p_vfo_freq_display_state->field_0xf & 0x20) == 0) {
            PTR_DAT_0306048c[0x1d] = PTR_DAT_0306048c[0x1d] & 0xfd | 2;
          }
        }
        else if ((bVar2 == 2) && ((p_vfo_freq_display_state->field_0xf & 0x20) != 0)) {
          PTR_DAT_0306048c[0x1d] = PTR_DAT_0306048c[0x1d] & 0xfd | 2;
        }
      }
      if ((PTR_DAT_0306048c[0x1d] & 2) != 0) {
        p_radio_mode_state_0003e318[2].flags_0x2 =
             p_radio_mode_state_0003e318[2].flags_0x2 & 0xbf | 0x40;
      }
    }
    if ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x40) == 0) {
      tx_abort_reset();
    }
    else {
      *(undefined1 *)PTR_DAT_03060634 = 0;
      if ((*PTR_DAT_03060638 & 0x18000) == 0x8000) {
        if (((p_vfo_display_state->flags_0x8 & 0xf0) == 0) && ((*(byte *)PTR_DAT_03060640 & 8) != 0)
           ) {
          tx_abort_on_condition();
          write_field_and_mbox_post(1,100);
        }
      }
      else if ((*(char *)PTR_DAT_03060644 == 'M') && ((p_state_0003ff3c->field_0x2 & 2) == 0)) {
        write_field_and_mbox_post(1,100);
      }
      if ((*(byte *)((int)PTR_DAT_03060638 + 3) & 0x80) != 0) {
        *(byte *)((int)PTR_DAT_03060638 + 3) = *(byte *)((int)PTR_DAT_03060638 + 3) & 0x7f;
        display_draw_number_centered
                  (0xa0,0xffff,0,PTR_PTR_03060650[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
      }
      if ((*(byte *)((int)PTR_DAT_03060638 + 3) & 2) == 0) {
        ptt_preamble_end_ui_audio_setup_1();
      }
      else if ((*(byte *)((int)PTR_DAT_03060638 + 3) & 4) == 0) {
        ctcss_or_dcs_code_display(*(undefined2 *)&p_vfo_display_state->field_0x11_0);
      }
    }
  }
  return;
}

