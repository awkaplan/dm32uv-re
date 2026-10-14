/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_lock_icon_update @ 0302e80c (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_lock_icon_update(undefined1 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  if (p_vfo_freq_display_state->field_0x1 < 0x10) {
    uVar1 = flash_field_find_nth_matching_value_wrapper(param_2);
    channel_lock_flag_bit_set_in_block11(param_1,uVar1);
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0302e928 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_0302e924 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  return;
}

