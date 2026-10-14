/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_is_inhibited @ 0302ed50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool tx_is_inhibited(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    if (p_radio_mode_state_0003e318[1].flags_0x2 == 0) {
      bVar1 = p_radio_mode_state_0003e318[2].flags_0x2;
      if ((bVar1 & 0x1c) == 0) {
        if (PTR_DAT_0302edf4[1] == '\0') {
          if ((bVar1 & 1) == 0) {
            if ((bVar1 & 0x40) == 0) {
              bVar2 = (*(byte *)p_call_active_flag & 8) != 0;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = true;
          }
        }
        else {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
  }
  else {
    iVar3 = call_state_not_idle_check();
    if (iVar3 == 0) {
      iVar3 = get_field_0301ea64_0x14();
      if (iVar3 == 0) {
        if (p_tx_ptt_ui_state->field_0x7 == 0) {
          bVar2 = (PTR_DAT_0302ee00[7] & 2) != 0;
        }
        else {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
  }
  return bVar2;
}

