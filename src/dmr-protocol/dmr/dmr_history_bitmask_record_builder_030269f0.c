/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_history_bitmask_record_builder @ 030269f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
dmr_history_bitmask_record_builder(undefined1 param_1,char param_2,byte *param_3,byte param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  
  puVar1 = PTR_DAT_03026a9c;
  *(undefined1 *)(PTR_DAT_03026a9c + 7) = 0;
  if (param_2 == '\0') {
    *(undefined1 *)((int)puVar1 + 0x11) = 0;
    if (param_4 != 0) {
      bVar3 = 0;
      pbVar4 = param_3;
      do {
        if (*pbVar4 != 0xff) {
          uVar2 = 0;
          do {
            if (((int)(uint)*pbVar4 >> (uVar2 & 0x3f) & 1U) == 0) {
              *(char *)((int)puVar1 + 0x11) = *(char *)((int)puVar1 + 0x11) + '\x01';
            }
            uVar2 = uVar2 + 1;
          } while (uVar2 != 8);
        }
        bVar3 = bVar3 + 1;
      } while ((bVar3 < param_4) && (pbVar4 = pbVar4 + 1, bVar3 != 0x14));
    }
    memcpy_bytes_iram(DAT_03026aa0,param_3,param_4);
  }
  puVar1 = PTR_DAT_03026a9c;
  history_record_push_type3_repeated
            (*(undefined1 *)PTR_DAT_03026a9c,PTR_DAT_03026a9c[10],PTR_DAT_03026a9c[0xb],param_1,1,
             *(char *)((int)PTR_DAT_03026a9c + 0x11) + '\x01');
  history_record_push_typed(puVar1);
  history_message_fragment_and_link(puVar1,param_2);
  if (p_call_setup_sm_state_aux->mode_0x1 == 0) {
    history_slot_alloc_with_data(puVar1);
  }
  else if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return 0;
}

