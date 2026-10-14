/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_set_layer2_mode @ 03023254 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_set_layer2_mode(char param_1)

{
  dword dVar1;
  
  if (p_call_setup_sm_state_aux->field_0x2 == 0) {
    if (param_1 == '\0') {
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 & 0xfffffffe;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 & 0xfffffffb;
      dVar1 = SystemControl_Type_11000000.LAYER2_CONTROL;
      SystemControl_Type_11000000.LAYER2_CONTROL = dVar1 & 0x10 | 0xcb;
      SystemControl_Type_11000000.LAYER2_SLOT_CNT = 0;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOT_CNT;
      SystemControl_Type_11000000.LAYER2_SLOT_CNT = dVar1 | 0x80200;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 5;
      SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0x40;
    }
    else {
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 & 0xfffffffe;
      SystemControl_Type_11000000.LAYER2_CONTROL = 0xd3;
      dVar1 = SystemControl_Type_11000000.LAYER2_CONTROL;
      SystemControl_Type_11000000.LAYER2_CONTROL = dVar1 | 8;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 0x800;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 1;
      dVar1 = SystemControl_Type_11000000.LAYER2_STATUS;
      SystemControl_Type_11000000.LAYER2_SLOT_CNT = (dVar1 >> 0x12 & 0x1ff | 0x200) << 10;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 4;
      dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
      SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 0x40;
      SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0x40;
    }
  }
  else {
    SystemControl_Type_11000000.LAYER2_CONTROL = 0x40;
    SystemControl_Type_11000000.LAYER2_TXRX_CTRL = 0x41;
  }
  return;
}

