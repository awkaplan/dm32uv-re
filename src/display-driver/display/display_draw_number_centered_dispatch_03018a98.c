/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_number_centered_dispatch @ 03018a98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
display_draw_number_centered_dispatch
          (undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_38 [32];
  
  uVar1 = number_to_string_format(auStack_38,param_4,&stack0x00000000);
  uVar2 = strlen_ck803s(auStack_38);
  uVar2 = uVar2 & 0xff;
  if ((0x10 < uVar2) && (*(char *)PTR_DAT_03018b00 == '\0')) {
    uVar2 = 0x10;
  }
  display_draw_string_mixed_ascii_gb2312
            (param_1,((int)(0x1e - uVar2) / 2) * 8 + 1U & 0xffff,auStack_38,param_2);
  return uVar1;
}

