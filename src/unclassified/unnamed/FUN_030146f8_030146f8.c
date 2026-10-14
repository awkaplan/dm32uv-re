/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030146f8 @ 030146f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030146f8(void)

{
  int iVar1;
  
  iVar1 = read_byte_field_0302e118();
  if (((iVar1 == 0) && ((*(byte *)PTR_call_active_flag_03014740 & 0xc) == 0)) &&
     (*(char *)PTR_DAT_03014744 == '\x01')) {
    write_field_and_mbox_post(1,6);
    PTR_DAT_03014738[4] = PTR_DAT_03014738[4] & 0xfe | 1;
  }
  return;
}

