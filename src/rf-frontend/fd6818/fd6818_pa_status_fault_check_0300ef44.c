/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818_pa_status_fault_check @ 0300ef44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool fd6818_pa_status_fault_check(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_0X69);
  if (-1 < (short)uVar1) {
    uVar2 = fd6818_reg_read(FD6818_PAGE0_REG_0X69);
    *(ushort *)PTR_DAT_0300f030 = uVar2 & 0xfff;
    uVar2 = fd6818_reg_read(FD6818_PAGE0_REG_0X6A);
    uVar2 = uVar2 & 0xfff;
    *(ushort *)PTR_DAT_0300f034 = uVar2;
    if (((uVar2 != 0x555) && (uVar2 != 0xaaa)) && (uVar2 != 0)) {
      if ((uVar1 & 0x4000) != 0) {
        return (bool)3;
      }
      *(ushort *)PTR_DAT_0300f030 = *(ushort *)PTR_DAT_0300f030 & 0x7fff;
      return (bool)2;
    }
  }
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_0X68);
  if (-1 < (short)uVar1) {
    *(ushort *)PTR_DAT_0300f038 = uVar1 & 0x1fff;
  }
  return -1 < (short)uVar1;
}

