/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_int_highrdy_commit @ 030c0206 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_int_highrdy_commit(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = puRam030c02dc;
  puVar2 = puRam030c02d8;
  puVar1 = puRam030c02d4;
  *(undefined4 *)*puRam030c02d8 = *puRam030c02d4;
  puVar3 = (undefined4 *)*puVar3;
  *puVar2 = puVar3;
  *puVar1 = *puVar3;
  return;
}

