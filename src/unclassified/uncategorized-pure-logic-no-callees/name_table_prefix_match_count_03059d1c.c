/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: name_table_prefix_match_count @ 03059d1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 222 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char name_table_prefix_match_count(void)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  uint uStack_2c;
  
  if (*(byte *)PTR_DAT_03059f08 == 0) {
    cVar10 = '\0';
  }
  else {
    uVar3 = (uint)*(byte *)PTR_DAT_03059f10;
    uStack_2c = 0;
    uVar7 = 0;
    cVar10 = '\0';
    do {
      uVar9 = (uint)*(byte *)(*PTR_DAT_03059f0c + uStack_2c);
      if (uVar7 < uVar9) {
        bVar2 = false;
        uVar8 = uVar7;
        do {
          uVar7 = uVar9;
          if (uVar3 == 0) {
            uVar6 = 0;
LAB_03059d72:
            if (*(char *)(*(int *)(uVar8 * 0xc + *PTR_DAT_03059f14) + uVar6) == '\0') {
              cVar10 = cVar10 + '\x01';
              bVar2 = true;
            }
            else if (!bVar2) {
              cVar10 = cVar10 + '\x01';
              break;
            }
          }
          else {
            pcVar5 = *(char **)(uVar8 * 0xc + *PTR_DAT_03059f14);
            pcVar4 = PTR_DAT_03059f1c;
            uVar6 = 0;
            if (*pcVar5 == *(char *)PTR_DAT_03059f18) {
              do {
                pcVar5 = pcVar5 + 1;
                uVar6 = uVar6 + 1 & 0xff;
                if (uVar3 <= uVar6) break;
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (cVar1 == *pcVar5);
              if (uVar3 == uVar6) goto LAB_03059d72;
            }
          }
          uVar8 = uVar8 + 1 & 0xff;
        } while (uVar8 < uVar9);
      }
      uStack_2c = uStack_2c + 1;
    } while ((uStack_2c & 0xff) < (uint)*(byte *)PTR_DAT_03059f08);
  }
  *(char *)PTR_DAT_03059f20 = cVar10;
  return cVar10;
}

