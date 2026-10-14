/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_flag_bits_sync_to_dat_03064328 @ 0306419c (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_flag_bits_sync_to_dat_03064328(void)

{
  undefined1 *puVar1;
  
  if (p_dm32_settings_block04[0x6c] == '\x01') {
    *PTR_DAT_03064328 = 1;
  }
  else {
    *PTR_DAT_03064328 = 0;
  }
  puVar1 = PTR_DAT_0306432c;
  PTR_DAT_0306432c[0x1d] = 0;
  puVar1[0x1c] = 0;
  PTR_DAT_03064328[1] = PTR_DAT_03064328[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
  *PTR_DAT_03064330 = 10;
  return;
}

