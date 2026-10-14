/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_scan_and_map_pressed_key @ 03013660 (file base 0x03000000; code starts at 0x03001000)
 * Size: 226 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 keypad_scan_and_map_pressed_key(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  
  keypad_scan_begin_mux_rows_drive_low();
  busy_wait_delay_loop_short(0x32);
  iVar4 = gpio_portb_read_input_bits_17_to_20();
  if (iVar4 == 0xf) {
    uVar3 = 0;
  }
  else {
    gpio_pin_set_output_level(0x47,1);
    gpio_pin_set_output_level(0x48,1);
    gpio_pin_set_output_level(0x49,1);
    gpio_pin_set_output_level(0x4a,1);
    gpio_pin_set_output_level(0x4b,1);
    busy_wait_delay_loop_short(0x32);
    iVar4 = gpio_read_input_bit(0x34);
    if (iVar4 == 0) {
      uVar3 = 7;
    }
    else {
      iVar4 = gpio_read_input_bit(0x33);
      if (iVar4 == 0) {
        uVar3 = 4;
      }
      else {
        gpio_pin_set_output_level(0x47,0);
        gpio_pin_set_output_level(0x48,0);
        gpio_pin_set_output_level(0x49,0);
        gpio_pin_set_output_level(0x4a,0);
        gpio_pin_set_output_level(0x4b,0);
        busy_wait_delay_loop_short(0x32);
        puVar2 = PTR_DAT_03013828;
        *(undefined1 *)PTR_DAT_03013828 = 0;
        iVar4 = 0;
        do {
          uVar5 = gpioc_reg0_set_bits(iVar4);
          if (uVar5 != 0xf) {
            if ((uVar5 & 8) != 0) {
              cVar6 = *(char *)PTR_DAT_03013828;
              do {
                cVar6 = cVar6 + '\x01';
                uVar1 = uVar5 * 2;
                uVar5 = uVar1 & 0xff;
              } while ((uVar1 & 8) != 0);
              *(char *)PTR_DAT_03013828 = cVar6;
            }
            return PTR_LAB_0301382c[*(byte *)PTR_DAT_03013828];
          }
          *(char *)puVar2 = *(char *)puVar2 + '\x04';
          iVar4 = iVar4 + 1;
        } while (iVar4 != 6);
        uVar3 = 0x65;
      }
    }
  }
  return uVar3;
}

