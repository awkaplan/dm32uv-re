/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_timeout_and_tx_state_tick @ 03064d34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 452 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_timeout_and_tx_state_tick(void)

{
  short sVar1;
  undefined2 *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  if ((PTR_DAT_03064e54[8] & 1) == 0) {
    iVar4 = get_current_mode_state1();
    if (iVar4 == 0) {
      uVar5 = vfo_active_side_mode_nibble();
      bVar3 = FUN_0002df40();
    }
    else {
      uVar5 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
      bVar3 = p_vfo_display_state->flags_0x8 & 1;
    }
    if (bVar3 != 0) {
      if ((*(byte *)PTR_DAT_03064e50 & 0x38) == 8) {
        uVar5 = 1;
      }
      if (((((*(byte *)PTR_DAT_03064e50 & 1) == 0) || ((*(byte *)PTR_DAT_03064e60 & 1) != 0)) ||
          ((p_dialog_flags_from_flash->flags_0x1 & 3) != 0)) ||
         ((iVar4 = keypad_dispatch_not_inhibited(), puVar2 = PTR_DAT_03064e50, iVar4 == 0 ||
          ((PTR_DAT_03064e68[1] & 1) != 0)))) {
        PTR_DAT_03064e50[2] = 0;
      }
      else if ((uVar5 == 1) || (uVar5 == 3)) {
        bVar3 = *(byte *)PTR_DAT_03064e50;
        if (((bVar3 & 0x38) == 8) &&
           ((*(char *)PTR_DAT_03064e60 != '\0' || ((*(byte *)p_call_active_flag & 4) != 0)))) {
          if ((bVar3 & 2) != 0) {
            PTR_DAT_03064e50[2] = 0;
            *(byte *)puVar2 = *(byte *)puVar2 & 0xfd;
          }
        }
        else if ((bVar3 & 2) == 0) {
          sVar1 = PTR_DAT_03064e50[2];
          PTR_DAT_03064e50[2] = sVar1 + 1U;
          if ((ushort)puVar2[1] <= (ushort)(sVar1 + 1U)) {
            event_queue_reset();
            puVar2 = PTR_DAT_03064f1c;
            if ((*(byte *)PTR_DAT_03064e50 & 0x38) == 0) {
              if (p_dialog_flags_from_flash->field_0x32 == 0) {
                ui_event_notify(0x1b);
                puVar2 = PTR_DAT_03064e50;
                PTR_DAT_03064e50[2] = 0;
                *(byte *)puVar2 = *(byte *)puVar2 & 0xfb;
              }
              else {
                PTR_DAT_03064f1c[2] = 0;
                *(byte *)puVar2 = *(byte *)puVar2 & 0xfd | 2;
                forward_to_FUN_0305dd94(3);
              }
            }
            else {
              PTR_DAT_03064f1c[2] = 0;
              *(byte *)puVar2 = *(byte *)puVar2 & 0xfd | 2;
            }
          }
          if (((int)((uint)(ushort)PTR_DAT_03064f1c[1] - (uint)*(byte *)(PTR_DAT_03064f1c + 3)) <=
               (int)(uint)(ushort)PTR_DAT_03064f1c[2]) && ((*(byte *)PTR_DAT_03064f1c & 0x38) == 0))
          {
            *(byte *)PTR_DAT_03064f1c = *(byte *)PTR_DAT_03064f1c & 0xfb | 4;
            ui_event_notify(0x25);
          }
        }
        else if ((bVar3 & 0x38) == 8) {
          sVar1 = PTR_DAT_03064f1c[2];
          PTR_DAT_03064f1c[2] = sVar1 + 1U;
          if (4 < (ushort)(sVar1 + 1U)) {
            tx_abort_on_condition();
            puVar2 = PTR_DAT_03064f1c;
            PTR_DAT_03064f1c[2] = 0;
            bVar3 = *(byte *)puVar2;
            *(byte *)puVar2 = bVar3 & 0xfb | 4;
            if ((bVar3 & 0xc0) == 0) {
              ui_event_notify(0x2e);
            }
            else {
              ui_event_notify(0x2f);
            }
          }
        }
        else if ((p_dialog_flags_from_flash->flags_0x1 & 3) != 1) {
          key_event_state_clear_preserve_bit0();
        }
      }
      else {
        PTR_DAT_03064e50[2] = 0;
      }
    }
  }
  return;
}

