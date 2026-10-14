/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_picker_render @ 03059dfc (file base 0x03000000; code starts at 0x03001000)
 * Size: 578 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 text_entry_char_picker_render(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uStack_44;
  uint uStack_34;
  undefined4 uStack_30;
  byte abStack_2c [8];
  
  uVar9 = 0x10 / *(byte *)PTR_DAT_03059f10;
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_03059f24,*(undefined2 *)p_text_entry_current_char,
             PTR_LAB_03059f2c,1);
  display_fill_rect(0,0xea,0xf0,0x102,0xc618);
  puVar6 = PTR_DAT_0305a11c;
  puVar5 = PTR_DAT_0305a118;
  if (*(char *)PTR_DAT_03059f08 != '\0') {
    uVar12 = 0;
    uStack_34 = 0;
    uVar15 = 0;
    uStack_44 = 0;
    do {
      uVar16 = (uint)*(byte *)(*puVar5 + uStack_34);
      if (uVar15 < uVar16) {
        bVar4 = false;
        uVar14 = uVar15;
        do {
          uVar15 = uVar16;
          bVar2 = *(byte *)PTR_DAT_0305a108;
          uVar16 = (uint)bVar2;
          if (uVar16 == 0) {
            uVar8 = 0;
            uVar13 = uVar12;
LAB_03059e86:
            abStack_2c[uVar8] = 0;
            iVar17 = uVar14 * 0xc;
            sVar3 = (short)uVar9;
            if (*(char *)(*(int *)(*puVar6 + iVar17) + uVar13) == '\0') {
              uStack_44 = uStack_44 + 1 & 0xff;
              uVar16 = uVar9 * (*(byte *)PTR_DAT_03059f30 / uVar9) & 0xff;
              if (uVar16 < uStack_44) {
                if (uVar16 + uVar9 < uStack_44) {
                  bVar4 = true;
                }
                else if (uStack_44 == *(byte *)PTR_DAT_03059f30 + 1) {
                  display_draw_string_gb2312
                            (0xea,((short)(uStack_44 - 1) -
                                  sVar3 * (short)((int)(uStack_44 - 1) / (int)uVar9)) * 0xc *
                                  ((short)uVar13 + 1) + 5,abStack_2c,0xffff,0xc618);
                  uStack_30 = *(undefined4 *)(*puVar6 + iVar17 + 8);
                  bVar4 = true;
                }
                else {
                  display_draw_string_gb2312
                            (0xea,((short)(uStack_44 - 1) -
                                  sVar3 * (short)((int)(uStack_44 - 1) / (int)uVar9)) * 0xc *
                                  ((short)uVar13 + 1) + 5,abStack_2c,0,0xc618);
                  bVar4 = true;
                }
              }
              else {
                bVar4 = true;
              }
            }
            else if (!bVar4) {
              uStack_44 = uStack_44 + 1 & 0xff;
              if (uStack_44 == *(byte *)PTR_DAT_0305a104 + 1) {
                display_draw_string_gb2312
                          (0xea,((short)(uStack_44 - 1) -
                                sVar3 * (short)((int)(uStack_44 - 1) / (int)uVar9)) *
                                (bVar2 + 1) * 0xc + 5,abStack_2c,0xffff,0xc618);
                uStack_30 = *(undefined4 *)(*puVar6 + iVar17 + 8);
              }
              else {
                display_draw_string_gb2312
                          (0xea,((short)uStack_44 + -1) * (bVar2 + 1) * 0xc,abStack_2c,0,0xc618);
              }
              break;
            }
          }
          else {
            pcVar11 = *(char **)(uVar14 * 0xc + *puVar6);
            pcVar7 = PTR_DAT_0305a110;
            uVar13 = 0;
            if (*(char *)PTR_DAT_0305a10c == *pcVar11) {
              do {
                pcVar11 = pcVar11 + 1;
                uVar13 = uVar13 + 1 & 0xff;
                if (uVar16 <= uVar13) break;
                cVar1 = *pcVar7;
                pcVar7 = pcVar7 + 1;
              } while (cVar1 == *pcVar11);
              if (uVar16 == uVar13) {
                uVar8 = uVar12;
                if (uVar13 != 0) {
                  iVar17 = *puVar6;
                  uVar10 = uVar12;
                  do {
                    abStack_2c[uVar10] = *(byte *)(*(int *)(iVar17 + uVar14 * 0xc + 4) + uVar10);
                    uVar8 = uVar8 + 1 & 0xff;
                    uVar10 = uVar10 + 1;
                  } while (uVar8 < uVar16);
                }
                goto LAB_03059e86;
              }
            }
          }
          uVar14 = uVar14 + 1 & 0xff;
          uVar16 = (uint)*(byte *)(*puVar5 + uStack_34);
        } while (uVar14 < uVar16);
      }
      uStack_34 = uStack_34 + 1 & 0xff;
    } while (uStack_34 < *(byte *)PTR_DAT_0305a114);
  }
  return uStack_30;
}

