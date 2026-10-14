/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_modem_core_reset_and_poll_ready @ 030043c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
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

void hr_c7000_modem_core_reset_and_poll_ready(void)

{
  dword dVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = _DAT_030044c4;
  SystemControl_Type_11000000.LCSFC_BAUDR = 4;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 & 0xff000000;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x10;
  SystemControl_Type_11000000.CLK_MGR_REG0x10 = dVar1 | 0x40712;
  SystemControl_Type_11000000.CLK_MGR_REG0x28 = 0x70006;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 & 0xfffffff0;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x24;
  SystemControl_Type_11000000.CLK_MGR_REG0x24 = dVar1 | 2;
  *PTR_DAT_030044c8 = _DAT_030044c4;
  *PTR_DAT_030044cc = uVar2;
  *PTR_LAB_030044d0 = _DAT_030044d4;
  *PTR_LAB_030044d8 = 24000000;
  uVar3 = _DAT_030044dc;
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 | 3;
  do {
    (*(code *)(uVar3 & 0xfffffffe))(100);
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  } while (-1 < (int)dVar1);
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 & 0xfffffffb;
  (*(code *)(uVar3 & 0xfffffffe))(100);
  dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  SystemControl_Type_11000000.CLK_MGR_REG0x04 = dVar1 & 0xfffffff7;
  do {
    (*(code *)(uVar3 & 0xfffffffe))(100);
    dVar1 = SystemControl_Type_11000000.CLK_MGR_REG0x04;
  } while ((dVar1 & 0x40000000) == 0);
  SystemControl_Type_11000000.CLK_MGR_REG0x2c = 0xffffffff;
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & 0xfffffffc;
  return;
}

