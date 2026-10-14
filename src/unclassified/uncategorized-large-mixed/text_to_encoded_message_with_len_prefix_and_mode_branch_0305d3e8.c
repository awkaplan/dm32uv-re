/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_to_encoded_message_with_len_prefix_and_mode_branch @ 0305d3e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint text_to_encoded_message_with_len_prefix_and_mode_branch
               (undefined4 param_1,char *param_2,uint param_3,undefined1 *param_4)

{
  byte bVar1;
  radio_mode_state_0003e318 *prVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  
  param_3 = param_3 & 0xffff;
  *param_4 = (char)param_1;
  param_4[1] = (char)((uint)param_1 >> 8);
  param_4[2] = (char)((uint)param_1 >> 0x10);
  param_4[3] = 0;
  param_4[4] = 0;
  prVar2 = p_radio_mode_state_0003e318;
  if (param_3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    do {
      if (uVar4 == 0) {
        bVar1 = prVar2[1].flags_0x5;
        if (bVar1 == 1) {
          if ((*param_2 == '\r') && (param_2[2] == '\n')) {
            uVar4 = 4;
          }
        }
        else if (bVar1 == 2) {
          uVar4 = 5;
        }
        else if (*param_2 == '\0') {
          uVar4 = 2;
        }
      }
      if (param_3 <= uVar4) goto LAB_0305d4ee;
      if (prVar2[1].flags_0x5 == 2) {
        if (param_2[uVar4] == '\0') {
          param_4[uVar5 + 3] = param_2[uVar4 + 1];
          uVar5 = uVar5 + 1 & 0xffff;
        }
        else {
          uVar3 = name_tag_encoded_length_table_lookup(CONCAT11(param_2[uVar4],param_2[uVar4 + 1]));
          param_4[uVar5 + 3] = (char)((ushort)uVar3 >> 8);
          uVar5 = uVar5 + 1 & 0xffff;
          param_4[uVar5 + 3] = (char)uVar3;
          uVar5 = uVar5 + 1 & 0xffff;
        }
      }
      else if (param_2[uVar4 + 1] == '\0') {
        param_4[uVar5 + 3] = param_2[uVar4];
        uVar5 = uVar5 + 1 & 0xffff;
      }
      else {
        uVar3 = name_tag_encoded_length_table_lookup(CONCAT11(param_2[uVar4 + 1],param_2[uVar4]));
        param_4[uVar5 + 3] = (char)((ushort)uVar3 >> 8);
        uVar5 = uVar5 + 1 & 0xffff;
        param_4[uVar5 + 3] = (char)uVar3;
        uVar5 = uVar5 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 2 & 0xffff;
    } while (uVar4 < param_3);
  }
  param_4[uVar5 + 3] = 0;
LAB_0305d4ee:
  return uVar5 + 4 & 0xffff;
}

