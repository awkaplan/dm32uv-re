/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: adc_diag_avg_ch1_display @ 03054ebc (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-adc
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void adc_diag_avg_ch1_display(void)

{
  undefined4 *puVar1;
  short sVar2;
  char cVar3;
  
  *(undefined2 *)PTR_DAT_03054fb8 = 0;
  if (*(char *)PTR_DAT_03054fbc == 'O') {
    *(undefined2 *)PTR_DAT_03054fb4 = 0x7a;
  }
  else {
    *(undefined2 *)PTR_DAT_03054fb4 = 0x7c;
  }
  puVar1 = PTR_DAT_03054fb8;
  cVar3 = '\0';
  do {
    sVar2 = adc_read_channel_dispatch(1);
    *(short *)puVar1 = sVar2 + *(short *)puVar1;
    busy_wait_delay_loop_short(0x32);
    cVar3 = cVar3 + '\x01';
  } while (cVar3 != '\x04');
  *(ushort *)PTR_DAT_03054fb8 = *(ushort *)PTR_DAT_03054fb8 >> 2;
  diag_rssi_sql_numeric_draw(3);
  return;
}

