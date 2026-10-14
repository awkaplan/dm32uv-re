/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dbyte_code_range_table_lookup @ 030110b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 768 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint dbyte_code_range_table_lookup(uint param_1,uint param_2)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  param_2 = param_2 & 0xff;
  uVar1 = param_1 << 8 | param_2;
  if (uVar1 < 0xd8a1) {
    if ((uVar1 + 0x4f5f & 0xffff) < 0x2759) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220
                            [((param_2 + param_1 * 0x5e) - 0x4141 & 0xffff) + 0x2f33];
    }
    else if ((uVar1 + 0x5e5e & 0xffff) < 0x5d) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x753a];
    }
    else if ((uVar1 + 0x5d5f & 0xffff) < 10) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x75dc];
    }
    else if ((uVar1 + 0x5d4f & 0xffff) < 0x3e) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x75e2];
    }
    else if ((uVar1 + 0x5d0f & 0xffff) < 0xc) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x75e6];
    }
    else if ((uVar1 + 0x5c5f & 0xffff) < 0x5d) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x768a];
    }
    else if ((uVar1 + 0x5b5f & 0xffff) < 0x53) {
      uVar1 = (uint)(ushort)PTR_LAB_03011220[uVar1 - 0x772d];
    }
    else if ((uVar1 + 0x5a5f & 0xffff) < 0x56) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x77da];
    }
    else if ((uVar1 + 0x595f & 0xffff) < 0x18) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7884];
    }
    else if ((uVar1 + 0x593f & 0xffff) < 0x18) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x788c];
    }
    else if ((uVar1 + 0x5920 & 0xffff) < 0xc) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7893];
    }
    else if ((uVar1 + 0x5912 & 0xffff) < 8) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7895];
    }
    else if ((uVar1 + 0x585f & 0xffff) < 0x21) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7941];
    }
    else if ((uVar1 + 0x582f & 0xffff) < 0x21) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7950];
    }
    else if ((uVar1 + 0x575f & 0xffff) < 0x20) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x79ff];
    }
    else if ((uVar1 + 0x573b & 0xffff) < 0x25) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x73ef];
    }
    else if ((uVar1 + 0x565c & 0xffff) < 0x4c) {
      uVar1 = (uint)(ushort)PTR_LAB_030113c4[uVar1 - 0x7abd];
    }
  }
  else {
    uVar1 = (uint)(ushort)PTR_LAB_03011220[((param_2 + param_1 * 0x5e) - 0x4ff1 & 0xffff) + 0x3dde];
  }
  return uVar1;
}

