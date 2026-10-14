/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_tmrkey_expiry_dispatch @ 03014a54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_tmrkey_expiry_dispatch(void)

{
  int iVar1;
  
  if ((PTR_DAT_03014ba4[2] & 4) != 0) {
    os_sem_post(DAT_03014bbc);
    codeplug_factory_defaults_write();
  }
  if ((*(byte *)p_call_active_flag & 0xf) == 0) {
    iVar1 = read_byte_field_0302e118();
    if (iVar1 == 0) {
      keypad_tmrkey_event_post_and_close(5);
    }
    else {
      write_field_and_mbox_post(2,5);
    }
  }
  else {
    write_field_and_mbox_post(2,5);
  }
  return;
}

