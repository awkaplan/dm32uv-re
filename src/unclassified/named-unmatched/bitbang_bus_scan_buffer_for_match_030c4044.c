/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitbang_bus_scan_buffer_for_match @ 030c4044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 216 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
bitbang_bus_scan_buffer_for_match(undefined1 param_1,undefined1 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  dword dVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_030c4244;
  dVar3 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar3 & ~(1 << (*PTR_DAT_030c4244 * 2 + 6U & 0x3f));
  func_0x030ddba0(1);
  dVar3 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar3 & ~(1 << (*puVar1 * 2 + 5U & 0x3f));
  iVar2 = serial_clock_out_byte_to_companion_chip(param_1);
  if ((iVar2 == 1) || (iVar2 = serial_clock_out_byte_to_companion_chip(param_2), iVar2 == 1)) {
    dVar3 = GPIOA_14020000.SWPORTA_DR;
    dVar3 = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar3;
  }
  else {
    if (param_4 != 0) {
      uVar4 = 0;
      do {
        iVar2 = serial_clock_out_byte_to_companion_chip(*(undefined1 *)(param_3 + uVar4));
        uVar4 = uVar4 + 1;
        if (iVar2 == 1) {
          dVar3 = GPIOA_14020000.SWPORTA_DR;
          dVar3 = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar3;
          goto LAB_030c40e4;
        }
      } while (uVar4 < param_4);
    }
    dVar3 = GPIOA_14020000.SWPORTA_DR;
    dVar3 = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar3;
  }
LAB_030c40e4:
  GPIOA_14020000.SWPORTA_DR = dVar3;
  func_0x030ddba0(1);
  dVar3 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 6U & 0x3f) | dVar3;
  func_0x030ddba0(1);
  return 0;
}

