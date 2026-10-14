/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_config_reset_and_flag @ 030233f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_config_reset_and_flag(void)

{
  dmr_call_config_state *pdVar1;
  
  pdVar1 = p_dmr_call_config_state;
  *(undefined1 *)p_dmr_call_config_state = 0;
  pdVar1->field_0x1 = 0;
  *(undefined2 *)&pdVar1->field_0x10 = 0;
  pdVar1->field_0x5 = 0;
  pdVar1->field_0x3 = 0;
  *(undefined2 *)&pdVar1->field_0xa = 0;
  pdVar1->field_0x9 = 0;
  pdVar1->field_0x6 = 0;
  pdVar1->field_0x7 = 0;
  pdVar1->field_0x8 = 0;
  pdVar1->field_0x13 = 0;
  *(undefined1 *)PTR_DAT_03023558 = 0;
  os_flag_post_clear_0300c784(0x18000200);
  return;
}

