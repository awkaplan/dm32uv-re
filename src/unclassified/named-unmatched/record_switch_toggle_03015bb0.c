/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: record_switch_toggle @ 03015bb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void record_switch_toggle(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(byte *)PTR_DAT_03015c7c & 0x10) == 0) {
    ui_event_notify(0x21);
  }
  else {
    iVar2 = poll_condition_group(0x14);
    if (iVar2 != 0) {
      iVar2 = scan_entry_get_mode_bits(0x14);
      if ((iVar2 == 0) || (iVar2 == 2)) {
        ui_event_notify(0x21);
      }
      else if ((*(byte *)((int)PTR_DAT_03015c80 + 0x2b) & 1) == 0) {
        settings_toggle_and_notify_0x45(1);
        ui_event_notify(0x18);
        *PTR_DAT_03015dc4 = 0;
        format_and_write_status_field2
                  (*(undefined4 *)
                    (PTR_PTR_03015dcc[((byte)PTR_DAT_03015dc8[0x30] >> 6 & 1) * 2] + 4));
      }
      else {
        if ((byte)(PTR_DAT_03015c84[1] - 1) < 2) {
          voice_record_direction_select(0);
          write_byte_field_030212e4(5);
          puVar1 = PTR_DAT_03015c80;
          if ((*(byte *)((int)PTR_DAT_03015c80 + 0x2b) & 4) != 0) {
            flash_write_split_across_page_boundary(PTR_DAT_03015c80[2],0x12,DAT_03015c88,2);
            mutex_guarded_param_dispatch_3(puVar1[3],*(undefined2 *)((int)puVar1 + 2));
            *(byte *)((int)puVar1 + 0x2b) = *(byte *)((int)puVar1 + 0x2b) & 0xfb;
          }
        }
        settings_toggle_and_notify_0x45(0);
        ui_event_notify(0x19);
        *PTR_DAT_03015c8c = 0;
        format_and_write_status_field2
                  (**(undefined4 **)
                     (PTR_PTR_03015c90 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
    }
  }
  return;
}

