/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_debounced_input_poll_a @ 0301306c (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_debounced_input_poll_a(void)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = keypad_read_pin_0x32_active_low();
  puVar2 = PTR_DAT_030131bc;
  *(char *)PTR_DAT_030131bc = (char)uVar3;
  if (*(byte *)((int)puVar2 + 1) == uVar3) {
    *(undefined1 *)PTR_DAT_030131c0 = 0;
  }
  else {
    cVar1 = *(char *)PTR_DAT_030131c0;
    *(byte *)PTR_DAT_030131c0 = cVar1 + 1U;
    if (3 < (byte)(cVar1 + 1U)) {
      *(undefined1 *)PTR_DAT_030131c0 = 0;
      if (uVar3 == 0) {
        event_queue_reset();
        (*(code *)(PTR_keypad_key_handler_table_030131c8[0x1f] & 0xfffffffe))();
        tx_led_or_tone_on();
      }
      else {
        key_event_state_clear_preserve_bit0();
        settings_set_menu_hold_interval(PTR_DAT_030131c4[0x3a]);
        event_queue_reset();
        (*(code *)(PTR_keypad_key_handler_table_030131c8[4] & 0xfffffffe))();
      }
      *(undefined1 *)((int)PTR_DAT_030131bc + 1) = *(undefined1 *)PTR_DAT_030131bc;
    }
  }
  return;
}

