/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_i2c_recv_byte @ 030655ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte rda5807m_i2c_recv_byte(void)

{
  dword dVar1;
  byte unaff_r4;
  char cVar2;
  
  dVar1 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = dVar1 & 0xfdffffff;
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  iram_delay_call_arg2();
  cVar2 = '\b';
  do {
    iram_delay_call_arg2();
    iram_delay_call_arg2();
    gpio_set_output_bit(0x1a);
    iram_delay_call_arg2();
    iram_delay_call_arg2();
    iram_delay_call_arg2();
    unaff_r4 = unaff_r4 * '\x02';
    dVar1 = GPIOA_14020000.EXT_PORTA;
    if ((dVar1 & 0x2000000) != 0) {
      unaff_r4 = unaff_r4 | 1;
    }
    gpio_clear_output_bit(0x1a);
    iram_delay_call_arg2();
    iram_delay_call_arg2();
    iram_delay_call_arg2();
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  dVar1 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = dVar1 | 0x2000000;
  iram_delay_call_arg2();
  return unaff_r4;
}

