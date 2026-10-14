/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_delay_line_shift @ 030cb390 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_squelch_delay_line_shift(int param_1)

{
  *(undefined2 *)(param_1 + 0x100) = *(undefined2 *)(param_1 + 0xfe);
  *(undefined2 *)(param_1 + 0xfe) = *(undefined2 *)(param_1 + 0xfc);
  *(undefined2 *)(param_1 + 0xfc) = *(undefined2 *)(param_1 + 0xfa);
  *(undefined2 *)(param_1 + 0xfa) = *(undefined2 *)(param_1 + 0xf8);
  *(undefined2 *)(param_1 + 0xf8) = *(undefined2 *)(param_1 + 0xf6);
  array_copy_u16(param_1 + 0x122,param_1 + 0x112,8);
  *(undefined2 *)(param_1 + 0x136) = *(undefined2 *)(param_1 + 0x134);
  array_copy_u16(param_1 + 0x112,param_1 + 0x102,8);
  *(undefined2 *)(param_1 + 0x134) = *(undefined2 *)(param_1 + 0x132);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

