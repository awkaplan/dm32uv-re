/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: name_tag_encoded_length_table_lookup @ 0301104c (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int name_tag_encoded_length_table_lookup(uint param_1)

{
  int iVar1;
  
  iVar1 = flash_table_binary_search_exact_match(PTR_LAB_03011220,0,99,(param_1 & 0xffff) >> 8);
  if (iVar1 == 0xffff) {
    iVar1 = 0;
  }
  else {
    iVar1 = flash_table_binary_search_exact_match
                      (PTR_LAB_03011220 + 0x96,
                       ((uint)*(byte *)((int)PTR_LAB_03011220 + iVar1 + 1) * 0x100 +
                       (uint)*(byte *)((int)PTR_LAB_03011220 + iVar1 + 2)) / 3,
                       ((uint)*(byte *)((int)PTR_LAB_03011220 + iVar1 + 4) * 0x100 +
                       (uint)*(byte *)((int)PTR_LAB_03011220 + iVar1 + 5)) / 3,param_1 & 0xff);
    if (iVar1 == 0xffff) {
      iVar1 = 0;
    }
    else {
      iVar1 = (uint)(byte)PTR_LAB_03011224[iVar1 + 1] * 0x100 +
              (uint)(byte)PTR_LAB_03011224[iVar1 + 2];
    }
  }
  return iVar1;
}

