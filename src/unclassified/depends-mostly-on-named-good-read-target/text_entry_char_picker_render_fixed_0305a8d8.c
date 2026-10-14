/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_picker_render_fixed @ 0305a8d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 444 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int text_entry_char_picker_render_fixed(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uStack_44;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  byte abStack_2c [8];
  
  display_fill_rect(0,0xea,0xe6,0x102,0xc618);
  if (*(char *)PTR_DAT_0305a9fc != '\0') {
    uStack_34 = 0;
    uStack_38 = 0;
    uVar16 = 0;
    uStack_44 = 0;
    do {
      iVar13 = *PTR_DAT_0305ab9c;
      uVar9 = (uint)*(byte *)(iVar13 + uStack_38);
      if (uVar16 < uVar9) {
        uVar14 = (uint)*(byte *)PTR_DAT_0305aba0;
        iVar12 = *PTR_DAT_0305aba4;
        bVar2 = *(byte *)PTR_DAT_0305aba8;
        cVar3 = *(char *)PTR_DAT_0305abac;
        uVar10 = 0;
        bVar4 = false;
        uVar15 = uVar16;
        do {
          uVar16 = uVar9;
          if (uVar14 == 0) {
            uVar9 = 0;
            uVar8 = uVar10;
LAB_0305a93e:
            abStack_2c[uVar9] = 0;
            iVar11 = uVar15 * 0xc;
            if (*(char *)(*(int *)(iVar12 + iVar11) + uVar8) == '\0') {
              uStack_44 = uStack_44 + 1 & 0xff;
              if (uStack_44 != bVar2 + 1) {
                bVar4 = true;
                goto LAB_0305aa28;
              }
              display_draw_string_gb2312(0xea,5,abStack_2c,0xffff,0xc618);
              iStack_30 = *(int *)(*PTR_DAT_0305aa00 + iVar11 + 8);
              cVar3 = *(char *)(iStack_30 + uStack_34);
              while (cVar3 != '\0') {
                uStack_34 = uStack_34 + 1 & 0xff;
                cVar3 = *(char *)(iStack_30 + uStack_34);
              }
              *(char *)PTR_DAT_0305aa04 = (char)(uStack_34 >> 1);
            }
            else {
              if (bVar4) goto LAB_0305aa28;
              uStack_44 = uStack_44 + 1 & 0xff;
              if (uStack_44 == *(byte *)PTR_DAT_0305aa08 + 1) {
                display_draw_string_gb2312(0xea,5,abStack_2c,0xffff,0xc618);
                iStack_30 = *(int *)(*PTR_DAT_0305aa00 + iVar11 + 8);
                for (; *(char *)(iStack_30 + uStack_34) != '\0'; uStack_34 = uStack_34 + 1 & 0xff) {
                }
                *(char *)PTR_DAT_0305ab90 = (char)(uStack_34 >> 1);
              }
            }
            break;
          }
          pcVar7 = *(char **)(uVar15 * 0xc + iVar12);
          pcVar5 = PTR_DAT_0305ab94;
          uVar8 = 0;
          if (*pcVar7 == cVar3) {
            do {
              pcVar7 = pcVar7 + 1;
              uVar8 = uVar8 + 1 & 0xff;
              if (uVar14 <= uVar8) break;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 == *pcVar7);
            if (uVar14 == uVar8) {
              uVar9 = uVar10;
              if (uVar8 != 0) {
                uVar6 = uVar10;
                do {
                  abStack_2c[uVar6] = *(byte *)(*(int *)(uVar15 * 0xc + iVar12 + 4) + uVar6);
                  uVar9 = uVar9 + 1 & 0xff;
                  uVar6 = uVar6 + 1;
                } while (uVar9 < uVar14);
              }
              goto LAB_0305a93e;
            }
          }
LAB_0305aa28:
          uVar15 = uVar15 + 1 & 0xff;
          uVar9 = (uint)*(byte *)(iVar13 + uStack_38);
        } while (uVar15 < uVar9);
      }
      uStack_38 = uStack_38 + 1 & 0xff;
    } while (uStack_38 < *(byte *)PTR_DAT_0305ab98);
  }
  return iStack_30;
}

