/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_config_callback_variant_dispatcher @ 0302072c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_config_callback_variant_dispatcher(undefined4 param_1,int param_2__w)

{
  undefined2 param_2 = (undefined2)param_2__w;
  if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
    memcpy_bytes_iram(param_1,DAT_03020764,param_2);
  }
  else {
    memcpy_bytes_iram(param_1,DAT_03020768,param_2);
  }
  return;
}

