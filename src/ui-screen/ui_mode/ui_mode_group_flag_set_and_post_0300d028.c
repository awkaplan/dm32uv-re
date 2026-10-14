/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_group_flag_set_and_post @ 0300d028 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_mode_group_flag_set_and_post(byte param_1,byte param_2)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_0300d0c0;
  PTR_DAT_0300d0c0[0x603] = PTR_DAT_0300d0c0[0x603] | param_1;
  if (param_1 == 1) {
    puVar1[0x606] = param_2 | puVar1[0x606];
  }
  else if (param_1 == 2) {
    PTR_DAT_0300d0c0[0x60c] = param_2 | PTR_DAT_0300d0c0[0x60c];
  }
  ui_mode_group_flag_post(4);
  return;
}

