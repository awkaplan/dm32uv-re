/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recent_value_list_append_to_flash @ 03055cc0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void recent_value_list_append_to_flash(ushort param_1,undefined4 param_2)

{
  uint uVar1;
  short sVar2;
  undefined1 auStack_70 [96];
  
  sVar2 = ((param_1 & 0xff) - 1) * 0x6d + 0x1c;
  flash_field_read_cached(0xf,sVar2,auStack_70,0x60);
  uVar1 = (uint)(byte)(*(char *)PTR_DAT_03055e4c * '\x03');
  auStack_70[uVar1] = (char)param_2;
  auStack_70[uVar1 + 1] = (char)((uint)param_2 >> 8);
  auStack_70[uVar1 + 2] = (char)((uint)param_2 >> 0x10);
  uVar1 = uVar1 + 3 & 0xff;
  if (uVar1 < 0x5e) {
    auStack_70[uVar1] = 0;
    auStack_70[uVar1 + 1] = 0;
    auStack_70[uVar1 + 2] = 0;
  }
  flash_block_write(0xf,sVar2,auStack_70,0x60);
  return;
}

