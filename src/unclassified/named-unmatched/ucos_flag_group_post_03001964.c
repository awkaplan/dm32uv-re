/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_flag_group_post @ 03001964 (file base 0x03000000; code starts at 0x03001000)
 * Size: 440 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
ucos_flag_group_post(int param_1,uint param_2,short param_3,undefined4 param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  func_0x000101f4();
  if (param_3 != 1) {
    if ((param_3 == 0) || (param_3 == -0x8000)) {
      *(uint *)(param_1 + 0x14) = param_2 | *(uint *)(param_1 + 0x14);
      goto LAB_030019be;
    }
    if (param_3 != -0x7fff) {
      irq_lock_release_global_value();
      cpu_sr_restore_irq_iram(uVar2);
      *param_5 = 0x5e25;
      return 0;
    }
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
LAB_030019be:
  *(undefined4 *)(param_1 + 0x18) = param_4;
  if (*(short *)(param_1 + 0x10) == 0) {
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0;
    uVar6 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    cVar1 = *(char *)PTR_LAB_03001b1c;
    *(char *)PTR_LAB_03001b1c = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      FUN_00010b3c();
    }
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    iVar7 = *(int *)(param_1 + 8);
    iVar3 = *(int *)(iVar7 + 8);
    while (iVar3 != 0) {
      iVar7 = *(int *)(iVar7 + 4);
      uVar5 = *(ushort *)(iVar3 + 100) & 0xf;
      if (uVar5 == 2) {
        uVar4 = *(uint *)(iVar3 + 0x5c) & ~*(uint *)(param_1 + 0x14);
        if (uVar4 != 0) {
          state_machine_field_init_with_mode_normalize(iVar3,uVar4,param_4);
        }
      }
      else if (uVar5 < 3) {
        if (uVar5 != 1) {
LAB_03001a6c:
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          func_0x000101f4();
          cVar1 = *(char *)PTR_LAB_03001b1c;
          *(char *)PTR_LAB_03001b1c = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            FUN_00010b58();
            if (*(short *)PTR_DAT_03001b20 == 0) {
              irq_lock_release_global_value();
              cpu_sr_restore_irq_iram(uVar2);
            }
            else {
              irq_lock_release_global_value();
              cpu_sr_restore_irq_iram(uVar2);
              func_0x00010b04();
            }
          }
          else {
            irq_lock_release_global_value();
            cpu_sr_restore_irq_iram(uVar2);
          }
          *param_5 = 0x3aff;
          return 0;
        }
        uVar4 = *(uint *)(iVar3 + 0x5c);
        if (uVar4 == (uVar4 & ~*(uint *)(param_1 + 0x14))) {
          state_machine_field_init_with_mode_normalize(iVar3,uVar4,param_4);
        }
      }
      else if (uVar5 == 4) {
        uVar4 = *(uint *)(iVar3 + 0x5c);
        if (uVar4 == (*(uint *)(param_1 + 0x14) & uVar4)) {
          state_machine_field_init_with_mode_normalize(iVar3,uVar4,param_4);
        }
      }
      else {
        if (uVar5 != 8) goto LAB_03001a6c;
        uVar4 = *(uint *)(iVar3 + 0x5c) & *(uint *)(param_1 + 0x14);
        if (uVar4 != 0) {
          state_machine_field_init_with_mode_normalize(iVar3,uVar4,param_4);
        }
      }
      if (iVar7 == 0) break;
      iVar3 = *(int *)(iVar7 + 8);
    }
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    func_0x000101f4();
    cVar1 = *(char *)PTR_LAB_03001b1c;
    *(char *)PTR_LAB_03001b1c = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      FUN_00010b58();
    }
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    if (-1 < param_3) {
      FUN_000105b4();
    }
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    func_0x000101f4();
    uVar6 = *(undefined4 *)(param_1 + 0x14);
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0;
  }
  return uVar6;
}

