/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_hold_debounce_state_dispatcher @ 030642c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 468 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void key_hold_debounce_state_dispatcher(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  iVar1 = get_current_mode_state2();
  if ((((((*(byte *)PTR_DAT_0306433c & 0x40) == 0) &&
        ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0)) &&
       ((*(byte *)((int)PTR_DAT_0306433c + 3) & 2) == 0)) &&
      (((*PTR_DAT_0306433c & 0x18000) != 0x8000 && ((*(byte *)PTR_DAT_03064340 & 0x10) == 0)))) &&
     (iVar1 != 0)) {
    iVar2 = keypad_dispatch_not_inhibited();
    if (iVar2 == 0) {
      set_flag_byte_03064328(0);
    }
    else if (iVar1 == 1) {
      bVar3 = *(char *)(_LAB_030644b8 + 0x1d) + 1;
      *(byte *)(_LAB_030644b8 + 0x1d) = bVar3;
      if (((*_DAT_030644bc & 0x20) == 0) || ((*(byte *)(_DAT_030644c0 + 1) & 2) != 0)) {
        if (1 < bVar3) {
          *(undefined1 *)(_LAB_030644b8 + 0x1d) = 0;
          if (p_radio_mode_state_0003e318[1].flags_0x2 == 0) {
            if ((p_radio_mode_state_0003e318->flags_0x7 & 2) == 0) {
              *(byte *)(_DAT_030644c0 + 1) =
                   *(byte *)(_DAT_030644c0 + 1) & 0xfe | *(byte *)(_DAT_030644c0 + 1) & 1 ^ 1;
              vfo_apply_active_side_config();
            }
            *(byte *)(_DAT_030644c8 + 3) = *(byte *)(_DAT_030644c8 + 3) & 0xbf;
            *(byte *)(_DAT_030644c0 + 1) = *(byte *)(_DAT_030644c0 + 1) & 0xfd;
          }
          else {
            set_flag_byte_03064328(3);
            display_refresh_tone_mode_icon();
          }
        }
      }
      else {
        *(undefined1 *)(_LAB_030644b8 + 0x1d) = 0;
        set_flag_byte_03064328(2);
      }
    }
    else if (iVar1 == 2) {
      bVar3 = *(char *)(_LAB_030644b8 + 0x1d) + 1;
      *(byte *)(_LAB_030644b8 + 0x1d) = bVar3;
      if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
        bVar4 = 0x14;
      }
      else {
        bVar4 = 0xf;
      }
      if (bVar4 < bVar3) {
        *(undefined1 *)(_LAB_030644b8 + 0x1d) = 0;
        *(byte *)(_DAT_030644c0 + 1) = *(byte *)(_DAT_030644c0 + 1) & 0xfd | 2;
        set_flag_byte_03064328(1);
      }
      else {
        iVar1 = tx_is_inhibited();
        if (iVar1 != 0) {
          *(undefined1 *)(_LAB_030644b8 + 0x1d) = 0;
          *(byte *)(_DAT_030644c8 + 3) = *(byte *)(_DAT_030644c8 + 3) & 0xbf | 0x40;
          set_flag_byte_03064328(3);
          display_refresh_tone_mode_icon();
        }
      }
    }
    else if (iVar1 == 3) {
      iVar1 = tx_is_inhibited();
      if (iVar1 == 0) {
        iVar1 = read_byte_field_0302e118();
        if ((iVar1 == 0) &&
           (bVar3 = *(char *)(_LAB_030644b8 + 0x1d) + 1, *(byte *)(_LAB_030644b8 + 0x1d) = bVar3,
           *_DAT_030644d0 <= (uint)bVar3)) {
          *(undefined1 *)(_LAB_030644b8 + 0x1d) = 3;
          *_DAT_030644d0 = 10;
          *(byte *)(_DAT_030644c8 + 3) = *(byte *)(_DAT_030644c8 + 3) & 0xbf;
          set_flag_byte_03064328(1);
          display_refresh_tone_mode_icon();
          *(byte *)(_DAT_030644c0 + 1) = *(byte *)(_DAT_030644c0 + 1) & 0xfd | 2;
        }
      }
      else {
        *(undefined1 *)(_LAB_030644b8 + 0x1d) = 0;
      }
    }
    else if ((iVar1 == 4) && (*_DAT_030644d4 == 'M')) {
      set_flag_byte_03064328(3);
    }
  }
  return;
}

