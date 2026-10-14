/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_page_tag_search @ 0300f52c (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_page_tag_search(char param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char local_25;
  
  if (param_1 == '\0') {
    uVar3 = *PTR_DAT_0300f694;
    uVar2 = *PTR_DAT_0300f698;
  }
  else if (param_1 == '\x01') {
    uVar3 = *PTR_DAT_0300f69c;
    uVar2 = *PTR_DAT_0300f6a0;
  }
  else {
    uVar2 = 0;
    uVar3 = 0;
  }
  uVar1 = uVar3 & 0xffff;
  if (uVar1 <= uVar2) {
    do {
      spi_flash_read_seq(uVar1,0xfff,&local_25,1);
      if (local_25 == param_2) {
        return uVar1;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 <= uVar2);
  }
  return uVar3;
}

