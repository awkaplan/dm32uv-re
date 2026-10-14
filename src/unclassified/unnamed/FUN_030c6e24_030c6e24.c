/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c6e24 @ 030c6e24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

uint FUN_030c6e24(uint param_1)

{
  dword dVar1;
  
  do {
    dVar1 = SSI_Type_14150000.SR;
  } while ((dVar1 & 2) == 0);
  SSI_Type_14150000.DR = param_1 & 0xffff;
  do {
    dVar1 = SSI_Type_14150000.SR;
  } while ((dVar1 & 4) == 0);
  do {
    dVar1 = SSI_Type_14150000.SR;
  } while ((dVar1 & 1) != 0);
  dVar1 = SSI_Type_14150000.DR;
  return dVar1 & 0xffff;
}

