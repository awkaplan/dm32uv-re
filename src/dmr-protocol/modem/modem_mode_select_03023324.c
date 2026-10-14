/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_mode_select @ 03023324 (file base 0x03000000; code starts at 0x03001000)
 * Size: 192 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_mode_select(byte param_1,byte param_2)

{
  dword dVar1;
  
  if (param_1 < 3) {
    if (param_1 == 0) {
      if (param_2 == 2) {
        modem_set_layer2_mode(0);
      }
      else {
        modem_set_mode_variant();
      }
      p_dmr_call_config_state->field_0x5 = param_2;
    }
    else if (p_dmr_call_config_state->field_0x7 == 0) {
      if (param_2 == 2) {
        modem_set_layer2_mode(0);
      }
      else {
        modem_set_mode_variant();
      }
      p_dmr_call_config_state->field_0x5 = param_2;
    }
  }
  else if (param_1 == 4) {
    if (param_2 == 2) {
      if (p_dmr_call_config_state->field_0x5 == 0) {
        if (*(char *)PTR_DAT_030233e4 == '\x03') {
          *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 0;
        }
        else {
          *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 2;
        }
        modem_set_layer2_mode(1);
        dVar1 = SystemControl_Type_11000000.LAYER2_STATUS;
        *(byte *)p_dmr_call_config_state =
             p_dmr_call_config_state->field_0xf ^ (byte)(dVar1 >> 0x1d) & 1;
      }
      else if (*(char *)PTR_DAT_030233e4 == '\x03') {
        *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 0;
      }
      else {
        *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 1;
      }
    }
    else {
      modem_set_mode_variant();
      if (*(char *)PTR_DAT_030233e4 == '\x03') {
        *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 0;
      }
      else {
        *(undefined1 *)((int)PTR_DAT_030233e4 + 7) = 1;
      }
    }
    p_dmr_call_config_state->field_0x5 = param_2;
  }
  return;
}

