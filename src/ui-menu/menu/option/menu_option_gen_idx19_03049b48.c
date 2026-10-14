/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx19 @ 03049b48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx19(void)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  ushort *unaff_r4;
  int unaff_r5;
  uint in_stack_00000004;
  
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
  uVar3 = uVar1 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar3) = 1;
  uVar3 = uVar3 + 1;
  uVar1 = (ushort)uVar3;
  *unaff_r4 = uVar1;
  if ((in_stack_00000004 & 0x80000) != 0) {
    *(undefined1 *)(unaff_r5 + (uVar3 & 0xffff)) = 2;
    *unaff_r4 = uVar1 + 1;
  }
  cVar2 = '\x04';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar2;
    uVar3 = uVar1 + 1;
    uVar1 = (ushort)uVar3;
    *unaff_r4 = uVar1;
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\n');
  if (SUBPIECE(in_stack_00000004, 2, 1) < '\0') {
    *(undefined1 *)(unaff_r5 + (uVar3 & 0xffff)) = 0xb;
    *unaff_r4 = uVar1 + 1;
  }
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xc;
  uVar3 = uVar1 + 1;
  uVar1 = (ushort)uVar3;
  *unaff_r4 = uVar1;
  if ((in_stack_00000004 & 0x100000) != 0) {
    *(undefined1 *)(unaff_r5 + (uVar3 & 0xffff)) = 0xd;
    *unaff_r4 = uVar1 + 1;
  }
  cVar2 = '\x0e';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar2;
    *unaff_r4 = uVar1 + 1;
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\x12');
  menu_option_gen_noop_stub();
  return;
}

