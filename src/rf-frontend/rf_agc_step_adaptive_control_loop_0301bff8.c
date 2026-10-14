/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_agc_step_adaptive_control_loop @ 0301bff8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 374 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_agc_step_adaptive_control_loop(uint param_1)

{
  short sVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  short sVar5;
  uint uVar6;
  char *pcVar7;
  uint *puVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  
  if ((((*(char *)PTR_DAT_0301c174 != '\0') && (*(char *)PTR_DAT_0301c178 != '\0')) && (param_1 < 2)
      ) && ((*(byte *)p_call_active_flag & 8) == 0)) {
    sVar5 = reg_0x67_lower9_read();
    puVar3 = PTR_DAT_0301c170;
    sVar1 = *(short *)((int)PTR_DAT_0301c170 + param_1 * 2 + 8);
    sVar9 = sVar5;
    if (0 < sVar1) {
      iVar10 = (int)sVar5 + (int)sVar1;
      sVar9 = (short)((uint)(iVar10 - (iVar10 >> 0x1f)) >> 1);
    }
    *(short *)((int)PTR_DAT_0301c170 + param_1 * 2 + 8) = sVar5;
    if (puVar3[param_1 + 3] != 0) {
      PTR_DAT_0301c170[param_1 + 3] = puVar3[param_1 + 3] + -1;
    }
    sVar1 = (short)((uint)((sVar9 + -0x8e) - (sVar9 + -0x8e >> 0x1f)) >> 1);
    if (0 < sVar1) {
      uVar6 = PTR_DAT_0301c170[param_1];
      uVar11 = uVar6;
      if (sVar1 < 10) {
        if (1 < uVar6) {
          uVar11 = uVar6 - 1;
        }
      }
      else if (1 < uVar6) {
        sVar9 = ((char)PTR_LAB_0301c180[uVar6 * 3 + 2] + 8) - sVar1;
        uVar11 = uVar6 - 1;
        if (sVar9 < (char)PTR_LAB_0301c180[uVar11 * 3 + 2]) {
          pcVar7 = PTR_LAB_0301c184 + (uVar6 - 2) * 3;
          do {
            if (uVar11 < 2) break;
            uVar11 = uVar11 - 1;
            cVar2 = *pcVar7;
            pcVar7 = pcVar7 + -3;
          } while (sVar9 < cVar2);
        }
      }
      if (uVar11 == 0) {
        uVar11 = 1;
      }
      if (uVar6 != uVar11) {
        puVar8 = PTR_DAT_0301c170 + param_1;
        *puVar8 = uVar11;
        puVar8[3] = 0x1e;
      }
    }
    if (sVar1 < -6) {
      if (PTR_DAT_0301c170[param_1 + 3] == 0) {
        uVar11 = PTR_DAT_0301c170[param_1] + 1;
        if (0x2a < uVar11) {
          uVar11 = 0x2a;
        }
        PTR_DAT_0301c170[param_1] = uVar11;
      }
    }
    else {
      PTR_DAT_0301c170[param_1 + 3] = 0x1e;
    }
    iVar10 = PTR_DAT_0301c170[param_1];
    (PTR_DAT_0301c170 + param_1)[5] = iVar10;
    puVar4 = PTR_LAB_0301c180;
    iVar10 = iVar10 * 3;
    *(char *)PTR_DAT_0301c188 = -7 - PTR_LAB_0301c180[iVar10 + 2];
    fd6818b_reg_write(FD6818_PAGE0_REG_13H,CONCAT11(puVar4[iVar10 + 1],puVar4[iVar10]));
  }
  return;
}

