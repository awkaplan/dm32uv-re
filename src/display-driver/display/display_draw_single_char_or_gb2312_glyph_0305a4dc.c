/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_single_char_or_gb2312_glyph @ 0305a4dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 272 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_single_char_or_gb2312_glyph(char *param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  ushort x;
  byte local_8;
  char cStack_7;
  undefined1 uStack_6;
  
  sVar1 = *(short *)p_text_entry_current_char;
  x = *(ushort *)PTR_DAT_0305a600;
  if ((uint)*DAT_0305a604 <= *(ushort *)PTR_DAT_0305a608 + 1) {
    if (*param_1 < '\0') {
      local_8 = param_1[(uint)(byte)PTR_DAT_0305a60c[0x321] * 2];
      cStack_7 = param_1[(uint)(byte)PTR_DAT_0305a60c[0x321] * 2 + 1];
      uStack_6 = 0;
      if (sVar1 == 5) {
        if (x < 0x21) {
          x = 0x20;
          uVar2 = 0xd1;
        }
        else {
          x = x - 0x18;
          uVar2 = 0xd1;
        }
      }
      else {
        uVar2 = sVar1 - 0x18;
      }
      display_draw_string_gb2312(x,uVar2,&local_8,0xffff,0xc618);
      if (1 < *(byte *)PTR_DAT_0305a610) {
        iVar3 = p_text_entry_buffer + (uint)*(byte *)PTR_DAT_0305a610;
        *(byte *)(iVar3 + -2) = local_8;
        *(char *)(iVar3 + -1) = cStack_7;
      }
    }
    else {
      local_8 = param_1[(byte)PTR_DAT_0305a60c[0x321]];
      cStack_7 = '\0';
      if (sVar1 == 5) {
        uVar2 = 5;
        if (*(char *)PTR_DAT_0305a610 != '\0') {
          if (x < 0x21) {
            x = 0x20;
            uVar2 = 0xe9;
          }
          else {
            x = x - 0x18;
            if (x < 0x20) {
              x = 0x20;
              uVar2 = 0xe9;
            }
            else {
              uVar2 = 0xe9;
            }
          }
        }
      }
      else {
        uVar2 = sVar1 - 0xc;
      }
      display_draw_string_gb2312(x,uVar2,&local_8,0xffff,0xc618);
      if (*(byte *)PTR_DAT_0305a610 != 0) {
        *(byte *)((uint)*(byte *)PTR_DAT_0305a610 + p_text_entry_buffer_alias) = local_8;
      }
    }
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_0305a600,*(undefined2 *)p_text_entry_current_char,
               PTR_DAT_0305a61c,1);
  }
  return;
}

