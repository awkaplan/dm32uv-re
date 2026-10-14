/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_commit_name @ 0304f630 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_commit_name(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(char *)p_active_screen_state_word == '\0') {
    uVar3 = *PTR_DAT_0304f7d0;
    *PTR_DAT_0304f7d4 = uVar3;
    cVar1 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_0304f7dc = cVar1 + '\x01';
    if ((PTR_DAT_0304f7e0[1] & 3) == 1) {
      uVar2 = 4;
    }
    else if ((PTR_DAT_0304f7e0[1] & 3) == 2) {
      uVar2 = 5;
    }
    else {
      uVar2 = 3;
    }
    channel_select_commit_and_notify
              (uVar2,uVar3,p_text_entry_buffer,cVar1 + '\x01',p_dm32_settings_block04[0x54]);
  }
  else {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}

