/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block_record_template_load_id0x6c_03048466 @ 03048466 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void block_record_template_load_id0x6c_03048466(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_0304848c;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_0304848c + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03048498 = *(undefined1 *)((int)puVar1 + 5);
  *(undefined1 *)PTR_DAT_0304849c = 0x6c;
  *(undefined1 *)p_active_screen_state_word = PTR_DAT_030484a0[8];
  return;
}

