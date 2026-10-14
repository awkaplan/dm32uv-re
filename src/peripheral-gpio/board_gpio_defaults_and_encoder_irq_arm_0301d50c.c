/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: board_gpio_defaults_and_encoder_irq_arm @ 0301d50c (file base 0x03000000; code starts at 0x03001000)
 * Size: 208 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-gpio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void board_gpio_defaults_and_encoder_irq_arm(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = radio_event_dispatch_by_name(_DAT_0301d5dc,0);
  iVar3 = noop_stub_0300c434();
  if (iVar3 == iVar2) {
    gpio_pin_set_output_level(0x21,0);
    gpio_pin_set_output_level(0x20,0);
    if ((*(byte *)PTR_DAT_0301d5e0 & 4) == 0) {
      gpio_pin_set_output_level(0x2c,0);
    }
    else {
      gpio_pin_set_output_level(0x2c,1);
    }
    gpio_pin_set_output_level(0x2e,0);
    gpio_pin_set_output_level(0x2f,0);
    GPIOA_14020000.DEBOUNCE = 0xffffffff;
    GPIOB_14100000.DEBOUNCE = 0xffffffff;
    GPIOC_14110000.DEBOUNCE = 0xffffffff;
    FUN_0301d27c(0x27,1,1);
    FUN_0301d27c(0x26,1,1);
    uVar1 = gpio_read_input_bit(0x27);
    *(undefined1 *)PTR_DAT_0301d5e4 = uVar1;
    uVar1 = gpio_read_input_bit(0x26);
    *(undefined1 *)PTR_DAT_0301d5e8 = uVar1;
    iVar2 = gpio_read_input_bit(0x27);
    if (iVar2 != 0) {
      gpio_interrupt_enable_bit_with_polarity(0x27,0);
    }
    iVar2 = gpio_read_input_bit(0x26);
    if (iVar2 != 0) {
      gpio_interrupt_enable_bit_with_polarity(0x26,0);
    }
    irq_controller_unmask_and_register_handler(_DAT_0301d5ec,0x2f);
    irq_controller_unmask_and_register_handler(_DAT_0301d5f0,0x2e);
    irq_controller_unmask_and_register_handler(_DAT_0301d5f4,0x31);
  }
  return;
}

