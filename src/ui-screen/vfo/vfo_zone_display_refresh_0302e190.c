/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_zone_display_refresh @ 0302e190 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_zone_display_refresh(void)

{
  vfo_freq_display_state *pvVar1;
  undefined2 uVar2;
  
  pvVar1 = p_vfo_freq_display_state;
  p_vfo_freq_display_state->flags_0x10 =
       p_vfo_freq_display_state->flags_0x10 & 0xe1 | (p_vfo_display_state->flags_0x8 >> 1 & 3) << 1
       | (p_vfo_display_state->flags_0x8 >> 4 & 3) << 3;
  uVar2 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
  *(undefined2 *)&pvVar1->field_0x58 = uVar2;
  return;
}

