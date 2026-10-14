/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitmask_nth_set_bit_table_index @ 03023d00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char bitmask_nth_set_bit_table_index(byte param_1,char param_2)

{
  char cVar1;
  byte *pbVar2;
  char cVar3;
  
  cVar3 = '\0';
  cVar1 = '\x01';
  pbVar2 = PTR_DAT_03023e5c;
  while (((*pbVar2 & param_1) == 0 || (cVar3 = cVar3 + '\x01', cVar3 != param_2))) {
    cVar1 = cVar1 + '\x01';
    pbVar2 = pbVar2 + 1;
    if (cVar1 == '\t') {
      return '\0';
    }
  }
  return cVar1;
}

