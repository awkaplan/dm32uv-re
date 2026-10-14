/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx33 @ 03049654 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx33(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  ushort *unaff_r4;
  int unaff_r5;
  
  cVar4 = '\0';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar4;
    *unaff_r4 = uVar1 + 1;
    cVar4 = cVar4 + '\x01';
  } while (cVar4 != '\x05');
  cVar4 = '\x06';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar4;
    uVar2 = uVar1 + 1;
    uVar3 = uVar2 & 0xffff;
    *unaff_r4 = (ushort)uVar2;
    cVar4 = cVar4 + '\x01';
  } while (cVar4 != '\'');
  *(undefined1 *)(unaff_r5 + uVar3) = 0x28;
  uVar2 = uVar3 + 1 & 0xffff;
  *(undefined1 *)(unaff_r5 + uVar2) = 0x29;
  uVar2 = uVar2 + 1;
  *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 0x2a;
  *unaff_r4 = (short)uVar2 + 1;
  menu_option_gen_noop_stub();
  return;
}

