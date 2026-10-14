/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: battery_monitor_adc_tick @ 0301bcb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-adc
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void battery_monitor_adc_tick(void)

{
  undefined4 *puVar1;
  short sVar2;
  
  if (*(byte *)PTR_DAT_0301be2c < 4) {
    *(byte *)PTR_DAT_0301be2c = *(byte *)PTR_DAT_0301be2c + 1;
    sVar2 = adc_read_channel_dispatch(2);
    *(short *)PTR_DAT_0301be30 = sVar2 + *(short *)PTR_DAT_0301be30;
  }
  else {
    *(undefined1 *)PTR_DAT_0301be2c = 0;
    puVar1 = PTR_DAT_0301be30;
    *(ushort *)PTR_DAT_0301be30 = *(ushort *)PTR_DAT_0301be30 >> 2;
    rssi_meter_level_update_and_fault_reset(*(undefined2 *)puVar1);
    *(undefined2 *)puVar1 = 0;
  }
  return;
}

