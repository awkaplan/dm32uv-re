/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_contact_record_copy @ 03035070 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_contact_record_copy(undefined1 *param_1,undefined1 *param_2,undefined1 param_3)

{
  *param_1 = *param_2;
  if ((byte)param_2[1] < 3) {
    param_1[1] = 0;
  }
  else {
    param_1[1] = 1;
  }
  memcpy_bytes_iram(param_1 + 2,param_2 + 2,0x10);
  param_1[0x12] = 0;
  param_1[0x16] = param_2[1];
  memcpy_bytes_iram(param_1 + 0x13,param_2 + 0x13,3);
  param_1[0x17] = param_3;
  return;
}

