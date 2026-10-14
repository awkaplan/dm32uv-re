/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_formatted_number_centered @ 03018bbc (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
display_draw_formatted_number_centered
          (short param_1,ushort param_2,ushort param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  byte abStack_2c [20];
  
  uVar1 = number_to_string_format(abStack_2c,param_5,&stack0x00000004);
  uVar2 = strlen_ck803s(abStack_2c);
  display_draw_string_gb2312
            (param_1,(short)((int)((uVar2 & 0xff) * -0xc + 0xf0) >> 1) + 0xc,abStack_2c,param_2,
             param_3);
  return uVar1;
}

