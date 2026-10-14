/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zero_bit_count_13byte_prefix @ 03052d04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char zero_bit_count_13byte_prefix(int param_1)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  uVar4 = 0;
  cVar1 = '\0';
  do {
    uVar2 = (uint)*(byte *)(param_1 + uVar4);
    cVar3 = '\0';
    while( true ) {
      if (((uVar4 & 0xff) == 0xc) && (cVar3 == '\x04')) {
        return cVar1;
      }
      if ((uVar2 & 1) == 0) {
        cVar1 = cVar1 + '\x01';
      }
      cVar3 = cVar3 + '\x01';
      if (cVar3 == '\b') break;
      uVar2 = uVar2 >> 1;
    }
    uVar4 = uVar4 + 1;
    if (uVar4 == 0xd) {
      return cVar1;
    }
  } while( true );
}

