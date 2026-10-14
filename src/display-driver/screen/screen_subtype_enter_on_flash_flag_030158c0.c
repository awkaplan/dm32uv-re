/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: screen_subtype_enter_on_flash_flag @ 030158c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void screen_subtype_enter_on_flash_flag(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte abStack_10 [4];
  
  scan_entry_get_mode_bits(0x1d);
  if ((PTR_DAT_03015964[3] & 0x40) == 0) {
    iVar3 = poll_condition_group(0x1d);
    cVar1 = *(char *)PTR_DAT_03015970;
    bVar2 = *(byte *)PTR_DAT_03015960;
    flash_field_read_cached(4,0x503,abStack_10,1);
    if ((PTR_DAT_03015974[1] == '\0') &&
       ((abStack_10[0] & 0x10) != 0 && ((bVar2 & 4) != 0 && (cVar1 == '\0' && iVar3 != 0)))) {
      *(undefined1 *)PTR_active_screen_subtype_03015978 = 2;
      PTR_DAT_03015974[1] = 2;
      write_field_and_mbox_post(1,0x18);
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

