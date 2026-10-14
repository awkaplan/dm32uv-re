/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: count_set_bits_in_flash_field @ 030559b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char count_set_bits_in_flash_field(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  byte *pbVar4;
  byte local_14 [4];
  byte abStack_10 [4];
  
  pbVar4 = local_14;
  flash_field_read_cached(0xf,0,local_14,5);
  cVar1 = '\0';
  do {
    uVar3 = (uint)*pbVar4;
    if (uVar3 != 0) {
      cVar2 = '\b';
      do {
        if ((uVar3 & 1) != 0) {
          cVar1 = cVar1 + '\x01';
        }
        uVar3 = uVar3 >> 1;
        cVar2 = cVar2 + -1;
      } while (cVar2 != '\0');
      *pbVar4 = (byte)uVar3;
    }
    pbVar4 = pbVar4 + 1;
  } while (pbVar4 != abStack_10);
  return cVar1;
}

