/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_timer_counter_to_time_components @ 0301d860 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
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

undefined4 hw_timer_counter_to_time_components(void)

{
  uint uVar1;
  
  TIMER_Type_14000000.CH[1].ControlReg = 2;
  uVar1 = *PTR_DAT_0301d8dc;
  TIMER_Type_14000000.CH[1].LoadCount = uVar1 / 1000;
  TIMER_Type_14000000.CH[2].ControlReg = 2;
  TIMER_Type_14000000.CH[2].LoadCount = uVar1 / 0x32;
  TIMER_Type_14000000.CH[3].ControlReg = 2;
  TIMER_Type_14000000.CH[3].LoadCount = uVar1 / 1000000;
  TIMER_Type_14000000.CH[4].ControlReg = 2;
  TIMER_Type_14000000.CH[4].LoadCount = uVar1;
  TIMER_Type_14000000.CH[5].ControlReg = 2;
  TIMER_Type_14000000.CH[5].LoadCount = uVar1 / 1000;
  irq_controller_unmask_and_register_handler(_DAT_0301d8e4,0x22);
  irq_controller_unmask_and_register_handler(_DAT_0301d8e8,0x23);
  set_flag_byte_03064328_variant_0301d858(_DAT_0301d8ec);
  irq_controller_unmask_and_register_handler(_DAT_0301d8f0,0x24);
  irq_controller_unmask_and_register_handler(_DAT_0301d8f4,0x25);
  irq_controller_unmask_and_register_handler(_DAT_0301d8f8,0x26);
  OSSemCreate_shared_name_wrapper(_DAT_0301d8fc,0);
  return 0;
}

