/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_select_type0 @ 0305cf60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_select_type0(void)

{
  undefined4 unaff_r6;
  int unaff_r7;
  uint uStack00000000;
  
  PTR_DAT_0305d00c[8] = 0;
  *(undefined4 *)PTR_DAT_0305d00c = unaff_r6;
  uStack00000000 = (uint)(ushort)PTR_DAT_0305d010[-1];
  field_mode_write_and_dispatch_to_0301f170(0,unaff_r7 != 0);
  return;
}

