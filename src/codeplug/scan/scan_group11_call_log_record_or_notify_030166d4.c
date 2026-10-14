/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_group11_call_log_record_or_notify @ 030166d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_group11_call_log_record_or_notify(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  byte abStack_c [4];
  
  scan_entry_get_mode_bits(0xb);
  if ((PTR_DAT_03016774[3] & 0x40) == 0) {
    bVar3 = PTR_DAT_0301678c[1];
    iVar2 = poll_condition_group(0xb);
    if (iVar2 == 0) {
      bVar3 = 0;
    }
    else {
      bVar3 = ~((bVar3 & 0x80) != 0);
    }
    if ((*(char *)PTR_DAT_03016794 == '\0') && (bVar3 != 0)) {
      tx_gate_write_call_record(1);
      cVar1 = PTR_DAT_03016780[0x6c];
      PTR_DAT_03016780[0x6c] = cVar1 + 1U;
      if (2 < (byte)(cVar1 + 1U)) {
        PTR_DAT_03016780[0x6c] = 0;
      }
      settings_flag_bits_sync_to_dat_03064328();
      flash_field_read_cached(4,0x80,abStack_c,1);
      abStack_c[0] = PTR_DAT_03016780[0x6c] << 6 | abStack_c[0] & 0x3f;
      flash_field_write_cached(4,0x80);
      write_field_and_mbox_post(1,100);
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

