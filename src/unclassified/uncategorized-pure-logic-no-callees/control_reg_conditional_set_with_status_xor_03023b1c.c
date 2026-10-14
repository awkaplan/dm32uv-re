/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: control_reg_conditional_set_with_status_xor @ 03023b1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void control_reg_conditional_set_with_status_xor(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
  if ((dVar1 & 0x40000000) == 0) {
    dVar1 = SystemControl_Type_11000000.LAYER2_CONTROL;
    SystemControl_Type_11000000.LAYER2_CONTROL = dVar1 & 0xffffffef;
    dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
    SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 2;
    dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
    SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 0x1000;
  }
  else {
    dVar1 = SystemControl_Type_11000000.LAYER2_SLOT_UPDATE;
    SystemControl_Type_11000000.LAYER2_SLOT_UPDATE = dVar1 | 0x20;
  }
  dVar1 = SystemControl_Type_11000000.LAYER2_STATUS;
  p_dmr_call_config_state->field_0xf = (byte)(dVar1 >> 0x1d) & 1 ^ *(byte *)p_dmr_call_config_state;
  return;
}

