/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_and_state_reset @ 030436c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_and_state_reset(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_03043794;
  *(undefined1 *)p_active_screen_option_count = PTR_DAT_03043794[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
  *(undefined1 *)PTR_active_screen_subtype_030437a0 = puVar1[5];
  *(undefined1 *)PTR_DAT_030437a4 = 1;
  *(undefined2 *)p_active_screen_index_list = 2;
  *(undefined1 *)p_active_screen_state_word = 0;
  *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
  return;
}

