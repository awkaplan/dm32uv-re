/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitbang_serial_command_read_pins56 @ 0301dd0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 250 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
bitbang_serial_command_read_pins56(byte param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  gpio_clear_output_bit(6);
  identity_return_arg();
  gpio_clear_output_bit(5);
  iVar2 = alpu_i2c_shift_out_byte(param_1);
  if (iVar2 == 1) {
    gpio_set_output_bit(5);
    identity_return_arg();
    gpio_set_output_bit(6);
    busy_wait_delay_loop_4arg(1);
    uVar3 = 0xff;
  }
  else {
    iVar2 = alpu_i2c_shift_out_byte(param_2);
    if (iVar2 == 1) {
      gpio_set_output_bit(5);
      identity_return_arg();
      gpio_set_output_bit(6);
      busy_wait_delay_loop_4arg(2);
      uVar3 = 0xff;
    }
    else {
      identity_return_arg();
      gpio_set_output_bit(6);
      identity_return_arg();
      gpio_set_output_bit(5);
      busy_wait_delay_loop_4arg(5);
      gpio_clear_output_bit(6);
      identity_return_arg();
      gpio_clear_output_bit(5);
      iVar2 = alpu_i2c_shift_out_byte(param_1 | 1);
      if (iVar2 == 1) {
        gpio_set_output_bit(5);
        identity_return_arg();
        gpio_set_output_bit(6);
        busy_wait_delay_loop_4arg(1);
        uVar3 = 0xff;
      }
      else {
        if (param_4 != 1) {
          uVar4 = 0;
          do {
            uVar1 = alpu_i2c_shift_in_byte(0);
            *(undefined1 *)(param_3 + uVar4) = uVar1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_4 - 1U);
        }
        uVar1 = alpu_i2c_shift_in_byte(1);
        *(undefined1 *)(param_3 + param_4 + -1) = uVar1;
        gpio_set_output_bit(5);
        identity_return_arg();
        gpio_set_output_bit(6);
        busy_wait_delay_loop_4arg(1);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

