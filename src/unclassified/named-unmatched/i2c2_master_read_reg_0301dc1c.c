/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: i2c2_master_read_reg @ 0301dc1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 238 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void i2c2_master_read_reg(uint param_1,uint param_2,int param_3,uint param_4)

{
  dword dVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  dVar1 = I2C2_RTC_14080000.IC_STATUS;
  while ((dVar1 & 8) != 0) {
    dVar1 = I2C2_RTC_14080000.IC_DATA_CMD;
    dVar1 = I2C2_RTC_14080000.IC_STATUS;
  }
  I2C2_RTC_14080000.IC_ENABLE = 0;
  dVar1 = I2C2_RTC_14080000.IC_CLR_INTR;
  I2C2_RTC_14080000.IC_TAR = (param_1 & 0xff) >> 1;
  I2C2_RTC_14080000.IC_ENABLE = 1;
  I2C2_RTC_14080000.IC_DATA_CMD = param_2 & 0xff;
  if (param_4 == 0) {
    I2C2_RTC_14080000.IC_START = 1;
  }
  else {
    dVar1 = I2C2_RTC_14080000.IC_STATUS;
    if ((dVar1 & 2) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      do {
        I2C2_RTC_14080000.IC_DATA_CMD = 0x100;
        uVar4 = uVar4 + 1;
        if (param_4 <= uVar4) break;
        dVar1 = I2C2_RTC_14080000.IC_STATUS;
      } while ((dVar1 & 2) != 0);
    }
    I2C2_RTC_14080000.IC_START = 1;
    uVar3 = 0;
    iVar2 = 0xfffff;
    do {
      for (; (dVar1 = I2C2_RTC_14080000.IC_STATUS, (dVar1 & 8) == 0 && (iVar2 != 0));
          iVar2 = iVar2 + -1) {
      }
      dVar1 = I2C2_RTC_14080000.IC_DATA_CMD;
      *(char *)(param_3 + uVar3) = (char)dVar1;
      if ((uVar4 < param_4) && (dVar1 = I2C2_RTC_14080000.IC_STATUS, (dVar1 & 2) != 0)) {
        I2C2_RTC_14080000.IC_DATA_CMD = 0x100;
        uVar4 = uVar4 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar2 = 0xfffff;
    } while (uVar3 < param_4);
  }
  I2C2_RTC_14080000.IC_START = 0;
  I2C2_RTC_14080000.IC_ENABLE = 0;
  return;
}

