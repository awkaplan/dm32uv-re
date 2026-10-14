/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_clear_pair_on_read_0xf @ 03035ba0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_clear_pair_on_read_0xf(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = settings_read_dispatcher(0xf);
  puVar1 = PTR_DAT_03035bd4;
  if (iVar2 == 1) {
    *(undefined1 *)((int)PTR_DAT_03035bd4 + 1) = 0;
    *(undefined1 *)puVar1 = 0;
  }
  return;
}

