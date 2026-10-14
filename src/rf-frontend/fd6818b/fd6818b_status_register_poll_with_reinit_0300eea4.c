/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_status_register_poll_with_reinit @ 0300eea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 160 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 fd6818b_status_register_poll_with_reinit(void)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0x10a;
  if ((PTR_DAT_0300f020[3] & 0x10) == 0) {
    uVar6 = 0xcf;
  }
  else {
    uVar6 = 0x262;
    uVar5 = 0x2dc;
  }
  uVar3 = fd6818_reg_read(FD6818_PAGE0_REG_0X0D);
  if ((((short)(ushort)uVar3 < 0) || (uVar3 < uVar6)) || (uVar5 < uVar3)) {
    cVar1 = *(char *)PTR_DAT_0300f02c;
    *(byte *)PTR_DAT_0300f02c = cVar1 + 1U;
    if ((byte)(cVar1 + 1U) < 0xc9) {
      uVar4 = 1;
    }
    else {
      *(undefined1 *)PTR_DAT_0300f02c = 0;
      fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x244);
      busy_wait_delay_n_units(10);
      fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x245);
      busy_wait_delay_n_units(200);
      uVar4 = 1;
    }
  }
  else {
    *(ushort *)PTR_DAT_0300f024 = (ushort)uVar3 & 0x7ff;
    uVar2 = fd6818_reg_read(FD6818_PAGE0_REG_0X0E);
    *(undefined2 *)PTR_DAT_0300f028 = uVar2;
    fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x244);
    uVar4 = 0;
  }
  return uVar4;
}

