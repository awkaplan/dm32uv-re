/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_pending_commit_and_post @ 030168c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_pending_commit_and_post(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_DAT_0301692c;
  if (*(char *)((int)PTR_DAT_0301692c + 0x2a) == '\x03') {
    *(undefined1 *)((int)PTR_DAT_0301692c + 0x2a) = 1;
    cVar1 = *(char *)((int)puVar2 + 0x29);
    if (cVar1 == '\x1d') {
      PTR_DAT_0301692c[0xb] = PTR_DAT_0301692c[1];
    }
    else if (cVar1 == '\x1e') {
      PTR_DAT_0301692c[0xb] = *PTR_DAT_0301692c;
    }
    else if (cVar1 == '\x1f') {
      PTR_DAT_0301692c[0xb] = PTR_DAT_0301692c[2];
    }
    else if (cVar1 == '\x15') {
      PTR_DAT_0301692c[0xb] = PTR_DAT_0301692c[3];
    }
    else if (cVar1 == '\x16') {
      PTR_DAT_0301692c[0xb] = PTR_DAT_0301692c[4];
    }
    else if (cVar1 == '\x05') {
      PTR_DAT_03016afc[0xb] = PTR_dialog_history_step_or_exit_to_idle_03016b00;
    }
    set_flag_bits_and_post_os_flag_0x8000(8);
  }
  return;
}

