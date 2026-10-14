/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_gate_press_standby_action_dispatch @ 03039a3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 510 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_gate_press_standby_action_dispatch(void)

{
  byte bVar1;
  int iVar2;
  
  if (((*(byte *)p_call_active_flag & 8) == 0) ||
     (iVar2 = bitwise_not_of_boolean_result(), iVar2 == 0)) {
    if ((*(byte *)PTR_DAT_03039b20 & 2) == 0) {
      if ((PTR_DAT_03039b08[8] & 1) == 0) {
        if ((*PTR_DAT_03039b20 & 0x18000) == 0x8000) {
          if ((*(byte *)((int)PTR_DAT_03039b20 + 2) & 2) == 0) {
            rda5807m_fm_off();
          }
          else {
            *(byte *)((int)PTR_DAT_03039b20 + 2) = *(byte *)((int)PTR_DAT_03039b20 + 2) & 0xfd;
            rda5807m_fm_on();
          }
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03039b24),1);
        }
        else {
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03039b24),0);
          if ((*(byte *)((int)PTR_DAT_03039b20 + 3) & 2) == 0) {
            iVar2 = get_current_mode_state1();
            if (iVar2 == 0) {
              if ((*(byte *)(_LAB_03039c60 + 4) & 1) == 0) {
                vfo_ab_swap();
                tx_gate_write_call_record(1);
              }
              else {
                *(byte *)(_LAB_03039c60 + 4) = *(byte *)(_LAB_03039c60 + 4) & 0xfe;
                if ((*(byte *)(_LAB_03039c64 + 0x2e) & 1) == 0) {
                  if ((*(byte *)(_LAB_03039c64 + 0x2d) & 0x80) == 0) {
                    if ((*(byte *)(_LAB_03039c60 + 0x15) & 1) != 0) {
                      tx_gate_write_call_record(0);
                      return;
                    }
                    *(byte *)(_LAB_03039c64 + 0x2d) =
                         *(byte *)(_LAB_03039c64 + 0x2d) & 0xfe |
                         ~*(byte *)(_LAB_03039c64 + 0x2d) & 1;
                    settings_write_dispatcher(0xc);
                  }
                  else {
                    if ((*(byte *)(_LAB_03039c60 + 0x15) & 2) != 0) {
                      tx_gate_write_call_record(0);
                      return;
                    }
                    *(byte *)(_LAB_03039c64 + 0x2d) =
                         *(byte *)(_LAB_03039c64 + 0x2d) & 0xfd |
                         (byte)(((*(byte *)(_LAB_03039c64 + 0x2d) ^ 2) >> 1 & 1) << 1);
                    settings_write_dispatcher(0xc);
                  }
                  iVar2 = get_current_mode_state2();
                  if (iVar2 != 0) {
                    set_flag_byte_03064328(4);
                    iVar2 = _LAB_03039c68;
                    *(undefined1 *)(_LAB_03039c68 + 0x1d) = 0;
                    *(undefined1 *)(iVar2 + 0x1c) = 0;
                    set_flag_byte_03064328(3);
                  }
                  vfo_load_side_config();
                  settings_bitfield_remap_0x2d();
                  bVar1 = *(byte *)(_LAB_03039c64 + 0x2d) >> 7;
                  *(byte *)(_LAB_03039c6c + 1) = *(byte *)(_LAB_03039c6c + 1) & 0xfe | bVar1;
                  display_clear_channel_row_background(bVar1,0);
                  ui_event_notify(0x1a);
                  ui_event_notify_alt(1);
                }
                else {
                  tx_gate_write_call_record(0);
                }
              }
            }
            else {
              *(byte *)(_LAB_03039c60 + 4) = *(byte *)(_LAB_03039c60 + 4) & 0xfe;
              dtmf_inject_digits_2_0();
              ui_event_notify(0x19);
              *(byte *)(_LAB_03039c70 + 0x10) = *(byte *)(_LAB_03039c70 + 0x10) & 0x7f;
            }
          }
          else {
            radio_idle_state_reset(1);
          }
        }
      }
      else {
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)*(byte *)(_LAB_03039c74 + 2) + _LAB_03039c78),0);
      }
    }
    else {
      write_status_mode_byte_pair
                (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03039b24),0);
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03039b1c = 0x44;
    write_status_mode_byte_pair(0x70,1);
  }
  return;
}

