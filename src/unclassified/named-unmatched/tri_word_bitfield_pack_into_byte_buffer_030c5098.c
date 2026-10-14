/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tri_word_bitfield_pack_into_byte_buffer @ 030c5098 (file base 0x03000000; code starts at 0x03001000)
 * Size: 242 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tri_word_bitfield_pack_into_byte_buffer(uint *param_1,int param_2,byte param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  if (param_3 < 6) {
    *(byte *)(param_2 + 7) =
         (byte)(*param_1 >> 0x15) & 1 | (byte)(*param_1 >> 0x10) & 0x10 | *(byte *)(param_2 + 7);
    *(byte *)(param_2 + 8) =
         (byte)(*param_1 >> 0x17) & 1 | (byte)((*param_1 & 0x400000) >> 0x12) |
         *(byte *)(param_2 + 8);
    puVar1 = param_1 + 1;
    *(byte *)(param_2 + 0x10) =
         (byte)(*puVar1 >> 0x15) & 1 | (byte)(*puVar1 >> 0x10) & 0x10 | *(byte *)(param_2 + 0x10);
    *(byte *)(param_2 + 0x11) =
         (byte)(*puVar1 >> 0x17) & 1 | (byte)((*puVar1 & 0x400000) >> 0x12) |
         *(byte *)(param_2 + 0x11);
    puVar2 = param_1 + 2;
    *(byte *)(param_2 + 0x19) =
         (byte)(*puVar2 >> 0x15) & 1 | (byte)(*puVar2 >> 0x10) & 0x10 | *(byte *)(param_2 + 0x19);
    *(byte *)(param_2 + 0x1a) =
         (byte)(*puVar2 >> 0x17) & 1 | (byte)((*puVar2 & 0x400000) >> 0x12) |
         *(byte *)(param_2 + 0x1a);
    *param_1 = *param_1 << 4;
    *puVar1 = *puVar1 << 4;
    *puVar2 = *puVar2 << 4;
  }
  return;
}

