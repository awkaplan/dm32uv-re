/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bit_pattern_match_count_with_position_gate @ 03023d30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char bit_pattern_match_count_with_position_gate(byte param_1,char param_2)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  
  cVar1 = '\0';
  cVar2 = '\x01';
  pbVar3 = PTR_DAT_03023e5c;
  while (((*pbVar3 & param_1) == 0 || (cVar1 = cVar1 + '\x01', cVar2 != param_2))) {
    cVar2 = cVar2 + '\x01';
    pbVar3 = pbVar3 + 1;
    if (cVar2 == '\t') {
      return '\0';
    }
  }
  return cVar1;
}

