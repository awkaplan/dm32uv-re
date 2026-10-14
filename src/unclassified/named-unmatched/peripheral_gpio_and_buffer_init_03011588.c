/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: peripheral_gpio_and_buffer_init @ 03011588 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
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

void peripheral_gpio_and_buffer_init(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_c [4];
  
  puVar1 = PTR_DAT_03011620;
  *(undefined2 *)(PTR_DAT_03011620 + 10) = 0;
  *puVar1 = *puVar1 & 0xfc | 2;
  puVar2 = PTR_DAT_03011624;
  *(undefined2 *)PTR_DAT_03011624 = 0;
  *(undefined2 *)((int)puVar2 + 2) = 0;
  *(undefined2 *)(puVar2 + 1) = 0;
  *(undefined1 *)((int)puVar2 + 6) = 0;
  if ((puVar1[0xd8] & 1) == 0) {
    gpio_set_output_bit(0x2c);
  }
  else {
    gpio_clear_output_bit(0x2c);
  }
  OSSemCreate_shared_name_wrapper(_DAT_03011628,1);
  uVar3 = _DAT_0301162c;
  memset_bytes(_DAT_0301162c,0,0x400);
  OSTaskCreate(_DAT_03011630,_DAT_03011634,_DAT_03011638,0,0x15,uVar3,0,0x100,0,0,0,3,auStack_c);
  return;
}

