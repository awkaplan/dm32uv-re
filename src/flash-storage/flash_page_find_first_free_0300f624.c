/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_page_find_first_free @ 0300f624 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort flash_page_find_first_free(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  char local_1d;
  
  if (param_1 == '\0') {
    uVar2 = *(ushort *)PTR_DAT_0300f694;
    uVar4 = *(ushort *)PTR_DAT_0300f698;
  }
  else if (param_1 == '\x01') {
    uVar2 = *(ushort *)PTR_DAT_0300f69c;
    uVar4 = *(ushort *)PTR_DAT_0300f6a0;
  }
  else {
    uVar4 = 0;
    uVar2 = 0;
  }
  if (uVar2 <= uVar4) {
    uVar3 = uVar2;
    do {
      spi_flash_read_seq(uVar3,0xfff,&local_1d,1);
      uVar1 = uVar3;
      if ((local_1d != '\0') && (uVar1 = uVar2, local_1d == -1)) {
        return uVar3;
      }
      uVar2 = uVar1;
      uVar3 = uVar3 + 1;
    } while (uVar3 <= uVar4);
  }
  return uVar2;
}

