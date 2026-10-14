/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_entry_initiate_and_show_range @ 03015714 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_entry_initiate_and_show_range(void)

{
  int iVar1;
  
  if ((PTR_DAT_0301579c[3] & 2) == 0) {
    if ((PTR_DAT_030157b4[3] & 1) == 0) {
      ui_event_notify(0x21);
    }
    else {
      iVar1 = tx_is_inhibited();
      if (iVar1 == 0) {
        iVar1 = scan_entry_get_mode_bits(0x1d);
        if ((((iVar1 == 1) || (iVar1 == 3)) &&
            (get_current_mode_state1(), *(char *)PTR_DAT_030157a8 == '\0')) &&
           (((PTR_DAT_030157b0[7] & 0x18) == 0 && ((PTR_DAT_030157b8[8] & 8) == 0)))) {
          if (PTR_DAT_03015958[5] == '\0') {
            ui_event_notify(0x1b);
            ring_buffer_multi_table_append_and_flush();
            dialog_show_icon_and_two_numbers
                      (0x30,0x30,PTR_DAT_03015954,
                       **(undefined4 **)
                         (PTR_PTR_0301594c + ((byte)PTR_DAT_03015948[0x30] >> 6 & 1) * 8),
                       PTR_LAB_03015950);
            OSTimeDly_ms_wrapper(1000);
            write_field_and_mbox_post(1,0x26);
          }
          else {
            ui_event_notify(0x1a);
            *(undefined1 *)PTR_DAT_03015944 = 1;
          }
        }
        else {
          ui_event_notify(0x1b);
          if ((PTR_DAT_030157b8[8] & 8) != 0) {
            format_and_write_status_field2
                      (**(undefined4 **)
                         (PTR_PTR_030157c0 + ((byte)PTR_DAT_030157bc[0x30] >> 6 & 1) * 8));
          }
        }
      }
    }
  }
  return;
}

