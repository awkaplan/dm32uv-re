/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_power_on_display_and_keypad_poll_loop @ 0305f128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 386 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_power_on_display_and_keypad_poll_loop(void)

{
  dword dVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 | 0xfe00;
  gpio_pin_set_output_level(0x4d,0);
  gpio_pin_set_output_level(0x4e,1);
  gpio_pin_set_output_level(0x47,1);
  gpio_pin_set_output_level(0x48,1);
  gpio_pin_set_output_level(0x49,1);
  gpio_pin_set_output_level(0x4a,1);
  gpio_pin_set_output_level(0x4b,1);
  iVar4 = gpio_read_input_bit(0x34);
  OSTimeDly_ms_wrapper(0x32);
  if ((iVar4 == 0) && (iVar4 = gpio_read_input_bit(0x33), iVar4 == 0)) {
    if ((PTR_DAT_0305f2b0[0x31] & 4) != 0) {
      PTR_DAT_0305f2b4[2] = PTR_DAT_0305f2b4[2] & 0xfb | 4;
      lcd_bus_pads_restore_after_keypad_scan();
      OSTimeDly_ms_wrapper(0x32);
      display_clear_fullscreen();
      puVar3 = PTR_PTR_0305f2b8;
      puVar2 = PTR_DAT_0305f2b0;
      display_draw_number_centered
                (0x46,0xffff,0,
                 *(uint *)PTR_PTR_0305f2b8[((byte)PTR_DAT_0305f2b0[0x30] >> 6 & 1) * 2]);
      display_draw_number_centered
                (100,0xffff,0,*(uint *)(puVar3[((byte)puVar2[0x30] >> 6 & 1) * 2] + 4));
      display_draw_number_centered
                (0x82,0xffff,0,*(uint *)(puVar3[((byte)puVar2[0x30] >> 6 & 1) * 2] + 8));
      display_draw_string_gb2312
                (0x122,0xc,
                 (byte *)**(undefined4 **)(PTR_PTR_0305f2bc + ((byte)puVar2[0x30] >> 6 & 1) * 8),
                 0xffff,0);
      display_draw_string_gb2312
                (0x122,0xb4,
                 (byte *)**(undefined4 **)(PTR_PTR_0305f2c0 + ((byte)puVar2[0x30] >> 6 & 1) * 8),
                 0xffff,0);
      settings_set_menu_hold_interval(puVar2[0x3a]);
      do {
        OSTimeDly_ms_wrapper(10);
        keypad_poll_and_dispatch_key_event();
      } while( true );
    }
    PTR_DAT_0305f2b4[2] = PTR_DAT_0305f2b4[2] & 0xf7 | 8;
    lcd_bus_pads_restore_after_keypad_scan();
    OSTimeDly_ms_wrapper(0x32);
    display_clear_fullscreen();
    puVar2 = PTR_DAT_0305f2b0;
    display_draw_number_centered
              (100,0xffff,0,PTR_PTR_0305f2c4[(byte)PTR_DAT_0305f2b0[0x30] >> 6 & 1]);
    settings_set_menu_hold_interval(puVar2[0x3a]);
    OSTimeDly_ms_wrapper(1000);
  }
  return;
}

