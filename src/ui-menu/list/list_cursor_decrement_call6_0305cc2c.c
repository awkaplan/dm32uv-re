/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_decrement_call6 @ 0305cc2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_cursor_decrement_call6(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_0305ce0c;
  list_cursor_decrement(param_1,param_2,*(char *)PTR_DAT_0305ce0c + '\x01');
  list_screen_none_placeholder(*param_1,*param_2,*(char *)puVar1 + '\x01');
  return;
}

