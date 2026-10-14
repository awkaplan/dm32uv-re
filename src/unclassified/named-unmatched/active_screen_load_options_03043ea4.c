/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: active_screen_load_options @ 03043ea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
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

void active_screen_load_options(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = _DAT_03043f38;
  uVar3 = (byte)PTR_DAT_03043f34[0x30] >> 6 & 1;
  iVar4 = _DAT_03043f38 + uVar3 * 8;
  bVar1 = *(byte *)(iVar4 + 4);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *(undefined4 *)(iVar2 + uVar3 * 8);
  *(undefined1 *)PTR_active_screen_subtype_03043efc = *(undefined1 *)(iVar4 + 5);
  if (*(char *)PTR_DAT_03043f18 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  return;
}

