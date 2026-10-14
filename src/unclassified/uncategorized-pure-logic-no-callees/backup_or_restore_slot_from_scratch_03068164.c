/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: backup_or_restore_slot_from_scratch @ 03068164 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void backup_or_restore_slot_from_scratch(int param_1__w)

{
  char param_1 = (char)param_1__w;
  if (param_1 == '\0') {
    PTR_DAT_030682a8[6] = PTR_DAT_030682a8[8];
  }
  else {
    PTR_DAT_030682a8[7] = PTR_DAT_030682a8[8];
  }
  return;
}

