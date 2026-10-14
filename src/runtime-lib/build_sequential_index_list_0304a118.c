/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: build_sequential_index_list @ 0304a118 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void build_sequential_index_list(ushort count,ushort *out_count,byte *out_list)

{
  ushort uVar1;
  
  if ((count & 0xff) != 0) {
    uVar1 = 0;
    do {
      *out_list = (byte)uVar1;
      uVar1 = uVar1 + 1 & 0xff;
      out_list = out_list + 1;
    } while (uVar1 < (count & 0xff));
  }
  *out_count = count & 0xff;
  return;
}

