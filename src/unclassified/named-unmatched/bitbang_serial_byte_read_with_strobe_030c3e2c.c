/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitbang_serial_byte_read_with_strobe @ 030c3e2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 248 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte bitbang_serial_byte_read_with_strobe(char param_1)

{
  dword dVar1;
  undefined4 *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = PTR_DAT_030c3fc8;
  dVar1 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = dVar1 & ~(1 << (*PTR_DAT_030c3fc8 * 2 + 6U & 0x3f));
  iVar4 = 8;
  bVar3 = 0;
  do {
    func_0x030ddba0(1);
    dVar1 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = 1 << (*puVar2 * 2 + 5U & 0x3f) | dVar1;
    func_0x030ddba0(1);
    dVar1 = GPIOA_14020000.EXT_PORTA;
    bVar3 = bVar3 * '\x02';
    iVar4 = iVar4 + -1;
    if ((1 << (*puVar2 * 2 + 6U & 0x3f) & dVar1) != 0) {
      bVar3 = bVar3 | 1;
    }
    dVar1 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = dVar1 & ~(1 << (*puVar2 * 2 + 5U & 0x3f));
    func_0x030ddba0(1);
  } while (iVar4 != 0);
  uVar5 = 1 << (*puVar2 * 2 + 6U & 0x3f);
  dVar1 = GPIOA_14020000.SWPORTA_DDR;
  GPIOA_14020000.SWPORTA_DDR = dVar1 | uVar5;
  if (param_1 == '\0') {
    dVar1 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = dVar1 & ~uVar5;
  }
  else {
    dVar1 = GPIOA_14020000.SWPORTA_DR;
    GPIOA_14020000.SWPORTA_DR = uVar5 | dVar1;
  }
  func_0x030ddba0(1);
  dVar1 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = 1 << (*puVar2 * 2 + 5U & 0x3f) | dVar1;
  func_0x030ddba0(1);
  dVar1 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar1 & ~(1 << (*puVar2 * 2 + 5U & 0x3f));
  dVar1 = GPIOA_14020000.SWPORTA_DR;
  GPIOA_14020000.SWPORTA_DR = dVar1 & ~(1 << (*puVar2 * 2 + 6U & 0x3f));
  return bVar3;
}

