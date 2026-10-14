/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_i2c_shift_out_byte @ 0002ced4 (IRAM address; the boot stub copies these bytes from program flash 0x030dcaf4)
 * Size: 128 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool alpu_i2c_shift_out_byte(byte param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  uRam14020004 = uRam14020004 | 0x40;
  pbVar3 = pbRam0002d038 + 8;
  pbVar2 = pbRam0002d038;
  do {
    if ((*pbVar2 & param_1) == 0) {
      gpio_clear_output_bit(6);
    }
    else {
      gpio_set_output_bit(6);
    }
    identity_return_arg();
    gpio_set_output_bit(5);
    identity_return_arg();
    gpio_clear_output_bit(5);
    pbVar2 = pbVar2 + 1;
  } while (pbVar2 != pbVar3);
  gpio_clear_output_bit(6);
  uRam14020004 = uRam14020004 & 0xffffffbf;
  identity_return_arg();
  gpio_set_output_bit(5);
  identity_return_arg();
  uVar1 = uRam14020050;
  gpio_clear_output_bit(5);
  uRam14020004 = uRam14020004 | 0x40;
  return (uVar1 & 0x40) != 0;
}

