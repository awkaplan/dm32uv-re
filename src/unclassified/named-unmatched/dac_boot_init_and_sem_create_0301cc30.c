/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dac_boot_init_and_sem_create @ 0301cc30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dac_boot_init_and_sem_create(void)

{
  dword dVar1;
  
  OSSemCreate_shared_name_wrapper(_DAT_0301cc64,1);
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & 0xcfffffff;
  DAC_Type_140f0000.DAC_PD_MODE_EN = 1;
  DAC_Type_140f0000.DAC_DATA_A = 0;
  DAC_Type_140f0000.DAC_DATA_B = 0;
  DAC_Type_140f0000.DAC_DATA_C = 0;
  DAC_Type_140f0000.DAC_PD_CTRL = 1;
  dac_channel_write_12bit(4,0x6e2);
  return;
}

