/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_inactivity_timeout_tick @ 0301cc68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1088 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_inactivity_timeout_tick(void)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_40 [52];
  
  puVar4 = PTR_DAT_0301cdc4;
  if (((*(byte *)PTR_call_active_flag_0301cdbc & 10) == 0) &&
     ((*(byte *)PTR_DAT_0301cdc0 & 0x10) == 0)) {
    if (((PTR_DAT_0301cdc8[8] & 1) == 0) &&
       ((iVar6 = keypad_dispatch_not_inhibited(), iVar6 != 0 &&
        ((*(byte *)PTR_DAT_0301cdcc & 0x40) == 0)))) {
      cVar1 = *(char *)((int)PTR_DAT_0301cdc4 + 2);
      if ((cVar1 != '\0') && (*(char *)((int)PTR_DAT_0301cdc4 + 2) = cVar1 + -1, cVar1 == '\x01')) {
        PTR_DAT_0301cdd0[0xb] = PTR_DAT_0301cdd0[0xb] & 0xfc;
      }
      if ((*(char *)PTR_DAT_0301cdc4 != '\0') || (*(char *)((int)PTR_DAT_0301cdc4 + 1) != '\0')) {
        event_queue_reset();
        *(byte *)(PTR_DAT_0301cdcc + 1) = *(byte *)(PTR_DAT_0301cdcc + 1) & 0xf7 | 8;
        cVar1 = PTR_DAT_0301cdd4[1];
        if (((cVar1 == '\x01') || ((cVar1 == '\x04' || (cVar1 == '\x02')))) &&
           ((PTR_DAT_0301cdd8[0x30] & 4) != 0)) {
          tx_gate_write_call_record(0);
          dialog_history_menu_step_and_refresh();
          puVar4 = PTR_DAT_0301cdc4;
          *(undefined1 *)PTR_DAT_0301cdc4 = 0;
          *(undefined1 *)((int)puVar4 + 1) = 0;
        }
        else {
          uVar7 = get_current_mode_state1();
          if ((uVar7 < 3) || ((PTR_DAT_0301cdd8[0x2d] & 4) != 0)) {
            if ((PTR_DAT_0301cde0[1] & 3) == 0) {
              if (PTR_DAT_0301cde4[7] == '\x04') {
                bVar2 = true;
              }
              else {
                bVar2 = 0x3f < *(byte *)PTR_DAT_0301cde8;
              }
            }
            else {
              bVar2 = true;
            }
            if ((*(char *)PTR_DAT_0301cf4c == '\0') || (bVar2)) {
              iVar6 = get_current_mode_state1();
              if ((iVar6 == 0) && (iVar6 = get_current_mode_state2(), iVar6 != 0)) {
                set_flag_byte_03064328(4);
                vfo_load_side_config();
                settings_bitfield_remap_0x2d();
                puVar5 = PTR_DAT_0301cf50;
                PTR_DAT_0301cf50[0x1d] = 0;
                puVar5[0x1c] = 0;
                set_flag_byte_03064328(3);
              }
              puVar5 = PTR_DAT_0301cf60;
              if ((*(uint *)PTR_DAT_0301cf54 & 0x18000) == 0x8000) {
                if (*(char *)PTR_DAT_0301cf58 == '\0') {
                  settings_value_step_by_ten_clamped_write(0);
                }
                else {
                  settings_value_step_by_ten_clamped_write(1);
                }
                puVar4 = PTR_DAT_0301cf58;
                *(undefined1 *)PTR_DAT_0301cf58 = 0;
                *(undefined1 *)((int)puVar4 + 1) = 0;
                PTR_DAT_0301cf54[2] = PTR_DAT_0301cf54[2] & 0xfd;
                rda5807m_tune(*(undefined2 *)PTR_DAT_0301cf5c);
                battery_value_display_format((uint)~(int)(char)PTR_DAT_0301cf60[0x2d] >> 0x1f);
              }
              else {
                if ((PTR_DAT_0301cf64[0x15] & 4) == 0) {
                  if ((PTR_DAT_0301cf60[0x2d] & 4) == 0) {
                    iVar6 = is_memory_channel_not_vfo();
                    puVar5 = PTR_DAT_0301d0e0;
                    if (iVar6 == 1) {
                      vfo_record_read(auStack_40,(byte)PTR_DAT_0301d0e0[0x2d] >> 7);
                      memcpy_ck803s(PTR_DAT_0301d0f0,auStack_40,0x33);
                      if ((puVar5[0x2d] & 0x80) == 0) {
                        *(byte *)PTR_DAT_0301d0f4 = *(byte *)PTR_DAT_0301d0f4 & 0xf7;
                      }
                      else {
                        *(byte *)PTR_DAT_0301d0f4 = *(byte *)PTR_DAT_0301d0f4 & 0xef;
                      }
                    }
                    if ((PTR_DAT_0301d0f8[1] & 1) == (byte)PTR_DAT_0301d0e0[0x2d] >> 7) {
                      if ((PTR_DAT_0301d0fc[0x10] & 0x40) == 0) {
                        if ((PTR_DAT_0301d0fc[0x10] & 0x80) != 0) {
                          PTR_DAT_0301d0fc[0x10] = PTR_DAT_0301d0fc[0x10] & 0x7f;
                          if (PTR_DAT_0301d104[1] != 0) {
                            ui_event_notify_alt(0x17);
                          }
                        }
                      }
                      else {
                        PTR_DAT_0301d0fc[0x10] = PTR_DAT_0301d0fc[0x10] & 0xbf;
                        if (PTR_DAT_0301d100[1] != 0) {
                          ui_event_notify_alt(0x15);
                        }
                      }
                    }
                    else {
                      ui_event_notify_alt(0x13);
                    }
                    if (*(char *)PTR_DAT_0301d0e4 == '\0') {
                      channel_freq_step_adjust_b();
                      *(char *)((int)PTR_DAT_0301d0e4 + 1) =
                           *(char *)((int)PTR_DAT_0301d0e4 + 1) + -1;
                    }
                    else {
                      channel_freq_step_adjust_a();
                      *(char *)PTR_DAT_0301d0e4 = *(char *)PTR_DAT_0301d0e4 + -1;
                    }
                    if (*(byte *)PTR_DAT_0301d108 < 200) {
                      tx_gate_write_call_record(1);
                    }
                    bcd_pack_and_write_flash_block_0x41
                              (*PTR_DAT_0301d0f0,(byte)PTR_DAT_0301d0e0[0x2d] >> 7);
                  }
                  else {
                    cVar1 = *(char *)PTR_DAT_0301cf58;
                    if (cVar1 == '\0') {
                      if ((byte)PTR_DAT_0301cf60[0x26] < 2) {
                        PTR_DAT_0301d0e0[0x26] = PTR_DAT_0301d0e0[0x2c];
                      }
                      else {
                        PTR_DAT_0301cf60[0x26] = PTR_DAT_0301cf60[0x26] - 1;
                      }
                      *(char *)((int)PTR_DAT_0301d0e4 + 1) =
                           *(char *)((int)PTR_DAT_0301d0e4 + 1) + -1;
                    }
                    else {
                      cVar3 = PTR_DAT_0301cf60[0x26];
                      PTR_DAT_0301cf60[0x26] = cVar3 + 1U;
                      if ((byte)puVar5[0x2c] < (byte)(cVar3 + 1U)) {
                        PTR_DAT_0301cf60[0x26] = 1;
                      }
                      *(char *)PTR_DAT_0301cf58 = cVar1 + -1;
                    }
                    settings_write_dispatcher(0x2b,PTR_DAT_0301d0e0[0x26]);
                    PTR_DAT_0301d0e8[4] = PTR_DAT_0301d0e8[4] & 0x7f | 0x80;
                    *(undefined1 *)PTR_DAT_0301d0ec = 0;
                  }
                }
                else {
                  if (*(char *)PTR_DAT_0301cf58 == '\0') {
                    if ((byte)PTR_DAT_0301cf60[0x26] < 2) {
                      PTR_DAT_0301cf60[0x26] = 10;
                    }
                    else {
                      PTR_DAT_0301cf60[0x26] = PTR_DAT_0301cf60[0x26] - 1;
                    }
                  }
                  else {
                    cVar1 = PTR_DAT_0301cf60[0x26];
                    PTR_DAT_0301cf60[0x26] = cVar1 + 1U;
                    if (10 < (byte)(cVar1 + 1U)) {
                      PTR_DAT_0301cf60[0x26] = 1;
                    }
                  }
                  puVar4 = PTR_DAT_0301cf58;
                  *(undefined1 *)PTR_DAT_0301cf58 = 0;
                  *(undefined1 *)((int)puVar4 + 1) = 0;
                  settings_write_dispatcher(0x2c,PTR_DAT_0301cf60[0x26]);
                  PTR_DAT_0301cf54[4] = PTR_DAT_0301cf54[4] & 0x7f | 0x80;
                  *(undefined1 *)PTR_DAT_0301cf68 = 0;
                }
                PTR_DAT_0301d0f8[1] = PTR_DAT_0301d0f8[1] & 0xfe | (byte)PTR_DAT_0301d0e0[0x2d] >> 7
                ;
                request_display_refresh(2);
              }
            }
            else if (*(char *)PTR_DAT_0301d0e4 == '\0') {
              if (PTR_DAT_0301d164[1] != '\0') {
                PTR_DAT_0301d164[1] = 0;
                write_field_and_mbox_post(2,1);
              }
            }
            else {
              *(undefined1 *)PTR_DAT_0301d0e4 = 0;
              write_field_and_mbox_post(2,2);
            }
          }
          else {
            if (*(char *)PTR_DAT_0301cdc4 == '\0') {
              PTR_DAT_0301cddc[0x5d] = PTR_DAT_0301cddc[0x5d] & 0xfe;
            }
            else {
              PTR_DAT_0301cddc[0x5d] = PTR_DAT_0301cddc[0x5d] & 0xfe | 1;
            }
            iVar6 = get_current_mode_state1();
            if (iVar6 == 6) {
              dtmf_digit_input_handler(3);
              vfo_frequency_panel_render();
              PTR_DAT_0301cddc[0x10] = PTR_DAT_0301cddc[0x10] & 0xfe | 1;
            }
            puVar4 = PTR_DAT_0301cdc4;
            *(undefined1 *)PTR_DAT_0301cdc4 = 0;
            *(undefined1 *)((int)puVar4 + 1) = 0;
          }
        }
      }
    }
  }
  else {
    *(undefined1 *)PTR_DAT_0301cdc4 = 0;
    *(undefined1 *)((int)puVar4 + 1) = 0;
  }
  return;
}

