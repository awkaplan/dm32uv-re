/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_scan_entry_toggle_and_reload @ 030167a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 278 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_scan_entry_toggle_and_reload(void)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  
  scan_entry_get_mode_bits(0xb);
  if ((PTR_DAT_03016914[3] & 0x40) == 0) {
    bVar3 = PTR_DAT_03016918[1];
    iVar2 = poll_condition_group(0xb);
    if (iVar2 == 0) {
      bVar3 = 0;
    }
    else {
      bVar3 = ~((bVar3 & 0x80) != 0);
    }
    if (*(char *)PTR_DAT_0301691c != '\0') {
      bVar3 = 0;
    }
    if (((PTR_DAT_03016920[0x2e] & 1) == 0) && (bVar3 != 0)) {
      if ((PTR_DAT_03016920[0x2d] & 0x80) == 0) {
        if ((PTR_DAT_03016914[0x15] & 1) != 0) {
          tx_gate_write_call_record(0);
        }
        PTR_DAT_03016920[0x2d] = PTR_DAT_03016920[0x2d] & 0xfe | ~PTR_DAT_03016920[0x2d] & 1;
        settings_write_dispatcher(0xc);
      }
      else {
        if ((PTR_DAT_03016914[0x15] & 2) != 0) {
          tx_gate_write_call_record(0);
        }
        PTR_DAT_03016920[0x2d] =
             PTR_DAT_03016920[0x2d] & 0xfd |
             (byte)((((byte)PTR_DAT_03016920[0x2d] ^ 2) >> 1 & 1) << 1);
        settings_write_dispatcher(0xc);
      }
      iVar2 = get_current_mode_state2();
      if (iVar2 != 0) {
        set_flag_byte_03064328(4);
        puVar1 = PTR_DAT_03016924;
        PTR_DAT_03016924[0x1d] = 0;
        puVar1[0x1c] = 0;
        set_flag_byte_03064328(3);
      }
      vfo_load_side_config();
      settings_bitfield_remap_0x2d();
      bVar3 = PTR_DAT_03016920[0x2d];
      PTR_DAT_03016928[1] = PTR_DAT_03016928[1] & 0xfe | bVar3 >> 7;
      display_clear_channel_row_background(bVar3 >> 7,0);
      ui_event_notify(0x1a);
      ui_event_notify_alt(1);
    }
    else {
      tx_gate_write_call_record(0);
    }
  }
  return;
}

