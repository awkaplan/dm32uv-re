/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: double_to_decimal_string @ 03071184 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1046 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char * double_to_decimal_string
                 (undefined4 param_1,uint param_2,char *param_3,char *param_4,char *param_5,
                 char *param_6)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcStack_34;
  undefined4 *puStack_2c;
  
  iVar3 = three_way_compare();
  if (iVar3 != 0) {
    if ((int)param_4 < 1) {
      return (char *)0x0;
    }
    *param_3 = 'i';
    if (param_4 == (char *)0x1) {
      return (char *)0x1;
    }
    param_3[1] = 'n';
    if ((int)param_4 < 3) {
      return (char *)0x2;
    }
    param_3[2] = 'f';
    if ((int)param_4 < 4) {
      return (char *)0x3;
    }
    param_3[3] = '\0';
    return (char *)0x4;
  }
  iVar3 = coord_pair_matches_stored(param_1,param_2);
  if (iVar3 != 0) {
    if ((int)param_4 < 1) {
      return (char *)0x0;
    }
    *param_3 = 'n';
    if (param_4 == (char *)0x1) {
      return (char *)0x1;
    }
    param_3[1] = 'a';
    if (param_4 == (char *)0x2) {
      return (char *)0x2;
    }
    param_3[2] = 'n';
    if (param_4 == (char *)0x3) {
      return (char *)0x3;
    }
    param_3[3] = '\0';
    return (char *)0x4;
  }
  iVar3 = soft_double_compare_packed_dup_0306f1b0(param_1,param_2,0,0);
  if (iVar3 != 0) {
    iVar3 = soft_double_compare_packed(param_1,param_2,0,0);
    uVar8 = param_2;
    pcVar15 = param_3;
    if (iVar3 < 0) {
      *param_3 = '-';
      param_4 = param_4 + -1;
      uVar8 = param_2 + 0x80000000;
      pcVar15 = param_3 + 1;
    }
    if (param_6 == (char *)0x0) {
      uVar7 = 0x3fe00000;
      uVar4 = 0;
    }
    else {
      uVar7 = 0x3fe00000;
      pcVar11 = (char *)0x0;
      do {
        uVar4 = soft_double_multiply();
        pcVar11 = pcVar11 + 1;
      } while (pcVar11 < param_6);
    }
    uVar4 = soft_double_add(param_1,uVar8,uVar4,uVar7);
    iVar3 = soft_double_compare_packed();
    if (iVar3 < 0) {
      *pcVar15 = '0';
      param_4 = param_4 + -1;
      pcVar15 = pcVar15 + 1;
    }
    soft_double_from_int((param_2 >> 0x14 & 0x7ff) - 0x3ff);
    soft_double_multiply();
    iVar3 = softdouble_to_int32();
    uVar5 = iVar3 + 1;
    uVar7 = DAT_030714c0;
    uVar9 = DAT_030714c4;
    if (0 < (int)uVar5) {
      uVar13 = uVar5;
      if (uVar5 < 0xb) {
        puStack_2c = _LAB_030715c0;
        uVar9 = 0x40240000;
        uVar7 = 0;
      }
      else {
        uVar9 = 0x40240000;
        puStack_2c = DAT_030714b0;
        uVar7 = 0;
        do {
          uVar7 = soft_double_multiply(uVar7);
          uVar13 = uVar13 - 10;
        } while (10 < uVar13);
      }
      for (; uVar13 != 1; uVar13 = uVar13 - 1) {
        uVar7 = soft_double_multiply(uVar7);
      }
      iVar3 = softdouble_compare_le(uVar7,uVar9,*PTR_DAT_030714bc,PTR_DAT_030714bc[1]);
      if (0 < iVar3) {
        bVar1 = true;
        do {
          uVar13 = uVar8;
          soft_double_divide(uVar4,uVar8,uVar7,uVar9);
          cVar2 = softdouble_to_int32();
          if ((bVar1) && (cVar2 == '\0')) {
            bVar1 = true;
          }
          else {
            *pcVar15 = cVar2 + '0';
            pcVar15 = pcVar15 + 1;
            if (param_4 == (char *)0x0) {
              soft_double_divide(param_1,param_2,uVar7,uVar9);
              iVar3 = double_to_decimal_string();
              if (iVar3 == 0) {
                return (char *)0x0;
              }
              pcVar15 = pcVar15 + iVar3;
              if (-iVar3 != 0) {
                *pcVar15 = 'e';
                pcVar15 = pcVar15 + 1;
              }
              iVar12 = 1000;
              iVar3 = -iVar3 + -1;
              iVar10 = 4;
              bVar1 = true;
              do {
                if (((int)uVar5 < iVar12) && (bVar1)) {
                  bVar1 = true;
                }
                else {
                  if (iVar3 != 0) {
                    *pcVar15 = (char)((int)uVar5 / iVar12) + '0';
                    pcVar15 = pcVar15 + 1;
                  }
                  uVar5 = uVar5 - iVar12 * ((int)uVar5 / iVar12);
                  iVar3 = iVar3 + -1;
                  bVar1 = false;
                }
                iVar10 = iVar10 + -1;
                iVar12 = iVar12 / 10;
              } while (iVar10 != 0);
              if (iVar3 == 0) {
                return (char *)0x0;
              }
              pcVar11 = pcVar15 + -(int)param_3;
              goto LAB_0307149a;
            }
            soft_double_from_int(cVar2);
            uVar6 = soft_double_multiply();
            uVar4 = soft_double_sub(uVar4,uVar8,uVar6,uVar13);
            param_4 = param_4 + -1;
            bVar1 = false;
          }
          uVar7 = soft_double_divide(uVar7,uVar9,*puStack_2c,puStack_2c[1]);
          iVar3 = softdouble_compare_le();
        } while (0 < iVar3);
      }
    }
    if (pcVar15 == param_3) {
      if (param_4 == (char *)0x0) {
        return (char *)0x0;
      }
      *pcVar15 = '0';
      param_4 = param_4 + -1;
      pcVar15 = pcVar15 + 1;
    }
    if ((param_6 != (char *)0x0) || (pcVar11 = pcVar15 + -(int)param_3, pcVar11 + 1 < param_5)) {
      if (param_4 == (char *)0x0) {
        return (char *)0x0;
      }
      *pcVar15 = '.';
      pcVar15 = pcVar15 + 1;
      if (param_6 == (char *)0x0) {
        pcStack_34 = param_3 + (int)(param_5 + (1 - (int)pcVar15));
      }
      else {
        pcStack_34 = param_6;
      }
      if (param_4 + -1 < pcStack_34) {
        return (char *)0x0;
      }
      pcVar11 = pcStack_34;
      pcVar14 = pcVar15;
      if (pcStack_34 != (char *)0x0) {
        do {
          uVar5 = uVar8;
          soft_double_divide(uVar4,uVar8,uVar7,uVar9);
          cVar2 = softdouble_to_int32();
          *pcVar14 = cVar2 + '0';
          soft_double_from_int();
          uVar6 = soft_double_multiply();
          uVar4 = soft_double_sub(uVar4,uVar8,uVar6,uVar5);
          uVar7 = soft_double_divide(uVar7,uVar9,*PTR_DAT_030714b8,PTR_DAT_030714b8[1]);
          pcVar11 = pcVar11 + -1;
          pcVar14 = pcVar14 + 1;
        } while (pcVar11 != (char *)0x0);
        pcVar15 = pcVar15 + (int)pcStack_34;
      }
      pcVar11 = pcVar15 + -(int)param_3;
    }
LAB_0307149a:
    *pcVar15 = '\0';
    return pcVar11;
  }
  if (param_6 == (char *)0x0) {
    param_6 = (char *)0x1;
  }
  else {
    param_6 = param_6 + 2;
  }
  if (param_4 < param_6) {
    param_6 = (char *)0x8;
  }
  else {
    pcVar15 = param_6;
    if (param_6 == (char *)0x0) goto LAB_03071218;
  }
  if ((int)param_2 < 0) {
    *param_3 = '-';
    param_6 = param_6 + 1;
  }
  pcVar11 = (char *)(uint)((int)param_2 < 0);
  pcVar15 = pcVar11;
  for (; pcVar11 < param_6; pcVar11 = pcVar11 + 1) {
    param_3[(int)pcVar11] = '0';
    pcVar15 = param_6;
  }
LAB_03071218:
  if (*param_3 == '0') {
    iVar3 = 1;
  }
  else {
    iVar3 = 2;
  }
  param_3[iVar3] = '.';
  param_3[(int)pcVar15] = '\0';
  return pcVar15;
}

