/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_record_template_load_id0x5e @ 03044a28 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void zone_record_template_load_id0x5e(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03044ae8;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03044ae8 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03044acc = *(undefined1 *)((int)puVar1 + 5);
  *(undefined1 *)PTR_DAT_03044aec = 0x5e;
  *(undefined1 *)p_active_screen_state_word = p_dm32_settings_block04[0x5f];
  return;
}

