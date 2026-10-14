/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_mode_transition_on_freq_delta @ 03055f88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 212 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_mode_transition_on_freq_delta(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1[2] & 0xf0) == 0x10) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    if (uVar2 < uVar1) {
      iVar3 = uVar1 - uVar2;
    }
    else {
      iVar3 = uVar2 - uVar1;
    }
    if (iVar3 == 0) {
      if ((*(byte *)((int)param_1 + 0xd) & 0x20) == 0) {
        modem_rf_mode_transition_apply
                  ((byte)param_1[2] >> 4,0,*(byte *)((int)param_1 + 0xd) >> 4 & 1);
        p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc;
      }
      else {
        modem_rf_mode_transition_apply
                  ((byte)param_1[2] >> 4,4,*(byte *)((int)param_1 + 0xd) >> 4 & 1);
        p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc | 2;
      }
    }
    else {
      modem_rf_mode_transition_apply((byte)param_1[2] >> 4,1,*(byte *)((int)param_1 + 0xd) >> 4 & 1)
      ;
      p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc | 1;
    }
  }
  else {
    modem_rf_mode_transition_apply((byte)param_1[2] >> 4,0,1);
    p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc;
  }
  return;
}

