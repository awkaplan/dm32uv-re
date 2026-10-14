/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cps_serial_handshake_command_dispatcher @ 0302b3d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 736 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void cps_serial_handshake_command_dispatcher(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  ushort block_id;
  int iVar8;
  int iVar9;
  int iStack_30;
  undefined1 uStack_2c;
  undefined1 auStack_2b [7];
  
  puVar6 = PTR_s_PASSSTA_0302b534;
  puVar5 = PTR_s_PSEARCH_0302b530;
  puVar4 = PTR_s_PROGRAM_0302b52c;
  iVar3 = DAT_0302b528;
  iVar2 = DAT_0302b524;
  puVar1 = PTR_DAT_0302b520;
  do {
    while( true ) {
      while (iVar8 = (*(code *)(*puVar1 & 0xfffffffe))(&uStack_2c,7,500,&iStack_30),
            iStack_30 == 0x72d9) {
        if (((*(byte *)PTR_DAT_0302b6e4 & 0x40) != 0) &&
           (clear_counter_block_0302a19c(), (*(byte *)PTR_DAT_0302b6e4 & 0x40) != 0)) {
          *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf;
          flash_quad_enable_and_system_reset();
        }
      }
      if (*(char *)(iVar2 + 1) == '\x02') {
        PTR_DAT_0302b538[2] = 0;
        *(undefined1 *)(iVar2 + 1) = 1;
      }
      key_event_state_clear_preserve_bit0();
      settings_set_menu_hold_interval(*(undefined1 *)(iVar3 + 0x3a));
      iVar9 = buffer_compare_memcmp_style(&uStack_2c,puVar4,7);
      puVar7 = PTR_DAT_0302b53c;
      if (iVar9 != 0) break;
      *(byte *)PTR_DAT_0302b53c = *(byte *)PTR_DAT_0302b53c & 0xbf | 0x40;
      *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
      *(byte *)PTR_DAT_0302b540 = *(byte *)PTR_DAT_0302b540 & 0xfe;
      fd6818b_driver_state_reset();
      mmio_11000074_bits_7_8_set_clear(0);
      if ((*(byte *)PTR_call_active_flag_0302b544 & 10) != 0) {
        tx_audio_dac_envelope_ramp(1,0,0);
        pa_band_select_vhf_uhf_gpio(0);
      }
      serial_protocol_vframe_command_loop_variant();
      flash_quad_enable_and_system_reset();
      tx_led_or_tone_off();
      tx_led_or_tone_on();
      *(byte *)PTR_DAT_0302b53c = *(byte *)PTR_DAT_0302b53c & 0xbf;
    }
    iVar9 = buffer_compare_memcmp_style(&uStack_2c,puVar5,7);
    puVar7 = PTR_DAT_0302b53c;
    if ((iVar9 == 0) && (iVar8 == 7)) {
      *(byte *)PTR_DAT_0302b53c = *(byte *)PTR_DAT_0302b53c & 0xbf | 0x40;
      *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
      uStack_2c = 6;
      memcpy_bytes_iram(auStack_2b,PTR_s_DP570UV_0302b548,7);
      (*(code *)(puVar1[1] & 0xfffffffe))(&uStack_2c,8);
    }
    else {
      iVar9 = buffer_compare_memcmp_style(&uStack_2c,puVar6,7);
      puVar7 = PTR_DAT_0302b53c;
      if ((iVar9 == 0) && (iVar8 == 7)) {
        *(byte *)PTR_DAT_0302b53c = *(byte *)PTR_DAT_0302b53c & 0xbf | 0x40;
        *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
        block_id = flash_block_id_resolve_locked(4);
        flash_block_read(block_id,0x439,auStack_2b,2);
        uStack_2c = 0x50;
        (*(code *)(puVar1[1] & 0xfffffffe))(&uStack_2c,3);
      }
      else {
        iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_PASWORD_0302b6e0,7);
        puVar7 = PTR_DAT_0302b6e4;
        if ((iVar9 == 0) && (iVar8 == 7)) {
          *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf | 0x40;
          *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
          uStack_2c = 6;
          (*(code *)(puVar1[1] & 0xfffffffe))();
          serial_password_command_handler();
        }
        else {
          iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_PCTESTM_0302b6e8,7);
          puVar7 = PTR_DAT_0302b6e4;
          if ((iVar9 == 0) && (iVar8 == 7)) {
            *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf | 0x40;
            *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
            uStack_2c = 6;
            (*(code *)(puVar1[1] & 0xfffffffe))();
            cps_serial_field_rw_dispatcher();
          }
          else {
            iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_RTCITEM_0302b6ec,7);
            puVar7 = PTR_DAT_0302b6e4;
            if ((iVar9 == 0) && (iVar8 == 7)) {
              *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf | 0x40;
              *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
              uStack_2c = 6;
              (*(code *)(puVar1[1] & 0xfffffffe))();
              rtc_chip_response_poll_and_date_apply();
            }
            else {
              iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_DEL_RCD_0302b6f0,7);
              if ((iVar9 == 0) && (iVar8 == 7)) {
                uStack_2c = 6;
                (*(code *)(puVar1[1] & 0xfffffffe))(&uStack_2c,1);
                *(byte *)(PTR_DAT_0302b6e4 + 1) = *(byte *)(PTR_DAT_0302b6e4 + 1) & 0xf7 | 8;
                flash_dual_range_invalidate();
                flash_quad_enable_and_system_reset();
              }
              else {
                iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_IDCHECK_0302b6f4,7);
                puVar7 = PTR_DAT_0302b6e4;
                if ((iVar9 == 0) && (iVar8 == 7)) {
                  *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf | 0x40;
                  *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
                  uStack_2c = 6;
                  (*(code *)(puVar1[1] & 0xfffffffe))();
                }
                else {
                  iVar9 = buffer_compare_memcmp_style(&uStack_2c,PTR_s_SYSINFO_0302b6f8,7);
                  puVar7 = PTR_DAT_0302b6e4;
                  if ((iVar9 == 0) && (iVar8 == 7)) {
                    *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf | 0x40;
                    *(byte *)(puVar7 + 1) = *(byte *)(puVar7 + 1) & 0xf7 | 8;
                    uStack_2c = 6;
                    (*(code *)(puVar1[1] & 0xfffffffe))();
                    serial_protocol_vframe_command_loop();
                  }
                  else {
                    clear_counter_block_0302a19c();
                    if ((*(byte *)PTR_DAT_0302b6e4 & 0x40) != 0) {
                      *(byte *)PTR_DAT_0302b6e4 = *(byte *)PTR_DAT_0302b6e4 & 0xbf;
                      flash_quad_enable_and_system_reset();
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } while( true );
}

