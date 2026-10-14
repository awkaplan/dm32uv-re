/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_number_centered @ 03018b5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int display_draw_number_centered(int y__w,int fg__w,int bg__w,uint value)

{
  short y = (short)y__w;
  ushort fg = (ushort)fg__w;
  ushort bg = (ushort)bg__w;
  int iVar1;
  uint uVar2;
  byte abStack_30 [20];
  
  iVar1 = number_to_string_format(abStack_30,value,&stack0x00000000);
  uVar2 = strlen_ck803s(abStack_30);
  display_draw_string_gb2312(y,(ushort)((int)((uVar2 & 0xff) * -0xc + 0xf0) >> 1),abStack_30,fg,bg);
  return iVar1;
}

