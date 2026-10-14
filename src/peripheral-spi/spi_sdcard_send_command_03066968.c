/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_sdcard_send_command @ 03066968 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-spi
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char spi_sdcard_send_command(byte param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  char cVar2;
  char local_24 [4];
  byte local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  
  if (*(char *)PTR_DAT_03066ad8 == '\0') {
    spi_sdcard_read_status_register();
  }
  iVar1 = spi_sdcard_select_and_wait_ready();
  if (iVar1 == 0) {
    local_20 = param_1 | 0x40;
    uStack_1f = (undefined1)((uint)param_2 >> 0x18);
    uStack_1e = (undefined1)((uint)param_2 >> 0x10);
    uStack_1d = (undefined1)((uint)param_2 >> 8);
    uStack_1c = (undefined1)param_2;
    uStack_1b = param_3;
    spi_controller_byte_xfer(1,1,&local_20,6);
    local_20 = 0xff;
    if (param_1 == 0xc) {
      spi_controller_byte_xfer(1,1,&local_20,1);
    }
    cVar2 = '\x1f';
    while( true ) {
      spi_controller_byte_xfer_rdwr(1,1,local_24,1,&local_20,0);
      if ((-1 < local_24[0]) || (cVar2 == '\0')) break;
      cVar2 = cVar2 + -1;
    }
  }
  else {
    local_24[0] = -1;
  }
  return local_24[0];
}

