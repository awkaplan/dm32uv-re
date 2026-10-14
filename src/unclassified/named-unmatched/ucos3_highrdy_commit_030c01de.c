/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_highrdy_commit @ 030c01de (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_highrdy_commit(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  puVar3 = puRam030c02dc;
  puVar2 = puRam030c02d8;
  piVar1 = piRam030c02d4;
  if (*piRam030c02d4 != 0) {
    *(int *)*puRam030c02d8 = *piRam030c02d4;
    piVar4 = (int *)*puVar3;
    *puVar2 = piVar4;
    *piVar1 = *piVar4;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

