/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx6 @ 03049930 (file base 0x03000000; code starts at 0x03001000)
 * Size: 502 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx6(void)

{
  ushort uVar1;
  uint uVar2;
  ushort *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  if ((in_stack_00000008 & 0x10000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x20000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 1;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000004 & 0x40000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 2;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x40000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 3;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x80000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 4;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x100000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 5;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x200000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 6;
    *unaff_r4 = uVar1 + 1;
  }
  if (((in_stack_00000008 & 0x400000) != 0) && ((unaff_r6 == 1 || (unaff_r6 == 3)))) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 7;
    *unaff_r4 = uVar1 + 1;
  }
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 8;
    *unaff_r4 = uVar1 + 1;
  }
  if ((in_stack_00000008 & 0x1000000) != 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 9;
    *unaff_r4 = uVar1 + 1;
  }
  if (((unaff_r6 == 1) || (unaff_r6 == 3)) && ((in_stack_00000008 & 0x2000000) != 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 10;
    *unaff_r4 = uVar1 + 1;
  }
  if (((p_dm32_settings_block04[0x2d] & 4) != 0) && ((in_stack_00000008 & 0x4000000) != 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xb;
    *unaff_r4 = uVar1 + 1;
  }
  if (((unaff_r6 == 1) || (unaff_r6 == 3)) && ((in_stack_00000008 & 0x8000000) != 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xc;
    *unaff_r4 = uVar1 + 1;
  }
  if (((p_dm32_settings_block04[0x2d] & 4) != 0) && ((in_stack_00000008 & 0x10000000) != 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xd;
    *unaff_r4 = uVar1 + 1;
  }
  if ((unaff_r6 == 0) || (unaff_r6 == 2)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xe;
    uVar2 = uVar1 + 1 & 0xffff;
    *(undefined1 *)(unaff_r5 + uVar2) = 0x10;
    uVar2 = uVar2 + 1 & 0xffff;
    *(undefined1 *)(unaff_r5 + uVar2) = 0x11;
    uVar2 = uVar2 + 1;
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 0x12;
    *unaff_r4 = (short)uVar2 + 1;
  }
  if ((unaff_r6 == 1) || (unaff_r6 == 3)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0xf;
    *unaff_r4 = uVar1 + 1;
  }
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0x13;
    uVar2 = uVar1 + 1;
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 0x14;
    *unaff_r4 = (short)uVar2 + 1;
  }
  if ((unaff_r6 != 1) && (unaff_r6 != 3)) {
    return;
  }
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0x15;
  *unaff_r4 = uVar1 + 1;
  menu_option_gen_noop_stub();
  return;
}

