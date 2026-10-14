/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx31 @ 03049e9a (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx31(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *unaff_r4;
  int unaff_r5;
  
  iVar1 = tone_signaling_type_classify(*(undefined2 *)&p_vfo_display_state->field_0x11_0);
  if (iVar1 == 0) {
    uVar2 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar2) = 0;
    uVar3 = uVar2 + 1;
    uVar2 = (ushort)uVar3;
    *unaff_r4 = uVar2;
    if ((p_vfo_display_state->field_0x16 >> 1 & 7) != 0) {
      *(undefined1 *)(unaff_r5 + (uVar3 & 0xffff)) = 1;
      *unaff_r4 = uVar2 + 1;
      menu_option_gen_noop_stub();
      return;
    }
  }
  else {
    uVar2 = *unaff_r4;
    *(undefined1 *)(unaff_r5 + (uint)uVar2) = 0;
    uVar3 = uVar2 + 1;
    uVar4 = uVar3 & 0xffff;
    *unaff_r4 = (ushort)uVar3;
    if ((p_vfo_display_state->field_0x16 >> 1 & 7) != 0) {
      *(undefined1 *)(unaff_r5 + uVar4) = 1;
      uVar3 = uVar4 + 1 & 0xffff;
      *(undefined1 *)(unaff_r5 + uVar3) = 2;
      uVar3 = uVar3 + 1;
      *(undefined1 *)(unaff_r5 + (uVar3 & 0xffff)) = 3;
      *unaff_r4 = (short)uVar3 + 1;
      menu_option_gen_noop_stub();
      return;
    }
  }
  return;
}

