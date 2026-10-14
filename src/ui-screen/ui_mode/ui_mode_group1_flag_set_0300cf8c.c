/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_group1_flag_set @ 0300cf8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_mode_group1_flag_set(byte param_1,byte param_2)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_0300d024;
  PTR_DAT_0300d024[0x601] = PTR_DAT_0300d024[0x601] | param_1;
  if (param_1 == 1) {
    puVar1[0x608] = param_2 | puVar1[0x608];
  }
  else if (param_1 == 2) {
    PTR_DAT_0300d024[0x60a] = param_2 | PTR_DAT_0300d024[0x60a];
  }
  else if (param_1 == 4) {
    PTR_DAT_0300d024[0x60d] = param_2 | PTR_DAT_0300d024[0x60d];
  }
  ui_mode_group_flag_post(1);
  return;
}

