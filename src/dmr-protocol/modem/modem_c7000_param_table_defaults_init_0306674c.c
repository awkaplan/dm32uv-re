/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_c7000_param_table_defaults_init @ 0306674c (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_c7000_param_table_defaults_init(void)

{
  dword dVar1;
  int iVar2;
  
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX1;
  SystemControl_Type_11000000.IO_DIPLEX1 = dVar1 & 0xfff81fff;
  gpio_pin_set_output_level(0x17,1);
  iVar2 = PTR_LAB_030668d8[1];
  *(undefined4 *)(iVar2 + 8) = 0;
  table_entry_write_word0(1,199);
  table_entry_write_field_0x14(1,0x10);
  *(undefined4 *)(iVar2 + 0x1c) = 7;
  *(undefined4 *)(iVar2 + 0x18) = 7;
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  OSSemCreate_shared_name_wrapper(_DAT_030668dc,1);
  return;
}

