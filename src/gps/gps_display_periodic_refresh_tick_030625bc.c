/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_display_periodic_refresh_tick @ 030625bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_display_periodic_refresh_tick(void)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = PTR_DAT_03062644;
  sVar1 = *(short *)(PTR_DAT_03062644 + 3);
  *(ushort *)(PTR_DAT_03062644 + 3) = sVar1 + 1U;
  if ((((*(ushort *)(puVar2 + 1) <= (ushort)(sVar1 + 1U)) && (0x1d < *(ushort *)(puVar2 + 1))) &&
      (iVar3 = tx_is_inhibited(), iVar3 == 0)) && (*(char *)PTR_DAT_03062650 == '\0')) {
    *(undefined2 *)(PTR_DAT_03062644 + 3) = 0;
    event_queue_reset();
    if ((((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) &&
        ((p_vfo_display_state->flags_0x8 & 8) == 0)) &&
       (((*(byte *)PTR_DAT_03062658 & 0x40) != 0 || ((*(byte *)PTR_DAT_03062644 & 4) != 0)))) {
      gps_display_refresh_and_notify();
    }
  }
  return;
}

