/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flags_bit67_lookup_table_read @ 03042492 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flags_bit67_lookup_table_read(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_PTR_0304253c;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_0304253c + uVar3 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03042530 = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5);
  if (*(char *)PTR_DAT_03042518 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  return;
}

