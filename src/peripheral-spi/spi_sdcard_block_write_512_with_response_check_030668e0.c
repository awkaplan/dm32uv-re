/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_sdcard_block_write_512_with_response_check @ 030668e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-spi
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 spi_sdcard_block_write_512_with_response_check(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte abStack_14 [4];
  char acStack_10 [4];
  
  iVar1 = poll_flag_until_ff_or_timeout();
  if (iVar1 == 0) {
    acStack_10[0] = param_2;
    spi_controller_byte_xfer(1,1,acStack_10,1);
    if (param_2 == -3) {
      uVar2 = 0;
    }
    else {
      spi_controller_byte_xfer(1,1,param_1,0x200);
      acStack_10[0] = -1;
      spi_controller_byte_xfer(1,1,acStack_10,1);
      spi_controller_byte_xfer(1,1,acStack_10,1);
      spi_controller_byte_xfer_rdwr(1,1,abStack_14,1,acStack_10,0);
      if ((abStack_14[0] & 0x1f) == 5) {
        uVar2 = 0;
      }
      else {
        uVar2 = 2;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

