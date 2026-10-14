/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitmask_table_index_lookup @ 03023db8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 382 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 bitmask_table_index_lookup(int param_1,byte param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = (uint)param_2;
  bVar2 = *(byte *)(param_1 + 3);
  uVar4 = count_table_entries_sharing_bit(bVar2);
  if (uVar4 < 6) {
    uVar5 = count_table_entries_sharing_bit(*(undefined1 *)(param_1 + uVar4 + 4));
    if (5 < (int)(uVar5 + uVar4)) {
      uVar5 = 5 - uVar4 & 0xff;
    }
    if ((uVar4 == 0) && (uVar5 == 0)) goto LAB_03023f40;
  }
  else {
    uVar5 = 0;
    uVar4 = 6;
  }
  if (uVar8 < 9) {
    if (uVar4 != 0) {
      if ((*(byte *)(uVar8 + DAT_03023e64) & bVar2) != 0) {
        iVar6 = bit_pattern_match_count_with_position_gate(bVar2,uVar8);
        iVar6 = char_in_allowlist_table_check(*(undefined1 *)(param_1 + iVar6 + 3));
        if (iVar6 == 0) {
          *param_3 = param_2;
          return 0;
        }
      }
LAB_03023e70:
      if (*(char *)(param_1 + 4) == -1) {
        uVar8 = 1;
LAB_03023e8c:
        bVar2 = bitmask_nth_set_bit_table_index(bVar2,uVar8);
        *param_3 = bVar2;
        return 0;
      }
      uVar8 = 1;
LAB_03023e9a:
      uVar8 = uVar8 + 1 & 0xff;
      if (uVar8 <= uVar4) goto LAB_03023e7c;
      uVar8 = 1;
      do {
        iVar6 = char_in_allowlist_table_check(*(undefined1 *)(param_1 + uVar8 + 3));
        if (iVar6 == 0) {
          bVar2 = bitmask_nth_set_bit_table_index(bVar2,uVar8);
          *param_3 = bVar2;
          return 0;
        }
        uVar8 = uVar8 + 1 & 0xff;
      } while (uVar8 <= uVar4);
    }
  }
  else {
    if (uVar5 != 0) {
      bVar1 = *(byte *)(param_1 + uVar4 + 4);
      if ((*(byte *)(uVar8 + DAT_03023e68) & bVar1) != 0) {
        iVar6 = bit_pattern_match_count_with_position_gate(bVar1,uVar8);
        iVar6 = char_in_allowlist_table_check(*(undefined1 *)(uVar4 + 4 + param_1 + iVar6));
        if (iVar6 == 0) {
          *param_3 = param_2;
          return 0;
        }
      }
    }
    if (uVar4 != 0) goto LAB_03023e70;
  }
  if (uVar5 != 0) {
    iVar6 = uVar4 + 4;
    if (*(char *)(param_1 + iVar6 + 1) == -1) {
      uVar4 = 1;
    }
    else {
      uVar4 = 1;
      do {
        uVar4 = uVar4 + 1 & 0xff;
        if (uVar5 < uVar4) {
          uVar4 = 1;
          do {
            iVar7 = char_in_allowlist_table_check(*(undefined1 *)(param_1 + uVar4 + iVar6));
            if (iVar7 == 0) {
              cVar3 = bitmask_nth_set_bit_table_index(*(undefined1 *)(param_1 + iVar6),uVar4);
              *param_3 = cVar3 + 8;
              return 0;
            }
            uVar4 = uVar4 + 1 & 0xff;
          } while (uVar4 <= uVar5);
          goto LAB_03023f40;
        }
      } while (*(char *)(param_1 + uVar4 + iVar6) != -1);
    }
    cVar3 = bitmask_nth_set_bit_table_index(*(undefined1 *)(param_1 + iVar6),uVar4);
    *param_3 = cVar3 + 8;
    return 0;
  }
LAB_03023f40:
  *param_3 = 0;
  return 1;
LAB_03023e7c:
  if (*(char *)(param_1 + uVar8 + 3) == -1) goto LAB_03023e8c;
  goto LAB_03023e9a;
}

