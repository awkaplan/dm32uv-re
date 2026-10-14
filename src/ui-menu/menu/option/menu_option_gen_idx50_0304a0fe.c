/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_gen_idx50 @ 0304a0fe (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_gen_idx50(void)

{
  ushort uVar1;
  char cVar2;
  ushort *unaff_r4;
  int unaff_r5;
  
  cVar2 = '\0';
  do {
    uVar1 = *unaff_r4;
    *(char *)(unaff_r5 + (uint)uVar1) = cVar2;
    *unaff_r4 = uVar1 + 1;
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\x03');
  return;
}

