/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_clock_out_byte_to_companion_chip @ 030c3f24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool serial_clock_out_byte_to_companion_chip(uint param_1)

{
  int iVar1;
  dword dVar2;
  dword dVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar4 = PTR_DAT_030c3fc8;
  dVar2 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = 1 << (*PTR_DAT_030c3fc8 * 2 + 6U & 0x3f) | dVar2;
  uVar6 = 7;
  do {
    func_0x030ddba0(1);
    if (((int)(param_1 & 0xff) >> (uVar6 & 0x3f) & 1U) == 0) {
      dVar2 = GPIOA_14020000.SWPORTA_DR;
      GPIOA_14020000.SWPORTA_DR = dVar2 & ~(1 << (*puVar4 * 2 + 6U & 0x3f));
    }
    else {
      dVar2 = GPIOA_14020000.SWPORTA_DR;
      GPIOA_14020000.SWPORTA_DR = 1 << (*puVar4 * 2 + 6U & 0x3f) | dVar2;
    }
    func_0x030ddba0(1);
    dVar2 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar4 * 2 + 5U & 0x3f) | dVar2;
    func_0x030ddba0(1);
    puVar5 = PTR_DAT_030c3fc8;
    dVar2 = GPIOA_14020000.SWPORTA_DR;
    uVar6 = uVar6 - 1;
    GPIOA_14020000.SWPORTA_DR = dVar2 & ~(1 << (*puVar4 * 2 + 5U & 0x3f));
  } while (uVar6 != 0xffffffff);
  dVar2 = GPIOA_14020000.SWPORTA_DR;
  uVar6 = ~(1 << (*puVar4 * 2 + 6U & 0x3f));
  GPIOA_14020000.SWPORTA_DR = dVar2 & uVar6;
  dVar2 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = uVar6 & dVar2;
  func_0x030ddba0(1);
  dVar2 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = 1 << (*puVar5 * 2 + 5U & 0x3f) | dVar2;
  func_0x030ddba0(1);
  iVar1 = *puVar5 * 2;
  dVar3 = GPIOA_14020000.EXT_PORTA;
  dVar2 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar2 & ~(1 << (iVar1 + 5U & 0x3f));
  uVar6 = 1 << (iVar1 + 6U & 0x3f);
  dVar2 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = uVar6 | dVar2;
  return (uVar6 & dVar3) != 0;
}

