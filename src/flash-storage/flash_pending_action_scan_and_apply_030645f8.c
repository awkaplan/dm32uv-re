/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_pending_action_scan_and_apply @ 030645f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 524 bytes
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

void flash_pending_action_scan_and_apply(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  char cVar13;
  byte bVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  byte *pbVar18;
  char cVar19;
  byte bStack_34;
  byte bStack_33;
  byte abStack_32 [14];
  
  puVar8 = PTR_DAT_03064694;
  puVar7 = PTR_DAT_03064690;
  puVar6 = PTR_DAT_0306468c;
  iVar15 = 0x750;
  do {
    flash_field_read_cached(3,iVar15,&bStack_34,0x10);
    uVar17 = (uint)(byte)*puVar6;
    if (uVar17 == 0) {
      uVar11 = 0;
LAB_03064668:
      if (0xf < abStack_32[uVar11]) {
        if (bStack_34 < 7) {
                    /* WARNING: Could not recover jumptable at 0x03064682. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(PTR_PTR_03064698[bStack_34] & 0xfffffffe))();
          return;
        }
        cVar1 = *(char *)((int)PTR_DAT_03064840 + 2);
        if (cVar1 != '\0') {
          if (cVar1 == '\x01') {
            settings_write_0xf00_wrapper(0xa0);
          }
          else if (cVar1 == '\x02') {
            settings_write_0xf00_wrapper(0xa6);
          }
          else if (cVar1 == '\x04') {
            settings_write_0xf00_wrapper(0xa5);
          }
        }
        bStack_33 = bStack_33 & 0xf;
        if (bStack_33 == 1) {
          *(undefined1 *)((int)PTR_DAT_03064840 + 3) = 1;
          return;
        }
        if (bStack_33 == 2) {
          *(byte *)PTR_DAT_03064840 = *(byte *)PTR_DAT_03064840 & 0xef | 0x10;
          PTR_DAT_03064850[5] = PTR_DAT_03064850[4];
          return;
        }
        if (*(char *)((int)PTR_DAT_03064840 + 2) == '\0') {
          return;
        }
        flash_quad_enable_and_system_reset();
        return;
      }
    }
    else if (abStack_32[0] < 0x10) {
      pbVar9 = abStack_32;
      uVar11 = 0;
      pbVar18 = puVar8;
      bVar3 = *puVar7;
      bVar16 = 0xe;
      bVar14 = abStack_32[0];
      do {
        bVar5 = bVar3;
        pbVar9 = pbVar9 + 1;
        if (((bVar5 != bVar14) && ((bVar5 != 0xe || (bVar16 != bVar14)))) ||
           (uVar11 = uVar11 + 1 & 0xff, uVar17 <= uVar11)) break;
        bVar3 = *pbVar18;
        bVar14 = *pbVar9;
        pbVar18 = pbVar18 + 1;
        bVar16 = bVar5;
      } while (bVar14 < 0x10);
      if (uVar17 == uVar11) goto LAB_03064668;
    }
    iVar15 = iVar15 + 0x10;
  } while (iVar15 != 2000);
  if (((uVar17 == 5) || (uVar17 == 10)) || (uVar17 == 0xb)) {
    cVar1 = *(char *)PTR_DAT_03064854;
    bVar4 = false;
    cVar13 = '\0';
    pcVar12 = PTR_DAT_03064848;
    pcVar10 = (char *)PTR_DAT_03064854;
    cVar19 = '\x0e';
    do {
      pcVar10 = pcVar10 + 1;
      cVar2 = *pcVar12;
      if (cVar2 != cVar1) {
        if (cVar2 == '\n') {
          bVar4 = true;
        }
        else if ((cVar2 != '\x0e') || ((cVar19 != cVar1 && (cVar19 != '\n')))) {
          if (cVar13 != '\x05') {
            if (uVar17 != 5) {
              return;
            }
            flash_block6_callsign_lookup_or_hex_fallback(_LAB_03064938,_LAB_0306493c);
            *(byte *)(_LAB_03064944 + 0x15) = *(byte *)(_LAB_03064944 + 0x15) & 0xbf | 0x40;
            _LAB_03064940[4] = 3;
            return;
          }
          break;
        }
      }
      cVar1 = *pcVar10;
      cVar13 = cVar13 + '\x01';
      pcVar12 = pcVar12 + 1;
      cVar19 = cVar2;
    } while (cVar13 != '\x05');
    if ((*(byte *)(_LAB_03064930 + 1) & 1) == 0) {
      radio_mode_enter_and_refresh(0);
    }
    else {
      radio_mode_enter_and_refresh(1);
    }
    if (*_LAB_03064934 != '\x05') {
      flash_block6_callsign_lookup_or_hex_fallback
                (_LAB_03064938 + (*_LAB_03064934 != '\n') + 5,_LAB_0306493c);
      if (bVar4) {
        _LAB_03064940[4] = 1;
      }
      else {
        _LAB_03064940[4] = 0;
      }
      *(byte *)(_LAB_03064944 + 0x15) = *(byte *)(_LAB_03064944 + 0x15) & 0xbf | 0x40;
    }
    if ((*(byte *)(_LAB_03064948 + 6) & 0xf) != 0) {
      if (bVar4) {
        _LAB_03064940[3] = 1;
      }
      else {
        _LAB_03064940[3] = 2;
        if ((*(byte *)(_LAB_03064948 + 6) & 0xf) == 2) {
          *_LAB_03064940 = *_LAB_03064940 & 0xef | 0x10;
          *(undefined1 *)(_LAB_0306494c + 5) = *(undefined1 *)(_LAB_0306494c + 4);
        }
      }
    }
  }
  return;
}

