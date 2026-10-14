/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_modem_core_clock_and_reset_init @ 0301d5f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void hr_c7000_modem_core_clock_and_reset_init(void)

{
  dword dVar1;
  undefined1 auStack_c [4];
  
  OSSemCreate_shared_name_wrapper(_DAT_0301d6a8,1);
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX1;
  SystemControl_Type_11000000.IO_DIPLEX1 = dVar1 | 0x38000000;
  dVar1 = SystemControl_Type_11000000.RESERVED_0x40;
  SystemControl_Type_11000000.RESERVED_0x40 = dVar1 & 0xfeffffff;
  dVar1 = SystemControl_Type_11000000.RESERVED_0x40;
  SystemControl_Type_11000000.RESERVED_0x40 = dVar1 | 0x2000000;
  dVar1 = SystemControl_Type_11000000.RESERVED_0x48;
  SystemControl_Type_11000000.RESERVED_0x48 = dVar1 | 0x8000000;
  dVar1 = SystemControl_Type_11000000.RESERVED_0x48;
  SystemControl_Type_11000000.RESERVED_0x48 = dVar1 | 0x4000000;
  gpio_pin_set_output_level(0x22,0);
  gpio_pin_set_output_level(0x24,0);
  gpio_pin_set_output_level(0x37,0);
  gpio_pin_set_output_level(0x23,0);
  PTR_DAT_0301d6ac[0xb] = PTR_DAT_0301d6ac[0xb] & 0xfb | 4;
  FUN_0301d27c(0x3b,1,0);
  gpio_interrupt_disable_bit(0x3b);
  FUN_0301d27c(0x3a,1,1);
  gpio_interrupt_enable_bit(0x3a);
  modem_sem_create_and_gpio_0x18_high();
  OSTaskCreate(_DAT_0301d6b4,_DAT_0301d6b8,_DAT_0301d6bc,0,0x1d,_DAT_0301d6b0,0,0x100,0,0,0,3,
               auStack_c);
  return;
}

