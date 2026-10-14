/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_bitbang_read_byte_pin8 @ 0002d230 (IRAM address; the boot stub copies these bytes from program flash 0x030dce50)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte fd6818b_bitbang_read_byte_pin8(char param_1)

{
  byte bVar1;
  int iVar2;
  
  uRam14020004 = uRam14020004 & 0xfffffeff;
  bVar1 = 0;
  iVar2 = 0;
  do {
    identity_return_arg();
    gpio_set_output_bit(7);
    identity_return_arg();
    bVar1 = bVar1 * '\x02';
    if ((uRam14020050 & 0x100) != 0) {
      bVar1 = bVar1 | 1;
    }
    gpio_clear_output_bit(7);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  uRam14020004 = uRam14020004 | 0x100;
  if (param_1 == '\0') {
    gpio_clear_output_bit(8);
  }
  else {
    gpio_set_output_bit(8);
  }
  identity_return_arg();
  gpio_set_output_bit(7);
  identity_return_arg();
  gpio_clear_output_bit(7);
  gpio_clear_output_bit(8);
  return bVar1;
}

