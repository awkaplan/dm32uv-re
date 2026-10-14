/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_binary_search_le_record @ 03033598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_binary_search_le_record(uint param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_2c;
  uint local_28;
  
  local_28 = 0;
  local_2c = 0;
  p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xfe;
  flash_read_mutex_guarded(*PTR_DAT_030336b0,&local_28,4);
  puVar1 = PTR_DAT_030336b0;
  if (local_28 - 1 < 50000) {
    if (local_28 != 0) {
      uVar4 = 1;
      uVar6 = local_28;
      do {
        uVar5 = uVar6 - uVar4;
        unaff_r4 = (uVar5 >> 1) + uVar4;
        uVar2 = unaff_r4 / 0x2c & 0xffff;
        uVar3 = unaff_r4 % 0x2c;
        if (uVar3 == 0) {
          uVar2 = uVar2 - 1 & 0xffff;
          uVar3 = 0x2c;
        }
        if (unaff_r4 < 0x2d) {
          iVar7 = *puVar1 + 0x10 + uVar2 * 0x1000 + (uVar3 - 1) * 0x5c;
        }
        else {
          iVar7 = uVar2 * 0x1000 + *puVar1 + (uVar3 - 1) * 0x5c;
        }
        local_2c = 0;
        flash_read_mutex_guarded(iVar7 + 0x10,&local_2c,3);
        if (local_2c < param_1) {
          uVar4 = unaff_r4;
          uVar2 = uVar6;
          if (uVar5 == 1) {
            uVar4 = unaff_r4 + 1;
          }
          else {
joined_r0x03033664:
            if (uVar2 == unaff_r4) {
              return unaff_r4;
            }
          }
        }
        else {
          if (local_2c <= param_1) {
            flash_read_mutex_guarded(iVar7,param_2,0x10);
            *(undefined1 *)(param_2 + 0xf) = 0;
            p_radio_mode_state_0003e318->flags_0x6 =
                 p_radio_mode_state_0003e318->flags_0x6 & 0xfe | 1;
            return unaff_r4;
          }
          uVar6 = unaff_r4;
          uVar2 = uVar4;
          if (uVar5 != 1) goto joined_r0x03033664;
          uVar6 = unaff_r4 - 1;
        }
      } while (uVar4 <= uVar6);
    }
  }
  else {
    unaff_r4 = 0;
  }
  return unaff_r4;
}

