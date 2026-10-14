/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx21 @ 03049c00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx21(void)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  ushort *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  uint in_stack_00000004;
  
  cVar3 = '\0';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar3;
    uVar2 = uVar1 + 1;
    uVar1 = (ushort)uVar2;
    *unaff_r4 = uVar1;
    cVar3 = cVar3 + '\x01';
  } while (cVar3 != '\n');
  if ((in_stack_00000004 & 0x2000000) != 0) {
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 0xc;
    *unaff_r4 = uVar1 + 1;
  }
  cVar3 = '\r';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar3;
    uVar2 = uVar1 + 1;
    uVar1 = (ushort)uVar2;
    *unaff_r4 = uVar1;
    cVar3 = cVar3 + '\x01';
  } while (cVar3 != '\x11');
  if (((unaff_r6 == 0) || ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)) ||
     ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) != 0)) {
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 0x11;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000004 & 0x1000000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0x12;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000004 & 0x200000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0x13;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000004 & 0x400000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0x14;
    *unaff_r4 = uVar1 + 1;
    menu_option_gen_noop_stub();
    return;
  }
  return;
}

