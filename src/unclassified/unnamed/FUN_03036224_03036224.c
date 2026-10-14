/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03036224 @ 03036224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_03036224(void)

{
  int iVar1;
  
  if (((PTR_DAT_03036360[8] == '\0') && (PTR_DAT_03036360[7] == '\0')) &&
     (iVar1 = read_byte_field_0302e118(), iVar1 == 0)) {
    write_field_and_mbox_post(1,0x26);
  }
  else {
    *(undefined1 *)PTR_active_screen_subtype_03036364 = 2;
    write_status_mode_byte_pair(0x5b,1);
    write_field_and_mbox_post(1,0x25);
  }
  return;
}

