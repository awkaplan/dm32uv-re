/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_scan_dwell_timer_tick @ 03066058 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_scan_dwell_timer_tick(void)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)PTR_DAT_03066184;
  *(ushort *)PTR_DAT_03066184 = sVar1 + 1U;
  if (((((uint)*PTR_DAT_03066180 >> 8 & 0xffff) <= (uint)(ushort)(sVar1 + 1U)) ||
      (*(char *)PTR_DAT_03066188 != '\0')) && (iVar2 = tx_is_inhibited(), iVar2 == 0)) {
    if (*(char *)PTR_DAT_0306618c == '\0') {
      *(undefined2 *)PTR_DAT_03066184 = 0;
      *(undefined1 *)PTR_DAT_03066188 = 0;
      event_queue_reset();
      if (((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) &&
         ((p_vfo_display_state->flags_0x8 & 8) == 0)) {
        channel_scan_step_and_lock();
      }
    }
  }
  return;
}

