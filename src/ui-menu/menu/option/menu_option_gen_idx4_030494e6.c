/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx4 @ 030494e6 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx4(void)

{
  ushort uVar1;
  uint uVar2;
  ushort *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  byte in_stack_00000008;
  
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
  uVar2 = uVar1 + 1;
  uVar1 = (ushort)uVar2;
  *unaff_r4 = uVar1;
  if ((in_stack_00000008 & 1) != 0) {
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 1;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x20) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 2;
    *unaff_r4 = uVar1 + 1;
  }
  if (((unaff_r6 == 1) || (unaff_r6 == 3)) && ((in_stack_00000008 & 0x40) != 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 3;
    *unaff_r4 = uVar1 + 1;
  }
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 4;
  *unaff_r4 = uVar1 + 1;
  menu_option_gen_noop_stub();
  return;
}

