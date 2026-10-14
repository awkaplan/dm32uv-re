/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_pair_store @ 0300da88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_freq_pair_store(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  
  if (DAT_0300db3c < param_2) {
    p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7 | 8;
  }
  else {
    p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7;
  }
  if (DAT_0300db3c < param_1) {
    p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xef | 0x10;
  }
  else {
    p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xef;
  }
  iVar1 = DAT_0300db44;
  bVar2 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (bVar2 == 0) {
    bandwidth_deviation_threshold_store(param_1,DAT_0300db44);
    bandwidth_deviation_threshold_store(param_2,iVar1 + 4);
  }
  else if (bVar2 == 0x10) {
    bandwidth_deviation_threshold_store(param_1,DAT_0300db44);
    bandwidth_deviation_threshold_store(param_2,iVar1 + 4);
  }
  else if (bVar2 == 0x20) {
    bandwidth_deviation_threshold_store(param_1,DAT_0300db44);
    bandwidth_deviation_threshold_store(param_2,iVar1 + 4);
  }
  return;
}

