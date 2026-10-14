/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_entry_status_update_tone_aware @ 030165f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 224 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_entry_status_update_tone_aware(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = scan_entry_get_mode_bits(0xb);
  if ((PTR_DAT_03016774[3] & 0x40) == 0) {
    iVar4 = poll_condition_group(0xb);
    cVar1 = *(char *)PTR_DAT_03016778;
    iVar5 = tone_signaling_type_classify(*(undefined2 *)((int)PTR_DAT_0301677c + 0x11));
    puVar2 = PTR_DAT_0301678c;
    if (iVar5 == 0) {
      ui_event_notify(0x21);
      format_and_write_status_field2(PTR_PTR_03016784[(byte)PTR_DAT_03016780[0x30] >> 6 & 1]);
    }
    else if ((*(char *)PTR_active_screen_subtype_03016788 == '/') &&
            ((PTR_DAT_0301678c[3] & 0x80) != 0)) {
      PTR_DAT_0301678c[3] = PTR_DAT_0301678c[3] & 0x7f;
      *(undefined1 *)PTR_active_screen_state_word_03016790 = 0;
      puVar2[4] = puVar2[4] & 0xfe;
      ui_event_notify_alt(8);
      ui_event_notify(0x19);
      write_field_and_mbox_post(1,100);
    }
    else if ((*(char *)PTR_DAT_03016794 == '\0') &&
            (iVar3 != 1 && (iVar3 != 3 && (cVar1 == '\0' && iVar4 != 0)))) {
      *(undefined1 *)PTR_active_screen_subtype_03016788 = 2;
      PTR_DAT_03016798[1] = 0xf;
      write_field_and_mbox_post(1,0x18);
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

