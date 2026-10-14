/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sdcard_data_block_read @ 03066ca8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int sdcard_data_block_read(int param_1,int param_2,int param_3__w)

{
  char param_3 = (char)param_3__w;
  int iVar1;
  
  os_sem_pend_ms(DAT_03066de8,0);
  if (PTR_DAT_03066de4[4] != '\x06') {
    param_2 = param_2 << 9;
  }
  if (param_3 == '\x01') {
    iVar1 = spi_sdcard_send_command(0x11,param_2,1);
    if (iVar1 == 0) {
      iVar1 = spi_sdcard_sync_byte_probe(param_1,0x200);
    }
  }
  else {
    spi_sdcard_send_command(0x12,param_2,1);
    do {
      iVar1 = spi_sdcard_sync_byte_probe(param_1,0x200);
      param_1 = param_1 + 0x200;
      param_3 = param_3 + -1;
      if (param_3 == '\0') break;
    } while (iVar1 == 0);
    spi_sdcard_send_command(0xc,0,1);
  }
  spi_sdcard_read_status_register();
  os_sem_post(DAT_03066de8);
  return iVar1;
}

