/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: check_stack_value_halt_if_positive @ 030cd33c (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void check_stack_value_halt_if_positive(void)

{
  short in_stack_00000008;
  
  if (0 < in_stack_00000008) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

