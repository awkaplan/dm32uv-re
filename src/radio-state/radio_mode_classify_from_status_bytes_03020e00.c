/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_classify_from_status_bytes @ 03020e00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 radio_mode_classify_from_status_bytes(void)

{
  undefined4 uVar1;
  
  if (*(char *)PTR_DAT_03020e38 == '\0') {
    uVar1 = 1;
  }
  else if (*(char *)PTR_DAT_03020e38 == '\x01') {
    if (*(char *)((int)PTR_DAT_03020e38 + 1) == '\x03') {
      uVar1 = 3;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}

