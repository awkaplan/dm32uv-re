/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: i2c2_master_write_reg @ 0301db40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 204 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 i2c2_master_write_reg(uint param_1,uint param_2,int param_3,uint param_4)

{
  dword dVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  I2C2_RTC_14080000.IC_ENABLE = 0;
  dVar1 = I2C2_RTC_14080000.IC_CLR_INTR;
  I2C2_RTC_14080000.IC_TAR = param_1 >> 1 & 0x7f;
  uVar5 = param_4;
  if (7 < param_4) {
    uVar5 = 7;
  }
  I2C2_RTC_14080000.IC_ENABLE = 1;
  I2C2_RTC_14080000.IC_DATA_CMD = param_2 & 0xff;
  if (uVar5 == 0) {
    uVar5 = 0;
  }
  else {
    uVar3 = 0;
    do {
      I2C2_RTC_14080000.IC_DATA_CMD = (uint)*(byte *)(param_3 + uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  I2C2_RTC_14080000.IC_START = 1;
  for (; uVar5 < param_4; uVar5 = uVar5 + 1) {
    do {
      dVar1 = I2C2_RTC_14080000.IC_STATUS;
    } while ((dVar1 & 2) == 0);
    I2C2_RTC_14080000.IC_DATA_CMD = (uint)*(byte *)(param_3 + uVar5);
  }
  iVar4 = 0xffffe;
  do {
    busy_wait_delay_loop_4arg(1);
    dVar1 = I2C2_RTC_14080000.IC_STATUS;
    if ((dVar1 & 5) == 4) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  I2C2_RTC_14080000.IC_START = 0;
  I2C2_RTC_14080000.IC_ENABLE = 0;
  do {
    dVar1 = I2C2_RTC_14080000.IC_ENABLE_STATUS;
  } while ((dVar1 & 1) != 0);
  if (iVar4 == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

