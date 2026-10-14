/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: field_pair_init_with_optional_string_copy @ 03041970 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void field_pair_init_with_optional_string_copy(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  
  uVar1 = p_text_entry_buffer;
  if (*(char *)PTR_DAT_03041a10 == '\x01') {
    string_copy_by_param_select(2,p_text_entry_buffer);
    cVar3 = strlen_ck803s(uVar1);
    *(char *)PTR_DAT_03041a40 = cVar3 + '\x01';
  }
  p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xfb | 4;
  init_field_pair_0x20_5();
  puVar2 = PTR_DAT_03041a48;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03041a48 + 1);
  *p_active_screen_option_ptr_array = *puVar2;
  *(undefined1 *)PTR_active_screen_subtype_03041a28 = *(undefined1 *)((int)puVar2 + 5);
  return;
}

