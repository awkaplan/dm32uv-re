/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_bitbang_write_byte_pin8 @ 0002d040 (IRAM address; the boot stub copies these bytes from program flash 0x030dcc60)
 * Size: 128 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool fd6818b_bitbang_write_byte_pin8(byte param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  uRam14020004 = uRam14020004 | 0x100;
  pbVar3 = pbRam0002d200 + 8;
  pbVar2 = pbRam0002d200;
  do {
    if ((*pbVar2 & param_1) == 0) {
      gpio_clear_output_bit(8);
    }
    else {
      gpio_set_output_bit(8);
    }
    identity_return_arg();
    gpio_set_output_bit(7);
    identity_return_arg();
    gpio_clear_output_bit(7);
    pbVar2 = pbVar2 + 1;
  } while (pbVar2 != pbVar3);
  gpio_clear_output_bit(8);
  uRam14020004 = uRam14020004 & 0xfffffeff;
  identity_return_arg();
  gpio_set_output_bit(7);
  identity_return_arg();
  uVar1 = uRam14020050;
  gpio_clear_output_bit(7);
  uRam14020004 = uRam14020004 | 0x100;
  return (uVar1 & 0x100) != 0;
}

