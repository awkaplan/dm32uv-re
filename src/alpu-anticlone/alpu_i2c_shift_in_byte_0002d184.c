/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_i2c_shift_in_byte @ 0002d184 (IRAM address; the boot stub copies these bytes from program flash 0x030dcda4)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte alpu_i2c_shift_in_byte(char param_1)

{
  byte bVar1;
  int iVar2;
  
  uRam14020004 = uRam14020004 & 0xffffffbf;
  bVar1 = 0;
  iVar2 = 0;
  do {
    identity_return_arg();
    gpio_set_output_bit(5);
    identity_return_arg();
    bVar1 = bVar1 * '\x02';
    if ((uRam14020050 & 0x40) != 0) {
      bVar1 = bVar1 | 1;
    }
    gpio_clear_output_bit(5);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  uRam14020004 = uRam14020004 | 0x40;
  if (param_1 == '\0') {
    gpio_clear_output_bit(6);
  }
  else {
    gpio_set_output_bit(6);
  }
  identity_return_arg();
  gpio_set_output_bit(5);
  identity_return_arg();
  gpio_clear_output_bit(5);
  gpio_clear_output_bit(6);
  return bVar1;
}

