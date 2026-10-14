/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clear_field_flag_if_setting0xf_and_empty @ 03035bb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void clear_field_flag_if_setting0xf_and_empty(void)

{
  int iVar1;
  
  iVar1 = settings_read_dispatcher(0xf);
  if ((iVar1 == 1) && (*(char *)((int)PTR_DAT_03035bd4 + 1) == '\0')) {
    *(undefined1 *)PTR_DAT_03035bd4 = 0;
  }
  return;
}

