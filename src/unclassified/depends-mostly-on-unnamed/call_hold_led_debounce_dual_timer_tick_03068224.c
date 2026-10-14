/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_hold_led_debounce_dual_timer_tick @ 03068224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_hold_led_debounce_dual_timer_tick(void)

{
  char cVar1;
  
  if (PTR_DAT_030682a8[6] != '\0') {
    if (((PTR_DAT_030682b4[1] & 1) == 0) && ((*(byte *)p_call_active_flag & 0xc) != 0)) {
      backup_or_restore_slot_from_scratch(0);
    }
    cVar1 = PTR_DAT_030682a8[6];
    PTR_DAT_030682a8[6] = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xf7;
    }
  }
  if (PTR_DAT_030682a8[7] != '\0') {
    if (((PTR_DAT_030682b4[1] & 1) != 0) && ((*(byte *)p_call_active_flag & 0xc) != 0)) {
      backup_or_restore_slot_from_scratch(1);
    }
    cVar1 = PTR_DAT_030682a8[7];
    PTR_DAT_030682a8[7] = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xef;
    }
  }
  return;
}

