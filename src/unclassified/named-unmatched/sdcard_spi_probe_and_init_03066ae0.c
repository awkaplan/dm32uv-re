/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sdcard_spi_probe_and_init @ 03066ae0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 452 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int sdcard_spi_probe_and_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  undefined1 auStack_30 [4];
  byte abStack_2c [2];
  char cStack_2a;
  char cStack_29;
  
  modem_c7000_param_table_defaults_init();
  table_entry_write_field_0x14_arg1h_10h();
  memset_bytes(abStack_2c,0xff,10);
  spi_controller_byte_xfer(1,1,abStack_2c,10);
  sVar5 = 0x14;
  while (iVar2 = spi_sdcard_send_command(0,0,0x95), iVar2 != 1) {
    if (sVar5 == 0) {
      PTR_DAT_03066de4[4] = 0;
      goto LAB_03066c7a;
    }
    sVar5 = sVar5 + -1;
  }
  *(undefined1 *)(PTR_DAT_03066c94 + 1) = 0;
  iVar3 = spi_sdcard_send_command(8,0x1aa,0x87);
  if (iVar3 == 1) {
    auStack_30[0] = 0xff;
    spi_controller_byte_xfer_rdwr(1,1,abStack_2c,4,auStack_30,0);
    if ((cStack_2a == '\x01') && (cStack_29 == -0x56)) {
      sVar5 = -2;
      do {
        spi_sdcard_send_command(0x37,0,1);
        iVar2 = spi_sdcard_send_command(0x29,0x40000000,1);
        if (iVar2 == 0) {
          if (sVar5 == 0) goto LAB_03066c7a;
          break;
        }
        sVar5 = sVar5 + -1;
      } while (sVar5 != -1);
      iVar3 = spi_sdcard_send_command(0x3a,0,1);
      if (iVar3 == 0) {
        spi_controller_byte_xfer_rdwr(1,1,abStack_2c,4,auStack_30,0);
        if ((abStack_2c[0] & 0x40) == 0) {
          *(undefined1 *)(PTR_DAT_03066c94 + 1) = 4;
        }
        else {
          *(undefined1 *)(PTR_DAT_03066c94 + 1) = 6;
        }
      }
    }
    goto LAB_03066c7a;
  }
  spi_sdcard_send_command(0x37,0,1);
  uVar4 = spi_sdcard_send_command(0x29,0,1);
  if (uVar4 < 2) {
    *(undefined1 *)(PTR_DAT_03066c94 + 1) = 2;
    sVar5 = -2;
    do {
      spi_sdcard_send_command(0x37,0,1);
      iVar2 = spi_sdcard_send_command(0x29,0,1);
      if (iVar2 == 0) goto LAB_03066c60;
      sVar5 = sVar5 + -1;
    } while (sVar5 != -1);
  }
  else {
    *(undefined1 *)(PTR_DAT_03066c94 + 1) = 1;
    sVar5 = -2;
    do {
      iVar2 = spi_sdcard_send_command(1,0,1);
      if (iVar2 == 0) goto LAB_03066c60;
      sVar5 = sVar5 + -1;
    } while (sVar5 != -1);
  }
LAB_03066c64:
  iVar3 = spi_sdcard_send_command(0x10,0x200,1);
  if (iVar3 == 0) goto LAB_03066c7a;
LAB_03066c74:
  *(undefined1 *)(PTR_DAT_03066c94 + 1) = 0;
LAB_03066c7a:
  spi_sdcard_read_status_register();
  puVar1 = PTR_DAT_03066c94;
  *(undefined1 *)PTR_DAT_03066c94 = 1;
  if (*(char *)(puVar1 + 1) == '\0') {
    if (iVar2 == 0) {
      iVar2 = 0xaa;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
LAB_03066c60:
  if (sVar5 != 0) goto LAB_03066c64;
  goto LAB_03066c74;
}

