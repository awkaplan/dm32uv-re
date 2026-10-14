/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: conditional_tone_dispatch_by_mode @ 0301a400 (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void conditional_tone_dispatch_by_mode(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = get_current_mode_state2();
  if (((((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) &&
       ((*(uint *)PTR_DAT_0301a528 & 0x18000) != 0x8000)) && (*(char *)PTR_DAT_0301a520 == '\0')) &&
     ((iVar2 = read_byte_field_0302e118(), iVar2 == 0 &&
      (iVar2 = get_current_mode_state1(), iVar2 == 0)))) {
    if (iVar1 == 3) {
      display_draw_tone_mode_icon(PTR_DAT_0301a52c[1] & 1,p_vfo_display_state->flags_0x8 >> 4,0x7ff)
      ;
    }
    else if ((iVar1 == 0) &&
            ((iVar1 = get_field_0301ea64_0x14(), iVar1 != 0 ||
             (iVar1 = read_byte_field_0305fca8(), iVar1 != 0)))) {
      display_draw_tone_mode_icon
                ((byte)p_dm32_settings_block04[0x2d] >> 7,p_vfo_display_state->flags_0x8 >> 4,0x7ff)
      ;
    }
  }
  return;
}

