/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: char_in_allowlist_table_check @ 03023d7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 char_in_allowlist_table_check(char param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (PTR_DAT_03023e58[0x4e] == '\0') {
    uVar1 = 1;
  }
  else if (PTR_DAT_03023e58[0x4e] == param_1) {
    uVar1 = 0;
  }
  else {
    pcVar2 = PTR_DAT_03023e60;
    do {
      if (*pcVar2 == '\0') {
        return 1;
      }
      if (*pcVar2 == param_1) {
        return 0;
      }
      pcVar2 = pcVar2 + 1;
    } while (pcVar2 != PTR_DAT_03023e60 + 0x21);
    uVar1 = 1;
  }
  return uVar1;
}

