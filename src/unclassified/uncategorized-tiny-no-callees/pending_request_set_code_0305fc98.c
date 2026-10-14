/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pending_request_set_code @ 0305fc98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void pending_request_set_code(undefined1 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = PTR_DAT_0305fd70;
  PTR_DAT_0305fd70[1] = 0;
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)((int)puVar1 + 1) = param_1;
  return;
}

