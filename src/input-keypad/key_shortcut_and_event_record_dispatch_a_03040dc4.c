/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_shortcut_and_event_record_dispatch_a @ 03040dc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 358 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void key_shortcut_and_event_record_dispatch_a(void)

{
  key_shortcut_dispatch_table();
  if ((PTR_DAT_03040ef0[8] & 4) != 0) {
    if ((PTR_DAT_03040ef0[8] & 0x20) == 0) {
      write_event_record_and_notify(*p_active_screen_state_word + '\x10',PTR_DAT_03040ef4[0x47]);
    }
    else {
      write_event_record_and_notify(PTR_DAT_03040ef4[0x48] + '\x10',*p_active_screen_state_word);
    }
  }
  if ((PTR_DAT_03040ef0[7] & 0x80) != 0) {
    if ((PTR_DAT_03040ef0[8] & 0x20) == 0) {
      write_event_record_and_notify(*p_active_screen_state_word + '\x05',PTR_DAT_03040ef4[0x47]);
    }
    else {
      write_event_record_and_notify(PTR_DAT_03040ef4[0x4a] + '\x05',*p_active_screen_state_word);
    }
  }
  if ((PTR_DAT_03040ef0[8] & 1) != 0) {
    if ((PTR_DAT_03040ef0[8] & 0x20) == 0) {
      write_event_record_and_notify(*p_active_screen_state_word,PTR_DAT_03040ef4[0x47]);
    }
    else {
      write_event_record_and_notify(PTR_DAT_03040ef4[0x4c],*p_active_screen_state_word);
    }
  }
  if ((PTR_DAT_03040ef0[8] & 2) != 0) {
    if ((PTR_DAT_03040ef0[8] & 0x20) == 0) {
      write_event_record_and_notify(*p_active_screen_state_word,PTR_DAT_03040ef4[0x47]);
    }
    else {
      write_event_record_and_notify(PTR_DAT_03040ef4[0x4e],*p_active_screen_state_word);
    }
  }
  if ((PTR_DAT_03040ef0[8] & 8) != 0) {
    if ((PTR_DAT_03040ef0[8] & 0x20) == 0) {
      write_event_record_and_notify
                (*(undefined1 *)p_active_screen_state_word,PTR_DAT_03040ff8[0x47]);
    }
    else {
      write_event_record_and_notify(PTR_DAT_03040ef4[0x50],*p_active_screen_state_word);
    }
  }
  if ((PTR_DAT_03040ffc[8] & 0x10) != 0) {
    if ((PTR_DAT_03040ffc[8] & 0x20) == 0) {
      write_event_record_and_notify
                (*(char *)p_active_screen_state_word + '\n',PTR_DAT_03040ff8[0x47]);
    }
    else {
      write_event_record_and_notify
                (PTR_DAT_03040ff8[0x52] + '\n',*(undefined1 *)p_active_screen_state_word);
    }
  }
  return;
}

