/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx14 @ 030496a2 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx14(void)

{
  ushort uVar1;
  int iVar2;
  ushort *unaff_r4;
  int unaff_r5;
  undefined4 in_stack_00000000;
  byte in_stack_00000008;
  
  uVar1 = *unaff_r4;
  *(undefined1 *)(unaff_r5 + (uint)uVar1) = 0;
  *unaff_r4 = uVar1 + 1;
  if (*(byte *)PTR_PTR_030497f0 < 5) {
    if (*(byte *)PTR_PTR_030497f0 == 3) {
      flash_field_read_cached
                (0xb,(*(short *)PTR_DAT_030497f4 + 0x80) * 2,(int)&stack0x00000000 + 2,2);
      SUBPIECE_SET(in_stack_00000000, 2, 2, SUBPIECE(in_stack_00000000, 2, 2) & 0xfff);
      if ((*(ushort *)&p_vfo_display_state->field_0x31_0 == 0) ||
         (SUBPIECE(in_stack_00000000, 2, 2) != *(ushort *)&p_vfo_display_state->field_0x31_0)) {
        if ((in_stack_00000008 & 2) != 0) {
          uVar1 = *unaff_r4;
          *(undefined1 *)(unaff_r5 + (uint)uVar1) = 2;
          *unaff_r4 = uVar1 + 1;
        }
        if ((in_stack_00000008 & 4) != 0) {
          uVar1 = *unaff_r4;
          *(undefined1 *)(unaff_r5 + (uint)uVar1) = 3;
          *unaff_r4 = uVar1 + 1;
        }
      }
    }
    if ((in_stack_00000008 & 8) != 0) {
      uVar1 = *unaff_r4;
      *(undefined1 *)(unaff_r5 + (uint)uVar1) = 4;
      *unaff_r4 = uVar1 + 1;
    }
    if (((*(char *)PTR_PTR_030497f0 == '\x03') && (iVar2 = scan_feature_enabled(0), iVar2 != 0)) &&
       ((in_stack_00000008 & 0x10) != 0)) {
      uVar1 = *unaff_r4;
      *(undefined1 *)(unaff_r5 + (uint)uVar1) = 5;
      *unaff_r4 = uVar1 + 1;
      menu_option_gen_noop_stub();
      return;
    }
  }
  return;
}

