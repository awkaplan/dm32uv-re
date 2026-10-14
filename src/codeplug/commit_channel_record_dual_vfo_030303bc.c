/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: commit_channel_record_dual_vfo @ 030303bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 412 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void commit_channel_record_dual_vfo(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,int param_14__w)

{
  char param_14 = (char)param_14__w;
  vfo_display_state *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pvVar1 = p_vfo_display_state;
  *(undefined4 *)p_vfo_display_state = param_1;
  *(undefined4 *)&pvVar1->field_0x4_0 = param_2;
  pvVar1->flags_0x8 = (char)param_3;
  pvVar1->flags_0x9 = (char)((uint)param_3 >> 8);
  pvVar1->field_0xa = (char)((uint)param_3 >> 0x10);
  pvVar1->field_0xb = (char)((uint)param_3 >> 0x18);
  pvVar1->field_0xc = (char)param_4;
  pvVar1->flags_0xd = (char)((uint)param_4 >> 8);
  pvVar1->field_0xe = (char)((uint)param_4 >> 0x10);
  pvVar1->field_0xf = (char)((uint)param_4 >> 0x18);
  *(undefined4 *)&pvVar1->field_0x10 = param_5;
  *(undefined4 *)&pvVar1->field_0x14 = param_6;
  *(undefined4 *)&pvVar1->field_0x18 = param_7;
  *(undefined4 *)&pvVar1->field_0x1c = param_8;
  *(undefined4 *)&pvVar1->field_0x20 = param_9;
  *(undefined4 *)&pvVar1->field_0x24 = param_10;
  *(undefined4 *)&pvVar1->field_0x28 = param_11;
  *(undefined4 *)&pvVar1->field_0x2c = param_12;
  *(undefined2 *)&pvVar1->field_0x30 = (undefined2)param_13;
  pvVar1->field_0x32 = SUBPIECE(param_13, 2, 1);
  if (param_14 == '\x01') {
    iVar4 = get_current_mode_state2();
    puVar3 = PTR_DAT_03030564;
    puVar2 = PTR_DAT_03030560;
    if (iVar4 == 0) {
      if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
        *PTR_DAT_03030560 = param_1;
        puVar2[1] = param_2;
        puVar2[2] = param_3;
        puVar2[3] = param_4;
        puVar2[4] = param_5;
        puVar2[5] = param_6;
        puVar2[6] = param_7;
        puVar2[7] = param_8;
        puVar2[8] = param_9;
        puVar2[9] = param_10;
        puVar2[10] = param_11;
        puVar2[0xb] = param_12;
        *(undefined2 *)(puVar2 + 0xc) = (undefined2)param_13;
        *(undefined1 *)((int)puVar2 + 0x32) = SUBPIECE(param_13, 2, 1);
      }
      else {
        *PTR_DAT_03030564 = param_1;
        puVar3[1] = param_2;
        puVar3[2] = param_3;
        puVar3[3] = param_4;
        puVar3[4] = param_5;
        puVar3[5] = param_6;
        puVar3[6] = param_7;
        puVar3[7] = param_8;
        puVar3[8] = param_9;
        puVar3[9] = param_10;
        puVar3[10] = param_11;
        puVar3[0xb] = param_12;
        *(undefined2 *)(puVar3 + 0xc) = (undefined2)param_13;
        *(undefined1 *)((int)puVar3 + 0x32) = SUBPIECE(param_13, 2, 1);
      }
    }
    else if ((PTR_DAT_0303055c[1] & 1) == 0) {
      *PTR_DAT_03030560 = param_1;
      puVar2[1] = param_2;
      puVar2[2] = param_3;
      puVar2[3] = param_4;
      puVar2[4] = param_5;
      puVar2[5] = param_6;
      puVar2[6] = param_7;
      puVar2[7] = param_8;
      puVar2[8] = param_9;
      puVar2[9] = param_10;
      puVar2[10] = param_11;
      puVar2[0xb] = param_12;
      *(undefined2 *)(puVar2 + 0xc) = (undefined2)param_13;
      *(undefined1 *)((int)puVar2 + 0x32) = SUBPIECE(param_13, 2, 1);
    }
    else {
      *PTR_DAT_03030564 = param_1;
      puVar3[1] = param_2;
      puVar3[2] = param_3;
      puVar3[3] = param_4;
      puVar3[4] = param_5;
      puVar3[5] = param_6;
      puVar3[6] = param_7;
      puVar3[7] = param_8;
      puVar3[8] = param_9;
      puVar3[9] = param_10;
      puVar3[10] = param_11;
      puVar3[0xb] = param_12;
      *(undefined2 *)(puVar3 + 0xc) = (undefined2)param_13;
      *(undefined1 *)((int)puVar3 + 0x32) = SUBPIECE(param_13, 2, 1);
    }
  }
  return;
}

