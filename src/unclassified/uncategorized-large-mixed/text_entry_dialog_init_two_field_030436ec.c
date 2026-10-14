/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_dialog_init_two_field @ 030436ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_dialog_init_two_field(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  
  uVar1 = p_text_entry_buffer;
  cVar3 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_030437b8 + 2);
  if (cVar3 == '\0') {
    dialog_request_init(0x10);
    uVar1 = p_text_entry_buffer;
    if (*(char *)PTR_DAT_030437bc == '\x01') {
      string_copy_by_param_select(1,p_text_entry_buffer);
      cVar3 = strlen_ck803s(uVar1);
      *(char *)PTR_DAT_030437c4 = cVar3 + '\x01';
    }
    puVar2 = PTR_DAT_030437c8;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030437c8 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_030437a0 = *(undefined1 *)((int)puVar2 + 5);
  }
  else if (cVar3 == '\x01') {
    if (*(char *)PTR_DAT_030437bc == '\x01') {
      string_copy_by_param_select(2,p_text_entry_buffer);
      cVar3 = strlen_ck803s(uVar1);
      *(char *)PTR_DAT_030437c4 = cVar3 + '\x01';
    }
    init_field_pair_0x20_5();
    puVar2 = PTR_DAT_030437cc;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030437cc + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_030437a0 = *(undefined1 *)((int)puVar2 + 5);
  }
  return;
}

