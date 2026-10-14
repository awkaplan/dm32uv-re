/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_mode_state_icon_blit_0x6b @ 0304c5fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_mode_state_icon_blit_0x6b(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = vfo_active_side_mode_nibble();
  if ((((*(char *)PTR_DAT_0304c71c == '\0') || (*(char *)PTR_DAT_0304c71c == '[')) ||
      (*(char *)PTR_DAT_0304c71c == 'F')) || (*(char *)PTR_DAT_0304c71c == 'M')) {
    uVar2 = get_current_mode_state1();
    if (1 < uVar2) {
      uVar1 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
    }
    if (((uVar1 == 1) || (uVar1 == 3)) && (*(char *)PTR_DAT_0304c724 != '\0')) {
      if ((PTR_DAT_0304c728[1] & 0x20) == 0) {
        display_blit_image(0x6b,5,0x15,0xf,PTR_LAB_0304c72c);
      }
      else {
        display_blit_image(0x6b,5,0x15,0xf,PTR_LAB_0304c72c);
      }
    }
  }
  return;
}

