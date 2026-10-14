/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_state_timeout_check @ 030234d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 130 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_state_timeout_check(void)

{
  if (p_dmr_call_config_state->field_0x5 == 2) {
    if (((byte)(PTR_DAT_03023578[1] - 1) < 2) && (p_dmr_call_config_state->field_0x7 == 0)) {
      if (2 < *(ushort *)&p_dmr_call_config_state->field_0x10) {
        modem_stop();
      }
    }
    else if (*(ushort *)&p_dmr_call_config_state->field_0x10 < 5) {
      if (1 < *(ushort *)&p_dmr_call_config_state->field_0x10) {
        PTR_DAT_03023564[(byte)~(*(char *)p_dmr_call_config_state != '\0') + 0x10] = 0;
      }
    }
    else {
      modem_stop();
    }
  }
  else if (*(ushort *)&p_dmr_call_config_state->field_0x10 < 0xd) {
    if (1 < *(ushort *)&p_dmr_call_config_state->field_0x10) {
      PTR_DAT_03023564[(byte)~(*(char *)p_dmr_call_config_state != '\0') + 0x10] = 0;
    }
  }
  else {
    modem_stop();
  }
  return;
}

