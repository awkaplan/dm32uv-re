/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_alloc_with_overflow_guard @ 0306be3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 868 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_block_alloc_with_overflow_guard
               (undefined4 *param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6,
               uint *param_7,int *param_8)

{
  undefined4 sr;
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uStack_48;
  undefined4 *puStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_28;
  
  if (param_8 == (int *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_7 == (uint *)0x0) {
    param_7 = &uStack_28;
  }
  *param_7 = 0;
  result_struct_init_or_null_delegate(param_1,param_8);
  if (*param_8 == 10000) {
    if ((param_2 == 0) || (param_3 != 0)) {
      if (param_4 == 0) {
        *param_8 = 0x2792;
      }
      else if (param_5 == 0) {
        *param_8 = 0x2793;
      }
      else if (param_6 == 0) {
        *param_8 = 0x2794;
      }
      else if (*PTR_DAT_0306bf44 == 0) {
        *param_8 = 0x27e7;
      }
      else {
        sr = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        if (param_2 == 0) {
          iStack_3c = PTR_DAT_0306bf3c[0xf];
          uVar1 = padded_block_total_size_with_overflow_guard(iStack_3c,param_4,4,4);
          if (uVar1 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x27e3;
            return;
          }
          iStack_3c = iStack_3c + uVar1;
          uStack_48 = padded_block_total_size_with_overflow_guard(iStack_3c,param_4,param_5,param_6)
          ;
          if (uStack_48 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x27e3;
            return;
          }
          uStack_38 = uStack_48 + uVar1;
          if ((uStack_38 < uVar1) || (uStack_38 < uStack_48)) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x27e3;
            return;
          }
          uVar1 = PTR_DAT_0306c0cc[0x11];
          if (uVar1 < uStack_38) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_7 = uStack_38 - uVar1;
            *param_8 = 0x27e2;
            return;
          }
          puStack_40 = PTR_DAT_0306c0cc;
          puVar7 = PTR_DAT_0306c0cc;
          puVar10 = PTR_DAT_0306c0cc;
        }
        else {
          uVar1 = param_3 + -1 + param_2;
          if (uVar1 < param_2) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x2797;
            return;
          }
          puVar6 = (undefined4 *)*_DAT_0306c0d0;
          if (puVar6 == (undefined4 *)0x0) {
            puVar10 = (undefined4 *)0x0;
          }
          else {
            puVar10 = (undefined4 *)0x0;
            do {
              puVar7 = puVar6;
              uVar5 = puVar7[0xe];
              puVar6 = puVar7;
              if (uVar5 == param_2) {
                if (puVar7[0x10] != param_3) {
LAB_0306bfbe:
                  OS_SchedLockTimeMeasStop();
                  cpu_sr_restore_irq_iram(sr);
                  *param_8 = 0x277f;
                  return;
                }
                puStack_40 = puVar7;
                if (puVar7 != (undefined4 *)0x0) goto LAB_0306bff2;
                break;
              }
              if (uVar1 < uVar5) break;
              uVar4 = uVar5 + puVar7[0x10] + -1;
              if (((param_2 <= uVar5) || (uVar1 <= uVar4)) || (param_2 <= uVar4)) goto LAB_0306bfbe;
              puVar6 = (undefined4 *)puVar7[3];
              puVar10 = puVar7;
            } while (puVar6 != (undefined4 *)0x0);
          }
          param_1[0xe] = param_2;
          param_1[0xf] = param_2;
          param_1[0x10] = param_3;
          param_1[0x11] = param_3;
          puVar7 = puVar6;
          puStack_40 = param_1;
LAB_0306bff2:
          uVar1 = padded_block_total_size_with_overflow_guard(PTR_DAT_0306c0cc[0xf],param_4,4,4);
          if (uVar1 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x27e3;
            return;
          }
          uVar5 = PTR_DAT_0306c0cc[0x11];
          if (uVar5 < uVar1) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_7 = uVar1 - uVar5;
            *param_8 = 0x27e2;
            return;
          }
          iStack_3c = puStack_40[0xf];
          uStack_48 = padded_block_total_size_with_overflow_guard(iStack_3c,param_4,param_5,param_6)
          ;
          if (uStack_48 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_8 = 0x27d9;
            return;
          }
          uVar1 = puStack_40[0x11];
          if (uVar1 < uStack_48) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_7 = uStack_48 - uVar1;
            *param_8 = 0x27d8;
            return;
          }
          uStack_38 = 0;
        }
        uVar1 = param_4 * 4;
        piVar2 = (int *)FUN_0306ba04(PTR_DAT_0306c0cc,uVar1,4);
        if (piVar2 == (int *)0x0) {
          uVar5 = PTR_DAT_0306c0cc[0x11];
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          if (param_2 == 0) {
            if (uVar5 < uStack_38) {
              *param_7 = uStack_38 - uVar5;
            }
            else {
              *param_7 = uStack_38;
            }
          }
          else if (uVar5 < uVar1) {
            *param_7 = uVar1 - uVar5;
          }
          else {
            *param_7 = uVar1;
          }
          *param_8 = 0x27e2;
        }
        else {
          uVar1 = 0;
          piVar9 = piVar2;
          do {
            iVar3 = FUN_0306ba04(puStack_40,param_5,param_6);
            if (iVar3 == 0) {
              uVar8 = puStack_40[0xf];
              uVar5 = puStack_40[0x11];
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(sr);
              uVar1 = padded_block_total_size_with_overflow_guard
                                (uVar8,param_4 - uVar1,param_5,param_6);
              if (uVar5 < uVar1) {
                *param_7 = uVar1 - uVar5;
              }
              else {
                *param_7 = uVar1;
              }
              *param_8 = 0x27d8;
              return;
            }
            *piVar9 = iVar3;
            uVar1 = uVar1 + 1;
            piVar9 = piVar9 + 1;
          } while (uVar1 < param_4);
          if (puStack_40 == param_1) {
            puStack_40[2] = puVar10;
            puStack_40[3] = puVar7;
            if (puVar10 == (undefined4 *)0x0) {
              *PTR_DAT_0306c300 = param_1;
            }
            else {
              puVar10[3] = puStack_40;
            }
            if (puVar7 != (undefined4 *)0x0) {
              puVar7[2] = param_1;
            }
          }
          else {
            iVar3 = puStack_40[5];
            param_1[4] = puStack_40;
            param_1[5] = iVar3;
            puStack_40[5] = param_1;
            if (iVar3 != 0) {
              *(undefined4 **)(iVar3 + 0x10) = param_1;
            }
          }
          *param_1 = DAT_0306c304;
          param_1[1] = puStack_40;
          param_1[6] = iStack_3c;
          param_1[7] = iStack_3c + (uStack_48 - 1);
          param_1[8] = piVar2;
          param_1[10] = uStack_48;
          param_1[0xd] = param_6;
          param_1[0xc] = param_5;
          param_1[0xb] = param_4;
          param_1[9] = param_4;
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_8 = 10000;
        }
      }
    }
    else {
      *param_8 = 0x277e;
    }
  }
  return;
}

