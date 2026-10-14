/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_sm_reset_and_status_clear @ 0301e528 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_sm_reset_and_status_clear(void)

{
  call_setup_sm_state *pcVar1;
  undefined4 *puVar2;
  dmr_status_flags *pdVar3;
  
  pcVar1 = p_call_setup_sm_state;
  *(undefined1 *)p_call_setup_sm_state = 0;
  pcVar1->field_0x1 = 0;
  pcVar1->field_0x5 = 0;
  puVar2 = PTR_DAT_0301e6f8;
  *(undefined1 *)PTR_DAT_0301e6f8 = 0;
  *(byte *)((int)puVar2 + 10) = *(byte *)((int)puVar2 + 10) & 0xfe;
  *(byte *)((int)puVar2 + 7) = *(byte *)((int)puVar2 + 7) & 0xfc;
  pdVar3 = p_dmr_status_flags;
  *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
  pdVar3->field_0x1 = pdVar3->field_0x1 & 0xe0;
  pdVar3->field_0xc = 0;
  return;
}

