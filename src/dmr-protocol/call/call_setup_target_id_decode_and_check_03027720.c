/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_target_id_decode_and_check @ 03027720 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1244 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool call_setup_target_id_decode_and_check(byte param_1,byte *param_2,uint *param_3,uint *param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 1) {
        pbVar7 = param_2 + 5;
        uVar3 = (uint)param_2[4] * 0x100 + (uint)param_2[3] * 0x10000 + (uint)*pbVar7;
        pbVar10 = param_2 + 7;
        pbVar8 = param_2 + 8;
        bVar5 = param_2[6];
        bVar1 = *pbVar10;
        bVar2 = *pbVar8;
        *param_3 = uVar3;
        *param_4 = (uint)bVar5 * 0x10000 + (uint)bVar1 * 0x100 + (uint)bVar2;
        if (0xffffef < uVar3) {
          return false;
        }
        bVar5 = *param_2 & 0x3f;
        if (bVar5 == 3) {
          if ((p_call_setup_sm_state->flags_0x18 & 8) != 0) {
            return false;
          }
          if (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 != uVar3) {
            return (p_call_setup_sm_state->flags_0x19 & 2) != 0;
          }
          return false;
        }
        if (bVar5 == 7) {
          *param_3 = uVar3;
          *param_4 = (uint)*pbVar10 * 0x100 + (uint)*pbVar8;
          return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
        }
        if ((*param_2 & 0x3f) != 0) {
          if (bVar5 != 4) {
            return true;
          }
          *param_3 = uVar3;
          *param_4 = (uint)*pbVar10 * 0x100 + (uint)*pbVar8;
          if (uVar3 != 0xff) {
            iVar4 = char_in_allowlist_table_check(*pbVar7);
            return iVar4 != 0;
          }
          return false;
        }
        if (p_call_setup_sm_state_aux->mode_0x1 == 2) {
          *param_3 = uVar3;
          *param_4 = (uint)*pbVar10 * 0x100 + (uint)*pbVar8;
          if (uVar3 != 0xff) {
            iVar4 = char_in_allowlist_table_check(*pbVar7);
            return iVar4 != 0;
          }
          return false;
        }
        if ((p_call_setup_sm_state->flags_0x19 & 4) == 0) {
          return false;
        }
        if ((p_call_setup_sm_state->flags_0x18 & 8) == 0) {
          if (*(uint *)&p_call_setup_sm_state_aux->field_0x2c_0 == uVar3) {
            return false;
          }
          puVar6 = PTR_DAT_030279b0;
          do {
            if (*puVar6 == uVar3) {
              return false;
            }
            puVar6 = puVar6 + 1;
          } while (puVar6 != PTR_DAT_030279b0 + 0x20);
          return true;
        }
        return false;
      }
    }
    else {
      if (param_1 == 3) {
        bVar5 = *param_2 & 0x3f;
        if ((param_2[1] == 0x10) && (bVar5 == 0x3e)) {
          return false;
        }
        if (((bVar5 == 0x26) || (bVar5 == 0x1d)) || ((bVar5 == 0x24 && (-1 < (char)param_2[3])))) {
          uVar3 = (uint)param_2[9] + (uint)param_2[7] * 0x10000 + (uint)param_2[8] * 0x100;
          uVar9 = (uint)param_2[5] * 0x100 + (uint)param_2[4] * 0x10000 + (uint)param_2[6];
        }
        else {
          uVar3 = (uint)param_2[6] + (uint)param_2[4] * 0x10000 + (uint)param_2[5] * 0x100;
          uVar9 = (uint)param_2[8] * 0x100 + (uint)param_2[7] * 0x10000 + (uint)param_2[9];
        }
        *param_3 = uVar3;
        *param_4 = uVar9;
        if (bVar5 == 0x27) {
          pbVar7 = &p_call_setup_sm_state_aux->field_0x2c_0;
          while ((*(uint *)pbVar7 != uVar3 ||
                 (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 == uVar9))) {
            pbVar7 = pbVar7 + 4;
            if (pbVar7 == &p_call_setup_sm_state_aux->field_0xb0) {
              return true;
            }
          }
          return false;
        }
        return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
      }
      if (param_1 == 6) {
        uVar3 = (uint)param_2[3] * 0x100 + (uint)param_2[2] * 0x10000 + (uint)param_2[4];
        uVar9 = (uint)param_2[6] * 0x100 + (uint)param_2[5] * 0x10000 + (uint)param_2[7];
        *param_3 = uVar3;
        *param_4 = uVar9;
        if ((char)*param_2 < '\0') {
          pbVar7 = &p_call_setup_sm_state_aux->field_0x2c_0;
          while ((*(uint *)pbVar7 != uVar3 ||
                 (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 == uVar9))) {
            pbVar7 = pbVar7 + 4;
            if (pbVar7 == &p_call_setup_sm_state_aux->field_0xb0) {
              return true;
            }
          }
          return false;
        }
        if (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 == uVar3) {
          if (uVar9 == *(uint *)&p_call_setup_sm_state_aux->field_0x24_0) {
            return (bool)~(p_call_setup_sm_state_aux->mode_0x1 != 1);
          }
          return false;
        }
        return true;
      }
    }
    return true;
  }
  bVar5 = *param_2 & 0x3f;
  if ((*param_2 & 0x3f) != 0) {
    if (bVar5 != 3) {
      if (bVar5 != 0x30) {
        return true;
      }
      uVar3 = (uint)param_2[4] + (uint)param_2[2] * 0x10000 + (uint)param_2[3] * 0x100;
      bVar5 = param_2[5];
      bVar1 = param_2[6];
      bVar2 = param_2[7];
      *param_3 = uVar3;
      *param_4 = (uint)bVar2 + (uint)bVar5 * 0x10000 + (uint)bVar1 * 0x100;
      if (-1 < (char)param_2[8]) {
        return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
      }
      return true;
    }
    uVar3 = (uint)param_2[5] + (uint)param_2[3] * 0x10000 + (uint)param_2[4] * 0x100;
    bVar5 = param_2[6];
    bVar1 = param_2[7];
    bVar2 = param_2[8];
    *param_3 = uVar3;
    *param_4 = (uint)bVar5 * 0x10000 + (uint)bVar1 * 0x100 + (uint)bVar2;
    if (0xffffef < uVar3) {
      return false;
    }
    if ((p_call_setup_sm_state->flags_0x18 & 8) == 0) {
      if ((uVar3 == 0) && ((param_2[2] & 0x30) == 0x10)) {
        uVar3 = (uint)param_2[6] * 0x10000 + (uint)param_2[7] * 0x100 + (uint)param_2[8];
        *param_3 = uVar3;
        *param_4 = 0;
        return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
      }
      if (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 != uVar3) {
        return (p_call_setup_sm_state->flags_0x19 & 2) != 0;
      }
      return false;
    }
    return false;
  }
  uVar3 = (uint)param_2[5] + (uint)param_2[3] * 0x10000 + (uint)param_2[4] * 0x100;
  pbVar8 = param_2 + 7;
  pbVar7 = param_2 + 8;
  bVar5 = param_2[6];
  bVar1 = *pbVar8;
  bVar2 = *pbVar7;
  *param_3 = uVar3;
  *param_4 = (uint)bVar5 * 0x10000 + (uint)bVar1 * 0x100 + (uint)bVar2;
  if (0xffffef < uVar3) {
    return false;
  }
  if ((p_call_setup_sm_state->flags_0x18 & 8) != 0) {
    return false;
  }
  if (p_call_setup_sm_state_aux->mode_0x1 == 2) {
    if (uVar3 == 0) {
      if ((param_2[2] & 0x30) == 0x10) {
        uVar3 = (uint)*pbVar8 * 0x100 + (uint)*pbVar7;
        *param_3 = uVar3;
        *param_4 = 0;
        return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
      }
      *param_3 = 0;
      *param_4 = (uint)*pbVar8 * 0x100 + (uint)*pbVar7;
    }
    else {
      *param_3 = uVar3;
      *param_4 = (uint)*pbVar8 * 0x100 + (uint)*pbVar7;
      if (uVar3 == 0xff) {
        return false;
      }
    }
    iVar4 = char_in_allowlist_table_check(param_2[5]);
    return iVar4 != 0;
  }
  if ((uVar3 == 0) && ((param_2[2] & 0x30) == 0x10)) {
    uVar3 = (uint)param_2[6] * 0x10000 + (uint)*pbVar8 * 0x100 + (uint)*pbVar7;
    *param_3 = uVar3;
    *param_4 = 0;
    return uVar3 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0;
  }
  if ((p_call_setup_sm_state->flags_0x19 & 4) == 0) {
    return false;
  }
  if (*(uint *)&p_call_setup_sm_state_aux->field_0x2c_0 != uVar3) {
    puVar6 = PTR_DAT_03027bac;
    do {
      if (*puVar6 == uVar3) {
        return false;
      }
      puVar6 = puVar6 + 1;
    } while (puVar6 != PTR_DAT_03027bac + 0x20);
    return true;
  }
  return false;
}

