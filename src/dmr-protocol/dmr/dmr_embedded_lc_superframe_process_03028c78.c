/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_embedded_lc_superframe_process @ 03028c78 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1716 bytes
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

void dmr_embedded_lc_superframe_process(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  
  if ((*(byte *)(_DAT_03028de0 + 0x19) & 0x11) != 0) {
    return;
  }
  uVar9 = *_DAT_03028de4;
  uVar10 = uVar9 >> 2 & 3;
  cVar1 = *(char *)(_DAT_03028de8 + 1);
  if (cVar1 == '\0') {
    if (uVar10 == 0) {
      cVar1 = *(char *)(_DAT_03028ddc + (uint)(byte)~(*_DAT_03028dec != 0) + 0xc);
joined_r0x03028d2c:
      if (cVar1 == '\x01') {
        return;
      }
    }
    else if (uVar10 == 1) {
      if (_DAT_03028dec[7] == 0) {
        return;
      }
      if (_DAT_03028dec[9] == 0) {
        return;
      }
      if (*_DAT_03028dec != *(byte *)(_DAT_03028de8 + 4)) {
        return;
      }
    }
  }
  else if (cVar1 == '\x04') {
    if (_DAT_03028dec[0xc] == 0) {
      return;
    }
    if (*_DAT_03028dec != _DAT_03028dec[2]) {
      return;
    }
  }
  else if (cVar1 == '\x01') {
    if (uVar10 == 1) {
      if (_DAT_03028dec[7] == 0) {
        return;
      }
      if (_DAT_03028dec[9] == 0) {
        return;
      }
      if (*_DAT_03028dec != *(byte *)(_DAT_03028de8 + 4)) {
        return;
      }
    }
    else if (uVar10 == 0) {
      cVar1 = *(char *)(_DAT_03028ddc + (uint)(byte)~(*_DAT_03028dec != 0) + 0xc);
      goto joined_r0x03028d2c;
    }
  }
  else if (cVar1 == '\x02') {
    if (*(char *)(_DAT_03028df0 + 0x72) == '\0') {
      return;
    }
    if (_DAT_03028dec[7] == 0) {
      return;
    }
    if (_DAT_03028dec[9] == 0) {
      return;
    }
    if (*_DAT_03028dec != *(byte *)(_DAT_03028de8 + 4)) {
      return;
    }
  }
  _DAT_03028dec[3] = 1;
  *(byte *)(_DAT_03028ddc + 6) = (byte)(uVar9 >> 4) & 0xf;
  if ((uVar9 >> 0x19 & 1) != 0) {
    return;
  }
  if (((uint)*(byte *)(_DAT_03028de8 + 5) != (uVar9 >> 4 & 0xf)) &&
     ((*(byte *)(_DAT_03028de0 + 0x18) & 8) == 0)) {
    return;
  }
  uVar9 = uVar9 >> 0x11 & 1;
  *(char *)(_DAT_03028ddc + 5) = (char)uVar9;
  iVar11 = _DAT_03028f8c;
  if (uVar9 == 1) {
    bVar2 = *_DAT_03028dec;
    if (*(char *)((uint)bVar2 + _DAT_03028df4) == '\0') {
      return;
    }
    pbVar4 = _DAT_03028dec;
    pbVar4[0x10] = 0;
    pbVar4[0x11] = 0;
    if ((*(byte *)(_DAT_03028df8 + 0x10) & 2) != 0) {
      return;
    }
    copy_bytes_from_offset_table(0,_DAT_03028dfc + (uint)bVar2 * 0xc,9);
    OSFlagPost_wrapper_set_fixed_grp(0x4000);
    return;
  }
  *(undefined1 *)(_DAT_03028f8c + 5) = 0;
  pbVar4 = _DAT_03028f90;
  iVar13 = iVar11 + 0x28;
  copy_bytes_from_offset_table(0,(uint)*_DAT_03028f90 * 0xc + iVar13,9);
  iVar11 = iVar11 + (uint)*pbVar4 * 0xc;
  cVar1 = *(char *)(iVar11 + 0x29);
  bVar2 = *(byte *)(iVar11 + 0x28);
  uVar9 = bVar2 & 0x3f;
  if ((bVar2 & 4) != 0) {
    uVar12 = bVar2 & 7;
    if (uVar12 == 4) {
      if ((*(byte *)(_DAT_03028f94 + 3) & 1) == 0) {
        *(byte *)(_DAT_03028f94 + 3) = *(byte *)(_DAT_03028f94 + 3) & 0xfe | 1;
      }
      else {
        *(byte *)(_DAT_03028f94 + 3) = *(byte *)(_DAT_03028f94 + 3) & 0xfc | 2;
        OSFlagPost_wrapper_set_fixed_grp(0x40000000);
      }
    }
    iVar6 = _DAT_03028f94;
    iVar11 = _DAT_03028f8c;
    if ((*(byte *)(_DAT_03028f94 + 3) & 1) != 0) {
      if (uVar12 == 4) {
        bVar8 = *_DAT_03028f90;
        bVar7 = *(byte *)(_DAT_03028f8c + (uint)bVar8 * 0xc + 0x2a);
        *(byte *)(_DAT_03028f94 + 3) = *(byte *)(_DAT_03028f94 + 3) & 0x87 | (bVar7 >> 6) << 3;
        *(byte *)(iVar6 + 4) = bVar7 >> 1 & 0x1f;
        memcpy_bytes_iram(iVar6 + 5,iVar11 + (uint)bVar8 * 0xc + 0x2a,7);
      }
      else {
        memcpy_bytes_iram(_DAT_03028f98 + uVar12 * 7,_DAT_03028f9c + (uint)*_DAT_03028f90 * 0xc,7);
        if (uVar12 == 7) {
          OSFlagPost_wrapper_set_fixed_grp(0x40000000);
        }
      }
    }
  }
  if ((cVar1 != '\0') || ((*(byte *)(_DAT_03028f94 + 3) & 3) != 0)) {
    if (cVar1 != '\x10') {
      return;
    }
    if ((*(byte *)(_DAT_0302912c + 3) & 1) != 0) {
      return;
    }
    pbVar4 = _DAT_03029128;
    pbVar4[0x10] = 0;
    pbVar4[0x11] = 0;
    if (*(char *)(_DAT_03029130 + 1) == '\x02') {
      *(undefined4 *)(_DAT_03029134 + 0x78) = 0;
      iVar11 = call_setup_target_id_decode_and_check
                         (1,(uint)*_DAT_03029128 * 0xc + iVar13,auStack_1c,&uStack_20);
      if (iVar11 == 0) {
        bVar8 = *_DAT_03029128;
        bVar7 = *(byte *)(_DAT_03029124 + (uint)bVar8 * 0xc + 0x2a);
        *(byte *)(_DAT_03029124 + 0xb) = bVar7;
        bVar7 = bVar7 & 0x30;
        if ((bVar7 == 0x20) || (bVar7 == 0x30)) {
          *(undefined1 *)(_DAT_03029124 + 9) = 1;
          *(undefined4 *)((uint)bVar8 * 0xc + _DAT_03029138) = uStack_20;
        }
        else {
          *(undefined1 *)(_DAT_03029124 + 9) = 0;
        }
        iVar11 = _DAT_03029124;
        uVar10 = (uint)*_DAT_03029128;
        iVar13 = _DAT_03029124 + uVar10;
        *(undefined1 *)(iVar13 + 0x12) = 0;
        *(undefined1 *)(iVar13 + 0x10) = 0;
        iVar11 = iVar11 + uVar10 * 0xc;
        iVar11 = (uint)*(byte *)(iVar11 + 0x2f) * 0x100 + (uint)*(byte *)(iVar11 + 0x2e) * 0x10000 +
                 (uint)*(byte *)(iVar11 + 0x30);
        if ((*(char *)(iVar13 + 0xc) != '\x01') ||
           (*(int *)(_DAT_03029124 + (uVar10 + 8) * 4) != iVar11)) {
          *(undefined1 *)(uVar10 + _DAT_0302913c) = 1;
          if ((bVar2 & 0x3f) == 0) {
            *(undefined1 *)(_DAT_03029124 + 8) = 1;
          }
          else if (uVar9 == 3) {
            *(undefined1 *)(_DAT_03029124 + 8) = 0;
          }
          iVar13 = _DAT_03029124;
          uVar9 = (uint)*_DAT_03029128;
          iVar6 = _DAT_03029124 + uVar9 * 0xc;
          *(uint *)(_DAT_03029124 + (uVar9 + 6) * 4) =
               (uint)*(byte *)(iVar6 + 0x2d) +
               (uint)*(byte *)(iVar6 + 0x2c) * 0x100 + (uint)*(byte *)(iVar6 + 0x2b) * 0x10000;
          *(int *)(iVar13 + (uVar9 + 8) * 4) = iVar11;
          OSFlagPost_wrapper_set_fixed_grp(2);
        }
      }
      else {
        if (*(char *)(_DAT_030292b4 + 0x15) == '\0') {
          *(undefined1 *)(_DAT_030292b8 + 0x74) = 1;
        }
        if (*(char *)(_DAT_030292b8 + 0x75) != '\0') {
          bVar2 = *_DAT_030292bc;
          bVar8 = *(byte *)(_DAT_030292c0 + (uint)bVar2 * 0xc + 0x2a);
          *(byte *)(_DAT_030292c0 + 0xb) = bVar8;
          bVar8 = bVar8 & 0x30;
          if ((bVar8 == 0x20) || (bVar8 == 0x30)) {
            *(undefined1 *)(_DAT_030292c0 + 9) = 1;
            *(undefined4 *)((uint)bVar2 * 0xc + _DAT_030292c4) = uStack_20;
          }
          else {
            *(undefined1 *)(_DAT_030292c0 + 9) = 0;
          }
        }
      }
      uVar3 = *(undefined1 *)(_DAT_030292c0 + (uint)*_DAT_030292bc * 0xc + 0x2a);
      iVar11 = _DAT_030292c0 + (uint)*_DAT_030292bc;
      *(undefined1 *)(iVar11 + 0x14) = uVar3;
      *(undefined1 *)(iVar11 + 0x16) = uVar3;
      return;
    }
    iVar13 = call_setup_target_id_decode_and_check
                       (1,(uint)*_DAT_030292bc * 0xc + iVar13,auStack_1c,&uStack_20);
    iVar11 = _DAT_030292c0;
    if (iVar13 == 0) {
      *(undefined1 *)(_DAT_030292c0 + 10) = 0;
      bVar8 = *_DAT_030292bc;
      bVar7 = *(byte *)(iVar11 + (uint)bVar8 * 0xc + 0x2a);
      *(byte *)(iVar11 + 0xb) = bVar7;
      bVar7 = bVar7 & 0x30;
      if ((bVar7 == 0x20) || (bVar7 == 0x30)) {
        *(undefined1 *)(_DAT_030292c0 + 9) = 1;
        *(undefined4 *)((uint)bVar8 * 0xc + _DAT_030292c4) = uStack_20;
      }
      else {
        *(undefined1 *)(_DAT_030292c0 + 9) = 0;
      }
      pbVar4 = _DAT_030292bc;
      if (uVar10 == 0) {
        bVar8 = *_DAT_030292bc;
        _DAT_030292bc[2] = bVar8;
        pbVar4[4] = bVar8;
      }
      iVar11 = _DAT_030292c0;
      uVar10 = (uint)*_DAT_030292bc;
      iVar13 = _DAT_030292c0 + uVar10;
      *(undefined1 *)(iVar13 + 0x12) = 0;
      *(undefined1 *)(iVar13 + 0x10) = 0;
      iVar11 = iVar11 + uVar10 * 0xc;
      iVar11 = (uint)*(byte *)(iVar11 + 0x2f) * 0x100 + (uint)*(byte *)(iVar11 + 0x2e) * 0x10000 +
               (uint)*(byte *)(iVar11 + 0x30);
      if ((*(char *)(iVar13 + 0xc) != '\x01') ||
         (*(int *)(_DAT_030292c0 + (uVar10 + 8) * 4) != iVar11)) {
        *(undefined1 *)(uVar10 + _DAT_030292c8) = 1;
        if ((bVar2 & 0x3f) == 0) {
          *(undefined1 *)(_DAT_030292c0 + 8) = 1;
        }
        else if (uVar9 == 3) {
          *(undefined1 *)(_DAT_030292c0 + 8) = 0;
        }
        iVar13 = _DAT_030292c0;
        uVar9 = (uint)*_DAT_030292bc;
        iVar6 = _DAT_030292c0 + uVar9 * 0xc;
        *(uint *)(_DAT_030292c0 + (uVar9 + 6) * 4) =
             (uint)*(byte *)(iVar6 + 0x2d) +
             (uint)*(byte *)(iVar6 + 0x2c) * 0x100 + (uint)*(byte *)(iVar6 + 0x2b) * 0x10000;
        *(int *)(iVar13 + (uVar9 + 8) * 4) = iVar11;
        OSFlagPost_wrapper_set_fixed_grp(2);
      }
    }
    else {
      bVar2 = *_DAT_030293fc;
      bVar8 = PTR_DAT_03029400[(uint)bVar2 * 0xc + 0x2a];
      PTR_DAT_03029400[0xb] = bVar8;
      bVar8 = bVar8 & 0x30;
      if ((bVar8 == 0x20) || (bVar8 == 0x30)) {
        PTR_DAT_03029400[9] = 1;
        *(undefined4 *)((uint)bVar2 * 0xc + _DAT_03029404) = uStack_20;
        pbVar4 = _DAT_030293fc;
        if (uVar10 == 0) {
          _DAT_030293fc[2] = bVar2;
          pbVar4[4] = bVar2;
        }
      }
      else {
        PTR_DAT_03029400[9] = 0;
      }
    }
    puVar5 = PTR_DAT_03029400;
    uVar9 = (uint)*_DAT_030293fc;
    if (*(char *)(uVar9 * 0xc + _DAT_03029408) != '\0') {
      bVar2 = PTR_DAT_03029400[uVar9 * 0xc + 0x2a];
      PTR_DAT_03029400[uVar9 + 0x14] = bVar2;
      if ((bVar2 & 0x30) == 0x20) {
        if ((((*(char *)(_DAT_0302940c + 1) == '\0') || (*(char *)(_DAT_0302940c + 1) == '\x04')) &&
            ((*(byte *)(uVar9 + _DAT_03029410 + 2) & 0x30) == 0x30)) &&
           (iVar11 = dmr_layer2_frame_build_and_send(_DAT_03029408 + uVar9 * 0xc), iVar11 == 0)) {
          *(undefined1 *)((uint)*_DAT_030293fc * 0xc + _DAT_03029408) = 0;
        }
        ((undefined1 *)((uint)*_DAT_030293fc + _DAT_03029410))[2] =
             *(undefined1 *)((uint)*_DAT_030293fc + _DAT_03029410);
        return;
      }
      *(byte *)(uVar9 + _DAT_03029410 + 2) = bVar2;
      return;
    }
    uVar3 = PTR_DAT_03029400[uVar9 * 0xc + 0x2a];
    PTR_DAT_03029400[uVar9 + 0x14] = uVar3;
    puVar5[uVar9 + 0x16] = uVar3;
    return;
  }
  if (*_DAT_03028fa0 != '\0') {
    return;
  }
  iVar11 = call_setup_target_id_decode_and_check
                     (1,(uint)*_DAT_03028f90 * 0xc + iVar13,auStack_1c,&uStack_20);
  pbVar4 = _DAT_03028f90;
  if (iVar11 != 0) {
    return;
  }
  pbVar4[0x10] = 0;
  pbVar4[0x11] = 0;
  bVar8 = *pbVar4;
  uVar12 = (uint)bVar8;
  *(undefined1 *)(_DAT_03028f8c + 0xb) = *(undefined1 *)(_DAT_03028f8c + uVar12 * 0xc + 0x2a);
  if (uVar10 == 0) {
    _DAT_03028f90[2] = bVar8;
  }
  iVar11 = _DAT_03028f8c;
  *(undefined1 *)(_DAT_03028f8c + 9) = 0;
  iVar13 = iVar11 + uVar12;
  *(undefined1 *)(iVar13 + 0x12) = 0;
  *(undefined1 *)(iVar13 + 0x10) = 0;
  iVar11 = iVar11 + uVar12 * 0xc;
  iVar11 = (uint)*(byte *)(iVar11 + 0x2f) * 0x100 + (uint)*(byte *)(iVar11 + 0x2e) * 0x10000 +
           (uint)*(byte *)(iVar11 + 0x30);
  if ((*(char *)(iVar13 + 0xc) == '\x01') && (*(int *)(_DAT_03028f8c + (uVar12 + 8) * 4) == iVar11))
  {
    return;
  }
  *(undefined1 *)(uVar12 + _DAT_03028fa4) = 1;
  if ((bVar2 & 0x3f) == 0) {
    *(undefined1 *)(_DAT_03028f8c + 8) = 1;
  }
  else {
    if (uVar9 == 3) {
      *(undefined1 *)(_DAT_03029124 + 8) = 0;
    }
    else if (*(char *)(_DAT_03029124 + 8) != '\0') goto LAB_03028fd4;
    if ((*(byte *)(_DAT_03029124 + 0xb) >> 4 & 2) != 0) {
      *(undefined1 *)(_DAT_03029124 + 10) = 1;
      goto LAB_03028fda;
    }
  }
LAB_03028fd4:
  *(undefined1 *)(_DAT_03029124 + 10) = 0;
LAB_03028fda:
  iVar13 = _DAT_03029124;
  uVar9 = (uint)*_DAT_03029128;
  iVar6 = _DAT_03029124 + uVar9 * 0xc;
  *(uint *)(_DAT_03029124 + (uVar9 + 6) * 4) =
       (uint)*(byte *)(iVar6 + 0x2d) +
       (uint)*(byte *)(iVar6 + 0x2c) * 0x100 + (uint)*(byte *)(iVar6 + 0x2b) * 0x10000;
  *(int *)(iVar13 + (uVar9 + 8) * 4) = iVar11;
  OSFlagPost_wrapper_set_fixed_grp(2);
  return;
}

