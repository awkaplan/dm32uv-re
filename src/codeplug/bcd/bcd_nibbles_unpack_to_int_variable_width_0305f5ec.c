/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_nibbles_unpack_to_int_variable_width @ 0305f5ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short bcd_nibbles_unpack_to_int_variable_width(ushort *param_1,char param_2)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = *param_1;
  param_2 = param_2 + '\x04';
  sVar1 = 0;
  do {
    sVar1 = sVar1 * 10 + (uVar2 >> 0xc);
    uVar2 = uVar2 << 4;
    param_2 = param_2 + -1;
  } while (param_2 != '\0');
  return sVar1;
}

