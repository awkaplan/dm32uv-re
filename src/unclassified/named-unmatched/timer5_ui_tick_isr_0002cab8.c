/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: timer5_ui_tick_isr @ 0002cab8 (IRAM address; the boot stub copies these bytes from program flash 0x030dc6d8)
 * Size: 216 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void timer5_ui_tick_isr(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = *PTR_DAT_0002cb98;
  *PTR_DAT_0002cb98 = cVar1 + 1U;
  if (9 < (byte)(cVar1 + 1U)) {
    *PTR_DAT_0002cb98 = 0;
    func_0x0300c494(PTR_ucos_flaggrp_0003fd90_0002cb94,1);
    if (((*PTR_DAT_0002cb9c & 0x20) != 0) &&
       (cVar1 = *PTR_DAT_0002cba0, *PTR_DAT_0002cba0 = cVar1 + 1U, 0x96 < (byte)(cVar1 + 1U))) {
      *PTR_DAT_0002cb9c = *PTR_DAT_0002cb9c & 0xdf;
      *(undefined2 *)PTR_DAT_0002cba4 = 0;
      *(undefined2 *)PTR_DAT_0002cba8 = 0;
      *(undefined2 *)PTR_DAT_0002cbac = 0;
      *PTR_DAT_0002cbb0 = 0;
      memset_bytes(PTR_DAT_0002cbb4,0,0x96);
      memset_bytes(PTR_DAT_0002cbb8,0,0x400);
    }
    if (((*PTR_DAT_0002cbbc & 0x42) == 0x40) &&
       (sVar2 = *(short *)(PTR_DAT_0002cbc0 + 0x14),
       *(ushort *)(PTR_DAT_0002cbc0 + 0x14) = sVar2 + 1U, 800 < (ushort)(sVar2 + 1U))) {
      *PTR_DAT_0002cbbc = *PTR_DAT_0002cbbc & 0xbf;
      *(undefined2 *)(PTR_DAT_0002cbc0 + 0x14) = 0;
      func_0x0305ef30();
    }
  }
  if ((*PTR_DAT_0002cbc4 != '\0') &&
     (cVar1 = *PTR_DAT_0002cbc8, *PTR_DAT_0002cbc8 = cVar1 + 1U, 0x14 < (byte)(cVar1 + 1U))) {
    *PTR_DAT_0002cbc4 = 0;
    *PTR_DAT_0002cbc8 = 0;
    func_0x0300c53c(PTR_DAT_0002cbcc);
  }
  func_0x03060884();
  return;
}

