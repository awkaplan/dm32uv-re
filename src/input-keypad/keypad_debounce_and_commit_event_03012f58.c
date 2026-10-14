/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_debounce_and_commit_event @ 03012f58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypad_debounce_and_commit_event(void)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = bitwise_not_of_boolean_result();
  puVar2 = PTR_keypad_confirmed_key_cur_03013018;
  PTR_keypad_confirmed_key_cur_03013018[2] = (char)uVar3;
  if ((byte)puVar2[3] == uVar3) {
    *(undefined1 *)PTR_DAT_0301301c = 0;
  }
  else {
    cVar1 = *(char *)PTR_DAT_0301301c;
    *(byte *)PTR_DAT_0301301c = cVar1 + 1U;
    if (3 < (byte)(cVar1 + 1U)) {
      *(undefined1 *)PTR_DAT_0301301c = 0;
      if (uVar3 == 0) {
        if ((*(byte *)PTR_DAT_03013048 & 2) == 0) {
          *(byte *)PTR_DAT_0301304c = *(byte *)PTR_DAT_0301304c & 0xfb | 4;
          *(byte *)((int)PTR_DAT_0301301c + 1) = *(byte *)((int)PTR_DAT_0301301c + 1) & 0xfe;
          PTR_DAT_03013050[8] = 0;
        }
        event_queue_reset();
        (*(code *)(PTR_keypad_key_handler_table_03013058[0x1c] & 0xfffffffe))();
      }
      else {
        if ((*(byte *)PTR_DAT_03013048 & 2) == 0) {
          *(byte *)PTR_DAT_0301304c = *(byte *)PTR_DAT_0301304c & 0xfd | 2;
          *(byte *)((int)PTR_DAT_0301301c + 1) = *(byte *)((int)PTR_DAT_0301301c + 1) & 0xfe;
          PTR_DAT_03013050[7] = 0;
        }
        key_event_state_clear_preserve_bit0();
        settings_set_menu_hold_interval(PTR_DAT_03013054[0x3a]);
        event_queue_reset();
        *(byte *)(PTR_DAT_03013048 + 1) = *(byte *)(PTR_DAT_03013048 + 1) & 0xf7 | 8;
        (*(code *)(PTR_keypad_key_handler_table_03013058[1] & 0xfffffffe))();
      }
      PTR_keypad_confirmed_key_cur_03013018[3] = PTR_keypad_confirmed_key_cur_03013018[2];
    }
  }
  return;
}

