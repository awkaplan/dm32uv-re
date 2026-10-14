/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_flags9_dispatch_and_name_encode @ 0305ed30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void event_flags9_dispatch_and_name_encode(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = get_current_mode_state2();
  if ((iVar2 != 0) && (iVar2 = get_current_mode_state2(), iVar2 != 4)) {
    set_flag_byte_03064328(3);
  }
  bVar1 = get_event_flags_byte_dispatch(9);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) {
        if ((bVar1 & 8) != 0) {
          update_event_flags_byte_dispatch(9,8);
          iVar2 = DAT_0305ee60;
          memset_bytes(DAT_0305ee60,0,0x20);
          encode_name_tag_field(iVar2);
          SUBPIECE_SET(uVar4, 0, 1, p_dialog_flags_from_flash->field_0x1c_0);
          SUBPIECE_SET(uVar4, 1, 1, p_dialog_flags_from_flash->flags_0x1d);
          SUBPIECE_SET(uVar4, 2, 1, p_dialog_flags_from_flash->flags_0x1e);
          SUBPIECE_SET(uVar4, 3, 1, p_dialog_flags_from_flash->flags_0x1f);
          if (((uVar4 & 0xf0100) != 0x20100) &&
             (iVar3 = strcmp_byte_ordinal(iVar2,DAT_0305ee68), iVar3 != 0)) {
            memcpy_bytes_iram(DAT_0305ee68,iVar2,0x20);
            *(byte *)(iVar2 + 0x20) = *(byte *)(iVar2 + 0x20) & 0xfe | 1;
            *(byte *)(iVar2 + -0x35) = *(byte *)(iVar2 + -0x35) & 0xbf | 0x40;
          }
        }
      }
      else {
        update_event_flags_byte_dispatch(9,4);
      }
    }
    else {
      update_event_flags_byte_dispatch(9,2);
      numeric_dialog_field_apply_or_gps_update();
    }
  }
  else {
    update_event_flags_byte_dispatch(9,1);
    dialog_tick_event_dispatcher();
  }
  return;
}

