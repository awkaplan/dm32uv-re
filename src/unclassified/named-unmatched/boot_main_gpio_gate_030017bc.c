/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: boot_main_gpio_gate @ 030017bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void boot_main_gpio_gate(void)

{
  int iVar1;
  
  board_gpio_init();
  OSTaskChangePrio();
  FUN_000120e8();
  func_0x0001239c(100);
  iVar1 = gpio_pin_read(0x2b);
  if ((iVar1 == 0) && (iVar1 = gpio_pin_read(0x33), iVar1 == 0)) {
    FUN_00011cf4(0x20);
    ucos3_sched_unlock_and_resched();
  }
  else {
    *PTR_DAT_03001800 = cpu_sr_restore_irq_inlined_fragment;
    cpu_sr_restore_irq_inlined_fragment();
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

