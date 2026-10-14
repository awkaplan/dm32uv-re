/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_write_dispatcher @ 0304b088 (file base 0x03000000; code starts at 0x03001000)
 * Size: 4602 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 settings_write_dispatcher(int param_1__w,int param_2__w)

{
  char param_1 = (char)param_1__w;
  byte param_2 = (byte)param_2__w;
  dm32_settings_block04 *pdVar1;
  radio_mode_state_0003e318 *prVar2;
  dm32_settings_block04 *pdVar3;
  undefined4 *puVar4;
  dm32_settings_block04 *pdVar5;
  dm32_settings_block04 *pdVar6;
  uint uVar7;
  byte local_18 [4];
  byte local_14;
  undefined1 uStack_13;
  byte bStack_12;
  byte bStack_11;
  byte local_e;
  byte local_d;
  
  pdVar6 = p_dm32_settings_block04;
  pdVar5 = p_dm32_settings_block04;
  pdVar3 = p_dm32_settings_block04;
  pdVar1 = p_dm32_settings_block04;
  local_e = 0;
  local_18[0] = param_2;
  if (param_1 == 'A') {
    p_dm32_settings_block04->callsign_colour = param_2;
    flash_field_write_cached(4,0);
    return 1;
  }
  if (param_1 == '\x10') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x80;
    }
    else {
      local_d = local_d & 0x7f;
    }
    p_dm32_settings_block04->field_0x41 = local_18[0];
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x11') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x40;
    }
    else {
      local_d = local_d & 0xbf;
    }
    p_dm32_settings_block04->field_0x42 = local_18[0];
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x12') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x20;
    }
    else {
      local_d = local_d & 0xdf;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xfe | local_18[0] & 1;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x13') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x10;
    }
    else {
      local_d = local_d & 0xef;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xfd | (local_18[0] & 1) << 1;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x14') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 8;
    }
    else {
      local_d = local_d & 0xf7;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xfb | (local_18[0] & 1) << 2;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x15') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 4;
    }
    else {
      local_d = local_d & 0xfb;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xf7 | (local_18[0] & 1) << 3;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x16') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 2;
    }
    else {
      local_d = local_d & 0xfd;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xef | (local_18[0] & 1) << 4;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x18') {
    flash_field_read_cached(4,0x20,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 1;
    }
    else {
      local_d = local_d & 0xfe;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xbf | (local_18[0] & 1) << 6;
    flash_field_write_cached(4,0x20,local_d);
    return 1;
  }
  if (param_1 == '\x17') {
    flash_field_read_cached(4,0x21,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x80;
    }
    else {
      local_d = local_d & 0x7f;
    }
    p_dm32_settings_block04->field_0x43 =
         p_dm32_settings_block04->field_0x43 & 0xdf | (local_18[0] & 1) << 5;
    flash_field_write_cached(4,0x21,local_d);
    return 1;
  }
  if (param_1 == '\x1a') {
    flash_field_read_cached(4,0x21,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x40;
    }
    else {
      local_d = local_d & 0xbf;
    }
    p_dm32_settings_block04->field_0x44 =
         p_dm32_settings_block04->field_0x44 & 0xfe | local_18[0] & 1;
    flash_field_write_cached(4,0x21,local_d);
    return 1;
  }
  if (param_1 == '*') {
    flash_field_read_cached(4,0x21,&local_d,1);
    local_d = (byte)((local_18[0] & 0xf) << 4) | local_d & 0xc0;
    p_dm32_settings_block04->field_0x44 =
         p_dm32_settings_block04->field_0x44 & 0xf3 | (byte)((local_18[0] & 3) << 2);
    flash_field_write_cached(4,0x21);
    return 1;
  }
  if (param_1 == '1') {
    p_dm32_settings_block04->field_0x55 = param_2;
    *(byte *)PTR_DAT_0304b458 = param_2;
    flash_field_write_cached(4,0x30);
    return 1;
  }
  if (param_1 == '-') {
    p_dm32_settings_block04->zone_a_colour = param_2;
    flash_field_write_cached(4,0x31);
    return 1;
  }
  if (param_1 == 'V') {
    p_dm32_settings_block04->field_0x31 =
         p_dm32_settings_block04->field_0x31 & 0xf7 | (param_2 & 1) << 3;
    flash_field_read_cached(4,0x33,&local_e,1);
    if ((pdVar1->field_0x31 & 8) == 0) {
      local_e = local_e & 0xfe;
    }
    else {
      local_e = local_e | 1;
    }
    flash_field_write_cached(4,0x33,local_e);
    return 1;
  }
  if (param_1 == '>') {
    flash_field_read_cached(4,0x40,&local_d,1);
    local_d = local_d & 0xfe;
    if (local_18[0] == 1) {
      local_d = local_d | 1;
    }
    flash_field_write_cached(4,0x40,local_d);
    return 1;
  }
  if (param_1 == '@') {
    flash_field_read_cached(4,0x40,&local_d,1);
    local_d = local_d & 0xbf;
    if (local_18[0] == 1) {
      local_d = local_d | 0x40;
    }
    PTR_DAT_0304b650[0xd8] = PTR_DAT_0304b650[0xd8] & 0xbf | (local_18[0] & 1) << 6;
    flash_field_write_cached(4,0x40,local_d);
    return 1;
  }
  if (param_1 == '?') {
    PTR_DAT_0304b650[0xb6] = param_2;
    flash_field_write_cached(4,0x41);
    return 1;
  }
  if (param_1 == '\t') {
    flash_field_read_cached(4,0x60,&local_d,1);
    pdVar1 = p_dm32_settings_block04;
    if (local_18[0] == 1) {
      local_d = local_d | 1;
    }
    else {
      local_d = local_d & 0xfe;
    }
    p_dm32_settings_block04->field_0x32 =
         p_dm32_settings_block04->field_0x32 & 0xf7 | (local_18[0] & 1) << 3;
    flash_field_write_cached(4,0x60,local_d);
    write_two_bit_flags_0301eef8(pdVar1->field_0x32 >> 4 & 1,pdVar1->field_0x32 >> 3 & 1);
    return 1;
  }
  if (param_1 == '\n') {
    flash_field_read_cached(4,0x60,&local_d,1);
    pdVar1 = p_dm32_settings_block04;
    if (local_18[0] == 1) {
      local_d = local_d | 2;
    }
    else {
      local_d = local_d & 0xfd;
    }
    p_dm32_settings_block04->field_0x32 =
         p_dm32_settings_block04->field_0x32 & 0xef | (local_18[0] & 1) << 4;
    flash_field_write_cached(4,0x60,local_d);
    write_two_bit_flags_0301eef8(pdVar1->field_0x32 >> 4 & 1,pdVar1->field_0x32 >> 3 & 1);
    return 1;
  }
  if (param_1 == 'E') {
    if (param_2 == 0) {
      p_radio_mode_state_0003e318[1].flags_0x5 = 0;
    }
    else if (param_2 == 1) {
      p_radio_mode_state_0003e318[1].flags_0x5 = 1;
    }
    else {
      p_radio_mode_state_0003e318[1].flags_0x5 = 2;
    }
    prVar2 = p_radio_mode_state_0003e318;
    write_single_byte_0301ea5c(p_radio_mode_state_0003e318[1].flags_0x5);
    flash_field_read_cached(4,0x65,&local_d,1);
    local_d = local_d & 0xf9 | prVar2[1].flags_0x5 * '\x02';
    flash_field_write_cached(4,0x65);
    return 1;
  }
  if (param_1 == '\f') {
    flash_field_read_cached(4,0x80,&local_d,1);
    if (local_18[0] == 1) {
      if ((p_dm32_settings_block04->field_0x2d & 0x80) == 0) {
        local_d = local_d | 2;
      }
      else {
        local_d = local_d | 4;
      }
    }
    else if ((p_dm32_settings_block04->field_0x2d & 0x80) == 0) {
      local_d = local_d & 0xfd;
    }
    else {
      local_d = local_d & 0xfb;
    }
    flash_field_write_cached(4,0x80,local_d);
    return 1;
  }
  if (param_1 == 'C') {
    if ((p_dm32_settings_block04->field_0x2d & 0x80) == 0) {
      p_dm32_settings_block04->field_0x2d =
           p_dm32_settings_block04->field_0x2d & 0xf7 | (param_2 & 1) << 3;
    }
    else {
      p_dm32_settings_block04->field_0x2d =
           p_dm32_settings_block04->field_0x2d & 0xef | (param_2 & 1) << 4;
    }
    p_dm32_settings_block04->field_0x2d =
         p_dm32_settings_block04->field_0x2d & 0xdf | (param_2 & 1) << 5;
    flash_field_read_cached(4,0x80,&local_d,1);
    if (local_18[0] == 1) {
      if ((p_dm32_settings_block04->field_0x2d & 0x80) == 0) {
        local_d = local_d | 8;
      }
      else {
        local_d = local_d | 0x10;
      }
    }
    else if ((p_dm32_settings_block04->field_0x2d & 0x80) == 0) {
      local_d = local_d & 0xf7;
    }
    else {
      local_d = local_d & 0xef;
    }
    flash_field_write_cached(4,0x80,local_d);
    return 1;
  }
  if (param_1 == '\r') {
    flash_field_read_cached(4,0x80,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 0x20;
    }
    else {
      local_d = local_d & 0xdf;
    }
    p_dm32_settings_block04->field_0x2d =
         p_dm32_settings_block04->field_0x2d & 0x7f | local_18[0] << 7;
    flash_field_write_cached(4,0x80,local_d);
    return 1;
  }
  if (param_1 == '\x0f') {
    flash_field_read_cached(4,0x85,&local_d,1);
    if (local_18[0] == 1) {
      local_d = local_d | 1;
    }
    else {
      local_d = local_d & 0xfe;
    }
    p_dm32_settings_block04->field_0x30 =
         p_dm32_settings_block04->field_0x30 & 0xfd | (local_18[0] & 1) << 1;
    flash_field_write_cached(4,0x85,local_d);
    return 1;
  }
  if (param_1 == '.') {
    p_dm32_settings_block04->field_0x57 = param_2 - 5;
    flash_field_write_cached(4,0x86);
    return 1;
  }
  if (param_1 != 'G') {
    if (param_1 != 'L') {
      if (param_1 != 'H') {
        if (param_1 != 'M') {
          if (param_1 != 'I') {
            if (param_1 != 'N') {
              if (param_1 != 'J') {
                if (param_1 != 'O') {
                  if (param_1 != 'K') {
                    if (param_1 != 'P') {
                      if (param_1 == 'Q') {
                        p_dm32_settings_block04->field_0x5c = param_2;
                        flash_field_write_cached(4,0x93);
                        puVar4 = p_ucos_tmr_tmrkey;
                        uVar7 = (uint)(byte)pdVar3->field_0x5c * 5 & 0xff;
                        p_ucos_tmr_tmrkey[8] = uVar7;
                        puVar4[9] = uVar7;
                        return 1;
                      }
                      if (param_1 == '\x03') {
                        p_dm32_settings_block04->standby_text_colour = param_2;
                        flash_field_write_cached(4,0xa0);
                        apply_flags_from_flash_0x65_0x66();
                        return 1;
                      }
                      if (param_1 == ':') {
                        p_dm32_settings_block04->field_0x5e = param_2;
                        flash_field_write_cached(4,0xa2);
                        return 1;
                      }
                      if (param_1 == '\b') {
                        flash_field_read_cached(4,0xa4,&local_d,1);
                        if (local_18[0] == 1) {
                          local_d = local_d | 1;
                        }
                        else {
                          local_d = local_d & 0xfe;
                        }
                        p_dm32_settings_block04->field_0x32 =
                             p_dm32_settings_block04->field_0x32 & 0xfb | (local_18[0] & 1) << 2;
                        flash_field_write_cached(4,0xa4,local_d);
                        return 1;
                      }
                      if (param_1 == '\a') {
                        flash_field_read_cached(4,0xa4,&local_d,1);
                        if (local_18[0] == 0) {
                          local_d = local_d & 0xfd;
                        }
                        else {
                          local_d = local_d | 2;
                        }
                        p_dm32_settings_block04->field_0x30 =
                             p_dm32_settings_block04->field_0x30 & 0xbf | (local_18[0] & 1) << 6;
                        if (((local_18[0] & 1) != 0) && (*(char *)PTR_DAT_0304bf44 == '\0')) {
                          *(undefined1 *)PTR_DAT_0304bf44 = 1;
                        }
                        flash_field_write_cached(4,0xa4,local_d);
                        return 1;
                      }
                      if (param_1 == 'Z') {
                        *(ushort *)&p_dm32_settings_block04->field_0x30 =
                             *(ushort *)&p_dm32_settings_block04->field_0x30 & 0xfc7f |
                             (param_2 & 7) << 7;
                        flash_field_read_cached(4,0xa4,&local_e,1);
                        local_e = local_18[0] << 4 | local_e & 0xf;
                        flash_field_write_cached(4,0xa4);
                        return 1;
                      }
                      if (param_1 == '_') {
                        p_dm32_settings_block04->field_0x6e = param_2;
                        map_index_to_16bit_value();
                        flash_field_write_cached(4,0x1e,local_18[0]);
                        return 1;
                      }
                      if (param_1 == '\x04') {
                        if (param_2 != 0) {
                          if (param_2 == 1) {
                            local_e = 1;
                          }
                          else {
                            local_e = 2;
                          }
                        }
                        p_vfo_display_state->flags_0x8 =
                             p_vfo_display_state->flags_0x8 & 0xf9 | local_e << 1;
                        p_dm32_settings_block04->field_0x38 = param_2;
                        vfo_field_write_2bit_at_8_direct_commit();
                        freq_calibration_apply_all();
                        return 1;
                      }
                      if (param_1 == 'B') {
                        p_vfo_display_state->field_0x19 =
                             p_vfo_display_state->field_0x19 & 0xf | param_2 << 4;
                        p_dm32_settings_block04->field_0x2f = param_2;
                        vfo_record_offset_select2();
                        return 1;
                      }
                      if (param_1 == '3') {
                        vfo_field_write_nibble_low_at_0xd(param_2);
                        return 1;
                      }
                      if (param_1 == '2') {
                        p_vfo_display_state->flags_0x9 =
                             p_vfo_display_state->flags_0x9 & 0xc0 | param_2 & 0x3f;
                        channel_field_write_6bit_at_9();
                        return 1;
                      }
                      if (param_1 == '\x06') {
                        if (p_dm32_settings_block04->field_0x29 != param_2) {
                          p_dm32_settings_block04->field_0x29 = param_2;
                          local_14 = param_2;
                          if ((pdVar5->field_0x2d & 0x80) == 0) {
                            flash_block_write(0x5c,5,&local_14,1);
                            pdVar1 = p_dm32_settings_block04;
                            p_dm32_settings_block04->field_0x27 = 1;
                            local_14 = 1;
                            uStack_13 = 0;
                            flash_block_write(0x5c,1,&local_14,2);
                            pdVar1->power_on_interface = pdVar1->field_0x29;
                          }
                          else {
                            flash_block_write(0x5c,7,&local_14,1);
                            pdVar1 = p_dm32_settings_block04;
                            p_dm32_settings_block04->field_0x28 = 1;
                            local_14 = 1;
                            uStack_13 = 0;
                            flash_block_write(0x5c,3,&local_14,2);
                            pdVar1->field_0x13 = pdVar1->field_0x29;
                          }
                          pdVar1 = p_dm32_settings_block04;
                          p_dm32_settings_block04->field_0x26 = 1;
                          contact_record_copy_with_limit((byte)pdVar1->field_0x2d >> 7);
                          return 1;
                        }
                        OSTimeDly_ms_wrapper(200);
                        return 1;
                      }
                      if (param_1 == '+') {
                        p_dm32_settings_block04->field_0x26 = param_2;
                        if ((pdVar6->field_0x2d & 0x80) == 0) {
                          p_dm32_settings_block04->field_0x27 = param_2;
                        }
                        else {
                          p_dm32_settings_block04->field_0x28 = param_2;
                        }
                        local_14 = p_dm32_settings_block04->field_0x27;
                        uStack_13 = 0;
                        bStack_12 = p_dm32_settings_block04->field_0x28;
                        bStack_11 = 0;
                        flash_block_write(0x5c,1,&local_14,4);
                        return 1;
                      }
                      if (param_1 == ',') {
                        p_dm32_settings_block04->field_0x26 = param_2;
                        if ((pdVar6->field_0x2d & 0x80) == 0) {
                          p_dm32_settings_block04->field_0x2a = param_2;
                        }
                        else {
                          p_dm32_settings_block04->field_0x2b = param_2;
                        }
                        local_14 = p_dm32_settings_block04->field_0x2a;
                        uStack_13 = p_dm32_settings_block04->field_0x2b;
                        flash_block_write(4,0xa8,&local_14,2);
                        return 1;
                      }
                      if (param_1 == '\x05') {
                        p_dm32_settings_block04->field_0x3d = param_2;
                        modem_set_digital_mode_enable();
                        vfo_field_write_bit4_at_0xd(local_18[0]);
                        return 1;
                      }
                      if (param_1 == 'D') {
                        vfo_field_write_nibble_high(param_2);
                        return 1;
                      }
                      if (param_1 == 'F') {
                        vfo_field_write_bit5_at_0xd(param_2);
                        return 1;
                      }
                      if (param_1 == 'R') {
                        local_14 = *(byte *)((int)PTR_DAT_0304c2b4 + 2);
                        uStack_13 = *(undefined1 *)((int)PTR_DAT_0304c2b4 + 3);
                        bStack_12 = *(byte *)PTR_DAT_0304c2b4 >> 4 |
                                    *(byte *)((int)PTR_DAT_0304c2b4 + 1) << 4;
                        bStack_11 = *(byte *)((int)PTR_DAT_0304c2b4 + 1) >> 4;
                        flash_block_write(0x11,0xe01,&local_14,4);
                        return 1;
                      }
                      if (param_1 == 'S') {
                        local_14 = *(byte *)((int)PTR_DAT_0304c2b8 + 2);
                        uStack_13 = *(undefined1 *)((int)PTR_DAT_0304c2b8 + 3);
                        bStack_12 = *(byte *)PTR_DAT_0304c2b8 >> 4 |
                                    *(byte *)((int)PTR_DAT_0304c2b8 + 1) << 4;
                        bStack_11 = *(byte *)((int)PTR_DAT_0304c2b8 + 1) >> 4;
                        flash_block_write(0x11,0xe05,&local_14,4);
                        return 1;
                      }
                      if (param_1 == 'W') {
                        *(byte *)PTR_DAT_0304c2bc = param_2;
                        flash_block_write(0x11,0xe00,local_18,1);
                        return 1;
                      }
                      if (param_1 == 'T') {
                        p_dm32_settings_block04->field_0x6b = param_2 & 0xf;
                        modem_buffer_indexed_byte_write_0301e5d8();
                        flash_block_write(4,0xa7,local_18,1);
                        return 1;
                      }
                      if (param_1 == 'U') {
                        p_dm32_settings_block04->field_0x6a = param_2;
                        config_table_entry_0x7d_indexed();
                        flash_block_write(4,0xa6,local_18,1);
                        return 1;
                      }
                      if (param_1 == '=') {
                        return 1;
                      }
                      if (param_1 == 'X') {
                        vfo_field_write_2bit_at_0xc(param_2);
                        *(byte *)PTR_DAT_0304c43c =
                             *(byte *)PTR_DAT_0304c43c & 0xfe | local_18[0] & 1;
                        return 1;
                      }
                      if (param_1 == 'Y') {
                        flash_field_write_cached(4,0x301,param_2);
                        PTR_DAT_0304c43c[2] = (ushort)local_18[0] * 0x1e;
                        return 1;
                      }
                      return 0;
                    }
                    uVar7 = (uint)param_2;
                    if (uVar7 < 0x2b) {
                      if (uVar7 == 0x1e) {
                        *(byte *)PTR_DAT_0304bf3c = *(byte *)PTR_DAT_0304bf3c & 0xfe | 1;
                      }
                      else {
                        *(byte *)PTR_DAT_0304bf3c = *(byte *)PTR_DAT_0304bf3c & 0xfe;
                        if (uVar7 == 0x26) {
                          *(byte *)PTR_DAT_0304bf2c = *(byte *)PTR_DAT_0304bf2c & 0xfe | 1;
                          goto LAB_0304bde8;
                        }
                      }
                    }
                    else {
                      local_18[0] = 0;
                      uVar7 = 0;
                      *(byte *)PTR_DAT_0304bf3c = *(byte *)PTR_DAT_0304bf3c & 0xfe;
                    }
                    *(byte *)PTR_DAT_0304bf2c = *(byte *)PTR_DAT_0304bf2c & 0xfe;
LAB_0304bde8:
                    p_dm32_settings_block04->field_0x7b = (char)uVar7;
                    PTR_DAT_0304bf38[2] = PTR_DAT_0304bf34[uVar7];
                    flash_field_write_cached(4,0x8c);
                    return 1;
                  }
                  uVar7 = (uint)param_2;
                  if (uVar7 < 0x2b) {
                    if (uVar7 == 0x1e) {
                      *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xfe | 1;
                    }
                    else {
                      *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xfe;
                      if (uVar7 == 0x26) {
                        *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xfe | 1;
                        goto LAB_0304bd68;
                      }
                    }
                  }
                  else {
                    local_18[0] = 0;
                    uVar7 = 0;
                    *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xfe;
                  }
                  *(byte *)PTR_DAT_0304bf2c = *(byte *)PTR_DAT_0304bf2c & 0xfe;
LAB_0304bd68:
                  p_dm32_settings_block04->field_0x75 = (char)uVar7;
                  PTR_DAT_0304bf38[7] = PTR_DAT_0304bf34[uVar7];
                  flash_field_write_cached(4,0x8b);
                  return 1;
                }
                uVar7 = (uint)param_2;
                if (uVar7 < 0x2b) {
                  if (uVar7 == 0x1e) {
                    *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef | 0x10;
                  }
                  else {
                    *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef;
                    if (uVar7 == 0x26) {
                      *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xef | 0x10;
                      goto LAB_0304bcd4;
                    }
                  }
                }
                else {
                  local_18[0] = 0;
                  uVar7 = 0;
                  *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef;
                }
                *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xef;
LAB_0304bcd4:
                p_dm32_settings_block04->field_0x79 = (char)uVar7;
                PTR_DAT_0304bd58[4] = PTR_DAT_0304bd54[uVar7];
                flash_field_write_cached(4,0x90);
                return 1;
              }
              uVar7 = (uint)param_2;
              if (uVar7 < 0x2b) {
                if (uVar7 == 0x1e) {
                  *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef | 0x10;
                }
                else {
                  *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef;
                  if (uVar7 == 0x26) {
                    *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xef | 0x10;
                    goto LAB_0304bc54;
                  }
                }
              }
              else {
                local_18[0] = 0;
                uVar7 = 0;
                *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xef;
              }
              *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xef;
LAB_0304bc54:
              p_dm32_settings_block04->field_0x73 = (char)uVar7;
              PTR_DAT_0304bd58[9] = PTR_DAT_0304bd54[uVar7];
              flash_field_write_cached(4,0x8f);
              return 1;
            }
            uVar7 = (uint)param_2;
            if (uVar7 < 0x2b) {
              if (uVar7 == 0x1e) {
                *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xf7 | 8;
              }
              else {
                *(byte *)PTR_DAT_0304bd48 = *(byte *)PTR_DAT_0304bd48 & 0xf7;
                if (uVar7 == 0x26) {
                  *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xf7 | 8;
                  goto LAB_0304bbd4;
                }
              }
            }
            else {
              local_18[0] = 0;
              uVar7 = 0;
              *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xf7;
            }
            *(byte *)PTR_DAT_0304bd4c = *(byte *)PTR_DAT_0304bd4c & 0xf7;
LAB_0304bbd4:
            p_dm32_settings_block04->field_0x78 = (char)uVar7;
            PTR_DAT_0304bd58[3] = PTR_DAT_0304bd54[uVar7];
            flash_field_write_cached(4,0x8e);
            return 1;
          }
          uVar7 = (uint)param_2;
          if (uVar7 < 0x2b) {
            if (uVar7 == 0x1e) {
              *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xf7 | 8;
            }
            else {
              *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xf7;
              if (uVar7 == 0x26) {
                *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xf7 | 8;
                goto LAB_0304bb3e;
              }
            }
          }
          else {
            local_18[0] = 0;
            uVar7 = 0;
            *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xf7;
          }
          *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xf7;
LAB_0304bb3e:
          p_dm32_settings_block04->field_0x72 = (char)uVar7;
          PTR_DAT_0304bba4[8] = PTR_DAT_0304bba0[uVar7];
          flash_field_write_cached(4,0x8d);
          return 1;
        }
        uVar7 = (uint)param_2;
        if (uVar7 < 0x2b) {
          if (uVar7 == 0x1e) {
            *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xfb | 4;
          }
          else {
            *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xfb;
            if (uVar7 == 0x26) {
              *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xfb | 4;
              goto LAB_0304babe;
            }
          }
        }
        else {
          local_18[0] = 0;
          uVar7 = 0;
          *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xfb;
        }
        *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xfb;
LAB_0304babe:
        p_dm32_settings_block04->field_0x77 = (char)uVar7;
        PTR_DAT_0304bba4[1] = PTR_DAT_0304bba0[uVar7];
        flash_field_write_cached(4,0x8a);
        return 1;
      }
      uVar7 = (uint)param_2;
      if (uVar7 < 0x2b) {
        if (uVar7 == 0x1e) {
          *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xfb | 4;
        }
        else {
          *(byte *)PTR_DAT_0304bb94 = *(byte *)PTR_DAT_0304bb94 & 0xfb;
          if (uVar7 == 0x26) {
            *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xfb | 4;
            goto LAB_0304ba3e;
          }
        }
      }
      else {
        local_18[0] = 0;
        uVar7 = 0;
        *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfb;
      }
      *(byte *)PTR_DAT_0304bb98 = *(byte *)PTR_DAT_0304bb98 & 0xfb;
LAB_0304ba3e:
      p_dm32_settings_block04->field_0x71 = (char)uVar7;
      PTR_DAT_0304bba4[6] = PTR_DAT_0304bba0[uVar7];
      flash_field_write_cached(4,0x89);
      return 1;
    }
    uVar7 = (uint)param_2;
    if (uVar7 < 0x2b) {
      if (uVar7 == 0x1e) {
        *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd | 2;
      }
      else {
        *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd;
        if (uVar7 == 0x26) {
          *(byte *)PTR_DAT_0304b9f4 = *(byte *)PTR_DAT_0304b9f4 & 0xfd | 2;
          goto LAB_0304b9a8;
        }
      }
    }
    else {
      local_18[0] = 0;
      uVar7 = 0;
      *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd;
    }
    *(byte *)PTR_DAT_0304b9f4 = *(byte *)PTR_DAT_0304b9f4 & 0xfd;
LAB_0304b9a8:
    p_dm32_settings_block04->field_0x76 = (char)uVar7;
    *PTR_DAT_0304b9fc = PTR_DAT_0304b9f8[uVar7];
    flash_field_write_cached(4,0x88);
    return 1;
  }
  uVar7 = (uint)param_2;
  if (uVar7 < 0x2b) {
    if (uVar7 == 0x1e) {
      *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd | 2;
    }
    else {
      *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd;
      if (uVar7 == 0x26) {
        *(byte *)PTR_DAT_0304b9f4 = *(byte *)PTR_DAT_0304b9f4 & 0xfd | 2;
        goto LAB_0304b928;
      }
    }
  }
  else {
    local_18[0] = 0;
    uVar7 = 0;
    *(byte *)PTR_DAT_0304b9f0 = *(byte *)PTR_DAT_0304b9f0 & 0xfd;
  }
  *(byte *)PTR_DAT_0304b9f4 = *(byte *)PTR_DAT_0304b9f4 & 0xfd;
LAB_0304b928:
  p_dm32_settings_block04->field_0x70 = (char)uVar7;
  PTR_DAT_0304b9fc[5] = PTR_DAT_0304b9f8[uVar7];
  flash_field_write_cached(4,0x87);
  return 1;
}

