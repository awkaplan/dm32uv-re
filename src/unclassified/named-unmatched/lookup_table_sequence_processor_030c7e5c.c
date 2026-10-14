/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lookup_table_sequence_processor @ 030c7e5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint lookup_table_sequence_processor(undefined4 param_1,short param_2,short param_3)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  short *unaff_r8;
  
  if (param_3 == 0) {
    uVar3 = 0;
    uVar4 = uVar3;
  }
  else {
    if (param_2 == 0) {
      uVar4 = 0x48;
      uVar3 = 4;
      unaff_r8 = _FUN_030c7ed8;
    }
    else {
      uVar4 = 0x31;
      uVar3 = 3;
      unaff_r8 = _FUN_030c7ed4;
    }
    sVar1 = 0;
    psVar2 = unaff_r8;
    do {
      sVar1 = sVar1 + 1;
      param_1 = unpack_bits_lsb_first_to_u16_array_signed((int)*psVar2,param_1,0x10);
      psVar2 = psVar2 + 1;
    } while ((int)sVar1 < (int)uVar3);
  }
  if ((uVar4 & 9) != 0) {
    unpack_bits_lsb_first_to_u16_array_signed((int)unaff_r8[uVar3],param_1);
  }
  return uVar4;
}

