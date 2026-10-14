/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx13 @ 0304988c (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx13(void)

{
  ushort uVar1;
  uint uVar2;
  ushort *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
  uVar2 = uVar1 + 1;
  uVar1 = (ushort)uVar2;
  *unaff_r4 = uVar1;
  if ((p_dm32_settings_block04[0x2d] & 4) != 0) {
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 1;
    *unaff_r4 = uVar1 + 1;
    if ((p_dm32_settings_block04[0x2d] & 4) != 0) goto LAB_030498f8;
  }
  if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 2;
    uVar2 = uVar1 + 1 & 0xffff;
    *(undefined1 *)(unaff_r5 + uVar2) = 3;
    uVar2 = uVar2 + 1;
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 4;
    *unaff_r4 = (short)uVar2 + 1;
  }
LAB_030498f8:
  if ((unaff_r6 == 0) && ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
    uVar1 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar1) = 5;
    uVar2 = uVar1 + 1 & 0xffff;
    *(undefined1 *)(unaff_r5 + uVar2) = 6;
    uVar2 = uVar2 + 1;
    *(undefined1 *)(unaff_r5 + (uVar2 & 0xffff)) = 7;
    *unaff_r4 = (short)uVar2 + 1;
    menu_option_gen_noop_stub();
    return;
  }
  return;
}

