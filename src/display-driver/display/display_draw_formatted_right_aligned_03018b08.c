/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_formatted_right_aligned @ 03018b08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
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
display_draw_formatted_right_aligned
          (undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_38 [32];
  
  uVar1 = number_to_string_format(auStack_38,param_5,&stack0x00000004);
  uVar2 = strlen_ck803s(auStack_38);
  iVar3 = 0x1e - (uVar2 & 0xff);
  display_draw_glyph_row_mutex
            (param_1,(iVar3 - (iVar3 >> 0x1f)) * 4 & 0xfff8,auStack_38,param_2,param_3);
  return uVar1;
}

