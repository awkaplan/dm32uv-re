/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_history_slot_append_batch @ 030242b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 358 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_history_slot_append_batch(void)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  byte bVar8;
  
  puVar3 = PTR_DAT_0302432c;
  PTR_DAT_0302432c[3] = 0;
  if ((byte)(puVar3[4] - 3) < 2) {
    iVar7 = read_byte_field_0300c3ac();
    if ((iVar7 == 1) || (*(char *)((uint)p_dmr_call_config_state->field_0x4 + DAT_0302433c) != '\0')
       ) {
      if (PTR_DAT_0302432c[2] == '\0') {
        PTR_DAT_0302432c[2] = 0x12;
      }
      else {
        PTR_DAT_0302432c[2] = PTR_DAT_0302432c[2] + -1;
      }
      scan_timer_apply_random_jitter(PTR_DAT_0302432c[2]);
      return;
    }
  }
  else if ((p_dmr_call_config_state->field_0x13 != 0) ||
          (*(char *)((uint)p_dmr_call_config_state->field_0x4 + DAT_0302433c) != '\0')) {
    if (PTR_DAT_0302432c[2] == '\0') {
      *(undefined1 *)(PTR_DAT_030244a0 + 1) = 0x12;
    }
    else {
      PTR_DAT_0302432c[2] = PTR_DAT_0302432c[2] + -1;
    }
    scan_timer_apply_random_jitter(*(undefined1 *)(PTR_DAT_030244a0 + 1));
    return;
  }
  puVar6 = PTR_DAT_030244a4;
  puVar4 = PTR_DAT_030244a0;
  PTR_DAT_030244a4[1] = PTR_DAT_030244a4[1] & 0xf800 | PTR_DAT_030244a0[4] & 0x7ff;
  puVar5 = PTR_DAT_030244a0;
  if (*(char *)(puVar4 + 3) != '\0') {
    bVar8 = 0;
    do {
      iVar7 = history_slot_allocate();
      if (iVar7 == 0) {
        OSTimeDly_ms_wrapper(0x46);
        iVar7 = history_slot_allocate();
        if (iVar7 != 0) goto LAB_03024392;
      }
      else {
LAB_03024392:
        *(undefined1 *)(iVar7 + 2) = 0;
        *(undefined1 *)(iVar7 + 3) = 3;
        memset_bytes(iVar7 + 5,0,0x18);
        *(undefined1 *)(iVar7 + 5) = 0x87;
        *(undefined1 *)(iVar7 + 6) = 0;
        uVar2 = puVar6[1];
        *(char *)(iVar7 + 7) = (char)((int)(uVar2 & 0x7ff) >> 3);
        *(byte *)(iVar7 + 8) = (byte)((uVar2 & 0x7ff) << 5) | *(byte *)((int)puVar6 + 3) >> 3;
        *(char *)(iVar7 + 9) = (char)(*(uint *)(puVar6 + 4) >> 0xc);
        *(byte *)(iVar7 + 10) = (byte)(*(uint *)(puVar6 + 4) >> 4) & 0xfe | *(byte *)puVar6;
        bVar1 = *(byte *)((int)puVar6 + 1);
        *(byte *)(iVar7 + 0xb) =
             *(char *)(puVar6 + 2) * '\x02' | (byte)(*(int *)(puVar6 + 4) << 3) | bVar1 >> 1;
        *(char *)(iVar7 + 0xc) = (char)(*(uint *)(puVar6 + 8) >> 0xc);
        *(byte *)(iVar7 + 0xd) = (byte)(*(uint *)(puVar6 + 8) >> 4) & 0xfe;
        *(byte *)(iVar7 + 0xe) =
             bVar1 & 1 | *(char *)(puVar6 + 6) * '\x02' | (byte)(*(int *)(puVar6 + 8) << 3);
        if (p_dmr_call_config_state->field_0x5 != 2) {
          modem_stop();
          modem_mode_select(4,2);
        }
        history_slot_link_append(iVar7);
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < *(byte *)(puVar5 + 3));
  }
  *(undefined1 *)(PTR_DAT_030244a0 + 2) = 0;
  osmbox_post_candidate2_on_check_0300c770();
  return;
}

