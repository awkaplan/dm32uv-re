/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talkgroup_index_decode_paged @ 03033310 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talkgroup_index_decode_paged(uint param_1,ushort *param_2,undefined1 *param_3)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar1 = (ushort)((param_1 & 0xffff) / 0xaa) & 0xff;
  uVar3 = (param_1 & 0xffff) % 0xaa;
  if (uVar3 == 0) {
    *param_2 = uVar1 + 0x43 & 0xff;
    uVar2 = 0xaa;
  }
  else {
    *param_2 = uVar1 + 0x44 & 0xff;
    uVar2 = (undefined1)uVar3;
  }
  *param_3 = uVar2;
  return;
}

