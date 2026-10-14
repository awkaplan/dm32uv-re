/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx25 @ 03049e30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx25(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
  uVar2 = uVar1 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar2) = 1;
  uVar2 = uVar2 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar2) = 2;
  uVar2 = uVar2 + 1;
  uVar3 = uVar2 & 0xffff;
  *unaff_r4 = (ushort)uVar2;
  if ((unaff_r6 != 0) && (unaff_r6 != 2)) {
    return;
  }
  *(undefined1 *)(unaff_r5 + uVar3) = 3;
  uVar2 = uVar3 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar2) = 4;
  uVar2 = uVar2 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar2) = 5;
  uVar2 = uVar2 + 1;
  *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 6;
  *unaff_r4 = (short)uVar2 + 1;
  menu_option_gen_noop_stub();
  return;
}

