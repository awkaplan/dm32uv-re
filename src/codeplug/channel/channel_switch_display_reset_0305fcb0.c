/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_switch_display_reset @ 0305fcb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_switch_display_reset(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = read_byte_field_0305fca8();
  if (iVar2 != 0) {
    PTR_DAT_0305fd74[3] = PTR_DAT_0305fd74[3] & 0xbf;
  }
  puVar1 = PTR_DAT_0305fd70;
  PTR_DAT_0305fd70[1] = 0;
  *(undefined1 *)puVar1 = 0;
  *(undefined1 *)((int)puVar1 + 1) = 0;
  return;
}

