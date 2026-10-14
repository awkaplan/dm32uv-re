/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_group14_resume_or_stop_status_update @ 03016280 (file base 0x03000000; code starts at 0x03001000)
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

void scan_group14_resume_or_stop_status_update(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  scan_entry_get_mode_bits(0xe);
  if (((PTR_DAT_03016340[3] & 0x40) == 0) && (iVar2 = poll_condition_group(0xe), iVar2 != 0)) {
    tx_timeout_cleanup();
    puVar1 = PTR_DAT_03016344;
    if (*(char *)((int)PTR_DAT_03016344 + 1) == '\x01') {
      *(undefined1 *)PTR_DAT_03016344 = 0;
      *(undefined1 *)((int)puVar1 + 1) = 0;
      PTR_DAT_03016340[8] = PTR_DAT_03016340[8] & 0xbf;
      *PTR_DAT_03016330 = 0;
      ui_event_notify(0x18);
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_03016348 + ((byte)PTR_DAT_03016338[0x30] >> 6 & 1) * 8));
    }
    else {
      *(undefined1 *)PTR_DAT_03016344 = 0;
      *(undefined1 *)((int)puVar1 + 1) = 1;
      PTR_DAT_03016340[8] = PTR_DAT_03016340[8] & 0xbf;
      *(byte *)((int)puVar1 + 3) = *(byte *)((int)puVar1 + 3) & 0xfe;
      *PTR_DAT_03016330 = 0;
      ui_event_notify(0x19);
      format_and_write_status_field
                (0,10,**(undefined4 **)
                        (PTR_PTR_0301634c + ((byte)PTR_DAT_03016338[0x30] >> 6 & 1) * 8));
    }
  }
  return;
}

