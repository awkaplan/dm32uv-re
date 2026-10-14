/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_state_machine_step @ 030286d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1250 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_state_machine_step(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  dmr_call_config_state *pdVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  undefined1 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint in_r13;
  
  pcVar3 = _DAT_030288d8;
  pdVar5 = p_dmr_call_config_state;
  uVar12 = *_DAT_03028784;
  uVar8 = uVar12 & 3;
  uVar7 = uVar12 >> 8 & 0xf;
  uVar13 = uVar12 >> 0xc & 7;
  uVar15 = uVar12 >> 4 & 0xf;
  uVar16 = uVar12 >> 0x13 & 1;
  uVar17 = uVar12 >> 2 & 3;
  if ((*(byte *)(_DAT_03028788 + 7) & 2) != 0) {
    *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
    return;
  }
  if ((*(byte *)(_DAT_0302878c + 0x19) & 0x11) != 0) {
    return;
  }
  cVar1 = *(char *)(_DAT_03028790 + 1);
  if (cVar1 == '\0') {
    if (uVar17 == 0) {
      if (*(char *)((int)PTR_DAT_0302877c + (byte)~(*(char *)p_dmr_call_config_state != '\0') + 0xc)
          == '\x01') {
        return;
      }
      cVar1 = *(char *)((int)PTR_DAT_0302877c +
                       (byte)~(*(char *)p_dmr_call_config_state != '\0') + 0xe);
joined_r0x0302887c:
      if (cVar1 == '\x01') {
        return;
      }
    }
    else if (uVar17 == 1) {
      if (p_dmr_call_config_state->field_0x7 == 0) {
        if (((uVar8 - 1 & 0xff) < 2) && (in_r13 = uVar12 >> 0x18, in_r13 == 0)) {
          *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
          pdVar5->field_0x7 = 1;
          return;
        }
      }
      else {
        if (_DAT_030288d8[9] == '\0') {
          return;
        }
        if (*_DAT_030288d8 != *(char *)(_DAT_030288dc + 4)) {
          return;
        }
      }
    }
  }
  else if (cVar1 == '\x04') {
    if ((uVar8 - 1 & 0xff) < 2) {
      if (uVar17 == 2) {
        *_DAT_030288d8 = '\0';
      }
      else if (uVar17 == 3) {
        *_DAT_030288d8 = '\x01';
      }
      pcVar3 = _DAT_030288d8;
      pcVar3[0x10] = '\0';
      pcVar3[0x11] = '\0';
      pcVar3[0xc] = '\x01';
    }
    if ((*_DAT_030288d8 != _DAT_030288d8[2]) && (uVar8 == 2)) {
      if (uVar7 != 3) {
        return;
      }
      if (uVar15 != 0xf) {
        return;
      }
    }
  }
  else if (cVar1 == '\x01') {
    if (uVar17 == 1) {
      if (_DAT_030288d8[7] == '\0') {
        if (uVar8 == 2) {
          if (uVar7 == 9) {
            pcVar3[0x10] = '\0';
            pcVar3[0x11] = '\0';
            pcVar3[7] = '\x01';
            OSFlagPost_wrapper_set_fixed_grp(0x10000000);
            return;
          }
        }
        else if (1 < (uVar8 - 1 & 0xff)) goto LAB_03028914;
        in_r13 = uVar12 >> 0x18;
        if (in_r13 == 0) {
          pcVar3[0x10] = '\0';
          pcVar3[0x11] = '\0';
          pcVar3[7] = '\x01';
          return;
        }
      }
      else {
        if (_DAT_030288d8[9] == '\0') {
          return;
        }
        if (*_DAT_030288d8 != *(char *)(_DAT_030288dc + 4)) {
          return;
        }
      }
    }
    else if (uVar17 == 0) {
      if (*(char *)(_DAT_030288e0 + (uint)(byte)~(*_DAT_030288d8 != '\0') + 0xc) == '\x01') {
        return;
      }
      cVar1 = *(char *)(_DAT_030288e0 + (uint)(byte)~(*_DAT_030288d8 != '\0') + 0xe);
      goto joined_r0x0302887c;
    }
  }
  else if (cVar1 == '\x02') {
    if (_DAT_030288d8[7] == '\0') {
      if (uVar8 != 2) {
        return;
      }
      if (uVar7 == 3) {
        *(undefined4 *)(_DAT_030288e4 + 0x78) = 0;
        dmr_call_setup_message_handler();
        return;
      }
      in_r13 = uVar12 >> 0x18;
      if ((uVar17 == 1) && (in_r13 == 0)) {
        *(undefined4 *)(_DAT_030288e4 + 0x78) = 0;
        _DAT_030288d8[7] = '\x01';
        return;
      }
    }
    else {
      if (_DAT_030288d8[9] == '\0') {
        if (uVar8 != 2) {
          return;
        }
        if (uVar7 != 3) {
          return;
        }
        *(undefined4 *)(_DAT_030288e4 + 0x78) = 0;
        dmr_call_setup_message_handler();
        return;
      }
      if (*(char *)(_DAT_03028aa4 + 0x72) != '\x01') {
        if (uVar8 != 2) {
          return;
        }
        if (uVar7 != 3) {
          return;
        }
        *(undefined4 *)(_DAT_03028aa4 + 0x78) = 0;
        dmr_call_setup_message_handler();
        return;
      }
      if (*(byte *)(_DAT_03028aa8 + 4) != *_DAT_03028aac) {
        return;
      }
    }
  }
LAB_03028914:
  if (uVar13 != 0) {
    *_DAT_03028ab0 = (char)uVar13 + -1;
  }
  iVar9 = _DAT_03028c20;
  pbVar4 = _DAT_03028c14;
  uVar14 = (undefined1)uVar15;
  if (uVar8 != 0) {
    if (uVar8 == 1) {
      pbVar4[0x10] = 0;
      pbVar4[0x11] = 0;
      *(undefined4 *)(_DAT_03028c1c + 0x78) = 0;
      iVar9 = _DAT_03028c20;
      iVar10 = _DAT_03028c20 + (uint)*pbVar4;
      *(undefined1 *)(iVar10 + 0x12) = 0;
      pbVar4[3] = 1;
      *(char *)(iVar9 + 2) = (char)uVar17;
      if (*(char *)(iVar10 + 0xc) == '\0') {
        return;
      }
      if (*(char *)(_DAT_03028c24 + 1) == '\x04') {
        if (uVar16 == 0) {
          copy_bytes_from_offset_table
                    (0x36,_DAT_03028c20 + 0x88 + (uint)*(byte *)(_DAT_03028c20 + 0xbe) * 0x1b,0x1b);
        }
        else {
          copy_bytes_from_offset_table
                    (0x66,iVar9 + 0x88 + (uint)*(byte *)(iVar9 + 0xbe) * 0x1b,0x1b);
        }
      }
      else if (uVar16 == 0) {
        copy_bytes_from_offset_table
                  (0x39,_DAT_03028c20 + 0x88 + (uint)*(byte *)(_DAT_03028c20 + 0xbe) * 0x1b,0x1b);
      }
      else {
        copy_bytes_from_offset_table
                  (0x69,_DAT_03028c20 + 0x88 + (uint)*(byte *)(_DAT_03028c20 + 0xbe) * 0x1b,0x1b);
      }
      puVar6 = _DAT_03028c34;
      iVar10 = _DAT_03028c30;
      iVar9 = _DAT_03028c2c;
      if (*(char *)(_DAT_03028c28 + 2) != '\0') {
        FUN_0002b300(_DAT_03028c30,_DAT_03028c2c + (uint)*(byte *)(_DAT_03028c2c + 0x36) * 0x1b,
                     *_DAT_03028c34);
        FUN_0002b30c(iVar10 + -0x80,iVar9 + (uint)*(byte *)(iVar9 + 0x36) * 0x1b,*puVar6);
      }
      iVar9 = _DAT_03028c20;
      pcVar3 = (char *)(_DAT_03028c20 + 0xbe);
      *(char *)(_DAT_03028c20 + 0xbf) = *pcVar3;
      *(char *)(iVar9 + 0xbe) = ~(*pcVar3 != '\0');
      return;
    }
    if (uVar8 == 2) {
      *(char *)(_DAT_03028c20 + 2) = (char)uVar17;
      *(undefined1 *)(iVar9 + 6) = uVar14;
      if ((*(byte *)(_DAT_03028c24 + 5) != uVar15) && ((*(byte *)(_DAT_03028c38 + 0x18) & 8) == 0))
      {
        return;
      }
      *(undefined4 *)(_DAT_03028c1c + 0x78) = 0;
      if (10 < uVar7) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x03028c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(uint *)(_DAT_03028c3c + uVar7 * 4) & 0xfffffffe))();
      return;
    }
    if (uVar8 != 3) {
      return;
    }
    if (in_r13 != 0) {
      return;
    }
    *(undefined1 *)(_DAT_03028ddc + 6) = uVar14;
    return;
  }
  if ((uVar13 == 4) && ((byte)(*(char *)(_DAT_03028aa8 + 1) - 1U) < 2)) {
    iVar9 = (uint)*_DAT_03028aac * 0xc;
    if (*(char *)(iVar9 + _DAT_03028ab4) != '\0') {
      if (((*(byte *)((uint)*_DAT_03028aac + _DAT_03028ab8 + 2) & 0x30) == 0x30) &&
         (iVar9 = dmr_layer2_frame_build_and_send(_DAT_03028ab4 + iVar9), iVar9 == 0)) {
        *(undefined1 *)((uint)*_DAT_03028aac * 0xc + _DAT_03028ab4) = 0;
      }
      goto LAB_0302897c;
    }
  }
  if (uVar13 == 5) {
    *(byte *)(_DAT_03028abc + 5) = (byte)(uVar12 >> 0x11) & 1;
  }
LAB_0302897c:
  if (*(char *)((uint)*_DAT_03028aac + _DAT_03028ac0) != '\0') {
    pbVar4 = _DAT_03028aac;
    pbVar4[0x10] = 0;
    pbVar4[0x11] = 0;
    *(undefined1 *)(_DAT_03028abc + 6) = uVar14;
    if (*(char *)(_DAT_03028aa8 + 1) == '\x04') {
      if (uVar16 == 0) {
        copy_bytes_from_offset_table
                  (0x36,_DAT_03028abc + 0x88 + (uint)*(byte *)(_DAT_03028abc + 0xbe) * 0x1b,0x1b);
      }
      else {
        copy_bytes_from_offset_table
                  (0x66,_DAT_03028abc + 0x88 + (uint)*(byte *)(_DAT_03028abc + 0xbe) * 0x1b,0x1b);
      }
    }
    else if (uVar16 == 0) {
      copy_bytes_from_offset_table
                (0x39,_DAT_03028abc + 0x88 + (uint)*(byte *)(_DAT_03028abc + 0xbe) * 0x1b,0x1b);
    }
    else {
      copy_bytes_from_offset_table
                (0x69,_DAT_03028abc + 0x88 + (uint)*(byte *)(_DAT_03028abc + 0xbe) * 0x1b,0x1b);
    }
    iVar10 = _DAT_03028acc;
    iVar9 = _DAT_03028ac8;
    pcVar3 = _DAT_03028ab0;
    if (*(char *)(_DAT_03028ac4 + 2) != '\0') {
      FUN_0002b300(_DAT_03028acc,_DAT_03028ac8 + (uint)*(byte *)(_DAT_03028ac8 + 0x36) * 0x1b,
                   *_DAT_03028ab0);
      FUN_0002b30c(iVar10 + -0x80,iVar9 + (uint)*(byte *)(iVar9 + 0x36) * 0x1b,*pcVar3);
    }
    iVar9 = _DAT_03028abc;
    pcVar3 = (char *)(_DAT_03028abc + 0xbe);
    *(char *)(_DAT_03028abc + 0xbf) = *pcVar3;
    *(char *)(iVar9 + 0xbe) = ~(*pcVar3 != '\0');
    if (uVar13 == 6) {
      deferred_task_dispatch_on_timer_match();
    }
    if (*(byte *)(_DAT_03028aa8 + 5) == uVar15) {
      *(undefined1 *)((uint)*_DAT_03028c14 + _DAT_03028c18 + 2) = 0;
    }
    else {
      bVar2 = *_DAT_03028aac;
      iVar9 = (uint)bVar2 + _DAT_03028ad0;
      bVar11 = *(char *)(iVar9 + 2) + 1;
      *(byte *)(iVar9 + 2) = bVar11;
      if (6 < bVar11) {
        *(undefined1 *)((uint)bVar2 + _DAT_03028ac0) = 0;
        OSFlagPost_wrapper_set_fixed_grp(4);
      }
    }
  }
  return;
}

