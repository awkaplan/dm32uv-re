/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_coordinate_pair_distance_calc @ 0306319c (file base 0x03000000; code starts at 0x03001000)
 * Size: 1234 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
gps_coordinate_pair_distance_calc
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined2 *param_9)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  puVar1 = PTR_LAB_030633b4;
  soft_double_multiply(param_1,param_2,*PTR_LAB_030633b4,PTR_LAB_030633b4[1]);
  uVar3 = soft_double_divide();
  soft_double_multiply(param_3,param_4,*puVar1,puVar1[1]);
  uVar4 = soft_double_divide();
  soft_double_multiply(param_5,param_6,*puVar1,puVar1[1]);
  uVar5 = soft_double_divide();
  soft_double_multiply(param_7,param_8,*puVar1,puVar1[1]);
  uVar6 = soft_double_divide();
  uVar13 = param_2;
  uVar7 = soft_double_sin(uVar3);
  uVar12 = param_6;
  uVar8 = soft_double_sin(uVar5);
  uVar15 = param_2;
  uVar9 = soft_double_cos(uVar3);
  uVar16 = param_6;
  uVar10 = soft_double_cos(uVar5);
  uVar17 = param_8;
  uVar11 = soft_double_sub(uVar6,param_8,uVar4,param_4);
  soft_double_cos();
  uVar12 = soft_double_multiply(uVar7,uVar13,uVar8,uVar12);
  soft_double_multiply(uVar9,uVar15,uVar10,uVar16);
  uVar7 = soft_double_multiply();
  uVar12 = soft_double_add(uVar12,uVar13,uVar7,uVar15);
  puVar1 = PTR_DAT_030633bc;
  *PTR_DAT_030633bc = uVar12;
  puVar1[1] = uVar13;
  uVar12 = soft_double_multiply();
  soft_double_sub(*(undefined4 *)PTR_LAB_030633c0,*(undefined4 *)(PTR_LAB_030633c0 + 4),uVar12,
                  uVar13);
  soft_double_x_plus_x_squared();
  uVar13 = soft_double_sin(uVar11,uVar17);
  soft_double_multiply(uVar10,uVar16,uVar13,uVar17);
  uVar13 = soft_double_divide();
  *puVar1 = uVar13;
  puVar1[1] = uVar16;
  soft_double_divide_or_reciprocal_series();
  soft_double_multiply();
  uVar13 = soft_double_divide();
  *puVar1 = uVar13;
  puVar1[1] = uVar16;
  iVar14 = softdouble_compare_le
                     (uVar4,param_4,*(undefined4 *)PTR_LAB_030633c4,
                      *(undefined4 *)(PTR_LAB_030633c4 + 4));
  if ((((iVar14 < 1) ||
       (iVar14 = soft_double_compare_packed
                           (uVar4,param_4,*(undefined4 *)PTR_LAB_030633c8,
                            *(undefined4 *)(PTR_LAB_030633c8 + 4)), -1 < iVar14)) ||
      (iVar14 = softdouble_compare_le
                          (uVar3,param_2,*(undefined4 *)PTR_LAB_030633c4,
                           *(undefined4 *)(PTR_LAB_030633c4 + 4)), iVar14 < 1)) ||
     (iVar14 = soft_double_compare_packed
                         (uVar3,param_2,*(undefined4 *)PTR_LAB_030633c8,
                          *(undefined4 *)(PTR_LAB_030633c8 + 4)), -1 < iVar14)) {
    *param_9 = 0;
    return 0;
  }
  iVar14 = softdouble_compare_le
                     (uVar6,param_8,*(undefined4 *)PTR_LAB_030633c4,
                      *(undefined4 *)(PTR_LAB_030633c4 + 4));
  if (((iVar14 < 1) ||
      (iVar14 = soft_double_compare_packed
                          (uVar6,param_8,*(undefined4 *)PTR_LAB_030633c8,
                           *(undefined4 *)(PTR_LAB_030633c8 + 4)), -1 < iVar14)) ||
     ((iVar14 = softdouble_compare_le
                          (uVar5,param_6,*(undefined4 *)PTR_LAB_030633c4,
                           *(undefined4 *)(PTR_LAB_030633c4 + 4)), iVar14 < 1 ||
      (iVar14 = soft_double_compare_packed
                          (uVar5,param_6,*(undefined4 *)PTR_LAB_030633c8,
                           *(undefined4 *)(PTR_LAB_030633c8 + 4)), -1 < iVar14)))) {
    *param_9 = 0;
    return 0;
  }
  iVar14 = softdouble_compare_le(uVar5,param_6,uVar3,param_2);
  if (iVar14 < 1) {
    iVar14 = soft_double_compare_packed(uVar5,param_6,uVar3,param_2);
    if (iVar14 < 0) {
      iVar14 = softdouble_compare_le(uVar6,param_8,uVar4,param_4);
      puVar1 = PTR_DAT_03063650;
      if (iVar14 < 1) {
        iVar14 = soft_double_compare_packed(uVar6,param_8,uVar4,param_4);
        puVar1 = PTR_DAT_03063650;
        if (-1 < iVar14) {
          iVar14 = soft_double_compare_packed_dup_0306f1b0(uVar6,param_8,uVar4,param_4);
          puVar1 = PTR_DAT_03063650;
          if (iVar14 != 0) {
            *param_9 = 0;
            return 0;
          }
          uVar13 = *(undefined4 *)(PTR_LAB_0306365c + 4);
          *PTR_DAT_03063650 = *(undefined4 *)PTR_LAB_0306365c;
          puVar1[1] = uVar13;
          goto LAB_030636c6;
        }
        uVar13 = soft_double_add(uVar13,uVar16,*(undefined4 *)PTR_LAB_03063658,
                                 *(undefined4 *)(PTR_LAB_03063658 + 4));
        *puVar1 = uVar13;
        puVar1[1] = uVar16;
      }
      else {
        uVar13 = soft_double_add(uVar13,uVar16,*(undefined4 *)PTR_LAB_03063654,
                                 *(undefined4 *)(PTR_LAB_03063654 + 4));
        *puVar1 = uVar13;
        puVar1[1] = uVar16;
      }
    }
    else {
      iVar14 = soft_double_compare_packed_dup_0306f1b0(uVar5,param_6,uVar3,param_2);
      if (iVar14 == 0) {
        iVar14 = softdouble_compare_le(uVar6,param_8,uVar4,param_4);
        puVar1 = PTR_DAT_03063650;
        if (iVar14 < 1) {
          iVar14 = soft_double_compare_packed(uVar6,param_8,uVar4,param_4);
          puVar1 = PTR_DAT_03063650;
          if (-1 < iVar14) {
            iVar14 = soft_double_compare_packed_dup_0306f1b0(uVar6,param_8,uVar4,param_4);
            if (iVar14 == 0) {
              *param_9 = 0;
              return 0;
            }
            *param_9 = 0;
            return 0;
          }
          uVar13 = *(undefined4 *)(PTR_LAB_03063658 + 4);
          *PTR_DAT_03063650 = *(undefined4 *)PTR_LAB_03063658;
          puVar1[1] = uVar13;
        }
        else {
          uVar13 = *(undefined4 *)(PTR_LAB_03063654 + 4);
          *PTR_DAT_03063650 = *(undefined4 *)PTR_LAB_03063654;
          puVar1[1] = uVar13;
        }
LAB_030636c6:
        uVar13 = *_LAB_030636dc;
        uVar12 = _LAB_030636dc[1];
        uVar2 = soft_double_to_int(uVar13,uVar12);
        *param_9 = uVar2;
        goto LAB_03063532;
      }
    }
  }
  else {
    iVar14 = softdouble_compare_le(uVar6,param_8,uVar4,param_4);
    if (iVar14 < 1) {
      iVar14 = soft_double_compare_packed(uVar6,param_8,uVar4,param_4);
      if (-1 < iVar14) {
        iVar14 = soft_double_compare_packed_dup_0306f1b0(uVar6,param_8,uVar4,param_4);
        puVar1 = PTR_DAT_03063650;
        if (iVar14 == 0) {
          uVar13 = *(undefined4 *)(PTR_LAB_0306364c + 4);
          *PTR_DAT_03063650 = *(undefined4 *)PTR_LAB_0306364c;
          puVar1[1] = uVar13;
          *param_9 = 0;
          return 3;
        }
        *param_9 = 0;
        return 0;
      }
      uVar13 = soft_double_add(uVar13,uVar16,*(undefined4 *)PTR_LAB_030633c8,
                               *(undefined4 *)(PTR_LAB_030633c8 + 4));
      *puVar1 = uVar13;
      puVar1[1] = uVar16;
    }
  }
  uVar13 = *PTR_DAT_03063650;
  uVar12 = PTR_DAT_03063650[1];
  uVar2 = soft_double_to_int(uVar13,uVar12);
  *param_9 = uVar2;
  iVar14 = softdouble_compare_gt
                     (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063660,
                      *(undefined4 *)(PTR_LAB_03063660 + 4));
  if (iVar14 < 1) {
    return 3;
  }
LAB_03063532:
  iVar14 = softdouble_compare_ne
                     (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063664,
                      *(undefined4 *)(PTR_LAB_03063664 + 4));
  if (iVar14 < 0) {
    iVar14 = softdouble_compare_ne
                       (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063668,
                        *(undefined4 *)(PTR_LAB_03063668 + 4));
    if ((iVar14 < 0) ||
       (iVar14 = softdouble_compare_gt
                           (uVar13,uVar12,*(undefined4 *)PTR_LAB_0306366c,
                            *(undefined4 *)(PTR_LAB_0306366c + 4)), 0 < iVar14)) {
      iVar14 = softdouble_compare_ne
                         (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063670,
                          *(undefined4 *)(PTR_LAB_03063670 + 4));
      if ((iVar14 < 0) ||
         (iVar14 = softdouble_compare_gt
                             (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063674,
                              *(undefined4 *)(PTR_LAB_03063674 + 4)), 0 < iVar14)) {
        iVar14 = softdouble_compare_ne
                           (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063678,
                            *(undefined4 *)(PTR_LAB_03063678 + 4));
        if ((iVar14 < 0) ||
           (iVar14 = softdouble_compare_gt
                               (uVar13,uVar12,*(undefined4 *)PTR_LAB_0306367c,
                                *(undefined4 *)(PTR_LAB_0306367c + 4)), 0 < iVar14)) {
          iVar14 = softdouble_compare_ne
                             (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063680,
                              *(undefined4 *)(PTR_LAB_03063680 + 4));
          if ((iVar14 < 0) ||
             (iVar14 = softdouble_compare_gt
                                 (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063684,
                                  *(undefined4 *)(PTR_LAB_03063684 + 4)), 0 < iVar14)) {
            iVar14 = softdouble_compare_ne
                               (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063688,
                                *(undefined4 *)(PTR_LAB_03063688 + 4));
            if ((iVar14 < 0) ||
               (iVar14 = softdouble_compare_gt
                                   (uVar13,uVar12,*(undefined4 *)PTR_LAB_0306368c,
                                    *(undefined4 *)(PTR_LAB_0306368c + 4)), 0 < iVar14)) {
              iVar14 = softdouble_compare_ne
                                 (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063690,
                                  *(undefined4 *)(PTR_LAB_03063690 + 4));
              if ((iVar14 < 0) ||
                 (iVar14 = softdouble_compare_gt
                                     (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063694,
                                      *(undefined4 *)(PTR_LAB_03063694 + 4)), 0 < iVar14)) {
                iVar14 = softdouble_compare_ne
                                   (uVar13,uVar12,*(undefined4 *)PTR_LAB_03063698,
                                    *(undefined4 *)(PTR_LAB_03063698 + 4));
                if (iVar14 < 0) {
                  uVar13 = 3;
                }
                else {
                  iVar14 = softdouble_compare_gt
                                     (uVar13,uVar12,*(undefined4 *)PTR_LAB_0306369c,
                                      *(undefined4 *)(PTR_LAB_0306369c + 4));
                  if (iVar14 < 1) {
                    uVar13 = 4;
                  }
                  else {
                    uVar13 = 3;
                  }
                }
              }
              else {
                uVar13 = 5;
              }
            }
            else {
              uVar13 = 6;
            }
          }
          else {
            uVar13 = 7;
          }
        }
        else {
          uVar13 = 8;
        }
      }
      else {
        uVar13 = 1;
      }
    }
    else {
      uVar13 = 2;
    }
  }
  else {
    uVar13 = 3;
  }
  return uVar13;
}

