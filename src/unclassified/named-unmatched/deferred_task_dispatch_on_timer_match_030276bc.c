/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: deferred_task_dispatch_on_timer_match @ 030276bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void deferred_task_dispatch_on_timer_match(void)

{
  dword dVar1;
  undefined4 *puVar2;
  int iVar3;
  
  dVar1 = SystemControl_Type_11000000.RX_INFO;
  if (((uint)*(byte *)PTR_DAT_03027814 == (dVar1 & 7)) &&
     ((uint)*(byte *)((int)PTR_DAT_03027814 + 1) == (dVar1 >> 3 & 0xff))) {
    *(undefined1 *)((int)PTR_DAT_03027814 + 2) = 1;
  }
  else if (*(char *)((int)PTR_DAT_03027814 + 2) == '\0') {
    return;
  }
  iVar3 = FUN_0002b318(_DAT_03027818,_DAT_03027818 + -0x399);
  puVar2 = PTR_DAT_03027814;
  if (iVar3 == 0) {
    FUN_0002b320(1,PTR_DAT_03027814);
  }
  else {
    FUN_0002b32c(*(undefined1 *)PTR_DAT_03027814,(int)PTR_DAT_03027814 + 0x23);
    FUN_0002b320(1,puVar2);
  }
  return;
}

