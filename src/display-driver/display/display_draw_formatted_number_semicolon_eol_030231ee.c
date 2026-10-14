/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_formatted_number_semicolon_eol @ 030231ee (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_draw_formatted_number_semicolon_eol
               (ushort param_1,ushort param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint uVar1;
  byte abStack_44 [52];
  
  number_to_string_format(abStack_44,param_5,&stack0x00000004);
  uVar1 = strlen_ck803s(abStack_44);
  uVar1 = uVar1 & 0xff;
  abStack_44[uVar1] = 0x3b;
  abStack_44[uVar1 + 1] = 0xd;
  abStack_44[uVar1 + 2] = 10;
  display_draw_string_gb2312(param_1 & 0xff,param_2 & 0xff,abStack_44,0xffff,0);
  return;
}

