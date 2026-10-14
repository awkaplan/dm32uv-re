/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_date_validate_and_write @ 0301c498 (file base 0x03000000; code starts at 0x03001000)
 * Size: 322 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 rtc_date_validate_and_write(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uStack_13;
  undefined1 uStack_12;
  short sStack_10;
  
  uVar5 = param_2 & 0xff;
  uVar6 = param_2 >> 8 & 0xff;
  uVar1 = param_2 >> 0x10;
  if (uVar1 < 0x7b2) {
    uVar4 = 1;
  }
  else if ((uVar6 - 1 & 0xff) < 0xc) {
    if ((uVar5 == 0) || ((byte)PTR_LAB_0301c5cc[uVar6] < uVar5)) {
      if (uVar1 % 400 != 0) {
        if (uVar1 % 100 == 0) {
          return 3;
        }
        if ((param_2 & 0x30000) != 0) {
          return 3;
        }
      }
      sStack_10 = (short)param_2;
      if (sStack_10 != 0x21d) {
        return 3;
      }
    }
    uVar2 = uVar1 - 1;
    uVar3 = uVar2;
    if ((uVar2 & 0x80000000) != 0) {
      uVar3 = uVar1 + 2;
    }
    uVar3 = (uVar5 + uVar1 * 0x16d + 0x559 +
             (uint)*(ushort *)(PTR_LAB_0301c5d0 + (uVar6 - 1) * 2 + 0x18) + ((int)uVar3 >> 2) +
            (int)uVar2 / 400) - (int)uVar2 / 100 & 0xffff;
    uVar5 = uVar3 - 1 & 0xffff;
    if (((uVar1 % 400 == 0) || ((uVar1 % 100 != 0 && ((param_2 & 0x30000) == 0)))) && (2 < uVar6)) {
      uVar5 = uVar3;
    }
    device_reg_write_selector_0xe0(0x12,0);
    uStack_12 = (undefined1)(param_1 >> 0x10);
    device_reg_write_selector_0xe0(0xc,uStack_12);
    uStack_13 = (undefined1)(param_1 >> 8);
    device_reg_write_selector_0xe0(0xd,uStack_13);
    device_reg_write_selector_0xe0(0xe,param_1 & 0xff);
    device_reg_write_selector_0xe0(0xf,uVar5 & 0xff);
    device_reg_write_selector_0xe0(0x10,uVar5 >> 8);
    device_reg_write_selector_0xe0(0x12,1);
    rtc_register_0x11_set_bit2();
    uVar4 = 0;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

