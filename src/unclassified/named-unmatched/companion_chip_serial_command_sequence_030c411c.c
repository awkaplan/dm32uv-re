/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: companion_chip_serial_command_sequence @ 030c411c (file base 0x03000000; code starts at 0x03001000)
 * Size: 404 bytes
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
companion_chip_serial_command_sequence(byte param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  dword dVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = PTR_DAT_030c4244;
  dVar4 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar4 & ~(1 << (*PTR_DAT_030c4244 * 2 + 6U & 0x3f));
  func_0x030ddba0(1);
  dVar4 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar4 & ~(1 << (*puVar1 * 2 + 5U & 0x3f));
  iVar3 = serial_clock_out_byte_to_companion_chip(param_1);
  if (iVar3 == 1) {
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar4;
    func_0x030ddba0();
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 6U & 0x3f) | dVar4;
    func_0x030ddba0(1);
    return 0;
  }
  iVar3 = serial_clock_out_byte_to_companion_chip(param_2);
  if (iVar3 != 1) {
    func_0x030ddba0(1);
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 6U & 0x3f) | dVar4;
    func_0x030ddba0(1);
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar4;
    func_0x030ddba0(5);
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = dVar4 & ~(1 << (*puVar1 * 2 + 6U & 0x3f));
    func_0x030ddba0(1);
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = dVar4 & ~(1 << (*puVar1 * 2 + 5U & 0x3f));
    iVar3 = serial_clock_out_byte_to_companion_chip(param_1 | 1);
    if (iVar3 == 1) {
      dVar4 = GPIOA_14020000.SWPORTA_DR;
      dVar4 = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar4;
    }
    else {
      if (param_4 != 1) {
        uVar6 = 0;
        do {
          uVar2 = bitbang_serial_byte_read_with_strobe(0);
          uVar5 = uVar6 + 1;
          *(undefined1 *)(param_3 + uVar6) = uVar2;
          uVar6 = uVar5;
        } while (uVar5 < param_4 - 1U);
      }
      uVar2 = bitbang_serial_byte_read_with_strobe(1);
      *(undefined1 *)(param_3 + param_4 + -1) = uVar2;
      dVar4 = GPIOA_14020000.SWPORTA_DR;
      dVar4 = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar4;
    }
    GPIOA_14020000.SWPORTA_DR = dVar4;
    func_0x030ddba0(1);
    dVar4 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 6U & 0x3f) | dVar4;
    func_0x030ddba0(1);
    return 0;
  }
  dVar4 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 5U & 0x3f) | dVar4;
  func_0x030ddba0();
  dVar4 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = 1 << (*puVar1 * 2 + 6U & 0x3f) | dVar4;
  func_0x030ddba0(2);
  return 0;
}

